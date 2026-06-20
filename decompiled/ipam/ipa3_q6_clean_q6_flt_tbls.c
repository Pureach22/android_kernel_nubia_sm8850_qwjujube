__int64 __fastcall ipa3_q6_clean_q6_flt_tbls(int a1, int a2)
{
  _UNKNOWN **v2; // x25
  unsigned __int64 v3; // x23
  unsigned __int64 v4; // x22
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x26
  unsigned __int64 v12; // x21
  __int64 *v13; // x20
  __int64 v14; // x10
  __int64 v15; // x9
  __int64 v16; // x11
  __int64 v17; // x12
  __int64 v18; // x8
  int v19; // w0
  unsigned int ep_mapping; // w0
  _BYTE *v21; // x8
  unsigned int v22; // w24
  int v23; // w0
  __int64 v24; // x0
  bool v25; // zf
  int v26; // w27
  __int64 v27; // x24
  int v28; // w19
  _BYTE *v29; // x8
  _UNKNOWN **v30; // x20
  int v31; // w26
  int v32; // w26
  __int64 v33; // x0
  _QWORD *v34; // x8
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  int v39; // w0
  __int64 v40; // x19
  _QWORD *v41; // x8
  __int64 v42; // x0
  __int64 v43; // x0
  int v44; // w23
  _QWORD *v45; // x8
  __int64 v46; // x0
  __int64 v47; // x0
  _QWORD *v48; // x8
  __int64 v49; // x0
  __int64 v50; // x0
  _QWORD *v51; // x8
  __int64 v52; // x0
  __int64 v53; // x0
  _DWORD *v54; // x9
  unsigned __int64 StatusReg; // x19
  __int64 v56; // x20
  int v58; // [xsp+Ch] [xbp-64h]
  __int64 *v59; // [xsp+10h] [xbp-60h]
  __int128 v60; // [xsp+18h] [xbp-58h] BYREF
  int v61; // [xsp+28h] [xbp-48h]
  __int64 v62; // [xsp+30h] [xbp-40h] BYREF
  __int64 v63; // [xsp+38h] [xbp-38h] BYREF
  __int64 v64; // [xsp+40h] [xbp-30h]
  __int64 v65; // [xsp+48h] [xbp-28h]
  __int64 v66; // [xsp+50h] [xbp-20h] BYREF
  __int64 v67; // [xsp+58h] [xbp-18h]
  __int64 v68; // [xsp+60h] [xbp-10h]
  __int64 v69; // [xsp+68h] [xbp-8h]

  v2 = &off_1F7000;
  LODWORD(v3) = a2;
  LODWORD(v4) = a1;
  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = ipa3_ctx;
  v67 = 0;
  v68 = 0;
  v66 = 0;
  v64 = 0;
  v65 = 0;
  v62 = 0;
  v63 = 0;
  v61 = 0;
  v60 = 0u;
  if ( ipa3_ctx )
  {
    v6 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v6 )
    {
      ipc_log_string(v6, "ipa %s:%d Entry\n", "ipa3_q6_clean_q6_flt_tbls", 4882);
      v5 = ipa3_ctx;
    }
    v7 = *(_QWORD *)(v5 + 34160);
    if ( v7 )
      ipc_log_string(v7, "ipa %s:%d Entry\n", "ipa3_q6_clean_q6_flt_tbls", 4882);
  }
  if ( !(_DWORD)v3 )
  {
    v8 = ipa3_ctx;
    if ( *(_BYTE *)(ipa3_ctx + 32270) == 1 )
    {
      if ( !ipa3_ctx )
        goto LABEL_28;
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d Clean hashable rules not supported\n", "ipa3_q6_clean_q6_flt_tbls", 4894);
        v8 = ipa3_ctx;
      }
      v10 = *(_QWORD *)(v8 + 34160);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d Clean hashable rules not supported\n", "ipa3_q6_clean_q6_flt_tbls", 4894);
        LODWORD(v3) = 0;
      }
      else
      {
LABEL_28:
        LODWORD(v3) = 0;
      }
      goto LABEL_99;
    }
  }
  v11 = _kmalloc_noprof(104LL * (unsigned int)(*(_DWORD *)(ipa3_ctx + 17496) + 1), 2336);
  if ( !v11 )
  {
LABEL_96:
    LODWORD(v3) = -12;
    goto LABEL_99;
  }
  while ( 1 )
  {
    v12 = 8LL * (unsigned int)(*((_DWORD *)v2[257] + 4374) + 1);
    v13 = (__int64 *)_kmalloc_noprof(v12, 2336);
    if ( !v13 )
    {
      LODWORD(v3) = -12;
      goto LABEL_98;
    }
    v14 = 16;
    if ( (_DWORD)v3 )
    {
      v15 = 20;
    }
    else
    {
      v14 = 4;
      v15 = 8;
    }
    v16 = 40;
    if ( !(_DWORD)v3 )
      v16 = 28;
    v17 = 44;
    v18 = **((_QWORD **)v2[257] + 4272);
    if ( !(_DWORD)v3 )
      v17 = 32;
    if ( (_DWORD)v4 )
    {
      v15 = v17;
      v14 = v16;
    }
    v58 = *(_DWORD *)(v18 + v14);
    v19 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, __int64 *, __int64))ipahal_flt_generate_empty_img)(
            1,
            *(unsigned int *)(v18 + v15),
            *(unsigned int *)(v18 + v15),
            0,
            &v63,
            1);
    if ( v19 )
    {
      LODWORD(v3) = v19;
      printk(&unk_3F16ED, "ipa3_q6_clean_q6_flt_tbls");
      v41 = v2[257];
      if ( v41 )
      {
        v42 = v41[4269];
        if ( v42 )
        {
          ipc_log_string(
            v42,
            "ipa %s:%d failed to generate flt single tbl empty img\n",
            "ipa3_q6_clean_q6_flt_tbls",
            4932);
          v41 = v2[257];
        }
        v43 = v41[4270];
        if ( v43 )
          ipc_log_string(
            v43,
            "ipa %s:%d failed to generate flt single tbl empty img\n",
            "ipa3_q6_clean_q6_flt_tbls",
            4932);
      }
      goto LABEL_67;
    }
    ep_mapping = ipa_get_ep_mapping(95);
    v21 = v2[257];
    v22 = ep_mapping;
    if ( ep_mapping == -1 || (v21[51242] & 1) != 0 )
    {
      LODWORD(v4) = 0;
      goto LABEL_35;
    }
    BYTE12(v60) = 0;
    v61 = 0;
    v23 = *((_DWORD *)v21 + 8060) > 0x14u
        ? ipahal_get_ep_reg_offset(133, ep_mapping)
        : ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(44, 0, 0);
    LODWORD(v60) = v23;
    ipahal_get_aggr_force_close_valmask(v22, &v62);
    *(_QWORD *)((char *)&v60 + 4) = v62;
    v24 = ((__int64 (__fastcall *)(__int64, __int128 *, _QWORD))ipahal_construct_imm_cmd)(7, &v60, 0);
    if ( v12 )
      break;
