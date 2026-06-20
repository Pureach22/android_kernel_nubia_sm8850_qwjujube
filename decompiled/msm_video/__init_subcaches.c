__int64 __fastcall _init_subcaches(__int64 *a1)
{
  __int64 v1; // x8
  __int64 v2; // x20
  __int64 v3; // x22
  __int64 v5; // x21
  __int64 v6; // x0
  __int64 v7; // x8
  unsigned __int64 v8; // x9
  _DWORD *v9; // x10
  int v10; // t1
  __int64 v11; // x11
  __int64 v12; // x8
  unsigned int v13; // w10
  unsigned __int64 v14; // x24
  char v15; // w9
  __int64 v17; // x25
  __int64 v18; // x0
  unsigned __int64 v19; // x20

  v1 = a1[489];
  v2 = *(unsigned int *)(v1 + 120);
  if ( !(_DWORD)v2 )
    return 0;
  v3 = *(_QWORD *)(v1 + 112);
  if ( !v3 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8F46D, "err ", 0xFFFFFFFFLL, "codec", "__init_subcaches");
    return 4294967274LL;
  }
  v5 = a1[488];
  v6 = devm_kmalloc(*a1 + 16, 24 * v2, 3520);
  *(_QWORD *)(v5 + 96) = v6;
  if ( !v6 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_91A3A, "err ", 0xFFFFFFFFLL, "codec", "__init_subcaches");
    return 4294967284LL;
  }
  v7 = 0;
  v8 = 0;
  v9 = (_DWORD *)(v3 + 8);
  *(_DWORD *)(v5 + 104) = v2;
  do
  {
    ++v8;
    *(_QWORD *)(*(_QWORD *)(v5 + 96) + v7 + 8) = *((_QWORD *)v9 - 1);
    v10 = *v9;
    v9 += 4;
    v11 = *(_QWORD *)(v5 + 96) + v7;
    v7 += 24;
    *(_DWORD *)(v11 + 16) = v10;
  }
  while ( v8 < *(unsigned int *)(v5 + 104) );
  v12 = a1[488];
  v13 = *(_DWORD *)(v12 + 104);
  v14 = *(_QWORD *)(v12 + 96);
  if ( v14 < v14 + 24LL * v13 )
  {
    v15 = msm_vidc_debug;
    do
    {
      if ( (v15 & 2) != 0 )
      {
        printk(&unk_851C7, "high", 0xFFFFFFFFLL, "codec", "__init_subcaches");
        v15 = msm_vidc_debug;
        v12 = a1[488];
      }
      v13 = *(_DWORD *)(v12 + 104);
      v14 += 24LL;
    }
    while ( v14 < *(_QWORD *)(v12 + 96) + 24 * (unsigned __int64)v13 );
    v14 = *(_QWORD *)(v12 + 96);
  }
  if ( v14 >= v14 + 24LL * v13 )
    return 0;
  while ( 1 )
  {
    v17 = *a1;
    v18 = llcc_slice_getd(*(unsigned int *)(v14 + 16));
    if ( !v18 )
      break;
    v19 = v18;
    if ( (unsigned int)_devm_add_action(v17 + 16, devm_llcc_release, v18, "devm_llcc_release") )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_90476, "high", 0xFFFFFFFFLL, "codec", "devm_llcc_release");
      llcc_slice_putd(v19);
      break;
    }
    *(_QWORD *)v14 = v19;
    if ( v19 >= 0xFFFFFFFFFFFFF001LL )
      goto LABEL_28;
    v14 += 24LL;
    if ( v14 >= *(_QWORD *)(a1[488] + 96) + 24 * (unsigned __int64)*(unsigned int *)(a1[488] + 104) )
      return 0;
  }
  v19 = 0;
  *(_QWORD *)v14 = 0;
LABEL_28:
  if ( (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_851FE, "err ", 0xFFFFFFFFLL, "codec", "__init_subcaches");
    v19 = *(_QWORD *)v14;
  }
  *(_QWORD *)v14 = 0;
  if ( v19 )
    return (unsigned int)v19;
  else
    return 4294966775LL;
}
