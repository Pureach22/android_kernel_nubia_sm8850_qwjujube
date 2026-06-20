__int64 __fastcall kgsl_icc_set_tag(__int64 a1, int a2)
{
  int v2; // w9
  __int64 v3; // x0
  __int64 v4; // x1

  v2 = *(_DWORD *)(a1 + 324);
  v3 = *(_QWORD *)(a1 + 1624);
  if ( v2 == a2 )
    v4 = 263;
  else
    v4 = 7;
  return icc_set_tag(v3, v4);
}
