__int64 __fastcall wlan_mlme_set_sap_max_peers(__int64 a1, int a2)
{
  __int64 psoc_ext_obj_fl; // x8
  __int64 result; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  result = 16;
  if ( (unsigned int)(a2 - 1) <= 0x3F )
  {
    if ( psoc_ext_obj_fl )
    {
      *(_BYTE *)(psoc_ext_obj_fl + 3216) = a2;
      return 0;
    }
  }
  return result;
}
