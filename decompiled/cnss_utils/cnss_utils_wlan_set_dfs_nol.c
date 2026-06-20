__int64 __fastcall cnss_utils_wlan_set_dfs_nol(__int64 a1, __int64 a2, unsigned __int16 a3)
{
  __int64 v3; // x22
  __int64 result; // x0
  __int64 v6; // x20
  __int64 v7; // x21

  v3 = cnss_utils_priv;
  if ( !cnss_utils_priv )
    return 4294967274LL;
  result = 4294967274LL;
  if ( a2 && a3 )
  {
    v6 = kmemdup_noprof(a2, a3, 2080);
    if ( v6 )
    {
      raw_spin_lock_bh(v3 + 384);
      v7 = *(_QWORD *)(v3 + 320);
      *(_QWORD *)(v3 + 320) = v6;
      *(_WORD *)(v3 + 328) = a3;
      raw_spin_unlock_bh(v3 + 384);
      kfree(v7);
      return 0;
    }
    else
    {
      return 4294967284LL;
    }
  }
  return result;
}
