__int64 mem_buf_dma_buf_init()
{
  __int64 v0; // x1
  __int64 v1; // x2
  __int64 result; // x0

  gh_rm_mem_notifier_cookie = gh_mem_notifier_register(8, mem_buf_vmperm_gh_notifier, 0);
  if ( (unsigned __int64)gh_rm_mem_notifier_cookie < 0xFFFFFFFFFFFFF001LL
    || (printk(&unk_1334F, v0, v1), result = (unsigned int)gh_rm_mem_notifier_cookie, !(_DWORD)gh_rm_mem_notifier_cookie) )
  {
    debugfs_create_file("mem_buf_summary", 256, mem_buf_debugfs_root, 0, &summary_fops);
    return 0;
  }
  return result;
}
