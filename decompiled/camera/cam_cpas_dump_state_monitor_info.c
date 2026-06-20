__int64 __fastcall cam_cpas_dump_state_monitor_info(__int64 a1)
{
  __int64 v1; // x9
  __int64 (__fastcall *v2)(__int64, __int64, __int64, __int64); // x8
  __int64 v4; // x0

  if ( g_cpas_intf && (*(_BYTE *)(g_cpas_intf + 852) & 1) != 0 )
  {
    v1 = *(_QWORD *)(g_cpas_intf + 480);
    v2 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(v1 + 88);
    if ( v2 )
    {
      v4 = *(_QWORD *)(v1 + 112);
      if ( *((_DWORD *)v2 - 1) != -1055839300 )
        __break(0x8228u);
      return v2(v4, 21, a1, 32);
    }
    else
    {
      return 0;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_dump_state_monitor_info",
      1295,
      "cpas intf not initialized");
    return 4294967277LL;
  }
}
