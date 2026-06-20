__int64 __fastcall chora_tlmm_probe(__int64 a1)
{
  __int64 match_data; // x0

  match_data = of_device_get_match_data(a1 + 16);
  if ( match_data )
    return msm_pinctrl_probe(a1, match_data);
  else
    return 4294967274LL;
}
