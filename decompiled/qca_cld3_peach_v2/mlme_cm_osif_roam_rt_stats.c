__int64 mlme_cm_osif_roam_rt_stats()
{
  __int64 (*v0)(void); // x8
  __int64 result; // x0

  if ( glbl_cm_ops )
  {
    v0 = *(__int64 (**)(void))(glbl_cm_ops + 112);
    if ( v0 )
    {
      if ( *((_DWORD *)v0 - 1) != -1345639576 )
        __break(0x8228u);
      return v0();
    }
  }
  return result;
}
