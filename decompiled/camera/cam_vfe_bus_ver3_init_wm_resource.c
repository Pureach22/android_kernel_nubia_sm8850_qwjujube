__int64 __fastcall cam_vfe_bus_ver3_init_wm_resource(
        unsigned int a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        _QWORD *a5,
        const char *a6,
        int a7,
        __int64 a8)
{
  _QWORD *v8; // x27
  __int64 v17; // x0
  unsigned __int64 v18; // x8
  int v19; // w8
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x8
  int v23; // w9
  __int64 v24; // x8
  __int64 result; // x0
  const char *v26; // x5
  __int64 v27; // x6
  __int64 v28; // x1
  __int64 v29; // x2
  __int64 v30; // x4
  __int64 v31; // x20
  unsigned __int64 StatusReg; // x28
  __int64 v33; // [xsp+8h] [xbp-8h]

  v8 = &unk_2FD000;
  if ( mem_trace_en == 1 )
  {
    v17 = cam_mem_trace_alloc(168, 0xCC0u, 0, "cam_vfe_bus_ver3_init_wm_resource", 0x642u);
    if ( v17 )
    {
LABEL_5:
      while ( 1 )
      {
        v18 = *(_QWORD *)(a3 + 488);
        if ( v18 )
        {
          if ( ((v18 >> a1) & 1) == 0 )
            break;
        }
        if ( (*(_BYTE *)(a8 + 133) & 1) != 0 || *(_BYTE *)(a8 + 134) == 1 )
        {
          v19 = *((unsigned __int8 *)v8 + 2904);
          v8 = (_QWORD *)v17;
          v20 = v19 == 1
              ? cam_mem_trace_alloc(240, 0xCC0u, 0, "cam_vfe_bus_ver3_init_wm_resource", 0x655u)
              : _kvmalloc_node_noprof(240, 0, 3520, 0xFFFFFFFFLL);
          v21 = v20;
          v17 = (__int64)v8;
          v8[8] = v21;
          if ( !v21 )
          {
            v26 = "VFE:%u Failed to alloc for WM res mc data";
            v27 = *(unsigned int *)(*(_QWORD *)(a2 + 24) + 4LL);
            v28 = 8;
            v29 = 1;
            v30 = 1624;
            goto LABEL_25;
          }
        }
        *(_QWORD *)(a4 + 24) = v17;
        *(_DWORD *)(v17 + 120) = a1;
        *(_DWORD *)(v17 + 152) = a7;
        *(_QWORD *)v17 = a2;
        *(_QWORD *)(v17 + 56) = a8;
        if ( a1 < 0x21 )
        {
          v22 = a3 + 240LL * a1;
          *a5 = *(_QWORD *)(a2 + 34752) + 152LL * *(unsigned int *)(v22 + 640);
          *(_DWORD *)(a4 + 8) = 1;
          *(_QWORD *)(a4 + 32) = a4 + 32;
          *(_QWORD *)(a4 + 40) = a4 + 32;
          *(_QWORD *)(a4 + 88) = cam_vfe_bus_ver3_start_wm;
          *(_QWORD *)(a4 + 96) = cam_vfe_bus_ver3_stop_wm;
          *(_QWORD *)(a4 + 112) = cam_vfe_bus_ver3_handle_wm_done_top_half;
          *(_QWORD *)(a4 + 120) = cam_vfe_bus_ver3_handle_wm_done_bottom_half;
          *(_QWORD *)(a4 + 16) = *(_QWORD *)(a2 + 24);
          if ( *(_BYTE *)(a3 + 8944) == 1 )
          {
            v23 = *(_DWORD *)(a3 + 8916) + *(_DWORD *)(a3 + 8936) + *(_DWORD *)(a3 + 8920) * *(_DWORD *)(v17 + 120);
            v24 = a3 + 240;
          }
          else
          {
            v23 = 0;
            v24 = v22 + 504;
          }
          *(_DWORD *)(v17 + 156) = v23;
          *(_QWORD *)(v17 + 8) = v24;
          if ( a6 )
            scnprintf(a4 + 128, 16, "%s", a6);
          return 0;
        }
        __break(0x5512u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v33 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &cam_vfe_bus_ver3_init_wm_resource__alloc_tag;
        v17 = _kvmalloc_node_noprof(168, 0, 3520, 0xFFFFFFFFLL);
        *(_QWORD *)(StatusReg + 80) = v33;
        if ( !v17 )
          goto LABEL_27;
      }
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v31 = v17;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_ver3_init_wm_resource",
          1613,
          "VFE:%u WM %d  not supported, supported_mask 0x%x",
          *(_DWORD *)(*(_QWORD *)(a2 + 24) + 4LL),
          a1,
          v18);
        v17 = v31;
      }
      *(_DWORD *)(v17 + 120) = a1;
      *(_QWORD *)(a4 + 24) = v17;
      return 0;
    }
  }
  else
  {
    v17 = _kvmalloc_node_noprof(168, 0, 3520, 0xFFFFFFFFLL);
    if ( v17 )
      goto LABEL_5;
  }
LABEL_27:
  result = 4294967284LL;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v26 = "VFE:%u Failed to alloc for WM res priv";
    v28 = debug_mdl & 8;
    v27 = *(unsigned int *)(*(_QWORD *)(a2 + 24) + 4LL);
    v29 = 4;
    v30 = 1605;
LABEL_25:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      v28,
      v29,
      "cam_vfe_bus_ver3_init_wm_resource",
      v30,
      v26,
      v27);
    return 4294967284LL;
  }
  return result;
}
