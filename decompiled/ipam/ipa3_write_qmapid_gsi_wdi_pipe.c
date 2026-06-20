__int64 __fastcall ipa3_write_qmapid_gsi_wdi_pipe(unsigned int a1, unsigned __int8 a2)
{
  __int64 v5; // x24
  unsigned int v6; // w26
  unsigned int v7; // w0
  unsigned int v8; // w20
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0

  _ReadStatusReg(SP_EL0);
  if ( a1 >= 0x25 )
    __break(0x5512u);
  v5 = ipa3_ctx + 168;
  ((void (*)(void))ipa3_get_client_mapping)();
  if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1) <= 0x85 )
    ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
  ipa3_inc_client_enable_clks();
  v6 = *(_DWORD *)(ipa3_ctx + 32240);
  v7 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(60, 0, a1);
  if ( v6 > 0x11 )
  {
    v8 = gsi_write_channel_scratch2_reg(*(_QWORD *)(v5 + 480LL * a1 + 8), (v7 << 14) & 0xFFFF0000 | (32 * a2));
    if ( v8 )
      goto LABEL_6;
  }
  else
  {
    v8 = gsi_write_channel_scratch3_reg(
           *(_QWORD *)(v5 + 480LL * a1 + 8),
           (a2 << 16) | (unsigned int)(unsigned __int16)(v7 >> 2));
    if ( v8 )
    {
LABEL_6:
      v9 = printk(&unk_3EFB51, "ipa3_write_qmapid_gsi_wdi_pipe");
      v10 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v11 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v11 )
        {
          ipc_log_string(
            v11,
            "ipa %s:%d gsi_write_channel_scratch failed %d\n",
            "ipa3_write_qmapid_gsi_wdi_pipe",
            3132,
            v8);
          v10 = ipa3_ctx;
        }
        v9 = *(_QWORD *)(v10 + 34160);
        if ( v9 )
          v9 = ipc_log_string(
                 v9,
                 "ipa %s:%d gsi_write_channel_scratch failed %d\n",
                 "ipa3_write_qmapid_gsi_wdi_pipe",
                 3132,
                 v8);
      }
      ((void (__fastcall *)(__int64))ipa_assert)(v9);
      goto LABEL_21;
    }
  }
  v12 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v13 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v13 )
    {
      ipc_log_string(
        v13,
        "ipa %s:%d client (ep: %d) qmap_id %d updated\n",
        "ipa3_write_qmapid_gsi_wdi_pipe",
        3136,
        a1,
        a2);
      v12 = ipa3_ctx;
    }
    v14 = *(_QWORD *)(v12 + 34160);
    if ( v14 )
      ipc_log_string(
        v14,
        "ipa %s:%d client (ep: %d) qmap_id %d updated\n",
        "ipa3_write_qmapid_gsi_wdi_pipe",
        3136,
        a1,
        a2);
  }
  ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
  if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1) <= 0x85 )
    ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
  ipa3_dec_client_disable_clks();
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return v8;
}
