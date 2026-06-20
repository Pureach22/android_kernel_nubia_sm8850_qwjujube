_QWORD *__fastcall clk_regulator_deinit(_QWORD *result)
{
  _QWORD *v1; // x19
  unsigned __int64 v2; // x8
  int v3; // w20
  __int64 v4; // x8

  if ( result[12] )
  {
    v1 = result;
    v2 = 0;
    v3 = 1;
    do
    {
      v4 = *(_QWORD *)(v1[11] + 8 * v2);
      result = memset(*(void **)(v4 + 8), 0, 8LL * *(int *)(v4 + 24));
      v2 = v3++;
    }
    while ( v1[12] > v2 );
  }
  return result;
}
