__int64 osif_cm_roam_rt_stats_evt_cb()
{
  __int64 (*v0)(void); // x8
  __int64 result; // x0

  if ( osif_cm_legacy_ops )
  {
    v0 = *(__int64 (**)(void))(osif_cm_legacy_ops + 72);
    if ( v0 )
    {
      if ( *((_DWORD *)v0 - 1) != -1345639576 )
        __break(0x8228u);
      return v0();
    }
  }
  return result;
}
