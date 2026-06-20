__int64 __fastcall mhi_controller_get_base(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL) + 80LL);
  if ( !v2 )
    return 4294967274LL;
  *a2 = v2;
  return 0;
}
