__int64 __fastcall ipa_wigig_send_wlan_msg(int a1, const char *a2, int *a3)
{
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x22
  size_t v10; // x0
  unsigned __int64 v11; // x2
  int v12; // w9
  __int16 v13; // w10
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 result; // x0
  __int64 v18; // x9
  unsigned int v19; // w19
  unsigned int v20; // w19
  unsigned __int64 StatusReg; // x24
  __int64 v22; // x25
  long double (*v23)(_QWORD, const char *, ...); // x0
  int v24; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = ipa3_ctx;
  v24 = 2621440;
  if ( ipa3_ctx )
  {
    v7 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d %d\n", "ipa_wigig_send_wlan_msg", 1917, a1);
      v6 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v6 + 34160);
    if ( v8 )
      ipc_log_string(v8, "ipa %s:%d %d\n", "ipa_wigig_send_wlan_msg", 1917, a1);
  }
  v9 = _kmalloc_cache_noprof(ipc_log_string, 3520, 40);
  if ( !v9 )
  {
LABEL_24:
    result = 4294967284LL;
    goto LABEL_25;
  }
  while ( 1 )
  {
    v10 = strnlen(a2, 0x20u);
    if ( v10 != -1 )
      break;
    _fortify_panic(2, -1, 0);
LABEL_23:
    _fortify_panic(7, 32, v11);
    StatusReg = _ReadStatusReg(SP_EL0);
    v22 = *(_QWORD *)(StatusReg + 80);
    v23 = ipc_log_string;
    *(_QWORD *)(StatusReg + 80) = &ipa_wigig_send_wlan_msg__alloc_tag;
    v9 = _kmalloc_cache_noprof(v23, 3520, 40);
    *(_QWORD *)(StatusReg + 80) = v22;
    if ( !v9 )
      goto LABEL_24;
  }
  if ( v10 == 32 )
    v11 = 32;
  else
    v11 = v10 + 1;
  if ( v11 >= 0x21 )
    goto LABEL_23;
  sized_strscpy(v9, a2);
  v12 = *a3;
  v13 = *((_WORD *)a3 + 2);
  v14 = ipa3_ctx;
  LOBYTE(v24) = a1;
  *(_DWORD *)(v9 + 32) = v12;
  *(_WORD *)(v9 + 36) = v13;
  if ( v14 )
  {
    v15 = *(_QWORD *)(v14 + 34152);
    if ( v15 )
    {
      ipc_log_string(
        v15,
        "ipa %s:%d send msg type:%d, len:%d, buff %pK",
        "ipa_wigig_send_wlan_msg",
        1928,
        (unsigned __int8)a1,
        40,
        (const void *)v9);
      v14 = ipa3_ctx;
    }
    v16 = *(_QWORD *)(v14 + 34160);
    if ( v16 )
      ipc_log_string(
        v16,
        "ipa %s:%d send msg type:%d, len:%d, buff %pK",
        "ipa_wigig_send_wlan_msg",
        1928,
        (unsigned __int8)a1,
        40,
        (const void *)v9);
  }
  result = ipa_send_msg((unsigned __int8 *)&v24, (_WORD *)v9, ipa_wigig_free_msg);
  v18 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    if ( *(_QWORD *)(ipa3_ctx + 34152) )
    {
      v19 = result;
      ipc_log_string(*(_QWORD *)(ipa3_ctx + 34152), "ipa %s:%d exit\n", "ipa_wigig_send_wlan_msg", 1931);
      v18 = ipa3_ctx;
      result = v19;
    }
    if ( *(_QWORD *)(v18 + 34160) )
    {
      v20 = result;
      ipc_log_string(*(_QWORD *)(v18 + 34160), "ipa %s:%d exit\n", "ipa_wigig_send_wlan_msg", 1931);
      result = v20;
    }
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
