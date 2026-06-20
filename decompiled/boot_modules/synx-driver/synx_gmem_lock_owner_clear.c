__int64 __fastcall synx_gmem_lock_owner_clear(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x8
  __int64 result; // x0

  v6 = synx_gmem_2;
  if ( *(_WORD *)(synx_gmem_2 + 12) && (synx_debug & 2) != 0 )
  {
    result = printk(&unk_29DF8, "warn", "synx_gmem_lock_owner_clear", 42, *(unsigned __int16 *)(synx_gmem_2 + 12), a6);
    v6 = synx_gmem_2;
  }
  *(_WORD *)(v6 + 12) = 8;
  return result;
}
