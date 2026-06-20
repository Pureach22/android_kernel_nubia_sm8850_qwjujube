__int64 qcom_scm_hdcp_available()
{
  __int64 v0; // x0
  __int64 v1; // x1
  __int64 v2; // x2
  __int64 v3; // x3
  __int64 v4; // x4
  __int64 v5; // x5
  __int64 v6; // x6
  __int64 v7; // x7
  unsigned int v8; // w19
  __int64 v9; // x20
  __int64 convention; // x0
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 v14; // x4
  __int64 v15; // x5
  __int64 v16; // x6
  __int64 v17; // x7
  int v18; // w0
  __int64 v19; // x2
  int v20; // w0
  bool v21; // zf
  __int64 v22; // x20
  __int64 v23; // x20
  __int64 v24; // x20
  _QWORD v26[3]; // [xsp+8h] [xbp-88h] BYREF
  _QWORD v27[2]; // [xsp+20h] [xbp-70h] BYREF
  __int64 v28; // [xsp+30h] [xbp-60h]
  __int64 v29; // [xsp+38h] [xbp-58h]
  __int64 v30; // [xsp+40h] [xbp-50h]
  __int64 v31; // [xsp+48h] [xbp-48h]
  __int64 v32; // [xsp+50h] [xbp-40h]
  __int64 v33; // [xsp+58h] [xbp-38h]
  __int64 v34; // [xsp+60h] [xbp-30h]
  __int64 v35; // [xsp+68h] [xbp-28h]
  __int64 v36; // [xsp+70h] [xbp-20h]
  __int64 v37; // [xsp+78h] [xbp-18h]
  int v38; // [xsp+80h] [xbp-10h]
  int v39; // [xsp+84h] [xbp-Ch]
  __int64 v40; // [xsp+88h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = qcom_scm_clk_enable();
  v8 = 1;
  if ( !(_DWORD)v0 )
  {
    v9 = *(_QWORD *)_scm;
    v37 = 0;
    v39 = 0;
    v35 = 0;
    v36 = 0;
    v27[0] = 0x100000006LL;
    v33 = 0;
    v34 = 0;
    v31 = 0;
    v32 = 0;
    v29 = 0;
    v30 = 0;
    v28 = 0;
    v38 = 2;
    memset(v26, 0, sizeof(v26));
    v27[1] = 1;
    convention = _get_convention(v0, v1, v2, v3, v4, v5, v6, v7);
    if ( (unsigned int)(convention - 1) >= 3 )
    {
      printk(&unk_1227A, "__qcom_scm_is_call_available", v12);
      v8 = 0;
    }
    else
    {
      v28 = qword_136F0[(unsigned int)(convention - 1)];
      v18 = _get_convention(convention, v11, v12, v13, v14, v15, v16, v17);
      if ( (unsigned int)(v18 - 2) >= 2 )
      {
        if ( v18 == 1 )
        {
          v20 = scm_legacy_call(v9, (__int64)v27, v26);
        }
        else
        {
          printk(&unk_124E9, "qcom_scm_call", v19);
          v20 = -22;
        }
      }
      else
      {
        v20 = _scm_smc_call(v9, v27, qcom_scm_convention, v26, 0);
      }
      if ( v20 )
        v21 = 1;
      else
        v21 = v26[0] == 0;
      v8 = !v21;
    }
    v22 = *(_QWORD *)(_scm + 8);
    clk_disable(v22);
    clk_unprepare(v22);
    v23 = *(_QWORD *)(_scm + 16);
    clk_disable(v23);
    clk_unprepare(v23);
    v24 = *(_QWORD *)(_scm + 24);
    clk_disable(v24);
    clk_unprepare(v24);
  }
  _ReadStatusReg(SP_EL0);
  return v8;
}
