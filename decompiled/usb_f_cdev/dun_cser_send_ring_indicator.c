__int64 __fastcall dun_cser_send_ring_indicator(__int64 a1, int a2)
{
  *(_WORD *)(a1 + 266) = *(_WORD *)(a1 + 266) & 0xFFF7 | (8 * (a2 != 0));
  return port_notify_serial_state(a1);
}
