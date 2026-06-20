__int64 __fastcall ipa3_nat_init_cmd(unsigned __int8 *a1)
{
  __int64 v2; // x23
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  unsigned int v6; // w21
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  int v10; // w8
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  unsigned int v16; // w20
  __int64 v17; // x8
  __int64 v18; // x0
  const char *v19; // x8
  const char *v20; // x4
  __int64 v21; // x0
  const char *v22; // x8
  const char *v23; // x4
  unsigned int v24; // w0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  unsigned int v34; // w0
  __int64 v35; // x0
  __int64 v36; // x0
  unsigned int v37; // w0
  __int64 v38; // x0
  __int64 v39; // x0
  unsigned int v40; // w0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x8
  __int64 v44; // x0
  const char *v45; // x8
  const char *v46; // x4
  __int64 v47; // x0
  const char *v48; // x8
  const char *v49; // x4
  unsigned __int8 *v50; // x0
  __int64 v51; // x1
  __int64 v52; // x2
  __int64 v53; // x8
  int v54; // w8
  unsigned int v55; // w0
  __int64 v56; // x0
  __int64 v57; // x0
  unsigned int inited; // w0
  unsigned int v59; // w0
  __int64 v60; // x8
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x8
  __int64 v68; // x0
  __int64 v69; // x0
  int v70; // [xsp+Ch] [xbp-44h] BYREF
  __int64 v71; // [xsp+10h] [xbp-40h]
  __int64 v72; // [xsp+18h] [xbp-38h] BYREF
  __int64 v73; // [xsp+20h] [xbp-30h]
  __int64 v74; // [xsp+28h] [xbp-28h]
  __int64 v75; // [xsp+30h] [xbp-20h]
  __int64 v76; // [xsp+38h] [xbp-18h]
  __int64 v77; // [xsp+40h] [xbp-10h]
  __int64 v78; // [xsp+48h] [xbp-8h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = ipa3_ctx;
  v76 = 0;
  v77 = 0;
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    v4 = ipa3_ctx;
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d In\n", "ipa3_nat_init_cmd", 1424);
      v4 = ipa3_ctx;
    }
    v5 = *(_QWORD *)(v4 + 34160);
    if ( v5 )
      ipc_log_string(v5, "ipa %s:%d In\n", "ipa3_nat_init_cmd", 1424);
  }
  if ( sram_compatible == 1 )
  {
    v6 = a1[28];
    v7 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_14;
  }
  else
  {
    v6 = 0;
    *((_WORD *)a1 + 14) = 0;
    v7 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_14;
  }
  v8 = *(_QWORD *)(v7 + 34152);
  if ( v8 )
  {
    ipc_log_string(
      v8,
      "ipa %s:%d tbl_index(%d) table_entries(%u)\n",
      "ipa3_nat_init_cmd",
      1435,
      *a1,
      *((unsigned __int16 *)a1 + 10));
    v7 = ipa3_ctx;
  }
  v9 = *(_QWORD *)(v7 + 34160);
  if ( v9 )
    ipc_log_string(
      v9,
      "ipa %s:%d tbl_index(%d) table_entries(%u)\n",
      "ipa3_nat_init_cmd",
      1435,
      *a1,
      *((unsigned __int16 *)a1 + 10));
LABEL_14:
  v10 = *a1;
  v76 = 0;
  v77 = 0;
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  if ( v10 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_nat_init_cmd__rs, "ipa3_nat_init_cmd") )
    {
      printk(&unk_3F2550, "ipa3_nat_init_cmd");
      v11 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_17:
        v12 = *(_QWORD *)(v11 + 34152);
        if ( v12 )
        {
          ipc_log_string(v12, "ipa %s:%d Unsupported table index %d\n", "ipa3_nat_init_cmd", 1441, *a1);
          v11 = ipa3_ctx;
        }
        v13 = *(_QWORD *)(v11 + 34160);
        if ( v13 )
        {
          ipc_log_string(v13, "ipa %s:%d Unsupported table index %d\n", "ipa3_nat_init_cmd", 1441, *a1);
LABEL_29:
          v16 = -1;
LABEL_30:
          v11 = ipa3_ctx;
          goto LABEL_72;
        }
        goto LABEL_71;
      }
    }
    else
    {
      v11 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_17;
    }
