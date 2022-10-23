package testesteste;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        int resultado = 0;
        ArrayList<POO1> poos = new ArrayList<POO1>();
        poos.add(new POO1());
        poos.add(new POO2());
        poos.add(new POO3());

        for (POO1 poo: poos) {
            resultado += poo.calcula();
        }

        System.out.println(resultado);
    }
}