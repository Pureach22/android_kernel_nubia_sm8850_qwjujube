__int64 __fastcall dp_peer_flush_ast_entries(__int64 result, __int64 a2)
{
  __int64 v2; // x1
  __int64 v3; // x19
  unsigned int v4; // w8
  __int64 v5; // x22
  bool v6; // cf
  int v7; // w8
  bool v8; // zf

  v2 = *(_QWORD *)(a2 + 216);
  if ( v2 )
  {
    v3 = result;
    do
    {
      v4 = *(_DWORD *)(v2 + 24);
      v5 = *(_QWORD *)(v2 + 48);
      v6 = v4 >= 5;
      v8 = v4 == 5;
      v7 = (1 << v4) & 0x26;
      v8 = !v8 && v6 || v7 == 0;
      if ( v8 )
        result = dp_peer_del_ast(v3);
      v2 = v5;
    }
    while ( v5 );
  }
  return result;
}
