__int64 osif_cm_roam_complete_cb()
{
  void (*v0)(void); // x8

  if ( osif_cm_legacy_ops )
  {
    v0 = *(void (**)(void))(osif_cm_legacy_ops + 80);
    if ( v0 )
    {
      if ( *((_DWORD *)v0 - 1) != 1458356883 )
        __break(0x8228u);
      v0();
    }
  }
  return 0;
}