LABEL_78:
    v16 = -1;
    goto LABEL_79;
  }
  if ( *((unsigned __int16 *)a1 + 10) == 0xFFFF || !*((_WORD *)a1 + 10) )
  {
    if ( (unsigned int)__ratelimit(&ipa3_nat_init_cmd__rs_24, "ipa3_nat_init_cmd") )
    {
      printk(&unk_3F2578, "ipa3_nat_init_cmd");
      v11 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_78;
    }
    else
    {
      v11 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_78;
    }
    v14 = *(_QWORD *)(v11 + 34152);
    if ( v14 )
    {
      ipc_log_string(v14, "ipa %s:%d Table entries is %d\n", "ipa3_nat_init_cmd", 1448, *((unsigned __int16 *)a1 + 10));
      v11 = ipa3_ctx;
    }
    v15 = *(_QWORD *)(v11 + 34160);
    if ( v15 )
    {
      ipc_log_string(v15, "ipa %s:%d Table entries is %d\n", "ipa3_nat_init_cmd", 1448, *((unsigned __int16 *)a1 + 10));
      goto LABEL_29;
    }
    goto LABEL_71;
  }
  if ( v6 >= 2 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_nat_init_cmd__rs_27, "ipa3_nat_init_cmd") )
    {
      printk(&unk_3A3A99, "ipa3_nat_init_cmd");
      v11 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_78;
    }
    else
    {
      v11 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_78;
    }
    v27 = *(_QWORD *)(v11 + 34152);
    if ( v27 )
    {
      ipc_log_string(v27, "ipa %s:%d Bad ipa3_nat_mem_in type\n", "ipa3_nat_init_cmd", 1454);
      v11 = ipa3_ctx;
    }
    v28 = *(_QWORD *)(v11 + 34160);
    if ( v28 )
    {
      ipc_log_string(v28, "ipa %s:%d Bad ipa3_nat_mem_in type\n", "ipa3_nat_init_cmd", 1454);
      goto LABEL_29;
    }
