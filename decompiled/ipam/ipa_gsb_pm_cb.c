void __fastcall ipa_gsb_pm_cb(__int64 a1, int a2)
{
  long double v2; // q0
  __int64 ipc_logbuf_low; // x0
  _QWORD *v4; // x8
  __int64 v5; // x9
  void (__fastcall *v6)(_QWORD, long double); // x8
  __int64 v7; // x0
  __int64 v8; // x9
  void (__fastcall *v9)(_QWORD, long double); // x8
  __int64 v10; // x0
  __int64 v11; // x9
  void (__fastcall *v12)(_QWORD, long double); // x8
  __int64 v13; // x0
  __int64 v14; // x9
  void (__fastcall *v15)(_QWORD, long double); // x8
  __int64 v16; // x0
  __int64 v17; // x8
  void (__fastcall *v18)(_QWORD, long double); // x9
  __int64 v19; // x0
  __int64 ipc_logbuf; // x0
  __int64 v22; // x0

  if ( a2 == 1 )
  {
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      v2 = ipc_log_string(ipc_logbuf_low, "ipa_gsb %s:%d wake up clients\n", "ipa_gsb_pm_cb", 449);
    }
    v4 = (_QWORD *)ipa_gsb_ctx;
    v5 = *(_QWORD *)(ipa_gsb_ctx + 96);
    if ( v5 )
    {
      v6 = *(void (__fastcall **)(_QWORD, long double))(v5 + 96);
      v7 = *(_QWORD *)(v5 + 40);
      if ( *((_DWORD *)v6 - 1) != 251140989 )
        __break(0x8228u);
      v6(v7, v2);
      v4 = (_QWORD *)ipa_gsb_ctx;
    }
    v8 = v4[13];
    if ( v8 )
    {
      v9 = *(void (__fastcall **)(_QWORD, long double))(v8 + 96);
      v10 = *(_QWORD *)(v8 + 40);
      if ( *((_DWORD *)v9 - 1) != 251140989 )
        __break(0x8228u);
      v9(v10, v2);
      v4 = (_QWORD *)ipa_gsb_ctx;
    }
    v11 = v4[14];
    if ( v11 )
    {
      v12 = *(void (__fastcall **)(_QWORD, long double))(v11 + 96);
      v13 = *(_QWORD *)(v11 + 40);
      if ( *((_DWORD *)v12 - 1) != 251140989 )
        __break(0x8228u);
      v12(v13, v2);
      v4 = (_QWORD *)ipa_gsb_ctx;
    }
    v14 = v4[15];
    if ( v14 )
    {
      v15 = *(void (__fastcall **)(_QWORD, long double))(v14 + 96);
      v16 = *(_QWORD *)(v14 + 40);
      if ( *((_DWORD *)v15 - 1) != 251140989 )
        __break(0x8228u);
      v15(v16, v2);
      v4 = (_QWORD *)ipa_gsb_ctx;
    }
    v17 = v4[16];
    if ( v17 )
    {
      v18 = *(void (__fastcall **)(_QWORD, long double))(v17 + 96);
      v19 = *(_QWORD *)(v17 + 40);
      if ( *((_DWORD *)v18 - 1) != 251140989 )
        __break(0x8229u);
      v18(v19, v2);
    }
  }
  else
  {
    printk(&unk_3A50D3, "ipa_gsb_pm_cb");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_gsb %s:%d Unexpected event %d\n", "ipa_gsb_pm_cb", 444, a2);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v22 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v22, "ipa_gsb %s:%d Unexpected event %d\n", "ipa_gsb_pm_cb", 444, a2);
    }
    __break(0x800u);
  }
}
