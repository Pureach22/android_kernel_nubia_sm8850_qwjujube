__int64 __fastcall cam_icp_mgr_send_init_config_io(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 v7; // x1
  unsigned int v8; // w0
  unsigned int v9; // w21
  unsigned int v10; // w9
  unsigned int v11; // w10
  __int64 v12; // x0
  const char *v13; // x5
  __int64 v14; // x6
  __int64 v15; // x4
  __int64 v16; // x22
  unsigned int v17; // w23
  __int64 v18; // x0
  int *task; // x0
  unsigned int v20; // w8
  int v21; // w9
  int v22; // w8
  int *v23; // x21
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x8
  int v27; // w9
  unsigned int *v28; // x0
  unsigned int v29; // w10
  _QWORD *v30; // x23
  __int64 v31; // x8
  __int16 v32; // w9
  unsigned int v33; // w0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x21
  __int64 v37; // x1
  __int64 v38; // x23
  __int64 v39; // x0
  __int64 v40; // x24
  __int64 v41; // x1
  __int64 v42; // x25
  int v43; // w0
  __int64 v44; // x21
  unsigned int (__fastcall *v45)(__int64, __int64, __int64 *, __int64); // x8
  __int64 v46; // x0
  const char *v47; // x5
  __int64 v48; // x6
  __int64 v49; // x4
  __int64 v50; // x0
  unsigned __int64 v51; // x20
  int v52; // w22
  __int64 v53; // t2
  __int64 cpu_buf; // x0
  __int64 v56; // x28
  __int64 v57; // x25
  unsigned int v58; // w26
  size_t v59; // [xsp+28h] [xbp-248h] BYREF
  const void *v60; // [xsp+30h] [xbp-240h] BYREF
  __int64 v61; // [xsp+38h] [xbp-238h] BYREF
  __int64 v62; // [xsp+40h] [xbp-230h] BYREF
  __int64 v63; // [xsp+48h] [xbp-228h] BYREF
  __int64 v64; // [xsp+50h] [xbp-220h]
  __int64 v65; // [xsp+58h] [xbp-218h]
  _QWORD s[66]; // [xsp+60h] [xbp-210h] BYREF

  s[64] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(unsigned int *)(a3 + 12);
  v7 = *(unsigned int *)(a1 + 148);
  v59 = 0;
  v60 = nullptr;
  v64 = 0;
  v65 = 0;
  v63 = 0;
  v8 = ((__int64 (__fastcall *)(__int64, __int64, const void **, size_t *, _QWORD, _QWORD))cam_mem_get_io_buf)(
         v6,
         v7,
         &v60,
         &v59,
         0,
         0);
  if ( v8 )
  {
    v9 = v8;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_send_init_config_io",
      8757,
      "%s: unable to get src buf info from io desc",
      (const char *)(a2 + 29824));
LABEL_53:
    _ReadStatusReg(SP_EL0);
    return v9;
  }
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_mgr_send_init_config_io",
      8763,
      "%s: hdl: %d, addr: %pK, size: %zu",
      (const char *)(a2 + 29824),
      *(_DWORD *)(a3 + 12),
      v60,
      v59);
  v11 = *(_DWORD *)(a3 + 8);
  v10 = *(_DWORD *)(a3 + 12);
  HIDWORD(v63) = 1;
  v64 = v10;
  v65 = v11;
  v12 = cam_icp_process_stream_settings(a2, &v63, 1);
  if ( (_DWORD)v12 )
  {
    v9 = v12;
    v13 = "%s: sending config io mapping failed rc %d";
    v14 = a2 + 29824;
    v15 = 8775;
LABEL_8:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_send_init_config_io",
      v15,
      v13,
      v14,
      v9);
    goto LABEL_53;
  }
  if ( (cam_presil_mode_enabled(v12) & 1) != 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x8000000,
      3,
      "cam_icp_mgr_send_init_config_io",
      8782,
      "%s: Sending IO Config buffers to presil: FD %d",
      (const char *)(a2 + 29824),
      *(__int16 *)(a3 + 14));
    cam_mem_mgr_send_buffer_to_presil();
  }
  v16 = *(_QWORD *)(a2 + 8);
  v17 = (unsigned int)v60;
  v18 = *(_QWORD *)(v16 + 992);
  memset(s, 0, 40);
  task = cam_req_mgr_workq_get_task(v18);
  if ( !task )
  {
    if ( (unsigned int)__ratelimit(&cam_icp_mgr_send_config_io__rs, "cam_icp_mgr_send_config_io") )
      v25 = 3;
    else
      v25 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      v25,
      256,
      1,
      "cam_icp_mgr_send_config_io",
      6101,
      "%s: No free cmd task",
      a2 + 29824);
    goto LABEL_44;
  }
  v20 = *(_DWORD *)(*(_QWORD *)(a2 + 16) + 8LL) - 2;
  if ( v20 >= 3 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_send_config_io",
      6120,
      "%s Invalid hw dev type not supported: %u",
      a2 + 29824);
    v9 = -22;
    goto LABEL_45;
  }
  v21 = dword_452050[v20];
  v22 = dword_452068[v20];
  *(_DWORD *)(a2 + 29192) = 0;
  v23 = task;
  HIDWORD(s[0]) = v22;
  LODWORD(s[1]) = v21;
  if ( mem_trace_en == 1 )
    v24 = cam_mem_trace_alloc(24, 0x820u, 0, "cam_icp_mgr_send_config_io", 0x17EEu);
  else
    v24 = _kvmalloc_node_noprof(24, 0, 2336, 0xFFFFFFFFLL);
  v26 = v24;
  if ( !v24 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_send_config_io",
      6128,
      "Failed in allocating memory for ICP ctx info");
