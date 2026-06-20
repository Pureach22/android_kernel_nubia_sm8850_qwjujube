__int64 __fastcall cam_vfe_core_read_hw_query(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  int v5; // w0
  unsigned int hw_query; // w20

  v2 = *(_QWORD *)(a2 + 96);
  if ( v2 )
  {
    *(_QWORD *)a2 = *(_QWORD *)v2;
    *(_DWORD *)(a2 + 8) = *(_DWORD *)(v2 + 8);
    *(_DWORD *)(a2 + 40) = *(_DWORD *)(v2 + 40);
    *(_QWORD *)(a2 + 48) = *(_QWORD *)(v2 + 48);
  }
  v5 = cam_vfe_enable_soc_resources(a1);
  if ( v5 )
  {
    hw_query = v5;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_core_read_hw_query",
      666,
      "Enable SOC Failed rc %d",
      v5);
  }
  else
  {
    hw_query = cam_vfe_top_read_hw_query(a1, *(_QWORD *)(a2 + 48), *(unsigned int *)(a2 + 40));
    if ( hw_query )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_core_read_hw_query",
        673,
        "Read  top query failed rc %d",
        hw_query);
    cam_vfe_disable_soc_resources(a1);
  }
  return hw_query;
}
