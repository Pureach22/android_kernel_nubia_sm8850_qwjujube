__int64 __fastcall qmi_calc_min_msg_len(__int64 a1, int a2)
{
  __int64 v2; // x20
  unsigned int v4; // w21
  int v5; // w8
  __int64 v6; // x8
  int v7; // w9
  int v8; // w10
  int v9; // w8
  int v10; // w8
  unsigned int v11; // w8
  int v12; // w10
  int v13; // w8

  if ( a1 )
  {
    v2 = a1;
    v4 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v5 = *(_DWORD *)v2;
          if ( *(_DWORD *)v2 != 1 )
            break;
          if ( a2 > 1 )
          {
            v2 += 32;
          }
          else
          {
            v6 = v2;
            do
            {
              v7 = *(unsigned __int8 *)(v6 + 16);
              v8 = *(unsigned __int8 *)(v6 + 48);
              v2 = v6 + 32;
              v6 += 32;
            }
            while ( v7 == v8 );
          }
        }
        if ( v5 > 8 )
          break;
        if ( !v5 )
          return v4;
        if ( v5 != 2 )
          goto LABEL_24;
        v9 = *(_DWORD *)(v2 + 8);
        v2 += 32;
        if ( v9 == 1 )
          v10 = 1;
        else
          v10 = 2;
        v4 += v10;
      }
      if ( v5 == 9 )
      {
        v13 = qmi_calc_min_msg_len(*(_QWORD *)(v2 + 24), (unsigned int)(a2 + 1)) + v4;
        goto LABEL_26;
      }
      if ( v5 != 10 )
      {
LABEL_24:
        v13 = v4 + *(_DWORD *)(v2 + 8) * *(_DWORD *)(v2 + 4);
        goto LABEL_26;
      }
      v11 = *(_DWORD *)(v2 + 4);
      if ( v11 < 0x100 )
        v12 = 1;
      else
        v12 = 2;
      if ( a2 <= 1 )
        v12 = 0;
      v13 = v4 + v12 + *(_DWORD *)(v2 + 8) * v11;
LABEL_26:
      v2 += 32;
      if ( a2 == 1 )
        v4 = v13 + 3;
      else
        v4 = v13;
    }
  }
  return 0;
}
