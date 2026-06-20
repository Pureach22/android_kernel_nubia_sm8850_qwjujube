__int64 __fastcall ipa3_nat_create_modify_pdn_cmd(__int64 a1, char a2)
{
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x21
  int max_pdn; // w0
  __int64 v10; // x8
  size_t v11; // x21
  __int64 v12; // x8
  _QWORD *v13; // x9
  __int64 result; // x0
  _QWORD v15[2]; // [xsp+0h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = ipa3_ctx;
  v15[0] = 0;
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d \n", "ipa3_nat_create_modify_pdn_cmd", 1180);
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
      ipc_log_string(v6, "ipa %s:%d \n", "ipa3_nat_create_modify_pdn_cmd", 1180);
  }
  v7 = ipahal_nat_entry_size(2, v15);
  v8 = v15[0];
  max_pdn = ipa3_get_max_pdn(v7);
  v10 = ipa3_ctx;
  if ( !*(_QWORD *)(ipa3_ctx + 29840) )
  {
    result = 4294967282LL;
    goto LABEL_16;
  }
  v11 = v8 * max_pdn;
  if ( (a2 & 1) != 0 )
  {
    memset(*(void **)(ipa3_ctx + 29840), 0, v11);
    v10 = ipa3_ctx;
  }
  *(_WORD *)(a1 + 17) = 0;
  *(_DWORD *)(a1 + 20) = 0;
  *(_DWORD *)(a1 + 8) = v11;
  *(_QWORD *)a1 = *(_QWORD *)(v10 + 29848);
  v12 = ipa3_ctx;
  v13 = (_QWORD *)(ipa3_ctx + 34152);
  *(_DWORD *)(a1 + 12) = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 288LL) + *(unsigned __int16 *)(ipa3_ctx + 29522);
  if ( !v12 )
    goto LABEL_14;
  if ( *v13 )
  {
    ipc_log_string(*v13, "ipa %s:%d return\n", "ipa3_nat_create_modify_pdn_cmd", 1201);
    v12 = ipa3_ctx;
  }
  result = *(_QWORD *)(v12 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d return\n", "ipa3_nat_create_modify_pdn_cmd", 1201);
LABEL_14:
    result = 0;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
