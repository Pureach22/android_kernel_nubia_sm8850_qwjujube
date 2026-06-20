__int64 __fastcall ipa3_install_dflt_flt_rules(unsigned int a1)
{
  __int64 v2; // x21
  __int64 result; // x0
  unsigned int v4; // w22
  __int64 v5; // x8
  __int64 v6; // x24
  __int64 v7; // x19
  void (__fastcall *v8)(_QWORD); // x8
  __int64 v9; // x19
  void (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  _DWORD s[92]; // [xsp+8h] [xbp-178h] BYREF
  __int64 v17; // [xsp+178h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)ipa3_get_max_num_pipes() <= a1 )
  {
    v13 = printk(&unk_3EF10D, "ipa3_install_dflt_flt_rules");
    v14 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v15 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v15 )
      {
        ipc_log_string(v15, "ipa %s:%d invalid ipa_ep_idx=%u\n", "ipa3_install_dflt_flt_rules", 1960, a1);
        v14 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v14 + 34160);
      if ( v13 )
        v13 = ipc_log_string(v13, "ipa %s:%d invalid ipa_ep_idx=%u\n", "ipa3_install_dflt_flt_rules", 1960, a1);
    }
    result = ((__int64 (__fastcall *)(__int64))ipa_assert)(v13);
  }
  else
  {
    if ( a1 >= 0x25 )
      goto LABEL_22;
    v2 = ipa3_ctx;
    result = ipa_is_ep_support_flt(a1);
    if ( (result & 1) != 0 )
    {
      memset(s, 0, sizeof(s));
      mutex_lock(ipa3_ctx + 29472);
      if ( a1 != 36 )
      {
        v4 = a1;
        v5 = v2 + 480LL * a1;
        v6 = v5 + 168;
        s[1] = 3;
        v7 = ipa3_ctx + 304LL * a1 + 17640;
        _ipa_add_flt_rule(v7, 0, s, 1, v5 + 556, 0);
        v8 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 112LL);
        if ( *((_DWORD *)v8 - 1) != 1856640366 )
          __break(0x8228u);
        v8(0);
        *(_BYTE *)(v7 + 128) = 1;
        v9 = ipa3_ctx + 304LL * v4;
        s[1] = 3;
        _ipa_add_flt_rule(v9 + 17792, 1, s, 1, v6 + 392, 0);
        v10 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 112LL);
        if ( *((_DWORD *)v10 - 1) != 1856640366 )
          __break(0x8228u);
        v10(1);
        *(_BYTE *)(v9 + 17920) = 1;
        result = mutex_unlock(ipa3_ctx + 29472);
        goto LABEL_21;
      }
LABEL_22:
      __break(0x5512u);
    }
    v11 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v12 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v12 )
      {
        ipc_log_string(
          v12,
          "ipa %s:%d cannot add flt rules to non filtering pipe num %d\n",
          "ipa3_install_dflt_flt_rules",
          1969,
          a1);
        v11 = ipa3_ctx;
      }
      result = *(_QWORD *)(v11 + 34160);
      if ( result )
        result = ipc_log_string(
                   result,
                   "ipa %s:%d cannot add flt rules to non filtering pipe num %d\n",
                   "ipa3_install_dflt_flt_rules",
                   1969,
                   a1);
    }
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
