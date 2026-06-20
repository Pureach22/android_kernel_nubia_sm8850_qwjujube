unsigned __int64 __fastcall adreno_coresight_remove(__int64 a1)
{
  unsigned __int64 v2; // x0
  unsigned __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 20664);
  if ( v2 && v2 <= 0xFFFFFFFFFFFFF000LL )
    coresight_unregister();
  result = *(_QWORD *)(a1 + 20696);
  if ( result )
  {
    if ( result <= 0xFFFFFFFFFFFFF000LL )
      return coresight_unregister();
  }
  return result;
}
