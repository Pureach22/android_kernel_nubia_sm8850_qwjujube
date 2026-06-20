__int64 __fastcall adreno_rpmh_to_cx_hlvl(unsigned int *a1, unsigned int a2, _DWORD *a3)
{
  __int64 v3; // x9
  __int64 v4; // x8

  if ( a2 == -1 )
  {
    LODWORD(v4) = -1;
  }
  else
  {
    v3 = *a1;
    if ( !(_DWORD)v3 )
      return 4294967274LL;
    v4 = 0;
    while ( *(unsigned __int16 *)(*((_QWORD *)a1 + 1) + 2 * v4) < a2 )
    {
      if ( v3 == ++v4 )
        return 4294967274LL;
    }
  }
  *a3 = v4;
  return 0;
}
