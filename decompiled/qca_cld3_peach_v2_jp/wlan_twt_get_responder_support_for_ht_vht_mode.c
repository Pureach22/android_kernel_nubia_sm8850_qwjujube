__int64 __fastcall wlan_twt_get_responder_support_for_ht_vht_mode(__int64 a1, _BYTE *a2)
{
  _BYTE *comp_private_obj; // x0
  unsigned int v4; // w8
  __int64 result; // x0

  comp_private_obj = (_BYTE *)wlan_twt_psoc_get_comp_private_obj(a1);
  if ( comp_private_obj )
  {
    v4 = (unsigned __int8)comp_private_obj[17];
    *a2 = v4;
    if ( *comp_private_obj == 1 && (v4 <= (unsigned __int8)comp_private_obj[21] || !comp_private_obj[1]) )
    {
      if ( !comp_private_obj[1] )
        LOBYTE(v4) = 0;
    }
    else
    {
      LOBYTE(v4) = 0;
    }
    result = 0;
  }
  else
  {
    LOBYTE(v4) = 0;
    result = 4;
  }
  *a2 = v4;
  return result;
}