LABEL_44:
    v9 = -12;
    goto LABEL_45;
  }
  v27 = *(_DWORD *)(a2 + 29224);
  *(_QWORD *)(v24 + 16) = a2;
  v28 = (unsigned int *)v23;
  *(_BYTE *)v26 = 0;
  *(_DWORD *)(v26 + 4) = v27;
  v29 = *(_DWORD *)(a2 + 72);
  HIDWORD(s[3]) = 1;
  *(_QWORD *)((char *)&s[1] + 4) = v26;
  s[4] = __PAIR64__(v17, v29);
  v30 = (_QWORD *)v26;
  *(_QWORD *)((char *)&s[2] + 4) = 0;
  v31 = *((_QWORD *)v23 + 1);
  LODWORD(s[0]) = 40;
  *(_DWORD *)v31 = 2;
  v32 = debug_mdl;
  *(_QWORD *)(v31 + 8) = s;
  *(_DWORD *)(v31 + 16) = 0;
  *((_QWORD *)v23 + 2) = cam_icp_mgr_process_cmd;
  if ( (v32 & 0x100) != 0 && !debug_priority )
  {
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v32 & 0x100,
      4,
      "cam_icp_mgr_send_config_io",
      6149,
      "%s: size_in_words %u",
      (const char *)(a2 + 29824),
      **(_DWORD **)(v31 + 8) >> 2);
    v28 = (unsigned int *)v23;
  }
  v33 = cam_req_mgr_workq_enqueue_task(v28, v16, 0);
  if ( !v33 )
  {
    v35 = ktime_get_with_offset(1);
    v36 = ns_to_timespec64(v35);
    v38 = v37;
    if ( cam_common_wait_for_completion_timeout(a2 + 29192) )
    {
      v9 = cam_icp_process_stream_settings(a2, &v63, 0);
      if ( !v9 )
        goto LABEL_53;
      v13 = "%s: sending config io unmapping failed %d";
      v14 = a2 + 29824;
      v15 = 8801;
      goto LABEL_8;
    }
    v39 = ktime_get_with_offset(1);
    v40 = ns_to_timespec64(v39);
    v42 = v41;
    v43 = jiffies_to_msecs(1250, v41);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_send_config_io",
      6163,
      "%s: FW response timeout for send IO cfg handle command on (timeout: %ums start: timestamp:[%lld:%06lld] end: times"
      "tamp:[%lld:%06lld])",
      (const char *)(a2 + 29824),
      v43,
      v36,
      v38 / 1000,
      v40,
      v42 / 1000);
    v44 = *(_QWORD *)(v16 + 80);
    if ( v44 )
    {
      LODWORD(v62) = 1;
      cam_icp_mgr_process_dbg_buf(v16);
      cam_hfi_queue_dump(*(unsigned int *)(v16 + 156), 0);
      v45 = *(unsigned int (__fastcall **)(__int64, __int64, __int64 *, __int64))(v44 + 88);
      v46 = *(_QWORD *)(v44 + 112);
      if ( *((_DWORD *)v45 - 1) != -1055839300 )
        __break(0x8228u);
      if ( !v45(v46, 15, &v62, 4) )
        goto LABEL_42;
      v47 = "[%s] Fail to dump debug info";
      v48 = v16 + 112;
      v49 = 219;
    }
    else
    {
      v47 = "[%s] ICP device interface is NULL";
      v48 = v16 + 112;
      v49 = 208;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_dump_debug_info",
      v49,
      v47,
      v48);
