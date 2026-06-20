__int64 qcom_scm_disable_sdi()
{
  __int64 result; // x0
  __int64 v1; // x1
  __int64 v2; // x2
  __int64 v3; // x3
  __int64 v4; // x4
  __int64 v5; // x5
  __int64 v6; // x6
  __int64 v7; // x7
  __int64 v8; // x19
  int convention; // w0
  __int64 v10; // x2
  unsigned int v11; // w0
  unsigned int v12; // w19
  __int64 v13; // x20
  __int64 v14; // x20
  __int64 v15; // x20
  _QWORD v16[3]; // [xsp+8h] [xbp-88h] BYREF
  __int64 v17; // [xsp+20h] [xbp-70h] BYREF
  int v18; // [xsp+28h] [xbp-68h]
  int v19; // [xsp+2Ch] [xbp-64h]
  __int64 v20; // [xsp+30h] [xbp-60h]
  __int64 v21; // [xsp+38h] [xbp-58h]
  __int64 v22; // [xsp+40h] [xbp-50h]
  __int64 v23; // [xsp+48h] [xbp-48h]
  __int64 v24; // [xsp+50h] [xbp-40h]
  __int64 v25; // [xsp+58h] [xbp-38h]
  __int64 v26; // [xsp+60h] [xbp-30h]
  __int64 v27; // [xsp+68h] [xbp-28h]
  __int64 v28; // [xsp+70h] [xbp-20h]
  __int64 v29; // [xsp+78h] [xbp-18h]
  int v30; // [xsp+80h] [xbp-10h]
  int v31; // [xsp+84h] [xbp-Ch]
  __int64 v32; // [xsp+88h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  v31 = 0;
  v17 = 0x900000001LL;
  v19 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v18 = 2;
  v20 = 1;
  v30 = 2;
  memset(v16, 0, sizeof(v16));
  result = qcom_scm_clk_enable();
  if ( !(_DWORD)result )
  {
    v8 = *(_QWORD *)_scm;
    convention = _get_convention(result, v1, v2, v3, v4, v5, v6, v7);
    if ( (unsigned int)(convention - 2) >= 2 )
    {
      if ( convention != 1 )
      {
        printk(&unk_124E9, "qcom_scm_call", v10);
        v12 = -22;
LABEL_7:
        v13 = *(_QWORD *)(_scm + 8);
        clk_disable(v13);
        clk_unprepare(v13);
        v14 = *(_QWORD *)(_scm + 16);
        clk_disable(v14);
        clk_unprepare(v14);
        v15 = *(_QWORD *)(_scm + 24);
        clk_disable(v15);
        clk_unprepare(v15);
        if ( v12 )
          result = v12;
        else
          result = LODWORD(v16[0]);
        goto LABEL_10;
      }
      v11 = scm_legacy_call(v8, (__int64)&v17, v16);
    }
    else
    {
      v11 = _scm_smc_call(v8, &v17, qcom_scm_convention, v16, 0);
    }
    v12 = v11;
    goto LABEL_7;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
