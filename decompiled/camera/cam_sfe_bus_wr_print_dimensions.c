__int64 __fastcall cam_sfe_bus_wr_print_dimensions(__int64 result, __int64 a2)
{
  __int64 v2; // x23
  __int64 v3; // x19
  unsigned int v4; // w20
  unsigned int v5; // w21
  const char *v6; // x24
  const char *v7; // x26
  _DWORD *v8; // x22
  const char *v9; // x19
  int v10; // w26
  int v11; // w27
  int v12; // w28
  const char *v13; // x25
  int v14; // w24
  int v15; // [xsp+0h] [xbp-50h]
  int v16; // [xsp+18h] [xbp-38h]
  unsigned int v18; // [xsp+4Ch] [xbp-4h]

  v2 = *(_QWORD *)(*(_QWORD *)(a2 + 27576) + 152LL * (unsigned int)result + 24);
  if ( *(_DWORD *)(v2 + 24) )
  {
    v3 = a2;
    v4 = result;
    v5 = 0;
    v6 = "cam_sfe_bus_wr_print_dimensions";
    v7 = "Unsupported SFE out %d";
    v18 = result;
    do
    {
      v8 = *(_DWORD **)(*(_QWORD *)(v2 + 32) + 152LL * (int)v5 + 24);
      if ( (*v8 & 0x80000000) != 0 || *v8 >= *(_DWORD *)(v3 + 27544) )
      {
        result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                   3,
                   0x40000000,
                   2,
                   v6,
                   1967,
                   v7,
                   v4);
      }
      else
      {
        v9 = v7;
        v10 = cam_io_r_mb(*(_QWORD *)(*((_QWORD *)v8 + 1) + 8LL) + *(unsigned int *)(*((_QWORD *)v8 + 2) + 68LL));
        v11 = cam_io_r_mb(*(_QWORD *)(*((_QWORD *)v8 + 1) + 8LL) + *(unsigned int *)(*((_QWORD *)v8 + 2) + 72LL));
        v12 = cam_io_r_mb(*(_QWORD *)(*((_QWORD *)v8 + 1) + 8LL) + *(unsigned int *)(*((_QWORD *)v8 + 2) + 76LL));
        v13 = v6;
        v14 = cam_io_r_mb(*(_QWORD *)(*((_QWORD *)v8 + 1) + 8LL) + *(unsigned int *)(*((_QWORD *)v8 + 2) + 80LL));
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000000,
          3,
          "__cam_sfe_bus_wr_print_wm_info",
          1941,
          "SFE:%u WM:%u width:%u height:%u stride:%u x_init:%u en_cfg:%u acquired width:%u height:%u pack_cfg: 0x%x",
          **((_DWORD **)v8 + 1),
          *v8,
          v8[13],
          v8[14],
          v8[15],
          v8[19],
          v8[24],
          v8[26],
          v8[27],
          v8[17]);
        v4 = v18;
        v15 = v10;
        v7 = v9;
        v3 = a2;
        v16 = v14;
        v6 = v13;
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   0x40000000,
                   3,
                   "__cam_sfe_bus_wr_print_wm_info",
                   1946,
                   "SFE:%u WM:%u last_consumed_image_addr:0x%x last_consumed_frame_header:0x%x fifo_word_cnt:%d [FH + Ima"
                   "ge] current_image_addr:0x%x",
                   *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v8 + 1) + 16LL) + 4LL),
                   *v8,
                   v15,
                   v11,
                   v12,
                   v16);
      }
      ++v5;
    }
    while ( v5 < *(_DWORD *)(v2 + 24) );
  }
  return result;
}
