__int64 slc_mpam_remove()
{
  configfs_unregister_group(root_group);
  return kfree(root_group);
}
