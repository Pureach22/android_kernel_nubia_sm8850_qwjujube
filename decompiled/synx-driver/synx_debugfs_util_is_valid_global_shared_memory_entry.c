bool __fastcall synx_debugfs_util_is_valid_global_shared_memory_entry(__int64 a1)
{
  if ( *(_DWORD *)a1 )
    return 1;
  if ( *(_DWORD *)(a1 + 4) )
    return 1;
  if ( *(_WORD *)(a1 + 8) )
    return 1;
  if ( *(_WORD *)(a1 + 10) )
    return 1;
  if ( *(_WORD *)(a1 + 12) )
    return 1;
  if ( *(_WORD *)(a1 + 14) )
    return 1;
  if ( *(_WORD *)(a1 + 16) )
    return 1;
  if ( *(_WORD *)(a1 + 18) )
    return 1;
  if ( *(_WORD *)(a1 + 20) )
    return 1;
  return *(_WORD *)(a1 + 22) != 0;
}
