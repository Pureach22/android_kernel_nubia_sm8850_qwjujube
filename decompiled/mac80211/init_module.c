__int64 init_module()
{
  unsigned int v0; // w19

  v0 = ieee80211_iface_init();
  if ( !v0 )
  {
    drop_reasons_register_subsys(2, &drop_reason_list_monitor);
    drop_reasons_register_subsys(1, &drop_reason_list_unusable);
  }
  return v0;
}
