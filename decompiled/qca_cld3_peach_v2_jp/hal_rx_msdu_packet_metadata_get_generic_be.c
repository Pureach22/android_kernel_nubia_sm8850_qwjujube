__int64 __fastcall hal_rx_msdu_packet_metadata_get_generic_be(__int64 result, _QWORD *a2)
{
  unsigned __int64 v2; // x8
  unsigned __int64 v3; // x8
  __int64 v4; // x8

  v2 = *a2 & 0xFFFFFFFFFFFF0000LL | (*(_QWORD *)(result + 12) >> 58) & 3LL;
  *a2 = v2;
  v3 = ((unsigned __int64)(unsigned __int16)*(_QWORD *)(result + 20) << 32) | v2 & 0xFFFF0000FFFFFFFFLL;
  *a2 = v3;
  v4 = v3 & 0xFFFFFFFFFFFFLL | (*(_QWORD *)(result + 20) >> 16 << 48);
  *a2 = v4;
  *a2 = v4 & 0xFFFFFFFF00000003LL | ((unsigned __int64)*(unsigned __int16 *)(result + 16) << 16);
  return result;
}
