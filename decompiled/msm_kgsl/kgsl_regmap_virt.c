__int64 __fastcall kgsl_regmap_virt(_DWORD *a1, __int64 a2)
{
  int v2; // w19
  __int64 result; // x0

  v2 = a2;
  result = kgsl_regmap_get_region(a1, a2);
  if ( result )
    return *(_QWORD *)result + (unsigned int)(4 * (v2 - *(_DWORD *)(result + 8)));
  return result;
}
