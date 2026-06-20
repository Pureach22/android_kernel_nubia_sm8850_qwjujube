__int64 __fastcall wmi_fill_oui_extensions(__int64 result, int a2, _DWORD *a3, char a4)
{
  _BYTE *v4; // x8
  int v5; // w11
  int v6; // w12
  int v7; // w13
  int v8; // w14
  int v9; // w15
  int v10; // w16
  int v11; // w10

  if ( a2 )
  {
    v4 = (_BYTE *)(result + 64);
    do
    {
      *a3 = 45023256;
      a3[2] = *((_DWORD *)v4 - 16) & 0x3F;
      a3[3] = *((_DWORD *)v4 - 15);
      a3[4] = *((_DWORD *)v4 - 14);
      a3[5] = *((_DWORD *)v4 - 12);
      v11 = *((_DWORD *)v4 - 10);
      a3[6] = v11;
      if ( (a4 & 1) == 0 || *v4 )
        v5 = 1;
      else
        v5 = 2;
      v6 = *((_DWORD *)v4 - 15);
      v7 = *((_DWORD *)v4 - 14);
      v8 = *((_DWORD *)v4 - 13);
      v9 = *((_DWORD *)v4 - 12);
      v10 = *((_DWORD *)v4 - 11);
      --a2;
      v4 += 68;
      a3[1] = v7 + v6 + v8 + v9 + v10 + v11 + v5;
      a3 += 7;
    }
    while ( a2 );
  }
  return result;
}
