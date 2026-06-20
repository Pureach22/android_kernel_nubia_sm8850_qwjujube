__int64 __fastcall aw882xx_dev_get_profile_count(__int64 a1, __int64 a2, __int64 a3)
{
  if ( a1 )
    return *(unsigned int *)(a1 + 624);
  printk(&unk_23AC5, "aw882xx_dev_get_profile_count", a3);
  return 4294967284LL;
}
