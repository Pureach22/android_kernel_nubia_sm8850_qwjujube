__int64 __fastcall cam_irq_controller_subscribe_irq(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        _QWORD *a8,
        unsigned int a9)
{
  char v12; // w26
  __int64 v17; // x0
  __int64 result; // x0
  unsigned int *v19; // x20
  __int64 v20; // x0
  __int64 v21; // x8
  unsigned int *v22; // x24
  unsigned int *v23; // x23
  unsigned int v24; // w11
  unsigned int v25; // w8
  __int64 v26; // x8
  __int64 v27; // x9
  unsigned __int64 StatusReg; // x22
  __int64 v29; // x25
  __int64 v30; // x27
  unsigned int v31; // w26
  __int64 v32; // x8
  unsigned int v33; // w9
  int v34; // w10
  __int64 v35; // x0
  unsigned int *v36; // x1
  __int64 v37; // x2
  __int64 v38; // x8
  __int64 v39; // x2
  unsigned int *v40; // x1
  __int64 v41; // [xsp+10h] [xbp-10h]

  if ( !a3 || !a1 || !a4 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, __int64))cam_print_log)(
      3,
      0x800000,
      1,
      "cam_irq_controller_subscribe_irq",
      572,
      "Inval params: ctlr=%pK hdl_priv=%pK bit_mask_arr=%pK",
      a1,
      a4,
      a3);
    return 4294967274LL;
  }
  if ( !a5 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x800000,
      1,
      "cam_irq_controller_subscribe_irq",
      577,
      "Missing top half handler");
    return 4294967274LL;
  }
  if ( a6 )
  {
    if ( !a7 || !a8 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, _QWORD *))cam_print_log)(
        3,
        0x800000,
        1,
        "cam_irq_controller_subscribe_irq",
        587,
        "Invalid params: bh_handler=%pK bh=%pK bh_enq_f=%pK",
        a6,
        a7,
        a8);
      return 4294967274LL;
    }
  }
  else if ( !a8 )
  {
    v12 = 1;
    if ( a2 < 5 )
      goto LABEL_16;
LABEL_22:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x800000,
      1,
      "cam_irq_controller_subscribe_irq",
      605,
      "Invalid priority=%u, max=%u",
      a2,
      5);
    return 4294967274LL;
  }
  if ( !*a8 || !a8[1] || !a8[2] )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _QWORD))cam_print_log)(
      3,
      0x800000,
      1,
      "cam_irq_controller_subscribe_irq",
      599,
      "Invalid: enqueue_func=%pK get_bh=%pK put_bh=%pK",
      *a8,
      a8[1],
      a8[2]);
    return 4294967274LL;
  }
  v12 = 0;
  if ( a2 >= 5 )
    goto LABEL_22;
