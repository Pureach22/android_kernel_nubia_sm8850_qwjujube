__int64 __fastcall ufs_qcom_enable_lane_clks(__int64 a1)
{
  __int64 v2; // x21
  __int64 v4; // x20
  unsigned int v5; // w0
  unsigned int v6; // w0
  __int64 v7; // x22
  unsigned int v8; // w0
  unsigned int v9; // w0
  __int64 v10; // x22
  unsigned int v11; // w0
  unsigned int v12; // w0
  unsigned int v13; // w0
  __int64 v14; // x20
  unsigned int v15; // w21
  unsigned int v16; // w19
  __int64 v17; // x20
  __int64 v18; // x19

  if ( (*(_BYTE *)(a1 + 128) & 1) != 0 )
    return 0;
  v2 = *(_QWORD *)(a1 + 96);
  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 64LL);
  v5 = clk_prepare(v2);
  if ( v5 )
  {
    v16 = v5;
LABEL_16:
    dev_err(v4, "%s: %s enable failed %d\n", "ufs_qcom_host_clk_enable", "rx_lane0_sync_clk", v16);
    return v16;
  }
  v6 = clk_enable(v2);
  if ( v6 )
  {
    v16 = v6;
    clk_unprepare(v2);
    goto LABEL_16;
  }
  v7 = *(_QWORD *)(a1 + 104);
  v8 = clk_prepare(v7);
  if ( v8 )
  {
    v15 = v8;
  }
  else
  {
    v9 = clk_enable(v7);
    if ( !v9 )
    {
      if ( *(_DWORD *)(*(_QWORD *)(a1 + 16) + 2688LL) < 2u )
        goto LABEL_13;
      v10 = *(_QWORD *)(a1 + 112);
      v11 = clk_prepare(v10);
      if ( v11 )
      {
        v15 = v11;
      }
      else
      {
        v12 = clk_enable(v10);
        if ( !v12 )
        {
          if ( *(_QWORD *)(a1 + 120) )
          {
            v13 = ufs_qcom_host_clk_enable(v4, "tx_lane1_sync_clk");
            if ( v13 )
            {
              v14 = *(_QWORD *)(a1 + 112);
              v15 = v13;
              clk_disable(v14);
              clk_unprepare(v14);
LABEL_23:
              v17 = *(_QWORD *)(a1 + 104);
              clk_disable(v17);
              clk_unprepare(v17);
              goto LABEL_24;
            }
          }
LABEL_13:
          *(_BYTE *)(a1 + 128) = 1;
          return 0;
        }
        v15 = v12;
        clk_unprepare(v10);
      }
      dev_err(v4, "%s: %s enable failed %d\n", "ufs_qcom_host_clk_enable", "rx_lane1_sync_clk", v15);
      goto LABEL_23;
    }
    v15 = v9;
    clk_unprepare(v7);
  }
  dev_err(v4, "%s: %s enable failed %d\n", "ufs_qcom_host_clk_enable", "tx_lane0_sync_clk", v15);
LABEL_24:
  v18 = *(_QWORD *)(a1 + 96);
  clk_disable(v18);
  clk_unprepare(v18);
  return v15;
}
