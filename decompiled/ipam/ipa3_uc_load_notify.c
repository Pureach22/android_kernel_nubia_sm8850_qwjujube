void ipa3_uc_load_notify()
{
  __int64 v0; // x0
  __int64 v1; // x8
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x1
  __int64 v5; // x2
  __int64 v6; // x3
  __int64 (__fastcall *v7)(__int64, __int64, __int64, __int64); // x8
  __int64 (__fastcall *v8)(__int64); // x8
  __int64 (__fastcall *v9)(__int64); // x8
  __int64 (__fastcall *v10)(__int64); // x8
  __int64 (__fastcall *v11)(__int64); // x8
  __int64 (__fastcall *v12)(__int64); // x8
  __int64 (__fastcall *v13)(__int64); // x8
  void (__fastcall *v14)(__int64); // x8
  __int64 v15; // x8
  __int64 v16; // x0

  _ReadStatusReg(SP_EL0);
  if ( *(_BYTE *)(ipa3_ctx + 43308) == 1 )
  {
    v0 = ipa3_inc_client_enable_clks();
    v1 = ipa3_ctx;
    *(_BYTE *)(ipa3_ctx + 34657) = 1;
    if ( v1 )
    {
      v2 = *(_QWORD *)(v1 + 34152);
      if ( v2 )
      {
        ipc_log_string(v2, "ipa %s:%d IPA uC loaded\n", "ipa3_uc_load_notify", 1210);
        v1 = ipa3_ctx;
      }
      v0 = *(_QWORD *)(v1 + 34160);
      if ( v0 )
        v0 = ipc_log_string(v0, "ipa %s:%d IPA uC loaded\n", "ipa3_uc_load_notify", 1210);
    }
    ipa3_proxy_clk_unvote(v0);
    ipa3_init_interrupts();
    v3 = ipa_add_interrupt_handler(1u, (__int64)ipa3_uc_event_handler, 1, ipa3_ctx);
    if ( (_DWORD)v3 )
    {
      v3 = printk(&unk_3C4917, "ipa3_uc_load_notify");
      v15 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v16 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v16 )
        {
          ipc_log_string(v16, "ipa %s:%d Fail to register for UC_IRQ0 rsp interrupt.\n", "ipa3_uc_load_notify", 1220);
          v15 = ipa3_ctx;
        }
        v3 = *(_QWORD *)(v15 + 34160);
        if ( v3 )
          v3 = ipc_log_string(
                 v3,
                 "ipa %s:%d Fail to register for UC_IRQ0 rsp interrupt.\n",
                 "ipa3_uc_load_notify",
                 1220);
      }
    }
    v7 = (__int64 (__fastcall *)(__int64, __int64, __int64, __int64))ipa3_uc_hdlrs;
    if ( ipa3_uc_hdlrs )
    {
      if ( *((_DWORD *)ipa3_uc_hdlrs - 1) != -440107680 )
        __break(0x8228u);
      v3 = v7(v3, v4, v5, v6);
    }
    v8 = (__int64 (__fastcall *)(__int64))off_2014D8;
    if ( off_2014D8 )
    {
      if ( *((_DWORD *)off_2014D8 - 1) != -440107680 )
        __break(0x8228u);
      v3 = v8(v3);
    }
    v9 = (__int64 (__fastcall *)(__int64))off_201500;
    if ( off_201500 )
    {
      if ( *((_DWORD *)off_201500 - 1) != -440107680 )
        __break(0x8228u);
      v3 = v9(v3);
    }
    v10 = (__int64 (__fastcall *)(__int64))off_201528;
    if ( off_201528 )
    {
      if ( *((_DWORD *)off_201528 - 1) != -440107680 )
        __break(0x8228u);
      v3 = v10(v3);
    }
    v11 = (__int64 (__fastcall *)(__int64))off_201550;
    if ( off_201550 )
    {
      if ( *((_DWORD *)off_201550 - 1) != -440107680 )
        __break(0x8228u);
      v3 = v11(v3);
    }
    v12 = (__int64 (__fastcall *)(__int64))off_201578;
    if ( off_201578 )
    {
      if ( *((_DWORD *)off_201578 - 1) != -440107680 )
        __break(0x8228u);
      v3 = v12(v3);
    }
    v13 = (__int64 (__fastcall *)(__int64))off_2015A0;
    if ( off_2015A0 )
    {
      if ( *((_DWORD *)off_2015A0 - 1) != -440107680 )
        __break(0x8228u);
      v3 = v13(v3);
    }
    v14 = (void (__fastcall *)(__int64))off_2015C8;
    if ( off_2015C8 )
    {
      if ( *((_DWORD *)off_2015C8 - 1) != -440107680 )
        __break(0x8228u);
      v14(v3);
    }
    ipa3_dec_client_disable_clks();
  }
  _ReadStatusReg(SP_EL0);
}
