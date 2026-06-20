__int64 __fastcall cti_freeze(__int64 a1)
{
  __int64 v1; // x8
  int v2; // w9
  __int64 v3; // x0

  v1 = *(_QWORD *)(a1 + 152);
  v2 = *(unsigned __int8 *)(v1 + 76);
  if ( v2 != 1 )
    return 0;
  v3 = *(_QWORD *)(v1 + 8);
  *(_BYTE *)(v1 + 78) = v2;
  return cti_disable(v3);
}
