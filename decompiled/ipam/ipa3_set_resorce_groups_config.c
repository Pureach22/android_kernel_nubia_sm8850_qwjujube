void ipa3_set_resorce_groups_config()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0
  unsigned __int64 v3; // x10
  unsigned __int64 v4; // x13
  unsigned __int16 v5; // w14
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int16 v13; // [xsp+Ch] [xbp-14h] BYREF
  int v14; // [xsp+10h] [xbp-10h] BYREF
  __int16 v15; // [xsp+14h] [xbp-Ch]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = ipa3_ctx;
  v15 = 0;
  v14 = 0;
  v13 = 0;
  if ( ipa3_ctx )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v1 )
    {
      ipc_log_string(v1, "ipa %s:%d ENTER\n", "ipa3_set_resorce_groups_config", 12493);
      v0 = ipa3_ctx;
    }
    v2 = *(_QWORD *)(v0 + 34160);
    if ( v2 )
    {
      ipc_log_string(v2, "ipa %s:%d ENTER\n", "ipa3_set_resorce_groups_config", 12493);
      v0 = ipa3_ctx;
    }
  }
  if ( *(_DWORD *)(v0 + 32240) >= 0x15u )
  {
    v3 = *(unsigned __int8 *)(v0 + 32244);
    if ( v3 >= 0x18 )
    {
      __break(0x5512u);
      _ipa_stop_gsi_channel();
      return;
    }
    v4 = (8LL * *(unsigned __int8 *)(v0 + 32244)) | 6;
    v5 = *((_WORD *)&ipa_rsrc_config + 4 * v3);
    LOBYTE(v15) = 0;
    v14 = v5;
    if ( v4 > 0xC0
      || (LOBYTE(v13) = *((_BYTE *)&ipa_rsrc_config + 8 * v3 + 6), ((8LL * (unsigned __int8)v3) | 7uLL) > 0xC0) )
    {
      __break(1u);
    }
    HIBYTE(v13) = *((_BYTE *)&ipa_rsrc_config + 8 * v3 + 7);
    if ( v0 )
    {
      v6 = *(_QWORD *)(v0 + 34152);
      if ( v6 )
      {
        ipc_log_string(v6, "ipa %s:%d Write IPA_RSRC_GRP_CFG\n", "ipa3_set_resorce_groups_config", 12505);
        v0 = ipa3_ctx;
      }
      v7 = *(_QWORD *)(v0 + 34160);
      if ( v7 )
        ipc_log_string(v7, "ipa %s:%d Write IPA_RSRC_GRP_CFG\n", "ipa3_set_resorce_groups_config", 12505);
    }
    ((void (__fastcall *)(__int64, _QWORD, int *))ipahal_write_reg_n_fields)(84, 0, &v14);
    v8 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d Write IPA_RSRC_GRP_CFG_EXT\n", "ipa3_set_resorce_groups_config", 12507);
        v8 = ipa3_ctx;
      }
      v10 = *(_QWORD *)(v8 + 34160);
      if ( v10 )
        ipc_log_string(v10, "ipa %s:%d Write IPA_RSRC_GRP_CFG_EXT\n", "ipa3_set_resorce_groups_config", 12507);
    }
    ((void (__fastcall *)(__int64, _QWORD, __int16 *))ipahal_write_reg_n_fields)(85, 0, &v13);
    v0 = ipa3_ctx;
  }
  if ( v0 )
  {
    v11 = *(_QWORD *)(v0 + 34152);
    if ( v11 )
    {
      ipc_log_string(v11, "ipa %s:%d EXIT\n", "ipa3_set_resorce_groups_config", 12510);
      v0 = ipa3_ctx;
    }
    v12 = *(_QWORD *)(v0 + 34160);
    if ( v12 )
      ipc_log_string(v12, "ipa %s:%d EXIT\n", "ipa3_set_resorce_groups_config", 12510);
  }
  _ReadStatusReg(SP_EL0);
}
