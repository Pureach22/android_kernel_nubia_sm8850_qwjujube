__int64 __fastcall cam_icp_mgr_init_devs(__int64 a1, __int64 a2)
{
  unsigned int v4; // w0
  unsigned int hw_info; // w21
  char v7; // w7
  unsigned int v8; // w6
  int v9; // w10
  __int64 v10; // x8
  int v11; // w25
  __int64 *v12; // x0
  int v13; // w9
  __int64 *v14; // x0
  int v15; // w9
  unsigned int v16; // w23
  int v17; // w22
  __int64 *v18; // x0
  int v19; // w26
  int v20; // w9
  bool v21; // w8
  const char *v22; // x5
  __int64 v23; // x6
  __int64 v24; // x4
  unsigned int v25; // w22
  unsigned int v26; // w0
  __int64 device_by_node; // x0
  unsigned int **v28; // x9
  unsigned int *v29; // x7
  __int64 v30; // x8
  __int64 v31; // x10
  __int64 *v32; // x8
  __int64 v33; // x10
  __int64 v34; // x6
  int v35; // w7
  __int64 v36; // x10
  unsigned int v37; // w11
  __int64 *v38; // x8
  __int64 v39; // x8
  __int64 v40; // x0
  unsigned int v41; // w8
  __int64 *v42; // x8
  __int64 v43; // x7
  const char *v44; // x5
  __int64 v45; // x6
  __int64 v46; // x4
  __int64 *v47; // x11
  __int64 v48; // x10
  __int64 v49; // x12
  __int64 *v50; // x11
  __int64 v51; // x10
  __int64 v52; // x12
  unsigned __int64 StatusReg; // x20
  __int64 v54; // x21
  __int64 v55; // [xsp+10h] [xbp-90h] BYREF
  __int64 *v56; // [xsp+18h] [xbp-88h] BYREF
  unsigned int v57; // [xsp+24h] [xbp-7Ch] BYREF
  _DWORD *v58; // [xsp+28h] [xbp-78h] BYREF
  __int64 v59; // [xsp+30h] [xbp-70h] BYREF
  _QWORD v60[2]; // [xsp+38h] [xbp-68h] BYREF
  _QWORD v61[2]; // [xsp+48h] [xbp-58h] BYREF
  __int64 v62; // [xsp+58h] [xbp-48h] BYREF
  __int64 v63; // [xsp+60h] [xbp-40h]
  int v64; // [xsp+68h] [xbp-38h]
  __int64 *v65; // [xsp+70h] [xbp-30h] BYREF
  __int64 *v66; // [xsp+78h] [xbp-28h]
  __int64 *v67; // [xsp+80h] [xbp-20h]
  __int64 *v68; // [xsp+88h] [xbp-18h]
  __int64 *v69; // [xsp+90h] [xbp-10h]
  __int64 v70; // [xsp+98h] [xbp-8h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v68 = nullptr;
  v69 = nullptr;
  v66 = nullptr;
  v67 = nullptr;
  v65 = nullptr;
  v64 = 0;
  v62 = 0;
  v63 = 0;
  v55 = 0;
  v56 = nullptr;
  v4 = cam_icp_alloc_processor_devs(a1, (char *)&v55 + 4, &v56, &v62);
  if ( v4 )
  {
    hw_info = v4;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_alloc_devs",
      9481,
      "[%s] proc devices allocation failed rc=%d",
      (const char *)(a2 + 112),
      v4);
LABEL_3:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_init_devs",
      9646,
      "[%s] devices allocation failed rc=%d",
      (const char *)(a2 + 112),
      hw_info);
    goto LABEL_4;
  }
  v7 = BYTE4(v55);
  if ( HIDWORD(v55) >= 5 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_alloc_devs",
      9487,
      "[%s] Invalid hw dev type: %u",
      a2 + 112);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(&v65, 0);
    else
      kvfree(&v65);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v56, 0);
    else
      kvfree(v56);
    hw_info = -22;
    goto LABEL_3;
  }
  v8 = *((_DWORD *)&v62 + HIDWORD(v55));
  if ( v8 >= 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_alloc_devs",
      9497,
      "Invalid number of ICP device: %u allocated exceeds ICP device supported per hw mgr: %u",
      v8,
      1);
    hw_info = -22;
    goto LABEL_51;
  }
  v9 = *(_DWORD *)(a2 + 44180);
  v10 = *(unsigned int *)(a2 + 144);
  (&v65)[HIDWORD(v55)] = v56;
  *(_DWORD *)(a2 + 44180) = v9 | (1LL << v7);
  if ( (unsigned int)v10 >= 2 )
    goto LABEL_124;
  v11 = *((_DWORD *)&icp_cpas_mask + v10);
  if ( (of_property_read_variable_u32_array(a1, "num-ipe", &v55, 1, 0) & 0x80000000) == 0 )
  {
    if ( mem_trace_en == 1 )
    {
      v12 = (__int64 *)cam_mem_trace_alloc(8LL * (unsigned int)v55, 0xCC0u, 0, "cam_icp_mgr_alloc_devs", 0x2525u);
      v56 = v12;
      if ( !v12 )
        goto LABEL_47;
    }
    else
    {
      v12 = (__int64 *)_kvmalloc_node_noprof(8LL * (unsigned int)v55, 0, 3520, 0xFFFFFFFFLL);
      v56 = v12;
      if ( !v12 )
      {
LABEL_47:
        v22 = "[%s] ipe device allocation failed";
        v23 = a2 + 112;
        v24 = 9512;
LABEL_50:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_mgr_alloc_devs",
          v24,
          v22,
          v23);
        hw_info = 0;
        goto LABEL_51;
      }
    }
    v13 = *(_DWORD *)(a2 + 44180);
    v11 |= 0x800u;
    v67 = v12;
    LODWORD(v63) = v55;
    *(_DWORD *)(a2 + 44180) = v13 | 4;
  }
  if ( (of_property_read_variable_u32_array(a1, "num-bps", &v55, 1, 0) & 0x80000000) == 0 )
  {
    if ( mem_trace_en == 1 )
    {
      v14 = (__int64 *)cam_mem_trace_alloc(8LL * (unsigned int)v55, 0xCC0u, 0, "cam_icp_mgr_alloc_devs", 0x2535u);
      v56 = v14;
      if ( !v14 )
        goto LABEL_48;
    }
    else
    {
      v14 = (__int64 *)_kvmalloc_node_noprof(8LL * (unsigned int)v55, 0, 3520, 0xFFFFFFFFLL);
      v56 = v14;
      if ( !v14 )
      {
LABEL_48:
        v22 = "[%s] bps device allocation failed";
        v23 = a2 + 112;
        v24 = 9528;
        goto LABEL_50;
      }
    }
    v15 = *(_DWORD *)(a2 + 44180);
    v11 |= 0x400u;
    v68 = v14;
    HIDWORD(v63) = v55;
    *(_DWORD *)(a2 + 44180) = v15 | 8;
  }
  v16 = 1;
  v17 = of_property_read_variable_u32_array(a1, "num-ofe", &v55, 1, 0);
  if ( v17 < 0 )
  {
    v19 = 0;
  }
  else
  {
    if ( mem_trace_en == 1 )
    {
      v18 = (__int64 *)cam_mem_trace_alloc(8LL * (unsigned int)v55, 0xCC0u, 0, "cam_icp_mgr_alloc_devs", 0x2545u);
      v56 = v18;
      if ( !v18 )
        goto LABEL_49;
    }
    else
    {
      v18 = (__int64 *)_kvmalloc_node_noprof(8LL * (unsigned int)v55, 0, 3520, 0xFFFFFFFFLL);
      v56 = v18;
      if ( !v18 )
      {
LABEL_49:
        v22 = "[%s] OFE device allocation failed";
        v23 = a2 + 112;
        v24 = 9544;
        goto LABEL_50;
      }
    }
    v20 = *(_DWORD *)(a2 + 44180);
    v16 = 2;
    v19 = 16;
    v69 = v18;
    v64 = v55;
    *(_DWORD *)(a2 + 44180) = v20 | 0x10;
  }
  v61[0] = 0;
  v61[1] = 0;
  v60[0] = 0;
  v60[1] = 0;
  v58 = nullptr;
  v59 = 0;
  v57 = 0;
  hw_info = cam_cpas_get_hw_info(&v59, v60, v61, &v58, &v57, nullptr, nullptr);
  if ( !hw_info )
  {
    if ( v57 >= v16 )
    {
      if ( (v11 & ~*v58) == 0 && (v17 < 0 || (v19 & ~v58[1]) == 0) )
      {
        if ( of_find_property(a1, "ipe_bps_pc_en", 0) )
          v21 = 1;
        else
          v21 = of_find_property(a1, "interframe_pc_en", 0) != 0;
        *(_BYTE *)(a2 + 44231) = v21;
        *(_BYTE *)(a2 + 44230) = of_find_property(a1, "icp_pc_en", 0) != 0;
        *(_BYTE *)(a2 + 44232) = of_find_property(a1, "icp_use_pil", 0) != 0;
        *(_BYTE *)(a2 + 44235) = of_find_property(a1, "synx_signaling_en", 0) != 0;
        *(_BYTE *)(a2 + 44236) = cam_cpas_is_fw_based_sys_caching_supported();
        goto LABEL_70;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_verify_hw_caps",
        9462,
        "[%s] Found unsupported HW, cpas caps mask: %u icp device mask: %u",
        a2 + 112);
      hw_info = -19;
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_verify_hw_caps",
        9454,
        "[%s] Number of found icp device caps mask %u exceeds cpas cap mask %u",
        (const char *)(a2 + 112),
        v16,
        v57);
      hw_info = -22;
    }
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_mgr_alloc_devs",
    9557,
    "CPAS ICP HW capability verification fails rc=%d",
    hw_info);
