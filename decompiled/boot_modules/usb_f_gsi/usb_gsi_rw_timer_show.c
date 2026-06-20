__int64 __fastcall usb_gsi_rw_timer_show(__int64 a1)
{
  __int64 connected_gsi; // x0

  connected_gsi = get_connected_gsi();
  if ( connected_gsi )
    seq_printf(a1, "%ums\n", *(unsigned __int16 *)(connected_gsi + 1402));
  return 0;
}
