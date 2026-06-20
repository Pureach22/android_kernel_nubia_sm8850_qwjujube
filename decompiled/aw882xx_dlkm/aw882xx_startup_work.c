__int64 __fastcall aw882xx_startup_work(__int64 a1)
{
  __int64 *v1; // x8
  __int64 v3; // x1

  v1 = *(__int64 **)(a1 - 48);
  v3 = v1[14];
  if ( !v3 )
    v3 = *v1;
  printk(&unk_26EB3, v3, "aw882xx_startup_work");
  mutex_lock(a1 + 416);
  aw882xx_start_pa(a1 - 112);
  return mutex_unlock(a1 + 416);
}
