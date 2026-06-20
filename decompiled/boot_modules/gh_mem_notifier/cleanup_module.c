__int64 cleanup_module()
{
  return gh_rm_unregister_notifier(&gh_mem_notifier_blk);
}
