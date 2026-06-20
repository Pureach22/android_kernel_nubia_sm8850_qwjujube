__int64 __fastcall dp_soc_set_pdev_status_down(__int64 a1, char a2, char a3)
{
  __int64 v3; // x8

  if ( a2 )
    return 16;
  v3 = *(_QWORD *)(a1 + 72);
  if ( !v3 )
    return 16;
  *(_BYTE *)(v3 + 16) = a3 & 1;
  return 0;
}
