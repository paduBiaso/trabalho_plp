//Code by Padu. 

#include <iostream>//std::cout 
#include <math.h> //std::pow std::sqrt 
#include <string> //This library is needed for std::stod  
using namespace std;
//this code uses stod, a lot 
//std::stod return invalid_argument when it can't cast the string to double
//make x an string, if stod(x) fails, we know that x is an unknown 


void writeMenu() {
     cout << "////////////////////////////// M E N U //////////////////////////////" << endl;
     cout << "'1' - Pythagorean Theorem" << endl;
     cout << "'2' - Law of Universal Gravitation" << endl;
     cout << "'3' - Einstein's Theory of Special Relativity" << endl;
     cout << "'4' - Chaos Theory" << endl;
     cout << "'5' - Clapeyron Equation" << endl;
     cout << "'6' - Torricelli's Equation" << endl;
     cout << "'7' - Gauss' Equation" << endl;
     cout << "'8' - Magnetic Force on a Current-Carrying Wire Equation" << endl;
     cout << "'9' - Write Menu again" << endl;
     cout << "'0' - Exit"  << endl;
     cout << "////////////////////////////////////////////////////////////////////" << endl;
}

bool pythagoreanTheorem(double &t_result) { 
    cout << "Pythagorean Theorem\n";
    cout << "a^2 + b^2 = c^2" << endl;
    
    string a,b,c;  //unknowns.
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;

    double aValue = 0;
    double bValue = 0;
    double cValue = 0;
    int unknownPosition = -1; 
    int unknownCount = 0;

    //Conversion from string to double 
    try {
        aValue = stod(a);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 1;
        //A is an unknown.
        ++unknownCount;
    }
    try {
        bValue = stod(b);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 2;
        //B is an unknown
        ++unknownCount;
        if(unknownCount > 1) { 
            return false; 
            //Return false if there is more than one unknown 
        }
    } 
    try { 
        cValue = stod(c);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 3;
        //C is an unknown
        ++unknownCount;
        if(unknownCount >1) { 
            return false;
        }
    }
    
    if(unknownPosition == 1) { 
        t_result = sqrt(pow(cValue,2) - pow(bValue,2));
        return true;
    }
    else if(unknownPosition == 2) { 
        t_result = sqrt(pow(cValue,2) - pow(aValue,2));
        return true;
    }
    else if(unknownPosition == 3) { 
        t_result = pow(aValue,2) + pow(bValue,2);
        t_result = sqrt(t_result);
        return true;
    }
    return false; //User didn't choose an unknown
}

bool gravitation(double &t_result) { 
    cout << "Newton's Law of Universal Gravitation" << endl;
    cout << "F = G * (m1*m2/r^2)" << endl;
   
    const double GRAVITATIONAL = 6.67408 * pow(10,-11); 
    string gravForce; //F
    string mass1; //m1
    string mass2; // m2
    string distance; //r
    cout << "F = ";
    cin >> gravForce;
    cout << "m1 = ";
    cin >> mass1;
    cout << "m2 = ";
    cin >> mass2;
    cout << "r = ";
    cin >> distance;

    double f = 0;
    double m1 = 0;
    double m2 = 0;
    double r = 0;
    int unknownPosition = -1;
    int unknownCount = 0;

    try {
        f = stod(gravForce);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 1;
        ++unknownCount; 
    }
    try {
        m1 = stod(mass1);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 2;
        ++unknownCount; 
        if(unknownCount > 1) { 
            return false;
        }
    }
    try {
        m2 = stod(mass2);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 3;
        ++unknownCount;
        if(unknownCount > 1) { 
            return false;
        }
    }
    try {
        r = stod(distance);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 4;
        ++unknownCount;
        if(unknownCount > 1) { 
            return false;
        }
    }

    if(unknownPosition == 1) { 
        t_result = (m1*m2/pow(r,2)) * GRAVITATIONAL;
        return true;
    }
    else if(unknownPosition == 2) { 
        t_result =  (f * pow(r,2)) / (GRAVITATIONAL * m2); 
        return true; 
    }
    else if(unknownPosition == 3) { 
        t_result =  (f * pow(r,2)) / (GRAVITATIONAL * m1); 
        return true;
    }
    else if(unknownPosition == 4) { 
        t_result = sqrt((GRAVITATIONAL * m1 * m2) / f);
        return true;
    }
    return false; 
}

