__int64 __fastcall dp_peer_ast_table_detach(__int64 a1)
{
  __int64 result; // x0

  result = *(_QWORD *)(a1 + 17552);
  if ( result )
  {
    result = _qdf_mem_free(result);
    *(_QWORD *)(a1 + 17552) = 0;
  }
  return result;
}
