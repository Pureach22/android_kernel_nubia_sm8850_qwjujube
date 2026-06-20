bool cam_cpas_is_fw_based_sys_caching_supported()
{
  __int64 v0; // x8
  int v1; // w9

  if ( g_cpas_intf && (*(_BYTE *)(g_cpas_intf + 852) & 1) != 0 )
  {
    v0 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(g_cpas_intf + 480) + 112LL) + 3392LL);
    v1 = *(_DWORD *)(v0 + 1592);
    return v1 && (unsigned int)(*(_DWORD *)(*(_QWORD *)(v0 + 1600) + ((__int64)(v1 - 1) << 6) + 4) - 6) < 8;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_is_fw_based_sys_caching_supported",
      1222,
      "cpas intf not initialized");
    return 0;
  }
}
