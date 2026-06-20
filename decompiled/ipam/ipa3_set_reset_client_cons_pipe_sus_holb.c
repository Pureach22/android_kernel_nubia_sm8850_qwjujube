__int64 __fastcall ipa3_set_reset_client_cons_pipe_sus_holb(unsigned __int8 a1, unsigned int a2)
{
  unsigned int ep_mapping; // w0
  unsigned int v4; // w20
  __int64 v5; // x22
  __int64 v6; // x22
  int v7; // t1
  __int64 result; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  int v15; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-18h]
  int v17; // [xsp+10h] [xbp-10h]
  __int16 v18; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v18 = a1;
  v15 = 0;
  v17 = a1 & 1;
  if ( a2 <= 0x85 && (a2 & 1) == 0 )
  {
    printk(&unk_3B492C, "ipa3_set_reset_client_cons_pipe_sus_holb");
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d client (%d) not CONS\n", "ipa3_set_reset_client_cons_pipe_sus_holb", 1471, a2);
        v9 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v9 + 34160);
      if ( v11 )
        ipc_log_string(v11, "ipa %s:%d client (%d) not CONS\n", "ipa3_set_reset_client_cons_pipe_sus_holb", 1471, a2);
    }
    goto LABEL_23;
  }
  ep_mapping = ipa_get_ep_mapping(a2);
  if ( ep_mapping == -1 )
  {
    printk(&unk_3E08A7, "ipa3_set_reset_client_cons_pipe_sus_holb");
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d client (%d) not valid\n", "ipa3_set_reset_client_cons_pipe_sus_holb", 1478, a2);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
        ipc_log_string(v14, "ipa %s:%d client (%d) not valid\n", "ipa3_set_reset_client_cons_pipe_sus_holb", 1478, a2);
    }
LABEL_23:
    result = 4294967274LL;
    goto LABEL_12;
  }
  v4 = ep_mapping;
  if ( ep_mapping >= 0x25 )
  {
    __break(0x5512u);
    JUMPOUT(0x915EC);
  }
  v5 = ipa3_ctx + 480LL * ep_mapping;
  client_lock_unlock_cb(a2, 1);
  v7 = *(_DWORD *)(v5 + 168);
  v6 = v5 + 168;
  if ( v7 && *(_BYTE *)(v6 + 404) == 1 )
  {
    if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0xDu )
      ((void (__fastcall *)(__int64, _QWORD, __int16 *))ipahal_write_reg_n_fields)(49, v4, &v18);
    ((void (__fastcall *)(__int64, _QWORD, int *))ipahal_write_reg_n_fields)(53, v4, &v15);
    ((void (__fastcall *)(__int64, _QWORD, int *))ipahal_write_reg_n_fields)(52, v4, &v15);
    if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0xEu )
      ((void (__fastcall *)(__int64, _QWORD, int *))ipahal_write_reg_n_fields)(52, v4, &v15);
  }
  client_lock_unlock_cb(a2, 0);
  result = 0;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
