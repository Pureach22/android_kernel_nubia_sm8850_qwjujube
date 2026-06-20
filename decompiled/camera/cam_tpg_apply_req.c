__int64 __fastcall cam_tpg_apply_req(__int64 a1)
{
  __int64 device_priv; // x0
  __int64 v3; // x20
  const char *v5; // x5
  __int64 v6; // x4
  __int64 v7; // [xsp+8h] [xbp-8h]

  if ( !a1 )
  {
    v5 = "invalid parameters";
    v6 = 117;
LABEL_9:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "cam_tpg_apply_req",
      v6,
      v5);
    return 4294967274LL;
  }
  device_priv = cam_get_device_priv(*(_DWORD *)(a1 + 4));
  if ( !device_priv )
  {
    v5 = "Device data is NULL";
    v6 = 124;
    goto LABEL_9;
  }
  if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
  {
    v7 = device_priv;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x200000000LL,
      4,
      "cam_tpg_apply_req",
      130,
      "TPG[%d] Got Apply request from crm %lld",
      *(_DWORD *)(device_priv + 564),
      *(_QWORD *)(a1 + 8));
    device_priv = v7;
  }
  v3 = device_priv;
  mutex_lock(device_priv + 24);
  tpg_hw_apply(v3 + 4568, *(_QWORD *)(a1 + 8));
  mutex_unlock(v3 + 24);
  return 0;
}
