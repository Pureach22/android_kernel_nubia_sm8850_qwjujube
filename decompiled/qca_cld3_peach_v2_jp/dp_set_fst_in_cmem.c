__int64 __fastcall dp_set_fst_in_cmem(char a1)
{
  __int64 result; // x0

  result = dp_get_context();
  *(_BYTE *)(result + 1496) = a1;
  return result;
}
