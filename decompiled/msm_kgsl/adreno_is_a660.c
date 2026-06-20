bool __fastcall adreno_is_a660(__int64 a1)
{
  int *v1; // x8
  int v2; // w19
  _BOOL8 result; // x0
  const char *v4; // x0
  bool v5; // w8

  v1 = *(int **)(a1 + 14264);
  v2 = *v1;
  if ( *v1 == 660 )
    return 1;
  v4 = *((const char **)v1 + 3);
  if ( v4 )
    v5 = strcmp(v4, "qcom,adreno-gpu-a642l") == 0;
  else
    v5 = 0;
  result = 1;
  if ( v2 != 643 && !v5 )
    return v2 == 662;
  return result;
}
