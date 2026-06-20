unsigned __int64 __fastcall _init_reset_clocks(_QWORD *a1)
{
  __int64 v1; // x8
  __int64 v2; // x20
  __int64 v3; // x21
  bool v4; // zf
  __int64 v6; // x22
  __int64 v7; // x0
  __int64 v8; // x8
  unsigned __int64 v9; // x9
  _BYTE *v10; // x10
  char v11; // t1
  __int64 v12; // x11
  __int64 v13; // x8
  unsigned int v14; // w10
  unsigned __int64 v15; // x24
  char v16; // w9
  unsigned __int64 result; // x0

  v1 = a1[489];
  v2 = *(_QWORD *)(v1 + 96);
  v3 = *(unsigned int *)(v1 + 104);
  if ( v2 )
    v4 = (_DWORD)v3 == 0;
  else
    v4 = 1;
  if ( v4 )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_8E96A, "high", 0xFFFFFFFFLL, "codec", "__init_reset_clocks");
    return 0;
  }
  v6 = a1[488];
  v7 = devm_kmalloc(*a1 + 16LL, 24 * v3, 3520);
  *(_QWORD *)(v6 + 80) = v7;
  if ( !v7 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8AC4C, "err ", 0xFFFFFFFFLL, "codec", "__init_reset_clocks");
    return 4294967284LL;
  }
  v8 = 0;
  v9 = 0;
  v10 = (_BYTE *)(v2 + 8);
  *(_DWORD *)(v6 + 88) = v3;
  do
  {
    ++v9;
    *(_QWORD *)(*(_QWORD *)(v6 + 80) + v8 + 8) = *((_QWORD *)v10 - 1);
    v11 = *v10;
    v10 += 16;
    v12 = *(_QWORD *)(v6 + 80) + v8;
    v8 += 24;
    *(_BYTE *)(v12 + 16) = v11;
  }
  while ( v9 < *(unsigned int *)(v6 + 88) );
  v13 = a1[488];
  v14 = *(_DWORD *)(v13 + 88);
  v15 = *(_QWORD *)(v13 + 80);
  if ( v15 < v15 + 24LL * v14 )
  {
    v16 = msm_vidc_debug;
    do
    {
      if ( (v16 & 2) != 0 )
      {
        printk(&unk_8518C, "high", 0xFFFFFFFFLL, "codec", "__init_reset_clocks");
        v16 = msm_vidc_debug;
        v13 = a1[488];
      }
      v14 = *(_DWORD *)(v13 + 88);
      v15 += 24LL;
    }
    while ( v15 < *(_QWORD *)(v13 + 80) + 24 * (unsigned __int64)v14 );
    v15 = *(_QWORD *)(v13 + 80);
  }
  if ( v15 >= v15 + 24LL * v14 )
    return 0;
  while ( 1 )
  {
    result = _devm_reset_control_get(*a1 + 16LL, *(_QWORD *)(v15 + 8), 0, 0, 0, (*(_BYTE *)(v15 + 16) & 1) == 0);
    *(_QWORD *)v15 = result;
    if ( !result || result >= 0xFFFFFFFFFFFFF001LL )
      break;
    v15 += 24LL;
    if ( v15 >= *(_QWORD *)(a1[488] + 80LL) + 24 * (unsigned __int64)*(unsigned int *)(a1[488] + 88LL) )
      return 0;
  }
  if ( (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_8AC93, "err ", 0xFFFFFFFFLL, "codec", "__init_reset_clocks");
    result = *(_QWORD *)v15;
  }
  *(_QWORD *)v15 = 0;
  if ( result )
    return (unsigned int)result;
  else
    return 4294967274LL;
}
