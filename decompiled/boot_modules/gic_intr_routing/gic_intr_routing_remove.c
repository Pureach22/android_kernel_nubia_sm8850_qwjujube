__int64 gic_intr_routing_remove()
{
  return debugfs_remove(debugfs_dir);
}
