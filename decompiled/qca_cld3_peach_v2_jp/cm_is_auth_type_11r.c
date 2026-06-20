__int64 __fastcall cm_is_auth_type_11r(__int64 a1, __int64 a2, char a3)
{
  int param; // w21

  param = wlan_crypto_get_param(a2, 7u);
  if ( wlan_vdev_is_open_mode(a2) )
  {
    if ( (a3 & 1) == 0 || (*(_BYTE *)(a1 + 1896) & 1) == 0 )
      return 0;
  }
  else if ( (param & 0x11300860) == 0 )
  {
    return 0;
  }
  return 1;
}