LABEL_51:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v56, 0);
  else
    kvfree(v56);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v65, 0);
  else
    kvfree(v65);
  if ( (mem_trace_en & 1) != 0 )
    cam_mem_trace_free(v66, 0);
  else
    kvfree(v66);
  if ( (mem_trace_en & 1) != 0 )
    cam_mem_trace_free(v67, 0);
  else
    kvfree(v67);
  if ( (mem_trace_en & 1) != 0 )
    cam_mem_trace_free(v68, 0);
  else
    kvfree(v68);
  if ( (mem_trace_en & 1) != 0 )
  {
    cam_mem_trace_free(v69, 0);
    if ( hw_info )
      goto LABEL_3;
  }
  else
  {
    kvfree(v69);
    if ( hw_info )
      goto LABEL_3;
  }
LABEL_70:
  hw_info = of_property_read_string_helper(a1, "compat-hw-name", 0, 0, 0);
  if ( (hw_info & 0x80000000) != 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_init_devs",
      9653,
      "[%s] Invalid compat-hw-name count=%d",
      (const char *)(a2 + 112),
      hw_info);
    goto LABEL_127;
  }
  if ( hw_info )
  {
    v25 = 0;
    while ( 1 )
    {
      v59 = 0;
      v26 = of_property_read_string_helper(a1, "compat-hw-name", &v59, 1, v25);
      if ( (v26 & 0x80000000) != 0 )
      {
        hw_info = v26;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_mgr_init_devs",
          9670,
          "[%s] unable to get property name: idx=%d rc=%d",
          (const char *)(a2 + 112),
          v25,
          v26);
        goto LABEL_127;
      }
      if ( !of_find_node_by_name(0, v59) )
        break;
      device_by_node = of_find_device_by_node();
      if ( !device_by_node )
      {
        v43 = v59;
        v44 = "[%s] platform device not found for %s";
        v45 = a2 + 112;
        v46 = 9687;
        goto LABEL_113;
      }
      v28 = *(unsigned int ***)(device_by_node + 168);
      if ( !v28 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_mgr_init_devs",
          9695,
          "[%s] invalid drvdata in ICP related devices",
          (const char *)(a2 + 112));
        hw_info = -22;
        goto LABEL_127;
      }
      v29 = *v28;
      if ( !*v28 || !*((_QWORD *)v29 + 11) )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_mgr_init_devs",
          9705,
          "[%s] invalid interface: iface=%pK process_cmd=%pK",
          a2 + 112);
        hw_info = -22;
        goto LABEL_127;
      }
      v30 = *v29;
      if ( (unsigned int)v30 >= 5 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_mgr_init_devs",
          9713,
          "[%s] Invalid HW type:%u",
          (const char *)(a2 + 112),
          v30);
        hw_info = -22;
        goto LABEL_127;
      }
      v31 = v29[1];
      if ( (unsigned int)v31 <= 0x7FFFFFFE )
      {
        v32 = (&v65)[v30];
        v33 = v31 + 1;
        while ( *v32 )
        {
          --v33;
          ++v32;
          if ( !v33 )
            goto LABEL_86;
        }
        *v32 = (__int64)v29;
      }