LABEL_94:
    __break(1u);
LABEL_95:
    __break(0x5512u);
    v54 = v2[257];
    StatusReg = _ReadStatusReg(SP_EL0);
    v56 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &ipa3_q6_clean_q6_flt_tbls__alloc_tag;
    v11 = _kmalloc_noprof(104LL * (unsigned int)(v54[4374] + 1), 2336);
    *(_QWORD *)(StatusReg + 80) = v56;
    if ( !v11 )
      goto LABEL_96;
  }
  *v13 = v24;
  if ( !v24 )
  {
    printk(&unk_3AEDE8, "ipa3_q6_clean_q6_flt_tbls");
    v48 = v2[257];
    if ( v48 )
    {
      v49 = v48[4269];
      if ( v49 )
      {
        ipc_log_string(v49, "ipa %s:%d failed to construct coal close IC\n", "ipa3_q6_clean_q6_flt_tbls", 4957);
        v48 = v2[257];
      }
      v50 = v48[4270];
      if ( v50 )
        ipc_log_string(v50, "ipa %s:%d failed to construct coal close IC\n", "ipa3_q6_clean_q6_flt_tbls", 4957);
    }
    ipahal_free_dma_mem(&v63);
    LODWORD(v3) = -12;
    goto LABEL_67;
  }
  ipa3_init_imm_cmd_desc(v11, v24);
  v21 = v2[257];
  LODWORD(v4) = 1;
