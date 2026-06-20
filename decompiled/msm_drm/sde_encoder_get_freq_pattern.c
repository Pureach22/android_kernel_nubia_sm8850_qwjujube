__int64 __fastcall sde_encoder_get_freq_pattern(__int64 a1, unsigned int a2, int a3)
{
  __int64 *v3; // x8
  int v4; // w10
  __int64 v5; // x12
  int v6; // w11
  int v7; // w9
  __int64 v8; // x13
  unsigned int v9; // w13
  __int64 v10; // x8
  void *v12; // x0

  if ( !a1 )
  {
    v12 = &unk_21233E;
LABEL_24:
    printk(v12, "sde_encoder_get_freq_pattern");
    return 0;
  }
  v3 = *(__int64 **)(a1 + 4800);
  if ( !v3 )
  {
    v10 = *(_QWORD *)(a1 + 328);
    if ( v10 && (*(_BYTE *)(v10 + 2289) & 1) != 0 )
      return 0;
    v12 = &unk_26C735;
    goto LABEL_24;
  }
  v4 = *((_DWORD *)v3 + 2);
  if ( !v4 )
    goto LABEL_21;
  v5 = *v3;
  v6 = 0;
  v7 = -1;
  while ( 1 )
  {
    v8 = v5 + 32LL * v6;
    if ( *(_DWORD *)(v8 + 20) == a3 )
      break;
LABEL_5:
    if ( v4 == ++v6 )
      goto LABEL_18;
  }
  v9 = *(_DWORD *)(v8 + 12);
  if ( v9 != a2 )
  {
    if ( v7 < 0 )
      v7 = v6;
    if ( v9 > a2 && v9 < *(_DWORD *)(v5 + 32LL * v7 + 12) )
      v7 = v6;
    goto LABEL_5;
  }
  v7 = v6;
LABEL_18:
  if ( v7 < 0 )
  {
LABEL_21:
    printk(&unk_21236C, "sde_encoder_get_freq_pattern");
    return 0;
  }
  return *v3 + 32LL * (unsigned int)v7;
}
