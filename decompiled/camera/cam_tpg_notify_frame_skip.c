__int64 __fastcall cam_tpg_notify_frame_skip(__int64 a1)
{
  __int64 device_priv; // x0
  __int64 v3; // x9
  __int64 result; // x0
  const char *v5; // x5
  __int64 v6; // x4

  if ( !a1 )
  {
    v5 = "invalid parameters";
    v6 = 96;
LABEL_8:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "cam_tpg_notify_frame_skip",
      v6,
      v5);
    return 4294967274LL;
  }
  device_priv = cam_get_device_priv(*(_DWORD *)(a1 + 4));
  if ( !device_priv )
  {
    v5 = "Device data is NULL";
    v6 = 101;
    goto LABEL_8;
  }
  v3 = device_priv;
  result = 0;
  if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x200000000LL,
      4,
      "cam_tpg_notify_frame_skip",
      107,
      "TPG[%d] Got Skip frame from crm for request %lld",
      *(_DWORD *)(v3 + 564),
      *(_QWORD *)(a1 + 8));
    return 0;
  }
  return result;
}
