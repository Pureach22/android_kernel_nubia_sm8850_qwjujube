__int64 __fastcall cam_cpastop_print_poweron_settings(__int64 a1)
{
  _QWORD *v1; // x26
  __int64 i; // x24
  __int64 v4; // x27
  int v5; // w8
  __int64 v6; // x28
  __int64 v7; // x25
  __int64 v8; // x9
  unsigned int v9; // w23

  v1 = *(_QWORD **)(a1 + 3680);
  for ( i = 0; i != 4; ++i )
  {
    v4 = *(_QWORD *)(*v1 + 8 * i + 8);
    if ( v4 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        3,
        "cam_cpastop_print_poweron_settings",
        1202,
        "QOS settings for %s :",
        g_camnoc_names[i]);
      v5 = *(_DWORD *)(v4 + 16);
      if ( v5 >= 1 )
      {
        v6 = 0;
        v7 = 216;
        do
        {
          v8 = *(_QWORD *)(v4 + 8) + v7;
          if ( *(_BYTE *)(v8 - 200) == 1 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              4,
              3,
              "cam_cpastop_print_poweron_settings",
              1208,
              "Reading QoS settings port: %d port name: %s",
              *(_DWORD *)(v8 - 216),
              *(const char **)(v8 - 208));
            v9 = *(_DWORD *)(v4 + 4);
            ((void (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_read)(
              a1,
              v9,
              *(_QWORD *)(v4 + 8) + v7 - 196);
            ((void (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_read)(
              a1,
              v9,
              *(_QWORD *)(v4 + 8) + v7 - 168);
            ((void (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_read)(
              a1,
              v9,
              *(_QWORD *)(v4 + 8) + v7 - 140);
            ((void (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_read)(
              a1,
              v9,
              *(_QWORD *)(v4 + 8) + v7 - 112);
            ((void (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_read)(
              a1,
              v9,
              *(_QWORD *)(v4 + 8) + v7 - 84);
            ((void (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_read)(
              a1,
              v9,
              *(_QWORD *)(v4 + 8) + v7 - 56);
            ((void (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_read)(
              a1,
              v9,
              *(_QWORD *)(v4 + 8) + v7 - 28);
            ((void (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_read)(
              a1,
              v9,
              *(_QWORD *)(v4 + 8) + v7 + 168);
            ((void (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_read)(a1, v9, *(_QWORD *)(v4 + 8) + v7);
            ((void (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_read)(
              a1,
              v9,
              *(_QWORD *)(v4 + 8) + v7 + 28);
            ((void (__fastcall *)(__int64, _QWORD, __int64))cam_cpas_util_reg_read)(
              a1,
              v9,
              *(_QWORD *)(v4 + 8) + v7 + 56);
            v5 = *(_DWORD *)(v4 + 16);
          }
          ++v6;
          v7 += 416;
        }
        while ( v6 < v5 );
      }
    }
  }
  return 0;
}
