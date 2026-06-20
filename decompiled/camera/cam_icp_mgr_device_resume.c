__int64 __fastcall cam_icp_mgr_device_resume(__int64 a1, __int64 a2)
{
  const char **v2; // x25
  int v3; // w8
  unsigned int v4; // w20
  unsigned int v8; // w22
  __int64 v9; // x6
  _QWORD *v10; // x27
  _DWORD *v11; // x8
  __int64 v12; // x0
  _DWORD *v13; // x8
  __int64 v14; // x0
  const char *v15; // x5
  __int64 v16; // x4
  unsigned int v17; // w24
  int v18; // w22
  __int64 v19; // x0
  _QWORD *v20; // x23

  v2 = *(const char ***)(a2 + 16);
  v3 = *((_DWORD *)v2 + 144);
  v4 = *((_DWORD *)v2 + 2);
  *((_DWORD *)v2 + 144) = v3 + 1;
  if ( v3 )
    return 0;
  if ( *((_DWORD *)v2 + 145) )
  {
    v8 = 0;
    do
    {
      v10 = *(_QWORD **)&v2[2][8 * v8];
      if ( !v10 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_mgr_device_resume",
          1869,
          "Device intf for %s[%u] is NULL",
          *v2,
          v8);
        return 4294967274LL;
      }
      v11 = (_DWORD *)v10[2];
      v12 = v10[14];
      if ( *(v11 - 1) != 1989616049 )
        __break(0x8228u);
      if ( ((unsigned int (__fastcall *)(__int64, _QWORD, _QWORD))v11)(v12, 0, 0) )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_mgr_device_resume",
          1876,
          "Fail to resume device %s[%u]",
          *v2,
          v8);
      if ( *(_BYTE *)(a1 + 44231) == 1 )
      {
        v13 = (_DWORD *)v10[11];
        v14 = v10[14];
        if ( *(v13 - 1) != -1055839300 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v13)(v14, 1, 0, 0);
      }
      v9 = *((unsigned int *)v2 + 145);
      ++v8;
    }
    while ( v8 < (unsigned int)v9 );
    if ( (unsigned int)v9 >= 3 )
    {
      v15 = "%u devices core info mask is not supported";
      v16 = 1823;
      goto LABEL_26;
    }
  }
  else
  {
    LODWORD(v9) = 0;
  }
  if ( v4 - 3 < 2 )
  {
    v17 = 0;
    v18 = 1;
    goto LABEL_27;
  }
  if ( v4 == 2 )
  {
    v17 = 0;
    if ( (_DWORD)v9 == 2 )
      v18 = 196608;
    else
      v18 = 0x10000;
    goto LABEL_27;
  }
  v15 = "Invalid hw device type: %u";
  v16 = 1841;
  v9 = v4;
LABEL_26:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_mgr_get_core_info_mask",
    v16,
    v15,
    v9);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_mgr_device_resume",
    1888,
    "%s Fail to get core info mask for hw dev: %s ctx id: %u rc:%d",
    (const char *)(a2 + 29824),
    *v2,
    *(_DWORD *)(a2 + 29224),
    -22);
  v17 = -22;
  v18 = 0;
LABEL_27:
  if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x2000100,
      4,
      "cam_icp_mgr_device_resume",
      1892,
      "%s core_info 0x%x",
      (const char *)(a2 + 29824),
      v18);
  if ( mem_trace_en == 1 )
    v19 = cam_mem_trace_alloc(24, 0xCC0u, 0, "cam_icp_mgr_device_resume", 0x767u);
  else
    v19 = _kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
  v20 = (_QWORD *)v19;
  if ( v19 )
  {
    *(_QWORD *)v19 = 0x1000300000018LL;
    *(_DWORD *)(v19 + 8) = 1;
    if ( v4 - 2 >= 3 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_device_resume",
        1919,
        "%s Invalid hw dev type: %u",
        (const char *)(a2 + 29824),
        v4);
      v17 = -22;
    }
    else
    {
      *(_DWORD *)(v19 + 12) = dword_452020[v4 - 2];
      *(_DWORD *)(v19 + 16) = *(unsigned __int8 *)(a1 + 44231);
      *(_DWORD *)(v19 + 20) = v18;
      hfi_write_cmd(*(unsigned int *)(a1 + 156), v19);
    }
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v20, 0);
    else
      kvfree(v20);
    return v17;
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_device_resume",
      1898,
      "%s Allocate command prop failed",
      (const char *)(a2 + 29824));
    return 4294967284LL;
  }
}
