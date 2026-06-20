__int64 __fastcall ipa3_cfg_ep_aggr(unsigned int a1, unsigned int *a2)
{
  __int64 v3; // x8
  unsigned int v4; // w22
  __int64 v6; // x5
  __int64 v7; // x0
  const char *v8; // x6
  __int64 v9; // x7
  const char *v10; // x8
  __int64 v11; // x0
  __int64 v12; // x5
  const char *v13; // x6
  __int64 v14; // x7
  const char *v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x10
  __int64 v19; // x12
  __int64 v20; // x8
  __int64 v21; // x11
  unsigned int v22; // w3
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  unsigned __int64 v26; // t2
  unsigned int v27; // w20
  __int64 v29; // x8
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x8
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x8
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x8
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x8
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x8
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x8
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x8
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x8
  __int64 v54; // x0
  __int64 v55; // x0

  _ReadStatusReg(SP_EL0);
  v3 = ipa3_ctx;
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
  {
    if ( a1 <= 0x23 )
    {
      v4 = a1;
LABEL_50:
      printk(&unk_3E4584, "ipa3_cfg_ep_aggr");
      v29 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_55;
      v30 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v30 )
      {
        ipc_log_string(
          v30,
          "ipa %s:%d bad parm, clnt_hdl = %d , ep_valid = %d\n",
          "ipa3_cfg_ep_aggr",
          9626,
          a1,
          *(_DWORD *)(ipa3_ctx + 480LL * v4 + 168));
        v29 = ipa3_ctx;
      }
      v31 = *(_QWORD *)(v29 + 34160);
      if ( v31 )
      {
        ipc_log_string(
          v31,
          "ipa %s:%d bad parm, clnt_hdl = %d , ep_valid = %d\n",
          "ipa3_cfg_ep_aggr",
          9626,
          a1,
          *(_DWORD *)(v29 + 480LL * v4 + 168));
        v27 = -22;
      }
      else
      {
LABEL_55:
        v27 = -22;
      }
      goto LABEL_47;
    }
LABEL_104:
    __break(0x5512u);
  }
  if ( a1 >= 0x24 )
    goto LABEL_104;
  v4 = a1;
  if ( !a2 || !*(_DWORD *)(ipa3_ctx + 480LL * a1 + 168) )
    goto LABEL_50;
  v6 = *a2;
  if ( a1 < 4 || (_DWORD)v6 != 2 )
  {
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        if ( (unsigned int)v6 > 2 )
          v8 = "undefined";
        else
          v8 = off_1E4170[v6];
        v9 = a2[1];
        if ( (unsigned int)v9 > 6 )
          v10 = "undefined";
        else
          v10 = off_1E4188[v9];
        ipc_log_string(
          v7,
          "ipa %s:%d pipe=%d en=%d(%s), type=%d(%s), byte_limit=%d, time_limit=%d\n",
          "ipa3_cfg_ep_aggr",
          9644,
          a1,
          v6,
          v8,
          v9,
          v10,
          a2[2],
          a2[3]);
        v3 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v3 + 34160);
      if ( v11 )
      {
        v12 = *a2;
        if ( (unsigned int)v12 > 2 )
          v13 = "undefined";
        else
          v13 = off_1E4170[v12];
        v14 = a2[1];
        if ( (unsigned int)v14 > 6 )
          v15 = "undefined";
        else
          v15 = off_1E4188[v14];
        ipc_log_string(
          v11,
          "ipa %s:%d pipe=%d en=%d(%s), type=%d(%s), byte_limit=%d, time_limit=%d\n",
          "ipa3_cfg_ep_aggr",
          9644,
          a1,
          v12,
          v13,
          v14,
          v15,
          a2[2],
          a2[3]);
        v3 = ipa3_ctx;
      }
      if ( v3 )
      {
        v16 = *(_QWORD *)(v3 + 34152);
        if ( v16 )
        {
          ipc_log_string(
            v16,
            "ipa %s:%d hard_byte_limit_en=%d aggr_sw_eof_active=%d\n",
            "ipa3_cfg_ep_aggr",
            9647,
            a2[5],
            *((unsigned __int8 *)a2 + 24));
          v3 = ipa3_ctx;
        }
        v17 = *(_QWORD *)(v3 + 34160);
        if ( v17 )
        {
          ipc_log_string(
            v17,
            "ipa %s:%d hard_byte_limit_en=%d aggr_sw_eof_active=%d\n",
            "ipa3_cfg_ep_aggr",
            9647,
            a2[5],
            *((unsigned __int8 *)a2 + 24));
          v3 = ipa3_ctx;
        }
      }
    }
    v19 = *((_QWORD *)a2 + 1);
    v18 = *((_QWORD *)a2 + 2);
    v20 = v3 + 480LL * a1;
    v21 = *(_QWORD *)a2;
    *(_DWORD *)(v20 + 432) = a2[6];
    *(_QWORD *)(v20 + 416) = v19;
    *(_QWORD *)(v20 + 424) = v18;
    *(_QWORD *)(v20 + 408) = v21;
    if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
    {
      printk(&unk_3E7136, "ipa3_get_client_mapping");
      v35 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v36 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v36 )
        {
          ipc_log_string(v36, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
          v35 = ipa3_ctx;
        }
        v37 = *(_QWORD *)(v35 + 34160);
        if ( v37 )
          ipc_log_string(v37, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
      }
      __break(0x800u);
      if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
      {
        printk(&unk_3E7136, "ipa3_get_client_mapping");
        v38 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v39 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v39 )
          {
            ipc_log_string(v39, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
            v38 = ipa3_ctx;
          }
          v40 = *(_QWORD *)(v38 + 34160);
          if ( v40 )
            ipc_log_string(v40, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
        }
        __break(0x800u);
      }
    }
    ipa3_inc_client_enable_clks();
    v22 = a2[3];
    if ( *(_DWORD *)(ipa3_ctx + 32240) < 0x11u )
    {
      HIDWORD(v26) = 652835029 * v22;
      LODWORD(v26) = 652835029 * v22;
      if ( (unsigned int)(v26 >> 2) >= 0x83126F )
      {
        printk(&unk_3BBDBE, "ipa3_cfg_ep_aggr");
        v50 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v51 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v51 )
          {
            ipc_log_string(v51, "ipa %s:%d given time limit %u is not in 0.5msec\n", "ipa3_cfg_ep_aggr", 9688, a2[3]);
            v50 = ipa3_ctx;
          }
          v52 = *(_QWORD *)(v50 + 34160);
          if ( v52 )
            ipc_log_string(v52, "ipa %s:%d given time limit %u is not in 0.5msec\n", "ipa3_cfg_ep_aggr", 9688, a2[3]);
        }
        __break(0x800u);
        v27 = -22;
        goto LABEL_45;
      }
      *(_DWORD *)(ipa3_ctx + 480LL * a1 + 420) *= 2;
    }
    else
    {
      if ( (unsigned int)ipa3_process_timer_cfg(v22, ipa3_ctx + 480LL * a1 + 433, ipa3_ctx + 480LL * a1 + 434) )
      {
        printk(&unk_3E71CE, "ipa3_cfg_ep_aggr");
        v47 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_97;
        v48 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v48 )
        {
          ipc_log_string(v48, "ipa %s:%d failed to process AGGR timer tmr=%u\n", "ipa3_cfg_ep_aggr", 9660, a2[3]);
          v47 = ipa3_ctx;
        }
        v49 = *(_QWORD *)(v47 + 34160);
        if ( v49 )
        {
          ipc_log_string(v49, "ipa %s:%d failed to process AGGR timer tmr=%u\n", "ipa3_cfg_ep_aggr", 9660, a2[3]);
          v27 = -22;
        }
        else
        {
LABEL_97:
          v27 = -22;
        }
        goto LABEL_45;
      }
      if ( *(_DWORD *)(ipa3_ctx + 32240) == 17 )
      {
        if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
        {
          printk(&unk_3E7136, "ipa3_get_client_mapping");
          v53 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v54 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v54 )
            {
              ipc_log_string(v54, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
              v53 = ipa3_ctx;
            }
            v55 = *(_QWORD *)(v53 + 34160);
            if ( v55 )
              ipc_log_string(v55, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
          }
          __break(0x800u);
        }
        else if ( *(_DWORD *)(ipa3_ctx + 168 + 480LL * a1 + 4) == 95 && *(_BYTE *)(ipa3_ctx + 168 + 480LL * a1 + 265) )
        {
          v23 = printk(&unk_3DF089, "ipa3_cfg_ep_aggr");
          v24 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v25 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v25 )
            {
              ipc_log_string(
                v25,
                "ipa %s:%d coal pipe using GRAN_SEL = %d\n",
                "ipa3_cfg_ep_aggr",
                9676,
                *(unsigned __int8 *)(ipa3_ctx + 480LL * a1 + 433));
              v24 = ipa3_ctx;
            }
            v23 = *(_QWORD *)(v24 + 34160);
            if ( v23 )
              v23 = ipc_log_string(
                      v23,
                      "ipa %s:%d coal pipe using GRAN_SEL = %d\n",
                      "ipa3_cfg_ep_aggr",
                      9676,
                      *(unsigned __int8 *)(v24 + 480LL * a1 + 433));
          }
          ((void (__fastcall *)(__int64))ipa_assert)(v23);
        }
      }
    }
    ((void (__fastcall *)(__int64, _QWORD, __int64))ipahal_write_reg_n_fields)(43, a1, ipa3_ctx + 480LL * a1 + 408);
    v27 = 0;
