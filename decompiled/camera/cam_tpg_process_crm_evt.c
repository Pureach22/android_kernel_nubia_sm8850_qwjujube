__int64 __fastcall cam_tpg_process_crm_evt(__int64 a1)
{
  __int64 device_priv; // x0
  int v3; // w6
  __int64 result; // x0
  const char *v5; // x5
  __int64 v6; // x4

  if ( !a1 )
  {
    v5 = "Invalid argument";
    v6 = 186;
LABEL_8:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "cam_tpg_process_crm_evt",
      v6,
      v5);
    return 4294967274LL;
  }
  device_priv = cam_get_device_priv(*(_DWORD *)(a1 + 4));
  if ( !device_priv )
  {
    v5 = "Invalid dev_hdl";
    v6 = 192;
    goto LABEL_8;
  }
  v3 = *(_DWORD *)(a1 + 20);
  if ( v3 == 4 )
  {
    tpg_hw_dump_status(device_priv + 4568);
    return 0;
  }
  result = 0;
  if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x200000000LL,
      4,
      "cam_tpg_process_crm_evt",
      201,
      "Got crm event notification: %d",
      v3);
    return 0;
  }
  return result;
}
