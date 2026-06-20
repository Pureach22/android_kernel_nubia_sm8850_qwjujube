__int64 __fastcall get_tpg_clk_level(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  unsigned __int64 v4; // x7
  __int64 v5; // x9
  __int64 v6; // x10
  unsigned __int64 v7; // x11
  unsigned int v8; // w19

  if ( !a1 )
    return (unsigned int)-22;
  v3 = *(_QWORD *)(a1 + 40);
  if ( !v3 )
    return (unsigned int)-22;
  v4 = *(_QWORD *)(a1 + 24);
  v5 = v3 + 1384;
  if ( *(_BYTE *)(v3 + 2860) )
  {
    v6 = *(unsigned int *)(v3 + 2796);
    if ( (unsigned int)v6 > 0x1F )
      goto LABEL_39;
    v7 = *(int *)(v5 + 4 * v6);
    if ( v4 <= v7 )
    {
      v8 = 0;
      goto LABEL_37;
    }
  }
  if ( *(_BYTE *)(v3 + 2861) )
  {
    v6 = *(unsigned int *)(v3 + 2796);
    if ( (unsigned int)v6 > 0x1F )
      goto LABEL_39;
    v8 = 1;
    v7 = *(int *)(v5 + 4 * v6 + 128);
    if ( v4 <= v7 )
    {
LABEL_37:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x200000000LL,
        3,
        "get_tpg_clk_level",
        916,
        "match detected %s : %llu:%d level : %d",
        *(const char **)(v3 + 8 * v6 + 872),
        v4,
        v7,
        v8);
      return v8;
    }
    if ( !*(_BYTE *)(v3 + 2862) )
      goto LABEL_16;
  }
  else
  {
    v8 = 0;
    if ( !*(_BYTE *)(v3 + 2862) )
      goto LABEL_16;
  }
  v6 = *(unsigned int *)(v3 + 2796);
  if ( (unsigned int)v6 > 0x1F )
    goto LABEL_39;
  v8 = 2;
  v7 = *(int *)(v5 + 4 * v6 + 256);
  if ( v4 <= v7 )
    goto LABEL_37;
LABEL_16:
  if ( *(_BYTE *)(v3 + 2863) )
  {
    v6 = *(unsigned int *)(v3 + 2796);
    if ( (unsigned int)v6 > 0x1F )
      goto LABEL_39;
    v8 = 3;
    v7 = *(int *)(v5 + 4 * v6 + 384);
    if ( v4 <= v7 )
      goto LABEL_37;
  }
  if ( *(_BYTE *)(v3 + 2864) )
  {
    v6 = *(unsigned int *)(v3 + 2796);
    if ( (unsigned int)v6 > 0x1F )
      goto LABEL_39;
    v8 = 4;
    v7 = *(int *)(v5 + 4 * v6 + 512);
    if ( v4 <= v7 )
      goto LABEL_37;
  }
  if ( *(_BYTE *)(v3 + 2865) )
  {
    v6 = *(unsigned int *)(v3 + 2796);
    if ( (unsigned int)v6 > 0x1F )
      goto LABEL_39;
    v8 = 5;
    v7 = *(int *)(v5 + 4 * v6 + 640);
    if ( v4 <= v7 )
      goto LABEL_37;
  }
  if ( *(_BYTE *)(v3 + 2866) )
  {
    v6 = *(unsigned int *)(v3 + 2796);
    if ( (unsigned int)v6 > 0x1F )
      goto LABEL_39;
    v8 = 6;
    v7 = *(int *)(v5 + 4 * v6 + 768);
    if ( v4 <= v7 )
      goto LABEL_37;
  }
  if ( *(_BYTE *)(v3 + 2867) )
  {
    v6 = *(unsigned int *)(v3 + 2796);
    if ( (unsigned int)v6 > 0x1F )
      goto LABEL_39;
    v8 = 7;
    v7 = *(int *)(v5 + 4 * v6 + 896);
    if ( v4 <= v7 )
      goto LABEL_37;
  }
  if ( *(_BYTE *)(v3 + 2868) )
  {
    v6 = *(unsigned int *)(v3 + 2796);
    if ( (unsigned int)v6 > 0x1F )
      goto LABEL_39;
    v8 = 8;
    v7 = *(int *)(v5 + 4 * v6 + 1024);
    if ( v4 <= v7 )
      goto LABEL_37;
  }
  if ( !*(_BYTE *)(v3 + 2869) )
    return v8;
  v6 = *(unsigned int *)(v3 + 2796);
  if ( (unsigned int)v6 <= 0x1F )
  {
    v8 = 9;
    v7 = *(int *)(v5 + 4 * v6 + 1152);
    if ( v4 <= v7 )
      goto LABEL_37;
    return v8;
  }
LABEL_39:
  __break(0x5512u);
  return tpg_hw_config(a1, a2, a3);
}
