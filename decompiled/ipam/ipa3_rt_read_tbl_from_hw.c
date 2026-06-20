__int64 __fastcall ipa3_rt_read_tbl_from_hw(unsigned int a1, unsigned int a2, char a3, _DWORD *a4, int *a5)
{
  _DWORD *v6; // x21
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 result; // x0
  __int64 v15; // x8
  _DWORD *v16; // x9
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x8
  int v21; // w19
  __int64 v22; // x0
  __int64 v23; // x2
  __int64 v24; // x0
  __int64 v25; // x19
  __int64 v26; // x11
  __int64 v27; // x12
  __int64 v28; // x10
  __int64 v29; // x25
  __int64 v30; // x0
  __int64 v31; // x25
  __int64 v32; // x0
  __int64 v33; // x1
  __int64 v34; // x8
  __int64 v35; // x9
  __int64 *v36; // x28
  __int64 v37; // x26
  char *v38; // x24
  __int64 *v39; // x24
  __int64 v40; // x8
  _QWORD *v41; // x24
  __int64 v42; // t1
  __int64 v43; // x8
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x25
  unsigned int v48; // w0
  __int64 v49; // x0
  __int64 v50; // x8
  unsigned int v51; // w21
  __int64 v52; // x8
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x8
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x8
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x8
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x8
  __int64 v65; // x0
  __int64 v66; // x0
  char v67[4]; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v68[2]; // [xsp+10h] [xbp-10h] BYREF

  v6 = a4;
  v68[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v68[0] = 0;
  v67[0] = 0;
  if ( ipa3_ctx )
  {
    v10 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v10 )
      ipc_log_string(
        v10,
        "ipa %s:%d tbl_idx=%d ip_t=%d hash=%d entry=0x%pK num_entry=0x%pK\n",
        "ipa3_rt_read_tbl_from_hw",
        2450,
        a1,
        a2,
        a3 & 1,
        a4,
        a5);
  }
  if ( (a3 & 1) != 0 )
  {
    v11 = ipa3_ctx;
    if ( *(_BYTE *)(ipa3_ctx + 32270) == 1 )
    {
      if ( ipa3_ctx )
      {
        v12 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v12 )
        {
          ipc_log_string(v12, "ipa %s:%d Reading hashable rules not supported\n", "ipa3_rt_read_tbl_from_hw", 2457);
          v11 = ipa3_ctx;
        }
        v13 = *(_QWORD *)(v11 + 34160);
        if ( v13 )
          ipc_log_string(v13, "ipa %s:%d Reading hashable rules not supported\n", "ipa3_rt_read_tbl_from_hw", 2457);
      }
      result = 0;
      *a5 = 0;
      goto LABEL_104;
    }
  }
  if ( a2 )
  {
    v15 = ipa3_ctx;
    v16 = *(_DWORD **)(ipa3_ctx + 34176);
    if ( a2 == 1 && *(_DWORD *)(*(_QWORD *)v16 + 96LL) <= a1 )
    {
      if ( (unsigned int)__ratelimit(&ipa3_rt_read_tbl_from_hw__rs_128, "ipa3_rt_read_tbl_from_hw") )
      {
        printk(&unk_3EF7CA, "ipa3_rt_read_tbl_from_hw");
        v17 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_103;
      }
      else
      {
        v17 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_103;
      }
      v18 = *(_QWORD *)(v17 + 34152);
      if ( v18 )
      {
        ipc_log_string(v18, "ipa %s:%d Invalid params\n", "ipa3_rt_read_tbl_from_hw", 2468);
        v17 = ipa3_ctx;
      }
      v19 = *(_QWORD *)(v17 + 34160);
      if ( v19 )
      {
        ipc_log_string(v19, "ipa %s:%d Invalid params\n", "ipa3_rt_read_tbl_from_hw", 2468);
LABEL_77:
        result = 4294967282LL;
LABEL_104:
        _ReadStatusReg(SP_EL0);
        return result;
      }
LABEL_103:
      result = 4294967282LL;
      goto LABEL_104;
    }
  }
  else
  {
    v15 = ipa3_ctx;
    v16 = *(_DWORD **)(ipa3_ctx + 34176);
    if ( *(_DWORD *)(*(_QWORD *)v16 + 52LL) <= a1 )
    {
      if ( (unsigned int)__ratelimit(&ipa3_rt_read_tbl_from_hw__rs, "ipa3_rt_read_tbl_from_hw") )
      {
        printk(&unk_3EF7CA, "ipa3_rt_read_tbl_from_hw");
        v52 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_103;
      }
      else
      {
        v52 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_103;
      }
      v53 = *(_QWORD *)(v52 + 34152);
      if ( v53 )
      {
        ipc_log_string(v53, "ipa %s:%d Invalid params\n", "ipa3_rt_read_tbl_from_hw", 2463);
        v52 = ipa3_ctx;
      }
      v54 = *(_QWORD *)(v52 + 34160);
      if ( v54 )
      {
        ipc_log_string(v54, "ipa %s:%d Invalid params\n", "ipa3_rt_read_tbl_from_hw", 2463);
        goto LABEL_77;
      }
      goto LABEL_103;
    }
  }
  v20 = v15 + 28640;
  v21 = v16[9] + *(_DWORD *)v20;
  v22 = v21
      + (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(
                        64,
                        0,
                        *(unsigned __int16 *)(v20 + 882) >> 2);
  if ( arm64_use_ng_mappings )
    v23 = 0x68000000000F13LL;
  else
    v23 = 0x68000000000713LL;
  v24 = ioremap_prot(v22, *(unsigned __int16 *)(ipa3_ctx + 29520), v23);
  if ( !v24 )
  {
    printk(&unk_3A5EB7, "ipa3_rt_read_tbl_from_hw");
    v55 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_98;
    v56 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v56 )
    {
      ipc_log_string(v56, "ipa %s:%d fail to ioremap IPA SRAM\n", "ipa3_rt_read_tbl_from_hw", 2479);
      v55 = ipa3_ctx;
    }
    v57 = *(_QWORD *)(v55 + 34160);
    if ( v57 )
    {
      ipc_log_string(v57, "ipa %s:%d fail to ioremap IPA SRAM\n", "ipa3_rt_read_tbl_from_hw", 2479);
      result = 4294967284LL;
    }
    else
    {
LABEL_98:
      result = 4294967284LL;
    }
    goto LABEL_104;
  }
  v25 = v24;
  memset(v6, 0, 224LL * *a5);
  v26 = 116;
  if ( a2 )
  {
    v27 = 128;
  }
  else
  {
    v26 = 72;
    v27 = 84;
  }
  if ( (a3 & 1) == 0 )
    v26 = v27;
  v28 = **(_QWORD **)(ipa3_ctx + 34176);
  v29 = *(unsigned int *)(v28 + v26);
  if ( ipa3_ctx )
  {
    v30 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v30 )
      ipc_log_string(
        v30,
        "ipa %s:%d hdr_base_ofst=0x%llx\n",
        "ipa3_rt_read_tbl_from_hw",
        2500,
        *(unsigned int *)(v28 + v26));
  }
  v31 = v25 + v29;
  v32 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD *, char *))ipahal_fltrt_read_addr_from_hdr)(v31, a1, v68, v67);
  if ( (_DWORD)v32 )
  {
    v51 = v32;
    printk(&unk_3CC922, "ipa3_rt_read_tbl_from_hw");
    v58 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v59 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v59 )
      {
        ipc_log_string(
          v59,
          "ipa %s:%d failed to read table address from header structure\n",
          "ipa3_rt_read_tbl_from_hw",
          2505);
        v58 = ipa3_ctx;
      }
      v60 = *(_QWORD *)(v58 + 34160);
      if ( v60 )
        ipc_log_string(
          v60,
          "ipa %s:%d failed to read table address from header structure\n",
          "ipa3_rt_read_tbl_from_hw",
          2505);
    }
    goto LABEL_80;
  }
  if ( ipa3_ctx )
  {
    v32 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v32 )
      v32 = ipc_log_string(
              v32,
              "ipa %s:%d rt tbl %d: tbl_addr=0x%llx is_sys=%d\n",
              "ipa3_rt_read_tbl_from_hw",
              2509,
              a1,
              v68[0],
              (unsigned __int8)v67[0]);
  }
  if ( !v68[0] )
  {
    printk(&unk_3EF7E6, "ipa3_rt_read_tbl_from_hw");
    v61 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_99;
    v62 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v62 )
    {
      ipc_log_string(v62, "ipa %s:%d invalid rt tbl addr\n", "ipa3_rt_read_tbl_from_hw", 2511);
      v61 = ipa3_ctx;
    }
    v63 = *(_QWORD *)(v61 + 34160);
    if ( v63 )
    {
      ipc_log_string(v63, "ipa %s:%d invalid rt tbl addr\n", "ipa3_rt_read_tbl_from_hw", 2511);
      v51 = -14;
    }
    else
    {
LABEL_99:
      v51 = -14;
    }
