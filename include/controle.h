#ifndef __CONTROLE_H_
#define __CONTROLE_H_

//CODIGO EXTREMAMENTE LIXO
class Controle {

    public:
    bool up;
    bool down;
    bool left;
    bool right;
    bool a;
    bool b;
    bool x;
    bool y;
    bool r;
    bool l;
    bool start;
    bool select;

    bool old_up;
    bool old_down;
    bool old_left;
    bool old_right;
    bool old_a;
    bool old_b;
    bool old_x;
    bool old_y;
    bool old_r;
    bool old_l;
    bool old_start;
    bool old_select;

    void reset () {
        up = false;
        down = false;
        left = false;
        right = false;
        a = false;
        b = false;
        x = false;
        y = false;
        r = false;
        l = false;
        start = false;
        select = false;
    }

    void updateOld () {
        old_up = up;
        old_down = down;
        old_left = left;
        old_right = right;
        old_a = a;
        old_b = b;
        old_x = x;
        old_y = y;
        old_r = r;
        old_l = l;
        old_start = start;
        old_select = select;
    }
};

#endif