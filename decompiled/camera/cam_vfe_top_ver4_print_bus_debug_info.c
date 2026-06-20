__int64 __fastcall cam_vfe_top_ver4_print_bus_debug_info(__int64 result, unsigned int *a2)
{
  __int64 v2; // x23
  __int64 v4; // x19
  unsigned int v5; // w24
  __int64 v6; // x25
  bool v7; // cc
  unsigned int v8; // w22
  __int64 v9; // x24

  v2 = *(_QWORD *)(result + 10432);
  v4 = result;
  if ( *a2 )
  {
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
               3,
               8,
               3,
               "cam_vfe_top_ver4_print_bus_debug_info",
               1043,
               "VFE[%u] Bus overflow status: 0x%x",
               *(unsigned int *)(v2 + 20));
    v5 = *a2;
    if ( *a2 )
    {
      v6 = 8;
      do
      {
        if ( (v5 & 1) != 0 )
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     8,
                     1,
                     "cam_vfe_top_ver4_print_bus_debug_info",
                     1049,
                     "VFE[%u] Bus Overflow %s",
                     *(_DWORD *)(v2 + 20),
                     *(const char **)(*(_QWORD *)(*(_QWORD *)(v4 + 16) + 56LL) + v6));
        v7 = v5 > 1;
        v6 += 16;
        v5 >>= 1;
      }
      while ( v7 );
    }
  }
  if ( a2[1] )
  {
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
               3,
               8,
               3,
               "cam_vfe_top_ver4_print_bus_debug_info",
               1057,
               "VFE[%u] Bus violation status: 0x%x",
               *(unsigned int *)(v2 + 20));
    v8 = a2[1];
    if ( v8 )
    {
      v9 = 8;
      do
      {
        if ( (v8 & 1) != 0 )
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     8,
                     1,
                     "cam_vfe_top_ver4_print_bus_debug_info",
                     1064,
                     "VFE[%u] Bus Violation %s",
                     *(_DWORD *)(v2 + 20),
                     *(const char **)(*(_QWORD *)(*(_QWORD *)(v4 + 16) + 56LL) + v9));
        v7 = v8 > 1;
        v9 += 16;
        v8 >>= 1;
      }
      while ( v7 );
    }
  }
  return result;
}
