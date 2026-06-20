__int64 __fastcall cam_cpas_prepare_subpart_info(unsigned int a1, int a2, int a3)
{
  __int64 v6; // x19
  __int64 v7; // x8
  __int64 v8; // x8

  if ( g_cpas_intf && (*(_BYTE *)(g_cpas_intf + 852) & 1) != 0 )
  {
    v6 = *(_QWORD *)(*(_QWORD *)(g_cpas_intf + 480) + 112LL);
    mutex_lock(v6);
    v7 = *(_QWORD *)(v6 + 3392);
    if ( v7 )
    {
      if ( a1 < 4 )
      {
        v8 = v7 + 8 * a1;
        *(_DWORD *)(v8 + 1336) = a2;
        *(_DWORD *)(v8 + 1340) = a3;
        mutex_unlock(v6);
        return 0;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_prepare_subpart_info",
        1079,
        "Invalid camera subpart index : %d",
        a1);
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_prepare_subpart_info",
        1048,
        "Invalid soc_private: 0x%x",
        0);
    }
    mutex_unlock(v6);
    return 4294967274LL;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_prepare_subpart_info",
      1039,
      "cpas intf not initialized");
    return 4294967277LL;
  }
}
