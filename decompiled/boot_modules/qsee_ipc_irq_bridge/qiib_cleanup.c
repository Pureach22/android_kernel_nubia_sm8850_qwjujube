__int64 qiib_cleanup()
{
  _QWORD *v0; // x8
  __int64 *v1; // x19
  __int64 *v2; // x22
  __int64 **v3; // x8
  __int64 *v4; // x9
  __int64 v5; // x0
  __int64 v6; // x8
  unsigned __int64 v7; // x0

  mutex_lock(qiib_info + 16);
  v0 = (_QWORD *)qiib_info;
  v1 = *(__int64 **)qiib_info;
  if ( (_QWORD *)*v0 != v0 )
  {
    do
    {
      v2 = (__int64 *)*v1;
      cdev_del(v1 + 4);
      v3 = (__int64 **)v1[1];
      if ( *v3 == v1 && (v4 = (__int64 *)*v1, *(__int64 **)(*v1 + 8) == v1) )
      {
        v4[1] = (__int64)v3;
        *v3 = v4;
      }
      else
      {
        _list_del_entry_valid_or_report(v1);
      }
      *v1 = 0xDEAD000000000100LL;
      v1[1] = 0xDEAD000000000122LL;
      device_destroy(*(_QWORD *)(qiib_info + 72), *(_DWORD *)(qiib_info + 80) & 0xFFF00000 | *((_DWORD *)v1 + 4));
      v5 = v1[31];
      if ( v5 )
        qcom_unregister_ssr_notifier(v5, v1 + 28);
      kfree(v1);
      v0 = (_QWORD *)qiib_info;
      v1 = v2;
    }
    while ( v2 != (__int64 *)qiib_info );
  }
  mutex_unlock(v0 + 2);
  v6 = qiib_info;
  v7 = *(_QWORD *)(qiib_info + 72);
  if ( v7 && v7 <= 0xFFFFFFFFFFFFF000LL )
  {
    class_destroy();
    v6 = qiib_info;
    *(_QWORD *)(qiib_info + 72) = 0;
  }
  return unregister_chrdev_region(*(_DWORD *)(v6 + 80) >> 20, *(unsigned int *)(v6 + 64));
}
