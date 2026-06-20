__int64 __fastcall synx_gmem_unlock(unsigned __int8 a1, __int64 a2)
{
  __int64 v4; // x5
  __int64 v6; // x8
  __int64 v7; // x0

  if ( (get_ipclite_feature(4) & 1) != 0 )
    return ipclite_global_spin_unlock(a1, a2);
  v6 = synx_gmem_2;
  if ( *(_WORD *)(synx_gmem_2 + 12) )
  {
    if ( (synx_debug & 2) != 0 )
    {
      printk(&unk_29DF8, "warn", "synx_gmem_lock_owner_clear", 42, *(unsigned __int16 *)(synx_gmem_2 + 12), v4);
      v6 = synx_gmem_2;
    }
  }
  v7 = synx_hwlock;
  *(_WORD *)(v6 + 12) = 8;
  return _hwspin_unlock(v7, 1, a2);
}
