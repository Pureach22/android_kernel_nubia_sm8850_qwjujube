__int64 __fastcall cnss_wlfw_server_arrive(
        __int64 a1,
        _DWORD *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  int v9; // w9
  __int64 v10; // x0
  unsigned int v12; // w0
  __int64 v13; // x6
  __int64 v14; // x7
  unsigned __int64 v15; // x23
  const char *v16; // x1
  __int64 result; // x0
  unsigned __int64 StatusReg; // x19
  const char *v19; // x1
  __int64 v20; // x7
  const char *v21; // x1
  unsigned __int64 v22; // x9
  unsigned int v23; // w19
  const char *v24; // x1
  __int64 v25; // x7
  const char *v26; // x1
  __int64 v27; // x20
  unsigned __int16 *v28; // x21
  unsigned __int64 v29; // x8
  unsigned __int64 v30; // x8
  unsigned int v31; // w0
  __int64 v32; // x7
  unsigned int v33; // w22
  __int64 v34; // x0
  unsigned int v35; // w0
  const char *v36; // x1
  __int16 v37; // w8
  const char *v38; // x9
  __int64 v39; // x0
  const char *v40; // x1
  const char *v41; // x5
  __int64 v42; // x7
  const char *v43; // x1
  __int64 v44; // x7
  unsigned __int16 *v45; // x21
  __int64 v46; // x0
  const char *v47; // x1
  unsigned int wake_irq; // w0
  __int64 v49; // x7
  const char *v50; // x1
  __int64 v51; // x6
  __int64 v52; // x0
  const char *v53; // x1
  __int64 v54; // x7
  char v55; // w8
  __int64 v56; // x6
  __int64 v57; // x0
  const char *v58; // x1
  __int64 v59; // x6
  __int64 v60; // x9
  __int64 v61; // x10
  __int64 v62; // x0
  const char *v63; // x1
  __int64 v64; // x8
  __int64 v65; // x9
  char v66; // w8
  __int64 v67; // x11
  __int64 v68; // x12
  __int64 v69; // x10
  __int64 v70; // x9
  __int64 v71; // x7
  __int64 v72; // x6
  __int64 v73; // x0
  const char *v74; // x1
  int v75; // w0
  __int64 v76; // x6
  __int64 v77; // x7
  int v78; // w8
  int v79; // w8
  int v80; // w0
  __int64 v81; // x7
  int v82; // w22
  __int64 v83; // x0
  int v84; // w0
  const char *v85; // x1
  const char *v86; // x1
  __int64 v87; // x0
  const char *v88; // x1
  const char *v89; // x5
  unsigned __int64 v96; // x9
  char v97; // [xsp+0h] [xbp-80h]
  char v98; // [xsp+0h] [xbp-80h]
  char v99; // [xsp+0h] [xbp-80h]
  char v100; // [xsp+0h] [xbp-80h]
  char v101; // [xsp+0h] [xbp-80h]
  char v102; // [xsp+0h] [xbp-80h]
  char v103; // [xsp+0h] [xbp-80h]
  int v104; // [xsp+4h] [xbp-7Ch] BYREF
  __int64 v105; // [xsp+8h] [xbp-78h] BYREF
  __int64 v106; // [xsp+10h] [xbp-70h]
  __int64 v107; // [xsp+18h] [xbp-68h]
  __int64 v108; // [xsp+20h] [xbp-60h]
  __int64 v109; // [xsp+28h] [xbp-58h]
  __int64 v110; // [xsp+30h] [xbp-50h] BYREF
  __int64 v111; // [xsp+38h] [xbp-48h]
  __int64 v112; // [xsp+40h] [xbp-40h]
  __int64 v113; // [xsp+48h] [xbp-38h]
  __int64 v114; // [xsp+50h] [xbp-30h]
  __int64 v115; // [xsp+58h] [xbp-28h]
  __int64 v116; // [xsp+60h] [xbp-20h]
  __int64 v117; // [xsp+68h] [xbp-18h]
  __int64 v118; // [xsp+70h] [xbp-10h]
  __int64 v119; // [xsp+78h] [xbp-8h]

  v119 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    result = 4294967277LL;
    goto LABEL_21;
  }
  if ( (*(_QWORD *)(a1 + 552) & 1) != 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v19 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v19 = "soft_irq";
    }
    else
    {
      v19 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v19,
      "cnss_wlfw_server_arrive",
      3u,
      3u,
      "Unexpected WLFW server arrive\n",
      a7,
      a8,
      v97);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v21 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v21 = "soft_irq";
    }
    else
    {
      v21 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v21,
      "cnss_wlfw_server_arrive",
      3u,
      3u,
      "ASSERT at line %d\n",
      3755,
      v20,
      v98);
    __break(0x800u);
    goto LABEL_20;
  }
  LODWORD(v110) = 42;
  if ( !a2 )
  {
LABEL_20:
    result = 4294967274LL;
    goto LABEL_21;
  }
  v9 = a2[1];
  v10 = *(_QWORD *)(a1 + 856);
  HIDWORD(v110) = *a2;
  LODWORD(v111) = v9;
  v12 = kernel_connect(v10, &v110, 12, 0);
  if ( (v12 & 0x80000000) != 0 )
  {
    v22 = _ReadStatusReg(SP_EL0);
    v23 = v12;
    if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
    {
      v24 = "irq";
    }
    else
    {
      v37 = *(_DWORD *)(v22 + 16);
      v38 = (const char *)(v22 + 2320);
      if ( (v37 & 0xFF00) != 0 )
        v24 = "soft_irq";
      else
        v24 = v38;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v24,
      "cnss_wlfw_connect_to_server",
      3u,
      3u,
      "Failed to connect to QMI WLFW remote service port\n",
      v13,
      v14,
      v97);
    kfree(a2);
    result = v23;
    goto LABEL_21;
  }
  _X8 = (unsigned __int64 *)(a1 + 552);
  __asm { PRFM            #0x11, [X8] }
  do
    v96 = __ldxr(_X8);
  while ( __stxr(v96 | 1, _X8) );
  v15 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
  {
    v16 = "irq";
  }
  else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
  {
    v16 = "soft_irq";
  }
  else
  {
    v16 = (const char *)(v15 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v16,
    "cnss_wlfw_connect_to_server",
    6u,
    6u,
    "QMI WLFW service connected, state: 0x%lx\n",
    *(_QWORD *)(a1 + 552),
    v14,
    v97);
  kfree(a2);
  v117 = 0;
  v118 = 0;
  v115 = 0;
  v116 = 0;
  v113 = 0;
  v114 = 0;
  v111 = 0;
  v112 = 0;
  v110 = 0;
  if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
  {
    v26 = "irq";
  }
  else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
  {
    v26 = "soft_irq";
  }
  else
  {
    v26 = (const char *)(v15 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v26,
    "cnss_wlfw_ind_register_send_sync",
    7u,
    7u,
    "Sending indication register message, state: 0x%lx\n",
    *(_QWORD *)(a1 + 552),
    v25,
    v99);
  v27 = _kmalloc_cache_noprof(of_get_property, 3520, 56);
  if ( !v27 )
    goto LABEL_182;
  v28 = (unsigned __int16 *)_kmalloc_cache_noprof(_of_parse_phandle_with_args, 3520, 16);
  if ( !v28 )
    goto LABEL_183;
  *(_BYTE *)(v27 + 10) = 1;
  *(_WORD *)(v27 + 8) = 257;
  *(_WORD *)(v27 + 42) = 257;
  *(_WORD *)(v27 + 50) = 257;
  *(_WORD *)(v27 + 20) = 257;
  v29 = *(_QWORD *)(a1 + 7928);
  *(_QWORD *)(v27 + 12) = 0x10101014B4E454CLL;
  *(_QWORD *)(v27 + 30) = 0x101010101010101LL;
  *(_WORD *)(v27 + 38) = 257;
  if ( v29 )
  {
    if ( v29 <= 0xFFFFFFFFFFFFF000LL )
    {
      v30 = *(_QWORD *)(a1 + 7936);
      if ( v30 )
      {
        if ( v30 <= 0xFFFFFFFFFFFFF000LL )
          *(_WORD *)(v27 + 54) = 257;
      }
    }
  }
  v31 = qmi_txn_init(a1 + 856, &v110, &wlfw_ind_register_resp_msg_v01_ei);
  if ( (v31 & 0x80000000) != 0 )
  {
    v33 = v31;
    v39 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
    {
      v40 = "irq";
    }
    else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
    {
      v40 = "soft_irq";
    }
    else
    {
      v40 = (const char *)(v15 + 2320);
    }
    v41 = "Failed to initialize txn for indication register request, err: %d\n";
  }
  else
  {
    v33 = qmi_send_request(a1 + 856, 0, &v110, 32, 102, &wlfw_ind_register_req_msg_v01_ei, v27);
    if ( (v33 & 0x80000000) != 0 )
    {
      qmi_txn_cancel(&v110);
      v39 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
      {
        v40 = "irq";
      }
      else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
      {
        v40 = "soft_irq";
      }
      else
      {
        v40 = (const char *)(v15 + 2320);
      }
      v41 = "Failed to send indication register request, err: %d\n";
    }
    else
    {
      v34 = _msecs_to_jiffies(*(unsigned int *)(a1 + 6696));
      v35 = qmi_txn_wait(&v110, v34);
      if ( (v35 & 0x80000000) == 0 )
      {
        if ( *v28 )
        {
          if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
          {
            v36 = "irq";
          }
          else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
          {
            v36 = "soft_irq";
          }
          else
          {
            v36 = (const char *)(v15 + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v36,
            "cnss_wlfw_ind_register_send_sync",
            3u,
            3u,
            "Indication register request failed, result: %d, err: %d\n",
            *v28,
            v28[1],
            v100);
          v33 = -*v28;
        }
        else if ( *((_BYTE *)v28 + 4) )
        {
          v33 = (*((unsigned __int8 *)v28 + 8) << 31 >> 31) & 0xFFFFFF8E;
        }
        else
        {
          v33 = 0;
        }
        goto LABEL_74;
      }
      v33 = v35;
      v39 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
      {
        v40 = "irq";
      }
      else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
      {
        v40 = "soft_irq";
      }
      else
      {
        v40 = (const char *)(v15 + 2320);
      }
      v41 = "Failed to wait for response of indication register request, err: %d\n";
    }
  }
  cnss_debug_ipc_log_print(v39, v40, "cnss_wlfw_ind_register_send_sync", 3u, 3u, v41, v33, v32, v100);
LABEL_74:
  kfree(v27);
  kfree(v28);
  if ( (v33 & 0x80000000) == 0 )
  {
    v117 = 0;
    v118 = 0;
    v115 = 0;
    v116 = 0;
    v113 = 0;
    v114 = 0;
    v111 = 0;
    v112 = 0;
    v109 = 0;
    v110 = 0;
    v107 = 0;
    v108 = 0;
    v105 = 0;
    v106 = 0;
    if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
    {
      v43 = "irq";
    }
    else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
    {
      v43 = "soft_irq";
    }
    else
    {
      v43 = (const char *)(v15 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v43,
      "cnss_wlfw_host_cap_send_sync",
      7u,
      7u,
      "Sending host capability message, state: 0x%lx\n",
      *(_QWORD *)(a1 + 552),
      v42,
      v100);
    v27 = _kmalloc_cache_noprof(memcpy, 3520, 1000);
    if ( v27 )
    {
      v45 = (unsigned __int16 *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 4);
      if ( v45 )
      {
        v46 = cnss_ipc_log_context;
        *(_BYTE *)v27 = 1;
        *(_DWORD *)(v27 + 4) = 1;
        if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
        {
          v47 = "irq";
        }
        else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
        {
          v47 = "soft_irq";
        }
        else
        {
          v47 = (const char *)(v15 + 2320);
        }
        cnss_debug_ipc_log_print(
          v46,
          v47,
          "cnss_wlfw_host_cap_send_sync",
          7u,
          7u,
          "Number of clients is %d\n",
          1,
          v44,
          v101);
        wake_irq = cnss_bus_get_wake_irq(a1);
        *(_DWORD *)(v27 + 12) = wake_irq;
        if ( wake_irq )
        {
          if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
          {
            v50 = "irq";
          }
          else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
          {
            v50 = "soft_irq";
          }
          else
          {
            v50 = (const char *)(v15 + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v50,
            "cnss_wlfw_host_cap_send_sync",
            7u,
            7u,
            "WAKE MSI base data is %d\n",
            wake_irq,
            v49,
            v102);
          *(_BYTE *)(v27 + 8) = 1;
        }
        v51 = *(unsigned __int8 *)(a1 + 6512);
        *(_BYTE *)(v27 + 166) = 1;
        v52 = cnss_ipc_log_context;
        *(_WORD *)(v27 + 154) = 257;
        *(_DWORD *)(v27 + 158) = 16843009;
        *(_BYTE *)(v27 + 167) = v51;
        if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
        {
          v53 = "irq";
        }
        else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
        {
          v53 = "soft_irq";
        }
        else
        {
          v53 = (const char *)(v15 + 2320);
        }
        cnss_debug_ipc_log_print(
          v52,
          v53,
          "cnss_wlfw_host_cap_send_sync",
          7u,
          7u,
          "Calibration done is %d\n",
          v51,
          v49,
          v102);
        if ( *(_BYTE *)(a1 + 7841) == 1 )
        {
          v55 = *(_BYTE *)(v27 + 153);
          *(_BYTE *)(v27 + 152) = 1;
          *(_BYTE *)(v27 + 153) = v55 | 2;
        }
        v56 = *(unsigned int *)(a1 + 6480);
        if ( (_DWORD)v56 )
        {
          *(_DWORD *)(v27 + 556) = v56;
          v57 = cnss_ipc_log_context;
          *(_BYTE *)(v27 + 555) = 1;
          if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
          {
            v58 = "irq";
          }
          else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
          {
            v58 = "soft_irq";
          }
          else
          {
            v58 = (const char *)(v15 + 2320);
          }
          cnss_debug_ipc_log_print(
            v57,
            v58,
            "cnss_wlfw_host_cap_send_sync",
            7u,
            7u,
            "Supported link speed in Host Cap %d\n",
            v56,
            v54,
            v103);
        }
        if ( (cnss_bus_is_smmu_s1_enabled(a1) & 1) != 0
          && !(unsigned int)cnss_bus_get_iova(a1)
          && !(unsigned int)cnss_bus_get_iova_ipa(a1) )
        {
          v60 = v108;
          v59 = v109;
          v61 = v106;
          *(_BYTE *)(v27 + 248) = 1;
          v62 = cnss_ipc_log_context;
          *(_QWORD *)(v27 + 256) = v59;
          *(_QWORD *)(v27 + 264) = v61 + v60;
          if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
          {
            v63 = "irq";
          }
          else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
          {
            v63 = "soft_irq";
          }
          else
          {
            v63 = (const char *)(v15 + 2320);
          }
          cnss_debug_ipc_log_print(
            v62,
            v63,
            "cnss_wlfw_host_cap_send_sync",
            7u,
            7u,
            "Sending iova starting 0x%llx with size 0x%llx\n",
            v59,
            v61 + v60,
            v103);
        }
        v64 = *(_QWORD *)(a1 + 528);
        *(_BYTE *)(v27 + 304) = 1;
        v65 = v64 - 4359;
        *(_DWORD *)(v27 + 308) = 2;
        if ( (unsigned __int64)(v64 - 4359) <= 0xB )
        {
          v66 = 1;
          if ( ((1LL << v65) & 0x489) != 0 )
          {
            *(_BYTE *)(v27 + 314) = 1;
            *(_WORD *)(v27 + 312) = 257;
            v67 = 330;
            *(_WORD *)(v27 + 322) = 32;
            v68 = 329;
            *(_DWORD *)(v27 + 316) = 0x10000;
            v69 = 331;
            *(_DWORD *)(v27 + 324) = 65793;
            *(_BYTE *)(v27 + 328) = 2;
            v70 = 332;
            *(_BYTE *)(v27 + 320) = 1;
LABEL_124:
            *(_BYTE *)(v27 + v68) = 0;
            *(_BYTE *)(v27 + v67) = 1;
            *(_BYTE *)(v27 + v69) = v66;
            *(_BYTE *)(v27 + v70) = 1;
            goto LABEL_125;
          }
          if ( v65 == 11 )
          {
            *(_WORD *)(v27 + 312) = 257;
            *(_DWORD *)(v27 + 316) = 0x10000;
            v66 = 0;
            *(_BYTE *)(v27 + 314) = 1;
            v67 = 328;
            *(_BYTE *)(v27 + 320) = 1;
            *(_DWORD *)(v27 + 322) = 16842784;
            v70 = 331;
            v69 = 329;
            *(_BYTE *)(v27 + 326) = 1;
            v68 = 327;
            goto LABEL_124;
          }
        }
LABEL_125:
        if ( !(unsigned int)cnss_get_feature_list(a1, &v105) )
        {
          v72 = v105;
          v73 = cnss_ipc_log_context;
          *(_BYTE *)(v27 + 345) = 1;
          *(_QWORD *)(v27 + 352) = v72;
          if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
          {
            v74 = "irq";
          }
          else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
          {
            v74 = "soft_irq";
          }
          else
          {
            v74 = (const char *)(v15 + 2320);
          }
          cnss_debug_ipc_log_print(
            v73,
            v74,
            "cnss_wlfw_host_cap_send_sync",
            7u,
            7u,
            "Sending feature list 0x%llx\n",
            v72,
            v71,
            v103);
        }
        if ( cnss_get_platform_name(a1, v27 + 183, 64) )
          *(_BYTE *)(v27 + 182) = 1;
        if ( *(_QWORD *)(a1 + 528) == 4369 || of_find_property(*(_QWORD *)(*(_QWORD *)a1 + 760LL), "fig-direct-cx", 0) )
        {
          v75 = of_property_read_variable_u32_array(*(_QWORD *)(*(_QWORD *)a1 + 760LL), "cx-mode", &v104, 1, 0);
          if ( v75 < 0 )
          {
            v82 = v75 & (v75 >> 31);
            if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
            {
              v86 = "irq";
            }
            else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
            {
              v86 = "soft_irq";
            }
            else
            {
              v86 = (const char *)(v15 + 2320);
            }
            cnss_debug_ipc_log_print(
              cnss_ipc_log_context,
              v86,
              "cnss_wlfw_host_cap_send_sync",
              3u,
              3u,
              "could not get cx mode\n",
              v76,
              v77,
              v103);
            goto LABEL_179;
          }
          v78 = v104;
          *(_BYTE *)(v27 + 992) = 1;
          if ( v78 == 3 )
            v79 = 2;
          else
            v79 = v78 == 2;
          *(_DWORD *)(v27 + 996) = v79;
        }
        v80 = qmi_txn_init(a1 + 856, &v110, &wlfw_host_cap_resp_msg_v01_ei);
        if ( v80 < 0 )
        {
          v82 = v80;
          v87 = cnss_ipc_log_context;
          if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
          {
            v88 = "irq";
          }
          else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
          {
            v88 = "soft_irq";
          }
          else
          {
            v88 = (const char *)(v15 + 2320);
          }
          v89 = "Failed to initialize txn for host capability request, err: %d\n";
        }
        else
        {
          v82 = qmi_send_request(a1 + 856, 0, &v110, 52, 982, &wlfw_host_cap_req_msg_v01_ei, v27);
          if ( v82 < 0 )
          {
            qmi_txn_cancel(&v110);
            v87 = cnss_ipc_log_context;
            if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
            {
              v88 = "irq";
            }
            else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
            {
              v88 = "soft_irq";
            }
            else
            {
              v88 = (const char *)(v15 + 2320);
            }
            v89 = "Failed to send host capability request, err: %d\n";
          }
          else
          {
            v83 = _msecs_to_jiffies(*(unsigned int *)(a1 + 6696));
            v84 = qmi_txn_wait(&v110, v83);
            if ( (v84 & 0x80000000) == 0 )
            {
              if ( *v45 )
              {
                if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
                {
                  v85 = "irq";
                }
                else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
                {
                  v85 = "soft_irq";
                }
                else
                {
                  v85 = (const char *)(v15 + 2320);
                }
                cnss_debug_ipc_log_print(
                  cnss_ipc_log_context,
                  v85,
                  "cnss_wlfw_host_cap_send_sync",
                  3u,
                  3u,
                  "Host capability request failed, result: %d, err: %d\n",
                  *v45,
                  v45[1],
                  v103);
                v82 = -*v45;
              }
              else
              {
                v82 = 0;
              }
              goto LABEL_179;
            }
            v82 = v84;
            v87 = cnss_ipc_log_context;
            if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
            {
              v88 = "irq";
            }
            else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
            {
              v88 = "soft_irq";
            }
            else
            {
              v88 = (const char *)(v15 + 2320);
            }
            v89 = "Failed to wait for response of host capability request, err: %d\n";
          }
        }
        cnss_debug_ipc_log_print(v87, v88, "cnss_wlfw_host_cap_send_sync", 3u, 3u, v89, (unsigned int)v82, v81, v103);
LABEL_179:
        kfree(v27);
        kfree(v45);
        result = v82 & (unsigned int)(v82 >> 31);
        goto LABEL_21;
      }
LABEL_183:
      kfree(v27);
      result = 4294967284LL;
      goto LABEL_21;
    }
LABEL_182:
    result = 4294967284LL;
    goto LABEL_21;
  }
  if ( v33 == -114 )
    result = 0;
  else
    result = v33;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
