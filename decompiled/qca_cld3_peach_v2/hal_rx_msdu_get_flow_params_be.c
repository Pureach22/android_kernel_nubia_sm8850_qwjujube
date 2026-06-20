__int64 __fastcall hal_rx_msdu_get_flow_params_be(__int64 result, bool *a2, bool *a3, _DWORD *a4)
{
  *a2 = (*(_DWORD *)(result + 36) & 0x2000) != 0;
  *a3 = (*(_DWORD *)(result + 36) & 0x1000) != 0;
  *a4 = (*(_QWORD *)(result + 20) >> 38) & 0xFFFFF;
  return result;
}