LABEL_71:
    v16 = -1;
    goto LABEL_72;
  }
  v17 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v18 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v18 )
    {
      if ( v6 == 1 )
        v19 = "IPA_NAT_MEM_IN_SRAM";
      else
        v19 = "INVALID_MEM_TYPE";
      if ( v6 )
        v20 = v19;
      else
        v20 = "IPA_NAT_MEM_IN_DDR";
      ipc_log_string(v18, "ipa %s:%d nmi(%s)\n", "ipa3_nat_init_cmd", 1459, v20);
      v17 = ipa3_ctx;
    }
    v21 = *(_QWORD *)(v17 + 34160);
    if ( v21 )
    {
      if ( v6 == 1 )
        v22 = "IPA_NAT_MEM_IN_SRAM";
      else
        v22 = "INVALID_MEM_TYPE";
      if ( v6 )
        v23 = v22;
      else
        v23 = "IPA_NAT_MEM_IN_DDR";
      ipc_log_string(v21, "ipa %s:%d nmi(%s)\n", "ipa3_nat_init_cmd", 1459, v23);
    }
  }
  if ( (*(_BYTE *)(v2 + 96LL * v6 + 29888) & 1) == 0 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_nat_init_cmd__rs_31, "ipa3_nat_init_cmd") )
    {
      printk(&unk_3D8925, "ipa3_nat_init_cmd");
      v11 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_78;
    }
    else
    {
      v11 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_78;
    }
    v29 = *(_QWORD *)(v11 + 34152);
    if ( v29 )
    {
      ipc_log_string(
        v29,
        "ipa %s:%d Attempt to init %s before mmap\n",
        "ipa3_nat_init_cmd",
        1464,
        (const char *)(v2 + 29528));
      v11 = ipa3_ctx;
    }
    v30 = *(_QWORD *)(v11 + 34160);
    if ( v30 )
    {
      ipc_log_string(
        v30,
        "ipa %s:%d Attempt to init %s before mmap\n",
        "ipa3_nat_init_cmd",
        1464,
        (const char *)(v2 + 29528));
      goto LABEL_29;
    }
    goto LABEL_71;
  }
  v24 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD))ipa3_nat_ipv6ct_check_table_params)(
          v2 + 29528,
          v6,
          *((unsigned int *)a1 + 1),
          (unsigned int)*((unsigned __int16 *)a1 + 10) + 1,
          0);
  if ( !v24 )
  {
    v34 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD))ipa3_nat_ipv6ct_check_table_params)(
            v2 + 29528,
            v6,
            *((unsigned int *)a1 + 2),
            *((unsigned __int16 *)a1 + 11),
            0);
    if ( v34 )
    {
      v16 = v34;
      if ( (unsigned int)__ratelimit(&ipa3_nat_init_cmd__rs_37, "ipa3_nat_init_cmd") )
      {
        printk(&unk_3FE254, "ipa3_nat_init_cmd");
        v11 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_79;
      }
      else
      {
        v11 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_79;
      }
      v35 = *(_QWORD *)(v11 + 34152);
      if ( v35 )
      {
        ipc_log_string(v35, "ipa %s:%d Bad params for NAT expansion table\n", "ipa3_nat_init_cmd", 1487);
        v11 = ipa3_ctx;
      }
      v36 = *(_QWORD *)(v11 + 34160);
      if ( !v36 )
        goto LABEL_72;
      ipc_log_string(v36, "ipa %s:%d Bad params for NAT expansion table\n", "ipa3_nat_init_cmd", 1487);
      goto LABEL_30;
    }
    v37 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, __int64))ipa3_nat_ipv6ct_check_table_params)(
            v2 + 29528,
            v6,
            *((unsigned int *)a1 + 3),
            (unsigned int)*((unsigned __int16 *)a1 + 10) + 1,
            1);
    if ( v37 )
    {
      v16 = v37;
      if ( (unsigned int)__ratelimit(&ipa3_nat_init_cmd__rs_40, "ipa3_nat_init_cmd") )
      {
        printk(&unk_3DE725, "ipa3_nat_init_cmd");
        v11 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_79;
      }
      else
      {
        v11 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_79;
      }
      v38 = *(_QWORD *)(v11 + 34152);
      if ( v38 )
      {
        ipc_log_string(v38, "ipa %s:%d Bad params for index table\n", "ipa3_nat_init_cmd", 1498);
        v11 = ipa3_ctx;
      }
      v39 = *(_QWORD *)(v11 + 34160);
      if ( !v39 )
        goto LABEL_72;
      ipc_log_string(v39, "ipa %s:%d Bad params for index table\n", "ipa3_nat_init_cmd", 1498);
      goto LABEL_30;
    }
    v40 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, __int64))ipa3_nat_ipv6ct_check_table_params)(
            v2 + 29528,
            v6,
            *((unsigned int *)a1 + 4),
            *((unsigned __int16 *)a1 + 11),
            1);
    if ( v40 )
    {
      v16 = v40;
      if ( (unsigned int)__ratelimit(&ipa3_nat_init_cmd__rs_43, "ipa3_nat_init_cmd") )
      {
        printk(&unk_3F2599, "ipa3_nat_init_cmd");
        v11 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_79;
      }
      else
      {
        v11 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_79;
      }
      v41 = *(_QWORD *)(v11 + 34152);
      if ( v41 )
      {
        ipc_log_string(v41, "ipa %s:%d Bad params for index expansion table\n", "ipa3_nat_init_cmd", 1509);
        v11 = ipa3_ctx;
      }
      v42 = *(_QWORD *)(v11 + 34160);
      if ( !v42 )
        goto LABEL_72;
      ipc_log_string(v42, "ipa %s:%d Bad params for index expansion table\n", "ipa3_nat_init_cmd", 1509);
      goto LABEL_30;
    }
    v43 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v44 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v44 )
      {
        v45 = "INVALID_MEM_TYPE";
        if ( v6 == 1 )
          v45 = "IPA_NAT_MEM_IN_SRAM";
        if ( v6 )
          v46 = v45;
        else
          v46 = "IPA_NAT_MEM_IN_DDR";
        ipc_log_string(v44, "ipa %s:%d Table memory becoming active: %s\n", "ipa3_nat_init_cmd", 1514, v46);
        v43 = ipa3_ctx;
      }
      v47 = *(_QWORD *)(v43 + 34160);
      if ( v47 )
      {
        v48 = "INVALID_MEM_TYPE";
        if ( v6 == 1 )
          v48 = "IPA_NAT_MEM_IN_SRAM";
        if ( v6 )
          v49 = v48;
        else
          v49 = "IPA_NAT_MEM_IN_DDR";
        ipc_log_string(v47, "ipa %s:%d Table memory becoming active: %s\n", "ipa3_nat_init_cmd", 1514, v49);
      }
    }
    if ( v6 )
    {
      v50 = a1;
      v51 = 1;
      v52 = *(unsigned int *)(**(_QWORD **)(ipa3_ctx + 34176) + 180LL);
    }
    else
    {
      v52 = *(_QWORD *)(v2 + 29912);
      v50 = a1;
      v51 = 0;
    }
    ipa3_nat_create_init_cmd(v50, v51, v52, &v72);
    v53 = ipa3_ctx;
    if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0xEu && *(_QWORD *)(v2 + 29840) && !a1[29] )
    {
      v54 = *((_DWORD *)a1 + 6);
      v71 = 0;
      v70 = v54;
      v55 = ipahal_nat_construct_entry(2, &v70);
      if ( v55 )
      {
        v16 = v55;
        printk(&unk_3CFE43, "ipa3_nat_init_cmd");
        v67 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v68 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v68 )
          {
            ipc_log_string(v68, "ipa %s:%d Fail to construct NAT pdn entry\n", "ipa3_nat_init_cmd", 1549);
            v67 = ipa3_ctx;
          }
          v69 = *(_QWORD *)(v67 + 34160);
          if ( v69 )
            ipc_log_string(v69, "ipa %s:%d Fail to construct NAT pdn entry\n", "ipa3_nat_init_cmd", 1549);
        }
        goto LABEL_30;
      }
      v53 = ipa3_ctx;
    }
    if ( v53 )
    {
      v56 = *(_QWORD *)(v53 + 34152);
      if ( v56 )
      {
        ipc_log_string(v56, "ipa %s:%d Posting NAT init command\n", "ipa3_nat_init_cmd", 1554);
        v53 = ipa3_ctx;
      }
      v57 = *(_QWORD *)(v53 + 34160);
      if ( v57 )
        ipc_log_string(v57, "ipa %s:%d Posting NAT init command\n", "ipa3_nat_init_cmd", 1554);
    }
    inited = ipa3_nat_send_init_cmd(&v72, 0);
    if ( inited )
    {
      v16 = inited;
      printk(&unk_3EC67A, "ipa3_nat_init_cmd");
      v11 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_79;
      v63 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v63 )
      {
        ipc_log_string(v63, "ipa %s:%d Fail to send NAT init immediate command\n", "ipa3_nat_init_cmd", 1559);
        v11 = ipa3_ctx;
      }
      v64 = *(_QWORD *)(v11 + 34160);
      if ( !v64 )
        goto LABEL_72;
      ipc_log_string(v64, "ipa %s:%d Fail to send NAT init immediate command\n", "ipa3_nat_init_cmd", 1559);
    }
    else
    {
      v59 = ipa3_nat_ipv6ct_init_device_structure(
              v2 + 29528,
              v6,
              *((unsigned int *)a1 + 1),
              *((unsigned int *)a1 + 2),
              *((unsigned __int16 *)a1 + 10),
              *((unsigned __int16 *)a1 + 11),
              *((unsigned int *)a1 + 3),
              *((unsigned int *)a1 + 4),
              a1[29]);
      if ( v59 )
      {
        v16 = v59;
        printk(&unk_3BE35D, "ipa3_nat_init_cmd");
        v11 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_79;
        v65 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v65 )
        {
          ipc_log_string(v65, "ipa %s:%d Table offset initialization failure\n", "ipa3_nat_init_cmd", 1574);
          v11 = ipa3_ctx;
        }
        v66 = *(_QWORD *)(v11 + 34160);
        if ( !v66 )
          goto LABEL_72;
        ipc_log_string(v66, "ipa %s:%d Table offset initialization failure\n", "ipa3_nat_init_cmd", 1574);
      }
      else
      {
        *(_DWORD *)(v2 + 29832) = *((_DWORD *)a1 + 6);
        v60 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v61 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v61 )
          {
            ipc_log_string(
              v61,
              "ipa %s:%d Public IP address:%pI4h\n",
              "ipa3_nat_init_cmd",
              1580,
              (const void *)(v2 + 29832));
            v60 = ipa3_ctx;
          }
          v62 = *(_QWORD *)(v60 + 34160);
          if ( v62 )
            ipc_log_string(
              v62,
              "ipa %s:%d Public IP address:%pI4h\n",
              "ipa3_nat_init_cmd",
              1580,
              (const void *)(v2 + 29832));
        }
        v16 = 0;
        *(_BYTE *)(v2 + 29751) = 1;
      }
    }
    goto LABEL_30;
  }
  v16 = v24;
  if ( (unsigned int)__ratelimit(&ipa3_nat_init_cmd__rs_34, "ipa3_nat_init_cmd") )
  {
    printk(&unk_3A3ABF, "ipa3_nat_init_cmd");
    v11 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_79;
  }
  else
  {
    v11 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_79;
  }
  v25 = *(_QWORD *)(v11 + 34152);
  if ( v25 )
  {
    ipc_log_string(v25, "ipa %s:%d Bad params for NAT base table\n", "ipa3_nat_init_cmd", 1476);
    v11 = ipa3_ctx;
  }
  v26 = *(_QWORD *)(v11 + 34160);
  if ( v26 )
  {
    ipc_log_string(v26, "ipa %s:%d Bad params for NAT base table\n", "ipa3_nat_init_cmd", 1476);
    goto LABEL_30;
  }
LABEL_72:
  if ( v11 )
  {
    v31 = *(_QWORD *)(v11 + 34152);
    if ( v31 )
    {
      ipc_log_string(v31, "ipa %s:%d Out\n", "ipa3_nat_init_cmd", 1585);
      v11 = ipa3_ctx;
    }
    v32 = *(_QWORD *)(v11 + 34160);
    if ( v32 )
      ipc_log_string(v32, "ipa %s:%d Out\n", "ipa3_nat_init_cmd", 1585);
  }
LABEL_79:
  _ReadStatusReg(SP_EL0);
  return v16;
}
