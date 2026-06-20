__int64 __fastcall qmp_combo_com_init(_QWORD *a1, char a2)
{
  unsigned int *v2; // x20
  __int64 v3; // x23
  int v5; // w8
  __int64 result; // x0
  int v7; // w0
  unsigned int v8; // w0
  unsigned int v9; // w0
  unsigned int v10; // w0
  unsigned int v11; // w0
  unsigned int v12; // w21
  __int64 v13; // x22
  unsigned int v14; // w24
  unsigned int v15; // w0
  int v16; // w0
  int v17; // w0
  unsigned int v18; // w0
  int v19; // w0
  int v20; // w0
  int v21; // w0
  __int64 v22; // x19
  __int64 v23; // x20
  int v24; // w0

  v3 = a1[1];
  v2 = (unsigned int *)a1[2];
  if ( (a2 & 1) == 0 )
  {
    v5 = *((_DWORD *)a1 + 64);
    *((_DWORD *)a1 + 64) = v5 + 1;
    if ( v5 )
      return 0;
  }
  v7 = regulator_bulk_enable(*(unsigned int *)(v3 + 272), a1[25]);
  if ( v7 )
  {
    v14 = v7;
    dev_err(*a1, "failed to enable regulators, err=%d\n", v7);
    goto LABEL_15;
  }
  v8 = reset_control_assert(a1[23]);
  if ( v8 )
  {
    v14 = v8;
    dev_err(*a1, "phy_reset assert failed\n");
  }
  else
  {
    v9 = reset_control_deassert(a1[23]);
    if ( v9 )
    {
      v14 = v9;
      dev_err(*a1, "phy_reset deassert failed\n");
    }
    else
    {
      if ( *((_DWORD *)a1 + 69) == 2 )
      {
LABEL_10:
        v12 = *((_DWORD *)a1 + 42);
        v13 = a1[20];
        v14 = clk_bulk_prepare(v12, v13);
        if ( !v14 )
        {
          v15 = clk_bulk_enable(v12, v13);
          if ( !v15 )
          {
            v16 = readl(v2 + 2);
            writel(v16 | 1, v2 + 2);
            readl(v2 + 2);
            if ( *((_DWORD *)a1 + 69) != 2 )
            {
              v17 = readl(v2 + 7);
              writel(v17 | 0xF, v2 + 7);
              readl(v2 + 7);
            }
            if ( *((_DWORD *)a1 + 114) == 2 )
              v18 = 3;
            else
              v18 = 2;
            writel(v18, v2 + 4);
            writel(3u, v2);
            if ( *((_DWORD *)a1 + 69) != 2 )
            {
              v19 = readl(v2 + 7);
              writel(v19 & 0xFFFFFFF0, v2 + 7);
              readl(v2 + 7);
            }
            v20 = readl(v2 + 3);
            writel(v20 & 0xFFFFFFFC, v2 + 3);
            readl(v2 + 3);
            v21 = readl(v2 + 1);
            writel(v21 & 0xFFFFFFFE, v2 + 1);
            readl(v2 + 1);
            v22 = a1[6];
            v23 = *(unsigned int *)(*(_QWORD *)(v3 + 280) + 20LL);
            v24 = readl((unsigned int *)(v22 + v23));
            writel(v24 | 1, (unsigned int *)(v22 + v23));
            readl((unsigned int *)(v22 + v23));
            return 0;
          }
          v14 = v15;
          clk_bulk_unprepare(v12, v13);
        }
        reset_control_assert(a1[23]);
        reset_control_assert(a1[24]);
        goto LABEL_14;
      }
      v10 = reset_control_assert(a1[24]);
      if ( v10 )
      {
        v14 = v10;
        dev_err(*a1, "global_phy_reset assert failed\n");
      }
      else
      {
        v11 = reset_control_deassert(a1[24]);
        if ( !v11 )
          goto LABEL_10;
        v14 = v11;
        dev_err(*a1, "global_phy_reset deassert failed\n");
      }
    }
  }
LABEL_14:
  regulator_bulk_disable(*(unsigned int *)(v3 + 272), a1[25]);
LABEL_15:
  result = v14;
  --*((_DWORD *)a1 + 64);
  return result;
}
