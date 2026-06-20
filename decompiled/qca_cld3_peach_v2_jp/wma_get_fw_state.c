__int64 __fastcall wma_get_fw_state(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( (unsigned int)_wma_validate_handle((__int64)a1, (__int64)"wma_get_fw_state", a2, a3, a4, a5, a6, a7, a8, a9) )
    return 4;
  v11 = wmi_buf_alloc_fl(*a1, 8u, "wma_get_fw_state", 0x25u);
  if ( !v11 )
    return 2;
  **(_QWORD **)(v11 + 224) = 0x100950004LL;
  result = wmi_unified_cmd_send_fl(
             *a1,
             v11,
             8u,
             0x1D001u,
             "wma_get_fw_state",
             0x31u,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19);
  if ( (_DWORD)result )
  {
    wmi_buf_free();
    return 16;
  }
  return result;
}
