__int64 __fastcall dun_cser_disconnect(__int64 a1)
{
  *(_WORD *)(a1 + 266) &= 0xFFFCu;
  return port_notify_serial_state(a1);
}
