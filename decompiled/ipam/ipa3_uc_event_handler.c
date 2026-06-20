__int64 __fastcall ipa3_uc_event_handler(__int64 a1, __int64 a2)
{
  __int64 v2; // x1
  __int64 v3; // x2
  __int64 v4; // x3
  __int64 v5; // x9
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned int v9; // w4
  void (__fastcall *v10)(__int64, __int64, __int64, __int64); // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  int v15; // w4
  __int64 v16; // x3
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  int v22; // w0
  _QWORD *v23; // x8
  unsigned int v24; // w9
  __int64 result; // x0
  int v26; // w19
  __int64 v27; // x9
  int v28; // w19
  __int64 v29; // x2
  __int64 v30; // x0
  __int64 v31; // x1
  __int64 v32; // x2
  __int64 v33; // x3
  void (__fastcall *v34)(__int64, __int64, __int64, __int64); // x8
  void (__fastcall *v35)(__int64); // x8
  __int64 v36; // x0
  void (__fastcall *v37)(__int64); // x8
  __int64 v38; // x0
  void (__fastcall *v39)(__int64); // x8
  __int64 v40; // x0
  void (__fastcall *v41)(__int64); // x8
  __int64 v42; // x0
  void (__fastcall *v43)(__int64); // x8
  __int64 v44; // x0
  void (__fastcall *v45)(__int64); // x8
  __int64 v46; // x0
  void (__fastcall *v47)(__int64); // x8
  __int64 v48; // x0
  __int64 v49; // x2
  __int64 v50; // x3
  __int64 v51; // x0
  __int64 v52; // x1
  __int64 v53; // x8
  unsigned int v54; // w10
  unsigned int v55; // w12
  unsigned __int8 *v56; // x25
  int v57; // w9
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x8
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x8
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x8
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x8
  __int64 v72; // x0
  __int64 v73; // x0
  unsigned int v74; // w19
  __int64 v75; // x8
  __int64 v76; // x20
  const char *v77; // x0
  __int64 v78; // x20
  const char *v79; // x0
  __int64 v80; // x8
  __int64 reg_n; // x0
  __int64 v82; // x1
  __int64 v83; // x2
  __int64 v84; // x3
  char v85; // w9
  __int64 v86; // x8
  __int64 v87; // x0
  __int64 v88; // x8
  __int64 v89; // x0
  __int64 v90; // x8
  __int64 v91; // x0
  __int64 v92; // x0
  const char *v93; // [xsp+0h] [xbp-20h] BYREF
  __int64 v94; // [xsp+8h] [xbp-18h]
  __int64 v95; // [xsp+10h] [xbp-10h]
  __int64 v96; // [xsp+18h] [xbp-8h]

  v96 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( ipa3_ctx != a2 )
    __break(0x800u);
  v94 = (__int64)"ipa_uc.c";
  v95 = 0x1000002E8LL;
  v93 = "ipa3_uc_event_handler";
  ipa3_inc_client_enable_clks();
  v5 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v6 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v6 )
    {
      ipc_log_string(
        v6,
        "ipa %s:%d uC evt opcode=%u\n",
        "ipa3_uc_event_handler",
        747,
        *(unsigned __int8 *)(*(_QWORD *)(ipa3_ctx + 34752) + 20LL));
      v5 = ipa3_ctx;
    }
    v7 = *(_QWORD *)(v5 + 34160);
    if ( v7 )
    {
      ipc_log_string(
        v7,
        "ipa %s:%d uC evt opcode=%u\n",
        "ipa3_uc_event_handler",
        747,
        *(unsigned __int8 *)(*(_QWORD *)(v5 + 34752) + 20LL));
      v5 = ipa3_ctx;
    }
  }
  v8 = *(_QWORD *)(v5 + 34752);
  v9 = *(unsigned __int8 *)(v8 + 20);
  v10 = (void (__fastcall *)(__int64, __int64, __int64, __int64))*(&ipa3_uc_hdlrs + 5 * (v9 >> 5) + 1);
  if ( v10 )
  {
    if ( *((_DWORD *)v10 - 1) != 540320615 )
      __break(0x8228u);
    v10(v8, v2, v3, v4);
    v5 = ipa3_ctx;
    v8 = *(_QWORD *)(ipa3_ctx + 34752);
    v9 = *(unsigned __int8 *)(v8 + 20);
  }
  if ( v9 == 2 )
  {
    if ( v5 )
    {
      if ( *(_QWORD *)(v5 + 34152) )
      {
        ipc_log_string(
          *(_QWORD *)(v5 + 34152),
          "ipa %s:%d uC evt log info ofst=0x%x\n",
          "ipa3_uc_event_handler",
          779,
          *(_DWORD *)(v8 + 24));
        v5 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v5 + 34160);
      if ( v13 )
      {
        ipc_log_string(
          v13,
          "ipa %s:%d uC evt log info ofst=0x%x\n",
          "ipa3_uc_event_handler",
          779,
          *(_DWORD *)(*(_QWORD *)(v5 + 34752) + 24LL));
        v5 = ipa3_ctx;
      }
    }
    v14 = v5 + 0x8000;
    v15 = *(_DWORD *)(v5 + 34768);
    v16 = *(unsigned int *)(*(_QWORD *)(v5 + 34752) + 24LL);
    if ( v15 )
    {
      if ( (_DWORD)v16 != v15 )
      {
        printk(&unk_3D8DF8, "ipa3_log_evt_hdlr");
        v17 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v18 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v18 )
          {
            ipc_log_string(
              v18,
              "ipa %s:%d uc top ofst changed new=%u cur=%u\n",
              "ipa3_log_evt_hdlr",
              550,
              *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 34752) + 24LL),
              *(_DWORD *)(ipa3_ctx + 34768));
            v17 = ipa3_ctx;
          }
          v19 = v17 + 0x8000;
          v20 = *(_QWORD *)(v19 + 1392);
          if ( v20 )
            ipc_log_string(
              v20,
              "ipa %s:%d uc top ofst changed new=%u cur=%u\n",
              "ipa3_log_evt_hdlr",
              550,
              *(_DWORD *)(*(_QWORD *)(v19 + 1984) + 24LL),
              *(_DWORD *)(v19 + 2000));
        }
      }
      goto LABEL_38;
    }
    v27 = *(_QWORD *)(v5 + 34176);
    *(_DWORD *)(v14 + 2000) = v16;
    v28 = *(_DWORD *)(v27 + 36);
    if ( v16 + 80 >= (unsigned __int64)((unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(
                                                        64,
                                                        0,
                                                        0)
                                      + v28
                                      + *(unsigned __int16 *)(ipa3_ctx + 29520)) )
    {
      printk(&unk_3DBEAC, "ipa3_log_evt_hdlr");
      v86 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v87 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v87 )
        {
          ipc_log_string(
            v87,
            "ipa %s:%d uc_top 0x%x outside SRAM\n",
            "ipa3_log_evt_hdlr",
            526,
            *(_DWORD *)(ipa3_ctx + 34768));
          v86 = ipa3_ctx;
        }
        v88 = v86 + 0x8000;
        v89 = *(_QWORD *)(v88 + 1392);
        if ( v89 )
          ipc_log_string(v89, "ipa %s:%d uc_top 0x%x outside SRAM\n", "ipa3_log_evt_hdlr", 526, *(_DWORD *)(v88 + 2000));
      }
    }
    else
    {
      if ( arm64_use_ng_mappings )
        v29 = 0x68000000000F13LL;
      else
        v29 = 0x68000000000713LL;
      v30 = ioremap_prot((unsigned int)(*(_DWORD *)(ipa3_ctx + 34768) + *(_DWORD *)(ipa3_ctx + 28640)), 80, v29);
      *(_QWORD *)(ipa3_ctx + 34760) = v30;
      if ( v30 )
      {
        v34 = (void (__fastcall *)(__int64, __int64, __int64, __int64))off_2014C8;
        if ( off_2014C8 )
        {
          if ( *((_DWORD *)off_2014C8 - 1) != 178579188 )
            __break(0x8228u);
          v34(v30, v31, v32, v33);
        }
        v35 = (void (__fastcall *)(__int64))off_2014F0;
        if ( off_2014F0 )
        {
          v36 = *(_QWORD *)(ipa3_ctx + 34760);
          if ( *((_DWORD *)off_2014F0 - 1) != 178579188 )
            __break(0x8228u);
          v35(v36);
        }
        v37 = (void (__fastcall *)(__int64))off_201518;
        if ( off_201518 )
        {
          v38 = *(_QWORD *)(ipa3_ctx + 34760);
          if ( *((_DWORD *)off_201518 - 1) != 178579188 )
            __break(0x8228u);
          v37(v38);
        }
        v39 = (void (__fastcall *)(__int64))off_201540;
        if ( off_201540 )
        {
          v40 = *(_QWORD *)(ipa3_ctx + 34760);
          if ( *((_DWORD *)off_201540 - 1) != 178579188 )
            __break(0x8228u);
          v39(v40);
        }
        v41 = (void (__fastcall *)(__int64))off_201568;
        if ( off_201568 )
        {
          v42 = *(_QWORD *)(ipa3_ctx + 34760);
          if ( *((_DWORD *)off_201568 - 1) != 178579188 )
            __break(0x8228u);
          v41(v42);
        }
        v43 = (void (__fastcall *)(__int64))off_201590;
        if ( off_201590 )
        {
          v44 = *(_QWORD *)(ipa3_ctx + 34760);
          if ( *((_DWORD *)off_201590 - 1) != 178579188 )
            __break(0x8228u);
          v43(v44);
        }
        v45 = (void (__fastcall *)(__int64))off_2015B8;
        if ( off_2015B8 )
        {
          v46 = *(_QWORD *)(ipa3_ctx + 34760);
          if ( *((_DWORD *)off_2015B8 - 1) != 178579188 )
            __break(0x8228u);
          v45(v46);
        }
        v47 = (void (__fastcall *)(__int64))off_2015E0;
        if ( off_2015E0 )
        {
          v48 = *(_QWORD *)(ipa3_ctx + 34760);
          if ( *((_DWORD *)off_2015E0 - 1) != 178579188 )
            __break(0x8228u);
          v47(v48);
        }
        goto LABEL_38;
      }
      printk(&unk_3A4291, "ipa3_log_evt_hdlr");
      v90 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v91 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v91 )
        {
          ipc_log_string(v91, "ipa %s:%d fail to ioremap uc top\n", "ipa3_log_evt_hdlr", 535);
          v90 = ipa3_ctx;
        }
        v92 = *(_QWORD *)(v90 + 34160);
        if ( v92 )
          ipc_log_string(v92, "ipa %s:%d fail to ioremap uc top\n", "ipa3_log_evt_hdlr", 535);
      }
    }
    *(_DWORD *)(ipa3_ctx + 34768) = 0;
    goto LABEL_38;
  }
  if ( v9 != 3 )
  {
    if ( v9 == 1 )
    {
      v74 = (unsigned __int8)*(_DWORD *)(v8 + 24);
      printk(&unk_3AD5E8, "ipa3_uc_event_handler");
      v75 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v76 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v76 )
        {
          v77 = ipa_hw_error_str(v74);
          ipc_log_string(v76, "ipa %s:%d uC Error, evt errorType = %s\n", "ipa3_uc_event_handler", 768, v77);
          v75 = ipa3_ctx;
        }
        v78 = *(_QWORD *)(v75 + 34160);
        if ( v78 )
        {
          v79 = ipa_hw_error_str(v74);
          ipc_log_string(v78, "ipa %s:%d uC Error, evt errorType = %s\n", "ipa3_uc_event_handler", 768, v79);
          v75 = ipa3_ctx;
        }
      }
      v80 = v75 + 0x8000;
      *(_BYTE *)(v80 + 1890) = 1;
      *(_DWORD *)(v80 + 2012) = v74;
      reg_n = ipahal_read_reg_n(13, 0);
      v85 = *(_BYTE *)(ipa3_ctx + 51241);
      *(_DWORD *)(ipa3_ctx + 34784) = reg_n;
      if ( (v85 & 1) == 0 )
        ((void (__fastcall *)(__int64, __int64, __int64, __int64))ipa_assert)(reg_n, v82, v83, v84);
    }
    else if ( v5 )
    {
      v11 = *(_QWORD *)(v5 + 34152);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d unsupported uC evt opcode=%u\n", "ipa3_uc_event_handler", 788, v9);
        v5 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v5 + 34160);
      if ( v12 )
        ipc_log_string(
          v12,
          "ipa %s:%d unsupported uC evt opcode=%u\n",
          "ipa3_uc_event_handler",
          788,
          *(unsigned __int8 *)(*(_QWORD *)(v5 + 34752) + 20LL));
    }
    goto LABEL_38;
  }
  if ( v5 )
  {
    if ( *(_QWORD *)(v5 + 34152) )
    {
      ipc_log_string(
        *(_QWORD *)(v5 + 34152),
        "ipa %s:%d uC evt log info ofst=0x%x\n",
        "ipa3_uc_event_handler",
        784,
        *(_DWORD *)(v8 + 24));
      v5 = ipa3_ctx;
    }
    v21 = *(_QWORD *)(v5 + 34160);
    if ( v21 )
      ipc_log_string(
        v21,
        "ipa %s:%d uC evt log info ofst=0x%x\n",
        "ipa3_uc_event_handler",
        784,
        *(_DWORD *)(*(_QWORD *)(v5 + 34752) + 24LL));
  }
  v93 = nullptr;
  v94 = 0;
  v22 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))ipahal_read_reg_mn)(66, 0, 1);
  v23 = (_QWORD *)ipa3_ctx;
  v24 = *(_DWORD *)(ipa3_ctx + 34892);
  *(_DWORD *)(ipa3_ctx + 34900) = v22;
  if ( v24 != v22 )
  {
    v26 = v22;
    do
    {
      v56 = (unsigned __int8 *)(v23[4358] + v24);
      v57 = v56[2];
      if ( v56[2] )
      {
        if ( v57 == 1 )
        {
          if ( v23 )
          {
            v58 = v23[4269];
            if ( v58 )
            {
              ipc_log_string(
                v58,
                "ipa %s:%d got quota-notify %d reach(%d) usage (%llu)\n",
                "ipa3_event_ring_hdlr",
                599,
                *v56,
                *((_DWORD *)v56 + 1),
                *((_QWORD *)v56 + 1));
              v23 = (_QWORD *)ipa3_ctx;
            }
            v59 = v23[4270];
            if ( v59 )
              ipc_log_string(
                v59,
                "ipa %s:%d got quota-notify %d reach(%d) usage (%llu)\n",
                "ipa3_event_ring_hdlr",
                599,
                *v56,
                *((_DWORD *)v56 + 1),
                *((_QWORD *)v56 + 1));
          }
          if ( !(unsigned int)ipa_broadcast_wdi_quota_reach_ind(0, *((_QWORD *)v56 + 1)) )
            goto LABEL_79;
          if ( (unsigned int)__ratelimit(&ipa3_event_ring_hdlr__rs_130, "ipa3_event_ring_hdlr") )
          {
            printk(&unk_3C16A1, "ipa3_event_ring_hdlr");
            v60 = ipa3_ctx;
            if ( ipa3_ctx )
            {
LABEL_90:
              v61 = *(_QWORD *)(v60 + 34152);
              if ( v61 )
              {
                ipc_log_string(v61, "ipa %s:%d failed on quota_reach for %d\n", "ipa3_event_ring_hdlr", 603, *v56);
                v60 = ipa3_ctx;
              }
              v62 = *(_QWORD *)(v60 + 34160);
              if ( v62 )
                ipc_log_string(v62, "ipa %s:%d failed on quota_reach for %d\n", "ipa3_event_ring_hdlr", 603, *v56);
            }
          }
          else
          {
            v60 = ipa3_ctx;
            if ( ipa3_ctx )
              goto LABEL_90;
          }
        }
        else
        {
          if ( v57 == 2 )
          {
            printk(&unk_3EF997, "ipa3_event_ring_hdlr");
            v71 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v72 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v72 )
              {
                ipc_log_string(
                  v72,
                  "ipa %s:%d Bad Periph for Chan %d QTimer %u %u\n",
                  "ipa3_event_ring_hdlr",
                  610,
                  v56[4],
                  *((_DWORD *)v56 + 3),
                  *((_DWORD *)v56 + 2));
                v71 = ipa3_ctx;
              }
              v73 = *(_QWORD *)(v71 + 34160);
              if ( v73 )
                ipc_log_string(
                  v73,
                  "ipa %s:%d Bad Periph for Chan %d QTimer %u %u\n",
                  "ipa3_event_ring_hdlr",
                  610,
                  v56[4],
                  *((_DWORD *)v56 + 3),
                  *((_DWORD *)v56 + 2));
            }
            v49 = *((unsigned int *)v56 + 2);
            v50 = *((unsigned int *)v56 + 3);
            v51 = v56[4];
            v52 = 1;
          }
          else
          {
            if ( v57 != 3 )
              goto LABEL_79;
            printk(&unk_3F2DAE, "ipa3_event_ring_hdlr");
            v68 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v69 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v69 )
              {
                ipc_log_string(
                  v69,
                  "ipa %s:%d Recovered Periph Chan %d QTimer %u %u\n",
                  "ipa3_event_ring_hdlr",
                  622,
                  v56[4],
                  *((_DWORD *)v56 + 3),
                  *((_DWORD *)v56 + 2));
                v68 = ipa3_ctx;
              }
              v70 = *(_QWORD *)(v68 + 34160);
              if ( v70 )
                ipc_log_string(
                  v70,
                  "ipa %s:%d Recovered Periph Chan %d QTimer %u %u\n",
                  "ipa3_event_ring_hdlr",
                  622,
                  v56[4],
                  *((_DWORD *)v56 + 3),
                  *((_DWORD *)v56 + 2));
            }
            v49 = *((unsigned int *)v56 + 2);
            v50 = *((unsigned int *)v56 + 3);
            v51 = v56[4];
            v52 = 0;
          }
          ipa3_uc_holb_event_log(v51, v52, v49, v50);
        }
      }
      else
      {
        if ( v23 )
        {
          v63 = v23[4269];
          if ( v63 )
          {
            ipc_log_string(
              v63,
              "ipa %s:%d prot(%d), index (%d) throughput (%llu)\n",
              "ipa3_event_ring_hdlr",
              582,
              *v56,
              *((_DWORD *)v56 + 1),
              *((_QWORD *)v56 + 1));
            v23 = (_QWORD *)ipa3_ctx;
          }
          v64 = v23[4270];
          if ( v64 )
            ipc_log_string(
              v64,
              "ipa %s:%d prot(%d), index (%d) throughput (%llu)\n",
              "ipa3_event_ring_hdlr",
              582,
              *v56,
              *((_DWORD *)v56 + 1),
              *((_QWORD *)v56 + 1));
        }
        v93 = nullptr;
        v94 = 0;
        LOBYTE(v93) = *((_DWORD *)v56 + 1);
        v94 = 200LL * *((_QWORD *)v56 + 1);
        if ( !(unsigned int)ipa3_inform_wlan_bw(&v93) )
          goto LABEL_79;
        if ( (unsigned int)__ratelimit(&ipa3_event_ring_hdlr__rs, "ipa3_event_ring_hdlr") )
        {
          printk(&unk_3ECBD4, "ipa3_event_ring_hdlr");
          v65 = ipa3_ctx;
          if ( ipa3_ctx )
          {
LABEL_102:
            v66 = *(_QWORD *)(v65 + 34152);
            if ( v66 )
            {
              ipc_log_string(
                v66,
                "ipa %s:%d failed on index %d to wlan\n",
                "ipa3_event_ring_hdlr",
                592,
                (unsigned __int8)v93);
              v65 = ipa3_ctx;
            }
            v67 = *(_QWORD *)(v65 + 34160);
            if ( v67 )
              ipc_log_string(
                v67,
                "ipa %s:%d failed on index %d to wlan\n",
                "ipa3_event_ring_hdlr",
                592,
                (unsigned __int8)v93);
          }
        }
        else
        {
          v65 = ipa3_ctx;
          if ( ipa3_ctx )
            goto LABEL_102;
        }
      }
LABEL_79:
      v53 = ipa3_ctx + 0x8000;
      v54 = *(_DWORD *)(ipa3_ctx + 34880);
      v55 = *(_DWORD *)(ipa3_ctx + 34888) + 16;
      *(_DWORD *)(ipa3_ctx + 34892) = (*(_DWORD *)(ipa3_ctx + 34892) + 16) % v54;
      *(_DWORD *)(v53 + 2120) = v55 % v54;
      ((void (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_write_reg_mn)(66, 0, 0);
      v23 = (_QWORD *)ipa3_ctx;
      v24 = *(_DWORD *)(ipa3_ctx + 34892);
    }
    while ( v24 != v26 );
  }
LABEL_38:
  v93 = "ipa3_uc_event_handler";
  v94 = (__int64)"ipa_uc.c";
  v95 = 0x100000316LL;
  result = ipa3_dec_client_disable_clks();
  _ReadStatusReg(SP_EL0);
  return result;
}
