__int64 __fastcall _update_residency_stats(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 v5; // x0
  __int64 v6; // x8
  unsigned __int64 v7; // x20
  __int64 v8; // x5
  _QWORD *v9; // x9
  __int64 v10; // x10
  _QWORD *v12; // x9
  _QWORD *v13; // x8

  if ( (msm_vidc_debug & 0x42) == 0 || *(_BYTE *)(a2 + 20) != 1 || *(_QWORD *)(a2 + 24) == a3 )
    return 0;
  v5 = ktime_get(a1);
  v6 = a2;
  v7 = v5 / 0x3E8;
  if ( a2 )
  {
    v8 = a3;
    v9 = (_QWORD *)(a2 + 40);
    while ( 1 )
    {
      v9 = (_QWORD *)*v9;
      if ( v9 == (_QWORD *)(a2 + 40) )
        break;
      if ( v9[2] == *(_QWORD *)(a2 + 24) )
      {
        if ( !v9 )
          break;
        v10 = v9[3];
        if ( v10 )
          v9[4] += v7 - v10;
        v9[3] = 0;
        if ( a3 )
          goto LABEL_15;
        return 0;
      }
    }
LABEL_14:
    if ( v8 )
      goto LABEL_15;
    return 0;
  }
  v8 = a3;
  if ( (msm_vidc_debug & 1) == 0 )
    goto LABEL_14;
  printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "get_residency_stats");
  v6 = 0;
  v8 = a3;
  if ( !a3 )
    return 0;
LABEL_15:
  if ( v6 )
  {
    v12 = (_QWORD *)(v6 + 40);
    v13 = (_QWORD *)(v6 + 40);
    while ( 1 )
    {
      v13 = (_QWORD *)*v13;
      if ( v13 == v12 )
        break;
      if ( v13[2] == v8 )
      {
        if ( !v13 )
          break;
        v13[3] = v7;
        return 0;
      }
    }
  }
  else if ( (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "get_residency_stats");
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    goto LABEL_27;
  }
  if ( (msm_vidc_debug & 1) == 0 )
    return 4294967274LL;
LABEL_27:
  printk(&unk_83B14, "err ", 0xFFFFFFFFLL, "codec", "__update_residency_stats");
  return 4294967274LL;
}