LABEL_80:
    iounmap(v25);
    result = v51;
    goto LABEL_104;
  }
  if ( v67[0] != 1 )
  {
    v38 = (char *)(v31 + v68[0]);
    goto LABEL_57;
  }
  if ( a2 < 3 )
  {
    v34 = ipa3_ctx;
    v35 = ipa3_ctx + 48LL * a2;
    v36 = *(__int64 **)(v35 + 29184);
    v37 = v35 + 29184;
    if ( v36 == (__int64 *)(v35 + 29184) )
    {
      v38 = nullptr;
      if ( !ipa3_ctx )
        goto LABEL_60;
      goto LABEL_58;
    }
    v38 = nullptr;
    do
    {
      if ( *((_DWORD *)v36 + 18) == a1 )
      {
        v39 = &v36[3 * ((a3 & 1) == 0)];
        v42 = v39[15];
        v41 = v39 + 15;
        v40 = v42;
        if ( !v42 )
          goto LABEL_43;
        if ( v40 == v68[0] )
          goto LABEL_48;
        printk(&unk_3F2BFC, "ipa3_rt_read_tbl_from_hw");
        v43 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v44 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v44 )
          {
            ipc_log_string(
              v44,
              "ipa %s:%d mismatch:parsed=%llx sw=%pad\n",
              "ipa3_rt_read_tbl_from_hw",
              2532,
              v68[0],
              v41);
            v43 = ipa3_ctx;
          }
          v45 = *(_QWORD *)(v43 + 34160);
          if ( v45 )
            ipc_log_string(
              v45,
              "ipa %s:%d mismatch:parsed=%llx sw=%pad\n",
              "ipa3_rt_read_tbl_from_hw",
              2532,
              v68[0],
              v41);
        }
        if ( *v41 )
LABEL_48:
          v38 = (char *)*(v41 - 1);
        else
LABEL_43:
          v38 = nullptr;
      }
      v36 = (__int64 *)*v36;
    }
    while ( v36 != (__int64 *)v37 );
