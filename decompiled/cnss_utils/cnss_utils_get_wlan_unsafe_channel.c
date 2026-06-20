__int64 __fastcall cnss_utils_get_wlan_unsafe_channel(__int64 a1, void *a2, _WORD *a3, unsigned __int16 a4)
{
  unsigned __int16 *v4; // x23
  unsigned int v8; // w21
  __int64 v9; // x8

  v4 = (unsigned __int16 *)cnss_utils_priv;
  if ( cnss_utils_priv )
  {
    mutex_lock(cnss_utils_priv + 336);
    v8 = -22;
    if ( a2 && a3 )
    {
      v9 = *v4;
      if ( 2 * v9 <= (unsigned __int64)a4 )
      {
        *a3 = v9;
        memcpy(a2, v4 + 1, 2LL * *v4);
        v8 = 0;
      }
      else
      {
        v8 = -12;
      }
    }
    mutex_unlock(v4 + 168);
  }
  else
  {
    return (unsigned int)-22;
  }
  return v8;
}
