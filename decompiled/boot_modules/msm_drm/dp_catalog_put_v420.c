__int64 __fastcall dp_catalog_put_v420(__int64 result)
{
  if ( result )
    return devm_kfree(*(_QWORD *)(*(_QWORD *)(result + 1192) - 8LL));
  return result;
}
