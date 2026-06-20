__int64 __fastcall qcom_icc_rpmh_configure_qos(__int64 a1)
{
  unsigned __int64 v1; // x8
  __int64 v3; // x9
  int i; // w22
  __int64 v5; // x20
  int v6; // w9
  char v7; // w24
  __int64 v8; // x21
  unsigned int v9; // w0
  unsigned __int64 v10; // x9
  unsigned __int64 v11; // x12
  int v12; // w11
  unsigned int v13; // w20
  __int64 v14; // x21
  unsigned int v15; // w0
  unsigned int v16; // w0
  unsigned __int64 v17; // x8
  unsigned __int64 j; // x20
  __int64 v19; // x0
  void (*v20)(void); // x8
  unsigned int v21; // w20
  __int64 v22; // x21
  unsigned __int64 v23; // x8
  __int64 v24; // x9
  int k; // w21
  int v26; // w9
  __int64 v27; // x20
  __int64 v28; // x1
  unsigned __int64 v29; // x9
  unsigned __int64 v30; // x12
  int v31; // w11
  unsigned int v33; // w22
  __int64 v34; // x8
  unsigned int v35; // w19

  v1 = *(_QWORD *)(a1 + 120);
  if ( v1 )
  {
    v3 = 0;
    for ( i = 0; i < v1; v3 = ++i )
    {
      v5 = *(_QWORD *)(*(_QWORD *)(a1 + 112) + 8 * v3);
      v6 = *(_DWORD *)(v5 + 160);
      if ( (*(_BYTE *)(v5 + 115) & 1) == 0 )
      {
        if ( v6 )
          continue;
        v10 = *(_QWORD *)(v5 + 168);
        if ( !v10 )
          continue;
        v11 = 0;
        v12 = 1;
        while ( !*(_QWORD *)(*(_QWORD *)(v5 + 176 + 8 * v11) + 408LL) )
        {
          v11 = v12++;
          if ( v10 <= v11 )
            goto LABEL_4;
        }
        v6 = 0;
      }
      v7 = *(_BYTE *)(v5 + 113);
      *(_BYTE *)(v5 + 113) = 1;
      v8 = *(_QWORD *)(*(_QWORD *)(a1 + 184) + 8LL * v6);
      qcom_icc_bcm_voter_add(v8);
      v9 = qcom_icc_bcm_voter_commit(v8);
      *(_BYTE *)(v5 + 113) = v7;
      if ( v9 )
      {
        v34 = *(_QWORD *)(a1 + 104);
        v35 = v9;
        dev_err(v34, "failed to vote BW to %s for QoS\n", *(const char **)v5);
        return v35;
      }
      v1 = *(_QWORD *)(a1 + 120);
LABEL_4:
      ;
    }
  }
  v13 = *(_DWORD *)(a1 + 176);
  v14 = *(_QWORD *)(a1 + 168);
  v15 = clk_bulk_prepare(v13, v14);
  if ( v15 )
  {
    v33 = v15;
LABEL_40:
    dev_err(*(_QWORD *)(a1 + 104), "failed to enable clocks for QoS\n");
    return v33;
  }
  v16 = clk_bulk_enable(v13, v14);
  if ( v16 )
  {
    v33 = v16;
    clk_bulk_unprepare(v13, v14);
    goto LABEL_40;
  }
  v17 = *(_QWORD *)(a1 + 136);
  if ( v17 )
  {
    for ( j = 0; j < v17; ++j )
    {
      v19 = *(_QWORD *)(*(_QWORD *)(a1 + 128) + 8 * j);
      if ( v19 && *(_QWORD *)(v19 + 408) )
      {
        v20 = **(void (***)(void))(v19 + 416);
        if ( *((_DWORD *)v20 - 1) != 1058342722 )
          __break(0x8228u);
        v20();
        v17 = *(_QWORD *)(a1 + 136);
      }
    }
  }
  v21 = *(_DWORD *)(a1 + 176);
  v22 = *(_QWORD *)(a1 + 168);
  clk_bulk_disable(v21, v22);
  clk_bulk_unprepare(v21, v22);
  v23 = *(_QWORD *)(a1 + 120);
  if ( v23 )
  {
    v24 = 0;
    for ( k = 0; k < v23; v24 = ++k )
    {
      v28 = *(_QWORD *)(*(_QWORD *)(a1 + 112) + 8 * v24);
      v26 = *(_DWORD *)(v28 + 160);
      if ( (*(_BYTE *)(v28 + 115) & 1) == 0 )
      {
        if ( v26 )
          continue;
        v29 = *(_QWORD *)(v28 + 168);
        if ( !v29 )
          continue;
        v30 = 0;
        v31 = 1;
        while ( !*(_QWORD *)(*(_QWORD *)(v28 + 176 + 8 * v30) + 408LL) )
        {
          v30 = v31++;
          if ( v29 <= v30 )
            goto LABEL_28;
        }
        v26 = 0;
      }
      v27 = *(_QWORD *)(*(_QWORD *)(a1 + 184) + 8LL * v26);
      qcom_icc_bcm_voter_add(v27);
      qcom_icc_bcm_voter_commit(v27);
      v23 = *(_QWORD *)(a1 + 120);
LABEL_28:
      ;
    }
  }
  return 0;
}
