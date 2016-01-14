#ifndef __ATOMHEART_INPUTMANAGER_H_
#define __ATOMHEART_INPUTMANAGER_H_

#include <map>
#include <SFML/Graphics.hpp>

/*NEW AND REVOLUTIONARY IMPUT MANAGER
  Example of usage
    * first, add a new line on enum InputAction (i.e. jump)
    the line will be -> " jump , "
    
    *second, bind it to a keyboard mouse or joistick trigger
    InputManager::bind(InputAction::jump, sf::Keyboard::Space);
    
    *third we use it by asking to input manager and acting
    if(InputManager::action(jump)) jump();
*/

namespace InputAction{
    //Possible Actions listed below
    enum action {
        up          ,
        down        ,
        left        ,
        right       ,
        jump        ,
        attack      ,
        pause       ,
        inputQtt
    };
}

class InputManager {
    
 public:

    static void  update();
    static float action(int s);

    static bool isBinded(int s);
    static bool isMouseBinded(int s);
    static bool isKeyboardBinded(int s);
    static bool isJoystickBinded(int s);

    static void bind(int s, sf::Keyboard::Key k);
    static void bind(int s, sf::Mouse::Button m);
    static void bind(int s, int nPad, sf::Joystick::Axis ja);
    static void bind(int s, int nPad, int nButton);
     
private:
    
    struct helperK {
        bool b;
        sf::Keyboard::Key k;
        helperK(sf::Keyboard::Key k) {
            this->b = false;
            this->k = k;
        }
    };
    
    struct helperM {
        bool b;
        sf::Mouse::Button m;
        helperM(sf::Mouse::Button m) {
            this->b = false;
            this->m = m;
        }
    };
    
    struct helperJA {
        int pos;
        sf::Joystick::Axis j;
        int nPad;
        helperJA(sf::Joystick::Axis j, int nPad) {
            this->pos = 0;
            this->j = j;
            this->nPad = nPad;
        }
    };
    
    struct helperJB {
        bool b;
        int nPad;
        int nButton;
        helperJB(int nPad, int nButton) {
            this->b = false;
            this->nPad = nPad;
            this->nButton = nButton;
        }
    };

    static std::map<int, helperM>  mouseBinds;
    static std::map<int, helperK>  keyboardBinds;
    static std::map<int, helperJA> joystickAxisBinds;
    static std::map<int, helperJB> joystickButtonBinds;
     
};

#endif
