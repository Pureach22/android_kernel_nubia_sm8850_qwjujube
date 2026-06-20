__int64 __fastcall _vote_bandwidth(_QWORD *a1)
{
  __int64 result; // x0
  unsigned int v3; // w20

  if ( *a1 )
  {
    if ( (msm_vidc_debug & 8) != 0 )
      printk(&unk_94DF9, "perf", 0xFFFFFFFFLL, "codec", a1[1]);
    result = icc_set_bw();
    if ( (_DWORD)result )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v3 = result;
        printk(&unk_8DCBC, "err ", 0xFFFFFFFFLL, "codec", a1[1]);
        return v3;
      }
    }
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_87AE9, "err ", 0xFFFFFFFFLL, "codec", "__vote_bandwidth");
    return 4294967274LL;
  }
  return result;
}
