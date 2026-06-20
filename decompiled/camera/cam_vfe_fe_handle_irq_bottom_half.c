__int64 __fastcall cam_vfe_fe_handle_irq_bottom_half(__int64 a1, __int64 a2)
{
  __int64 v2; // x24
  int v3; // w19
  int v4; // w21
  __int64 v5; // x25
  __int64 v6; // x0
  int v7; // w8
  __int64 result; // x0
  _DWORD *v9; // x8
  _QWORD *v10; // x24
  unsigned __int64 v11; // x21
  int v12; // w0
  bool v13; // cf
  int v14; // w0
  int v15; // w0
  int v16; // w0
  int v17; // w0
  int v18; // w0
  int v19; // w0
  int v20; // w0
  int v21; // w0
  int v22; // w0
  int v23; // w0
  int v24; // w0
  int v25; // w0
  int v26; // w0
  unsigned __int64 v27; // x21
  int v28; // w0
  unsigned __int64 v29; // x19
  int v30; // w0
  unsigned __int64 v31; // x19
  int v32; // w0
  char v33; // w8
  __int64 v34; // x20
  unsigned int v35; // w19
  __int64 v36; // x20
  __int64 v37; // x20
  __int64 v38; // x19
  __int64 v39; // x19
  __int64 v40; // x20

  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_fe_handle_irq_bottom_half",
      517,
      "Invalid params");
    return 0xFFFFFFFFLL;
  }
  v2 = *(_QWORD *)(a1 + 24);
  v3 = *(_DWORD *)(a2 + 16);
  v4 = *(_DWORD *)(a2 + 20);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v34 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_fe_handle_irq_bottom_half",
      528,
      "event ID, irq_status_0 = 0x%x",
      v3);
    a1 = v34;
  }
  if ( (*(_DWORD *)(*(_QWORD *)(v2 + 32) + 80LL) & v3) != 0 )
  {
    if ( *(_BYTE *)(v2 + 84) == 1 && *(_DWORD *)(v2 + 88) <= 2u )
    {
      v5 = a1;
      if ( (unsigned int)__ratelimit(&cam_vfe_fe_handle_irq_bottom_half__rs, "cam_vfe_fe_handle_irq_bottom_half") )
        v6 = 3;
      else
        v6 = 2;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        v6,
        8,
        3,
        "cam_vfe_fe_handle_irq_bottom_half",
        534,
        "Received SOF");
      a1 = v5;
      v7 = *(_DWORD *)(v2 + 88) + 1;
      *(_DWORD *)(v2 + 88) = v7;
      if ( v7 == 2 )
      {
        *(_BYTE *)(v2 + 84) = 0;
        *(_DWORD *)(v2 + 88) = 0;
      }
    }
    else if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v40 = a1;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_fe_handle_irq_bottom_half",
        544,
        "Received SOF");
      a1 = v40;
    }
  }
  v9 = *(_DWORD **)(v2 + 32);
  if ( (v9[21] & v3) != 0 && (debug_mdl & 8) != 0 && !debug_priority )
  {
    v36 = a1;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_fe_handle_irq_bottom_half",
      549,
      "Received EPOCH");
    v9 = *(_DWORD **)(v2 + 32);
    a1 = v36;
  }
  if ( (v9[22] & v3) != 0 && (debug_mdl & 8) != 0 && !debug_priority )
  {
    v37 = a1;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_fe_handle_irq_bottom_half",
      552,
      "Received REG_UPDATE_ACK");
    v9 = *(_DWORD **)(v2 + 32);
    a1 = v37;
  }
  if ( (v9[23] & v3) != 0 && (debug_mdl & 8) != 0 && !debug_priority )
  {
    v38 = a1;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_fe_handle_irq_bottom_half",
      555,
      "Received EOF");
    v9 = *(_DWORD **)(v2 + 32);
    a1 = v38;
  }
  if ( (v9[25] & v4) == 0 )
  {
    result = 0;
    v33 = debug_mdl;
    if ( (debug_mdl & 8) == 0 )
      return result;
    goto LABEL_51;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v39 = a1;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_fe_handle_irq_bottom_half",
      558,
      "Received ERROR");
    a1 = v39;
  }
  if ( (unsigned int)(*(_DWORD *)(a1 + 8) - 1) >= 2 )
  {
    v10 = *(_QWORD **)(a1 + 24);
    v11 = 2620;
    do
    {
      v12 = cam_io_r_mb(*v10 + v11);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_fe_reg_dump",
        372,
        "offset 0x%x val 0x%x",
        v11,
        v12);
      v13 = v11 >= 0xA8D;
      v11 += 4LL;
    }
    while ( !v13 );
    v14 = cam_io_r_mb(*v10 + 3596LL);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_fe_reg_dump",
      377,
      "offset 0x%x val 0x%x",
      3596,
      v14);
    v15 = cam_io_r_mb(*v10 + 3600LL);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_fe_reg_dump",
      377,
      "offset 0x%x val 0x%x",
      3600,
      v15);
    v16 = cam_io_r_mb(*v10 + 3604LL);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_fe_reg_dump",
      377,
      "offset 0x%x val 0x%x",
      3604,
      v16);
    v17 = cam_io_r_mb(*v10 + 3608LL);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_fe_reg_dump",
      377,
      "offset 0x%x val 0x%x",
      3608,
      v17);
    v18 = cam_io_r_mb(*v10 + 3612LL);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_fe_reg_dump",
      377,
      "offset 0x%x val 0x%x",
      3612,
      v18);
    v19 = cam_io_r_mb(*v10 + 3616LL);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_fe_reg_dump",
      377,
      "offset 0x%x val 0x%x",
      3616,
      v19);
    v20 = cam_io_r_mb(*v10 + 3620LL);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_fe_reg_dump",
      377,
      "offset 0x%x val 0x%x",
      3620,
      v20);
    v21 = cam_io_r_mb(*v10 + 3624LL);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_fe_reg_dump",
      377,
      "offset 0x%x val 0x%x",
      3624,
      v21);
    v22 = cam_io_r_mb(*v10 + 3628LL);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_fe_reg_dump",
      377,
      "offset 0x%x val 0x%x",
      3628,
      v22);
    v23 = cam_io_r_mb(*v10 + 3632LL);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_fe_reg_dump",
      377,
      "offset 0x%x val 0x%x",
      3632,
      v23);
    v24 = cam_io_r_mb(*v10 + 3636LL);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_fe_reg_dump",
      377,
      "offset 0x%x val 0x%x",
      3636,
      v24);
    v25 = cam_io_r_mb(*v10 + 3640LL);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_fe_reg_dump",
      377,
      "offset 0x%x val 0x%x",
      3640,
      v25);
    v26 = cam_io_r_mb(*v10 + 3644LL);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_fe_reg_dump",
      377,
      "offset 0x%x val 0x%x",
      3644,
      v26);
    v27 = 0x2000;
    do
    {
      v28 = cam_io_r_mb(*v10 + v27);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_fe_reg_dump",
        382,
        "offset 0x%x val 0x%x",
        v27,
        v28);
      v13 = v27 >= 0x20B5;
      v27 += 4LL;
    }
    while ( !v13 );
    v29 = 9472;
    do
    {
      v30 = cam_io_r_mb(*v10 + v29);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_fe_reg_dump",
        387,
        "offset 0x%x val 0x%x",
        v29,
        v30);
      v13 = v29 >= 0x2559;
      v29 += 4LL;
    }
    while ( !v13 );
    v31 = 9728;
    do
    {
      v32 = cam_io_r_mb(*v10 + v31);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_fe_reg_dump",
        392,
        "offset 0x%x val 0x%x",
        v31,
        v32);
      v13 = v31 >= 0x2659;
      v31 += 4LL;
    }
    while ( !v13 );
    cam_cpas_dump_camnoc_buff_fill_info();
  }
  result = 0xFFFFFFFFLL;
  v33 = debug_mdl;
  if ( (debug_mdl & 8) != 0 )
  {
LABEL_51:
    if ( !debug_priority )
    {
      v35 = result;
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v33 & 8,
        4,
        "cam_vfe_fe_handle_irq_bottom_half",
        564,
        "returing status = %d",
        result);
      return v35;
    }
  }
  return result;
}
