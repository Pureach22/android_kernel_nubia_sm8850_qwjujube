__int64 __fastcall msm_msi_snps_irq_setup(__int64 a1)
{
  int v2; // w24
  int v3; // w22
  __int64 v4; // x20
  unsigned int v5; // w23
  __int64 i; // x25
  __int64 v7; // x0
  __int64 v8; // x10
  _QWORD *v9; // x2
  __int64 v10; // x8
  _DWORD *v11; // x9
  int v12; // w10
  __int64 result; // x0
  __int64 v14; // x21
  unsigned int v15; // w20
  bool v16; // cf

  if ( *(int *)(a1 + 32) < 1 )
    return 0;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  v5 = -1;
  for ( i = 60; ; i += 1056 )
  {
    v7 = irq_of_parse_and_map(*(_QWORD *)(a1 + 24), (unsigned int)v4);
    if ( !(_DWORD)v7 )
      break;
    v8 = *(_QWORD *)(a1 + 48);
    v9 = (_QWORD *)(v8 + 1056 * v4);
    v10 = 0;
    *v9 = *(_QWORD *)(a1 + 152) + 12 * (int)v4 + 2088;
    v9[1] = *(_QWORD *)(a1 + 152) + 12 * (int)v4 + 2092;
    v9[2] = *(_QWORD *)(a1 + 152) + 12 * (int)v4 + 2096;
    v11 = (_DWORD *)(v8 + i);
    do
    {
      v12 = v2 + v10;
      *(v11 - 3) = v10;
      *(v11 - 2) = v7;
      ++v10;
      *(_QWORD *)(v11 - 5) = v9;
      *v11 = v12;
      v11 += 8;
    }
    while ( v10 != 32 );
    irq_set_chained_handler_and_data(v7, msm_msi_snps_handler, v9);
    ++v4;
    --v3;
    ++v5;
    v2 += 32;
    if ( v4 >= *(int *)(a1 + 32) )
      return 0;
  }
  dev_err(*(_QWORD *)(a1 + 16), "MSI: failed to parse/map interrupt\n");
  if ( (int)v4 - 1 < 0 )
    return 4294967277LL;
  v14 = 1056LL * v5 + 52;
  do
  {
    v15 = *(_DWORD *)(*(_QWORD *)(a1 + 48) + v14);
    irq_set_chained_handler_and_data(v15, 0, 0);
    irq_dispose_mapping(v15);
    v16 = __CFADD__(v3++, 1);
    v14 -= 1056;
    result = 4294967277LL;
  }
  while ( !v16 );
  return result;
}
