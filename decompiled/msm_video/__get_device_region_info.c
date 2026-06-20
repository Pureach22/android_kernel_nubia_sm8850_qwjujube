__int64 __fastcall _get_device_region_info(__int64 a1, unsigned int *a2, _DWORD *a3)
{
  __int64 v3; // x10
  __int64 v4; // x9
  unsigned int v5; // w8
  unsigned int *v6; // x11
  unsigned int v7; // w10
  unsigned int v8; // w12

  v3 = *(_QWORD *)(a1 + 3904);
  v4 = *(unsigned int *)(v3 + 136);
  if ( (_DWORD)v4 )
  {
    v5 = 0;
    v6 = (unsigned int *)(*(_QWORD *)(v3 + 128) + 20LL);
    v7 = -1;
    do
    {
      v8 = *v6;
      if ( *v6 > v5 )
        v5 = *(v6 - 1) + v8;
      v6 += 8;
      if ( v8 < v7 )
        v7 = v8;
      --v4;
    }
    while ( v4 );
    if ( v7 == -1 || !v5 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_81DA5, "err ", 0xFFFFFFFFLL, "codec", "__get_device_region_info");
      return 4294967274LL;
    }
    else
    {
      *a2 = v7;
      *a3 = v5 - v7;
      return 0;
    }
  }
  else
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_8634A, "high", 0xFFFFFFFFLL, "codec", "__get_device_region_info");
    return 0;
  }
}
