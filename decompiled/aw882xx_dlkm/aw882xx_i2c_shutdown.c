__int64 __fastcall aw882xx_i2c_shutdown(__int64 a1)
{
  __int64 v1; // x19
  __int64 *v2; // x8
  __int64 v3; // x1

  v1 = *(_QWORD *)(a1 + 184);
  v2 = *(__int64 **)(v1 + 64);
  v3 = v2[14];
  if ( !v3 )
    v3 = *v2;
  printk(&unk_26EB3, v3, "aw882xx_i2c_shutdown");
  mutex_lock(v1 + 528);
  aw882xx_device_stop(*(_QWORD *)(v1 + 96));
  return mutex_unlock(v1 + 528);
}
