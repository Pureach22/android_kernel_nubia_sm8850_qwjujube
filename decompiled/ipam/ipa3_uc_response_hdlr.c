__int64 __fastcall ipa3_uc_response_hdlr(__int64 a1, __int64 a2)
{
  __int64 v2; // x2
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  unsigned __int64 v7; // x3
  unsigned __int64 v8; // x19
  __int64 (__fastcall *v9)(__int64, __int64, __int64, unsigned __int64); // x9
  int v10; // w0
  __int64 v11; // x0
  __int64 v12; // x0
  int v13; // w24
  __int64 v14; // x0
  __int64 v15; // x0
  unsigned int v16; // w19
  int v17; // w20
  __int64 v18; // x2
  __int64 v19; // x0
  int v20; // w19
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x2
  int v25; // w9
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x0
  unsigned __int64 v29; // x0
  __int64 (__fastcall *v30)(unsigned __int64); // x8
  __int64 (__fastcall *v31)(unsigned __int64); // x8
  __int64 (__fastcall *v32)(unsigned __int64); // x8
  __int64 (__fastcall *v33)(unsigned __int64); // x8
  __int64 (__fastcall *v34)(unsigned __int64); // x8
  __int64 (__fastcall *v35)(unsigned __int64); // x8
  __int64 (__fastcall *v36)(unsigned __int64); // x8
  void (__fastcall *v37)(unsigned __int64); // x8
  __int64 v38; // x8
  __int64 v39; // x8
  __int64 v40; // x8
  __int64 v41; // x8
  __int64 v42; // x8
  __int64 v43; // x8
  __int64 result; // x0
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x8
  __int64 v48; // x0
  __int64 v49; // x8
  __int64 v50; // x0
  __int64 v51; // x8
  __int64 v52; // x0
  __int64 v53; // x8
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x20
  __int64 v57; // x9

  _ReadStatusReg(SP_EL0);
  if ( ipa3_ctx != a2 )
    __break(0x800u);
  ipa3_inc_client_enable_clks();
  v3 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v4 )
    {
      ipc_log_string(
        v4,
        "ipa %s:%d uC rsp opcode=%u\n",
        "ipa3_uc_response_hdlr",
        845,
        *(unsigned __int8 *)(*(_QWORD *)(ipa3_ctx + 34752) + 12LL));
      v3 = ipa3_ctx;
    }
    v5 = *(_QWORD *)(v3 + 34160);
    if ( v5 )
    {
      ipc_log_string(
        v5,
        "ipa %s:%d uC rsp opcode=%u\n",
        "ipa3_uc_response_hdlr",
        845,
        *(unsigned __int8 *)(*(_QWORD *)(v3 + 34752) + 12LL));
      v3 = ipa3_ctx;
    }
  }
  v6 = *(_QWORD *)(v3 + 34752);
  v7 = *(unsigned __int8 *)(v6 + 12);
  v8 = v7 >> 5;
  v9 = (__int64 (__fastcall *)(__int64, __int64, __int64, unsigned __int64))*(&ipa3_uc_hdlrs
                                                                            + 5 * (unsigned int)(v7 >> 5)
                                                                            + 2);
  if ( v9 )
  {
    if ( *((_DWORD *)v9 - 1) != 937835395 )
      __break(0x8229u);
    v10 = v9(v6, v3 + 34776, v2, v7);
    v3 = ipa3_ctx;
    if ( !v10 )
    {
      if ( ipa3_ctx )
      {
        v22 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v22 )
        {
          ipc_log_string(v22, "ipa %s:%d feature %d specific response handler\n", "ipa3_uc_response_hdlr", 863, v8);
          v3 = ipa3_ctx;
        }
        v23 = *(_QWORD *)(v3 + 34160);
        if ( v23 )
        {
          ipc_log_string(v23, "ipa %s:%d feature %d specific response handler\n", "ipa3_uc_response_hdlr", 863, v8);
          v3 = ipa3_ctx;
        }
      }
      complete_all(v3 + 34720);
      goto LABEL_102;
    }
    v6 = *(_QWORD *)(ipa3_ctx + 34752);
    LODWORD(v7) = *(unsigned __int8 *)(v6 + 12);
  }
  if ( (_DWORD)v7 != 2 )
  {
    if ( (_DWORD)v7 == 1 )
    {
      if ( *(_BYTE *)(v3 + 34657) == 1 )
      {
        if ( v3 )
        {
          v11 = *(_QWORD *)(v3 + 34152);
          if ( v11 )
          {
            ipc_log_string(v11, "ipa %s:%d uC resp op INIT_COMPLETED is unexpected\n", "ipa3_uc_response_hdlr", 875);
            v3 = ipa3_ctx;
          }
          v12 = *(_QWORD *)(v3 + 34160);
          if ( v12 )
            ipc_log_string(v12, "ipa %s:%d uC resp op INIT_COMPLETED is unexpected\n", "ipa3_uc_response_hdlr", 875);
        }
      }
      else
      {
        mutex_lock(&uc_loaded_nb_lock);
        v24 = ipa3_ctx;
        v25 = *(unsigned __int8 *)(ipa3_ctx + 34904);
        *(_BYTE *)(ipa3_ctx + 34657) = 1;
        if ( v25 == 1 )
        {
          queue_work_on(32, ipa_uc_holb_wq, &ipa3_holb_enabled_work);
          v24 = ipa3_ctx;
        }
        blocking_notifier_call_chain(&uc_loaded_notifier, 1, v24);
        v26 = mutex_unlock(&uc_loaded_nb_lock);
        v27 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v28 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v28 )
          {
            ipc_log_string(v28, "ipa %s:%d IPA uC loaded\n", "ipa3_uc_response_hdlr", 892);
            v27 = ipa3_ctx;
          }
          v26 = *(_QWORD *)(v27 + 34160);
          if ( v26 )
            v26 = ipc_log_string(v26, "ipa %s:%d IPA uC loaded\n", "ipa3_uc_response_hdlr", 892);
        }
        ipa3_proxy_clk_unvote(v26);
        v29 = ipa_pc_qmp_enable();
        v30 = (__int64 (__fastcall *)(unsigned __int64))ipa3_uc_hdlrs;
        if ( ipa3_uc_hdlrs )
        {
          if ( *((_DWORD *)ipa3_uc_hdlrs - 1) != -440107680 )
            __break(0x8228u);
          v29 = v30(v29);
        }
        v31 = (__int64 (__fastcall *)(unsigned __int64))off_2014D8;
        if ( off_2014D8 )
        {
          if ( *((_DWORD *)off_2014D8 - 1) != -440107680 )
            __break(0x8228u);
          v29 = v31(v29);
        }
        v32 = (__int64 (__fastcall *)(unsigned __int64))off_201500;
        if ( off_201500 )
        {
          if ( *((_DWORD *)off_201500 - 1) != -440107680 )
            __break(0x8228u);
          v29 = v32(v29);
        }
        v33 = (__int64 (__fastcall *)(unsigned __int64))off_201528;
        if ( off_201528 )
        {
          if ( *((_DWORD *)off_201528 - 1) != -440107680 )
            __break(0x8228u);
          v29 = v33(v29);
        }
        v34 = (__int64 (__fastcall *)(unsigned __int64))off_201550;
        if ( off_201550 )
        {
          if ( *((_DWORD *)off_201550 - 1) != -440107680 )
            __break(0x8228u);
          v29 = v34(v29);
        }
        v35 = (__int64 (__fastcall *)(unsigned __int64))off_201578;
        if ( off_201578 )
        {
          if ( *((_DWORD *)off_201578 - 1) != -440107680 )
            __break(0x8228u);
          v29 = v35(v29);
        }
        v36 = (__int64 (__fastcall *)(unsigned __int64))off_2015A0;
        if ( off_2015A0 )
        {
          if ( *((_DWORD *)off_2015A0 - 1) != -440107680 )
            __break(0x8228u);
          v29 = v36(v29);
        }
        v37 = (void (__fastcall *)(unsigned __int64))off_2015C8;
        if ( off_2015C8 )
        {
          if ( *((_DWORD *)off_2015C8 - 1) != -440107680 )
            __break(0x8228u);
          v37(v29);
        }
      }
    }
    else
    {
      printk(&unk_3C4A5F, "ipa3_uc_response_hdlr");
      v45 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v46 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v46 )
        {
          ipc_log_string(
            v46,
            "ipa %s:%d Unsupported uC rsp opcode = %u\n",
            "ipa3_uc_response_hdlr",
            931,
            *(unsigned __int8 *)(*(_QWORD *)(ipa3_ctx + 34752) + 12LL));
          v45 = ipa3_ctx;
        }
        v47 = v45 + 0x8000;
        v48 = *(_QWORD *)(v47 + 1392);
        if ( v48 )
          ipc_log_string(
            v48,
            "ipa %s:%d Unsupported uC rsp opcode = %u\n",
            "ipa3_uc_response_hdlr",
            931,
            *(unsigned __int8 *)(*(_QWORD *)(v47 + 1984) + 12LL));
      }
    }
    goto LABEL_102;
  }
  v13 = *(_DWORD *)(v6 + 16);
  if ( v3 )
  {
    v14 = *(_QWORD *)(v3 + 34152);
    if ( v14 )
    {
      ipc_log_string(
        v14,
        "ipa %s:%d uC cmd response opcode=%u status=%u\n",
        "ipa3_uc_response_hdlr",
        915,
        (unsigned __int8)v13,
        BYTE1(v13));
      v3 = ipa3_ctx;
    }
    v15 = *(_QWORD *)(v3 + 34160);
    if ( v15 )
    {
      ipc_log_string(
        v15,
        "ipa %s:%d uC cmd response opcode=%u status=%u\n",
        "ipa3_uc_response_hdlr",
        915,
        (unsigned __int8)v13,
        BYTE1(v13));
      v3 = ipa3_ctx;
    }
  }
  if ( (unsigned __int8)v13 == *(_DWORD *)(v3 + 34772) )
  {
    *(_DWORD *)(v3 + 34776) = BYTE1(v13);
    if ( (unsigned __int8)v13 != 197 )
    {
LABEL_101:
      complete_all(ipa3_ctx + 34720);
      goto LABEL_102;
    }
    v16 = *(_DWORD *)(*(_QWORD *)(v3 + 34752) + 40LL);
    v17 = v16 & 0xFFFFFF;
    if ( arm64_use_ng_mappings )
      v18 = 0x68000000000F13LL;
    else
      v18 = 0x68000000000713LL;
    v19 = ioremap_prot(*(_DWORD *)(v3 + 28640) + (v16 & 0xFFFFFF), 100, v18);
    if ( !v19 )
    {
      printk(&unk_3F89B4, "ipa3_uc_save_dbg_stats");
      v53 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v54 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v54 )
        {
          ipc_log_string(v54, "ipa %s:%d unexpected NULL mmio\n", "ipa3_uc_save_dbg_stats", 422);
          v53 = ipa3_ctx;
        }
        v55 = *(_QWORD *)(v53 + 34160);
        if ( v55 )
          ipc_log_string(v55, "ipa %s:%d unexpected NULL mmio\n", "ipa3_uc_save_dbg_stats", 422);
      }
      goto LABEL_101;
    }
    v20 = HIBYTE(v16);
    if ( v20 <= 5 )
    {
      switch ( v20 )
      {
        case 1:
          v43 = ipa3_ctx + 45056;
          if ( !*(_QWORD *)(ipa3_ctx + 45080) )
          {
            *(_DWORD *)(ipa3_ctx + 45072) = v17;
            *(_QWORD *)(v43 + 24) = v19;
            *(_WORD *)(v43 + 20) = HIWORD(v13);
            goto LABEL_101;
          }
          goto LABEL_100;
        case 3:
          v42 = ipa3_ctx + 40960;
          if ( !*(_QWORD *)(ipa3_ctx + 44952) )
          {
            *(_DWORD *)(ipa3_ctx + 44944) = v17;
            *(_QWORD *)(v42 + 3992) = v19;
            *(_WORD *)(v42 + 3988) = HIWORD(v13);
            goto LABEL_101;
          }
          goto LABEL_100;
        case 4:
          v38 = ipa3_ctx + 40960;
          if ( !*(_QWORD *)(ipa3_ctx + 45032) )
          {
            *(_DWORD *)(ipa3_ctx + 45024) = v17;
            *(_QWORD *)(v38 + 4072) = v19;
            *(_WORD *)(v38 + 4068) = HIWORD(v13);
            goto LABEL_101;
          }
          goto LABEL_100;
      }
    }
    else if ( v20 > 8 )
    {
      if ( v20 == 9 )
      {
        v41 = ipa3_ctx + 45056;
        if ( !*(_QWORD *)(ipa3_ctx + 45096) )
        {
          *(_DWORD *)(ipa3_ctx + 45088) = v17;
          *(_QWORD *)(v41 + 40) = v19;
          *(_WORD *)(v41 + 36) = HIWORD(v13);
          goto LABEL_101;
        }
        goto LABEL_100;
      }
      if ( v20 == 10 )
      {
        v39 = ipa3_ctx + 45056;
        if ( !*(_QWORD *)(ipa3_ctx + 45112) )
        {
          *(_DWORD *)(ipa3_ctx + 45104) = v17;
          *(_QWORD *)(v39 + 56) = v19;
          *(_WORD *)(v39 + 52) = HIWORD(v13);
          goto LABEL_101;
        }
        goto LABEL_100;
      }
    }
    else
    {
      if ( v20 == 6 )
      {
        v40 = ipa3_ctx + 45056;
        if ( !*(_QWORD *)(ipa3_ctx + 45064) )
        {
          *(_DWORD *)v40 = v17;
          *(_QWORD *)(v40 + 8) = v19;
          *(_WORD *)(v40 + 4) = HIWORD(v13);
          goto LABEL_101;
        }
        goto LABEL_100;
      }
      if ( v20 == 7 )
      {
        v21 = ipa3_ctx + 40960;
        if ( !*(_QWORD *)(ipa3_ctx + 45048) )
        {
          *(_DWORD *)(ipa3_ctx + 45040) = v17;
          *(_QWORD *)(v21 + 4088) = v19;
          *(_WORD *)(v21 + 4084) = HIWORD(v13);
          goto LABEL_101;
        }
LABEL_100:
        iounmap(v19);
        goto LABEL_101;
      }
    }
    v56 = v19;
    printk(&unk_3E6E2A, "ipa3_uc_save_dbg_stats");
    v57 = ipa3_ctx;
    v19 = v56;
    if ( ipa3_ctx )
    {
      if ( *(_QWORD *)(ipa3_ctx + 34152) )
      {
        ipc_log_string(
          *(_QWORD *)(ipa3_ctx + 34152),
          "ipa %s:%d unknown protocols %d\n",
          "ipa3_uc_save_dbg_stats",
          504,
          v20);
        v57 = ipa3_ctx;
        v19 = v56;
      }
      if ( *(_QWORD *)(v57 + 34160) )
      {
        ipc_log_string(*(_QWORD *)(v57 + 34160), "ipa %s:%d unknown protocols %d\n", "ipa3_uc_save_dbg_stats", 504, v20);
        v19 = v56;
      }
    }
    goto LABEL_100;
  }
  printk(&unk_3A42B5, "ipa3_uc_response_hdlr");
  v49 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v50 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v50 )
    {
      ipc_log_string(
        v50,
        "ipa %s:%d Expected cmd=%u rcvd cmd=%u\n",
        "ipa3_uc_response_hdlr",
        927,
        *(_DWORD *)(ipa3_ctx + 34772),
        (unsigned __int8)v13);
      v49 = ipa3_ctx;
    }
    v51 = v49 + 0x8000;
    v52 = *(_QWORD *)(v51 + 1392);
    if ( v52 )
      ipc_log_string(
        v52,
        "ipa %s:%d Expected cmd=%u rcvd cmd=%u\n",
        "ipa3_uc_response_hdlr",
        927,
        *(_DWORD *)(v51 + 2004),
        (unsigned __int8)v13);
  }
LABEL_102:
  result = ipa3_dec_client_disable_clks();
  _ReadStatusReg(SP_EL0);
  return result;
}
