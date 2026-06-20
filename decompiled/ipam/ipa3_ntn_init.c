__int64 ipa3_ntn_init()
{
  __int64 v0; // x8
  void *v2[6]; // [xsp+0h] [xbp-30h] BYREF

  v2[5] = *(void **)(_ReadStatusReg(SP_EL0) + 1808);
  v2[3] = ipa3_uc_ntn_event_log_info_handler;
  v2[4] = nullptr;
  v2[1] = nullptr;
  v2[2] = nullptr;
  v2[0] = ipa3_uc_ntn_loaded_handler;
  ipa3_uc_register_handlers(5u, v2);
  v0 = ipa3_ctx + 43200;
  *(_QWORD *)(ipa3_ctx + 43200) = 0;
  *(_QWORD *)(v0 + 8) = 0;
  *(_QWORD *)(v0 + 16) = 0;
  *(_DWORD *)(v0 + 24) = 0;
  _ReadStatusReg(SP_EL0);
  return 0;
}
