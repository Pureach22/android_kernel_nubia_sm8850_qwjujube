__int64 __fastcall aw882xx_dev_set_profile_index(__int64 a1, unsigned int a2)
{
  __int64 *v3; // x9
  __int64 v4; // x8

  if ( (a2 & 0x80000000) != 0 || *(_DWORD *)(a1 + 624) <= a2 )
    return 4294967274LL;
  v3 = *(__int64 **)(a1 + 112);
  *(_BYTE *)(a1 + 49) = a2;
  v4 = v3[14];
  if ( !v4 )
    v4 = *v3;
  printk(&unk_28BF1, v4, "aw882xx_dev_set_profile_index");
  return 0;
}
