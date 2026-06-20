__int64 __fastcall dfs_detach(__int64 a1)
{
  timer_delete_sync(a1 + 168);
  *(_BYTE *)(a1 + 152) &= ~4u;
  return dfs_nol_detach(a1);
}
