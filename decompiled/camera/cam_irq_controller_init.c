__int64 __fastcall cam_irq_controller_init(const char *a1, __int64 a2, unsigned int *a3, __int64 *a4)
{
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x19
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  size_t v17; // x0
  unsigned __int64 v18; // x2
  __int64 *v19; // x8
  __int64 v20; // x9
  int v21; // w10
  unsigned int v22; // w11
  int v23; // w26
  __int64 v24; // x11
  __int64 v25; // x13
  int v26; // w10
  __int64 v27; // x1
  int v28; // w11
  unsigned int v29; // w6
  __int64 v30; // x1
  unsigned int v31; // w10
  int v32; // w9
  unsigned __int64 StatusReg; // x24
  __int64 v34; // x25
  _QWORD *v35; // x0
  _QWORD *v36; // x0
  __int64 v37; // [xsp+8h] [xbp-8h]
  __int64 v38; // [xsp+8h] [xbp-8h]
  __int64 v39; // [xsp+8h] [xbp-8h]
  __int64 v40; // [xsp+8h] [xbp-8h]

  *a4 = 0;
  if ( !*a3 || !a2 || !a1 || !*((_QWORD *)a3 + 1) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x800000,
      1,
      "cam_irq_controller_init",
      382,
      "Invalid parameters");
    return 4294967274LL;
  }
  if ( mem_trace_en == 1 )
    v8 = cam_mem_trace_alloc(328, 0xCC0u, 0, "cam_irq_controller_init", 0x183u);
  else
    v8 = _kvmalloc_node_noprof(328, 0, 3520, 0xFFFFFFFFLL);
  v10 = v8;
  if ( !v8 )
  {
LABEL_62:
    result = 4294967284LL;
    if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x800000,
        4,
        "cam_irq_controller_init",
        389,
        "Failed to allocate IRQ Controller");
      return 4294967284LL;
    }
    return result;
  }
  while ( 1 )
  {
    if ( mem_trace_en == 1 )
    {
      v11 = cam_mem_trace_alloc(112LL * *a3, 0xCC0u, 0, "cam_irq_controller_init", 0x18Au);
      *(_QWORD *)(v10 + 32) = v11;
      if ( !v11 )
        goto LABEL_65;
    }
    else
    {
      v12 = _kvmalloc_node_noprof(112LL * *a3, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(v10 + 32) = v12;
      if ( !v12 )
      {
LABEL_65:
        if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 0x800000,
            4,
            "cam_irq_controller_init",
            396,
            "Failed to allocate IRQ register Arr");
        goto LABEL_80;
      }
    }
    if ( mem_trace_en == 1 )
    {
      v13 = cam_mem_trace_alloc(4LL * *a3, 0xCC0u, 0, "cam_irq_controller_init", 0x192u);
      *(_QWORD *)(v10 + 40) = v13;
      if ( !v13 )
        goto LABEL_68;
    }
    else
    {
      v14 = _kvmalloc_node_noprof(4LL * *a3, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(v10 + 40) = v14;
      if ( !v14 )
      {
LABEL_68:
        if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 0x800000,
            4,
            "cam_irq_controller_init",
            404,
            "Failed to allocate IRQ status Arr");
LABEL_77:
        v36 = *(_QWORD **)(v10 + 32);
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v36, 0);
        else
          kvfree(v36);
LABEL_80:
        if ( mem_trace_en == 1 )
          cam_mem_trace_free((_QWORD *)v10, 0);
        else
          kvfree(v10);
        return 4294967284LL;
      }
    }
    if ( mem_trace_en != 1 )
    {
      v16 = _kvmalloc_node_noprof(4LL * *a3, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(v10 + 192) = v16;
      if ( v16 )
        goto LABEL_23;
LABEL_71:
      if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 0x800000,
          4,
          "cam_irq_controller_init",
          414,
          "Failed to allocate BH payload bit mask Arr");
      v35 = *(_QWORD **)(v10 + 40);
      if ( (mem_trace_en & 1) != 0 )
        cam_mem_trace_free(v35, 0);
      else
        kvfree(v35);
      goto LABEL_77;
    }
    v15 = cam_mem_trace_alloc(4LL * *a3, 0xCC0u, 0, "cam_irq_controller_init", 0x19Bu);
    *(_QWORD *)(v10 + 192) = v15;
    if ( !v15 )
      goto LABEL_71;
