__int64 __fastcall ipa3_resume_gsi_wdi_pipe(unsigned int a1)
{
  __int64 v2; // x8
  unsigned int v3; // w20
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x23
  int v7; // w0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  unsigned int started; // w19
  unsigned int v12; // w8
  __int64 v13; // x8
  unsigned int v14; // w9
  unsigned int v15; // w9
  __int64 v16; // x12
  __int64 v17; // x11
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v29; // x8
  __int64 v30; // x0
  __int64 v31; // x0
  int v32; // w21
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // [xsp+20h] [xbp-50h] BYREF
  __int64 v43; // [xsp+28h] [xbp-48h]
  __int64 v44; // [xsp+30h] [xbp-40h]
  __int64 v45; // [xsp+38h] [xbp-38h] BYREF
  __int64 v46; // [xsp+40h] [xbp-30h]
  __int64 v47; // [xsp+48h] [xbp-28h]
  __int64 v48; // [xsp+50h] [xbp-20h]
  __int64 v49; // [xsp+58h] [xbp-18h]
  __int16 v50; // [xsp+64h] [xbp-Ch] BYREF
  __int64 v51; // [xsp+68h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = ipa3_ctx;
  v50 = 0;
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v3 = *(_DWORD *)(ipa3_ctx + 34920);
  if ( ipa3_ctx )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d ep=%d\n", "ipa3_resume_gsi_wdi_pipe", 2702, a1);
      v2 = ipa3_ctx;
    }
    v5 = *(_QWORD *)(v2 + 34160);
    if ( v5 )
      ipc_log_string(v5, "ipa %s:%d ep=%d\n", "ipa3_resume_gsi_wdi_pipe", 2702, a1);
  }
  if ( a1 >= 0x25 )
    __break(0x5512u);
  v6 = ipa3_ctx + 480LL * a1;
  if ( *(_DWORD *)(v6 + 620) == 3 )
  {
    ((void (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1) <= 0x85 )
      ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_mapping)(a1);
    ipa3_inc_client_enable_clks();
    v50 = 0;
    v7 = ipa_cfg_ep_ctrl(a1, &v50);
    if ( v7 )
    {
      v32 = v7;
      printk(&unk_3C7B03, "ipa3_resume_gsi_wdi_pipe");
      v33 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v34 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v34 )
        {
          ipc_log_string(
            v34,
            "ipa %s:%d client (ep: %d) fail un-susp/delay result=%d\n",
            "ipa3_resume_gsi_wdi_pipe",
            2715,
            a1,
            v32);
          v33 = ipa3_ctx;
        }
        v35 = *(_QWORD *)(v33 + 34160);
        if ( v35 )
          ipc_log_string(
            v35,
            "ipa %s:%d client (ep: %d) fail un-susp/delay result=%d\n",
            "ipa3_resume_gsi_wdi_pipe",
            2715,
            a1,
            v32);
      }
    }
    else
    {
      v8 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v9 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v9 )
        {
          ipc_log_string(v9, "ipa %s:%d client (ep: %d) un-susp/delay\n", "ipa3_resume_gsi_wdi_pipe", 2717, a1);
          v8 = ipa3_ctx;
        }
        v10 = *(_QWORD *)(v8 + 34160);
        if ( v10 )
          ipc_log_string(v10, "ipa %s:%d client (ep: %d) un-susp/delay\n", "ipa3_resume_gsi_wdi_pipe", 2717, a1);
      }
    }
    started = gsi_start_channel(*(_QWORD *)(v6 + 176));
    if ( started )
    {
      v36 = printk(&unk_3F8BA6, "ipa3_resume_gsi_wdi_pipe");
      v37 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v38 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v38 )
        {
          ipc_log_string(v38, "ipa %s:%d gsi_start_channel failed %d\n", "ipa3_resume_gsi_wdi_pipe", 2721, started);
          v37 = ipa3_ctx;
        }
        v36 = *(_QWORD *)(v37 + 34160);
        if ( v36 )
          v36 = ipc_log_string(
                  v36,
                  "ipa %s:%d gsi_start_channel failed %d\n",
                  "ipa3_resume_gsi_wdi_pipe",
                  2721,
                  started);
      }
      ((void (__fastcall *)(__int64))ipa_assert)(v36);
    }
    v12 = *(_DWORD *)(v6 + 172);
    if ( v12 - 87 <= 6 && ((1 << (v12 - 87)) & 0x55) != 0 || v12 <= 0x13 && ((1 << v12) & 0x82800) != 0 )
    {
      if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, __int64, _QWORD, _QWORD))ipa3_uc_client_add_holb_monitor)(
                           *(unsigned __int16 *)(v6 + 176),
                           3,
                           v3,
                           0) )
      {
        printk(&unk_3C68A9, "ipa3_resume_gsi_wdi_pipe");
        v39 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v40 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v40 )
          {
            ipc_log_string(
              v40,
              "ipa %s:%d Add HOLB monitor failed for gsi ch %lu\n",
              "ipa3_resume_gsi_wdi_pipe",
              2730,
              *(_QWORD *)(v6 + 176));
            v39 = ipa3_ctx;
          }
          v41 = *(_QWORD *)(v39 + 34160);
          if ( v41 )
            ipc_log_string(
              v41,
              "ipa %s:%d Add HOLB monitor failed for gsi ch %lu\n",
              "ipa3_resume_gsi_wdi_pipe",
              2730,
              *(_QWORD *)(v6 + 176));
        }
      }
    }
    v13 = ipa3_ctx;
    v14 = *(_DWORD *)(ipa3_ctx + 32240);
    if ( v14 >= 0x11 && (v14 > 0x17 || ((1 << v14) & 0x940000) == 0) )
    {
      v15 = *(_DWORD *)(v6 + 172);
      v16 = 45281;
      v17 = 45280;
      if ( v15 < 0x86 && (v15 & 1) == 0 )
      {
        v16 = 45279;
        v17 = 45278;
      }
      *(_BYTE *)(ipa3_ctx + v16) = *(_QWORD *)(v6 + 176);
      *(_BYTE *)(v13 + v17) = v15 < 0x86 && (v15 & 1) == 0;
      ipa3_uc_debug_stats_alloc(
        *(_QWORD *)(ipa3_ctx + 45274),
        *(unsigned int *)(ipa3_ctx + 45282) | ((unsigned __int64)*(unsigned __int16 *)(ipa3_ctx + 45286) << 32));
    }
    gsi_query_channel_info(*(_QWORD *)(v6 + 176), &v45);
    gsi_read_channel_scratch(*(_QWORD *)(v6 + 176), &v42);
    v18 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v19 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v19 )
      {
        ipc_log_string(
          v19,
          "ipa %s:%d ch=%lu channel base = 0x%llx , event base 0x%llx\n",
          "ipa3_resume_gsi_wdi_pipe",
          2757,
          *(_QWORD *)(v6 + 176),
          *(_QWORD *)(v6 + 224),
          *(_QWORD *)(v6 + 200));
        v18 = ipa3_ctx;
      }
      v20 = *(_QWORD *)(v18 + 34160);
      if ( v20 )
      {
        ipc_log_string(
          v20,
          "ipa %s:%d ch=%lu channel base = 0x%llx , event base 0x%llx\n",
          "ipa3_resume_gsi_wdi_pipe",
          2757,
          *(_QWORD *)(v6 + 176),
          *(_QWORD *)(v6 + 224),
          *(_QWORD *)(v6 + 200));
        v18 = ipa3_ctx;
      }
      if ( v18 )
      {
        v21 = *(_QWORD *)(v18 + 34152);
        if ( v21 )
        {
          ipc_log_string(
            v21,
            "ipa %s:%d RP=0x%llx WP=0x%llx ev_valid=%d ERP=0x%llx EWP=0x%llx\n",
            "ipa3_resume_gsi_wdi_pipe",
            2760,
            v46,
            v45,
            (unsigned __int8)v47,
            v49,
            v48);
          v18 = ipa3_ctx;
        }
        v22 = *(_QWORD *)(v18 + 34160);
        if ( v22 )
        {
          ipc_log_string(
            v22,
            "ipa %s:%d RP=0x%llx WP=0x%llx ev_valid=%d ERP=0x%llx EWP=0x%llx\n",
            "ipa3_resume_gsi_wdi_pipe",
            2760,
            v46,
            v45,
            (unsigned __int8)v47,
            v49,
            v48);
          v18 = ipa3_ctx;
        }
        if ( v18 )
        {
          v23 = *(_QWORD *)(v18 + 34152);
          if ( v23 )
          {
            ipc_log_string(
              v23,
              "ipa %s:%d Scratch 0 = %x Scratch 1 = %x Scratch 2 = %x Scratch 3 = %x\n",
              "ipa3_resume_gsi_wdi_pipe",
              2763,
              v42,
              HIDWORD(v42),
              v43,
              HIDWORD(v43));
            v18 = ipa3_ctx;
          }
          v24 = *(_QWORD *)(v18 + 34160);
          if ( v24 )
            ipc_log_string(
              v24,
              "ipa %s:%d Scratch 0 = %x Scratch 1 = %x Scratch 2 = %x Scratch 3 = %x\n",
              "ipa3_resume_gsi_wdi_pipe",
              2763,
              v42,
              HIDWORD(v42),
              v43,
              HIDWORD(v43));
        }
      }
    }
    *(_DWORD *)(v6 + 620) |= 4u;
    v25 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v26 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v26 )
      {
        ipc_log_string(v26, "ipa %s:%d exit\n", "ipa3_resume_gsi_wdi_pipe", 2766);
        v25 = ipa3_ctx;
      }
      v27 = *(_QWORD *)(v25 + 34160);
      if ( v27 )
        ipc_log_string(v27, "ipa %s:%d exit\n", "ipa3_resume_gsi_wdi_pipe", 2766);
    }
  }
  else
  {
    printk(&unk_3C4C2C, "ipa3_resume_gsi_wdi_pipe");
    v29 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_70;
    v30 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v30 )
    {
      ipc_log_string(
        v30,
        "ipa %s:%d WDI channel bad state %d\n",
        "ipa3_resume_gsi_wdi_pipe",
        2706,
        *(_DWORD *)(v6 + 620));
      v29 = ipa3_ctx;
    }
    v31 = *(_QWORD *)(v29 + 34160);
    if ( v31 )
    {
      ipc_log_string(
        v31,
        "ipa %s:%d WDI channel bad state %d\n",
        "ipa3_resume_gsi_wdi_pipe",
        2706,
        *(_DWORD *)(v6 + 620));
      started = -14;
    }
    else
    {
LABEL_70:
      started = -14;
    }
  }
  _ReadStatusReg(SP_EL0);
  return started;
}