LABEL_45:
    if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
    {
      printk(&unk_3E7136, "ipa3_get_client_mapping");
      v41 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v42 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v42 )
        {
          ipc_log_string(v42, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
          v41 = ipa3_ctx;
        }
        v43 = *(_QWORD *)(v41 + 34160);
        if ( v43 )
          ipc_log_string(v43, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
      }
      __break(0x800u);
      if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
      {
        printk(&unk_3E7136, "ipa3_get_client_mapping");
        v44 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v45 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v45 )
          {
            ipc_log_string(v45, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
            v44 = ipa3_ctx;
          }
          v46 = *(_QWORD *)(v44 + 34160);
          if ( v46 )
            ipc_log_string(v46, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
        }
        __break(0x800u);
      }
    }
    ipa3_dec_client_disable_clks();
    goto LABEL_47;
  }
  printk(&unk_3FC013, "ipa3_cfg_ep_aggr");
  v32 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v33 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v33 )
    {
      ipc_log_string(v33, "ipa %s:%d pipe=%d cannot be configured to DEAGGR\n", "ipa3_cfg_ep_aggr", 9632, a1);
      v32 = ipa3_ctx;
    }
    v34 = *(_QWORD *)(v32 + 34160);
    if ( v34 )
      ipc_log_string(v34, "ipa %s:%d pipe=%d cannot be configured to DEAGGR\n", "ipa3_cfg_ep_aggr", 9632, a1);
  }
  __break(0x800u);
  v27 = -22;
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return v27;
}
