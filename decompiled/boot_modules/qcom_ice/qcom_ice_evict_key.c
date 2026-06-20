__int64 __fastcall qcom_ice_evict_key(_BYTE *a1, unsigned int a2)
{
  if ( a1[33] != 1 )
    return qcom_scm_clear_ice_key(a2, 0);
  if ( a1[34] == 1 )
  {
    a2 <<= a1[32] != 1;
    return qcom_scm_clear_ice_key(a2, 0);
  }
  return 0;
}
