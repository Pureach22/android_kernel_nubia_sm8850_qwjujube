__int64 __fastcall aw882xx_monitor_deinit(__int64 a1)
{
  _QWORD *v1; // x20
  __int64 *v3; // x8
  __int64 v4; // x1
  int v5; // w8

  v1 = (_QWORD *)(a1 - 560);
  v3 = *(__int64 **)(a1 - 560);
  v4 = v3[14];
  if ( !v4 )
    v4 = *v3;
  printk(&unk_26EB3, v4, "aw882xx_monitor_stop");
  v5 = *(unsigned __int8 *)(a1 + 204);
  *(_DWORD *)(a1 - 52) = 0;
  *(_BYTE *)(a1 + 200) = 0;
  if ( !v5 )
    cancel_delayed_work_sync(a1);
  return sysfs_remove_group(*v1, &aw_monitor_attr_group);
}
