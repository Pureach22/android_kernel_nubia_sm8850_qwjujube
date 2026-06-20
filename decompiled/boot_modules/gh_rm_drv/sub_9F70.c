__int64 sub_9F70()
{
  int v0; // w23

  if ( (v0 & 0x1000000) == 0 )
    JUMPOUT(0x3524);
  return gh_rm_set_virtio_mmio_cb();
}
