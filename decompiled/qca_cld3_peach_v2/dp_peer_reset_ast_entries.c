__int64 __fastcall dp_peer_reset_ast_entries(__int64 result, __int64 a2)
{
  __int64 v2; // x1
  __int64 v3; // x19
  int v4; // w8
  __int64 v5; // x20

  v2 = *(_QWORD *)(a2 + 216);
  if ( v2 )
  {
    v3 = result;
    do
    {
      v4 = *(_DWORD *)(v2 + 24);
      v5 = *(_QWORD *)(v2 + 48);
      if ( v4 == 7 || v4 == 4 )
        result = dp_peer_del_ast(v3);
      v2 = v5;
    }
    while ( v5 );
  }
  return result;
}
