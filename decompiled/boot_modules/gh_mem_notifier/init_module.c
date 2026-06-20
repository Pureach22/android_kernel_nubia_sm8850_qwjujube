__int64 init_module()
{
  unsigned int v0; // w19

  v0 = gh_rm_register_notifier(&gh_mem_notifier_blk);
  if ( v0 )
    printk(&unk_63D0, "gh_mem_notifier_init", v0);
  return v0;
}
