__int64 __fastcall hal_rx_msdu_start_msdu_len_set_be(__int64 result, __int16 a2)
{
  *(_QWORD *)(result + 36) = *(_QWORD *)(result + 36) & 0xFFFFC000FFFFFFFFLL | ((unsigned __int64)(a2 & 0x3FFF) << 32);
  return result;
}
