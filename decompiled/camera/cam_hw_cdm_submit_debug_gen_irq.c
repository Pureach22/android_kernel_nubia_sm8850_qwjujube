__int64 __fastcall cam_hw_cdm_submit_debug_gen_irq(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v5; // x24
  __int64 v6; // x22
  __int64 (*v7)(void); // x8
  int v8; // w0
  __int64 v9; // x21
  int v10; // w7
  unsigned int v11; // w6
  __int64 result; // x0
  unsigned int *v13; // x8
  int v14; // w23
  int v15; // w0
  _DWORD *v16; // x8
  _BOOL8 v17; // x2
  __int64 v18; // x0
  __int64 v19; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v20[2]; // [xsp+10h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 3680);
  v6 = *(_QWORD *)(a2 + 8);
  v19 = 0;
  v20[0] = 0;
  v7 = *(__int64 (**)(void))(*(_QWORD *)(v5 + 240) + 40LL);
  if ( *((_DWORD *)v7 - 1) != -605791253 )
    __break(0x8228u);
  v8 = v7();
  if ( a3 >= 4 )
    __break(0x5512u);
  v9 = v5 + 640LL * a3;
  v10 = *(_DWORD *)(v9 + 2404);
  v11 = *(unsigned __int8 *)(v9 + 2400);
  if ( v10 - 1 >= v11 )
  {
    v13 = *(unsigned int **)(v6 + 24);
    v14 = 4 * v8;
    if ( v13[5] - v13[6] >= 4 * v8 )
    {
      if ( (debug_mdl & 1) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          4,
          "cam_hw_cdm_submit_debug_gen_irq",
          986,
          "Last Tag: 0x%x Total BLs: %d, Cookie: %d",
          v11,
          *(_DWORD *)(v6 + 20),
          *(_QWORD *)(v6 + 32));
        v13 = *(unsigned int **)(v6 + 24);
      }
      v15 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD *, __int64 *, _QWORD, _QWORD))cam_mem_get_io_buf)(
              *v13,
              *(unsigned int *)(v5 + 224),
              v20,
              &v19,
              0,
              0);
      if ( v15 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          1,
          "cam_hw_cdm_submit_debug_gen_irq",
          991,
          "Getting a hwva from mem_hdl failed. rc: %d",
          v15);
        result = 4294967274LL;
      }
      else
      {
        v16 = *(_DWORD **)(*(_QWORD *)(v5 + 240) + 136LL);
        v17 = **(_DWORD **)(*(_QWORD *)(v5 + 232) + 72LL) > 1u;
        v18 = *(_QWORD *)(*(_QWORD *)(v6 + 24) + 8LL) + (*(_DWORD *)(*(_QWORD *)(v6 + 24) + 24LL) & 0xFFFFFFFC);
        if ( *(v16 - 1) != 1079251131 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, _BOOL8, _QWORD))v16)(v18, 255, v17, a3);
        if ( (cam_hw_cdm_bl_write(
                a1,
                *(_DWORD *)(*(_QWORD *)(v6 + 24) + 16LL) + LODWORD(v20[0]),
                v14 - 1,
                *(unsigned __int8 *)(v9 + 2400),
                0,
                a3)
            & 1) != 0 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            1,
            1,
            "cam_hw_cdm_submit_debug_gen_irq",
            1008,
            "CDM hw bl write failed for Debug GenIRQ USRdata: %d, Tag: 0x%x",
            255,
            *(unsigned __int8 *)(v9 + 2400));
        }
        else
        {
          *(_DWORD *)(*(_QWORD *)(v6 + 24) + 24LL) += v14;
          *(_DWORD *)(*(_QWORD *)(v6 + 24) + 16LL) += v14;
          if ( !cam_cdm_write_hw_reg(
                  a1,
                  *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 3680) + 232LL) + 8LL * a3 + 8) + 8LL),
                  1u) )
          {
            result = 0;
            goto LABEL_21;
          }
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            1,
            1,
            "cam_hw_cdm_commit_bl_write",
            840,
            "Failed to write CDM commit BL");
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            1,
            1,
            "cam_hw_cdm_submit_debug_gen_irq",
            1017,
            "Cannot commit the Debug GenIRQ BL with Tag: 0x%x",
            *(unsigned __int8 *)(v9 + 2400));
        }
        result = 4294967291LL;
      }
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        1,
        1,
        "cam_hw_cdm_submit_debug_gen_irq",
        981,
        "Insufficient memory for GenIRQ Command");
      result = 4294967284LL;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_submit_debug_gen_irq",
      976,
      "Invalid BL Tag: %d, BL Depth: %d Fifo_idx: %d",
      v11,
      v10,
      a3);
    result = 4294967274LL;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
