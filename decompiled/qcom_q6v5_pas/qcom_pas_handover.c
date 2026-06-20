__int64 __fastcall qcom_pas_handover(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x20
  __int64 v4; // x20
  __int64 result; // x0
  int v6; // w20
  __int64 v7; // x22
  int v8; // w21
  __int64 v9; // x19
  __int64 v10; // x20
  int v11; // w21
  __int64 v13; // x20
  int v14; // w0
  __int64 v15; // x20
  int v16; // w0

  if ( *(_BYTE *)(a1 + 1304) == 1 )
  {
    v10 = *(_QWORD *)(a1 + 1288);
    v11 = -50;
    while ( 1 )
    {
      usleep_range_state(100, 200, 2);
      if ( (readl(v10) & 8) != 0 )
        break;
      if ( __CFADD__(v11++, 1) )
      {
        v13 = *(_QWORD *)(a1 - 24);
        v14 = readl(*(_QWORD *)(a1 + 1288));
        dev_err(v13, "state not changed in handover TCSR val = %d\n", v14);
        goto LABEL_2;
      }
    }
    v15 = *(_QWORD *)(a1 - 24);
    v16 = readl(*(_QWORD *)(a1 + 1288));
    dev_info(v15, "state changed in handover for soccp! TCSR val = %d\n", v16);
  }
LABEL_2:
  if ( *(_QWORD *)(a1 + 368) )
    ((void (*)(void))regulator_disable)();
  if ( *(_QWORD *)(a1 + 360) )
    ((void (*)(void))regulator_disable)();
  if ( *(_DWORD *)(a1 + 384) - 1 >= 0 )
  {
    v2 = 16LL * (unsigned int)(*(_DWORD *)(a1 + 384) - 1);
    do
    {
      regulator_set_voltage(*(_QWORD *)(*(_QWORD *)(a1 + 376) + v2), 0, 0x7FFFFFFF);
      regulator_set_load(*(_QWORD *)(*(_QWORD *)(a1 + 376) + v2), 0);
      regulator_disable(*(_QWORD *)(*(_QWORD *)(a1 + 376) + v2));
      v2 -= 16;
    }
    while ( v2 != -16 );
  }
  v3 = *(_QWORD *)(a1 + 352);
  clk_disable(v3);
  clk_unprepare(v3);
  v4 = *(_QWORD *)(a1 + 344);
  clk_disable(v4);
  result = clk_unprepare(v4);
  v6 = *(_DWORD *)(a1 + 416);
  if ( v6 )
  {
    v7 = 0;
    v8 = 0;
    v9 = a1 + 392;
    do
    {
      dev_pm_genpd_set_performance_state(*(_QWORD *)(v9 + 8 * v7), 0);
      result = _pm_runtime_idle(*(_QWORD *)(v9 + 8 * v7), 5);
      v7 = ++v8;
    }
    while ( v6 != v8 );
  }
  return result;
}
