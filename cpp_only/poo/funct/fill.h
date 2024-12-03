#ifndef FILLIN_H
#define FILLIN_H

class Fillin {
public:
    Fillin(int i)
        :m_valeur(i)
    {}

    int operator()()
    {
        m_valeur+=4;
        return m_valeur;
    }

private:
    int m_valeur;
};

#endif // end of FILLIN_H
