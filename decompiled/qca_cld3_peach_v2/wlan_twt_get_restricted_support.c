__int64 __fastcall wlan_twt_get_restricted_support(__int64 a1, _BYTE *a2)
{
  unsigned __int8 *comp_private_obj; // x0
  int v4; // w8
  unsigned int v5; // w9
  __int64 result; // x0

  comp_private_obj = (unsigned __int8 *)wlan_twt_psoc_get_comp_private_obj(a1);
  if ( comp_private_obj )
  {
    v4 = comp_private_obj[23];
    if ( v4 == 1 )
      v5 = comp_private_obj[29];
    else
      v5 = 0;
    if ( comp_private_obj[8] == 1 )
    {
      if ( comp_private_obj[14] == 1 && v5 < *comp_private_obj )
      {
        if ( comp_private_obj[23] )
          LOBYTE(v4) = comp_private_obj[29];
      }
      else if ( comp_private_obj[14] )
      {
        LOBYTE(v4) = *comp_private_obj;
      }
      else
      {
        LOBYTE(v4) = 0;
      }
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
