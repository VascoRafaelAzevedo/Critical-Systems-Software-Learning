#include <iostream>

class IntSmartPtr {
private:
    int* ptr;  // o raw pointer que vamos gerir

public:
    // Construtor: recebe o pointer
    IntSmartPtr(int* p) : ptr(p) {
        std::cout << "SmartPtr criado, gere endereço " << ptr << "\n";
    }
    
    // Destrutor: MAGIA AQUI! 🎩
    ~IntSmartPtr() {
        std::cout << "SmartPtr destruído, a fazer delete de " << ptr << "\n";
//        delete ptr;  // Cleanup automático!
        ptr = nullptr;
    }
    
    // Operador * para aceder ao valor (como Java's .value)
    int& operator*() {
        return *ptr;
    }
    
    // Proibir cópia (veremos porquê)
    IntSmartPtr(const IntSmartPtr&) = delete;
    IntSmartPtr& operator=(const IntSmartPtr&) = delete;
};

// TESTE:
int main() {
    std::cout << "=== Início ===\n";
    
    {  // novo scope
        IntSmartPtr sp(new int(42));
        std::cout << "Valor: " << *sp << "\n";
        
        *sp = 100;  // modificar
        std::cout << "Novo valor: " << *sp << "\n";
        
    }  // ← AQUI o destrutor é chamado! Delete automático! ⚡
    
    std::cout << "=== Fim (sem leaks!) ===\n";
    
    return 0;
}