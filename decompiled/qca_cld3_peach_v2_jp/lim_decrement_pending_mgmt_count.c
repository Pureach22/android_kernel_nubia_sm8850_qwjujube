__int64 __fastcall lim_decrement_pending_mgmt_count(__int64 a1)
{
  int v2; // w8

  raw_spin_lock(a1 + 12744);
  v2 = *(_DWORD *)(a1 + 12724);
  if ( v2 )
    *(_DWORD *)(a1 + 12724) = v2 - 1;
  return raw_spin_unlock(a1 + 12744);
}
