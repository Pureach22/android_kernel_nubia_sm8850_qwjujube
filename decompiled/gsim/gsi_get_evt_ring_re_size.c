__int64 __fastcall gsi_get_evt_ring_re_size(unsigned int a1)
{
  if ( a1 >= 0x1F )
  {
    __break(0x5512u);
    JUMPOUT(0x24C90);
  }
  return *(unsigned int *)(gsi_ctx + 328LL * a1 + 18336);
}
