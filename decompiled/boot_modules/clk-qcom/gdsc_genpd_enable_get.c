__int64 __fastcall gdsc_genpd_enable_get(__int64 a1, __int64 *a2)
{
  __int64 v2; // x8
  __int64 v3; // x8

  v2 = *(_QWORD *)(a1 + 24);
  if ( v2 )
  {
    if ( *(_DWORD *)(v2 + 500) )
      v3 = (*(_WORD *)(v2 + 488) & 7) != 0;
    else
      v3 = 1;
  }
  else
  {
    v3 = -19;
  }
  *a2 = v3;
  return 0;
}
