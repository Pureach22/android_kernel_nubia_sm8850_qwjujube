int *__fastcall cam_cdm_write_regrandom(int *a1, int a2, _DWORD *a3)
{
  _DWORD *v3; // x8
  int *result; // x0
  int v5; // w9

  if ( a2 )
  {
    *a1 = (unsigned __int16)a2 | 0x4000000;
    v3 = a1 + 1;
    do
    {
      result = v3 + 2;
      --a2;
      *v3 = *a3;
      v5 = a3[1];
      a3 += 2;
      v3[1] = v5;
      v3 += 2;
    }
    while ( a2 );
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_cdm_write_regrandom",
      311,
      "Number of reg-val pairs can not be 0");
    return a1;
  }
  return result;
}
