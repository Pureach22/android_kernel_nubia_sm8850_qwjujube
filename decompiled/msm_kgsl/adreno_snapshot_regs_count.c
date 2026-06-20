unsigned __int64 __fastcall adreno_snapshot_regs_count(unsigned __int64 result)
{
  int v1; // w9
  unsigned __int64 v2; // x8
  int *v3; // x8
  bool v4; // zf
  int v5; // w11
  int v6; // t1
  int v7; // w11

  v1 = *(_DWORD *)result;
  if ( *(_DWORD *)result == -1 )
    return 0;
  v2 = result;
  LODWORD(result) = 0;
  v3 = (int *)(v2 + 8);
  do
  {
    v5 = *(v3 - 1) - v1;
    v4 = *(v3 - 1) == v1;
    v6 = *v3;
    v3 += 2;
    v1 = v6;
    v7 = v5 + 3;
    if ( v4 )
      v7 = 2;
    result = (unsigned int)(v7 + result);
  }
  while ( v1 != -1 );
  return result;
}
