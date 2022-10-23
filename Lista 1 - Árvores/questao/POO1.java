package questao;

import java.util.ArrayList;

public class POO1 {
    public int calcula() {
        return 1;
    }
}

public class POO2 extends POO1 {
    public int calcula() {
        return 2;
    }
}

public class POO3 extends POO2 {
    public int calcula() {
        return 3;
    }
}

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
