__int64 __fastcall qcom_cc_runtime_suspend(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  _QWORD *v7; // x22
  __int64 v8; // x0
  unsigned __int64 v9; // x8
  int v10; // w23
  _QWORD v12[6]; // [xsp+0h] [xbp-30h] BYREF

  v12[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD **)(a1 + 152);
  memset(v12, 0, 40);
  if ( (unsigned int)pm_clk_suspend(a1, a2, a3, a4, a5, a6) )
  {
    dev_warn(a1, "%s: failed to disable clocks\n", "qcom_cc_runtime_suspend");
    v8 = v7[13];
    if ( !v8 )
      goto LABEL_5;
  }
  else
  {
    v8 = v7[13];
    if ( !v8 )
      goto LABEL_5;
  }
  if ( (unsigned int)icc_set_bw(v8, 0, 0) )
    dev_warn(a1, "%s: failed to unvote bw\n", "qcom_cc_runtime_suspend");
LABEL_5:
  if ( v7[12] )
  {
    v9 = 0;
    v10 = 1;
    do
    {
      v12[0] = *(_QWORD *)(v7[11] + 8 * v9);
      if ( v12[0] && (unsigned int)clk_unvote_vdd_level(v12, 1) )
        dev_warn(a1, "%s: failed to unvote voltage\n", "qcom_cc_runtime_suspend");
      v9 = v10++;
    }
    while ( v7[12] > v9 );
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
