__int64 __fastcall cam_smmu_driver_init(_DWORD *a1, _DWORD *a2)
{
  __int64 v2; // x10
  __int64 v3; // x0
  _QWORD *v5; // x10
  __int64 v6; // x11
  __int64 *v7; // x9
  __int64 v8; // x12
  _QWORD *v9; // x8
  __int64 **v10; // x1
  __int64 *v11; // x0

  if ( a1 && a2 )
  {
    *a2 = dword_394060;
    v2 = qword_3940E8;
    a1[2] = dword_3940F0;
    *(_QWORD *)a1 = v2;
    byte_3940FB = byte_3940D6;
    if ( (byte_3940D6 & 1) == 0 )
    {
      if ( mem_trace_en == 1 )
        v3 = cam_mem_trace_alloc(28800, 0xCC0u, 0, "cam_smmu_driver_init", 0x15D8u);
      else
        v3 = _kvmalloc_node_noprof(28800, 0, 3520, 0xFFFFFFFFLL);
      v5 = &unk_394000;
      buf_tracking_pool = v3;
      if ( v3 )
      {
        v6 = 0;
        v7 = &qword_3940D8;
        v8 = 600;
        qword_3940D8 = (__int64)&qword_3940D8;
        qword_3940E0 = (__int64)&qword_3940D8;
        do
        {
          v9 = (_QWORD *)(v5[34] + v6);
          *v9 = v9;
          v9[1] = v9;
          v10 = (__int64 **)v7[1];
          v11 = (__int64 *)(v5[34] + v6);
          if ( v11 != v7 && v11 != (__int64 *)v10 && *v10 == v7 )
          {
            v7[1] = (__int64)v11;
            *v11 = (__int64)v7;
            v11[1] = (__int64)v10;
            *v10 = v11;
          }
          else
          {
            _list_add_valid_or_report(v11);
          }
          --v8;
          v6 += 48;
        }
        while ( v8 );
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          64,
          2,
          "cam_smmu_driver_init",
          5595,
          "[SMMU_BT] Not enough mem for buffer tracker pool");
      }
    }
    return 0;
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_driver_init",
      5581,
      "Invalid params csf: %p num_cbs: %p",
      a1,
      a2);
    return 4294967274LL;
  }
}
