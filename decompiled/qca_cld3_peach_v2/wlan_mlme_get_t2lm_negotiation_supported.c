__int64 __fastcall wlan_mlme_get_t2lm_negotiation_supported(__int64 a1)
{
  __int64 result; // x0

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
    return *(unsigned int *)(result + 1124);
  return result;
}
