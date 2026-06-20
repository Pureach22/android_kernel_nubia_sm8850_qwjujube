__int64 __fastcall validate_packet(unsigned int *a1, unsigned __int64 a2, unsigned int a3, __int64 a4)
{
  unsigned __int64 v4; // x8
  __int64 v5; // x5
  void *v6; // x0

  if ( !a1 || !a2 || !a3 )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v6 = &unk_83321;
LABEL_17:
    printk(v6, "err ", 0xFFFFFFFFLL, "codec", a4);
    return 4294967274LL;
  }
  if ( (unsigned __int64)a1 < a2 || (v4 = a2 + a3, v4 < (unsigned __int64)a1) )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v6 = &unk_854A8;
    goto LABEL_17;
  }
  v5 = *a1;
  if ( !(_DWORD)v5 )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v6 = &unk_82F2D;
    goto LABEL_17;
  }
  if ( (unsigned int)v5 > 0x1F && (unsigned __int64)a1 + v5 <= v4 )
    return 0;
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_8969B, "err ", 0xFFFFFFFFLL, "codec", a4);
  return 4294967274LL;
}