bool relativity(double &t_result) { 
    cout << "Einstein's Theory of Special Relativity" << endl;
    cout << "E = M * C^2" << endl;

    double const c  = 300000000; //c is the speed of the light, meaning 300000000 m/s 
    string energy;
    string mass;
    cout << "E = ";
    cin >> energy;
    cout << "M = ";
    cin >> mass;
    
    int unknownPosition = -1;
    int unknownCount = 0;
    double e = 0;
    double m = 0;

    try { 
        e = stod(energy);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 1;
        ++unknownCount;
    }
    try { 
        m = stod(mass);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 2;
        ++unknownCount;
        if(unknownCount > 1) { 
            return false;
        }
    }

    if(unknownPosition == 1) { 
        t_result = m * pow(c,2);
        return true;
    }
    else if(unknownPosition == 2) { 
        t_result = e / pow(c,2);
        return true;
    }
    return false; 
}

bool chaos(double &t_result,bool &t_bhaskara, double &x1, double &x2) { 
    cout << "Chaos Theory" << endl;
    cout << "xNew = k * xOld * (1 - xOld)" << endl;

    string xNew; 
    string k;
    string xOld;
    cout << "xNew = ";
    cin >> xNew;
    cout << "k = ";
    cin >> k;
    cout << "xOld = ";
    cin >> xOld;

    int unknownPosition = -1;
    int unknownCount = 0;
    double xNewValue = 0;
    double kValue = 0;
    double xOldValue = 0;

    try { 
        xNewValue = stod(xNew);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 1;
        ++unknownCount;
    }
    try { 
        kValue = stod(k);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 2;
        ++unknownCount;
        if(unknownCount > 1) { 
            return false;
        }
    }
    try { 
        xOldValue = stod(xOld);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 3;
        ++unknownCount;
            if(unknownCount > 1) { 
              return false;
        }
    }

    if(unknownPosition == 1) { 
        t_result = kValue * xOldValue * (1 - xOldValue);
        return true;
    }
    else if(unknownPosition == 2) { 
        t_result =  xNewValue / (xOldValue * (1-xOldValue));
        return true; 
    }
    else if(unknownPosition == 3) { 
        //After the algebrism we have xOld^2 - xOld + xNew/k.
        //We'll need to use bhaskara to solve this quadratic equation 
        //Where a = 1; 
        //b = -1;
        //c = xNew/k;
        double delta = 1 - (4 * 1 * xNewValue/kValue);
        if(delta < 0) { 
            cout << "There is no real solution for delta" << endl;
        }
        else if(delta == 0) { 
            x1 = 1/2;
            x2 = x1;
        }
        else {
            x1 = (1 + sqrt(delta)) / 2;
            x2 = (1 - sqrt(delta)) / 2;
            t_bhaskara = true;
        }
        return true;
    }
    return false;
}

bool clapeyron(double &t_result) {
    cout << "Clapeyron Equation" << endl;
    cout << "p * V = n * R * T" << endl;
    string pressure;
    string volume;
    string numberOfMols;
    string temperature;
    const double GAS = 8.31; //Source: https://pt.wikipedia.org/wiki/Constante_universal_dos_gases_perfeitos
    
    cout << "p = ";
    cin >> pressure;
    cout << "V = ";
    cin >> volume;
    cout << "n = ";
    cin >> numberOfMols;
    cout << "T = ";
    cin >> temperature;

    int unknownPosition = -1;
    int unknownCount = 0;
    double pValue = 0;
    double vValue = 0;
    double nValue = 0;
    double tValue = 0;

    try { 
        pValue = stod(pressure);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 1;
        ++unknownCount;
    }
    try { 
        vValue = stod(volume);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 2;
        ++unknownCount;
        if(unknownCount > 1) { 
            return false;
        }
    }
    try { 
        nValue = stod(numberOfMols);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 3;
        ++unknownCount;
            if(unknownCount > 1) { 
              return false;
        }
    }
    try { 
        tValue = stod(temperature);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 4;
        ++unknownCount;
            if(unknownCount > 1) { 
              return false;
        }
    }

    if(unknownPosition == 1) { 
        t_result = (nValue * GAS * tValue) / vValue;
        return true;
    }
    else if(unknownPosition == 2) { 
        t_result = (nValue * GAS * vValue) / pValue;
        return true;
    }
    else if(unknownPosition == 3) { 
        t_result = (pValue * vValue) / (GAS * tValue);
        return true;
    }
    else if(unknownPosition == 4) { 
        t_result = (pValue * vValue) / (GAS * nValue);
        return true;
    }
    return false;
}

