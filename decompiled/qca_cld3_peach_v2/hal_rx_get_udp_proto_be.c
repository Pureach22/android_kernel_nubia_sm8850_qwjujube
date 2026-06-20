__int64 __fastcall hal_rx_get_udp_proto_be(__int64 a1)
{
  return (*(unsigned __int8 *)(a1 + 45) >> 5) & 1;
}
