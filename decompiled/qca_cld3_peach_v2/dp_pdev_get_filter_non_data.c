bool __fastcall dp_pdev_get_filter_non_data(__int64 a1)
{
  if ( !*(_WORD *)(*(_QWORD *)(a1 + 96456) + 37074LL) && !*(_WORD *)(*(_QWORD *)(a1 + 96456) + 37080LL) )
    return 0;
  if ( *(_WORD *)(*(_QWORD *)(a1 + 96456) + 37076LL) )
    return 1;
  return *(_WORD *)(*(_QWORD *)(a1 + 96456) + 37082LL) != 0;
}
