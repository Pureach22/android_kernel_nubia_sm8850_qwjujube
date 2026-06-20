void cds_ssr_protect_init()
{
  ssr_protect_lock = 0;
  shutdown_notifier_head = (__int64)&shutdown_notifier_head;
  qword_8D5790 = (__int64)&shutdown_notifier_head;
}
