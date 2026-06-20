__int64 __fastcall cam_vfe_bus_ver3_debug_handler(__int64 result, unsigned int *a2)
{
  __int64 v2; // x22
  __int64 v3; // x23
  unsigned int v5; // w24
  const char **v6; // x25
  bool v7; // cc
  unsigned int v8; // w21
  const char **v9; // x23

  v2 = *(_QWORD *)(result + 72);
  v3 = *(_QWORD *)(result + 34984);
  if ( *a2 )
  {
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
               3,
               8,
               3,
               "cam_vfe_bus_ver3_debug_handler",
               282,
               "VFE[%u] Bus overflow status: 0x%x",
               *(unsigned int *)(v2 + 20));
    v5 = *a2;
    if ( *a2 )
    {
      v6 = (const char **)(v3 + 728);
      do
      {
        if ( (v5 & 1) != 0 )
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     8,
                     1,
                     "cam_vfe_bus_ver3_debug_handler",
                     288,
                     "VFE[%u] Bus Overflow %s",
                     *(_DWORD *)(v2 + 20),
                     *v6);
        v7 = v5 > 1;
        v6 += 30;
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
               "cam_vfe_bus_ver3_debug_handler",
               297,
               "VFE[%u] Bus violation status: 0x%x",
               *(unsigned int *)(v2 + 20));
    v8 = a2[1];
    if ( v8 )
    {
      v9 = (const char **)(v3 + 728);
      do
      {
        if ( (v8 & 1) != 0 )
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     8,
                     1,
                     "cam_vfe_bus_ver3_debug_handler",
                     305,
                     "VFE[%u] Bus Overflow %s",
                     *(_DWORD *)(v2 + 20),
                     *v9);
        v7 = v8 > 1;
        v9 += 30;
        v8 >>= 1;
      }
      while ( v7 );
    }
  }
  return result;
}
