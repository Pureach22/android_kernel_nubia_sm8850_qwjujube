__int64 __fastcall slc_mpam_version(__int64 a1, _DWORD *a2)
{
  __int64 v2; // x8
  __int64 v3; // x9

  v2 = *(_QWORD *)(a1 + 152);
  if ( !v2 )
    return 4294967274LL;
  v3 = *(_QWORD *)(v2 + 16);
  if ( !v3 || (*(_BYTE *)(v2 + 88) & 2) == 0 )
    return 4294967274LL;
  *a2 = *(_DWORD *)(v3 + 32);
  return 0;
}
