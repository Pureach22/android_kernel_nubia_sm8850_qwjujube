__int64 __fastcall dp_set_pdev_reo_dest(__int64 a1, char a2, int a3)
{
  __int64 v3; // x8

  if ( a2 )
    return 16;
  v3 = *(_QWORD *)(a1 + 72);
  if ( !v3 )
    return 16;
  *(_DWORD *)(v3 + 95028) = a3;
  return 0;
}
