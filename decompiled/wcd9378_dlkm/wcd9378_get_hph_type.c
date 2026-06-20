__int64 __fastcall wcd9378_get_hph_type(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 mbhc; // x0
  __int64 v5; // x8
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 128);
  mbhc = wcd9378_soc_get_mbhc(v2);
  if ( mbhc )
  {
    v5 = mbhc;
    result = 0;
    *(_QWORD *)(a2 + 72) = *(unsigned int *)(v5 + 388);
  }
  else
  {
    dev_err(*(_QWORD *)(v2 + 24), "%s: mbhc not initialized!\n", "wcd9378_get_hph_type");
    return 4294967274LL;
  }
  return result;
}
