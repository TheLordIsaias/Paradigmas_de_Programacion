class Cuenta{
    private:
        int numero;
        long int dniTitular;
        double saldo;
    public:
        void Crear(int num, long int titular, double monto);
        bool Depositar(double monto);
        bool Extraer(double monto);
        double GetSaldo();
        void MostrarInformacion();
};