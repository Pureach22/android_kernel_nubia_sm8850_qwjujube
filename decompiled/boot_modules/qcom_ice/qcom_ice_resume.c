__int64 __fastcall qcom_ice_resume(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x20
  unsigned int v4; // w0
  unsigned int v5; // w0
  __int64 v6; // x0
  int v7; // w0
  __int64 v8; // x1
  __int64 v9; // x0
  unsigned int v11; // w19

  if ( *(_BYTE *)(a1 + 35) != 1 )
    goto LABEL_4;
  v2 = *(_QWORD *)(a1 + 24);
  v3 = *(_QWORD *)a1;
  v4 = clk_prepare(v2);
  if ( v4 )
  {
    v11 = v4;
LABEL_13:
    dev_err(v3, "failed to enable core clock (%d)\n", v11);
    return v11;
  }
  v5 = clk_enable(v2);
  if ( v5 )
  {
    v11 = v5;
    clk_unprepare(v2);
    goto LABEL_13;
  }
LABEL_4:
  if ( *(_BYTE *)(a1 + 33) == 1 )
  {
    v6 = *(_QWORD *)(a1 + 8);
    if ( *(unsigned __int8 *)(a1 + 32) < 2u )
    {
      v8 = v6 + 36864;
      v9 = 7;
    }
    else
    {
      v7 = readl(v6);
      v8 = *(_QWORD *)(a1 + 8);
      v9 = v7 & 0xFFFFFFFE;
    }
    writel(v9, v8);
  }
  qcom_ice_hwkm_init(a1);
  return qcom_ice_wait_bist_status((_QWORD *)a1);
}