LABEL_86:
      v34 = *(unsigned int *)(a2 + 44184);
      v35 = *((_DWORD *)v28 + 2);
      if ( (unsigned int)(v35 + v34) > 0xA )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_mgr_init_devs",
          9730,
          "Num of PIDs may go beyond the threshold, current num_pid: %d, num_pid in the dev: %d, threshold: %d",
          v34,
          v35,
          10);
        hw_info = -22;
        goto LABEL_127;
      }
      if ( v35 )
      {
        v36 = 0;
        while ( (unsigned int)(v34 + v36) <= 9 )
        {
          v37 = v28[2][v36];
          *(_DWORD *)(a2 + 44184) = v34 + v36 + 1;
          *(_DWORD *)(a2 + 44188 + 4 * v34 + 4 * v36++) = v37;
          if ( (unsigned int)v36 >= *((_DWORD *)v28 + 2) )
            goto LABEL_91;
        }
LABEL_124:
        __break(0x5512u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v54 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &cam_icp_mgr_set_up_dev_info__alloc_tag_621;
        v40 = _kvmalloc_node_noprof(584LL * *(unsigned int *)(a2 + 64), 0, 3520, 0xFFFFFFFFLL);
        *(_QWORD *)(StatusReg + 80) = v54;
        *(_QWORD *)(a2 + 56) = v40;
        if ( !v40 )
        {
LABEL_125:
          hw_info = -12;
          goto LABEL_126;
        }
LABEL_108:
        v41 = v63;
        if ( (_DWORD)v63 )
        {
          v42 = v67;
          *(_BYTE *)(a2 + 70) = 0;
          *(_QWORD *)(v40 + 16) = v42;
          **(_QWORD **)(a2 + 56) = "IPE";
          *(_DWORD *)(*(_QWORD *)(a2 + 56) + 8LL) = 2;
          *(_DWORD *)(*(_QWORD *)(a2 + 56) + 580LL) = v63;
          v41 = 1;
        }
        else
        {
          *(_BYTE *)(a2 + 70) = -1;
        }
        if ( HIDWORD(v63) )
        {
          v47 = v68;
          v48 = *(_QWORD *)(a2 + 56) + 584LL * v41;
          *(_BYTE *)(a2 + 71) = v41;
          v49 = 584LL * v41;
          *(_QWORD *)(v48 + 16) = v47;
          *(_QWORD *)(*(_QWORD *)(a2 + 56) + v49) = "BPS";
          *(_DWORD *)(*(_QWORD *)(a2 + 56) + v49 + 8) = 3;
          ++v41;
          *(_DWORD *)(*(_QWORD *)(a2 + 56) + v49 + 580) = HIDWORD(v63);
        }
        else
        {
          *(_BYTE *)(a2 + 71) = -1;
        }
        if ( v64 )
        {
          v50 = v69;
          v51 = *(_QWORD *)(a2 + 56) + 584LL * v41;
          *(_BYTE *)(a2 + 72) = v41;
          hw_info = 0;
          v52 = 584LL * v41;
          *(_QWORD *)(v51 + 16) = v50;
          *(_QWORD *)(*(_QWORD *)(a2 + 56) + v52) = "OFE";
          *(_DWORD *)(*(_QWORD *)(a2 + 56) + v52 + 8) = 4;
          *(_DWORD *)(*(_QWORD *)(a2 + 56) + v52 + 580) = v64;
        }
        else
        {
          hw_info = 0;
          *(_BYTE *)(a2 + 72) = -1;
        }
        goto LABEL_4;
      }
LABEL_91:
      if ( ++v25 == hw_info )
        goto LABEL_92;
    }
    v43 = v59;
    v44 = "[%s] missing node %s";
    v45 = a2 + 112;
    v46 = 9677;
