__int64 destroy_devices()
{
  class_unregister(&zram_control_class);
  idr_for_each(&zram_index_idr, zram_remove_cb, 0);
  idr_destroy(&zram_index_idr);
  unregister_blkdev((unsigned int)zram_major, "zram");
  return _cpuhp_remove_state(61, 0);
}
