__int64 __fastcall qcom_scm_hdcp_req(unsigned int *a1, unsigned int a2, _DWORD *a3)
{
  __int64 v3; // x8
  __int64 v4; // x10
  __int64 v5; // x9
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 result; // x0
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x3
  __int64 v13; // x4
  __int64 v14; // x5
  __int64 v15; // x6
  __int64 v16; // x7
  __int64 v17; // x19
  int convention; // w0
  __int64 v19; // x2
  unsigned int v20; // w0
  unsigned int v21; // w19
  __int64 v22; // x20
  __int64 v23; // x20
  __int64 v24; // x20
  _QWORD v25[3]; // [xsp+8h] [xbp-88h] BYREF
  _QWORD v26[14]; // [xsp+20h] [xbp-70h] BYREF

  v26[13] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26[0] = 0x100000011LL;
  v26[1] = 10;
  v3 = a1[1];
  v26[2] = *a1;
  v26[3] = v3;
  v4 = a1[3];
  v26[4] = a1[2];
  v26[5] = v4;
  v5 = a1[5];
  v26[6] = a1[4];
  v26[7] = v5;
  v6 = a1[7];
  v26[8] = a1[6];
  v26[9] = v6;
  v7 = a1[9];
  v26[10] = a1[8];
  v26[11] = v7;
  v26[12] = 2;
  if ( a2 <= 5 )
  {
    memset(v25, 0, sizeof(v25));
    result = qcom_scm_clk_enable();
    if ( (_DWORD)result )
      goto LABEL_10;
    v17 = *(_QWORD *)_scm;
    convention = _get_convention(result, v10, v11, v12, v13, v14, v15, v16);
    if ( (unsigned int)(convention - 2) >= 2 )
    {
      if ( convention != 1 )
      {
        printk(&unk_124E9, "qcom_scm_call", v19);
        v21 = -22;
        goto LABEL_9;
      }
      v20 = scm_legacy_call(v17, (__int64)v26, v25);
    }
    else
    {
      v20 = _scm_smc_call(v17, v26, qcom_scm_convention, v25, 0);
    }
    v21 = v20;
LABEL_9:
    *a3 = v25[0];
    v22 = *(_QWORD *)(_scm + 8);
    clk_disable(v22);
    clk_unprepare(v22);
    v23 = *(_QWORD *)(_scm + 16);
    clk_disable(v23);
    clk_unprepare(v23);
    v24 = *(_QWORD *)(_scm + 24);
    clk_disable(v24);
    clk_unprepare(v24);
    result = v21;
    goto LABEL_10;
  }
  result = 4294967262LL;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
