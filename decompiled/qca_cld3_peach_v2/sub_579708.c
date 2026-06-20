__int64 __fastcall sub_579708(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  int v4; // w25

  return hal_rx_tlv_get_pn_num_be(a1, a2, a3, (unsigned int)(v4 + (a4 << 27)));
}