LABEL_23:
    v17 = strnlen(a1, 0x10u);
    if ( v17 != -1 )
      break;
    _fortify_panic(2, -1, 0);
LABEL_61:
    _fortify_panic(7, 16, v18);
    StatusReg = _ReadStatusReg(SP_EL0);
    v34 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_irq_controller_init__alloc_tag;
    v10 = _kvmalloc_node_noprof(328, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v34;
    if ( !v10 )
      goto LABEL_62;
  }
  if ( v17 == 16 )
    v18 = 16;
  else
    v18 = v17 + 1;
  if ( v18 >= 0x11 )
    goto LABEL_61;
  sized_strscpy(v10, a1);
  if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x800000,
      4,
      "cam_irq_controller_init",
      421,
      "num_registers: %d",
      *a3);
  v19 = a4;
  v20 = a2;
  if ( *a3 )
  {
    v21 = 0;
    while ( 1 )
    {
      v23 = v21;
      v24 = 112LL * v21;
      v25 = 28LL * v21;
      *(_DWORD *)(*(_QWORD *)(v10 + 32) + v24) = v21;
      *(_DWORD *)(*(_QWORD *)(v10 + 32) + v24 + 4) = *(_DWORD *)(*((_QWORD *)a3 + 1) + v25);
      *(_DWORD *)(*(_QWORD *)(v10 + 32) + v24 + 8) = *(_DWORD *)(*((_QWORD *)a3 + 1) + v25 + 4);
      *(_DWORD *)(*(_QWORD *)(v10 + 32) + v24 + 12) = *(_DWORD *)(*((_QWORD *)a3 + 1) + v25 + 8);
      *(_DWORD *)(*(_QWORD *)(v10 + 32) + v24 + 16) = *(_DWORD *)(*((_QWORD *)a3 + 1) + v25 + 12);
      *(_DWORD *)(*(_QWORD *)(v10 + 32) + v24 + 20) = *(_DWORD *)(*((_QWORD *)a3 + 1) + v25 + 16);
      *(_DWORD *)(*(_QWORD *)(v10 + 32) + v24 + 24) = *(_DWORD *)(*((_QWORD *)a3 + 1) + v25 + 20);
      *(_DWORD *)(*(_QWORD *)(v10 + 32) + v24 + 28) = *(_DWORD *)(*((_QWORD *)a3 + 1) + v25 + 24);
      *(_BYTE *)(*(_QWORD *)(v10 + 32) + v24 + 108) = 1;
      v26 = debug_priority;
      v27 = debug_mdl & 0x800000;
      if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
      {
        v38 = v20;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v27,
          4,
          "cam_irq_controller_init",
          440,
          "i %d mask_reg_offset: 0x%x",
          v23,
          *(_DWORD *)(*(_QWORD *)(v10 + 32) + 112LL * v23 + 4));
        v20 = v38;
        v19 = a4;
        v26 = debug_priority;
        v27 = debug_mdl & 0x800000;
        if ( (debug_mdl & 0x800000) == 0 )
          goto LABEL_39;
      }
      else if ( !v27 )
      {
        goto LABEL_39;
      }
      if ( !v26 )
      {
        v39 = v20;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v27,
          4,
          "cam_irq_controller_init",
          442,
          "i %d clear_reg_offset: 0x%x",
          v23,
          *(_DWORD *)(*(_QWORD *)(v10 + 32) + 112LL * v23 + 8));
        v20 = v39;
        v19 = a4;
        v26 = debug_priority;
        v27 = debug_mdl & 0x800000;
      }
