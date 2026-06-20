__int64 sub_2D5608()
{
  __asm { PRFM            #0x13, [X24,#-0xBD]! }
  return hdd_conn_get_connected_band();
}
