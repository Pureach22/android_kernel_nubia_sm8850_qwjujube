__int64 __fastcall wlan_cm_set_check_assoc_disallowed(__int64 a1, char a2)
{
  __int64 result; // x0
  char v4; // w9

  result = wlan_psoc_mlme_get_cmpt_obj(a1);
  if ( result )
  {
    if ( (a2 & 1) != 0 )
      v4 = 2;
    else
      v4 = 0;
    *(_BYTE *)(result + 2048) = *(_BYTE *)(result + 2048) & 0xFD | v4;
  }
  return result;
}
