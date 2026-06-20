__int64 __fastcall hal_rx_msdu_get_reo_destination_indication_be(__int64 result, _DWORD *a2)
{
  *a2 = (*(_QWORD *)(result + 20) >> 33) & 0x1F;
  return result;
}
