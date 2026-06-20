__int64 __fastcall dp_get_pdev_mlo_timestamp_offset(__int64 a1, char a2)
{
  __int64 v2; // x8

  if ( a2 )
    return 16;
  v2 = *(_QWORD *)(a1 + 72);
  if ( !v2 )
    return 16;
  else
    return *(_QWORD *)(v2 + 96476);
}
