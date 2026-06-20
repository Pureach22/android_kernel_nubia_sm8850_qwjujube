__int64 __fastcall battery_module_pack_vendor_get(char *a1)
{
  __int64 v2; // x2
  __int64 result; // x0
  __int64 v4; // x2
  __int64 v5; // x1
  int v6; // w8
  __int64 v7; // x8
  unsigned int v8; // w20
  unsigned int v9; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-18h] BYREF
  __int16 v11; // [xsp+10h] [xbp-10h]
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  v11 = 0;
  v10 = 0;
  if ( (unsigned int)kstrtoint(&v10, 10, &v9) )
    goto LABEL_2;
  printk(&unk_7F03, v9, v2);
  v5 = (unsigned int)((int)v9 / 1000);
  v9 = v5;
  if ( (int)v5 <= 109 * dword_74 / 100 )
  {
    v6 = 91 * resistance_kohm / 100;
    if ( (int)v5 >= v6 )
    {
      if ( (int)v5 >= 109 * resistance_kohm / 100 || (int)v5 <= v6 )
      {
        if ( (int)v5 >= 109 * dword_58 / 100 || (int)v5 <= 91 * dword_58 / 100 )
        {
          if ( (int)v5 >= 109 * dword_5C / 100 || (int)v5 <= 91 * dword_5C / 100 )
          {
            if ( (int)v5 >= 109 * dword_60 / 100 || (int)v5 <= 91 * dword_60 / 100 )
            {
              if ( (int)v5 >= 109 * dword_64 / 100 || (int)v5 <= 91 * dword_64 / 100 )
              {
                if ( (int)v5 >= 109 * dword_68 / 100 || (int)v5 <= 91 * dword_68 / 100 )
                {
                  if ( (int)v5 >= 109 * dword_6C / 100 || (int)v5 <= 91 * dword_6C / 100 )
                  {
                    if ( (int)v5 >= 109 * dword_70 / 100 || (int)v5 <= 91 * dword_70 / 100 )
                    {
                      v8 = 0;
                      goto LABEL_11;
                    }
                    v7 = 7;
                  }
                  else
                  {
                    v7 = 6;
                  }
                }
                else
                {
                  v7 = 5;
                }
              }
              else
              {
                v7 = 4;
              }
            }
            else
            {
              v7 = 3;
            }
          }
          else
          {
            v7 = 2;
          }
        }
        else
        {
          v7 = 1;
        }
      }
      else
      {
        v7 = 0;
      }
      v8 = battery_vendor_id[v7];
LABEL_11:
      printk(&unk_7D46, v5, v8);
      result = snprintf(a1, 0x1000u, "%2d", v8);
      goto LABEL_3;
    }
  }
  printk(&unk_7E27, v5, v4);
LABEL_2:
  result = 0xFFFFFFFFLL;
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
