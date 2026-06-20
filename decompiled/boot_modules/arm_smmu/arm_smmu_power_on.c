__int64 __fastcall arm_smmu_power_on(__int64 a1)
{
  int v2; // w8
  int v3; // w8
  unsigned int v4; // w20
  __int64 v6; // x0
  __int64 v7; // x20
  __int64 v8; // x21
  __int64 v9; // x22
  _QWORD *v10; // x23
  unsigned int v11; // w0
  __int64 v12; // x21
  __int64 v13; // x22
  unsigned int v14; // w0
  unsigned int v15; // w0
  int v16; // w8
  int v17; // w21
  __int64 v18; // x22
  __int64 v19; // x0
  __int64 (__fastcall *v20)(_QWORD); // x8
  unsigned int v21; // w0
  int v22; // w8
  int v23; // w21
  __int64 v24; // x21

  mutex_lock(a1 + 48);
  v2 = *(_DWORD *)(a1 + 96);
  if ( v2 >= 1 )
  {
    v3 = v2 + 1;
LABEL_3:
    v4 = 0;
    *(_DWORD *)(a1 + 96) = v3;
    goto LABEL_4;
  }
  v6 = *(_QWORD *)(a1 + 40);
  if ( !v6 || (v4 = icc_set_bw(v6, 0, 1000)) == 0 )
  {
    v7 = *(unsigned int *)(a1 + 32);
    if ( (int)v7 >= 1 )
    {
      v8 = *(_QWORD *)(a1 + 24);
      v9 = 0;
      v10 = (_QWORD *)(v8 + 8);
      while ( 1 )
      {
        v11 = regulator_enable(*v10);
        if ( v11 )
          break;
        ++v9;
        v10 += 3;
        if ( v7 == v9 )
          goto LABEL_11;
      }
      v4 = v11;
      if ( v9 )
      {
        v18 = v9 + 1;
        do
          regulator_disable(*(_QWORD *)(v8 + 24LL * (unsigned int)(v18-- - 2) + 8));
        while ( v18 > 1 );
      }
      goto LABEL_23;
    }
LABEL_11:
    if ( *(int *)(a1 + 16) < 1 )
    {
LABEL_15:
      v15 = arm_smmu_enable_clocks(a1);
      if ( !v15 )
      {
        v20 = *(__int64 (__fastcall **)(_QWORD))(a1 + 104);
        if ( !v20 )
          goto LABEL_34;
        if ( *((_DWORD *)v20 - 1) != 877532232 )
          __break(0x8228u);
        v21 = v20(a1);
        if ( !v21 )
        {
LABEL_34:
          v3 = 1;
          goto LABEL_3;
        }
        v22 = *(_DWORD *)(a1 + 16);
        v4 = v21;
        if ( !v22 )
          goto LABEL_19;
        v23 = v22 - 1;
        do
          clk_disable(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 8LL * v23--));
        while ( v23 != -1 );
        v15 = v4;
      }
      v16 = *(_DWORD *)(a1 + 16);
      v4 = v15;
      if ( v16 )
      {
        v17 = v16 - 1;
        do
          clk_unprepare(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 8LL * v17--));
        while ( v17 != -1 );
      }
    }
    else
    {
      v12 = 0;
      v13 = 8;
      while ( 1 )
      {
        v14 = clk_prepare(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 8 * v12));
        if ( v14 )
          break;
        ++v12;
        v13 -= 8;
        if ( v12 >= *(int *)(a1 + 16) )
          goto LABEL_15;
      }
      v4 = v14;
      dev_err(*(_QWORD *)a1, "Couldn't prepare clock #%d\n", v12);
      if ( (_DWORD)v12 )
      {
        v24 = -v13;
        do
        {
          clk_unprepare(*(_QWORD *)(*(_QWORD *)(a1 + 8) + v24));
          v24 -= 8;
        }
        while ( v24 != -8 );
      }
    }
LABEL_19:
    regulator_bulk_disable(*(unsigned int *)(a1 + 32), *(_QWORD *)(a1 + 24));
LABEL_23:
    v19 = *(_QWORD *)(a1 + 40);
    if ( v19 && (unsigned int)icc_set_bw(v19, 0, 0) )
      __break(0x800u);
  }
LABEL_4:
  mutex_unlock(a1 + 48);
  return v4;
}
