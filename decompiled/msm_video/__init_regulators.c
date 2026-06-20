unsigned __int64 __fastcall _init_regulators(_QWORD *a1)
{
  __int64 v1; // x8
  __int64 v2; // x21
  __int64 v3; // x22
  __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x8
  unsigned __int64 v8; // x9
  _BYTE *v9; // x10
  char v10; // t1
  __int64 v11; // x11
  __int64 v12; // x8
  unsigned int v13; // w10
  unsigned __int64 *v14; // x24
  char v15; // w9
  unsigned __int64 result; // x0
  unsigned int v17; // w19

  v1 = a1[489];
  v2 = *(unsigned int *)(v1 + 24);
  if ( !(_DWORD)v2 )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_82DCE, "high", 0xFFFFFFFFLL, "codec", "__init_regulators");
    return 0;
  }
  v3 = *(_QWORD *)(v1 + 16);
  if ( !v3 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8F5E2, "err ", 0xFFFFFFFFLL, "codec", "__init_regulators");
    return 4294967274LL;
  }
  v5 = a1[488];
  v6 = devm_kmalloc(*a1 + 16LL, 24 * v2, 3520);
  *(_QWORD *)(v5 + 32) = v6;
  if ( !v6 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_933FA, "err ", 0xFFFFFFFFLL, "codec", "__init_regulators");
    return 4294967284LL;
  }
  v7 = 0;
  v8 = 0;
  v9 = (_BYTE *)(v3 + 8);
  *(_DWORD *)(v5 + 40) = v2;
  do
  {
    ++v8;
    *(_QWORD *)(*(_QWORD *)(v5 + 32) + v7 + 8) = *((_QWORD *)v9 - 1);
    v10 = *v9;
    v9 += 16;
    v11 = *(_QWORD *)(v5 + 32) + v7;
    v7 += 24;
    *(_BYTE *)(v11 + 16) = v10;
  }
  while ( v8 < *(unsigned int *)(v5 + 40) );
  v12 = a1[488];
  v13 = *(_DWORD *)(v12 + 40);
  v14 = *(unsigned __int64 **)(v12 + 32);
  if ( v14 < &v14[3 * v13] )
  {
    v15 = msm_vidc_debug;
    do
    {
      if ( (v15 & 2) != 0 )
      {
        printk(&unk_8DCFE, "high", 0xFFFFFFFFLL, "codec", "__init_regulators");
        v15 = msm_vidc_debug;
        v12 = a1[488];
      }
      v13 = *(_DWORD *)(v12 + 40);
      v14 += 3;
    }
    while ( (unsigned __int64)v14 < *(_QWORD *)(v12 + 32) + 24 * (unsigned __int64)v13 );
    v14 = *(unsigned __int64 **)(v12 + 32);
  }
  if ( v14 >= &v14[3 * v13] )
    return 0;
  while ( 1 )
  {
    result = devm_regulator_get(*a1 + 16LL, v14[1]);
    *v14 = result;
    if ( !result || result >= 0xFFFFFFFFFFFFF001LL )
      break;
    v14 += 3;
    if ( (unsigned __int64)v14 >= *(_QWORD *)(a1[488] + 32LL) + 24 * (unsigned __int64)*(unsigned int *)(a1[488] + 40LL) )
      return 0;
  }
  if ( result )
    result = (unsigned int)result;
  else
    result = 4294966775LL;
  if ( (msm_vidc_debug & 1) != 0 )
  {
    v17 = result;
    printk(&unk_87B36, "err ", 0xFFFFFFFFLL, "codec", "__init_regulators");
    result = v17;
  }
  *v14 = 0;
  return result;
}
