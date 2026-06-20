__int64 gh_rm_drv_remove()
{
  gunyah_rm_notifier_unregister(rm, &gh_rm_core_notifier_blk);
  return idr_destroy(&gh_rm_call_idr);
}
