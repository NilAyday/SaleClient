// dllmain.cpp : Defines the entry point for the DLL application.
#include "SaleClient.h"
#include <iostream>
#include <fstream>
#include <string> 
#include <iomanip >
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

using namespace std;

JNIEXPORT jobject JNICALL Java_phase1_Main_productReg
(JNIEnv *env, jobject obj) {
     jclass TestClass = env->GetObjectClass(obj);
    jfieldID fidPrNo = env->GetFieldID(TestClass, "prNo","I");
   jfieldID fidPrName = env->GetFieldID(TestClass, "prName", "Ljava/lang/String;");
    jfieldID fidPrPrice = env->GetFieldID(TestClass, "prPrice", "D");
    jfieldID fidPrKDV = env->GetFieldID(TestClass, "prKDV","D");
    jfieldID fidPrBarcode = env->GetFieldID(TestClass, "prBarcode", "Ljava/lang/String;");
   
   
   jint No = env->GetIntField(obj, fidPrNo);
    jstring Name = (jstring) env->GetObjectField(obj, fidPrName);
    jdouble Price = (jdouble)env->GetDoubleField(obj, fidPrPrice);
    jdouble Kdv = (jdouble)env->GetDoubleField(obj, fidPrKDV);
    jstring Barcode =(jstring) env->GetObjectField(obj, fidPrBarcode);

       
  
   const char* Name2 = env->GetStringUTFChars(Name, NULL);
   const char* Barcode2 = env->GetStringUTFChars(Barcode, NULL);
    
    ofstream myfile("C:\\SaleClient\\products.txt", ios::app);
    if (myfile.is_open())
    {
        
        
        myfile << "Urun sayisi: ";
           myfile << No;
            myfile << "\n";
            myfile << "Urun Adi: ";
            myfile << Name2;
            myfile << "\n";
            myfile << "Urun Fiyati: ";
            myfile << fixed << std::setprecision(2) << Price;
            myfile << "\n";
            myfile << "Urun KDVsi: ";
            myfile << fixed << std::setprecision(2) << Kdv;
            myfile << "\n";
            myfile << "Urun Barkodu: ";
            myfile << Barcode2;
            myfile << "\n";

        myfile << "-------\n";
        myfile.close();
    }
    else {
        cout << "Unable to open file";
        return 0;
    }
    cout << obj;
    return obj;
   
}


JNIEXPORT jobject JNICALL Java_phase1_Main_productSend
(JNIEnv* env, jobject obj) {
    int argc;
        char* argv;
        argv = "localhost";
    WSADATA wsaData;
    SOCKET ConnectSocket = INVALID_SOCKET;
    struct addrinfo* result = NULL,
        * ptr = NULL,
        hints;
    const char* sendbuf = "this is a test";
    char recvbuf[DEFAULT_BUFLEN];
    int iResult;
    int recvbuflen = DEFAULT_BUFLEN;

    jclass TestClass = env->GetObjectClass(obj);
    jfieldID fidPrNo = env->GetFieldID(TestClass, "prNo", "I");
    jfieldID fidPrName = env->GetFieldID(TestClass, "prName", "Ljava/lang/String;");
    jfieldID fidPrPrice = env->GetFieldID(TestClass, "prPrice", "D");
    jfieldID fidPrKDV = env->GetFieldID(TestClass, "prKDV", "D");
    jfieldID fidPrBarcode = env->GetFieldID(TestClass, "prBarcode", "Ljava/lang/String;");


    jint No = env->GetIntField(obj, fidPrNo);
    jstring Name = (jstring)env->GetObjectField(obj, fidPrName);
    jdouble Price = (jdouble)env->GetDoubleField(obj, fidPrPrice);
    jdouble Kdv = (jdouble)env->GetDoubleField(obj, fidPrKDV);
    jstring Barcode = (jstring)env->GetObjectField(obj, fidPrBarcode);

    
    int No2 = (int)env->GetIntField(obj, fidPrNo);
    string No3 = to_string(No2);
    const char* No4 = No3.c_str();

    double Price2 = (double)env->GetDoubleField(obj, fidPrPrice);
    string Price3 = to_string(Price2);
    const char* Price4 = Price3.c_str();

    double KDV2 = (double)env->GetDoubleField(obj, fidPrKDV);
    string KDV3 = to_string(KDV2);
    const char* KDV4 = KDV3.c_str();


    const char* Name2 = env->GetStringUTFChars(Name, NULL);
    const char* Barcode2 = env->GetStringUTFChars(Barcode, NULL);
    
    

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    iResult = getaddrinfo("localhost", DEFAULT_PORT, &hints, &result);
    

    // Attempt to connect to an address until one succeeds
    for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

        // Create a SOCKET for connecting to server
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
            ptr->ai_protocol);
        if (ConnectSocket == INVALID_SOCKET) {
            printf("socket failed with error: %ld\n", WSAGetLastError());
            WSACleanup();
           
        }

        // Connect to server.
        iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
    }

    // Send an initial buffer
    ///
    /// 
    /// 
   // iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
    send(ConnectSocket, No4 , (int)strlen(No4), 0);
    send(ConnectSocket, "\r\n", (int)strlen(" "), 0);
    send(ConnectSocket, Name2, (int)strlen(Name2), 0);
    send(ConnectSocket, "\r\n", (int)strlen(" "), 0);
    send(ConnectSocket, Price4, (int)strlen(Price4), 0);
    send(ConnectSocket, "\r\n", (int)strlen(" "), 0);
    send(ConnectSocket, KDV4, (int)strlen(KDV4), 0);
    send(ConnectSocket, "\r\n", (int)strlen(" "), 0);
    send(ConnectSocket, Barcode2, (int)strlen(Barcode2), 0);
    send(ConnectSocket, "\r\n", (int)strlen(" "), 0);
    /// <summary>
    ///
    /// </summary>
    
    if (iResult == SOCKET_ERROR) {
        printf("send failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        
    }

    printf("Bytes Sent: %ld\n", iResult);

    // shutdown the connection since no more data will be sent
    iResult = shutdown(ConnectSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        
    }

    // Receive until the peer closes the connection
    do {

        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0)
            printf("Bytes received: %d\n", iResult);
        else if (iResult == 0)
            printf("Connection closed\n");
        else
            printf("recv failed with error: %d\n", WSAGetLastError());

    } while (iResult > 0);

    // cleanup
    closesocket(ConnectSocket);
    WSACleanup();

    return obj;
}







