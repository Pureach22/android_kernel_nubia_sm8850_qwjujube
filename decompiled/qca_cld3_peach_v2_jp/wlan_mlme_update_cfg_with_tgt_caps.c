_BYTE *__fastcall wlan_mlme_update_cfg_with_tgt_caps(__int64 a1, _BYTE *a2)
{
  _BYTE *result; // x0

  result = (_BYTE *)mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
  {
    result[1065] = *a2;
    result[1079] = a2[1];
    result[1080] = a2[2];
    result[1081] = a2[4];
    result[1096] = a2[5];
  }
  return result;
}
