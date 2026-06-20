__int64 __fastcall cam_tpg_setup_link(__int64 a1)
{
  __int64 device_priv; // x0
  __int64 v3; // x19
  __int64 v4; // x8
  __int64 v5; // x6
  const char *v6; // x5
  __int64 v7; // x1
  __int64 v8; // x4
  __int64 v10; // x8

  if ( !a1 )
    return 4294967274LL;
  device_priv = cam_get_device_priv(*(_DWORD *)(a1 + 8));
  if ( !device_priv )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "cam_tpg_setup_link",
      60,
      "Device data is NULL");
    return 4294967274LL;
  }
  v3 = device_priv;
  mutex_lock(device_priv + 24);
  if ( *(_DWORD *)a1 )
  {
    *(_DWORD *)(v3 + 4496) = *(_DWORD *)(a1 + 4);
    v4 = debug_mdl;
    *(_QWORD *)(v3 + 4560) = *(_QWORD *)(a1 + 24);
    if ( (v4 & 0x200000000LL) == 0 || debug_priority )
      goto LABEL_11;
    v5 = *(unsigned int *)(v3 + 564);
    v6 = "TPG[%d] CRM enable link done";
    v7 = v4 & 0x200000000LL;
    v8 = 68;
  }
  else
  {
    *(_QWORD *)(v3 + 4560) = 0;
    v10 = debug_mdl;
    *(_DWORD *)(v3 + 4496) = -1;
    if ( (v10 & 0x200000000LL) == 0 || debug_priority )
      goto LABEL_11;
    v5 = *(unsigned int *)(v3 + 564);
    v6 = "TPG[%d] CRM disable link done";
    v7 = v10 & 0x200000000LL;
    v8 = 72;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    v7,
    4,
    "cam_tpg_setup_link",
    v8,
    v6,
    v5);
LABEL_11:
  mutex_unlock(v3 + 24);
  return 0;
}
