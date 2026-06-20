__int64 __fastcall ieee80211_amsdu_realloc_pad(__int64 a1, __int64 a2, unsigned int a3)
{
  if ( *(_DWORD *)(a2 + 224) - *(_DWORD *)(a2 + 216) >= a3 )
    return 1;
  if ( !(unsigned int)pskb_expand_head(a2, a3, 0, 2080) )
    return 1;
  dev_printk(&unk_BBEF5, *(_QWORD *)(a1 + 72) + 392LL, "failed to reallocate TX buffer\n");
  return 0;
}
