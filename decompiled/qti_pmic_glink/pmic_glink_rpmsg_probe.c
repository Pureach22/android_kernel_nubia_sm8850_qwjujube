__int64 __fastcall pmic_glink_rpmsg_probe(__int64 a1)
{
  _UNKNOWN **v2; // x21
  _QWORD *v3; // x22

  mutex_lock(&pmic_glink_dev_lock);
  v2 = &pmic_glink_dev_list;
  do
  {
    v2 = (_UNKNOWN **)*v2;
    if ( v2 == &pmic_glink_dev_list )
    {
      mutex_unlock(&pmic_glink_dev_lock);
      goto LABEL_8;
    }
  }
  while ( strcmp((const char *)(a1 + 912), (const char *)*(v2 - 31)) );
  v3 = v2 - 34;
  mutex_unlock(&pmic_glink_dev_lock);
  if ( v2 != (_UNKNOWN **)&unk_110 )
  {
    down_write(v2 - 20);
    *(_QWORD *)(a1 + 152) = v3;
    *v3 = a1;
    *((_DWORD *)v2 + 4) = 1;
    up_write(v2 - 20);
    queue_work_on(32, system_wq, v2 - 7);
    ipc_log_string(*(v2 - 30), "%s probed\n", (const char *)(a1 + 912));
    return 0;
  }
LABEL_8:
  printk(&unk_784C, "pmic_glink_rpmsg_probe", a1 + 912);
  return 4294966779LL;
}
