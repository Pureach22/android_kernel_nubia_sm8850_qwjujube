__int64 __fastcall ipa_generate_rt_hw_rule(int a1, __int64 a2, __int64 a3)
{
  int v4; // w8
  _DWORD *v5; // x21
  int ep_mapping; // w0
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 result; // x0
  int v19; // w19
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x20
  __int64 v31; // x11
  __int64 v32; // x2
  char v33; // w9
  __int64 v34; // x8
  __int64 v35; // x9
  int v36; // w8
  int v37; // w9
  int v38; // w10
  int v39; // w8
  int v40; // w9
  char v41; // w10
  unsigned int v42; // w19
  __int64 v43; // x8
  __int64 v44; // x0
  __int64 v45; // x0
  _DWORD v46[2]; // [xsp+0h] [xbp-30h] BYREF
  __int64 v47; // [xsp+8h] [xbp-28h]
  __int64 v48; // [xsp+10h] [xbp-20h]
  __int64 v49; // [xsp+18h] [xbp-18h]
  __int64 v50; // [xsp+20h] [xbp-10h]
  __int64 v51; // [xsp+28h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int8 *)(a2 + 185);
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  if ( v4 && (*(_BYTE *)(a2 + 35) & 8) != 0 )
  {
    if ( (unsigned int)__ratelimit(&ipa_generate_rt_hw_rule__rs, "ipa_generate_rt_hw_rule") )
      printk(&unk_3C0E1A, "ipa_generate_rt_hw_rule");
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d PURE_ACK rule atrb used with hash rule\n", "ipa_generate_rt_hw_rule", 57);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
      {
        ipc_log_string(v14, "ipa %s:%d PURE_ACK rule atrb used with hash rule\n", "ipa_generate_rt_hw_rule", 57);
        goto LABEL_31;
      }
    }
LABEL_45:
    result = 0xFFFFFFFFLL;
    goto LABEL_46;
  }
  v5 = (_DWORD *)(a2 + 20);
  v46[0] = a1;
  ep_mapping = ipa_get_ep_mapping(*(unsigned int *)(a2 + 20));
  v46[1] = ep_mapping;
  if ( ep_mapping == -1 )
  {
    if ( (unsigned int)__ratelimit(&ipa_generate_rt_hw_rule__rs_159, "ipa_generate_rt_hw_rule") )
      printk(&unk_3EF807, "ipa_generate_rt_hw_rule");
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v16 )
      {
        ipc_log_string(v16, "ipa %s:%d Wrong destination pipe specified in RT rule\n", "ipa_generate_rt_hw_rule", 65);
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
      {
        ipc_log_string(v17, "ipa %s:%d Wrong destination pipe specified in RT rule\n", "ipa_generate_rt_hw_rule", 65);
        goto LABEL_31;
      }
    }
    goto LABEL_45;
  }
  if ( *v5 > 0x85u || (*v5 & 1) == 0 )
  {
    v19 = ep_mapping;
    if ( (unsigned int)__ratelimit(&ipa_generate_rt_hw_rule__rs_162, "ipa_generate_rt_hw_rule") )
      printk(&unk_3AA455, "ipa_generate_rt_hw_rule");
    v20 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v21 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v21 )
      {
        ipc_log_string(v21, "ipa %s:%d No RT rule on IPA_client_producer pipe.\n", "ipa_generate_rt_hw_rule", 70);
        v20 = ipa3_ctx;
      }
      v22 = *(_QWORD *)(v20 + 34160);
      if ( v22 )
        ipc_log_string(v22, "ipa %s:%d No RT rule on IPA_client_producer pipe.\n", "ipa_generate_rt_hw_rule", 70);
    }
    if ( (unsigned int)__ratelimit(&ipa_generate_rt_hw_rule__rs_165, "ipa_generate_rt_hw_rule") )
    {
      printk(&unk_3EF840, "ipa_generate_rt_hw_rule");
      v23 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_45;
    }
    else
    {
      v23 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_45;
    }
    v24 = *(_QWORD *)(v23 + 34152);
    if ( v24 )
    {
      ipc_log_string(v24, "ipa %s:%d pipe_idx: %d dst_pipe: %d\n", "ipa_generate_rt_hw_rule", 72, v19, *v5);
      v23 = ipa3_ctx;
    }
    v25 = *(_QWORD *)(v23 + 34160);
    if ( v25 )
      ipc_log_string(v25, "ipa %s:%d pipe_idx: %d dst_pipe: %d\n", "ipa_generate_rt_hw_rule", 72, v19, *v5);
    goto LABEL_45;
  }
  if ( *(_QWORD *)(a2 + 208) )
  {
    v8 = ipa3_id_find(*(unsigned int *)(a2 + 24));
    if ( !v8 || *(_DWORD *)(v8 + 16) != 1468208647 || (ipa3_check_idr_if_freed(*(_QWORD *)(a2 + 208)) & 1) != 0 )
    {
      if ( (unsigned int)__ratelimit(&ipa_generate_rt_hw_rule__rs_168, "ipa_generate_rt_hw_rule") )
        printk(&unk_3D352B, "ipa_generate_rt_hw_rule");
      v9 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v10 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v10 )
        {
          ipc_log_string(v10, "ipa %s:%d Header entry already deleted\n", "ipa_generate_rt_hw_rule", 85);
          v9 = ipa3_ctx;
        }
        v11 = *(_QWORD *)(v9 + 34160);
        if ( v11 )
        {
          ipc_log_string(v11, "ipa %s:%d Header entry already deleted\n", "ipa_generate_rt_hw_rule", 85);
LABEL_31:
          result = 0xFFFFFFFFLL;
          goto LABEL_46;
        }
      }
      goto LABEL_45;
    }
  }
  else if ( *(_QWORD *)(a2 + 216) )
  {
    v26 = ipa3_id_find(*(unsigned int *)(a2 + 28));
    if ( !v26 || *(_DWORD *)(v26 + 16) != 1468208648 || (ipa3_check_idr_if_freed(*(_QWORD *)(a2 + 216)) & 1) != 0 )
    {
      if ( (unsigned int)__ratelimit(&ipa_generate_rt_hw_rule__rs_169, "ipa_generate_rt_hw_rule") )
        printk(&unk_3DEBEF, "ipa_generate_rt_hw_rule");
      v27 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v28 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v28 )
        {
          ipc_log_string(v28, "ipa %s:%d Proc header entry already deleted\n", "ipa_generate_rt_hw_rule", 93);
          v27 = ipa3_ctx;
        }
        v29 = *(_QWORD *)(v27 + 34160);
        if ( v29 )
        {
          ipc_log_string(v29, "ipa %s:%d Proc header entry already deleted\n", "ipa_generate_rt_hw_rule", 93);
          goto LABEL_31;
        }
      }
      goto LABEL_45;
    }
  }
  v30 = *(_QWORD *)(a2 + 216);
  if ( v30 )
  {
    if ( (ipa3_check_idr_if_freed(*(_QWORD *)(a2 + 216)) & 1) != 0 || *(_DWORD *)(v30 + 16) != 1468208648 )
    {
      LODWORD(v47) = 0;
      v32 = a3;
      LODWORD(v48) = 0;
    }
    else
    {
      v31 = *(_QWORD *)(v30 + 56);
      v32 = a3;
      v33 = *(_BYTE *)(ipa3_ctx + 30408);
      LODWORD(v47) = 2;
      BYTE4(v47) = v33;
      LODWORD(v48) = *(_DWORD *)(ipa3_ctx + 29176) + *(_DWORD *)(v31 + 16);
    }
  }
  else
  {
    v34 = *(_QWORD *)(a2 + 208);
    v32 = a3;
    if ( v34 && *(_DWORD *)(v34 + 16) == 1468208647 )
    {
      v35 = *(_QWORD *)(v34 + 328);
      v36 = *(unsigned __int8 *)(v34 + 350);
      LODWORD(v47) = 1;
      v37 = *(_DWORD *)(v35 + 16);
      if ( v36 == 1 )
        v38 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 144LL);
      else
        v38 = 0;
      BYTE4(v47) = v36;
      LODWORD(v48) = v38 + v37;
    }
    else
    {
      LODWORD(v47) = 0;
      LODWORD(v48) = 0;
    }
  }
  v39 = *(unsigned __int16 *)(a2 + 232);
  v40 = *(unsigned __int16 *)(a2 + 234);
  v41 = *(_BYTE *)(a2 + 238);
  v50 = a2 + 20;
  HIDWORD(v48) = v39;
  LODWORD(v49) = v40;
  BYTE4(v49) = v41;
  result = ((__int64 (__fastcall *)(_DWORD *, __int64, __int64))ipahal_rt_generate_hw_rule)(v46, a2 + 224, v32);
  if ( (_DWORD)result )
  {
    v42 = result;
    printk(&unk_3FE796, "ipa_generate_rt_hw_rule");
    v43 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v44 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v44 )
      {
        ipc_log_string(v44, "ipa %s:%d failed to generate rt h/w rule\n", "ipa_generate_rt_hw_rule", 131);
        v43 = ipa3_ctx;
      }
      v45 = *(_QWORD *)(v43 + 34160);
      if ( v45 )
        ipc_log_string(v45, "ipa %s:%d failed to generate rt h/w rule\n", "ipa_generate_rt_hw_rule", 131);
    }
    result = v42;
  }
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