LABEL_16:
  if ( mem_trace_en == 1 )
    v17 = cam_mem_trace_alloc(112, 0xCC0u, 0, "cam_irq_controller_subscribe_irq", 0x261u);
  else
    v17 = _kvmalloc_node_noprof(112, 0, 3520, 0xFFFFFFFFLL);
  v19 = (unsigned int *)v17;
  if ( !v17 )
  {
    result = 4294967284LL;
    if ( (debug_mdl & 0x800000) == 0 || debug_priority )
      return result;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x800000,
      4,
      "cam_irq_controller_subscribe_irq",
      611,
      "Error allocating hlist_node");
    return 4294967284LL;
  }
  if ( mem_trace_en == 1 )
    v20 = cam_mem_trace_alloc(4LL * *(unsigned int *)(a1 + 24), 0xCC0u, 0, "cam_irq_controller_subscribe_irq", 0x268u);
  else
    v20 = _kvmalloc_node_noprof(4LL * *(unsigned int *)(a1 + 24), 0, 3520, 0xFFFFFFFFLL);
  *((_QWORD *)v19 + 1) = v20;
  if ( !v20 )
  {
    if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x800000,
        4,
        "cam_irq_controller_subscribe_irq",
        618,
        "Error allocating hlist_node");
      if ( (mem_trace_en & 1) != 0 )
        goto LABEL_41;
    }
    else if ( (mem_trace_en & 1) != 0 )
    {
LABEL_41:
      cam_mem_trace_free(v19, 0);
      return 4294967284LL;
    }
    kvfree(v19);
    return 4294967284LL;
  }
  v21 = a6;
  v22 = v19 + 18;
  v23 = v19 + 22;
  *((_QWORD *)v19 + 9) = v19 + 18;
  *((_QWORD *)v19 + 10) = v19 + 18;
  *((_QWORD *)v19 + 11) = v19 + 22;
  *((_QWORD *)v19 + 12) = v19 + 22;
  if ( *(_DWORD *)(a1 + 24) )
  {
    v24 = 0;
    do
    {
      *(_DWORD *)(*((_QWORD *)v19 + 1) + 4LL * (int)v24) = *(_DWORD *)(a3 + 4LL * (int)v24);
      ++v24;
    }
    while ( v24 < *(_DWORD *)(a1 + 24) );
  }
  *v19 = a2;
  *((_QWORD *)v19 + 2) = a4;
  *((_QWORD *)v19 + 3) = a5;
  *((_QWORD *)v19 + 4) = v21;
  *((_QWORD *)v19 + 5) = a7;
  v25 = *(_DWORD *)(a1 + 168);
  *(_DWORD *)(a1 + 168) = v25 + 1;
  v19[26] = v25;
  v19[27] = a9;
  if ( (v12 & 1) == 0 )
  {
    v27 = a8[1];
    v26 = a8[2];
    *((_QWORD *)v19 + 6) = *a8;
    *((_QWORD *)v19 + 7) = v27;
    *((_QWORD *)v19 + 8) = v26;
  }
  if ( *(_DWORD *)(a1 + 168) >> 30 )
    *(_DWORD *)(a1 + 168) = 1;
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    v41 = 0;
  else
    v41 = raw_spin_lock_irqsave(a1 + 320);
  v29 = *v19;
  if ( (int)v29 <= 4 && *(_DWORD *)(a1 + 24) )
  {
    if ( (unsigned int)v29 > 4 )
    {
      __break(0x5512u);
      goto LABEL_63;
    }
    v30 = *((_QWORD *)v19 + 1);
    v31 = 0;
    do
    {
      v32 = *(_QWORD *)(a1 + 32) + 112LL * (int)v31;
      *(_DWORD *)(v32 + 4 * v29 + 32) |= *(_DWORD *)(v30 + 4LL * (int)v31);
      v33 = *(_DWORD *)(v30 + 4LL * (int)v31);
      v34 = *(_DWORD *)(v32 + 52);
      *(_BYTE *)(v32 + 108) = 1;
      v35 = v34 | v33;
      *(_DWORD *)(v32 + 52) = v35;
      cam_io_w_mb(v35, *(_QWORD *)(a1 + 16) + *(unsigned int *)(v32 + 4));
      ++v31;
    }
    while ( v31 < *(_DWORD *)(a1 + 24) );
  }
  v36 = *(unsigned int **)(a1 + 80);
  v37 = a1 + 72;
  if ( v19 != (unsigned int *)a1 && v36 != v22 && *(_QWORD *)v36 == v37 )
  {
    *(_QWORD *)(a1 + 80) = v22;
    *((_QWORD *)v19 + 9) = v37;
    *((_QWORD *)v19 + 10) = v36;
    *(_QWORD *)v36 = v22;
    goto LABEL_52;
  }
LABEL_63:
  _list_add_valid_or_report(v19 + 18);
LABEL_52:
  v38 = a1 + 16LL * a2;
  v39 = v38 + 88;
  v40 = *(unsigned int **)(v38 + 96);
  if ( v23 == (unsigned int *)(v38 + 88) || v40 == v23 || *(_QWORD *)v40 != v39 )
  {
    _list_add_valid_or_report(v19 + 22);
  }
  else
  {
    *(_QWORD *)(v38 + 96) = v23;
    *((_QWORD *)v19 + 11) = v39;
    *((_QWORD *)v19 + 12) = v40;
    *(_QWORD *)v40 = v23;
  }
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 )
    raw_spin_unlock_irqrestore(a1 + 320, v41);
  return v19[26];
}