LABEL_57:
    v34 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_60;
LABEL_58:
    v46 = *(_QWORD *)(v34 + 34160);
    if ( v46 )
      ipc_log_string(v46, "ipa %s:%d First rule addr 0x%pK\n", "ipa3_rt_read_tbl_from_hw", 2544, v38);
LABEL_60:
    if ( v38 )
    {
      if ( *a5 < 1 )
      {
        LODWORD(v47) = 0;
LABEL_79:
        v51 = 0;
        *a5 = v47;
      }
      else
      {
        v47 = 0;
        while ( 1 )
        {
          v48 = ipahal_rt_parse_hw_rule(v38, v6);
          if ( v48 )
            break;
          if ( ipa3_ctx )
          {
            v49 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v49 )
              ipc_log_string(v49, "ipa %s:%d rule_size=%d\n", "ipa3_rt_read_tbl_from_hw", 2560, v6[55]);
          }
          v50 = (unsigned int)v6[55];
          if ( (_DWORD)v50 )
          {
            ++v47;
            v38 += v50;
            v6 += 56;
            if ( v47 < *a5 )
              continue;
          }
          goto LABEL_79;
        }
        v51 = v48;
        printk(&unk_3DEC43, "ipa3_rt_read_tbl_from_hw");
        v64 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v65 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v65 )
          {
            ipc_log_string(v65, "ipa %s:%d failed parsing rt rule\n", "ipa3_rt_read_tbl_from_hw", 2556);
            v64 = ipa3_ctx;
          }
          v66 = *(_QWORD *)(v64 + 34160);
          if ( v66 )
            ipc_log_string(v66, "ipa %s:%d failed parsing rt rule\n", "ipa3_rt_read_tbl_from_hw", 2556);
        }
      }
    }
    else
    {
      v51 = 0;
      *a5 = 0;
    }
    goto LABEL_80;
  }
  __break(0x5512u);
  return ipa3_set_nat_conn_track_exc_rt_tbl(v32, v33);
}
