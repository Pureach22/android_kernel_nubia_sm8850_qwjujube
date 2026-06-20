__int64 __fastcall cam_icp_v1_deinit_hw(__int64 a1, unsigned __int8 *a2)
{
  __int64 v3; // x21
  int v4; // w20
  __int64 v5; // x0
  int v6; // w22
  unsigned int v7; // w20
  const char *v8; // x6
  const char *v9; // x7
  const char *v10; // x5
  __int64 v11; // x4
  __int64 v13; // x0

  if ( !a1 || !a2 )
  {
    if ( a1 )
      v8 = "Non-NULL";
    else
      v8 = "NULL";
    if ( a2 )
      v9 = "Non-NULL";
    else
      v9 = "NULL";
    v10 = "Invalid icp hw info is %s args is %s";
    v11 = 286;
    goto LABEL_20;
  }
  v3 = *(_QWORD *)(a1 + 3680);
  if ( !v3 )
  {
    v10 = "soc_info = %pK core_info = %pK";
    v8 = (const char *)(a1 + 96);
    v11 = 295;
    v9 = nullptr;
LABEL_20:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_v1_deinit_hw",
      v11,
      v10,
      v8,
      v9);
    return 4294967274LL;
  }
  v4 = *a2;
  v5 = raw_spin_lock_irqsave(a1 + 48);
  v6 = *(_DWORD *)(a1 + 92);
  raw_spin_unlock_irqrestore(a1 + 48, v5);
  if ( !v6 )
    return 0;
  if ( v4 )
    hfi_send_freq_info(*(unsigned int *)(v3 + 60), 0);
  v7 = cam_icp_soc_resources_disable(a1 + 96);
  if ( v7 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_v1_deinit_hw",
      312,
      "soc disable is failed: %d",
      v7);
  if ( *(_BYTE *)(v3 + 64) == 1 )
  {
    if ( (unsigned int)cam_cpas_stop(*(_DWORD *)(v3 + 56)) )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_v1_deinit_hw",
        316,
        "cpas stop is failed");
    else
      *(_BYTE *)(v3 + 64) = 0;
  }
  v13 = raw_spin_lock_irqsave(a1 + 48);
  *(_DWORD *)(a1 + 92) = 0;
  raw_spin_unlock_irqrestore(a1 + 48, v13);
  return v7;
}
