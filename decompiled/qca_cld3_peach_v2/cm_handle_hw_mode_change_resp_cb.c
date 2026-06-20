__int64 __fastcall cm_handle_hw_mode_change_resp_cb(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19

  if ( !a1 )
    return 16;
  v9 = *(_QWORD *)(a1 + 8);
  if ( !v9 )
    return 16;
  wlan_cm_hw_mode_change_resp(
    *(_QWORD *)v9,
    *(unsigned __int8 *)(v9 + 8),
    *(_DWORD *)(v9 + 12),
    *(_DWORD *)(v9 + 16),
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9);
  _qdf_mem_free(v9);
  return 0;
}
