__int64 __fastcall cnss_utils_wlan_get_dfs_nol(__int64 a1, void *a2, __int16 a3)
{
  __int64 v3; // x21
  size_t v4; // x19

  v3 = cnss_utils_priv;
  if ( cnss_utils_priv )
  {
    LODWORD(v4) = -22;
    if ( a2 && a3 )
    {
      LOWORD(v4) = a3;
      raw_spin_lock_bh(cnss_utils_priv + 384);
      if ( *(_QWORD *)(v3 + 320) && *(_WORD *)(v3 + 328) )
      {
        if ( (unsigned __int16)v4 >= (unsigned int)*(unsigned __int16 *)(v3 + 328) )
          v4 = *(unsigned __int16 *)(v3 + 328);
        else
          v4 = (unsigned __int16)v4;
        memcpy(a2, *(const void **)(v3 + 320), v4);
      }
      else
      {
        LODWORD(v4) = -2;
      }
      raw_spin_unlock_bh(v3 + 384);
    }
  }
  else
  {
    LODWORD(v4) = -22;
  }
  return (unsigned int)v4;
}
