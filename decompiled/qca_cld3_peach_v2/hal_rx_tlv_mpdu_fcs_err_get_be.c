__int64 __fastcall hal_rx_tlv_mpdu_fcs_err_get_be(__int64 a1)
{
  return *(_QWORD *)(a1 + 52) >> 63;
}
