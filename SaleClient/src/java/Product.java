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
public class Product {
    private int prNo;
    private String UrunAdi;
    private int UrunFiyati;
    private int UrunKDVsi;
    private String UrunBarkodu;
    
    
    /*public Product(int UrunNo, 
     String UrunAdi,
     int UrunFiyati,
     int UrunKDVsi,
     String UrunBarkodu){
        this.UrunNo=UrunNo;
        this.UrunAdi=UrunAdi;
        this.UrunFiyati=UrunFiyati;
        this.UrunKDVsi=UrunKDVsi;
        this.UrunBarkodu=UrunBarkodu;



        
    }*/
    
    public Product(){}
    /**
     * @return the UrunNo
     */
    public int getUrunNo() {
        return prNo;
    }

    
    public void setUrunNo(int prNo) {
        this.prNo = prNo;
    }

    /**
     * @return the UrunAdi
     */
    public String getUrunAdi() {
        return UrunAdi;
    }

    /**
     * @param UrunAdi the UrunAdi to set
     */
    public void setUrunAdi(String UrunAdi) {
        this.UrunAdi = UrunAdi;
    }

    /**
     * @return the UrunFiyati
     */
    public int getUrunFiyati() {
        return UrunFiyati;
    }

    /**
     * @param UrunFiyati the UrunFiyati to set
     */
    public void setUrunFiyati(int UrunFiyati) {
        this.UrunFiyati = UrunFiyati;
    }

    /**
     * @return the UrunKDVsi
     */
    public int getUrunKDVsi() {
        return UrunKDVsi;
    }

    /**
     * @param UrunKDVsi the UrunKDVsi to set
     */
    public void setUrunKDVsi(int UrunKDVsi) {
        this.UrunKDVsi = UrunKDVsi;
    }

    /**
     * @return the UrunBarkodu
     */
    public String getUrunBarkodu() {
        return UrunBarkodu;
    }

    /**
     * @param UrunBarkodu the UrunBarkodu to set
     */
    public void setUrunBarkodu(String UrunBarkodu) {
        this.UrunBarkodu = UrunBarkodu;
    }
   
    
}
