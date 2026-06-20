__int64 __fastcall pmic_glink_rpmsg_remove(__int64 a1)
{
  _UNKNOWN **v2; // x21

  mutex_lock(&pmic_glink_dev_lock);
  v2 = &pmic_glink_dev_list;
  do
  {
    v2 = (_UNKNOWN **)*v2;
    if ( v2 == &pmic_glink_dev_list )
    {
      mutex_unlock(&pmic_glink_dev_lock);
      return printk(&unk_784C, "pmic_glink_rpmsg_remove", a1 + 912);
    }
  }
  while ( strcmp((const char *)(a1 + 912), (const char *)*(v2 - 31)) );
  mutex_unlock(&pmic_glink_dev_lock);
  if ( v2 != (_UNKNOWN **)&unk_110 )
  {
    down_write(v2 - 20);
    *((_DWORD *)v2 + 4) = 0;
    *(v2 - 34) = nullptr;
    up_write(v2 - 20);
    return ipc_log_string(*(v2 - 30), "%s removed\n", (const char *)(a1 + 912));
  }
  return printk(&unk_784C, "pmic_glink_rpmsg_remove", a1 + 912);
}
