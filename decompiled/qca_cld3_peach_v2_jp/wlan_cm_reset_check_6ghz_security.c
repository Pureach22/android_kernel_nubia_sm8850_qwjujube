__int64 __fastcall wlan_cm_reset_check_6ghz_security(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x19

  result = wlan_psoc_mlme_get_cmpt_obj(a1);
  if ( result )
  {
    v3 = result;
    result = cfg_psoc_get_values(a1);
    *(_BYTE *)(v3 + 2000) = *(_BYTE *)(v3 + 2000) & 0xF7 | (8 * *(_BYTE *)(result + 1021));
  }
  return result;
}
