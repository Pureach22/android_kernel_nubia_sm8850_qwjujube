__int64 __fastcall cam_isp_dev_component_bind(__int64 a1)
{
  unsigned int v2; // w0
  const char **v3; // x19
  size_t v4; // x0
  int v5; // w20
  __int64 v6; // x1
  int v7; // w3
  unsigned int v8; // w19
  size_t v9; // x0
  unsigned int v10; // w8
  int v11; // w9
  __int64 v12; // x0
  __int64 v13; // x20
  __int64 v14; // x0
  __int64 v15; // x0
  size_t v16; // x0
  unsigned int v17; // w0
  __int64 result; // x0
  __int64 v19; // x27
  __int64 v20; // x28
  __int64 v21; // x21
  unsigned int v22; // w0
  unsigned int v23; // w0
  const char *v24; // x5
  __int64 v25; // x4
  unsigned int v26; // w0
  const char *v27; // x3
  _QWORD v28[2]; // [xsp+8h] [xbp-1A8h] BYREF
  _QWORD v29[2]; // [xsp+18h] [xbp-198h] BYREF
  unsigned int v30; // [xsp+2Ch] [xbp-184h] BYREF
  char *s; // [xsp+30h] [xbp-180h] BYREF
  __int64 v32; // [xsp+38h] [xbp-178h] BYREF
  __int64 v33; // [xsp+40h] [xbp-170h]
  __int64 v34; // [xsp+48h] [xbp-168h]
  __int64 v35; // [xsp+50h] [xbp-160h]
  __int64 v36; // [xsp+58h] [xbp-158h]
  __int64 v37; // [xsp+60h] [xbp-150h]
  __int64 v38; // [xsp+68h] [xbp-148h]
  __int64 v39; // [xsp+70h] [xbp-140h]
  __int64 v40; // [xsp+78h] [xbp-138h]
  __int64 v41; // [xsp+80h] [xbp-130h]
  __int64 v42; // [xsp+88h] [xbp-128h]
  __int64 v43; // [xsp+90h] [xbp-120h]
  __int64 v44; // [xsp+98h] [xbp-118h]
  __int64 v45; // [xsp+A0h] [xbp-110h]
  __int64 v46; // [xsp+A8h] [xbp-108h]
  __int64 v47; // [xsp+B0h] [xbp-100h]
  __int64 v48; // [xsp+B8h] [xbp-F8h]
  __int64 v49; // [xsp+C0h] [xbp-F0h]
  __int64 v50; // [xsp+C8h] [xbp-E8h]
  __int64 v51; // [xsp+D0h] [xbp-E0h]
  __int64 v52; // [xsp+D8h] [xbp-D8h]
  _QWORD v53[9]; // [xsp+E0h] [xbp-D0h] BYREF
  __int64 (__fastcall *v54)(); // [xsp+128h] [xbp-88h]
  void *v55; // [xsp+130h] [xbp-80h]
  __int64 v56; // [xsp+138h] [xbp-78h]
  __int64 v57; // [xsp+140h] [xbp-70h]
  __int64 v58; // [xsp+148h] [xbp-68h]
  __int64 v59; // [xsp+150h] [xbp-60h]
  __int64 v60; // [xsp+158h] [xbp-58h]
  __int64 v61; // [xsp+160h] [xbp-50h]
  __int64 v62; // [xsp+168h] [xbp-48h]
  __int64 v63; // [xsp+170h] [xbp-40h]
  __int64 v64; // [xsp+178h] [xbp-38h]
  __int64 v65; // [xsp+180h] [xbp-30h]
  __int64 v66; // [xsp+188h] [xbp-28h]
  __int64 v67; // [xsp+190h] [xbp-20h]
  __int64 v68; // [xsp+198h] [xbp-18h]
  __int64 v69; // [xsp+1A0h] [xbp-10h]

  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  s = nullptr;
  v32 = 0;
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  v55 = nullptr;
  v56 = 0;
  v54 = nullptr;
  memset(v53, 0, sizeof(v53));
  v30 = -1;
  v29[0] = 0;
  v29[1] = 0;
  v28[0] = 0;
  v28[1] = 0;
  ktime_get_real_ts64(v29);
  v2 = of_property_read_string_helper(*(_QWORD *)(a1 + 744), "arch-compat", &s, 1, 0);
  if ( (v2 & 0x80000000) != 0 )
  {
    v8 = v2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_dev_component_bind",
      196,
      "Error: failed to read arch-compat");
LABEL_53:
    result = v8;
    goto LABEL_54;
  }
  v3 = (const char **)(a1 - 16);
  qword_3A8AE0 = (__int64)&cam_isp_subdev_internal_ops;
  dword_3A8B20 = 0;
  v4 = strlen(s);
  if ( strnstr(s, "ife", v4) )
  {
    v5 = 65538;
    v6 = (__int64)v3;
    v7 = 65538;
LABEL_7:
    v10 = cam_subdev_probe((__int64)&g_isp_dev, v6, (__int64)"cam-isp", v7);
    v11 = 8;
    v12 = 4416;
    goto LABEL_8;
  }
  v9 = strlen(s);
  if ( strnstr(s, "mc_tfe", v9) )
  {
    v5 = 65555;
    v6 = (__int64)v3;
    v7 = 65555;
    goto LABEL_7;
  }
  v16 = strlen(s);
  if ( !strnstr(s, "tfe", v16) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_dev_component_bind",
      220,
      "Invalid ISP hw type %s",
      s);
    result = 4294967274LL;
    goto LABEL_54;
  }
  v5 = 65552;
  v10 = cam_subdev_probe((__int64)&g_isp_dev, (__int64)v3, (__int64)"cam-isp", 65552);
  qword_3A8B08 = (__int64)cam_isp_subdev_handle_message;
  v11 = 4;
  v12 = 2208;
