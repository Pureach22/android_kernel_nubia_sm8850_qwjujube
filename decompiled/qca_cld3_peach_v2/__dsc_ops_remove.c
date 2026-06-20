bool __fastcall _dsc_ops_remove(int *a1)
{
  int v2; // w9
  _BOOL8 result; // x0

  v2 = *a1 - 1;
  result = *a1 == 1;
  *a1 = v2;
  return result;
}
