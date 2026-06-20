__int64 __fastcall ipa3_nat_send_init_cmd(__int64 a1, char a2)
{
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  unsigned int v7; // w23
  char v8; // w21
  unsigned int ep_mapping; // w21
  unsigned int v10; // w8
  int ep_reg_offset; // w0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  unsigned int v15; // w19
  unsigned int modify_pdn_cmd; // w0
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  unsigned int v21; // w0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  unsigned int v25; // w20
  __int64 result; // x0
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x8
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x8
  __int64 v43; // x0
  __int64 v44; // x0
  _QWORD v45[3]; // [xsp+0h] [xbp-200h] BYREF
  __int128 v46; // [xsp+18h] [xbp-1E8h] BYREF
  int v47; // [xsp+28h] [xbp-1D8h]
  __int64 v48; // [xsp+30h] [xbp-1D0h] BYREF
  __int64 v49; // [xsp+38h] [xbp-1C8h]
  __int64 v50; // [xsp+40h] [xbp-1C0h]
  __int64 v51; // [xsp+48h] [xbp-1B8h]
  __int64 v52; // [xsp+50h] [xbp-1B0h]
  _QWORD s[53]; // [xsp+58h] [xbp-1A8h] BYREF

  s[52] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x1A0u);
  v48 = 0;
  v4 = ipa3_ctx;
  v47 = 0;
  v46 = 0u;
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d \n", "ipa3_nat_send_init_cmd", 1214);
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
      ipc_log_string(v6, "ipa %s:%d \n", "ipa3_nat_send_init_cmd", 1214);
  }
  memset(s, 0, 0x1A0u);
  v49 = 0;
  v50 = 0;
  v51 = 0;
  v52 = 0;
  if ( (unsigned int)ipa_get_ep_mapping(95) == -1 || (*(_BYTE *)(ipa3_ctx + 51242) & 1) != 0 )
  {
    v7 = 0;
    v8 = 1;
  }
  else
  {
    ep_mapping = ipa_get_ep_mapping(95);
    BYTE12(v46) = 0;
    v10 = *(_DWORD *)(ipa3_ctx + 32240);
    v47 = 0;
    if ( v10 > 0x14 )
      ep_reg_offset = ipahal_get_ep_reg_offset(133, ep_mapping);
    else
      ep_reg_offset = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(44, 0, 0);
    LODWORD(v46) = ep_reg_offset;
    ipahal_get_aggr_force_close_valmask(ep_mapping, &v48);
    *(_QWORD *)((char *)&v46 + 4) = v48;
    v12 = ((__int64 (__fastcall *)(__int64, __int128 *, _QWORD))ipahal_construct_imm_cmd)(7, &v46, 0);
    v49 = v12;
    if ( !v12 )
    {
      printk(&unk_3AEDE8, "ipa3_nat_send_init_cmd");
      v36 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v37 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v37 )
        {
          ipc_log_string(v37, "ipa %s:%d failed to construct coal close IC\n", "ipa3_nat_send_init_cmd", 1241);
          v36 = ipa3_ctx;
        }
        v38 = *(_QWORD *)(v36 + 34160);
        if ( v38 )
        {
          ipc_log_string(v38, "ipa %s:%d failed to construct coal close IC\n", "ipa3_nat_send_init_cmd", 1241);
          result = 4294967284LL;
          goto LABEL_44;
        }
      }
      goto LABEL_52;
    }
    ipa3_init_imm_cmd_desc(s, v12);
    v8 = 0;
    v7 = 1;
  }
  v13 = ipahal_construct_nop_imm_cmd(0, 0, 0);
  *(&v49 + v7) = v13;
  if ( !v13 )
  {
    printk(&unk_3CCC37, "ipa3_nat_send_init_cmd");
    v30 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v31 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v31 )
      {
        ipc_log_string(v31, "ipa %s:%d failed to construct NOP imm cmd\n", "ipa3_nat_send_init_cmd", 1253);
        v30 = ipa3_ctx;
      }
      v32 = *(_QWORD *)(v30 + 34160);
      if ( v32 )
        ipc_log_string(v32, "ipa %s:%d failed to construct NOP imm cmd\n", "ipa3_nat_send_init_cmd", 1253);
    }
    if ( (v8 & 1) == 0 )
      kfree(v49);