LABEL_39:
      if ( v27 && !v26 )
      {
        v40 = v20;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v27,
          4,
          "cam_irq_controller_init",
          444,
          "i %d status_reg_offset: 0x%x",
          v23,
          *(_DWORD *)(*(_QWORD *)(v10 + 32) + 112LL * v23 + 12));
        v20 = v40;
        v19 = a4;
        v26 = debug_priority;
        v27 = debug_mdl & 0x800000;
        if ( (debug_mdl & 0x800000) != 0 )
        {
LABEL_42:
          if ( !v26 )
          {
            v37 = v20;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v27,
              4,
              "cam_irq_controller_init",
              446,
              "i %d set_reg_offset: 0x%x",
              v23,
              *(_DWORD *)(*(_QWORD *)(v10 + 32) + 112LL * v23 + 16));
            v20 = v37;
            v19 = a4;
          }
        }
      }
      else if ( v27 )
      {
        goto LABEL_42;
      }
      v22 = *a3;
      v21 = v23 + 1;
      if ( v23 + 1 >= *a3 )
        goto LABEL_49;
    }
  }
  v22 = 0;
LABEL_49:
  *(_DWORD *)(v10 + 24) = v22;
  v28 = debug_mdl;
  v29 = a3[5];
  v30 = debug_mdl & 0x800000;
  *(_DWORD *)(v10 + 52) = v29;
  *(_DWORD *)(v10 + 48) = a3[4];
  *(_DWORD *)(v10 + 56) = a3[6];
  v31 = a3[7];
  *(_QWORD *)(v10 + 16) = v20;
  v32 = debug_priority;
  *(_BYTE *)(v10 + 324) = 0;
  *(_DWORD *)(v10 + 60) = v31;
  *(_DWORD *)(v10 + 68) = -1;
  if ( (v28 & 0x800000) != 0 && !v32 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v30,
      4,
      "cam_irq_controller_init",
      458,
      "global_clear_bitmask: 0x%x",
      v29);
    v32 = debug_priority;
    v19 = a4;
    v30 = debug_mdl & 0x800000;
    if ( (debug_mdl & 0x800000) != 0 )
      goto LABEL_52;
  }
  else if ( v30 )
  {
LABEL_52:
    if ( !v32 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v30,
        4,
        "cam_irq_controller_init",
        460,
        "global_irq_cmd_offset: 0x%x",
        *(_DWORD *)(v10 + 48));
      v32 = debug_priority;
      v19 = a4;
      v30 = debug_mdl & 0x800000;
    }
  }
  if ( v30 && !v32 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v30,
      4,
      "cam_irq_controller_init",
      462,
      "mem_base: %pK",
      *(const void **)(v10 + 16));
    v19 = a4;
  }
  *(_QWORD *)(v10 + 72) = v10 + 72;
  *(_QWORD *)(v10 + 80) = v10 + 72;
  *(_QWORD *)(v10 + 88) = v10 + 88;
  *(_QWORD *)(v10 + 96) = v10 + 88;
  *(_QWORD *)(v10 + 104) = v10 + 104;
  *(_QWORD *)(v10 + 112) = v10 + 104;
  *(_QWORD *)(v10 + 120) = v10 + 120;
  *(_QWORD *)(v10 + 128) = v10 + 120;
  *(_QWORD *)(v10 + 136) = v10 + 136;
  *(_QWORD *)(v10 + 144) = v10 + 136;
  *(_QWORD *)(v10 + 152) = v10 + 152;
  *(_QWORD *)(v10 + 160) = v10 + 152;
  *(_DWORD *)(v10 + 168) = 1;
  *(_DWORD *)(v10 + 320) = 0;
  *v19 = v10;
  return 0;
}
