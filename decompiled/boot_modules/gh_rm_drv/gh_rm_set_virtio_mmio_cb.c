__int64 __fastcall gh_rm_set_virtio_mmio_cb(void *a1)
{
  unsigned int v2; // w19

  if ( a1 )
  {
    mutex_lock(&gh_virtio_mmio_fn_lock);
    if ( gh_virtio_mmio_fn )
    {
      v2 = -16;
    }
    else
    {
      v2 = 0;
      gh_virtio_mmio_fn = a1;
    }
    mutex_unlock(&gh_virtio_mmio_fn_lock);
  }
  else
  {
    return (unsigned int)-22;
  }
  return v2;
}
