__int64 gh_rm_unset_virtio_mmio_cb()
{
  mutex_lock(&gh_virtio_mmio_fn_lock);
  gh_virtio_mmio_fn = nullptr;
  return mutex_unlock(&gh_virtio_mmio_fn_lock);
}
