__int64 __fastcall cam_res_mgr_gpio_request(__int64 a1, unsigned int a2, __int64 a3, const char *a4)
{
  __int64 v8; // x1
  _QWORD *v9; // x9
  unsigned int v10; // w0
  __int64 *v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  unsigned int v14; // w21
  __int64 v15; // x1
  __int64 v16; // x2
  __int64 v17; // x3
  __int64 v18; // x22
  unsigned int v19; // w0
  __int64 v20; // x8
  int idx_from_shared_pctrl_gpio; // w0
  int v22; // w20

  mutex_lock(cam_res + 488);
  if ( cam_res && *(_BYTE *)(cam_res + 200) == 1 )
  {
    v8 = cam_res + 456;
    while ( 1 )
    {
      v8 = *(_QWORD *)v8;
      if ( v8 == cam_res + 456 )
        break;
      if ( *(_DWORD *)(v8 + 32) == a2 )
      {
        if ( !v8 )
          break;
        v9 = (_QWORD *)(v8 + 16);
        while ( 1 )
        {
          v9 = (_QWORD *)*v9;
          if ( v9 == (_QWORD *)(v8 + 16) )
            break;
          if ( v9[2] == a1 )
            goto LABEL_47;
        }
        v14 = cam_res_mgr_add_device(a1, v8);
        if ( v14 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x200000,
            1,
            "cam_res_mgr_gpio_request",
            539,
            "add device to gpio res list failed rc: %d",
            v14);
        goto LABEL_48;
      }
    }
  }
  if ( (debug_mdl & 0x200000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x200000,
      4,
      "cam_res_mgr_gpio_request",
      465,
      "gpio: %u not found in gpio_res list",
      a2);
  v10 = gpio_request_one(a2, a3, a4);
  if ( v10 )
  {
    v14 = v10;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x200000,
      1,
      "cam_res_mgr_gpio_request",
      469,
      "gpio %d:%s request fails rc = %d",
      a2,
      a4,
      v10);
    goto LABEL_48;
  }
  if ( !cam_res )
    goto LABEL_47;
  if ( *(_BYTE *)(cam_res + 200) != 1
    || (cam_res_mgr_gpio_is_in_shared_gpio(a2) & 1) == 0
    && (cam_res_mgr_gpio_is_in_shared_pctrl_gpio(a2, v15, v16, v17) & 1) == 0 )
  {
    goto LABEL_36;
  }
  if ( (debug_mdl & 0x200000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x200000,
      4,
      "cam_res_mgr_gpio_request",
      483,
      "gpio: %u is shared",
      a2);
  if ( mem_trace_en == 1 )
  {
    v18 = cam_mem_trace_alloc(40, 0xCC0u, 0, "cam_res_mgr_gpio_request", 0x1E5u);
    if ( v18 )
      goto LABEL_25;
LABEL_31:
    v14 = -12;
    goto LABEL_48;
  }
  v18 = _kvmalloc_node_noprof(40, 0, 3520, 0xFFFFFFFFLL);
  if ( !v18 )
    goto LABEL_31;
LABEL_25:
  *(_DWORD *)(v18 + 32) = a2;
  *(_DWORD *)(v18 + 36) = 0;
  *(_QWORD *)v18 = v18;
  *(_QWORD *)(v18 + 8) = v18;
  *(_QWORD *)(v18 + 16) = v18 + 16;
  *(_QWORD *)(v18 + 24) = v18 + 16;
  v19 = cam_res_mgr_add_device(a1, v18);
  if ( !v19 )
  {
    v12 = cam_res + 456;
    v11 = *(__int64 **)(cam_res + 464);
    if ( v18 == cam_res + 456 || v11 == (__int64 *)v18 || *v11 != v12 )
    {
      _list_add_valid_or_report(v18);
      v20 = cam_res;
      if ( !cam_res )
        goto LABEL_47;
LABEL_37:
      if ( *(_BYTE *)(v20 + 200) == 1 && (cam_res_mgr_gpio_is_in_shared_pctrl_gpio(a2, (__int64)v11, v12, v13) & 1) != 0 )
      {
        idx_from_shared_pctrl_gpio = cam_res_mgr_util_get_idx_from_shared_pctrl_gpio((_QWORD *)a2);
        if ( (debug_mdl & 0x200000) != 0 && !debug_priority )
        {
          v22 = idx_from_shared_pctrl_gpio;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x200000,
            4,
            "cam_res_mgr_gpio_request",
            511,
            "shared_pctrl_gpio is at idx: %d",
            idx_from_shared_pctrl_gpio);
          if ( (v22 & 0x80000000) == 0 )
            goto LABEL_42;
        }
        else if ( (idx_from_shared_pctrl_gpio & 0x80000000) == 0 )
        {
LABEL_42:
          cam_res_mgr_shared_pinctrl_select_state();
          v14 = 0;
          goto LABEL_48;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x200000,
          1,
          "cam_res_mgr_gpio_request",
          514,
          "pctrl_gpio: %u not found",
          a2);
        v14 = -22;
        goto LABEL_48;
      }
LABEL_47:
      v14 = 0;
      goto LABEL_48;
    }
    *(_QWORD *)(cam_res + 464) = v18;
    *(_QWORD *)v18 = v12;
    *(_QWORD *)(v18 + 8) = v11;
    *v11 = v18;
LABEL_36:
    v20 = cam_res;
    if ( !cam_res )
      goto LABEL_47;
    goto LABEL_37;
  }
  v14 = v19;
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)v18, 0);
  else
    kvfree(v18);
LABEL_48:
  mutex_unlock(cam_res + 488);
  return v14;
}