LABEL_35:
  if ( !*((_DWORD *)v21 + 8577) )
  {
LABEL_56:
    if ( v21 )
    {
      v37 = *((_QWORD *)v21 + 4269);
      if ( v37 )
      {
        ipc_log_string(
          v37,
          "ipa %s:%d Sending %d descriptors for flt tbl clearing\n",
          "ipa3_q6_clean_q6_flt_tbls",
          5012,
          v4);
        v21 = v2[257];
      }
      v38 = *((_QWORD *)v21 + 4270);
      if ( v38 )
        ipc_log_string(
          v38,
          "ipa %s:%d Sending %d descriptors for flt tbl clearing\n",
          "ipa3_q6_clean_q6_flt_tbls",
          5012,
          v4);
    }
    v39 = ((__int64 (__fastcall *)(_QWORD, __int64))ipa3_send_cmd)((unsigned int)v4, v11);
    if ( v39 )
    {
      v44 = v39;
      printk(&unk_3B759A, "ipa3_q6_clean_q6_flt_tbls");
      v45 = v2[257];
      if ( v45 )
      {
        v46 = v45[4269];
        if ( v46 )
        {
          ipc_log_string(
            v46,
            "ipa %s:%d failed to send immediate command (err %d)\n",
            "ipa3_q6_clean_q6_flt_tbls",
            5015,
            v44);
          v45 = v2[257];
        }
        v47 = v45[4270];
        if ( v47 )
          ipc_log_string(
            v47,
            "ipa %s:%d failed to send immediate command (err %d)\n",
            "ipa3_q6_clean_q6_flt_tbls",
            5015,
            v44);
      }
      LODWORD(v3) = -14;
    }
    else
    {
      LODWORD(v3) = 0;
    }
    goto LABEL_63;
  }
  v25 = v22 == -1;
  v3 = 0;
  v26 = 0;
  v27 = 572;
  v28 = !v25;
  v59 = v13;
  while ( 1 )
  {
    if ( (ipa_is_ep_support_flt((unsigned int)v3) & 1) == 0 )
      goto LABEL_42;
    if ( v3 >= 0x24 )
      goto LABEL_95;
    v29 = v2[257];
    if ( !*(_DWORD *)&v29[v27 - 404] || v29[v27] == 1 )
      break;
LABEL_41:
    ++v26;
LABEL_42:
    v21 = v2[257];
    ++v3;
    v27 += 480;
    if ( v3 >= *((unsigned int *)v21 + 8577) )
    {
      v13 = v59;
      goto LABEL_56;
    }
  }
  if ( (unsigned int)v4 >= *((_DWORD *)v29 + 4374) + v28 )
  {
    printk(&unk_3B1937, "ipa3_q6_clean_q6_flt_tbls");
    v51 = v2[257];
    if ( v51 )
    {
      v13 = v59;
      v52 = v51[4269];
      if ( v52 )
      {
        ipc_log_string(v52, "ipa %s:%d number of commands is out of range\n", "ipa3_q6_clean_q6_flt_tbls", 4982);
        v51 = v2[257];
      }
      v53 = v51[4270];
      if ( v53 )
        ipc_log_string(v53, "ipa %s:%d number of commands is out of range\n", "ipa3_q6_clean_q6_flt_tbls", 4982);
      LODWORD(v3) = -105;
    }
    else
    {
      v13 = v59;
      LODWORD(v3) = -105;
    }
    goto LABEL_63;
  }
  v30 = v2;
  *(_WORD *)((char *)&v68 + 1) = 0;
  v2 = (_UNKNOWN **)v11;
  HIDWORD(v68) = 0;
  LODWORD(v67) = v65;
  v66 = v64;
  v31 = *((unsigned __int16 *)v29 + 14761);
  v32 = v58 + ((__int64 (*)(void))ipahal_get_hw_tbl_hdr_width)() + v31;
  HIDWORD(v67) = v32 + ((__int64 (*)(void))ipahal_get_hw_tbl_hdr_width)() * v26;
  v33 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(11, &v66, 0);
  if ( v12 <= 8LL * (int)v4 )
    goto LABEL_94;
  v11 = (__int64)v2;
  v59[(int)v4] = v33;
  if ( v33 )
  {
    ipa3_init_imm_cmd_desc(&v2[13 * (int)v4], v33);
    LODWORD(v4) = v4 + 1;
    v2 = v30;
    goto LABEL_41;
  }
  printk(&unk_3A5FC7, "ipa3_q6_clean_q6_flt_tbls");
  v34 = v30[257];
  if ( v34 )
  {
    v35 = v34[4269];
    if ( v35 )
    {
      ipc_log_string(v35, "ipa %s:%d fail construct dma_shared_mem cmd\n", "ipa3_q6_clean_q6_flt_tbls", 5000);
      v34 = v30[257];
    }
    v13 = v59;
    v36 = v34[4270];
    if ( v36 )
    {
      ipc_log_string(v36, "ipa %s:%d fail construct dma_shared_mem cmd\n", "ipa3_q6_clean_q6_flt_tbls", 5000);
      LODWORD(v3) = -12;
      goto LABEL_63;
    }
  }
  else
  {
    v13 = v59;
  }
  LODWORD(v3) = -12;
LABEL_63:
  ipahal_free_dma_mem(&v63);
  if ( (int)v4 >= 1 )
  {
    v40 = 8LL * (unsigned int)v4;
    v4 = 0;
    while ( v12 > v4 )
    {
      kfree(v13[v4 / 8]);
      v4 += 8LL;
      if ( v40 == v4 )
        goto LABEL_67;
    }
    goto LABEL_94;
  }
LABEL_67:
  kfree(v13);
LABEL_98:
  kfree(v11);
LABEL_99:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v3;
}