bool torricelli(double &t_result) { 
    cout << "Torricelli's Equation" << endl;
    cout << "v^2 = v0^2 + 2 * a * S" << endl;
    
    string initialVelocity;
    string finalVelocity;
    string acceleration;
    string displacement;
    
    cout << "Final Velocity = ";
    cin >> finalVelocity;    
    cout << "Initial Velocity = ";
    cin >> initialVelocity;
    cout << "Acceletarion = ";
    cin >> acceleration;
    cout << "Displacement = ";
    cin >> displacement;
    
    double iVValue = 0;
    double fVValue = 0;
    double aValue = 0;
    double sValue = 0;
    int unknownCount = 0;
    int unknownPosition = -1;
    
    try { 
        fVValue = stod(finalVelocity);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 1;
        ++unknownCount;
    }
    try { 
        iVValue = stod(initialVelocity);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 2;
        ++unknownCount;
        if(unknownCount > 1) { 
            return false;
        }
    }
    try { 
        aValue = stod(acceleration);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 3;
        ++unknownCount;
        if(unknownCount > 1) { 
            return false;
        }
    }
    try { 
        sValue = stod(displacement);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 4;
        ++unknownCount;
        if(unknownCount > 1) { 
            return false;
        }
    }
    
    if(unknownPosition == 1) {
        t_result = sqrt(pow(iVValue,2) + (2 * aValue * sValue));
        return true; 
    }
    if(unknownPosition == 2) {
        t_result = sqrt(pow(fVValue,2) - (2 * aValue * sValue));
        return true; 
    }
    if(unknownPosition == 3) {
        t_result = (pow(fVValue,2) - pow(iVValue,2))/(2*sValue);
        return true;
    }
    if(unknownPosition == 4) {
        t_result = (pow(fVValue,2) - pow(iVValue,2))/(2*aValue);
        return true;
    }
    return false;
}

bool gauss(double &t_result) { 
    cout << "Gauss' Equation" << endl;
    cout << "1/f = 1/p + 1/p1" << endl;
    string focus;
    string objectposition;
    string imageposition;
    cout <<"Focus = ";
    cin >> focus;
    cout << "Object position = ";
    cin >> objectposition;
    cout << "Image position = ";
    cin >> imageposition;

    double fValue = 0;
    double opValue = 0;
    double ipValue = 0;
    int unknownCount = 0;
    int unknownPosition = -1;
    
    try { 
        fValue = stod(focus);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 1;
        ++unknownCount;
    }
    try { 
        opValue = stod(objectposition);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 2;
        ++unknownCount;
        if(unknownCount > 1) { 
            return false;
        }
    }
    try { 
        ipValue = stod(imageposition);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 3;
        ++unknownCount;
        if(unknownCount > 1) { 
            return false;
        }
    }
    
    if (unknownPosition == 1){
        t_result = 1/opValue + 1/ipValue;
        t_result = 1/t_result;
        return true;
    }
    if (unknownPosition == 2){
        t_result = 1/fValue - 1/ipValue;
        t_result = 1/t_result;
        return true;
    }
    if (unknownPosition == 3){
        t_result = 1/fValue - 1/opValue;
        t_result = 1/t_result;
        return true;
    }
    return false;
    
}

