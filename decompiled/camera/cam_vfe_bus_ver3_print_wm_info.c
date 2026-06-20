__int64 __fastcall cam_vfe_bus_ver3_print_wm_info(__int64 a1, __int64 a2, __int64 a3, const char *a4)
{
  __int64 v4; // x8
  __int64 v5; // x26
  __int64 v7; // x28
  __int64 v10; // x19
  unsigned int v11; // w25
  int v12; // w24
  char v13; // w27
  __int64 v14; // x19
  int v15; // w22
  __int64 v16; // x19
  __int64 v17; // x25
  int v18; // w24
  __int64 v19; // x22
  unsigned int v20; // w0
  __int64 v21; // x28
  unsigned int v22; // w22
  int v23; // w23
  int v24; // w24
  int v25; // w25
  int v26; // w26
  int v27; // w0
  __int64 result; // x0
  __int64 v29; // x22
  int v30; // w19
  int v31; // w23
  int v32; // w24
  int v33; // w25
  int v34; // w26
  int v35; // w0
  int v36; // w19
  int v37; // w23
  int v38; // w24
  int v39; // w25
  int v40; // w26
  int v41; // w0
  int v42; // w6
  int v43; // [xsp+48h] [xbp-8h]
  unsigned int v44; // [xsp+4Ch] [xbp-4h]

  v4 = *(_QWORD *)(a2 + 80);
  v5 = *(_QWORD *)(a2 + 16);
  v7 = *(unsigned int *)(a1 + 156);
  if ( (*(_BYTE *)(v4 + 232) & 8) != 0 && (*(_BYTE *)(a2 + 34675) & 1) == 0 )
  {
    v14 = *(_QWORD *)(a3 + 80);
    v15 = *(_DWORD *)(v4 + 20);
    if ( (*(_BYTE *)(v14 + 232) & 8) != 0 )
    {
      v17 = *(unsigned int *)(v14 + 20);
      v18 = *(_DWORD *)(v4 + 20);
      v19 = a3;
      v20 = cam_io_r_mb(*(_QWORD *)(a3 + 16) + v17);
      if ( (debug_mdl & 8) != 0 )
      {
        if ( debug_priority )
        {
          a3 = v19;
          v11 = v20 >> *(_DWORD *)(v14 + 84);
        }
        else
        {
          v42 = v17;
          v11 = v20 >> *(_DWORD *)(v14 + 84);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_vfe_bus_ver3_get_rd_ctxt_sel",
            5067,
            "Read SEL Register: reg=0x%x, val=0x%x, RD ctxt=%u, VFE=%u, mem_base=0x%pK",
            v42,
            v20,
            v11,
            *(_DWORD *)(*(_QWORD *)(v19 + 24) + 4LL),
            *(const void **)(v19 + 16));
          a3 = v19;
        }
        v15 = v18;
      }
      else
      {
        a3 = v19;
        v11 = v20 >> *(_DWORD *)(v14 + 84);
        v15 = v18;
      }
    }
    else
    {
      v11 = 0;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v16 = a3;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_ver3_get_rd_ctxt_sel",
          5053,
          "Skipping read select read: separate RD/WR not supported");
        a3 = v16;
        v11 = 0;
      }
    }
    if ( (debug_mdl & 8) != 0 )
    {
      v10 = a3;
      if ( !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_bus_ver3_print_wm_info",
          3100,
          "Captured original read rd_context: %u (reg: 0x%x)",
          v11,
          v15);
      v13 = 0;
    }
    else
    {
      v13 = 0;
      v10 = a3;
    }
    v12 = 1;
  }
  else
  {
    v10 = a3;
    v11 = 0;
    v12 = 0;
    v13 = 1;
  }
  v21 = v5 + v7;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_vfe_bus_ver3_print_wm_info",
    3108,
    "VFE:%u WM:%d wm_name:%s width:%u height:%u stride:%u x_init:%u en_cfg:%u acquired width:%u height:%u",
    *(_DWORD *)(*(_QWORD *)a1 + 8LL),
    *(_DWORD *)(a1 + 120),
    a4,
    *(_DWORD *)(a1 + 16),
    *(_DWORD *)(a1 + 20),
    *(_DWORD *)(a1 + 32),
    *(_DWORD *)(a1 + 40),
    *(_DWORD *)(a1 + 44),
    *(_DWORD *)(a1 + 144),
    *(_DWORD *)(a1 + 148));
  v22 = v11;
  v43 = v12;
  v44 = v11;
  if ( v12 )
  {
    cam_vfe_bus_ver3_set_rd_ctxt_sel(v10, 0);
    v22 = 0;
  }
  v23 = cam_io_r_mb(v21 + *(unsigned int *)(*(_QWORD *)(a1 + 8) + 96LL));
  v24 = cam_io_r_mb(v21 + *(unsigned int *)(*(_QWORD *)(a1 + 8) + 100LL));
  v25 = cam_io_r_mb(v21 + *(unsigned int *)(*(_QWORD *)(a1 + 8) + 104LL));
  v26 = cam_io_r_mb(v21 + *(unsigned int *)(*(_QWORD *)(a1 + 8) + 108LL));
  v27 = cam_io_r_mb(v21 + *(unsigned int *)(*(_QWORD *)(a1 + 8) + 132LL));
  result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             8,
             3,
             "cam_vfe_bus_ver3_print_wm_info",
             3123,
             "VFE:%u WM:%u Context:%u last consumed address:0x%x last frame addr:0x%x fifo cnt:0x%x current client addres"
             "s:0x%x limiter: 0x%x",
             *(_DWORD *)(*(_QWORD *)(a2 + 24) + 4LL),
             *(_DWORD *)(a1 + 120),
             v22,
             v23,
             v24,
             v25,
             v26,
             v27);
  v29 = v10;
  if ( (v13 & 1) == 0 )
  {
    v30 = v44;
    if ( v43 )
    {
      v30 = 1;
      cam_vfe_bus_ver3_set_rd_ctxt_sel(v29, 1);
    }
    v31 = cam_io_r_mb(v21 + *(unsigned int *)(*(_QWORD *)(a1 + 8) + 96LL));
    v32 = cam_io_r_mb(v21 + *(unsigned int *)(*(_QWORD *)(a1 + 8) + 100LL));
    v33 = cam_io_r_mb(v21 + *(unsigned int *)(*(_QWORD *)(a1 + 8) + 104LL));
    v34 = cam_io_r_mb(v21 + *(unsigned int *)(*(_QWORD *)(a1 + 8) + 108LL));
    v35 = cam_io_r_mb(v21 + *(unsigned int *)(*(_QWORD *)(a1 + 8) + 132LL));
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_vfe_bus_ver3_print_wm_info",
      3123,
      "VFE:%u WM:%u Context:%u last consumed address:0x%x last frame addr:0x%x fifo cnt:0x%x current client address:0x%x limiter: 0x%x",
      *(_DWORD *)(*(_QWORD *)(a2 + 24) + 4LL),
      *(_DWORD *)(a1 + 120),
      v30,
      v31,
      v32,
      v33,
      v34,
      v35);
    v36 = v44;
    if ( v43 )
    {
      v36 = 2;
      cam_vfe_bus_ver3_set_rd_ctxt_sel(v29, 2);
    }
    v37 = cam_io_r_mb(v21 + *(unsigned int *)(*(_QWORD *)(a1 + 8) + 96LL));
    v38 = cam_io_r_mb(v21 + *(unsigned int *)(*(_QWORD *)(a1 + 8) + 100LL));
    v39 = cam_io_r_mb(v21 + *(unsigned int *)(*(_QWORD *)(a1 + 8) + 104LL));
    v40 = cam_io_r_mb(v21 + *(unsigned int *)(*(_QWORD *)(a1 + 8) + 108LL));
    v41 = cam_io_r_mb(v21 + *(unsigned int *)(*(_QWORD *)(a1 + 8) + 132LL));
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               8,
               3,
               "cam_vfe_bus_ver3_print_wm_info",
               3123,
               "VFE:%u WM:%u Context:%u last consumed address:0x%x last frame addr:0x%x fifo cnt:0x%x current client addr"
               "ess:0x%x limiter: 0x%x",
               *(_DWORD *)(*(_QWORD *)(a2 + 24) + 4LL),
               *(_DWORD *)(a1 + 120),
               v36,
               v37,
               v38,
               v39,
               v40,
               v41);
  }
  if ( v43 )
  {
    result = cam_vfe_bus_ver3_set_rd_ctxt_sel(v29, v44);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               debug_mdl & 8,
               4,
               "cam_vfe_bus_ver3_print_wm_info",
               3129,
               "Restored original read rd_context: %u",
               v44);
  }
  return result;
}