LABEL_42:
    v9 = -121;
    goto LABEL_45;
  }
  v9 = v33;
  if ( (unsigned int)__ratelimit(&cam_icp_mgr_send_config_io__rs_361, "cam_icp_mgr_send_config_io") )
    v34 = 3;
  else
    v34 = 2;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    v34,
    256,
    1,
    "cam_icp_mgr_send_config_io",
    6154,
    "%s: Failed to enqueue io config task",
    a2 + 29824);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v30, 0);
  else
    kvfree(v30);
LABEL_45:
  if ( (unsigned int)__ratelimit(&cam_icp_mgr_send_init_config_io__rs, "cam_icp_mgr_send_init_config_io") )
    v50 = 3;
  else
    v50 = 2;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    v50,
    256,
    1,
    "cam_icp_mgr_send_init_config_io",
    8791,
    "%s: IO Config command failed %d size:%d",
    (const char *)(a2 + 29824),
    v9,
    *(_DWORD *)(a3 + 8));
  v53 = a3 + 8;
  v51 = *(unsigned int *)(a3 + 8);
  v52 = *(_DWORD *)(v53 + 4);
  v61 = 0;
  v62 = 0;
  memset(s, 0, 0x200u);
  cpu_buf = cam_mem_get_cpu_buf(v52, &v62, &v61);
  if ( (_DWORD)cpu_buf )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_dump_io_cfg",
      91,
      "%s: Unable to get io_cfg buf address",
      (const char *)(a2 + 29824));
LABEL_52:
    cam_icp_process_stream_settings(a2, &v63, 0);
    goto LABEL_53;
  }
  if ( (unsigned int)v51 < 4 )
  {
LABEL_51:
    cam_mem_put_cpu_buf(v52);
    goto LABEL_52;
  }
  v56 = v62;
  v57 = 0;
  v58 = 0;
  while ( v58 < 0x201 )
  {
    cpu_buf = snprintf((char *)s + v58, 512LL - v58, "0X%08X-", *(_DWORD *)(v56 + 4 * v57));
    if ( (v57 & 7) != 0 )
    {
      v58 += cpu_buf;
    }
    else
    {
      v58 = 0;
      if ( (debug_mdl & 0x100) != 0 && !debug_priority )
      {
        cpu_buf = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 0x100,
                    4,
                    "cam_icp_dump_io_cfg",
                    101,
                    "%s: %s",
                    "cam_icp_dump_io_cfg",
                    (const char *)s);
        v58 = 0;
      }
    }
    if ( v51 >> 2 == ++v57 )
      goto LABEL_51;
  }
  __break(0x5512u);
  return cam_icp_ctx_clk_info_init(cpu_buf);
}
