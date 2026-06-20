__int64 __fastcall cam_vfe_bus_dump_wm_data(__int64 a1, __int64 a2)
{
  unsigned int v2; // w8
  unsigned int v3; // w19
  __int64 v5; // x25
  unsigned int v6; // w21
  unsigned int wm_idx; // w0
  __int64 v8; // x8
  const char *v10; // x5
  __int64 v11; // x4
  __int64 v12; // x6

  v2 = *(_DWORD *)(a2 + 8) - 12288;
  if ( v2 >= 0x17 )
  {
    v10 = "Unsupported res_id: %u";
    v11 = 3676;
    v12 = 23;
  }
  else
  {
    v3 = dword_44E784[v2];
    v5 = *(_QWORD *)(a1 + 152LL * v3 + 39128);
    if ( !*(_DWORD *)(v5 + 16) )
      return 0;
    v6 = 0;
    while ( 1 )
    {
      wm_idx = cam_vfe_bus_get_wm_idx(v3, v6);
      if ( (wm_idx & 0x80000000) != 0 || wm_idx >= *(_DWORD *)(a1 + 33616) )
        break;
      v8 = *(_QWORD *)(a1 + 33632 + 152LL * wm_idx + 24);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        3,
        "cam_vfe_bus_dump_wm_data",
        3698,
        "VFE:%d WM:%d width:%u height:%u stride:%u x_init:%u en_cfg:%u acquired width:%u height:%u",
        **(_DWORD **)(v8 + 8),
        wm_idx,
        *(_DWORD *)(v8 + 32),
        *(_DWORD *)(v8 + 36),
        *(_DWORD *)(v8 + 40),
        *(_DWORD *)(v8 + 72),
        *(_DWORD *)(v8 + 112),
        *(_DWORD *)(v8 + 132),
        *(_DWORD *)(v8 + 136));
      if ( ++v6 >= *(_DWORD *)(v5 + 16) )
        return 0;
    }
    v10 = "Unsupported VFE out %d";
    v11 = 3686;
    v12 = v3;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    8,
    1,
    "cam_vfe_bus_dump_wm_data",
    v11,
    v10,
    v12);
  return 4294967274LL;
}
