__int64 __fastcall cnss_utils_set_wlan_unsafe_channel(__int64 a1, const void *a2, unsigned __int16 a3)
{
  unsigned __int16 *v3; // x22
  unsigned int v6; // w21

  v3 = (unsigned __int16 *)cnss_utils_priv;
  if ( cnss_utils_priv )
  {
    mutex_lock(cnss_utils_priv + 336);
    v6 = -22;
    if ( a2 && a3 <= 0x9Du )
    {
      *v3 = a3;
      if ( a3 )
        memcpy(v3 + 1, a2, 2LL * (a3 & 0x7FFF));
      v6 = 0;
    }
    mutex_unlock(v3 + 168);
  }
  else
  {
    return (unsigned int)-22;
  }
  return v6;
}
