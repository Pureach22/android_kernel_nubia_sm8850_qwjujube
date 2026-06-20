__int64 *__fastcall msm_vidc_fetch_buffer(__int64 a1, int a2, unsigned int a3)
{
  unsigned int v3; // w9
  __int64 v4; // x8
  __int64 *v5; // x10
  __int64 *v6; // x8

  v3 = a2 - 9;
  if ( (unsigned int)(a2 - 9) < 6 && ((0x33u >> v3) & 1) != 0 )
  {
    v4 = (__int64)*(&off_9C110 + v3);
    v5 = (__int64 *)(a1 + v4);
    if ( a1 + v4 )
    {
      v6 = (__int64 *)(a1 + v4);
      while ( 1 )
      {
        v6 = (__int64 *)*v6;
        if ( v6 == v5 )
          break;
        if ( *((_DWORD *)v6 + 8) == a3 )
          return v6;
      }
      if ( a1 && (msm_vidc_debug & 1) != 0 )
        printk(&unk_9636D, "err ", a1 + 340, "msm_vidc_fetch_buffer", a3);
    }
  }
  else if ( (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_93B5F, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_fetch_buffer");
  }
  return nullptr;
}