LABEL_8:
  dword_3A8B6C = v5;
  dword_3A8B70 = v11;
  if ( v10 )
  {
    v8 = v10;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_dev_component_bind",
      226,
      "ISP cam_subdev_probe failed!");
    goto LABEL_53;
  }
  v32 = 0;
  v33 = 0;
  v13 = qword_3A8AF8;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  v38 = 0;
  v39 = 0;
  v40 = 0;
  v41 = 0;
  v42 = 0;
  v43 = 0;
  v44 = 0;
  v45 = 0;
  v46 = 0;
  v47 = 0;
  v48 = 0;
  v49 = 0;
  v50 = 0;
  v51 = 0;
  v52 = 0;
  if ( mem_trace_en == 1 )
  {
    v14 = cam_mem_trace_alloc(v12, 0xCC0u, 0, "cam_isp_dev_component_bind", 0xEAu);
  }
  else
  {
    if ( !is_mul_ok(dword_3A8B70, 0x228u) )
    {
      qword_3A8B28 = 0;
      goto LABEL_45;
    }
    v14 = _kvmalloc_node_noprof(552LL * dword_3A8B70, 0, 3520, 0xFFFFFFFFLL);
  }
  qword_3A8B28 = v14;
  if ( !v14 )
  {
LABEL_45:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_dev_component_bind",
      237,
      "Mem Allocation failed for ISP base context");
LABEL_51:
    v8 = -12;
LABEL_52:
    cam_subdev_remove((void **)&g_isp_dev);
    goto LABEL_53;
  }
  if ( mem_trace_en == 1 )
  {
    v15 = cam_mem_trace_alloc(45768LL * dword_3A8B70, 0xCC0u, 0, "cam_isp_dev_component_bind", 0xF4u);
  }
  else
  {
    if ( !is_mul_ok(dword_3A8B70, 0xB2C8u) )
    {
      qword_3A8B30 = 0;
      goto LABEL_47;
    }
    v15 = _kvmalloc_node_noprof(45768LL * dword_3A8B70, 0, 3520, 0xFFFFFFFFLL);
  }
  qword_3A8B30 = v15;
  if ( !v15 )
  {
LABEL_47:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_dev_component_bind",
      247,
      "Mem Allocation failed for Isp private context");
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)qword_3A8B28, 0);
    else
      kvfree(qword_3A8B28);
    qword_3A8B28 = 0;
    goto LABEL_51;
  }
  v17 = cam_isp_hw_mgr_init(s, (__int64)&v32, (__int64)&v30, dword_3A8B6C);
  if ( v17 )
  {
    v8 = v17;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_dev_component_bind",
      257,
      "Can not initialized ISP HW manager!");
LABEL_33:
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)qword_3A8B28, 0);
    else
      kvfree(qword_3A8B28);
    qword_3A8B28 = 0;
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)qword_3A8B30, 0);
    else
      kvfree(qword_3A8B30);
    qword_3A8B30 = 0;
    goto LABEL_52;
  }
  if ( dword_3A8B70 >= 1 )
  {
    v19 = 0;
    v20 = 0;
    v21 = 0;
    while ( 1 )
    {
      v22 = cam_isp_context_init(
              qword_3A8B30 + v19,
              qword_3A8B28 + v20,
              v13 + 280,
              v13 + 112,
              (unsigned int)v21,
              (unsigned int)dword_3A8B6C,
              v30);
      if ( v22 )
        break;
      ++v21;
      v20 += 552;
      v19 += 45768;
      if ( v21 >= dword_3A8B70 )
        goto LABEL_29;
    }
    v8 = v22;
    v24 = "ISP context init failed!";
    v25 = 269;
    goto LABEL_32;
  }
LABEL_29:
  cam_common_register_evt_inject_cb((__int64)cam_isp_dev_evt_inject_cb, 0);
  v23 = ((__int64 (__fastcall *)(__int64, __int64 *, __int64, _QWORD, const char *))cam_node_init)(
          v13,
          &v32,
          qword_3A8B28,
          (unsigned int)dword_3A8B70,
          "cam-isp");
  if ( v23 )
  {
    v8 = v23;
    v24 = "ISP node init failed!";
    v25 = 281;
LABEL_32:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_dev_component_bind",
      v25,
      v24);
    goto LABEL_33;
  }
  v26 = v30;
  *(_QWORD *)(v13 + 336) = cam_isp_subdev_close_internal;
  cam_smmu_set_client_page_fault_handler(v26, (__int64)cam_isp_dev_iommu_fault_handler, v13);
  _mutex_init(&unk_3A8B38, "&g_isp_dev.isp_mutex", &cam_isp_dev_component_bind___key);
  v27 = *v3;
  LODWORD(v53[0]) = 40960;
  scnprintf((char *)v53 + 4, 64, "%s", v27);
  v54 = cam_isp_vmrm_callback_handler;
  v55 = &g_isp_dev;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_isp_dev_component_bind",
      303,
      "Component bound successfully");
  ktime_get_real_ts64(v28);
  cam_record_bind_latency();
  result = 0;
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return result;
}
