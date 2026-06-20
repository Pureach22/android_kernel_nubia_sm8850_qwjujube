__int64 __fastcall cam_jpeg_mgr_stop_deinit_dev(__int64 a1, unsigned int a2)
{
  __int64 v2; // x21
  __int64 v4; // x22
  __int64 v6; // x9
  _DWORD *v7; // x8
  __int64 v8; // x0
  unsigned int v9; // w0
  __int64 v10; // x6
  const char *v11; // x5
  __int64 v12; // x4
  __int64 v13; // x9
  _DWORD *v14; // x8
  __int64 v15; // x0
  unsigned int v16; // w0
  __int64 v17; // x6
  const char *v18; // x5
  __int64 v19; // x4
  __int64 v20; // x9
  _DWORD *v21; // x8
  __int64 v22; // x0
  __int64 result; // x0
  _QWORD v24[5]; // [xsp+8h] [xbp-28h] BYREF

  v24[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24[0] = cam_jpeg_hw_mgr_sched_bottom_half;
  memset(&v24[1], 0, 24);
  if ( a2 >= 2 )
    __break(0x5512u);
  v2 = a2;
  v4 = a1 + 5192;
  v6 = **(_QWORD **)(a1 + 5192 + 8LL * a2);
  v7 = *(_DWORD **)(v6 + 88);
  if ( !v7 )
  {
    v11 = "process_cmd null %d";
    v12 = 1145;
    v10 = a2;
    goto LABEL_8;
  }
  v8 = *(_QWORD *)(v6 + 112);
  if ( *(v7 - 1) != -1055839300 )
    __break(0x8228u);
  v9 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64))v7)(v8, 1, v24, 32);
  if ( v9 )
  {
    v10 = v9;
    v11 = "SET_IRQ_CB fail %d";
    v12 = 1143;
LABEL_8:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_stop_deinit_dev",
      v12,
      v11,
      v10);
  }
  v13 = **(_QWORD **)(v4 + 8 * v2);
  v14 = *(_DWORD **)(v13 + 64);
  if ( !v14 )
  {
    v18 = "op stop null %d";
    v19 = 1155;
    v17 = a2;
    goto LABEL_15;
  }
  v15 = *(_QWORD *)(v13 + 112);
  if ( *(v14 - 1) != 1989616049 )
    __break(0x8228u);
  v16 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v14)(v15, 0, 0);
  if ( v16 )
  {
    v17 = v16;
    v18 = "stop fail %d";
    v19 = 1153;
LABEL_15:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_mgr_stop_deinit_dev",
      v19,
      v18,
      v17);
  }
  v20 = **(_QWORD **)(v4 + 8 * v2);
  v21 = *(_DWORD **)(v20 + 24);
  if ( v21 )
  {
    v22 = *(_QWORD *)(v20 + 112);
    if ( *(v21 - 1) != 1989616049 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v21)(v22, 0, 0);
    if ( (_DWORD)result )
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 512,
                 1,
                 "cam_jpeg_mgr_stop_deinit_dev",
                 1164,
                 "Failed to Deinit %d HW %d",
                 a2,
                 result);
  }
  else
  {
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               512,
               1,
               "cam_jpeg_mgr_stop_deinit_dev",
               1166,
               "op deinit null %d",
               a2);
  }
  *(_DWORD *)(a1 + 4 * v2 + 5256) = 0;
  *(_QWORD *)(a1 + 8 * v2 + 5264) = 0;
  _ReadStatusReg(SP_EL0);
  return result;
}
