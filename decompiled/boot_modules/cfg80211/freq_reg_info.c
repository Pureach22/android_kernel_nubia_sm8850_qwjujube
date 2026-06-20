unsigned __int64 __fastcall freq_reg_info(__int64 a1, unsigned int a2)
{
  unsigned int v3; // w11
  __int64 *v4; // x8
  __int64 v5; // x23
  unsigned int v6; // w25
  unsigned int v7; // w20
  unsigned int v8; // w26
  bool v9; // w22
  unsigned int v10; // w28
  unsigned __int64 v11; // x21
  int v12; // w8
  int v13; // w8
  char does_bw_fit_range; // w0
  int v15; // w8
  unsigned int v17; // [xsp+Ch] [xbp-4h]

  if ( a2 >= 0xF4240 )
    v3 = 20000;
  else
    v3 = 1000;
  if ( (*((_DWORD *)last_request + 5) | 2) == 3 || !*(_QWORD *)(a1 + 384) )
    v4 = &cfg80211_regdomain;
  else
    v4 = (__int64 *)(a1 + 384);
  v5 = *v4;
  v6 = 8;
  v7 = 20000;
  if ( a2 <= 0x2AEA540 )
    v8 = 2000000;
  else
    v8 = 20000000;
  v17 = v3;
  while ( 1 )
  {
    if ( !v5 )
    {
      v11 = -22;
      if ( v6 > 8 )
        goto LABEL_38;
      goto LABEL_32;
    }
    if ( *(_DWORD *)(v5 + 16) )
      break;
    v11 = -34;
LABEL_31:
    if ( v6 > 8 )
      goto LABEL_38;
LABEL_32:
    v15 = _freq_reg_info_bws[v6--];
    v7 = 1000 * v15;
    if ( 1000 * v15 < v3 )
      return v11;
  }
  v9 = 0;
  v10 = 0;
  do
  {
    v11 = v5 + 28 + 96LL * (int)v10;
    if ( v9 )
      goto LABEL_23;
    v12 = a2 - *(_DWORD *)v11;
    if ( v12 < 0 )
      v12 = *(_DWORD *)v11 - a2;
    if ( v12 <= v8 )
    {
LABEL_23:
      v9 = 1;
    }
    else
    {
      v13 = a2 - *(_DWORD *)(v11 + 4);
      if ( v13 < 0 )
        v13 = *(_DWORD *)(v11 + 4) - a2;
      v9 = v13 <= v8;
    }
    does_bw_fit_range = cfg80211_does_bw_fit_range(v5 + 28 + 96LL * (int)v10, a2, v7);
    if ( v9 && (does_bw_fit_range & 1) != 0 )
    {
      v3 = v17;
      if ( v11 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_31;
      return v11;
    }
    ++v10;
  }
  while ( v10 < *(_DWORD *)(v5 + 16) );
  v3 = v17;
  if ( v9 )
    v11 = -22;
  else
    v11 = -34;
  if ( v6 <= 8 )
    goto LABEL_32;
LABEL_38:
  __break(0x5512u);
  return v11;
}
