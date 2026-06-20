__int64 __fastcall qcom_scm_pas_shutdown(unsigned int a1)
{
  __int64 result; // x0
  __int64 v2; // x1
  __int64 v3; // x2
  __int64 v4; // x3
  __int64 v5; // x4
  __int64 v6; // x5
  __int64 v7; // x6
  __int64 v8; // x7
  __int64 *v9; // x8
  __int64 v10; // x8
  int v11; // w9
  unsigned int v12; // w19
  unsigned int v13; // w0
  __int64 v14; // x19
  int convention; // w0
  __int64 v16; // x2
  unsigned int v17; // w0
  __int64 v18; // x8
  int v19; // w9
  __int64 v20; // x20
  __int64 v21; // x20
  __int64 v22; // x20
  _QWORD v23[3]; // [xsp+8h] [xbp-88h] BYREF
  __int64 v24; // [xsp+20h] [xbp-70h] BYREF
  int v25; // [xsp+28h] [xbp-68h]
  int v26; // [xsp+2Ch] [xbp-64h]
  __int64 v27; // [xsp+30h] [xbp-60h]
  __int64 v28; // [xsp+38h] [xbp-58h]
  __int64 v29; // [xsp+40h] [xbp-50h]
  __int64 v30; // [xsp+48h] [xbp-48h]
  __int64 v31; // [xsp+50h] [xbp-40h]
  __int64 v32; // [xsp+58h] [xbp-38h]
  __int64 v33; // [xsp+60h] [xbp-30h]
  __int64 v34; // [xsp+68h] [xbp-28h]
  __int64 v35; // [xsp+70h] [xbp-20h]
  __int64 v36; // [xsp+78h] [xbp-18h]
  int v37; // [xsp+80h] [xbp-10h]
  int v38; // [xsp+84h] [xbp-Ch]
  __int64 v39; // [xsp+88h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  v38 = 0;
  v24 = 0x600000002LL;
  v26 = 0;
  v25 = 1;
  v27 = a1;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v37 = 2;
  memset(v23, 0, sizeof(v23));
  result = qcom_scm_clk_enable();
  if ( !(_DWORD)result )
  {
    v9 = (__int64 *)_scm;
    if ( *(_QWORD *)(_scm + 32) )
    {
      mutex_lock(_scm + 280);
      v10 = _scm;
      v11 = *(_DWORD *)(_scm + 328);
      if ( v11 )
      {
        v12 = 0;
      }
      else
      {
        v13 = icc_set_bw(*(_QWORD *)(_scm + 32), 0, 0xFFFFFFFFLL);
        v10 = _scm;
        v12 = v13;
        if ( (v13 & 0x80000000) != 0 )
        {
          dev_err(*(_QWORD *)_scm, "failed to set bandwidth request\n");
          goto LABEL_17;
        }
        v11 = *(_DWORD *)(_scm + 328);
      }
      *(_DWORD *)(v10 + 328) = v11 + 1;
      result = mutex_unlock(v10 + 280);
      if ( v12 )
        goto LABEL_19;
      v9 = (__int64 *)_scm;
    }
    v14 = *v9;
    convention = _get_convention(result, v2, v3, v4, v5, v6, v7, v8);
    if ( (unsigned int)(convention - 2) >= 2 )
    {
      if ( convention != 1 )
      {
        printk(&unk_124E9, "qcom_scm_call", v16);
        v12 = -22;
        goto LABEL_14;
      }
      v17 = scm_legacy_call(v14, (__int64)&v24, v23);
    }
    else
    {
      v17 = _scm_smc_call(v14, &v24, qcom_scm_convention, v23, 0);
    }
    v12 = v17;
LABEL_14:
    if ( !*(_QWORD *)(_scm + 32) )
      goto LABEL_19;
    mutex_lock(_scm + 280);
    v18 = _scm;
    v19 = *(_DWORD *)(_scm + 328) - 1;
    *(_DWORD *)(_scm + 328) = v19;
    if ( v19 )
    {
LABEL_18:
      mutex_unlock(v18 + 280);
LABEL_19:
      v20 = *(_QWORD *)(_scm + 8);
      clk_disable(v20);
      clk_unprepare(v20);
      v21 = *(_QWORD *)(_scm + 16);
      clk_disable(v21);
      clk_unprepare(v21);
      v22 = *(_QWORD *)(_scm + 24);
      clk_disable(v22);
      clk_unprepare(v22);
      if ( v12 )
        result = v12;
      else
        result = LODWORD(v23[0]);
      goto LABEL_22;
    }
    icc_set_bw(*(_QWORD *)(v18 + 32), 0, 0);
LABEL_17:
    v18 = _scm;
    goto LABEL_18;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
