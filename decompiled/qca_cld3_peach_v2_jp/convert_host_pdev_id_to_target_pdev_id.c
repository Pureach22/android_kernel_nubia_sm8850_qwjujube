__int64 __fastcall convert_host_pdev_id_to_target_pdev_id(__int64 a1, unsigned int a2)
{
  if ( a2 > 2 )
    return 0;
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 760) + 7748LL) == 1 )
    return *(unsigned int *)(*(_QWORD *)(a1 + 856) + 4LL * a2);
  return a2 + 1;
}
