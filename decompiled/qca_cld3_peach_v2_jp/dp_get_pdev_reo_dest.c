__int64 __fastcall dp_get_pdev_reo_dest(__int64 a1, char a2)
{
  __int64 v2; // x8

  if ( a2 )
    return 0;
  v2 = *(_QWORD *)(a1 + 72);
  if ( !v2 )
    return 0;
  else
    return *(unsigned int *)(v2 + 95028);
}
