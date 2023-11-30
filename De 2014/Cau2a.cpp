#include <iostream>
#include <string>
class IFace {
public:
    virtual void show() = 0;
    virtual IFace* clone() = 0;
    virtual ~IFace() {}
};
class EyedFace : public IFace {
private:
    std::string shape;
    int eyes;
public:
    void show() override {
        // Implement the show function
        std::cout << "Shape: " << shape << ", Eyes: " << eyes << std::endl;
    }
    IFace* clone() override {
        EyedFace* Clone = new EyedFace(shape, eyes);
        return Clone;
    }
    ~EyedFace() override {
        // Destructor implementation
    }

    EyedFace(const std::string& sh, const int& e) : shape(sh), eyes(e) {}
    // Remove the unnecessary destructor
};
int main() {
    // Example usage
    EyedFace* originalFace = new EyedFace("Round", 2);
    originalFace->show();
    IFace* clonedFace = originalFace->clone();
    clonedFace->show();
    delete originalFace;
    delete clonedFace;
    return 0;
}