bool force(double &t_result) { 
    cout << "Magnetic Force on a Current-Carrying Wire Equation" << endl;
    cout << "Fm = B * i * l * sin(theta)" << endl;
    
    string magneticForce;
    string magneticField;
    string electricCurrent;
    string lenght;
    string theta;
    cout << "Magnetic Force = ";
    cin >> magneticForce;
    cout << "Magnetic Field =  ";
    cin >> magneticField;
    cout << "Electric Current = ";
    cin >> electricCurrent;
    cout << "Lenght = ";
    cin >> lenght;
    cout << "Theta = ";
    cin >> theta;
    
    double fmValue = 0;
    double bValue = 0;
    double iValue = 0;
    double lValue = 0;
    double thetaValue = 0;
    int unknownPosition = -1;
    int unknownCount = 0;
    
    try { 
        fmValue = stod(magneticForce);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 1;
        ++unknownCount;
    }
    try { 
        bValue = stod(magneticField);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 2;
        ++unknownCount;
        if(unknownCount > 1) { 
            return false;
        }
    }
    try { 
        lValue = stod(lenght);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 3;
        ++unknownCount;
        if(unknownCount > 1) { 
            return false;
        }
    }
    try { 
        thetaValue = stod(theta);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 5;
        ++unknownCount;
        if(unknownCount > 1) { 
            return false;
        }
    }
    try { 
        iValue = stod(electricCurrent);
    }
    catch(invalid_argument &ia) { 
        unknownPosition = 4;
        ++unknownCount;
        if(unknownCount > 1) { 
            return false;
        }
    }
    
    if(unknownPosition == 1) {
        t_result = bValue * iValue * lValue * sin(thetaValue);
        return true;
    }
    if(unknownPosition == 2) {
        t_result = fmValue / (iValue * lValue * sin(thetaValue));
        return true;
    }
    if(unknownPosition == 3) {
        t_result = fmValue / (bValue * lValue * sin(thetaValue));
        return true;
    }
    if(unknownPosition == 4) {
        t_result = fmValue / (bValue * iValue * sin(thetaValue));
        return true;
    }
    if(unknownPosition == 5) {
        t_result = fmValue / (iValue * lValue * iValue);
        return true;
    }
    return false;
}

int main() {
    cout << "AngryduckCalculator >(*)\n";
    writeMenu();
    cout << "Option : ";
    int option;
    cin >> option;
    cout << endl;  
    double result = 0;
    //t_result is passed by reference, its value will be modified by any function called
    //every function will return false if the user didn't choose an unknown, however it won't stop the execution 
    while(option != 0 and (option >=1 or option <= 9)) { 
        switch(option) { 
            case 1:
                if(pythagoreanTheorem(result)) {
                    cout << "Result = " << result << endl;
                }
                else {
                    cout << "ERROR: Invalid parameters, please try again\n";
                }
                break;
            case 2:
                if(gravitation(result)) { 
                    cout << "Result = " << result << endl;
                }
                else { 
                    cout << "ERROR: Invalid parameters, please try again\n";
                }
                break;
            case 3:
                if(relativity(result)) { 
                    cout << "Result = " << result << endl;
                }
                else { 
                    cout << "ERROR: Invalid parameters, please try again\n";
                }
                break;
            case 4: {
                //we might need bhaskara for this one 
                //so we need x1 and x2 for the roots of delta 
                bool bhaskara = false;
                double xOld1 = 1; 
                double xOld2 = 0;
                if(chaos(result,bhaskara,xOld1,xOld2)) {
                    if(!bhaskara) { 
                        //If bhaskara was not used, we can use result normally
                        cout << "Result = " << result << endl;
                    }
                    else {
                        //If bhaskara was used, print x1 and x2 (if they exist) 
                        cout << "xOld1 = " << xOld1 << " and " << "xOld2 = " << xOld2 << endl;
                    }
                } 
                else { 
                    cout << "ERROR: Invalid parameters, please try again\n";
                }
            }
                break;
            case 5:
                if(clapeyron(result)) { 
                    cout << "Result = " << result << endl;
                }
                else { 
                    cout << "ERROR: Invalid parameters, please try again\n";
                }
                break;
            case 6:
                if(torricelli(result)) { 
                    cout << "Result = " << result << endl;
                }
                else { 
                    cout << "ERROR: Invalid parameters, please try again\n";
                }
                break;
            case 7:
                if(gauss(result)) { 
                    cout << "Result = " << result << endl;
                }
                else { 
                    cout << "ERROR: Invalid parameters, please try again\n";
                }
                break;
            case 8:
                if(force(result)) { 
                    cout << "Result = " << result << endl;
                }
                else { 
                    cout << "ERROR: Invalid parameters, please try again\n";
                }
                break;
            case 9:
                writeMenu();
                break;
                
            default:
                cout<<"ERROR: Invalid option!\n";
                break;
        }
        cout << "Option: ";
        cin >> option;
        cout << endl;
    }//While end 
    cout << "Good bye!" << endl;
    return 0; 
}

