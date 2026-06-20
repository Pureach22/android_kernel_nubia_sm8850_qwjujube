__int64 __fastcall dp_link_put(__int64 result)
{
  if ( result )
    return devm_kfree(*(_QWORD *)(result - 16));
  return result;
}