LABEL_52:
    result = 4294967284LL;
    goto LABEL_44;
  }
  ipa3_init_imm_cmd_desc(&s[13 * v7], v13);
  v14 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))ipahal_construct_imm_cmd)(2, a1, 0);
  *(&v49 + v7 + 1) = v14;
  if ( v14 )
  {
    ipa3_init_imm_cmd_desc(&s[13 * v7 + 13], v14);
    v15 = v7 | 2;
    if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0xEu )
    {
      memset(v45, 0, sizeof(v45));
      modify_pdn_cmd = ipa3_nat_create_modify_pdn_cmd(v45, a2 & 1);
      if ( modify_pdn_cmd )
      {
        v25 = modify_pdn_cmd;
        printk(&unk_3E689A, "ipa3_nat_send_init_cmd");
        v39 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v40 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v40 )
          {
            ipc_log_string(v40, "ipa %s:%d  Fail to create modify pdn command\n", "ipa3_nat_send_init_cmd", 1285);
            v39 = ipa3_ctx;
          }
          v41 = *(_QWORD *)(v39 + 34160);
          if ( v41 )
            ipc_log_string(v41, "ipa %s:%d  Fail to create modify pdn command\n", "ipa3_nat_send_init_cmd", 1285);
        }
        goto LABEL_31;
      }
      v17 = ((__int64 (__fastcall *)(__int64, _QWORD *, _QWORD))ipahal_construct_imm_cmd)(11, v45, 0);
      *(&v49 + v15) = v17;
      if ( !v17 )
      {
        printk(&unk_3EC777, "ipa3_nat_send_init_cmd");
        v42 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v43 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v43 )
          {
            ipc_log_string(
              v43,
              "ipa %s:%d fail construct dma_shared_mem cmd: for pdn table",
              "ipa3_nat_send_init_cmd",
              1292);
            v42 = ipa3_ctx;
          }
          v44 = *(_QWORD *)(v42 + 34160);
          if ( v44 )
            ipc_log_string(
              v44,
              "ipa %s:%d fail construct dma_shared_mem cmd: for pdn table",
              "ipa3_nat_send_init_cmd",
              1292);
        }
        v25 = -12;
        goto LABEL_31;
      }
      ipa3_init_imm_cmd_desc(&s[13 * v15], v17);
      v18 = ipa3_ctx;
      v15 = v7 + 3;
      if ( ipa3_ctx )
      {
        v19 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v19 )
        {
          ipc_log_string(v19, "ipa %s:%d added PDN table copy cmd\n", "ipa3_nat_send_init_cmd", 1298);
          v18 = ipa3_ctx;
        }
        v20 = *(_QWORD *)(v18 + 34160);
        if ( v20 )
          ipc_log_string(v20, "ipa %s:%d added PDN table copy cmd\n", "ipa3_nat_send_init_cmd", 1298);
      }
    }
    v21 = ((__int64 (__fastcall *)(_QWORD, _QWORD *))ipa3_send_cmd)(v15, s);
    if ( v21 )
    {
      v25 = v21;
      printk(&unk_3D5C73, "ipa3_nat_send_init_cmd");
      v33 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v34 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v34 )
        {
          ipc_log_string(v34, "ipa %s:%d fail to send NAT init immediate command\n", "ipa3_nat_send_init_cmd", 1303);
          v33 = ipa3_ctx;
        }
        v35 = *(_QWORD *)(v33 + 34160);
        if ( v35 )
          ipc_log_string(v35, "ipa %s:%d fail to send NAT init immediate command\n", "ipa3_nat_send_init_cmd", 1303);
      }
    }
    else
    {
      v22 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v23 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v23 )
        {
          ipc_log_string(v23, "ipa %s:%d return\n", "ipa3_nat_send_init_cmd", 1307);
          v22 = ipa3_ctx;
        }
        v24 = *(_QWORD *)(v22 + 34160);
        if ( v24 )
          ipc_log_string(v24, "ipa %s:%d return\n", "ipa3_nat_send_init_cmd", 1307);
      }
      v25 = 0;
    }
LABEL_31:
    kfree(v49);
    kfree(v50);
    if ( v15 != 2 )
    {
      kfree(v51);
      if ( v15 != 3 )
        kfree(v52);
    }
    result = v25;
    goto LABEL_44;
  }
  if ( (unsigned int)__ratelimit(&ipa3_nat_send_init_cmd__rs, "ipa3_nat_send_init_cmd") )
  {
    printk(&unk_3EF522, "ipa3_nat_send_init_cmd");
    v27 = ipa3_ctx;
    if ( ipa3_ctx )
      goto LABEL_37;
  }
  else
  {
    v27 = ipa3_ctx;
    if ( ipa3_ctx )
    {
LABEL_37:
      v28 = *(_QWORD *)(v27 + 34152);
      if ( v28 )
      {
        ipc_log_string(v28, "ipa %s:%d fail to construct NAT init imm cmd\n", "ipa3_nat_send_init_cmd", 1264);
        v27 = ipa3_ctx;
      }
      v29 = *(_QWORD *)(v27 + 34160);
      if ( v29 )
        ipc_log_string(v29, "ipa %s:%d fail to construct NAT init imm cmd\n", "ipa3_nat_send_init_cmd", 1264);
    }
  }
  kfree(v49);
  if ( (v8 & 1) == 0 )
    kfree(v50);
  result = 0xFFFFFFFFLL;
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return result;
}
