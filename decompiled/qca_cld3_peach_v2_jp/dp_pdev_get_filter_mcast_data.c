__int64 __fastcall dp_pdev_get_filter_mcast_data(__int64 a1)
{
  if ( (*(_WORD *)(*(_QWORD *)(a1 + 95560) + 37078LL) & 0x4000) != 0 )
    return 1;
  else
    return (*(unsigned __int16 *)(*(_QWORD *)(a1 + 95560) + 37084LL) >> 14) & 1;
}
