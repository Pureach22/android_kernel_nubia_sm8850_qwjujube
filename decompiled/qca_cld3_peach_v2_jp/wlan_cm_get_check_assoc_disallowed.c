__int64 __fastcall wlan_cm_get_check_assoc_disallowed(__int64 a1, _BYTE *a2)
{
  __int64 result; // x0
  int v4; // w8

  result = wlan_psoc_mlme_get_cmpt_obj(a1);
  if ( result )
    v4 = (*(unsigned __int8 *)(result + 2000) >> 1) & 1;
  else
    LOBYTE(v4) = 0;
  *a2 = v4;
  return result;
}
