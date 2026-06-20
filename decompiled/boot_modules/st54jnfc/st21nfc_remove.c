__int64 __fastcall st21nfc_remove(__int64 a1)
{
  __int64 v1; // x21
  unsigned __int64 v3; // x20
  unsigned __int64 v4; // x8
  __int64 result; // x0
  unsigned __int64 v6; // x1
  unsigned __int64 v7; // x1
  unsigned __int64 v8; // x1

  v1 = *(_QWORD *)(a1 + 184);
  v3 = *(_QWORD *)(v1 + 928);
  if ( v3 && v3 <= 0xFFFFFFFFFFFFF000LL && *(_BYTE *)(v1 + 920) == 1 )
  {
    clk_disable(*(_QWORD *)(v1 + 928));
    clk_unprepare(v3);
    *(_BYTE *)(v1 + 920) = 0;
  }
  misc_deregister(v1 + 176);
  v4 = *(_QWORD *)(v1 + 968);
  if ( v4 && v4 <= 0xFFFFFFFFFFFFF000LL )
  {
    sysfs_remove_file_ns(a1 + 32, &dev_attr_power_stats, 0);
    devm_gpiod_put(a1 + 32, *(_QWORD *)(v1 + 968));
  }
  sysfs_remove_group(a1 + 32, &st21nfc_attr_grp);
  result = *(_QWORD *)(v1 + 520);
  if ( result )
  {
    result = wakeup_source_unregister();
    *(_QWORD *)(v1 + 520) = 0;
  }
  v6 = *(_QWORD *)(v1 + 952);
  if ( v6 && v6 <= 0xFFFFFFFFFFFFF000LL )
    result = devm_gpiod_put(a1 + 32, v6);
  v7 = *(_QWORD *)(v1 + 944);
  if ( v7 && v7 <= 0xFFFFFFFFFFFFF000LL )
    result = devm_gpiod_put(a1 + 32, v7);
  v8 = *(_QWORD *)(v1 + 960);
  if ( v8 )
  {
    if ( v8 <= 0xFFFFFFFFFFFFF000LL )
      return devm_gpiod_put(a1 + 32, v8);
  }
  return result;
}
