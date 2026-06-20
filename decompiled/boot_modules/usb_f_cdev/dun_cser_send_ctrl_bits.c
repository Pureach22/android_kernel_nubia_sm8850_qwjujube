__int64 __fastcall dun_cser_send_ctrl_bits(__int64 a1, __int16 a2)
{
  *(_WORD *)(a1 + 266) = a2;
  return port_notify_serial_state(a1);
}
