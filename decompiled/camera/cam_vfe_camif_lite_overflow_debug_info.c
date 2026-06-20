__int64 __fastcall cam_vfe_camif_lite_overflow_debug_info(__int64 *a1)
{
  __int64 v2; // x23
  int v3; // w20
  int v4; // w21
  int v5; // w22
  int v6; // w0
  __int64 result; // x0
  int v8; // w21
  int v9; // w22
  int v10; // w23
  int v11; // w0
  int v12; // w21
  int v13; // w22
  int v14; // w23
  int v15; // w0
  int v16; // w0
  __int64 v17; // x8
  __int64 v18; // x9
  int v19; // w19
  int v20; // w0

  v2 = *(_QWORD *)(a1[5] + 3296);
  v3 = cam_io_r(*a1 + *(unsigned int *)(a1[3] + 100));
  v4 = cam_io_r(*a1 + *(unsigned int *)(a1[3] + 104));
  v5 = cam_io_r(*a1 + *(unsigned int *)(a1[3] + 108));
  v6 = cam_io_r(*a1 + *(unsigned int *)(a1[3] + 112));
  result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             8,
             3,
             "cam_vfe_camif_lite_overflow_debug_info",
             812,
             "status_0: 0x%X status_1: 0x%X status_2: 0x%X status_3: 0x%X",
             v3,
             v4,
             v5,
             v6);
  if ( (*(_BYTE *)(v2 + 24) & 1) == 0 )
  {
    v8 = cam_io_r(*a1 + *(unsigned int *)(a1[3] + 116));
    v9 = cam_io_r(*a1 + *(unsigned int *)(a1[3] + 120));
    v10 = cam_io_r(*a1 + *(unsigned int *)(a1[3] + 124));
    v11 = cam_io_r(*a1 + *(unsigned int *)(a1[3] + 128));
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_overflow_debug_info",
      827,
      "status_4: 0x%X status_5: 0x%X status_6: 0x%X status_7: 0x%X",
      v8,
      v9,
      v10,
      v11);
    v12 = cam_io_r(*a1 + *(unsigned int *)(a1[3] + 132));
    v13 = cam_io_r(*a1 + *(unsigned int *)(a1[3] + 136));
    v14 = cam_io_r(*a1 + *(unsigned int *)(a1[3] + 140));
    v15 = cam_io_r(*a1 + *(unsigned int *)(a1[3] + 144));
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_camif_lite_overflow_debug_info",
      838,
      "status_8: 0x%X status_9: 0x%X status_10: 0x%X status_11: 0x%X",
      v12,
      v13,
      v14,
      v15);
    v16 = cam_io_r(*a1 + *(unsigned int *)(a1[3] + 148));
    v17 = a1[3];
    v18 = *a1;
    v19 = v16;
    v20 = cam_io_r(v18 + *(unsigned int *)(v17 + 152));
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             8,
             3,
             "cam_vfe_camif_lite_overflow_debug_info",
             844,
             "status_12: 0x%X status_13: 0x%X",
             v19,
             v20);
  }
  return result;
}
