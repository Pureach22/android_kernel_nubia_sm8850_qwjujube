__int64 __fastcall cam_sfe_bus_deinit_sfe_out_resource(__int64 a1)
{
  __int64 v1; // x19
  int v2; // w8
  unsigned int v3; // w20
  __int64 v4; // x8
  _QWORD *v5; // x0

  if ( !*(_DWORD *)(a1 + 8) )
    return 0;
  v1 = *(_QWORD *)(a1 + 24);
  *(_DWORD *)(a1 + 64) = 0;
  *(_DWORD *)(a1 + 8) = 0;
  *(_QWORD *)(a1 + 88) = 0;
  *(_QWORD *)(a1 + 96) = 0;
  *(_QWORD *)(a1 + 112) = 0;
  *(_QWORD *)(a1 + 120) = 0;
  *(_QWORD *)(a1 + 32) = a1 + 32;
  *(_QWORD *)(a1 + 40) = a1 + 32;
  *(_QWORD *)(a1 + 16) = 0;
  *(_QWORD *)(a1 + 24) = 0;
  if ( !v1 )
    return 4294967284LL;
  v2 = *(_DWORD *)(v1 + 24);
  *(_QWORD *)(v1 + 40) = 0;
  if ( v2 )
  {
    v3 = 0;
    do
    {
      v4 = *(_QWORD *)(v1 + 32) + 152LL * (int)v3;
      *(_DWORD *)(v4 + 8) = 0;
      *(_QWORD *)(v4 + 32) = v4 + 32;
      *(_QWORD *)(v4 + 40) = v4 + 32;
      v5 = *(_QWORD **)(v4 + 24);
      *(_QWORD *)(v4 + 88) = 0;
      *(_QWORD *)(v4 + 96) = 0;
      *(_QWORD *)(v4 + 112) = 0;
      *(_QWORD *)(v4 + 120) = 0;
      *(_QWORD *)(v4 + 16) = 0;
      *(_QWORD *)(v4 + 24) = 0;
      if ( v5 )
      {
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v5, 0);
        else
          kvfree(v5);
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000000,
          1,
          "cam_sfe_bus_deinit_sfe_out_resource",
          1913,
          "SFE:%d deinit WM:%d failed rc:%d",
          **(_DWORD **)(v1 + 8),
          v3,
          -12);
      }
      ++v3;
    }
    while ( v3 < *(_DWORD *)(v1 + 24) );
  }
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)v1, 0);
  else
    kvfree(v1);
  return 0;
}
