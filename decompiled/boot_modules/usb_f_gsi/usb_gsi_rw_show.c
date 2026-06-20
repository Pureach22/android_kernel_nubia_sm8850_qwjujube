__int64 __fastcall usb_gsi_rw_show(__int64 a1)
{
  __int64 connected_gsi; // x0

  connected_gsi = get_connected_gsi();
  if ( connected_gsi )
    seq_printf(a1, "%d\n", *(unsigned __int8 *)(connected_gsi + 1400));
  return 0;
}
