__int64 __fastcall cam_vfe_top_dump_perf_counters(__int64 result, const char *a2, _QWORD *a3)
{
  __int64 v3; // x10
  __int64 v4; // x12
  __int64 v6; // x9
  unsigned __int64 v7; // x21
  __int64 v8; // x22
  __int64 v9; // x20
  __int64 v10; // x8
  unsigned int *v11; // x28
  int v12; // w24
  int v13; // w25
  int v14; // w26
  int v15; // w27
  int v16; // w0
  __int64 v17; // x8
  int v18; // w0
  unsigned __int64 v19; // x21
  __int64 v20; // x22
  __int64 v21; // x20
  unsigned int *v22; // x28
  int v23; // w24
  int v24; // w25
  int v25; // w26
  int v26; // w27
  int v27; // w0
  __int64 v28; // x8
  int v29; // w0
  __int64 v30; // [xsp+40h] [xbp-20h]
  __int64 v31; // [xsp+48h] [xbp-18h]
  const char *v32; // [xsp+50h] [xbp-10h]

  v4 = a3[1];
  v3 = a3[2];
  v32 = (const char *)result;
  v6 = *(_QWORD *)(a3[1304] + 288LL);
  if ( *(_DWORD *)(v4 + 248) )
  {
    v7 = 0;
    v8 = v4 + 252;
    v30 = a3[1304];
    v31 = a3[1];
    v9 = v6 + *(_QWORD *)(v3 + 256);
    v10 = v31;
    while ( v7 != 8 )
    {
      if ( (a3[v7 + 1347] & 0x100000000LL) != 0 )
      {
        v11 = (unsigned int *)(v8 + 28 * v7++);
        v12 = *(_DWORD *)(*a3 + 4LL);
        v13 = cam_io_r_mb(v9 + v11[2]);
        v14 = cam_io_r_mb(v9 + v11[3]);
        v15 = cam_io_r_mb(v9 + v11[4]);
        v16 = cam_io_r_mb(v9 + v11[5]);
        v17 = v11[6];
        LODWORD(v11) = v16;
        v18 = cam_io_r_mb(v9 + v17);
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   8,
                   3,
                   "cam_vfe_top_dump_perf_counters",
                   587,
                   "VFE [%u] on %s %s counter: %d pixel_cnt: %d line_cnt: %d stall_cnt: %d always_cnt: %d status: 0x%x",
                   v12,
                   a2,
                   v32,
                   v7,
                   v13,
                   v14,
                   v15,
                   (_DWORD)v11,
                   v18);
        v10 = a3[1];
      }
      else
      {
        ++v7;
      }
      if ( v7 >= *(unsigned int *)(v10 + 248) )
      {
        v4 = v31;
        v3 = a3[2];
        v6 = *(_QWORD *)(v30 + 288);
        if ( *(_DWORD *)(v10 + 476) )
          goto LABEL_11;
        return result;
      }
    }
    goto LABEL_18;
  }
  v10 = a3[1];
  if ( *(_DWORD *)(v4 + 476) )
  {
LABEL_11:
    v19 = 0;
    v20 = v4 + 480;
    v21 = v6 + *(_QWORD *)(v3 + 264);
    while ( v19 != 8 )
    {
      if ( (a3[v19 + 1355] & 0x100000000LL) != 0 )
      {
        v22 = (unsigned int *)(v20 + 28 * v19++);
        v23 = *(_DWORD *)(*a3 + 4LL);
        v24 = cam_io_r_mb(v21 + v22[2]);
        v25 = cam_io_r_mb(v21 + v22[3]);
        v26 = cam_io_r_mb(v21 + v22[4]);
        v27 = cam_io_r_mb(v21 + v22[5]);
        v28 = v22[6];
        LODWORD(v22) = v27;
        v29 = cam_io_r_mb(v21 + v28);
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   8,
                   3,
                   "cam_vfe_top_dump_perf_counters",
                   608,
                   "VFE [%u] Bayer on %s %s counter: %d pixel_cnt: %d line_cnt: %d stall_cnt: %d always_cnt: %d status: 0x%x",
                   v23,
                   a2,
                   v32,
                   v19,
                   v24,
                   v25,
                   v26,
                   (_DWORD)v22,
                   v29);
        v10 = a3[1];
      }
      else
      {
        ++v19;
      }
      if ( v19 >= *(unsigned int *)(v10 + 476) )
        return result;
    }
LABEL_18:
    __break(0x5512u);
    return cam_vfe_ver4_err_irq_top_half();
  }
  return result;
}
