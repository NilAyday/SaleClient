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
public class ProductManager {
    
    private Product urun;
    
    public ProductManager(Product urun){
        
    }

    /**
     * @return the urun
     */
    public Product getUrun() {
        return urun;
    }

    /**
     * @param urun the urun to set
     */
    public void setUrun(Product urun) {
        this.urun = urun;
    }
    
    public void printUrun(Product urun){
        System.out.println(urun.getUrunAdi());
    }
    
}
