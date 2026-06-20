__int64 __fastcall dp_catalog_put_v200(__int64 result)
{
  if ( result )
    return devm_kfree(*(_QWORD *)(*(_QWORD *)(result + 1192) - 24LL));
  return result;
}
