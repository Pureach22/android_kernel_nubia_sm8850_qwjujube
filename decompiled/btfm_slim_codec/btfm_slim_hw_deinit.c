__int64 __fastcall btfm_slim_hw_deinit(__int64 a1, __int64 a2, __int64 a3)
{
  printk(&unk_8E30, "btfm_slim_hw_deinit", a3);
  if ( !a1 )
    return 4294967274LL;
  if ( *(_BYTE *)(a1 + 1072) )
  {
    mutex_lock(a1 + 976);
    *(_BYTE *)(a1 + 1072) = 0;
    mutex_unlock(a1 + 976);
  }
  return 0;
}
