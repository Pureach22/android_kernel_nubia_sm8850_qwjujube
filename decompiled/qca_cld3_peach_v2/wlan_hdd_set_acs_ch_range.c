__int64 __fastcall wlan_hdd_set_acs_ch_range(__int64 a1, unsigned int a2, char a3, char a4)
{
  unsigned int v4; // w19
  __int64 v5; // x20
  unsigned int v6; // w8
  char v7; // w21
  char v8; // w22
  int v9; // w0
  int v10; // w8
  unsigned int *v11; // x8
  __int64 v12; // x9
  unsigned int v13; // w10
  unsigned int v14; // w11
  unsigned int v16; // w13
  unsigned int v17; // w12

  if ( a2 <= 4 && ((0x17u >> a2) & 1) != 0 )
  {
    v4 = dword_AF74DC[a2];
    v5 = a1;
    v6 = dword_AF74C8[a2];
    *(_DWORD *)(a1 + 1148) = dword_AF74B4[a2];
    v7 = a4;
    v8 = a3;
    *(_DWORD *)(a1 + 1152) = wlan_reg_ch_to_freq(v6);
    v9 = wlan_reg_ch_to_freq(v4);
    a3 = v8;
    a4 = v7;
    v10 = v9;
    a1 = v5;
    *(_DWORD *)(v5 + 1156) = v10;
  }
  if ( (a3 & 1) != 0 )
  {
    *(_DWORD *)(a1 + 1148) = 16;
    if ( (a4 & 1) == 0 )
      goto LABEL_6;
  }
  else if ( (a4 & 1) == 0 )
  {
LABEL_6:
    v11 = *(unsigned int **)(a1 + 1160);
    if ( v11 )
      goto LABEL_7;
    return 4294967274LL;
  }
  *(_DWORD *)(a1 + 1148) = 256;
  v11 = *(unsigned int **)(a1 + 1160);
  if ( v11 )
  {
LABEL_7:
    v12 = *(unsigned __int8 *)(a1 + 1168);
    v13 = *v11;
    *(_DWORD *)(a1 + 1152) = *v11;
    v14 = v11[v12 - 1];
    *(_DWORD *)(a1 + 1156) = v14;
    if ( !v12 )
      return 0;
    while ( 1 )
    {
      v16 = *v11;
      if ( v13 > *v11 && v16 )
      {
        *(_DWORD *)(a1 + 1152) = v16;
        v13 = v16;
        v17 = *v11;
        if ( v14 >= *v11 )
          goto LABEL_10;
      }
      else
      {
        v17 = *v11;
        if ( v14 >= v16 )
          goto LABEL_10;
      }
      v14 = v17;
      *(_DWORD *)(a1 + 1156) = v17;
LABEL_10:
      --v12;
      ++v11;
      if ( !v12 )
        return 0;
    }
  }
  return 4294967274LL;
}
