__int64 __fastcall gsi_get_chan_poll_mode(unsigned int a1)
{
  if ( a1 < 0x24 )
    return *(unsigned int *)(gsi_ctx + 448LL * a1 + 484);
  __break(0x5512u);
  return gsi_get_ring_len();
}
