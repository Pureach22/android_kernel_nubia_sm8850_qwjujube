__int64 __fastcall tpg_hw_v_1_0_process_cmd(_DWORD *a1, int a2, _DWORD *a3)
{
  int v3; // w21
  __int64 v4; // x19
  __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x4
  __int64 v10; // x20
  __int64 v11; // x19
  int v12; // w8
  __int64 v13; // x21
  __int64 v14; // x20
  unsigned int v16; // w19
  int v17; // w22
  int v18; // w21

  if ( !a1 )
  {
    v8 = 221;
    goto LABEL_11;
  }
  switch ( a2 )
  {
    case 16384:
      v14 = *((_QWORD *)a1 + 5);
      v16 = cam_io_r_mb(*(_QWORD *)(v14 + 312) + 28LL);
      v17 = 1 << *a1;
      cam_io_w_mb(v17 | v16, *(_QWORD *)(v14 + 312) + 28LL);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "configure_global_configs",
        80,
        "TPG:%d Set top Mux: 0x%x",
        *a1,
        v17 | v16);
      v6 = 55;
      v7 = *(_QWORD *)(v14 + 288) + 96LL;
LABEL_24:
      cam_io_w_mb(v6, v7);
      return 0;
    case 16386:
      if ( a3 )
      {
        v10 = *((_QWORD *)a3 + 1);
        v11 = *((_QWORD *)a1 + 5);
        v12 = a3[1];
        if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
        {
          v18 = a3[1];
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x200000000LL,
            4,
            "configure_dt",
            130,
            "TPG[%d] slot(%d,%d) <= dt:%d",
            *a1,
            *a3,
            v12,
            *(unsigned __int16 *)(v10 + 67));
          v12 = v18;
        }
        v13 = (unsigned int)(16 * v12);
        cam_io_w_mb(*(_DWORD *)(v10 + 44) & 0x3FFFu | (*(_DWORD *)(v10 + 40) << 16), *(_QWORD *)(v11 + 288) + v13 + 112);
        cam_io_w_mb(*(unsigned __int16 *)(v10 + 67), *(_QWORD *)(v11 + 288) + v13 + 128);
        if ( (unsigned int)*(unsigned __int8 *)(v10 + 48) - 10 > 6 )
          v6 = 65544;
        else
          v6 = dword_454BAC[(unsigned __int8)(*(_BYTE *)(v10 + 48) - 10)];
        v7 = *(_QWORD *)(v11 + 288) + v13 + 144;
        goto LABEL_24;
      }
      v8 = 246;
      goto LABEL_11;
    case 16385:
      if ( a3 )
      {
        v3 = a3[1];
        v4 = *((_QWORD *)a3 + 1);
        v5 = *((_QWORD *)a1 + 5);
        if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x200000000LL,
            4,
            "configure_vc",
            170,
            "Configureing vc : %d at the slot : %d num_dts=%d",
            *(unsigned __int16 *)(v4 + 65),
            *a3,
            v3);
        cam_io_w_mb(((v3 << 8) - 256) | (unsigned int)*(unsigned __int16 *)(v4 + 65), *(_QWORD *)(v5 + 288) + 100LL);
        cam_io_w_mb(*(unsigned int *)(v4 + 57), *(_QWORD *)(v5 + 288) + 104LL);
        cam_io_w_mb(0, *(_QWORD *)(v5 + 288) + 164LL);
        v6 = *(unsigned int *)(v4 + 61);
        v7 = *(_QWORD *)(v5 + 288) + 168LL;
        goto LABEL_24;
      }
      v8 = 231;
LABEL_11:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x200000000LL,
        1,
        "tpg_hw_v_1_0_process_cmd",
        v8,
        "invalid argument");
      return 4294967274LL;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x200000000LL,
    1,
    "tpg_hw_v_1_0_process_cmd",
    259,
    "invalid argument");
  return 0;
}
