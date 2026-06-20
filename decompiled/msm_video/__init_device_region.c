__int64 __fastcall _init_device_region(_QWORD *a1)
{
  __int64 v1; // x8
  __int64 v2; // x20
  __int64 v3; // x22
  bool v4; // zf
  __int64 v6; // x21
  __int64 v7; // x0
  __int64 v8; // x8
  unsigned __int64 v9; // x9
  int v10; // w10
  __int64 v11; // x11
  __int64 v12; // x8
  unsigned __int64 v13; // x24
  char v14; // w9

  v1 = a1[489];
  v2 = *(_QWORD *)(v1 + 160);
  v3 = *(unsigned int *)(v1 + 168);
  if ( v2 )
    v4 = (_DWORD)v3 == 0;
  else
    v4 = 1;
  if ( v4 )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_89F57, "high", 0xFFFFFFFFLL, "codec", "__init_device_region");
    return 0;
  }
  v6 = a1[488];
  v7 = devm_kmalloc(*a1 + 16LL, 32 * v3, 3520);
  *(_QWORD *)(v6 + 128) = v7;
  if ( v7 )
  {
    v8 = 0;
    v9 = 0;
    *(_DWORD *)(v6 + 136) = v3;
    do
    {
      ++v9;
      *(_QWORD *)(*(_QWORD *)(v6 + 128) + v8) = *(_QWORD *)(v2 + v8);
      *(_QWORD *)(*(_QWORD *)(v6 + 128) + v8 + 8) = *(_QWORD *)(v2 + v8 + 8);
      *(_DWORD *)(*(_QWORD *)(v6 + 128) + v8 + 16) = *(_DWORD *)(v2 + v8 + 16);
      *(_DWORD *)(*(_QWORD *)(v6 + 128) + v8 + 20) = *(_DWORD *)(v2 + v8 + 20);
      v10 = *(_DWORD *)(v2 + v8 + 24);
      v11 = *(_QWORD *)(v6 + 128) + v8;
      v8 += 32;
      *(_DWORD *)(v11 + 24) = v10;
    }
    while ( v9 < *(unsigned int *)(v6 + 136) );
    v12 = a1[488];
    v13 = *(_QWORD *)(v12 + 128);
    if ( v13 < v13 + 32LL * *(unsigned int *)(v12 + 136) )
    {
      v14 = msm_vidc_debug;
      do
      {
        if ( (v14 & 2) != 0 )
        {
          printk(&unk_91A84, "high", 0xFFFFFFFFLL, "codec", "__init_device_region");
          v14 = msm_vidc_debug;
          v12 = a1[488];
        }
        v13 += 32LL;
      }
      while ( v13 < *(_QWORD *)(v12 + 128) + 32 * (unsigned __int64)*(unsigned int *)(v12 + 136) );
    }
    return 0;
  }
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_887E8, "err ", 0xFFFFFFFFLL, "codec", "__init_device_region");
  return 4294967284LL;
}
