__int64 __fastcall msm_vidc_v4l2_fh_init(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // w9
  unsigned int v6; // w9

  if ( *(_QWORD *)(a1 + 1664) )
  {
    if ( a1 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_8CB8F, "err ", a1 + 340, "msm_vidc_v4l2_fh_init", a5);
    }
    return 4294967274LL;
  }
  v5 = *(_DWORD *)(a1 + 308);
  if ( v5 == 2 )
  {
    v6 = 0;
  }
  else
  {
    if ( v5 != 1 )
      return 4294967274LL;
    v6 = 1;
  }
  v4l2_fh_init(a1 + 1648, *(_QWORD *)(a1 + 320) + 1352LL * v6 + 16);
  *(_QWORD *)(a1 + 1672) = a1 + 1424;
  v4l2_fh_add(a1 + 1648);
  return 0;
}
