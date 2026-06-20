__int64 __fastcall dun_cser_connect(__int64 a1)
{
  *(_WORD *)(a1 + 266) |= 3u;
  return port_notify_serial_state(a1);
}
