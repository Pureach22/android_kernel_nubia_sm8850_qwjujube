__int64 __fastcall synx_gmem_lock(unsigned __int8 a1, __int64 a2)
{
  __int64 v4; // x4
  __int64 v5; // x5
  __int64 result; // x0

  if ( (get_ipclite_feature(4) & 1) != 0 )
    return ipclite_global_spin_lock_timeout(a1, 500, a2);
  if ( synx_hwlock )
  {
    result = _hwspin_lock_timeout(synx_hwlock, 500, 1, a2);
    if ( !(_DWORD)result )
      *(_WORD *)(synx_gmem_2 + 12) = 0;
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_2AE54, &unk_29207, "synx_gmem_lock", 54, v4, v5);
    return 4294967274LL;
  }
  return result;
}
