int __cdecl perfmgr_is_enable()
{
  if ( ifas_log_enable )
    printk(&unk_FFBA, (unsigned int)ifas_enable);
  return ifas_enable;
}
