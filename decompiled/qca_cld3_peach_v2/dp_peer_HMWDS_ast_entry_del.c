__int64 __fastcall dp_peer_HMWDS_ast_entry_del(__int64 a1, __int64 a2)
{
  if ( *(_BYTE *)(a1 + 17706) != 1 )
    return 4294967292LL;
  dp_del_wds_entry_wrapper(a1, a2);
  return 0;
}
