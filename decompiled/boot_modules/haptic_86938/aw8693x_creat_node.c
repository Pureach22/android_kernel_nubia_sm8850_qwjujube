__int64 __fastcall aw8693x_creat_node(__int64 a1)
{
  unsigned int group; // w0
  unsigned int v3; // w19

  group = sysfs_create_group(*(_QWORD *)(a1 + 248), &aw8693x_vibrator_attribute_group);
  if ( (group & 0x80000000) == 0 )
    return 0;
  v3 = group;
  printk(&unk_1564F, "haptic_hv", 2330, "aw8693x_creat_node");
  return v3;
}
