__int64 __fastcall qmp_combo_typec_switch_set(__int64 a1, int a2)
{
  __int64 drvdata; // x0
  __int64 v4; // x19
  __int64 v5; // x22
  int v6; // w8
  _QWORD *v7; // x21
  __int64 v8; // x20
  __int64 v9; // x23
  __int64 v10; // x20
  __int64 v11; // x24
  int v12; // w0
  __int64 v13; // x20
  __int64 v14; // x24
  int v15; // w0
  __int64 v16; // x20
  __int64 v17; // x21
  int v18; // w0
  unsigned int v19; // w20
  __int64 v20; // x21
  __int64 v21; // x23
  void (__fastcall *v22)(_QWORD); // x8

  drvdata = typec_switch_get_drvdata();
  if ( a2 )
  {
    v4 = drvdata;
    if ( *(_DWORD *)(drvdata + 456) != a2 )
    {
      v5 = *(_QWORD *)(drvdata + 8);
      mutex_lock(drvdata + 208);
      v6 = *(_DWORD *)(v4 + 256);
      *(_DWORD *)(v4 + 456) = a2;
      if ( v6 )
      {
        if ( *(_DWORD *)(v4 + 280) )
        {
          v7 = *(_QWORD **)(*(_QWORD *)(v4 + 264) + 152LL);
          v8 = v7[16];
          v9 = v7[1];
          clk_disable(v8);
          clk_unprepare(v8);
          clk_set_parent(v7[17], v7[19]);
          v10 = v7[6];
          v11 = **(unsigned int **)(v9 + 280);
          v12 = readl((unsigned int *)(v10 + v11));
          writel(v12 | 1, (unsigned int *)(v10 + v11));
          readl((unsigned int *)(v10 + v11));
          v13 = v7[6];
          v14 = *(unsigned int *)(*(_QWORD *)(v9 + 280) + 4LL);
          v15 = readl((unsigned int *)(v13 + v14));
          writel(v15 & 0xFFFFFFFC, (unsigned int *)(v13 + v14));
          readl((unsigned int *)(v13 + v14));
          v16 = v7[6];
          v17 = *(unsigned int *)(*(_QWORD *)(v9 + 280) + 20LL);
          v18 = readl((unsigned int *)(v16 + v17));
          writel(v18 & 0xFFFFFFFE, (unsigned int *)(v16 + v17));
          readl((unsigned int *)(v16 + v17));
        }
        v19 = *(_DWORD *)(v4 + 168);
        v20 = *(_QWORD *)(v4 + 160);
        v21 = *(_QWORD *)(v4 + 8);
        clk_bulk_disable(v19, v20);
        clk_bulk_unprepare(v19, v20);
        regulator_bulk_disable(*(unsigned int *)(v21 + 272), *(_QWORD *)(v4 + 200));
        qmp_combo_com_init(v4, 1);
        if ( *(_DWORD *)(v4 + 280) )
          qmp_combo_usb_power_on(*(_QWORD *)(v4 + 264));
        if ( *(_DWORD *)(v4 + 344) )
        {
          v22 = *(void (__fastcall **)(_QWORD))(v5 + 240);
          if ( *((_DWORD *)v22 - 1) != -1494932575 )
            __break(0x8228u);
          v22(v4);
        }
      }
      mutex_unlock(v4 + 208);
    }
  }
  return 0;
}
