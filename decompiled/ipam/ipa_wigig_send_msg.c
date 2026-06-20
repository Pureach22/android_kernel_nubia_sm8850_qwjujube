__int64 __fastcall ipa_wigig_send_msg(int a1, const char *a2, __int64 a3, int a4, char a5)
{
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x23
  size_t v14; // x0
  unsigned __int64 v15; // x2
  __int16 v16; // w9
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 result; // x0
  __int64 v21; // x9
  unsigned int v22; // w19
  unsigned int v23; // w19
  unsigned __int64 StatusReg; // x26
  __int64 v25; // x27
  long double (*v26)(_QWORD, const char *, ...); // x0
  int v27; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = ipa3_ctx;
  v27 = 0;
  if ( ipa3_ctx )
  {
    v11 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v11 )
    {
      ipc_log_string(v11, "ipa %s:%d \n", "ipa_wigig_send_msg", 1945);
      v10 = ipa3_ctx;
    }
    v12 = *(_QWORD *)(v10 + 34160);
    if ( v12 )
      ipc_log_string(v12, "ipa %s:%d \n", "ipa_wigig_send_msg", 1945);
  }
  v13 = _kmalloc_cache_noprof(ipc_log_string, 3520, 44);
  if ( !v13 )
  {
LABEL_27:
    result = 4294967284LL;
    goto LABEL_28;
  }
  while ( 1 )
  {
    v14 = strnlen(a2, 0x20u);
    if ( v14 != -1 )
      break;
    _fortify_panic(2, -1, 0);
LABEL_26:
    _fortify_panic(7, 32, v15);
    StatusReg = _ReadStatusReg(SP_EL0);
    v25 = *(_QWORD *)(StatusReg + 80);
    v26 = ipc_log_string;
    *(_QWORD *)(StatusReg + 80) = &ipa_wigig_send_msg__alloc_tag;
    v13 = _kmalloc_cache_noprof(v26, 3520, 44);
    *(_QWORD *)(StatusReg + 80) = v25;
    if ( !v13 )
      goto LABEL_27;
  }
  if ( v14 == 32 )
    v15 = 32;
  else
    v15 = v14 + 1;
  if ( v15 >= 0x21 )
    goto LABEL_26;
  sized_strscpy(v13, a2);
  v16 = *(_WORD *)(a3 + 4);
  *(_DWORD *)(v13 + 32) = *(_DWORD *)a3;
  *(_WORD *)(v13 + 36) = v16;
  if ( a1 == 40 )
    *(_DWORD *)(v13 + 40) = a4;
  else
    *(_BYTE *)(v13 + 40) = a5 & 1;
  v17 = ipa3_ctx;
  LOBYTE(v27) = a1;
  HIWORD(v27) = 44;
  if ( ipa3_ctx )
  {
    v18 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v18 )
    {
      ipc_log_string(
        v18,
        "ipa %s:%d send msg type:%d, len:%d, buff %pK",
        "ipa_wigig_send_msg",
        1961,
        (unsigned __int8)a1,
        44,
        (const void *)v13);
      v17 = ipa3_ctx;
    }
    v19 = *(_QWORD *)(v17 + 34160);
    if ( v19 )
      ipc_log_string(
        v19,
        "ipa %s:%d send msg type:%d, len:%d, buff %pK",
        "ipa_wigig_send_msg",
        1961,
        (unsigned __int8)a1,
        44,
        (const void *)v13);
  }
  result = ipa_send_msg((unsigned __int8 *)&v27, (_WORD *)v13, ipa_wigig_free_msg);
  v21 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    if ( *(_QWORD *)(ipa3_ctx + 34152) )
    {
      v22 = result;
      ipc_log_string(*(_QWORD *)(ipa3_ctx + 34152), "ipa %s:%d exit\n", "ipa_wigig_send_msg", 1964);
      v21 = ipa3_ctx;
      result = v22;
    }
    if ( *(_QWORD *)(v21 + 34160) )
    {
      v23 = result;
      ipc_log_string(*(_QWORD *)(v21 + 34160), "ipa %s:%d exit\n", "ipa_wigig_send_msg", 1964);
      result = v23;
    }
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
