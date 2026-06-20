__int64 __fastcall cam_cpastop_handle_errlogger(unsigned int a1, _QWORD *a2, __int64 a3, _DWORD *a4)
{
  __int64 v8; // x23
  __int64 v9; // x9
  unsigned int *v10; // x8
  unsigned int v11; // w9
  __int64 v12; // x20
  int v13; // w0
  unsigned __int64 v14; // x8
  __int64 result; // x0
  __int64 v16; // x0
  unsigned __int64 v17; // [xsp+30h] [xbp-210h] BYREF
  char s[512]; // [xsp+38h] [xbp-208h] BYREF
  __int64 v19; // [xsp+238h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v17 = 0;
  if ( a1 >= 4 )
    goto LABEL_11;
  v8 = *(_QWORD *)(*a2 + 8LL * a1 + 8);
  v9 = *(unsigned int *)(v8 + 4);
  if ( (unsigned int)v9 > 9 )
    goto LABEL_11;
  v10 = *(unsigned int **)(v8 + 48);
  if ( v10 )
  {
    v11 = *((_DWORD *)a2 + v9 + 703);
    if ( v11 <= 7 )
    {
      v12 = a3 + 24LL * v11;
      *a4 = cam_io_r_mb(*(_QWORD *)(v12 + 288) + *v10);
      a4[1] = cam_io_r_mb(*(_QWORD *)(v12 + 288) + *(unsigned int *)(*(_QWORD *)(v8 + 48) + 4LL));
      a4[2] = cam_io_r_mb(*(_QWORD *)(v12 + 288) + *(unsigned int *)(*(_QWORD *)(v8 + 48) + 8LL));
      a4[3] = cam_io_r_mb(*(_QWORD *)(v12 + 288) + *(unsigned int *)(*(_QWORD *)(v8 + 48) + 12LL));
      a4[4] = cam_io_r_mb(*(_QWORD *)(v12 + 288) + *(unsigned int *)(*(_QWORD *)(v8 + 48) + 16LL));
      a4[5] = cam_io_r_mb(*(_QWORD *)(v12 + 288) + *(unsigned int *)(*(_QWORD *)(v8 + 48) + 20LL));
      a4[6] = cam_io_r_mb(*(_QWORD *)(v12 + 288) + *(unsigned int *)(*(_QWORD *)(v8 + 48) + 24LL));
      a4[7] = cam_io_r_mb(*(_QWORD *)(v12 + 288) + *(unsigned int *)(*(_QWORD *)(v8 + 48) + 28LL));
      a4[8] = cam_io_r_mb(*(_QWORD *)(v12 + 288) + *(unsigned int *)(*(_QWORD *)(v8 + 48) + 32LL));
      v13 = cam_io_r_mb(*(_QWORD *)(v12 + 288) + *(unsigned int *)(*(_QWORD *)(v8 + 48) + 36LL));
      v14 = (unsigned int)a4[2];
      a4[9] = v13;
      cam_print_to_buffer(
        (__int64)s,
        0x200u,
        &v17,
        1u,
        4u,
        "%s NoC Error Info: %s, MAINCTL_LOW = 0x%x, ERRVLD_LOW = 0x%x",
        (__int64)g_camnoc_slave_err_code[(v14 >> 8) & 7],
        (__int64)g_camnoc_names[a1],
        *a4);
      cam_print_to_buffer(
        (__int64)s,
        0x200u,
        &v17,
        1u,
        4u,
        "ERRLOG0_LOW = 0x%x, ERRLOG0_HIGH = 0x%x, ERRLOG1_LOW = 0x%x, ERRLOG1_HIGH = 0x%x, ERRLOG2_LOW = 0x%x, ERRLOG2_HI"
        "GH = 0x%x, ERRLOG3_LOW = 0x%x, ERRLOG3_HIGH = 0x%x",
        (unsigned int)a4[2],
        (unsigned int)a4[3],
        a4[4]);
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 4,
                 1,
                 "cam_cpastop_handle_errlogger",
                 656,
                 "%s",
                 s);
      goto LABEL_10;
    }
LABEL_11:
    __break(0x5512u);
  }
  if ( (unsigned int)__ratelimit(&cam_cpastop_handle_errlogger__rs, "cam_cpastop_handle_errlogger") )
    v16 = 3;
  else
    v16 = 2;
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             v16,
             4,
             1,
             "cam_cpastop_handle_errlogger",
             595,
             "Invalid err logger info");
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
