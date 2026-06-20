__int64 ipa3_wdi_init()
{
  void *v1[6]; // [xsp+0h] [xbp-30h] BYREF

  v1[5] = *(void **)(_ReadStatusReg(SP_EL0) + 1808);
  v1[3] = ipa3_uc_wdi_event_log_info_handler;
  v1[4] = nullptr;
  v1[1] = ipa3_uc_wdi_event_handler;
  v1[2] = nullptr;
  v1[0] = ipa3_uc_wdi_loaded_handler;
  ipa3_uc_register_handlers(3u, v1);
  _ReadStatusReg(SP_EL0);
  return 0;
}
