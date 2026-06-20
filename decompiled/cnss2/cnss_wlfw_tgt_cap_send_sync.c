__int64 __fastcall cnss_wlfw_tgt_cap_send_sync(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v9; // x24
  const char *v11; // x1
  __int64 v12; // x19
  unsigned __int16 *v13; // x20
  unsigned int v14; // w0
  __int64 v15; // x7
  unsigned int v16; // w22
  __int64 v17; // x0
  unsigned int v18; // w0
  const char *v19; // x1
  __int64 v20; // x0
  const char *v21; // x1
  const char *v22; // x5
  int v23; // w9
  int v24; // w8
  int v25; // w9
  int v26; // w8
  size_t v27; // x0
  unsigned __int64 v28; // x2
  size_t v29; // x0
  unsigned __int64 v30; // x2
  const char *v31; // x1
  __int64 v32; // x2
  __int64 v33; // x3
  __int64 v34; // x4
  __int64 v35; // x5
  __int64 v36; // x6
  __int64 v37; // x7
  int v38; // w8
  __int64 v39; // x6
  const char *v40; // x1
  __int64 v41; // x6
  __int64 v42; // x0
  const char *v43; // x1
  __int64 v44; // x1
  __int64 v45; // x2
  __int64 v46; // x3
  __int64 v47; // x4
  __int64 v48; // x5
  __int64 v49; // x6
  __int64 v50; // x7
  __int64 v51; // x6
  __int64 v52; // x0
  const char *v53; // x1
  __int64 v54; // x7
  __int64 v55; // x8
  __int64 v56; // x0
  const char *v57; // x1
  __int64 v58; // x7
  __int64 v59; // x8
  const char *v60; // x1
  __int64 v61; // x7
  __int64 v62; // x8
  const char *v63; // x1
  __int64 v64; // x7
  __int64 v65; // x8
  const char *v66; // x1
  unsigned int v67; // w8
  int v68; // w22
  int v69; // w23
  const char *v70; // x1
  int v71; // w8
  int v72; // w9
  int v73; // w8
  int v74; // w9
  const char *v75; // x1
  int v76; // w8
  __int64 v77; // x6
  int v78; // w10
  const char *v79; // x1
  __int64 v80; // x2
  __int64 v81; // x3
  __int64 v82; // x4
  __int64 v83; // x5
  __int64 v84; // x6
  __int64 v85; // x7
  __int64 v86; // x6
  __int64 v87; // x7
  const char *v88; // x1
  unsigned __int64 v89; // x6
  const char *v90; // x1
  const char *v91; // x1
  const char *v92; // x1
  const char *v93; // x1
  __int64 v94; // x20
  __int64 (__fastcall *v95)(_QWORD, _QWORD, _QWORD); // x0
  char v97; // [xsp+0h] [xbp-B0h]
  char v98; // [xsp+0h] [xbp-B0h]
  char v99; // [xsp+0h] [xbp-B0h]
  char v100; // [xsp+0h] [xbp-B0h]
  _QWORD v101[9]; // [xsp+20h] [xbp-90h] BYREF
  char s[48]; // [xsp+68h] [xbp-48h] BYREF
  __int64 v103; // [xsp+98h] [xbp-18h]
  __int64 v104; // [xsp+A0h] [xbp-10h]
  __int64 v105; // [xsp+A8h] [xbp-8h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v9 = _ReadStatusReg(SP_EL0);
  v105 = *(_QWORD *)(StatusReg + 1808);
  memset(v101, 0, sizeof(v101));
  if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
  {
    v11 = "irq";
  }
  else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
  {
    v11 = "soft_irq";
  }
  else
  {
    v11 = (const char *)(v9 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v11,
    "cnss_wlfw_tgt_cap_send_sync",
    7u,
    7u,
    "Sending target capability message, state: 0x%lx\n",
    *(_QWORD *)(a1 + 552),
    a8,
    v97);
  v12 = _kmalloc_cache_noprof(of_find_compatible_node, 3520, 1);
  if ( !v12 )
    goto LABEL_186;
  while ( 1 )
  {
    v13 = (unsigned __int16 *)_kmalloc_cache_noprof(iommu_get_domain_for_dev, 3520, 2344);
    if ( !v13 )
    {
      kfree(v12);
LABEL_186:
      v16 = -12;
      goto LABEL_187;
    }
    v14 = qmi_txn_init(a1 + 856, v101, &wlfw_cap_resp_msg_v01_ei);
    if ( (v14 & 0x80000000) != 0 )
    {
      v16 = v14;
      v20 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
      {
        v21 = "irq";
      }
      else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
      {
        v21 = "soft_irq";
      }
      else
      {
        v21 = (const char *)(v9 + 2320);
      }
      v22 = "Failed to initialize txn for target capability request, err: %d\n";
      goto LABEL_40;
    }
    v16 = qmi_send_request(a1 + 856, 0, v101, 36, 0, &wlfw_cap_req_msg_v01_ei, v12);
    if ( (v16 & 0x80000000) != 0 )
    {
      qmi_txn_cancel(v101);
      v20 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
      {
        v21 = "irq";
      }
      else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
      {
        v21 = "soft_irq";
      }
      else
      {
        v21 = (const char *)(v9 + 2320);
      }
      v22 = "Failed to send respond target capability request, err: %d\n";
      goto LABEL_40;
    }
    v17 = _msecs_to_jiffies(*(unsigned int *)(a1 + 6696));
    v18 = qmi_txn_wait(v101, v17);
    if ( (v18 & 0x80000000) != 0 )
    {
      v16 = v18;
      v20 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
      {
        v21 = "irq";
      }
      else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
      {
        v21 = "soft_irq";
      }
      else
      {
        v21 = (const char *)(v9 + 2320);
      }
      v22 = "Failed to wait for response of target capability request, err: %d\n";
LABEL_40:
      cnss_debug_ipc_log_print(v20, v21, "cnss_wlfw_tgt_cap_send_sync", 3u, 3u, v22, v16, v15, v98);
LABEL_41:
      kfree(v12);
      kfree(v13);
      goto LABEL_187;
    }
    if ( *v13 )
    {
      if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
      {
        v19 = "irq";
      }
      else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
      {
        v19 = "soft_irq";
      }
      else
      {
        v19 = (const char *)(v9 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v19,
        "cnss_wlfw_tgt_cap_send_sync",
        3u,
        3u,
        "Target capability request failed, result: %d, err: %d\n",
        *v13,
        v13[1],
        v98);
      v16 = -*v13;
      goto LABEL_41;
    }
    if ( *((_BYTE *)v13 + 4) )
    {
      v23 = *((_DWORD *)v13 + 3);
      *(_DWORD *)(a1 + 1464) = *((_DWORD *)v13 + 2);
      *(_DWORD *)(a1 + 1468) = v23;
    }
    if ( *((_BYTE *)v13 + 16) )
      v24 = *((_DWORD *)v13 + 5);
    else
      v24 = 255;
    v25 = *((unsigned __int8 *)v13 + 24);
    *(_DWORD *)(a1 + 1472) = v24;
    if ( v25 )
      *(_DWORD *)(a1 + 1476) = *((_DWORD *)v13 + 7);
    if ( !*((_BYTE *)v13 + 32) )
      goto LABEL_52;
    v26 = *((_DWORD *)v13 + 9);
    *((_BYTE *)v13 + 72) = 0;
    *(_DWORD *)(a1 + 1480) = v26;
    v27 = strnlen((const char *)v13 + 40, 0x21u);
    if ( v27 < 0x22 )
      break;
    _fortify_panic(2, 33, v27 + 1);
LABEL_181:
    v29 = _fortify_panic(7, 33, v28);
LABEL_182:
    _fortify_panic(2, 129, v29 + 1);
LABEL_183:
    _fortify_panic(7, 129, v30);
    v94 = *(_QWORD *)(v9 + 80);
    v95 = of_find_compatible_node;
    *(_QWORD *)(v9 + 80) = &cnss_wlfw_tgt_cap_send_sync__alloc_tag;
    v12 = _kmalloc_cache_noprof(v95, 3520, 1);
    *(_QWORD *)(v9 + 80) = v94;
    if ( !v12 )
      goto LABEL_186;
  }
  if ( v27 == 33 )
    v28 = 33;
  else
    v28 = v27 + 1;
  if ( v28 >= 0x22 )
    goto LABEL_181;
  sized_strscpy(a1 + 1484, v13 + 20);
LABEL_52:
  if ( !*((_BYTE *)v13 + 76) )
    goto LABEL_59;
  *((_BYTE *)v13 + 205) = 0;
  v29 = strnlen((const char *)v13 + 77, 0x81u);
  if ( v29 >= 0x82 )
    goto LABEL_182;
  if ( v29 == 129 )
    v30 = 129;
  else
    v30 = v29 + 1;
  if ( v30 >= 0x82 )
    goto LABEL_183;
  sized_strscpy(a1 + 1584, (char *)v13 + 77);
LABEL_59:
  if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
  {
    v31 = "irq";
  }
  else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
  {
    v31 = "soft_irq";
  }
  else
  {
    v31 = (const char *)(v9 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v31,
    "cnss_wlfw_tgt_cap_send_sync",
    6u,
    6u,
    "direct cx data pin mode: %d\n",
    *((unsigned __int8 *)v13 + 1180),
    v15,
    v98);
  if ( *((_BYTE *)v13 + 1180) )
  {
    v38 = *((unsigned __int8 *)v13 + 1181);
    *(_BYTE *)(a1 + 7992) = *((_BYTE *)v13 + 1181) != 0;
    if ( !v38 )
      goto LABEL_75;
  }
  else if ( (*(_BYTE *)(a1 + 7992) & 1) == 0 )
  {
    goto LABEL_75;
  }
  if ( (cnss_set_cx_mode(a1, 1, v32, v33, v34, v35, v36, v37) & 0x80000000) != 0 )
  {
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
    {
      v40 = "irq";
    }
    else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      v40 = "soft_irq";
    }
    else
    {
      v40 = (const char *)(v9 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v40,
      "cnss_wlfw_tgt_cap_send_sync",
      3u,
      3u,
      "Failed to set to Data Pin Mode\n",
      v39,
      v37,
      v99);
  }
LABEL_75:
  if ( *((_BYTE *)v13 + 208) )
  {
    v41 = *((unsigned int *)v13 + 53);
    v42 = cnss_ipc_log_context;
    *(_DWORD *)(a1 + 6740) = v41;
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
    {
      v43 = "irq";
    }
    else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      v43 = "soft_irq";
    }
    else
    {
      v43 = (const char *)(v9 + 2320);
    }
    cnss_debug_ipc_log_print(v42, v43, "cnss_wlfw_tgt_cap_send_sync", 7u, 7u, "Voltage for CPR: %dmV\n", v41, v37, v99);
    cnss_update_cpr_info(a1, v44, v45, v46, v47, v48, v49, v50);
  }
  if ( *((_BYTE *)v13 + 216) )
  {
    v51 = *((unsigned int *)v13 + 55);
    v52 = cnss_ipc_log_context;
    *(_DWORD *)(a1 + 6484) = v51;
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
    {
      v53 = "irq";
    }
    else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      v53 = "soft_irq";
    }
    else
    {
      v53 = (const char *)(v9 + 2320);
    }
    cnss_debug_ipc_log_print(
      v52,
      v53,
      "cnss_wlfw_tgt_cap_send_sync",
      7u,
      7u,
      "Device frequency is %d HZ\n",
      v51,
      v37,
      v99);
  }
  if ( *((_BYTE *)v13 + 224) )
    *(_DWORD *)(a1 + 1716) = *((_DWORD *)v13 + 57);
  if ( *((_BYTE *)v13 + 264) )
  {
    v54 = *((_QWORD *)v13 + 34);
    v55 = *((_QWORD *)v13 + 35);
    v56 = cnss_ipc_log_long_context;
    *(_QWORD *)(a1 + 1520) = v54;
    *(_QWORD *)(a1 + 1528) = v55;
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
    {
      v57 = "irq";
    }
    else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      v57 = "soft_irq";
    }
    else
    {
      v57 = (const char *)(v9 + 2320);
    }
    cnss_debug_ipc_log_print(
      v56,
      v57,
      "cnss_wlfw_tgt_cap_send_sync",
      8u,
      7u,
      "Device memory info[%d]: start = 0x%llx, size = 0x%llx\n",
      0,
      v54,
      v55);
    v58 = *((_QWORD *)v13 + 36);
    v59 = *((_QWORD *)v13 + 37);
    *(_QWORD *)(a1 + 1536) = v58;
    *(_QWORD *)(a1 + 1544) = v59;
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
    {
      v60 = "irq";
    }
    else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      v60 = "soft_irq";
    }
    else
    {
      v60 = (const char *)(v9 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_long_context,
      v60,
      "cnss_wlfw_tgt_cap_send_sync",
      8u,
      7u,
      "Device memory info[%d]: start = 0x%llx, size = 0x%llx\n",
      1,
      v58,
      v59);
    v61 = *((_QWORD *)v13 + 38);
    v62 = *((_QWORD *)v13 + 39);
    *(_QWORD *)(a1 + 1552) = v61;
    *(_QWORD *)(a1 + 1560) = v62;
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
    {
      v63 = "irq";
    }
    else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      v63 = "soft_irq";
    }
    else
    {
      v63 = (const char *)(v9 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_long_context,
      v63,
      "cnss_wlfw_tgt_cap_send_sync",
      8u,
      7u,
      "Device memory info[%d]: start = 0x%llx, size = 0x%llx\n",
      2,
      v61,
      v62);
    v64 = *((_QWORD *)v13 + 40);
    v65 = *((_QWORD *)v13 + 41);
    *(_QWORD *)(a1 + 1568) = v64;
    *(_QWORD *)(a1 + 1576) = v65;
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
    {
      v66 = "irq";
    }
    else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      v66 = "soft_irq";
    }
    else
    {
      v66 = (const char *)(v9 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_long_context,
      v66,
      "cnss_wlfw_tgt_cap_send_sync",
      8u,
      7u,
      "Device memory info[%d]: start = 0x%llx, size = 0x%llx\n",
      3,
      v64,
      v65);
  }
  if ( *((_BYTE *)v13 + 240) )
  {
    v67 = *((unsigned __int8 *)v13 + 248);
    v68 = (v67 >> 5) & 1;
    *(_BYTE *)(a1 + 7512) = v67 & 1;
    v69 = (v67 >> 6) & 1;
    *(_BYTE *)(a1 + 7513) = (v67 & 4) != 0;
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
    {
      v70 = "irq";
    }
    else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      v70 = "soft_irq";
    }
    else
    {
      v70 = (const char *)(v9 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v70,
      "cnss_wlfw_tgt_cap_send_sync",
      7u,
      7u,
      "FW aux uc support capability: %d\n",
      (v67 >> 2) & 1,
      v37,
      v99);
    cnss_xdump_update_wl_cap(a1, v68, v69);
    *(_QWORD *)(a1 + 7520) = *((_QWORD *)v13 + 31);
  }
  if ( !*((_BYTE *)v13 + 360) || (v71 = v13[181], (unsigned int)(v71 - 1) >= 0x180) )
    LOWORD(v71) = 0;
  v72 = *((unsigned __int8 *)v13 + 354);
  *(_WORD *)(a1 + 7752) = v71;
  if ( v72 )
    v73 = *((_DWORD *)v13 + 89);
  else
    v73 = 0;
  v74 = *((unsigned __int8 *)v13 + 372);
  *(_DWORD *)(a1 + 7756) = v73;
  if ( v74 )
    *(_BYTE *)(a1 + 7760) = *((_BYTE *)v13 + 373);
  if ( *(_QWORD *)(a1 + 528) == 4369 || of_find_property(*(_QWORD *)(*(_QWORD *)a1 + 760LL), "fig-direct-cx", 0) )
  {
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
    {
      v75 = "irq";
    }
    else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      v75 = "soft_irq";
    }
    else
    {
      v75 = (const char *)(v9 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v75,
      "cnss_wlfw_tgt_cap_send_sync",
      6u,
      6u,
      "ol_cpr_cfg_ext is: %d\n",
      *((unsigned __int8 *)v13 + 1182),
      v37,
      v99);
    if ( *(_BYTE *)(a1 + 7992) == 1 && *((_BYTE *)v13 + 1182) )
      ((void (__fastcall *)(__int64, unsigned __int16 *))cnss_ol_cpr_cfg_ext_setup)(a1, v13 + 592);
  }
  else if ( *((_BYTE *)v13 + 374) )
  {
    cnss_aop_ol_cpr_cfg_setup(a1, (unsigned int *)v13 + 94);
  }
  v76 = *(_DWORD *)(a1 + 7824);
  if ( v76 )
  {
    v77 = *(unsigned int *)(a1 + 1472);
    v78 = 0;
    while ( (_DWORD)v77 != *(_DWORD *)(*(_QWORD *)(a1 + 7832) + 4LL * v78) )
    {
      if ( v76 == ++v78 )
        goto LABEL_157;
    }
    v103 = 0;
    v104 = 0;
    s[47] = 0;
    strcpy(s, "{class: wlan_pdc, ss: rf, res: pdc, enable: 0}");
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
    {
      v79 = "irq";
    }
    else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      v79 = "soft_irq";
    }
    else
    {
      v79 = (const char *)(v9 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v79,
      "cnss_wlfw_tgt_cap_send_sync",
      7u,
      7u,
      "Disabling WLAN PDC for board_id: %02x\n",
      v77,
      v37,
      v99);
    if ( (cnss_aop_send_msg(a1, s, v80, v81, v82, v83, v84, v85) & 0x80000000) != 0 )
    {
      if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
      {
        v88 = "irq";
      }
      else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
      {
        v88 = "soft_irq";
      }
      else
      {
        v88 = (const char *)(v9 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v88,
        "cnss_wlfw_tgt_cap_send_sync",
        7u,
        7u,
        "Failed to Send AOP Msg",
        v86,
        v87,
        v99);
    }
  }
LABEL_157:
  if ( *((_BYTE *)v13 + 1168) )
  {
    v89 = *(_QWORD *)(v13 + 586);
    *(_QWORD *)(a1 + 7844) = v89;
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
    {
      v90 = "irq";
    }
    else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      v90 = "soft_irq";
    }
    else
    {
      v90 = (const char *)(v9 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v90,
      "cnss_wlfw_tgt_cap_send_sync",
      6u,
      6u,
      "serial id  0x%x 0x%x\n",
      v89,
      HIDWORD(v89),
      v99);
  }
  if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
  {
    v91 = "irq";
  }
  else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
  {
    v91 = "soft_irq";
  }
  else
  {
    v91 = (const char *)(v9 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v91,
    "cnss_wlfw_tgt_cap_send_sync",
    7u,
    7u,
    "Target capability: chip_id: 0x%x, chip_family: 0x%x, board_id: 0x%x, soc_id: 0x%x, otp_version: 0x%x\n",
    *(unsigned int *)(a1 + 1464),
    *(unsigned int *)(a1 + 1468),
    *(_DWORD *)(a1 + 1472));
  if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
  {
    v92 = "irq";
  }
  else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
  {
    v92 = "soft_irq";
  }
  else
  {
    v92 = (const char *)(v9 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v92,
    "cnss_wlfw_tgt_cap_send_sync",
    7u,
    7u,
    "fw_version: 0x%x, fw_build_timestamp: %s, fw_build_id: %s, hwid_bitmap:0x%x\n",
    *(unsigned int *)(a1 + 1480),
    a1 + 1484,
    a1 + 48);
  if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
  {
    v93 = "irq";
  }
  else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
  {
    v93 = "soft_irq";
  }
  else
  {
    v93 = (const char *)(v9 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v93,
    "cnss_wlfw_tgt_cap_send_sync",
    7u,
    7u,
    "Hang event params, Length: 0x%x, Offset Address: 0x%x\n",
    *(unsigned __int16 *)(a1 + 7752),
    *(unsigned int *)(a1 + 7756),
    v100);
  kfree(v12);
  kfree(v13);
  v16 = 0;
LABEL_187:
  _ReadStatusReg(SP_EL0);
  return v16;
}
