__int64 __fastcall ipa3_install_dl_opt_wdi_dpath_flt_rules(unsigned int a1, int a2)
{
  __int64 v4; // x22
  __int64 result; // x0
  __int64 v6; // x24
  __int64 v7; // x22
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  void (__fastcall *v11)(_QWORD); // x8
  void (__fastcall *v12)(_QWORD); // x8
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  char s[368]; // [xsp+8h] [xbp-178h] BYREF
  __int64 v17; // [xsp+178h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)ipa3_get_max_num_pipes() <= a1 )
  {
    v13 = printk(&unk_3EF10D, "ipa3_install_dl_opt_wdi_dpath_flt_rules");
    v14 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v15 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v15 )
      {
        ipc_log_string(v15, "ipa %s:%d invalid ipa_ep_idx=%u\n", "ipa3_install_dl_opt_wdi_dpath_flt_rules", 2024, a1);
        v14 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v14 + 34160);
      if ( v13 )
        v13 = ipc_log_string(
                v13,
                "ipa %s:%d invalid ipa_ep_idx=%u\n",
                "ipa3_install_dl_opt_wdi_dpath_flt_rules",
                2024,
                a1);
    }
    result = ((__int64 (__fastcall *)(__int64))ipa_assert)(v13);
  }
  else
  {
    if ( a1 >= 0x25 )
      goto LABEL_35;
    v4 = ipa3_ctx;
    result = ipa_is_ep_support_flt(a1);
    v6 = ipa3_ctx;
    if ( (result & 1) != 0 )
    {
      v7 = v4 + 480LL * a1 + 168;
      if ( ipa3_ctx )
      {
        v8 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v8 )
        {
          ipc_log_string(v8, "ipa %s:%d ipa ep idx: %d\n", "ipa3_install_dl_opt_wdi_dpath_flt_rules", 2037, a1);
          v6 = ipa3_ctx;
        }
        v9 = *(_QWORD *)(v6 + 34160);
        if ( v9 )
        {
          ipc_log_string(v9, "ipa %s:%d ipa ep idx: %d\n", "ipa3_install_dl_opt_wdi_dpath_flt_rules", 2037, a1);
          v6 = ipa3_ctx;
        }
      }
      if ( *(_BYTE *)(v6 + 32267) == 1 )
      {
        memset(s, 0, 256);
        snprintf(s, 0x100u, "ipa-event-log %s:%d ipa ep idx: %d\n", "ipa3_install_dl_opt_wdi_dpath_flt_rules", 2039, a1);
        ipa3_send_opt_log_msg(s);
        v6 = ipa3_ctx;
      }
      memset(s, 0, sizeof(s));
      mutex_lock(v6 + 29472);
      if ( *(_DWORD *)(v7 + 396) )
      {
        if ( *(_DWORD *)(v7 + 400) )
        {
LABEL_27:
          result = mutex_unlock(ipa3_ctx + 29472);
          goto LABEL_28;
        }
      }
      else
      {
        if ( a1 == 36 )
          goto LABEL_35;
        strcpy(&s[164], " ");
        s[352] = 1;
        s[184] = 1;
        *(_DWORD *)&s[4] = 0;
        *(_DWORD *)&s[348] = a2;
        _ipa_add_flt_rule((__int64 *)(ipa3_ctx + 304LL * a1 + 17640), 0, (__int64)s, 0, v7 + 396, 0);
        v11 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 112LL);
        if ( *((_DWORD *)v11 - 1) != 1856640366 )
          __break(0x8228u);
        v11(0);
        if ( *(_DWORD *)(v7 + 400) )
          goto LABEL_27;
      }
      if ( a1 != 36 )
      {
        strcpy(&s[164], " ");
        s[352] = 1;
        s[184] = 1;
        *(_DWORD *)&s[4] = 0;
        *(_DWORD *)&s[348] = a2;
        _ipa_add_flt_rule((__int64 *)(ipa3_ctx + 304LL * a1 + 17792), 1u, (__int64)s, 0, v7 + 400, 0);
        v12 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 112LL);
        if ( *((_DWORD *)v12 - 1) != 1856640366 )
          __break(0x8228u);
        v12(1);
        goto LABEL_27;
      }
LABEL_35:
      __break(0x5512u);
    }
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(
          v10,
          "ipa %s:%d cannot add flt rules to non filtering pipe num %d\n",
          "ipa3_install_dl_opt_wdi_dpath_flt_rules",
          2033,
          a1);
        v6 = ipa3_ctx;
      }
      result = *(_QWORD *)(v6 + 34160);
      if ( result )
        result = ipc_log_string(
                   result,
                   "ipa %s:%d cannot add flt rules to non filtering pipe num %d\n",
                   "ipa3_install_dl_opt_wdi_dpath_flt_rules",
                   2033,
                   a1);
    }
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
