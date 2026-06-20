__int64 __fastcall hal_rx_tlv_csum_err_get_be(__int64 result, _DWORD *a2, _DWORD *a3, int *a4)
{
  *a2 = (*(_QWORD *)(result + 52) >> 51) & 1;
  *a3 = (*(_QWORD *)(result + 52) >> 50) & 1;
  *a4 = (*(_DWORD *)(result + 44) >> 14) & 1;
  return result;
}
