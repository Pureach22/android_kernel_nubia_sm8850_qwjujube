void ipa3_default_evict_register()
{
  __int64 v0; // x8
  _BYTE *v1; // x9
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // [xsp+8h] [xbp-18h] BYREF
  int v5; // [xsp+10h] [xbp-10h]
  __int64 v6; // [xsp+18h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = ipa3_ctx;
  v1 = (_BYTE *)(ipa3_ctx + 28652);
  if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0x11u && (*v1 & 1) == 0 )
  {
    v5 = 0;
    v4 = 0;
    *v1 = 1;
    if ( v0 )
    {
      v2 = *(_QWORD *)(v0 + 34152);
      if ( v2 )
      {
        ipc_log_string(
          v2,
          "ipa %s:%d Setting COAL eviction register with default values\n",
          "ipa3_default_evict_register",
          14729);
        v0 = ipa3_ctx;
      }
      v3 = *(_QWORD *)(v0 + 34160);
      if ( v3 )
        ipc_log_string(
          v3,
          "ipa %s:%d Setting COAL eviction register with default values\n",
          "ipa3_default_evict_register",
          14729);
    }
    ipa3_get_default_evict_values((__int64)&v4);
    ((void (__fastcall *)(__int64, _QWORD, __int64 *))ipahal_write_reg_n_fields)(128, 0, &v4);
  }
  _ReadStatusReg(SP_EL0);
}
