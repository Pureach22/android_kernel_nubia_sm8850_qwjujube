__int64 sub_30A314()
{
  __asm { PRFM            #0x13, [X24,#-0xBD]! }
  return hdd_conn_get_connected_band();
}
