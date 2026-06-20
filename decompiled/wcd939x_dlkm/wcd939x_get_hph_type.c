__int64 __fastcall wcd939x_get_hph_type(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 mbhc; // x0
  __int64 v5; // x8

  v2 = *(_QWORD *)(a1 + 128);
  mbhc = wcd939x_soc_get_mbhc(v2);
  if ( mbhc )
  {
    v5 = mbhc;
    *(_QWORD *)(a2 + 72) = *(unsigned int *)(v5 + 388);
    return 0;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&wcd939x_get_hph_type__rs, "wcd939x_get_hph_type") )
      dev_err(*(_QWORD *)(v2 + 24), "%s: mbhc not initialized!\n", "wcd939x_get_hph_type");
    return 4294967274LL;
  }
}
