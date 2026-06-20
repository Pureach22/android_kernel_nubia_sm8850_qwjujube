__int64 __fastcall cam_sfe_top_dump_perf_counters(__int64 result, const char *a2, __int64 a3, __int64 a4)
{
  _DWORD *v4; // x27
  unsigned int v5; // w8
  __int64 v6; // x22
  const char *v9; // x21
  __int64 v10; // x28
  int v11; // w23
  int v12; // w24
  int v13; // w25
  int v14; // w26
  int v15; // w0
  int v16; // w22
  int v17; // w23
  int v18; // w24
  int v19; // w25
  int v20; // w26
  int v21; // w0
  int v22; // [xsp+3Ch] [xbp-4h]

  v4 = *(_DWORD **)(a3 + 16);
  v5 = v4[21];
  if ( v5 )
  {
    v6 = a3 + 28672;
    v9 = (const char *)result;
    v10 = *(_QWORD *)(*(_QWORD *)a3 + 288LL);
    if ( (*(_BYTE *)(a3 + 32240) & 1) != 0 )
    {
      v22 = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 4LL);
      v11 = cam_io_r_mb(v10 + (unsigned int)v4[23]);
      v12 = cam_io_r_mb(v10 + (unsigned int)v4[24]);
      v13 = cam_io_r_mb(v10 + (unsigned int)v4[25]);
      v14 = cam_io_r_mb(v10 + (unsigned int)v4[26]);
      v15 = cam_io_r_mb(v10 + (unsigned int)v4[27]);
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 0x40000000,
                 3,
                 "cam_sfe_top_dump_perf_counters",
                 345,
                 "SFE [%u] on %s %s counter: %d pixel_cnt: %d line_cnt: %d stall_cnt: %d always_cnt: %d status: 0x%x",
                 v22,
                 a2,
                 v9,
                 1,
                 v11,
                 v12,
                 v13,
                 v14,
                 v15);
      v5 = *(_DWORD *)(*(_QWORD *)(a3 + 16) + 84LL);
    }
    if ( v5 >= 2 )
    {
      if ( *(_BYTE *)(v6 + 3576) == 1 )
      {
        v16 = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 4LL);
        v17 = cam_io_r_mb(v10 + (unsigned int)v4[29]);
        v18 = cam_io_r_mb(v10 + (unsigned int)v4[30]);
        v19 = cam_io_r_mb(v10 + (unsigned int)v4[31]);
        v20 = cam_io_r_mb(v10 + (unsigned int)v4[32]);
        v21 = cam_io_r_mb(v10 + (unsigned int)v4[33]);
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   0x40000000,
                   3,
                   "cam_sfe_top_dump_perf_counters",
                   345,
                   "SFE [%u] on %s %s counter: %d pixel_cnt: %d line_cnt: %d stall_cnt: %d always_cnt: %d status: 0x%x",
                   v16,
                   a2,
                   v9,
                   2,
                   v17,
                   v18,
                   v19,
                   v20,
                   v21);
        v5 = *(_DWORD *)(*(_QWORD *)(a3 + 16) + 84LL);
      }
      if ( v5 > 2 )
      {
        __break(0x5512u);
        return cam_sfe_top_set_hw_clk_rate(result, a2, a3, a4);
      }
    }
  }
  return result;
}
