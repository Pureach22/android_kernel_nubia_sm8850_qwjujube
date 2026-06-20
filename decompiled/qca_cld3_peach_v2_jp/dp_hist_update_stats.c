int *__fastcall dp_hist_update_stats(int *result, int a2)
{
  int v2; // w8
  bool v3; // cc
  __int64 v4; // x8
  int v5; // w8

  if ( !result )
    return result;
  v2 = *result;
  if ( *result > 2 )
  {
    if ( (unsigned int)(v2 - 5) < 2 )
    {
      if ( a2 < 2 )
        goto LABEL_70;
      if ( a2 >= 4 )
      {
        if ( a2 >= 6 )
        {
          if ( a2 >= 8 )
          {
            if ( a2 >= 10 )
            {
              if ( a2 >= 20 )
              {
                if ( a2 >= 30 )
                {
                  if ( a2 >= 40 )
                  {
                    if ( a2 >= 50 )
                    {
LABEL_66:
                      if ( a2 >= 100 )
                      {
                        if ( a2 >= 250 )
                        {
                          v3 = a2 < 500;
                          goto LABEL_92;
                        }
                        goto LABEL_90;
                      }
                      goto LABEL_88;
                    }
LABEL_86:
                    v4 = 8;
                    goto LABEL_94;
                  }
LABEL_84:
                  v4 = 7;
                  goto LABEL_94;
                }
LABEL_82:
                v4 = 6;
                goto LABEL_94;
              }
LABEL_80:
              v4 = 5;
              goto LABEL_94;
            }
LABEL_78:
            v4 = 4;
            goto LABEL_94;
          }
LABEL_76:
          v4 = 3;
          goto LABEL_94;
        }
LABEL_74:
        v4 = 2;
        goto LABEL_94;
      }
    }
    else if ( v2 == 3 )
    {
      if ( a2 < 250 )
        goto LABEL_70;
      if ( a2 >= 500 )
      {
        if ( a2 >= 750 )
        {
          if ( a2 >= 1000 )
          {
            if ( a2 >= 1500 )
            {
              if ( a2 >= 2000 )
              {
                if ( a2 >= 2500 )
                {
                  if ( a2 >= 5000 )
                  {
                    if ( a2 >= 6000 )
                    {
                      if ( a2 >= 7000 )
                      {
                        if ( a2 >= 8000 )
                        {
                          v3 = a2 < 9000;
LABEL_92:
                          v4 = 11;
                          if ( !v3 )
                            v4 = 12;
                          goto LABEL_94;
                        }
LABEL_90:
                        v4 = 10;
                        goto LABEL_94;
                      }
LABEL_88:
                      v4 = 9;
                      goto LABEL_94;
                    }
                    goto LABEL_86;
                  }
                  goto LABEL_84;
                }
                goto LABEL_82;
              }
              goto LABEL_80;
            }
            goto LABEL_78;
          }
          goto LABEL_76;
        }
        goto LABEL_74;
      }
    }
    else
    {
      if ( v2 != 4 )
        goto LABEL_95;
      if ( a2 < 10 )
        goto LABEL_70;
      if ( a2 >= 20 )
      {
        if ( a2 >= 30 )
        {
          if ( a2 >= 40 )
          {
            if ( a2 >= 50 )
            {
              if ( a2 >= 60 )
              {
                if ( a2 >= 70 )
                {
                  if ( a2 >= 80 )
                  {
                    if ( a2 >= 90 )
                    {
                      if ( a2 >= 100 )
                      {
                        if ( a2 >= 150 )
                        {
                          v3 = a2 < 200;
                          goto LABEL_92;
                        }
                        goto LABEL_90;
                      }
                      goto LABEL_88;
                    }
                    goto LABEL_86;
                  }
                  goto LABEL_84;
                }
                goto LABEL_82;
              }
              goto LABEL_80;
            }
            goto LABEL_78;
          }
          goto LABEL_76;
        }
        goto LABEL_74;
      }
    }
LABEL_72:
    v4 = 1;
    goto LABEL_94;
  }
  switch ( v2 )
  {
    case 0:
      if ( a2 < 1 )
        goto LABEL_70;
      if ( a2 != 1 )
      {
        if ( a2 >= 3 )
        {
          if ( a2 != 3 )
          {
            if ( a2 >= 5 )
            {
              if ( a2 != 5 )
              {
                if ( a2 >= 7 )
                {
                  if ( a2 != 7 )
                  {
                    if ( a2 >= 9 )
                    {
                      if ( a2 != 9 )
                      {
                        if ( a2 >= 11 )
                        {
                          v4 = 11;
                          if ( a2 != 11 )
                            v4 = 12;
                          goto LABEL_94;
                        }
                        goto LABEL_90;
                      }
                      goto LABEL_88;
                    }
                    goto LABEL_86;
                  }
                  goto LABEL_84;
                }
                goto LABEL_82;
              }
              goto LABEL_80;
            }
            goto LABEL_78;
          }
          goto LABEL_76;
        }
        goto LABEL_74;
      }
      goto LABEL_72;
    case 1:
      if ( a2 < 10 )
        goto LABEL_70;
      if ( a2 >= 20 )
      {
        if ( a2 >= 30 )
        {
          if ( a2 >= 40 )
          {
            if ( a2 >= 50 )
            {
              if ( a2 >= 60 )
              {
                if ( a2 >= 70 )
                {
                  if ( a2 >= 80 )
                  {
                    if ( a2 >= 90 )
                      goto LABEL_66;
                    goto LABEL_86;
                  }
                  goto LABEL_84;
                }
                goto LABEL_82;
              }
              goto LABEL_80;
            }
            goto LABEL_78;
          }
          goto LABEL_76;
        }
        goto LABEL_74;
      }
      goto LABEL_72;
    case 2:
      if ( a2 >= 5 )
      {
        if ( a2 >= 10 )
        {
          if ( a2 >= 15 )
          {
            if ( a2 >= 20 )
            {
              if ( a2 >= 25 )
              {
                if ( a2 >= 30 )
                {
                  if ( a2 >= 35 )
                  {
                    if ( a2 >= 40 )
                    {
                      if ( a2 >= 45 )
                      {
                        if ( a2 >= 50 )
                        {
                          if ( a2 >= 55 )
                          {
                            v3 = a2 < 60;
                            goto LABEL_92;
                          }
                          goto LABEL_90;
                        }
                        goto LABEL_88;
                      }
                      goto LABEL_86;
                    }
                    goto LABEL_84;
                  }
                  goto LABEL_82;
                }
                goto LABEL_80;
              }
              goto LABEL_78;
            }
            goto LABEL_76;
          }
          goto LABEL_74;
        }
        goto LABEL_72;
      }
LABEL_70:
      v4 = 0;
LABEL_94:
      ++*(_QWORD *)&result[2 * v4 + 2];
      break;
  }
LABEL_95:
  if ( result[29] > a2 )
    result[29] = a2;
  if ( result[28] < a2 )
    result[28] = a2;
  v5 = result[30];
  if ( v5 )
    a2 = (v5 + a2) / 2;
  result[30] = a2;
  return result;
}
