__int64 __fastcall cam_irq_controller_handle_irq(__int64 a1, __int64 a2, int a3)
{
  __int64 v5; // x8
  int v6; // w8
  int v7; // w21
  int v8; // w25
  int v9; // w28
  int v10; // w22
  int v11; // w23
  int v12; // w11
  const char *v13; // x13
  __int64 v14; // x9
  _DWORD *v15; // x27
  int v16; // w8
  int v17; // w10
  __int64 v18; // x24
  const char *v19; // x27
  __int64 v20; // x22
  int v21; // w8
  __int64 v22; // x1
  _QWORD *v23; // x25
  _QWORD *v24; // x27
  int v25; // w28
  __int64 v26; // x0
  _QWORD *v27; // x23
  int v28; // w8
  int v29; // w12
  __int64 v30; // x9
  unsigned int v31; // w8
  _DWORD *v32; // x8
  __int64 v33; // x0
  __int64 v34; // x1
  __int64 (__fastcall *v35)(__int64, __int64); // x8
  __int64 v36; // x0
  int v37; // w0
  _DWORD *v38; // x8
  __int64 v39; // x0
  __int64 v40; // x0
  void (__fastcall *v41)(__int64, __int64, __int64, __int64); // x8
  __int64 v42; // x2
  __int64 v43; // x3
  __int64 result; // x0
  const void *v45; // [xsp+18h] [xbp-28h]
  int v46; // [xsp+20h] [xbp-20h]
  char v47; // [xsp+24h] [xbp-1Ch]
  _QWORD v48[3]; // [xsp+28h] [xbp-18h] BYREF

  v48[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    result = 0;
    goto LABEL_99;
  }
  if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x800000,
      4,
      "cam_irq_controller_handle_irq",
      1138,
      "Locking: %s IRQ Controller: [%pK], lock handle: %pK",
      (const char *)a2,
      (const void *)a2,
      (const void *)(a2 + 320));
  v45 = (const void *)(a2 + 320);
  raw_spin_lock(a2 + 320);
  if ( (*(_BYTE *)(a2 + 324) & 1) == 0 )
  {
    memset(v48, 0, 13);
    _cam_irq_controller_read_registers(a2);
    if ( *(_DWORD *)(a2 + 64) )
    {
      cam_irq_controller_get_need_reg_read(a2, v48);
      cam_irq_controller_dep_reg_read(a2, v48);
    }
    v5 = *(unsigned int *)(a2 + 48);
    if ( (_DWORD)v5 )
    {
      if ( *(_BYTE *)(a2 + 325) == 1 )
      {
        cam_io_w_mb(*(unsigned int *)(a2 + 52), *(_QWORD *)(a2 + 16) + v5);
        if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x800000,
            4,
            "cam_irq_controller_read_registers",
            1095,
            "Delayed Global Clear done from %s",
            (const char *)a2);
      }
    }
  }
  v6 = *(_DWORD *)(a2 + 24);
  v47 = 0;
  v46 = 0;
  if ( v6 )
  {
    v7 = 0;
    v8 = 0;
    v9 = 0;
    v10 = 0;
    v11 = 0;
    v12 = 0;
    v13 = "reg:%d priority:%d need_th_processing = %d force_rd_mask: 0x%x";
    do
    {
      v14 = *(_QWORD *)(a2 + 40);
      v15 = (_DWORD *)(*(_QWORD *)(a2 + 32) + 112LL * v12);
      v16 = v15[7];
      v17 = v16 | *(_DWORD *)(v14 + 4LL * v12);
      if ( (v17 & v15[8]) != 0 )
      {
        v11 = 1;
        LOBYTE(v46) = 1;
      }
      v18 = v12;
      if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x800000,
          4,
          "cam_irq_controller_process_th",
          1115,
          "reg:%d priority:%d need_th_processing = %d force_rd_mask: 0x%x",
          v12,
          0,
          v11,
          v16);
        v14 = *(_QWORD *)(a2 + 40);
        v16 = v15[7];
        v13 = "reg:%d priority:%d need_th_processing = %d force_rd_mask: 0x%x";
        v17 = v16 | *(_DWORD *)(v14 + 4 * v18);
      }
      if ( (v15[9] & v17) != 0 )
      {
        v10 = 1;
        BYTE1(v46) = 1;
      }
      if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x800000,
          4,
          "cam_irq_controller_process_th",
          1115,
          "reg:%d priority:%d need_th_processing = %d force_rd_mask: 0x%x",
          v18,
          1,
          v10,
          v16);
        v14 = *(_QWORD *)(a2 + 40);
        v16 = v15[7];
        v13 = "reg:%d priority:%d need_th_processing = %d force_rd_mask: 0x%x";
        v17 = v16 | *(_DWORD *)(v14 + 4 * v18);
      }
      if ( (v15[10] & v17) != 0 )
      {
        v9 = 1;
        BYTE2(v46) = 1;
      }
      if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x800000,
          4,
          "cam_irq_controller_process_th",
          1115,
          "reg:%d priority:%d need_th_processing = %d force_rd_mask: 0x%x",
          v18,
          2,
          v9,
          v16);
        v14 = *(_QWORD *)(a2 + 40);
        v16 = v15[7];
        v13 = "reg:%d priority:%d need_th_processing = %d force_rd_mask: 0x%x";
      }
      if ( ((*(_DWORD *)(v14 + 4 * v18) | v16) & v15[11]) != 0 )
      {
        v8 = 1;
        HIBYTE(v46) = 1;
      }
      if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x800000,
          4,
          "cam_irq_controller_process_th",
          1115,
          "reg:%d priority:%d need_th_processing = %d force_rd_mask: 0x%x",
          v18,
          3,
          v8,
          v16);
        v14 = *(_QWORD *)(a2 + 40);
        v16 = v15[7];
        v13 = "reg:%d priority:%d need_th_processing = %d force_rd_mask: 0x%x";
      }
      if ( ((*(_DWORD *)(v14 + 4 * v18) | v16) & v15[12]) != 0 )
      {
        v7 = 1;
        v47 = 1;
      }
      if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
      {
        v19 = v13;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, int, int))cam_print_log)(
          3,
          debug_mdl & 0x800000,
          4,
          "cam_irq_controller_process_th",
          1115,
          v13,
          (unsigned int)v18,
          4,
          v7,
          v16);
        v13 = v19;
      }
      v12 = v18 + 1;
    }
    while ( (unsigned int)(v18 + 1) < *(_DWORD *)(a2 + 24) );
  }
  v20 = 0;
  while ( 2 )
  {
    if ( *((_BYTE *)&v46 + v20) != 1 )
      goto LABEL_42;
    v21 = debug_priority;
    v22 = debug_mdl & 0x800000;
    if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v22,
        4,
        "cam_irq_controller_process_th",
        1122,
        "(%s) Invoke TH processing priority:%d",
        (const char *)a2,
        v20);
      v21 = debug_priority;
      v22 = debug_mdl & 0x800000;
      v48[0] = 0;
      if ( (debug_mdl & 0x800000) != 0 )
      {
LABEL_47:
        if ( !v21 )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            v22,
            4,
            "__cam_irq_controller_th_processing",
            849,
            "Enter");
      }
    }
    else
    {
      v48[0] = 0;
      if ( v22 )
        goto LABEL_47;
    }
    v23 = (_QWORD *)(a2 + 88 + 16 * v20);
    v24 = (_QWORD *)*v23;
    if ( (_QWORD *)*v23 == v23 )
      goto LABEL_42;
    v25 = -22;
    do
    {
      v27 = (_QWORD *)*v24;
      if ( *((_DWORD *)v24 + 5) != a3 )
        goto LABEL_55;
      v28 = *(_DWORD *)(a2 + 24);
      if ( !v28 )
        goto LABEL_55;
      v29 = 0;
      while ( ((*(_DWORD *)(*(_QWORD *)(a2 + 32) + 112LL * v29 + 28) | *(_DWORD *)(*(_QWORD *)(a2 + 40) + 4LL * v29))
             & *(_DWORD *)(*(v24 - 10) + 4LL * v29)) == 0 )
      {
        if ( v28 == ++v29 )
          goto LABEL_55;
      }
      if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 0x800000,
          4,
          "__cam_irq_controller_th_processing",
          860,
          "match found");
        v28 = *(_DWORD *)(a2 + 24);
      }
      *(_QWORD *)(a2 + 176) = 0;
      *(_QWORD *)(a2 + 200) = 0;
      *(_BYTE *)(a2 + 208) = 0;
      v30 = *(v24 - 9);
      *(_DWORD *)(a2 + 184) = v28;
      *(_QWORD *)(a2 + 176) = v30;
      if ( v28 )
      {
        v31 = 0;
        do
        {
          *(_DWORD *)(*(_QWORD *)(a2 + 192) + 4LL * (int)v31) = *(_DWORD *)(*(v24 - 10) + 4LL * (int)v31)
                                                              & *(_DWORD *)(*(_QWORD *)(a2 + 40) + 4LL * (int)v31);
          ++v31;
        }
        while ( v31 < *(_DWORD *)(a2 + 24) );
      }
      v48[0] = 0;
      if ( *(v24 - 7) )
      {
        v32 = (_DWORD *)*(v24 - 4);
        v33 = *(v24 - 6);
        if ( *(v32 - 1) != -28199355 )
          __break(0x8228u);
        v25 = ((__int64 (__fastcall *)(__int64, _QWORD *))v32)(v33, v48);
        if ( v25 || (v34 = v48[0]) == 0 )
        {
          if ( (unsigned int)__ratelimit(&_cam_irq_controller_th_processing__rs, "__cam_irq_controller_th_processing") )
            v26 = 3;
          else
            v26 = 2;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            v26,
            8,
            1,
            "__cam_irq_controller_th_processing",
            880,
            "No payload, IRQ handling frozen for %s",
            (const char *)a2);
          goto LABEL_55;
        }
        v25 = 0;
        v35 = (__int64 (__fastcall *)(__int64, __int64))*(v24 - 8);
        if ( v35 )
        {
LABEL_76:
          v36 = **(unsigned int **)(a2 + 40);
          if ( *((_DWORD *)v35 - 1) != 814944108 )
            __break(0x8228u);
          v37 = v35(v36, a2 + 176);
          v34 = v48[0];
          v25 = v37;
        }
      }
      else
      {
        v34 = 0;
        v35 = (__int64 (__fastcall *)(__int64, __int64))*(v24 - 8);
        if ( v35 )
          goto LABEL_76;
      }
      if ( v25 && v34 )
      {
        v38 = (_DWORD *)*(v24 - 3);
        v39 = *(v24 - 6);
        if ( *(v38 - 1) != -972578753 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD *))v38)(v39, v48);
      }
      else if ( *(v24 - 7) )
      {
        if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x800000,
            4,
            "__cam_irq_controller_th_processing",
            902,
            "Enqueuing bottom half for %s",
            (const char *)a2);
          v34 = v48[0];
        }
        v40 = *(v24 - 6);
        v41 = (void (__fastcall *)(__int64, __int64, __int64, __int64))*(v24 - 5);
        v42 = *(v24 - 9);
        v43 = *(_QWORD *)(a2 + 200);
        if ( *((_DWORD *)v41 - 1) != -1968556866 )
          __break(0x8228u);
        v41(v40, v34, v42, v43);
      }
LABEL_55:
      v24 = v27;
    }
    while ( v27 != v23 );
    if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x800000,
        4,
        "__cam_irq_controller_th_processing",
        912,
        "Exit");
LABEL_42:
    if ( ++v20 != 5 )
      continue;
    break;
  }
  raw_spin_unlock(v45);
  result = 1;
  if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x800000,
      4,
      "cam_irq_controller_handle_irq",
      1149,
      "Unlocked: %s IRQ Controller: %pK, lock handle: %pK",
      (const char *)a2,
      (const void *)a2,
      v45);
    result = 1;
  }
LABEL_99:
  _ReadStatusReg(SP_EL0);
  return result;
}