LABEL_113:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_init_devs",
      v46,
      v44,
      v45,
      v43);
    hw_info = -19;
    goto LABEL_127;
  }
LABEL_92:
  v38 = v65;
  if ( !v65 )
    v38 = v66;
  v39 = *v38;
  *(_QWORD *)(a2 + 80) = v39;
  if ( v39 )
  {
    if ( (_DWORD)v63 )
      ++*(_DWORD *)(a2 + 64);
    if ( HIDWORD(v63) )
      ++*(_DWORD *)(a2 + 64);
    if ( v64 )
      ++*(_DWORD *)(a2 + 64);
    if ( mem_trace_en == 1 )
    {
      v40 = cam_mem_trace_alloc(584LL * *(unsigned int *)(a2 + 64), 0xCC0u, 0, "cam_icp_mgr_set_up_dev_info", 0x2591u);
      *(_QWORD *)(a2 + 56) = v40;
      if ( !v40 )
        goto LABEL_125;
    }
    else
    {
      v40 = _kvmalloc_node_noprof(584LL * *(unsigned int *)(a2 + 64), 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(a2 + 56) = v40;
      if ( !v40 )
        goto LABEL_125;
    }
    goto LABEL_108;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_mgr_set_up_dev_info",
    9606,
    "[%s] Invalid ICP dev interface is NULL",
    (const char *)(a2 + 112));
  hw_info = -22;
LABEL_126:
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_mgr_init_devs",
    9743,
    "Failed to set up hw device info rc=%d",
    hw_info);
LABEL_127:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v65, 0);
  else
    kvfree(v65);
  if ( (mem_trace_en & 1) != 0 )
    cam_mem_trace_free(v66, 0);
  else
    kvfree(v66);
  if ( (mem_trace_en & 1) != 0 )
    cam_mem_trace_free(v67, 0);
  else
    kvfree(v67);
  if ( (mem_trace_en & 1) != 0 )
    cam_mem_trace_free(v68, 0);
  else
    kvfree(v68);
  if ( (mem_trace_en & 1) != 0 )
    cam_mem_trace_free(v69, 0);
  else
    kvfree(v69);
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return hw_info;
}
