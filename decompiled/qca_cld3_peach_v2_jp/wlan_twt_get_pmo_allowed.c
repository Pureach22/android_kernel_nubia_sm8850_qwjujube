__int64 __fastcall wlan_twt_get_pmo_allowed(__int64 a1)
{
  __int64 result; // x0

  result = wlan_twt_psoc_get_comp_private_obj(a1);
  if ( result )
    return *(_DWORD *)(result + 80) == 0;
  return result;
}
