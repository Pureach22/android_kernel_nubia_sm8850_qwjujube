__int64 __fastcall dsi_parser_put(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    dsi_parser_free_mem(*(_QWORD *)(result + 24), *(_QWORD *)(result + 8));
    devm_kfree(*(_QWORD *)(v1 + 24));
    return devm_kfree(*(_QWORD *)(v1 + 24));
  }
  return result;
}
