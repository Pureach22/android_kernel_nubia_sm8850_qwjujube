__int64 __fastcall cam_csiphy_program_lane_settings(__int64 a1, unsigned int a2, __int16 a3, char a4, int *a5)
{
  int v5; // w19
  __int64 v6; // x26
  __int64 v7; // x28
  int v8; // w24
  unsigned int v9; // w23
  unsigned __int8 v11; // w21
  int v13; // w27
  _DWORD *v14; // x25
  int v15; // w9
  unsigned int v16; // w8
  __int64 v17; // x1
  __int64 v18; // x0
  const char *v20; // x7
  __int64 v21; // [xsp+8h] [xbp-8h]

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_program_lane_settings",
      1821,
      "Device is NULL");
    return 4294967274LL;
  }
  v5 = *a5;
  v6 = *((_QWORD *)a5 + 1);
  if ( *a5 && v6 )
  {
    v7 = *(_QWORD *)(a1 + 1200);
    v8 = a5[1];
    v9 = HIBYTE(a3);
    v11 = a3;
    v13 = 0;
    v21 = a1 + 104LL * a2;
    while ( 1 )
    {
      v14 = (_DWORD *)(v6 + 16LL * v13);
      v15 = v14[3];
      v16 = *v14 + v8;
      if ( v15 <= 7 )
        break;
      if ( v15 == 8 )
      {
        v17 = v7 + v16;
        v18 = v9;
        goto LABEL_23;
      }
      if ( v15 == 64 )
      {
        if ( (a4 & 1) == 0 )
        {
          v17 = v7 + v16;
          v18 = 0;
          goto LABEL_23;
        }
        goto LABEL_18;
      }
      if ( v15 != 0x8000 )
        goto LABEL_19;
      if ( a2 > 2 )
      {
        __break(0x5512u);
        return cam_csiphy_shutdown(a1);
      }
      if ( *(_BYTE *)(v21 + 690) == 1 )
      {
        v17 = v7 + v16;
        v18 = 10;
LABEL_23:
        cam_io_w_mb(v18, v17);
      }
LABEL_24:
      a1 = (unsigned int)v14[2];
      if ( (int)a1 >= 1 )
        a1 = usleep_range_state(a1, (int)a1 + 5, 2);
      if ( v5 == ++v13 )
        return 0;
    }
    if ( v15 != 1 )
    {
      if ( v15 != 4 )
      {
LABEL_19:
        if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
          ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            (unsigned __int16)debug_mdl & 0x8000,
            4,
            "cam_csiphy_program_lane_settings",
            1861,
            "Do Nothing");
        goto LABEL_24;
      }
      v17 = v7 + v16;
      v18 = v11;
      goto LABEL_23;
    }
LABEL_18:
    v18 = (unsigned int)v14[1];
    v17 = v7 + v16;
    goto LABEL_23;
  }
  if ( v6 )
    v20 = "Y";
  else
    v20 = "N";
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x8000,
    1,
    "cam_csiphy_program_lane_settings",
    1833,
    "Invalid lane settings param, num_offsets: %u, reg_array: %s",
    v5,
    v20);
  return 4294967274LL;
}
