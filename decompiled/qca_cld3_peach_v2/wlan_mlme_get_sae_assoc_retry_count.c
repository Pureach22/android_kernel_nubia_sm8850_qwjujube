__int64 __fastcall wlan_mlme_get_sae_assoc_retry_count(__int64 a1, char *a2)
{
  __int64 psoc_ext_obj_fl; // x0
  char v4; // w8
  unsigned int v5; // w8
  __int64 result; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  v4 = psoc_ext_obj_fl;
  if ( psoc_ext_obj_fl )
  {
    v5 = *(unsigned __int8 *)(psoc_ext_obj_fl + 1084);
    result = 0;
    if ( ((v5 >> 3) & 6) != 0 )
      v4 = 2;
    else
      v4 = (v5 >> 3) & 7;
  }
  else
  {
    result = 16;
  }
  *a2 = v4;
  return result;
}
