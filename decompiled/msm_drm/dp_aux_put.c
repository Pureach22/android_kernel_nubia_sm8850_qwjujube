__int64 __fastcall dp_aux_put(__int64 result)
{
  if ( result )
    return devm_kfree(*(_QWORD *)(result - 8));
  return result;
}
