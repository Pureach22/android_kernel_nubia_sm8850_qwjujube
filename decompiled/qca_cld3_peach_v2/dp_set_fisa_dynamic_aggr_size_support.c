__int64 __fastcall dp_set_fisa_dynamic_aggr_size_support(char a1)
{
  __int64 result; // x0

  result = dp_get_context();
  *(_BYTE *)(result + 1499) = a1;
  return result;
}
