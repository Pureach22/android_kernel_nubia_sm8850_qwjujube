__int64 __fastcall ipa_set_pkt_init_ex_hdr_ofst(__int64 a1, char a2)
{
  __int64 v3; // x0
  int ep_mapping; // w19
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 result; // x0
  unsigned __int16 v10; // w23
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  unsigned __int16 *v14; // x0
  size_t v15; // x2
  int v16; // w10
  unsigned __int16 *v17; // x19
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  int v24; // [xsp+0h] [xbp-30h] BYREF
  int v25; // [xsp+4h] [xbp-2Ch] BYREF
  __int16 v26; // [xsp+8h] [xbp-28h]
  __int64 v27; // [xsp+Ah] [xbp-26h]
  __int64 v28; // [xsp+12h] [xbp-1Eh]
  __int64 v29; // [xsp+1Ah] [xbp-16h]
  int v30; // [xsp+22h] [xbp-Eh]
  __int64 v31; // [xsp+28h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  v29 = 0;
  v28 = 0;
  v27 = 0;
  if ( !a1 )
  {
LABEL_24:
    result = 4294967274LL;
    goto LABEL_25;
  }
  v3 = *(unsigned int *)(a1 + 32);
  v24 = 0;
  ep_mapping = ipa_get_ep_mapping(v3);
  v6 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v7 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d dst_ep_idx=%d\n", "ipa_set_pkt_init_ex_hdr_ofst", 9008, ep_mapping);
      v6 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v6 + 34160);
    if ( v8 )
      ipc_log_string(v8, "ipa %s:%d dst_ep_idx=%d\n", "ipa_set_pkt_init_ex_hdr_ofst", 9008, ep_mapping);
  }
  if ( ep_mapping == -1 )
  {
    printk(&unk_3DA941, "ipa_set_pkt_init_ex_hdr_ofst");
    v18 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v19 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v19 )
      {
        ipc_log_string(
          v19,
          "ipa %s:%d Client %u is not mapped\n",
          "ipa_set_pkt_init_ex_hdr_ofst",
          9010,
          *(_DWORD *)(a1 + 32));
        v18 = ipa3_ctx;
      }
      v20 = *(_QWORD *)(v18 + 34160);
      if ( v20 )
        ipc_log_string(
          v20,
          "ipa %s:%d Client %u is not mapped\n",
          "ipa_set_pkt_init_ex_hdr_ofst",
          9010,
          *(_DWORD *)(a1 + 32));
    }
    goto LABEL_24;
  }
  if ( (a2 & 1) != 0 )
  {
    result = ipa3_get_hdr_proc_ctx_offset(a1, &v24);
    if ( (_DWORD)result )
      goto LABEL_25;
  }
  else
  {
    result = ipa3_get_hdr_offset(a1, &v24);
    if ( (_DWORD)result )
      goto LABEL_25;
  }
  v10 = v24;
  v11 = ipa3_ctx;
  HIWORD(v28) = v24;
  if ( ipa3_ctx )
  {
    v12 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v12 )
    {
      ipc_log_string(
        v12,
        "ipa %s:%d cmd.rt_hdr_offset=%d\n",
        "ipa_set_pkt_init_ex_hdr_ofst",
        9022,
        (unsigned __int16)v24);
      v11 = ipa3_ctx;
    }
    v13 = *(_QWORD *)(v11 + 34160);
    if ( v13 )
      ipc_log_string(v13, "ipa %s:%d cmd.rt_hdr_offset=%d\n", "ipa_set_pkt_init_ex_hdr_ofst", 9022, v10);
  }
  v26 = 0;
  v25 = 16843009;
  LOBYTE(v28) = 1;
  BYTE1(v29) = 1;
  BYTE1(v28) = ep_mapping;
  LOBYTE(v29) = a2 & 1;
  v14 = (unsigned __int16 *)((__int64 (__fastcall *)(__int64, int *, _QWORD))ipahal_construct_imm_cmd)(16, &v25, 0);
  if ( v14 )
  {
    v15 = *v14;
    v16 = ep_mapping * v15;
    v17 = v14;
    memcpy((void *)(*(_QWORD *)(ipa3_ctx + 50184) + v16), v14 + 2, v15);
    kfree(v17);
    result = 0;
  }
  else
  {
    printk(&unk_3FA63B, "ipa_set_pkt_init_ex_hdr_ofst");
    v21 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v22 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v22 )
      {
        ipc_log_string(v22, "ipa %s:%d failed to construct IMM cmd\n", "ipa_set_pkt_init_ex_hdr_ofst", 9036);
        v21 = ipa3_ctx;
      }
      v23 = *(_QWORD *)(v21 + 34160);
      if ( v23 )
        ipc_log_string(v23, "ipa %s:%d failed to construct IMM cmd\n", "ipa_set_pkt_init_ex_hdr_ofst", 9036);
    }
    result = 4294967284LL;
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
