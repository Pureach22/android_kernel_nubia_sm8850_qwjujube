__int64 __fastcall aw882xx_set_fmt(__int64 a1)
{
  __int64 *v1; // x9
  __int64 v2; // x8

  v1 = *(__int64 **)(*(_QWORD *)(a1 + 96) + 24LL);
  v2 = v1[14];
  if ( !v2 )
    v2 = *v1;
  printk(&unk_22BED, v2, "aw882xx_set_fmt");
  return 0;
}
