__int64 __fastcall msm_msi_qgic_irq_setup(__int64 a1)
{
  unsigned int v2; // w20
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x10
  __int64 result; // x0
  int v8; // w21
  unsigned int v9; // w20

  if ( *(int *)(a1 + 32) < 1 )
    return 0;
  v2 = 0;
  while ( 1 )
  {
    v3 = irq_of_parse_and_map(*(_QWORD *)(a1 + 24), v2);
    if ( !(_DWORD)v3 )
      break;
    v4 = *(_QWORD *)(a1 + 48) + 1056LL * (v2 >> 5);
    v5 = v2 & 0x1F;
    v6 = v4 + 32 * v5;
    *(_QWORD *)(v6 + 40) = v4;
    *(_DWORD *)(v6 + 60) = v2;
    *(_DWORD *)(v6 + 48) = v5;
    *(_DWORD *)(v6 + 52) = v3;
    irq_set_chained_handler_and_data(v3, msm_msi_qgic_handler, a1);
    if ( (signed int)++v2 >= *(_DWORD *)(a1 + 32) )
      return 0;
  }
  dev_err(*(_QWORD *)(a1 + 16), "MSI: failed to parse/map interrupt\n");
  if ( !v2 )
    return 4294967277LL;
  v8 = v2 + 1;
  do
  {
    v9 = *(_DWORD *)(*(_QWORD *)(a1 + 48) + 1056LL * ((unsigned int)(v8 - 2) >> 5) + 32LL * ((v8 - 2) & 0x1F) + 52);
    irq_set_chained_handler_and_data(v9, 0, 0);
    irq_dispose_mapping(v9);
    --v8;
    result = 4294967277LL;
  }
  while ( v8 > 1 );
  return result;
}
