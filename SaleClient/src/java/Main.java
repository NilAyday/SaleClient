/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package phase1;



/**
 *
 * @author Atalay Korkut
 */
public class Main {
    
Product a= new Product();

    public int prNo;
    public String prName;
     public double prPrice;
     public double prKDV;
     public String prBarcode;

   public native Product productReg();
   
   public native Product productSend();
   
    
    public static void main(String[] args) {
        
        
        
     
       
        System.loadLibrary("SaleClient");
        
       
      ProductRegistration.main(args);
       
        
       // Main main=new Main();
        
            
    }
    
}
