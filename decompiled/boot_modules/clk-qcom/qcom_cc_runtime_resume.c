__int64 __fastcall qcom_cc_runtime_resume(__int64 a1)
{
  _QWORD *v2; // x21
  unsigned __int64 v3; // x8
  unsigned __int64 v4; // x9
  int v5; // w22
  const char *v6; // x20
  unsigned int v7; // w0
  __int64 v8; // x0
  unsigned int v9; // w0
  __int64 result; // x0
  unsigned int v11; // w21
  _QWORD v12[6]; // [xsp+0h] [xbp-30h] BYREF

  v12[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(a1 + 152);
  v3 = v2[12];
  memset(v12, 0, 40);
  if ( v3 )
  {
    v4 = 0;
    v5 = 1;
    v6 = "%s: failed to vote voltage\n";
    do
    {
      v12[0] = *(_QWORD *)(v2[11] + 8 * v4);
      if ( v12[0] )
      {
        v7 = clk_vote_vdd_level(v12, 1);
        if ( v7 )
        {
          v11 = v7;
LABEL_14:
          dev_warn(a1, v6, "qcom_cc_runtime_resume");
          result = v11;
          goto LABEL_10;
        }
        v3 = v2[12];
      }
      v4 = v5++;
    }
    while ( v3 > v4 );
  }
  v8 = v2[13];
  if ( v8 )
  {
    v9 = icc_set_bw(v8, 0, 1);
    if ( v9 )
    {
      v11 = v9;
      v6 = "%s: failed to vote bw\n";
      goto LABEL_14;
    }
  }
  result = pm_clk_resume(a1);
  if ( (_DWORD)result )
  {
    v11 = result;
    v6 = "%s: failed to enable clocks\n";
    goto LABEL_14;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
