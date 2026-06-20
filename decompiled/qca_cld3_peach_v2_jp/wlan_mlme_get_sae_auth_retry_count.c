__int64 __fastcall wlan_mlme_get_sae_auth_retry_count(__int64 a1, _BYTE *a2)
{
  __int64 psoc_ext_obj_fl; // x8
  __int64 result; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
  {
    result = 0;
    LODWORD(psoc_ext_obj_fl) = *(_DWORD *)(psoc_ext_obj_fl + 1084) & 7;
    if ( (unsigned int)psoc_ext_obj_fl >= 3 )
      LOBYTE(psoc_ext_obj_fl) = 3;
  }
  else
  {
    result = 16;
  }
  *a2 = psoc_ext_obj_fl;
  return result;
}
