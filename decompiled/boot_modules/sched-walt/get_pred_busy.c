__int64 __fastcall get_pred_busy(char *a1, int a2, unsigned __int16 a3, unsigned __int16 a4)
{
  _QWORD *v4; // x7
  unsigned int v5; // w8
  int v6; // w5
  int v7; // w8
  unsigned int v8; // w8
  bool v9; // cc
  int v10; // w11
  unsigned int v11; // w10
  __int16 v12; // w6
  unsigned __int16 v13; // w8
  unsigned int v14; // w9

  if ( a1 == (char *)&init_task )
    v4 = &vendor_data_pad;
  else
    v4 = a1 + 5184;
  if ( v4[21] < 0x5F5E100u )
  {
    LOWORD(v8) = a3;
  }
  else
  {
    v5 = a4 >> a2;
    v6 = __clz(__rbit32(v5)) + a2;
    if ( v5 )
      v7 = v6;
    else
      v7 = 16;
    if ( v7 <= 15 )
    {
      v9 = v7 < 2;
      v10 = (v7 & 0x3FF) << 6;
      v11 = *((unsigned __int16 *)v4 + 28);
      if ( v7 < 2 )
        v12 = 1;
      else
        v12 = v7;
      v13 = (v12 << 6) + 64;
      if ( v9 )
        v14 = 0;
      else
        v14 = v10;
      if ( v11 >= (v13 & 0xFFC0u) || v14 > v11 )
      {
        v11 = *((unsigned __int16 *)v4 + 29);
        if ( v11 >= v13 || v14 > v11 )
        {
          v11 = *((unsigned __int16 *)v4 + 30);
          if ( v11 >= v13 || v14 > v11 )
          {
            v11 = *((unsigned __int16 *)v4 + 31);
            if ( v11 >= v13 || v14 > v11 )
            {
              v11 = *((unsigned __int16 *)v4 + 32);
              if ( v14 > v11 || v11 >= (unsigned __int16)((v12 << 6) + 64) )
                LOWORD(v11) = a3;
            }
          }
        }
      }
      v8 = (v14 + v13) >> 1;
      if ( v14 <= (unsigned __int16)v11 )
        LOWORD(v8) = v11;
      if ( a3 > (unsigned int)(unsigned __int16)v8 )
        LOWORD(v8) = a3;
    }
    else
    {
      LOWORD(v8) = a3;
    }
  }
  return (unsigned __int16)v8;
}
