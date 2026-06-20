__int64 __fastcall cam_bps_process_cmd(__int64 a1, int a2, unsigned int *a3)
{
  const char *v3; // x5
  __int64 v4; // x4
  const char *v5; // x5
  __int64 v6; // x4
  __int64 result; // x0
  __int64 *v8; // x21
  unsigned int *v9; // x19
  int updated; // w0
  int v11; // w6
  __int64 v12; // x26
  __int64 v13; // x19
  __int64 v14; // x20
  __int64 v15; // x1
  unsigned int *v16; // x25
  __int64 v17; // x5
  int v18; // w8
  unsigned int v19; // w22
  int v20; // w0
  unsigned int v21; // w19
  int v22; // w0
  unsigned int v23; // w19
  unsigned int *v24; // x25
  int v25; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-18h] BYREF
  __int64 v27; // [xsp+10h] [xbp-10h]
  __int64 v28; // [xsp+18h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v5 = "Invalid arguments";
    v6 = 340;
    goto LABEL_6;
  }
  if ( (unsigned int)a2 >= 9 )
  {
    v3 = "Invalid command : %x";
    v4 = 345;
LABEL_4:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      256,
      1,
      "cam_bps_process_cmd",
      v4,
      v3,
      (unsigned int)a2);
LABEL_7:
    result = 4294967274LL;
    goto LABEL_8;
  }
  v8 = *(__int64 **)(a1 + 3680);
  if ( a2 <= 3 )
  {
    switch ( a2 )
    {
      case 0:
        result = ((__int64 (*)(void))cam_bps_handle_pc)();
        goto LABEL_8;
      case 1:
        result = ((__int64 (*)(void))cam_bps_handle_resume)();
        goto LABEL_8;
      case 3:
        if ( a3 )
        {
          if ( a3[156] )
          {
            v9 = a3;
            updated = cam_cpas_update_ahb_vote(*((_DWORD *)v8 + 2), (__int64)a3);
            a3 = v9;
            v11 = updated;
          }
          else
          {
            v11 = 0;
          }
          if ( a3[157] )
            v11 = cam_cpas_update_axi_vote(*((_DWORD *)v8 + 2), (__int64)(a3 + 4));
          if ( v11 < 0 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x2000000,
              1,
              "cam_bps_cpas_vote",
              43,
              "cpas vote is failed: %d",
              v11);
            result = 0;
            goto LABEL_8;
          }
          goto LABEL_44;
        }
        v5 = "cmd args NULL";
        v6 = 358;
        goto LABEL_6;
    }
    goto LABEL_26;
  }
  if ( a2 <= 5 )
  {
    if ( a2 != 4 )
    {
      if ( *((_BYTE *)v8 + 16) == 1 )
      {
        cam_cpas_stop(*((_DWORD *)v8 + 2));
        result = 0;
        *((_BYTE *)v8 + 16) = 0;
        goto LABEL_8;
      }
LABEL_44:
      result = 0;
      goto LABEL_8;
    }
    if ( a3 )
    {
      if ( (v8[2] & 1) == 0 )
      {
        result = cam_cpas_start(*((_DWORD *)v8 + 2), (__int64)a3, (__int64)(a3 + 4));
        *((_BYTE *)v8 + 16) = 1;
        goto LABEL_8;
      }
      goto LABEL_44;
    }
    v5 = "cmd args NULL";
    v6 = 370;
LABEL_6:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_bps_process_cmd",
      v6,
      v5);
    goto LABEL_7;
  }
  if ( a2 != 6 )
  {
    if ( a2 == 7 )
    {
      if ( *((_BYTE *)v8 + 17) == 1 )
        cam_bps_toggle_clk(a1 + 96, 0);
      result = 0;
      *((_BYTE *)v8 + 17) = 0;
      goto LABEL_8;
    }
LABEL_26:
    v3 = "Invalid Cmd Type:%u";
    v4 = 457;
    goto LABEL_4;
  }
  v12 = *v8;
  v13 = *a3;
  v14 = a1;
  v26 = 0;
  v27 = 0;
  v15 = debug_mdl & 0x2000100;
  v25 = 0;
  if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
  {
    v24 = a3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v15,
      4,
      "cam_bps_process_cmd",
      401,
      "bps_src_clk rate = %d",
      v13);
    a3 = v24;
    a1 = v14;
    if ( (*((_BYTE *)v8 + 17) & 1) == 0 )
      goto LABEL_33;
  }
  else if ( (*((_BYTE *)v8 + 17) & 1) == 0 )
  {
LABEL_33:
    v16 = a3;
    if ( *((_BYTE *)a3 + 8) == 1 )
    {
      cam_bps_handle_pc(v14, v15);
      cam_cpas_reg_write(*((_DWORD *)v8 + 2), 0, *(_DWORD *)(v12 + 4), 1, 0, v17);
      a1 = v14;
    }
    if ( (unsigned int)cam_bps_toggle_clk(a1 + 96, 1) )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        256,
        1,
        "cam_bps_process_cmd",
        412,
        "Enable failed");
    else
      *((_BYTE *)v8 + 17) = 1;
    a1 = v14;
    if ( *((_BYTE *)v16 + 8) == 1 )
    {
      v18 = cam_bps_handle_resume(v14);
      a1 = v14;
      if ( v18 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          256,
          1,
          "cam_bps_process_cmd",
          418,
          "BPS resume failed");
        a1 = v14;
      }
    }
  }
  if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x2000100,
      4,
      "cam_bps_process_cmd",
      421,
      "clock rate %d",
      v13);
    a1 = v14;
  }
  v19 = ((__int64 (__fastcall *)(__int64, _QWORD))cam_bps_update_clk_rate)(a1 + 96, (unsigned int)v13);
  if ( v19 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x2000000,
      1,
      "cam_bps_process_cmd",
      424,
      "Failed to update clk %d",
      v13);
  if ( !(unsigned int)cam_soc_util_get_clk_level((_BYTE *)(v14 + 96), v13, *(_DWORD *)(v14 + 2892), &v25) )
  {
    LODWORD(v26) = 0;
    LODWORD(v27) = v25;
    v20 = cam_cpas_update_ahb_vote(*((_DWORD *)v8 + 2), (__int64)&v26);
    if ( v20 )
    {
      v21 = v20;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x2000000,
        1,
        "cam_bps_process_cmd",
        437,
        "failed at updating ahb vote level rc: %d",
        v20);
      result = v21;
      goto LABEL_8;
    }
    v22 = cam_cpas_update_axi_floor_lvl(*((_DWORD *)v8 + 2), v25);
    if ( v22 )
    {
      v23 = v22;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x2000000,
        1,
        "cam_bps_process_cmd",
        445,
        "failed at updating axi vote level clk_level: %d rc: %d",
        v25,
        v22);
      result = v23;
      goto LABEL_8;
    }
    v19 = 0;
  }
  result = v19;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
