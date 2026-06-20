__int64 __fastcall cam_ipe_process_cmd(__int64 a1, int a2, __int64 a3)
{
  const char *v3; // x5
  __int64 v4; // x4
  __int64 result; // x0
  __int64 *v6; // x21
  __int64 v7; // x19
  int updated; // w0
  int v9; // w6
  __int64 v10; // x26
  int v11; // w20
  __int64 v12; // x19
  __int64 v13; // x1
  __int64 v14; // x25
  __int64 v15; // x5
  int v16; // w0
  int v17; // w8
  __int64 v18; // x25
  unsigned int v19; // w20
  int v20; // w8
  int v21; // w0
  unsigned int v22; // w19
  int v23; // w0
  unsigned int v24; // w19
  __int64 v25; // x25
  int v26; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v27; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v28; // [xsp+8h] [xbp-18h] BYREF
  __int64 v29; // [xsp+10h] [xbp-10h]
  __int64 v30; // [xsp+18h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_ipe_process_cmd",
      338,
      "Invalid arguments");
    goto LABEL_6;
  }
  if ( (unsigned int)a2 >= 9 )
  {
    v3 = "Invalid command : %x";
    v4 = 343;
LABEL_4:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      256,
      1,
      "cam_ipe_process_cmd",
      v4,
      v3,
      (unsigned int)a2);
LABEL_6:
    result = 4294967274LL;
    goto LABEL_7;
  }
  v6 = *(__int64 **)(a1 + 3680);
  if ( a2 <= 3 )
  {
    switch ( a2 )
    {
      case 0:
        result = ((__int64 (*)(void))cam_ipe_handle_pc)();
        goto LABEL_7;
      case 1:
        result = ((__int64 (*)(void))cam_ipe_handle_resume)();
        goto LABEL_7;
      case 3:
        if ( !a3 )
          goto LABEL_6;
        if ( *(_DWORD *)(a3 + 624) )
        {
          v7 = a3;
          updated = cam_cpas_update_ahb_vote(*((_DWORD *)v6 + 2), a3);
          a3 = v7;
          v9 = updated;
        }
        else
        {
          v9 = 0;
        }
        if ( *(_DWORD *)(a3 + 628) )
          v9 = cam_cpas_update_axi_vote(*((_DWORD *)v6 + 2), a3 + 16);
        if ( v9 )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x2000000,
            1,
            "cam_ipe_cpas_vote",
            42,
            "cpas vote is failed: %d",
            v9);
LABEL_42:
        result = 0;
        goto LABEL_7;
    }
    goto LABEL_25;
  }
  if ( a2 <= 5 )
  {
    if ( a2 == 4 )
    {
      if ( !a3 )
        goto LABEL_6;
      if ( (v6[2] & 1) == 0 )
      {
        result = cam_cpas_start(*((_DWORD *)v6 + 2), a3, a3 + 16);
        *((_BYTE *)v6 + 16) = 1;
        goto LABEL_7;
      }
    }
    else if ( *((_BYTE *)v6 + 16) == 1 )
    {
      cam_cpas_stop(*((_DWORD *)v6 + 2));
      result = 0;
      *((_BYTE *)v6 + 16) = 0;
      goto LABEL_7;
    }
    goto LABEL_42;
  }
  if ( a2 != 6 )
  {
    if ( a2 == 7 )
    {
      if ( *((_BYTE *)v6 + 17) == 1 )
        cam_ipe_toggle_clk(a1 + 96, 0);
      result = 0;
      *((_BYTE *)v6 + 17) = 0;
      goto LABEL_7;
    }
LABEL_25:
    v3 = "Invalid Cmd Type:%u";
    v4 = 451;
    goto LABEL_4;
  }
  v10 = *v6;
  v11 = *(_DWORD *)a3;
  v12 = a1;
  v28 = 0;
  v29 = 0;
  v13 = debug_mdl & 0x2000100;
  v26 = 0;
  v27 = v11;
  if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
  {
    v25 = a3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v13,
      4,
      "cam_ipe_process_cmd",
      394,
      "ipe_src_clk rate = %d",
      v11);
    a1 = v12;
    a3 = v25;
    if ( (*((_BYTE *)v6 + 17) & 1) == 0 )
      goto LABEL_32;
  }
  else if ( (*((_BYTE *)v6 + 17) & 1) == 0 )
  {
LABEL_32:
    v14 = a3;
    if ( *(_BYTE *)(a3 + 8) == 1 )
    {
      cam_ipe_handle_pc(v12, v13);
      cam_cpas_reg_write(*((_DWORD *)v6 + 2), 0, *(_DWORD *)(v10 + 4), 1, 0, v15);
      a1 = v12;
    }
    if ( (unsigned int)cam_ipe_toggle_clk(a1 + 96, 1) )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        256,
        1,
        "cam_ipe_process_cmd",
        404,
        "Enable failed");
    else
      *((_BYTE *)v6 + 17) = 1;
    a3 = v14;
    a1 = v12;
    if ( *(_BYTE *)(v14 + 8) == 1 )
    {
      v16 = cam_ipe_handle_resume(v12);
      a3 = v14;
      v17 = v16;
      a1 = v12;
      if ( v17 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          256,
          1,
          "cam_ipe_process_cmd",
          410,
          "bps resume failed");
        a1 = v12;
        a3 = v14;
      }
    }
  }
  v18 = a3;
  if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x2000100,
      4,
      "cam_ipe_process_cmd",
      413,
      "clock rate %d",
      v11);
    a1 = v12;
  }
  v19 = ((__int64 (__fastcall *)(__int64, unsigned int *))cam_ipe_update_clk_rate)(a1 + 96, &v27);
  if ( v19 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x2000000,
      1,
      "cam_ipe_process_cmd",
      417,
      "Failed to update clk %d",
      v27);
  if ( !(unsigned int)cam_soc_util_get_clk_level((_BYTE *)(v12 + 96), v27, *(_DWORD *)(v12 + 2892), &v26) )
  {
    v20 = v26;
    LODWORD(v28) = 0;
    *(_DWORD *)(v18 + 4) = v26;
    LODWORD(v29) = v20;
    v21 = cam_cpas_update_ahb_vote(*((_DWORD *)v6 + 2), (__int64)&v28);
    if ( v21 )
    {
      v22 = v21;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x2000000,
        1,
        "cam_ipe_process_cmd",
        431,
        "failed at updating ahb vote level rc: %d",
        v21);
      result = v22;
      goto LABEL_7;
    }
    v23 = cam_cpas_update_axi_floor_lvl(*((_DWORD *)v6 + 2), v26);
    if ( v23 )
    {
      v24 = v23;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x2000000,
        1,
        "cam_ipe_process_cmd",
        439,
        "failed at updating axi vote level clk_level: %d rc: %d",
        v26,
        v23);
      result = v24;
      goto LABEL_7;
    }
    v19 = 0;
  }
  result = v19;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
