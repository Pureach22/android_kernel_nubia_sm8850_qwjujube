__int64 __fastcall check_client(unsigned int a1, unsigned int a2, int a3)
{
  __int64 *v4; // x8
  unsigned int v5; // w9

  if ( !num_clients )
    goto LABEL_5;
  if ( memblock[0] == __PAIR64__(a2, a1) )
    return 0;
  if ( num_clients == 1 )
    goto LABEL_5;
  if ( qword_8598 == __PAIR64__(a2, a1) )
    return 1;
  if ( num_clients == 2 )
    goto LABEL_5;
  if ( qword_85F8 == __PAIR64__(a2, a1) )
    return 2;
  if ( num_clients == 3 )
    goto LABEL_5;
  if ( qword_8658 == __PAIR64__(a2, a1) )
    return 3;
  if ( num_clients == 4 )
    goto LABEL_5;
  if ( qword_86B8 == __PAIR64__(a2, a1) )
    return 4;
  if ( num_clients == 5 )
    goto LABEL_5;
  if ( qword_8718 == __PAIR64__(a2, a1) )
    return 5;
  if ( num_clients == 6 )
    goto LABEL_5;
  if ( qword_8778 == __PAIR64__(a2, a1) )
    return 6;
  if ( num_clients == 7 )
    goto LABEL_5;
  if ( qword_87D8 == __PAIR64__(a2, a1) )
    return 7;
  if ( num_clients == 8 )
    goto LABEL_5;
  if ( qword_8838 == __PAIR64__(a2, a1) )
    return 8;
  if ( num_clients == 9 )
    goto LABEL_5;
  if ( qword_8898 == __PAIR64__(a2, a1) )
    return 9;
  if ( num_clients == 10 )
  {
LABEL_5:
    if ( a3 )
      return 1000;
    v4 = memblock;
    if ( LODWORD(memblock[0]) == 1000 )
    {
      v5 = 0;
    }
    else
    {
      v4 = &qword_8598;
      if ( (_DWORD)qword_8598 == 1000 )
      {
        v5 = 1;
      }
      else
      {
        v4 = &qword_85F8;
        if ( (_DWORD)qword_85F8 == 1000 )
        {
          v5 = 2;
        }
        else
        {
          v4 = &qword_8658;
          if ( (_DWORD)qword_8658 == 1000 )
          {
            v5 = 3;
          }
          else
          {
            v4 = &qword_86B8;
            if ( (_DWORD)qword_86B8 == 1000 )
            {
              v5 = 4;
            }
            else
            {
              v4 = &qword_8718;
              if ( (_DWORD)qword_8718 == 1000 )
              {
                v5 = 5;
              }
              else
              {
                v4 = &qword_8778;
                if ( (_DWORD)qword_8778 == 1000 )
                {
                  v5 = 6;
                }
                else
                {
                  v4 = &qword_87D8;
                  if ( (_DWORD)qword_87D8 == 1000 )
                  {
                    v5 = 7;
                  }
                  else
                  {
                    v4 = &qword_8838;
                    if ( (_DWORD)qword_8838 == 1000 )
                    {
                      v5 = 8;
                    }
                    else
                    {
                      v4 = &qword_8898;
                      if ( (_DWORD)qword_8898 != 1000 )
                        return 1000;
                      v5 = 9;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    *(_DWORD *)v4 = a1;
    *((_DWORD *)v4 + 1) = a2;
    v4[2] = 0;
    return v5;
  }
  else
  {
    __break(0x5512u);
    return fill_alloc_response();
  }
}
