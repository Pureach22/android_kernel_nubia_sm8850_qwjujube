__int64 __fastcall ieee80211_min_bw_limit_from_chandef(__int64 a1)
{
  __int64 v1; // x1

  v1 = *(unsigned int *)(a1 + 8);
  if ( (unsigned int)v1 < 0xE && ((0x203Fu >> v1) & 1) != 0 )
    return dword_C0F50[v1];
  _warn_printk("unhandled chandef width %d\n", v1);
  __break(0x800u);
  return 0;
}
