__int64 __fastcall cam_tpg_publish_dev_info(__int64 a1)
{
  if ( !a1 )
    return 4294967274LL;
  if ( cam_get_device_priv(*(_DWORD *)a1) )
  {
    *(_QWORD *)(a1 + 260) = 0x100000009LL;
    *(_DWORD *)(a1 + 272) = 1;
    *(_QWORD *)(a1 + 4) = 0x6770742D6D6163LL;
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "cam_tpg_publish_dev_info",
      36,
      "Device data is NULL");
    return 4294967274LL;
  }
}
