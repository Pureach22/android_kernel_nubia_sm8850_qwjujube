__int64 __fastcall hfi_create_packet(
        unsigned int *a1,
        unsigned int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        const void *a8,
        unsigned int a9)
{
  __int64 v10; // x6
  _DWORD *v12; // x22
  int v19; // w9

  if ( !a1 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "hfi_create_packet");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v10 = *a1;
  if ( (unsigned int)v10 <= 0x1F )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_89997, "err ", 0xFFFFFFFFLL, "codec", "hfi_create_packet");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  if ( (unsigned int)v10 + a9 + 32 > a2 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_88074, "err ", 0xFFFFFFFFLL, "codec", "hfi_create_packet");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v12 = (unsigned int *)((char *)a1 + v10);
  memset((char *)a1 + v10, 0, a9 + 32);
  *v12 = a9 + 32;
  v12[1] = a3;
  v12[2] = a4;
  v12[3] = a5;
  v12[4] = a6;
  v12[5] = a7;
  if ( a9 )
    memcpy(v12 + 8, a8, a9);
  v19 = *a1;
  ++a1[7];
  *a1 = v19 + *v12;
  return 0;
}
