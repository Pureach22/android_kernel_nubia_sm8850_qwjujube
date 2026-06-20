int *__fastcall reg_modify_5g_maxbw(int *result, unsigned int *a2)
{
  int v2; // w9
  __int64 v3; // x8
  unsigned int v4; // w10
  unsigned int v5; // w12
  char v6; // w15
  _DWORD *v7; // x13
  unsigned int v8; // w14
  int v9; // w12
  int v10; // w15
  int v11; // w12
  unsigned int v12; // w15
  unsigned int v13; // w16
  bool v14; // cc

  v2 = *result;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  do
  {
    v7 = (_DWORD *)((char *)&center_5g + 16 * v3);
    if ( v2 == *v7 && (v6 & 1) == 0 )
    {
      v8 = *((unsigned __int16 *)result + 11);
      if ( v8 - 161 >= 0xFFFFFF73 )
      {
        do
        {
          if ( (unsigned __int8)v8 > 0x4Fu )
          {
            if ( (unsigned __int8)v8 == 80 )
            {
              v11 = v7[2];
              v4 = v11 - 40;
              v5 = v11 + 40;
            }
            else if ( (unsigned __int8)v8 == 160 )
            {
              v10 = v7[3];
              if ( v10 )
              {
                v4 = v10 - 80;
                v5 = v10 + 80;
              }
              else
              {
                v8 >>= 1;
                *((_WORD *)result + 11) = v8;
              }
            }
          }
          else if ( (unsigned __int8)v8 == 20 )
          {
            v4 = *v7 - 10;
            v5 = *v7 + 10;
          }
          else if ( (unsigned __int8)v8 == 40 )
          {
            v9 = v7[1];
            v4 = v9 - 20;
            v5 = v9 + 20;
          }
          v13 = *a2;
          v12 = a2[1];
          if ( v12 <= v5 && v13 >= v4 || v13 > v4 && v13 < v5 || v12 > v4 && v12 < v5 )
          {
            v8 >>= 1;
            *((_WORD *)result + 11) = v8;
          }
          else
          {
            v14 = v12 > v4;
            v6 = 1;
            if ( !v14 || v13 >= v5 )
              goto LABEL_3;
          }
        }
        while ( v8 - 161 > 0xFFFFFF72 );
      }
      v6 = 0;
    }
LABEL_3:
    ++v3;
  }
  while ( v3 != 28 );
  return result;
}
