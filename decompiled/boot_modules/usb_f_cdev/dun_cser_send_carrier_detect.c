__int64 __fastcall dun_cser_send_carrier_detect(__int64 a1, int a2)
{
  __int16 v2; // w8

  if ( a2 )
    v2 = (*(_WORD *)(a1 + 266) & 0xFFFE) + 1;
  else
    v2 = *(_WORD *)(a1 + 266) & 0xFFFE;
  *(_WORD *)(a1 + 266) = v2;
  return port_notify_serial_state();
}
