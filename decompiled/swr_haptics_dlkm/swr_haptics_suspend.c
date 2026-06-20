__int64 __fastcall swr_haptics_suspend(__int64 a1)
{
  if ( a1 && a1 != 72 && *(_QWORD *)(a1 + 152) )
    return 0;
  if ( (unsigned int)__ratelimit(&swr_haptics_suspend__rs, "swr_haptics_suspend") )
    dev_err(a1, "%s: no data for swr_hap\n", "swr_haptics_suspend");
  return 4294967277LL;
}
