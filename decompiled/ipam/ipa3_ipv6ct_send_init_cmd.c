__int64 __fastcall ipa3_ipv6ct_send_init_cmd(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  unsigned int v5; // w22
  char v6; // w20
  unsigned int ep_mapping; // w20
  unsigned int v8; // w8
  int ep_reg_offset; // w0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned int v13; // w19
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int128 v30; // [xsp+8h] [xbp-178h] BYREF
  int v31; // [xsp+18h] [xbp-168h]
  __int64 v32; // [xsp+20h] [xbp-160h] BYREF
  __int64 v33; // [xsp+28h] [xbp-158h]
  __int64 v34; // [xsp+30h] [xbp-150h]
  __int64 v35; // [xsp+38h] [xbp-148h]
  _QWORD s[40]; // [xsp+40h] [xbp-140h] BYREF

  s[39] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x138u);
  v32 = 0;
  v2 = ipa3_ctx;
  v31 = 0;
  v30 = 0u;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d \n", "ipa3_ipv6ct_send_init_cmd", 1325);
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
      ipc_log_string(v4, "ipa %s:%d \n", "ipa3_ipv6ct_send_init_cmd", 1325);
  }
  memset(s, 0, 0x138u);
  v33 = 0;
  v34 = 0;
  v35 = 0;
  if ( (unsigned int)ipa_get_ep_mapping(95) == -1 || (*(_BYTE *)(ipa3_ctx + 51242) & 1) != 0 )
  {
    v5 = 0;
    v6 = 1;
  }
  else
  {
    ep_mapping = ipa_get_ep_mapping(95);
    BYTE12(v30) = 0;
    v8 = *(_DWORD *)(ipa3_ctx + 32240);
    v31 = 0;
    if ( v8 > 0x14 )
      ep_reg_offset = ipahal_get_ep_reg_offset(133, ep_mapping);
    else
      ep_reg_offset = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(44, 0, 0);
    LODWORD(v30) = ep_reg_offset;
    ipahal_get_aggr_force_close_valmask(ep_mapping, &v32);
    *(_QWORD *)((char *)&v30 + 4) = v32;
    v10 = ((__int64 (__fastcall *)(__int64, __int128 *, _QWORD))ipahal_construct_imm_cmd)(7, &v30, 0);
    v33 = v10;
    if ( !v10 )
    {
      printk(&unk_3AEDE8, "ipa3_ipv6ct_send_init_cmd");
      v27 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v28 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v28 )
        {
          ipc_log_string(v28, "ipa %s:%d failed to construct coal close IC\n", "ipa3_ipv6ct_send_init_cmd", 1351);
          v27 = ipa3_ctx;
        }
        v29 = *(_QWORD *)(v27 + 34160);
        if ( v29 )
        {
          ipc_log_string(v29, "ipa %s:%d failed to construct coal close IC\n", "ipa3_ipv6ct_send_init_cmd", 1351);
          v13 = -12;
          goto LABEL_33;
        }
      }
      goto LABEL_41;
    }
    ipa3_init_imm_cmd_desc(s, v10);
    v6 = 0;
    v5 = 1;
  }
  v11 = ipahal_construct_nop_imm_cmd(0, 0, 0);
  *(&v33 + v5) = v11;
  if ( !v11 )
  {
    printk(&unk_3CCC37, "ipa3_ipv6ct_send_init_cmd");
    v21 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v22 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v22 )
      {
        ipc_log_string(v22, "ipa %s:%d failed to construct NOP imm cmd\n", "ipa3_ipv6ct_send_init_cmd", 1363);
        v21 = ipa3_ctx;
      }
      v23 = *(_QWORD *)(v21 + 34160);
      if ( v23 )
        ipc_log_string(v23, "ipa %s:%d failed to construct NOP imm cmd\n", "ipa3_ipv6ct_send_init_cmd", 1363);
    }
    if ( (v6 & 1) == 0 )
      kfree(v33);
LABEL_41:
    v13 = -12;
    goto LABEL_33;
  }
  ipa3_init_imm_cmd_desc(&s[13 * v5], v11);
  v12 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))ipahal_construct_imm_cmd)(15, a1, 0);
  *(&v33 + v5 + 1) = v12;
  if ( v12 )
  {
    ipa3_init_imm_cmd_desc(&s[13 * v5 + 13], v12);
    v13 = ((__int64 (__fastcall *)(_QWORD, _QWORD *))ipa3_send_cmd)(v5 | 2, s);
    if ( v13 )
    {
      printk(&unk_3FE374, "ipa3_ipv6ct_send_init_cmd");
      v24 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v25 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v25 )
        {
          ipc_log_string(
            v25,
            "ipa %s:%d Fail to send IPv6CT init immediate command\n",
            "ipa3_ipv6ct_send_init_cmd",
            1390);
          v24 = ipa3_ctx;
        }
        v26 = *(_QWORD *)(v24 + 34160);
        if ( v26 )
          ipc_log_string(
            v26,
            "ipa %s:%d Fail to send IPv6CT init immediate command\n",
            "ipa3_ipv6ct_send_init_cmd",
            1390);
      }
    }
    else
    {
      v14 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v15 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v15 )
        {
          ipc_log_string(v15, "ipa %s:%d return\n", "ipa3_ipv6ct_send_init_cmd", 1394);
          v14 = ipa3_ctx;
        }
        v16 = *(_QWORD *)(v14 + 34160);
        if ( v16 )
          ipc_log_string(v16, "ipa %s:%d return\n", "ipa3_ipv6ct_send_init_cmd", 1394);
      }
    }
    kfree(v33);
    kfree(v34);
    if ( (v6 & 1) == 0 )
      kfree(v35);
    goto LABEL_33;
  }
  if ( (unsigned int)__ratelimit(&ipa3_ipv6ct_send_init_cmd__rs, "ipa3_ipv6ct_send_init_cmd") )
  {
    printk(&unk_3F56D3, "ipa3_ipv6ct_send_init_cmd");
    v17 = ipa3_ctx;
    if ( ipa3_ctx )
      goto LABEL_26;
  }
  else
  {
    v17 = ipa3_ctx;
    if ( ipa3_ctx )
    {
LABEL_26:
      v18 = *(_QWORD *)(v17 + 34152);
      if ( v18 )
      {
        ipc_log_string(v18, "ipa %s:%d fail to construct IPv6CT init imm cmd\n", "ipa3_ipv6ct_send_init_cmd", 1380);
        v17 = ipa3_ctx;
      }
      v19 = *(_QWORD *)(v17 + 34160);
      if ( v19 )
        ipc_log_string(v19, "ipa %s:%d fail to construct IPv6CT init imm cmd\n", "ipa3_ipv6ct_send_init_cmd", 1380);
    }
  }
  kfree(v33);
  if ( (v6 & 1) == 0 )
    kfree(v34);
  v13 = -1;
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return v13;
}
