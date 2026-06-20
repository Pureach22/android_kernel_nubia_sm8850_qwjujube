__int64 __fastcall cam_ofe_process_cmd(__int64 a1, int a2, unsigned int *a3)
{
  const char *v3; // x5
  __int64 v4; // x4
  const char *v5; // x5
  __int64 v6; // x4
  __int64 result; // x0
  __int64 *v8; // x21
  unsigned int *v9; // x20
  int updated; // w19
  __int64 v11; // x26
  __int64 v12; // x19
  __int64 v13; // x20
  __int64 v14; // x1
  unsigned int *v15; // x25
  __int64 v16; // x5
  int v17; // w0
  int v18; // w8
  unsigned int *v19; // x25
  unsigned int v20; // w22
  int v21; // w8
  unsigned int v22; // w0
  const char *v23; // x5
  unsigned int v24; // w19
  __int64 v25; // x4
  unsigned int v26; // w0
  unsigned int *v27; // x25
  int v28; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v29; // [xsp+8h] [xbp-18h] BYREF
  __int64 v30; // [xsp+10h] [xbp-10h]
  __int64 v31; // [xsp+18h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v5 = "Invalid arguments";
    v6 = 334;
    goto LABEL_6;
  }
  if ( (unsigned int)a2 >= 9 )
  {
    v3 = "Invalid command : %x";
    v4 = 339;
LABEL_4:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      256,
      1,
      "cam_ofe_process_cmd",
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
        result = ((__int64 (*)(void))cam_ofe_handle_pc)();
        goto LABEL_8;
      case 1:
        result = ((__int64 (*)(void))cam_ofe_handle_resume)();
        goto LABEL_8;
      case 3:
        if ( a3 )
        {
          if ( a3[156] )
          {
            v9 = a3;
            updated = cam_cpas_update_ahb_vote(*((_DWORD *)v8 + 2), (__int64)a3);
            if ( updated )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x2000000,
                1,
                "cam_ofe_cpas_vote",
                39,
                "CPAS AHB vote failed rc:%d",
                updated);
            a3 = v9;
          }
          else
          {
            updated = 0;
          }
          if ( a3[157] )
            updated = cam_cpas_update_axi_vote(*((_DWORD *)v8 + 2), (__int64)(a3 + 4));
          if ( updated )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x2000000,
              1,
              "cam_ofe_cpas_vote",
              45,
              "CPAS AXI vote failed rc:%d",
              updated);
          goto LABEL_47;
        }
        v5 = "cmd args NULL";
        v6 = 352;
        goto LABEL_6;
    }
LABEL_28:
    v3 = "Invalid Cmd Type:%u";
    v4 = 454;
    goto LABEL_4;
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
LABEL_47:
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
      goto LABEL_47;
    }
    v5 = "cmd args NULL";
    v6 = 364;
LABEL_6:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_ofe_process_cmd",
      v6,
      v5);
    goto LABEL_7;
  }
  if ( a2 == 6 )
  {
    v11 = *v8;
    v12 = *a3;
    v13 = a1;
    v29 = 0;
    v30 = 0;
    v14 = debug_mdl & 0x2000100;
    v28 = 0;
    if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
    {
      v27 = a3;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v14,
        4,
        "cam_ofe_process_cmd",
        395,
        "ofe_src_clk rate = %d",
        v12);
      a1 = v13;
      a3 = v27;
      if ( (*((_BYTE *)v8 + 17) & 1) != 0 )
        goto LABEL_52;
    }
    else if ( (*((_BYTE *)v8 + 17) & 1) != 0 )
    {
      goto LABEL_52;
    }
    v15 = a3;
    if ( *((_BYTE *)a3 + 8) == 1 )
    {
      cam_ofe_handle_pc(v13, v14);
      cam_cpas_reg_write(*((_DWORD *)v8 + 2), 0, *(_DWORD *)(v11 + 4), 1, 0, v16);
      a1 = v13;
    }
    if ( (unsigned int)cam_ofe_toggle_clk(a1 + 96, 1) )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        256,
        1,
        "cam_ofe_process_cmd",
        406,
        "Enable failed");
    else
      *((_BYTE *)v8 + 17) = 1;
    a3 = v15;
    a1 = v13;
    if ( *((_BYTE *)v15 + 8) == 1 )
    {
      v17 = cam_ofe_handle_resume(v13);
      a3 = v15;
      v18 = v17;
      a1 = v13;
      if ( v18 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          256,
          1,
          "cam_ofe_process_cmd",
          412,
          "OFE resume failed");
        a1 = v13;
        a3 = v15;
      }
    }
LABEL_52:
    v19 = a3;
    if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x2000100,
        4,
        "cam_ofe_process_cmd",
        415,
        "clock rate %d",
        v12);
      a1 = v13;
    }
    v20 = ((__int64 (__fastcall *)(__int64, _QWORD))cam_ofe_update_clk_rate)(a1 + 96, (unsigned int)v12);
    if ( v20 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x2000000,
        1,
        "cam_ofe_process_cmd",
        418,
        "Failed to update clk %d",
        v12);
    if ( (unsigned int)cam_soc_util_get_clk_level((_BYTE *)(v13 + 96), v12, *(_DWORD *)(v13 + 2892), &v28) )
      goto LABEL_58;
    v21 = v28;
    LODWORD(v29) = 0;
    v19[1] = v28;
    LODWORD(v30) = v21;
    v22 = cam_cpas_update_ahb_vote(*((_DWORD *)v8 + 2), (__int64)&v29);
    if ( v22 )
    {
      v23 = "failed at updating ahb vote level rc: %d";
      v24 = v22;
      v25 = 432;
    }
    else
    {
      v26 = cam_cpas_update_axi_floor_lvl(*((_DWORD *)v8 + 2), v28);
      if ( !v26 )
      {
        v20 = 0;
LABEL_58:
        result = v20;
        goto LABEL_8;
      }
      v23 = "failed at updating axi vote level clk_level rc: %d";
      v24 = v26;
      v25 = 441;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      0x2000000,
      1,
      "cam_ofe_process_cmd",
      v25,
      v23,
      v24);
    result = v24;
    goto LABEL_8;
  }
  if ( a2 != 7 )
    goto LABEL_28;
  if ( *((_BYTE *)v8 + 17) == 1 )
    cam_ofe_toggle_clk(a1 + 96, 0);
  result = 0;
  *((_BYTE *)v8 + 17) = 0;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
