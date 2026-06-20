__int64 __fastcall cam_ife_csid_ver2_dump_crop_reg(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x23
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x9
  __int64 v8; // x8
  unsigned int v10; // w19
  __int64 v11; // x10
  __int64 v12; // x22
  const char *v13; // x21
  int v14; // w20
  __int64 v15; // x27
  int applied_src_clk; // w0
  unsigned int v17; // w8
  __int64 v18; // x25
  __int64 v19; // x26
  __int64 v20; // x22
  int v21; // w19
  int v22; // w20
  int v23; // w21
  int v24; // w0

  v2 = *(_QWORD *)(a1 + 3680);
  v4 = raw_spin_lock(v2 + 30968);
  v7 = *(_QWORD *)(v2 + 31128);
  v8 = *a2;
  if ( *(_DWORD *)(v7 + 92) != 1 || (unsigned int)v8 >= 0xC )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_dump_crop_reg",
      8539,
      "CSID[%u] Invalid dev state :%d or path_id :%u",
      *(unsigned int *)(*(_QWORD *)(v2 + 31120) + 4LL));
    v10 = -22;
LABEL_12:
    raw_spin_unlock(v2 + 30968);
    return v10;
  }
  v11 = *(unsigned int *)(v7 + 2892);
  if ( (unsigned int)v11 < 0x20 )
  {
    v12 = *(_QWORD *)(v7 + 384);
    v13 = *(const char **)(v7 + 8 * v11 + 968);
    v14 = *(_DWORD *)(*(_QWORD *)(v2 + 31120) + 4LL);
    v15 = *(unsigned int *)(*(_QWORD *)(**(_QWORD **)(v2 + 31136) + 8 * v8 + 136) + 316LL);
    applied_src_clk = cam_soc_util_get_applied_src_clk((_QWORD *)(v7 + 96), 1);
    v4 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
           3,
           8,
           3,
           "cam_ife_csid_ver2_dump_crop_reg",
           8551,
           "CSID[%u] Clock Name=%s Clock Rate=%u",
           v14,
           v13,
           applied_src_clk);
    v17 = *a2;
    if ( *a2 <= 0xC )
    {
      v10 = 0;
      v18 = v2 + 152LL * v17;
      if ( *(_DWORD *)(v18 + 8) == 4 )
      {
        v19 = *(_QWORD *)(v18 + 24);
        if ( v19 )
        {
          v20 = v12 + v15;
          v21 = cam_io_r_mb(v20 + *(unsigned int *)(*(_QWORD *)(v19 + 264) + 128LL));
          v22 = cam_io_r_mb(v20 + *(unsigned int *)(*(_QWORD *)(v19 + 264) + 132LL));
          v23 = cam_io_r_mb(v20 + *(unsigned int *)(*(_QWORD *)(v19 + 264) + 16LL));
          v24 = cam_io_r_mb(v20 + *(unsigned int *)(*(_QWORD *)(v19 + 264) + 36LL));
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            3,
            "cam_ife_csid_ver2_dump_crop_reg",
            8561,
            "CSID[%u] %s HCROP=0x%x VCROP=0x%x, CFG0=0x%x CFG1=0x%x",
            *(_DWORD *)(*(_QWORD *)(v2 + 31120) + 4LL),
            (const char *)(v18 + 128),
            v21,
            v22,
            v23,
            v24);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            3,
            "cam_ife_csid_ver2_dump_crop_reg",
            8565,
            "CSID[%u] %s width=%d height=%d start line:%d end line:%d",
            *(_DWORD *)(*(_QWORD *)(v2 + 31120) + 4LL),
            (const char *)(v18 + 128),
            *(_DWORD *)(v19 + 152),
            *(_DWORD *)(v19 + 164),
            *(_DWORD *)(v19 + 156),
            *(_DWORD *)(v19 + 160));
          v10 = 0;
        }
      }
      goto LABEL_12;
    }
  }
  __break(0x5512u);
  return cam_ife_csid_ver2_irq_comp_cfg(v4, v5, v6);
}
