__int64 __fastcall cm_get_ch_width(__int64 a1, __int64 a2)
{
  char is_24ghz_ch_freq; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  int v13; // w8
  int v14; // w10
  int v15; // w9
  int v16; // w9
  unsigned int v17; // w10
  int v18; // w10
  char v19; // w11
  unsigned int v20; // w8
  int v21; // w10
  unsigned int v22; // w4
  unsigned __int16 v23; // w8
  unsigned __int8 v24; // w9
  unsigned int v25; // w10
  char v26; // w11
  unsigned int v28; // w5

  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(unsigned int *)(a1 + 1192));
  v13 = *(unsigned __int16 *)(a2 + 2);
  v14 = *(_DWORD *)(a1 + 52);
  if ( (is_24ghz_ch_freq & 1) != 0 )
    v15 = 16;
  else
    v15 = 2;
  v16 = v13 & v15;
  if ( v14 <= 22 )
  {
    if ( v14 > 16 )
    {
      if ( (unsigned int)(v14 - 17) >= 2 )
      {
        v17 = v14 - 19;
LABEL_17:
        if ( v17 < 2 )
        {
LABEL_18:
          v18 = 160;
          goto LABEL_24;
        }
LABEL_22:
        v19 = 0;
        v18 = 20;
        goto LABEL_25;
      }
LABEL_23:
      v18 = 80;
      goto LABEL_24;
    }
    if ( (unsigned int)(v14 - 7) >= 4 && (unsigned int)(v14 - 13) >= 4 )
      goto LABEL_22;
  }
  else if ( v14 > 32 )
  {
    if ( v14 >= 37 )
    {
      if ( v14 != 37 )
      {
        if ( v14 == 40 )
        {
          v18 = 320;
          goto LABEL_24;
        }
        if ( v14 == 39 )
          goto LABEL_18;
        goto LABEL_22;
      }
      goto LABEL_23;
    }
  }
  else if ( (unsigned int)(v14 - 23) >= 4 )
  {
    if ( (unsigned int)(v14 - 27) >= 2 )
    {
      v17 = v14 - 29;
      goto LABEL_17;
    }
    goto LABEL_23;
  }
  v18 = 40;
LABEL_24:
  v19 = 1;
LABEL_25:
  if ( ((unsigned __int8)v19 & ((v13 & 1) == 0)) != 0 )
    v20 = 20;
  else
    v20 = v18;
  if ( v20 >= 0x28 )
    v21 = 40;
  else
    v21 = v20;
  if ( v16 )
    v22 = v20;
  else
    v22 = v21;
  if ( !*(_QWORD *)(a1 + 1800) || !*(_QWORD *)(a1 + 1808) )
    return v22;
  v23 = *(_WORD *)(a1 + 1204);
  if ( v23 )
  {
    v24 = 0;
    do
    {
      v25 = v23;
      v26 = v23 & 1;
      v23 >>= 1;
      v24 += v26;
    }
    while ( v25 > 1 );
  }
  else
  {
    v24 = 0;
  }
  v28 = 20 * v24;
  if ( v22 > v28 )
    return v22 - v28;
  qdf_trace_msg(0x68u, 2u, "%s: Invalid bw %d punctured_bw %d", v5, v6, v7, v8, v9, v10, v11, v12, "cm_get_ch_width");
  return 20;
}
