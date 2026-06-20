__int64 wlan_spatial_reuse_osif_event()
{
  __int64 (*v0)(void); // x8
  __int64 result; // x0

  v0 = (__int64 (*)(void))sr_cb;
  if ( sr_cb )
  {
    if ( *((_DWORD *)sr_cb - 1) != -1691826021 )
      __break(0x8228u);
    return v0();
  }
  return result;
}
