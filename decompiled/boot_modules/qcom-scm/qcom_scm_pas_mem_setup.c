__int64 __fastcall qcom_scm_pas_mem_setup(unsigned int a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v4; // x1
  __int64 v5; // x2
  __int64 v6; // x3
  __int64 v7; // x4
  __int64 v8; // x5
  __int64 v9; // x6
  __int64 v10; // x7
  __int64 *v11; // x8
  __int64 v12; // x8
  int v13; // w9
  unsigned int v14; // w19
  unsigned int v15; // w0
  __int64 v16; // x19
  int convention; // w0
  __int64 v18; // x2
  unsigned int v19; // w0
  __int64 v20; // x8
  int v21; // w9
  __int64 v22; // x20
  __int64 v23; // x20
  __int64 v24; // x20
  _QWORD v25[3]; // [xsp+8h] [xbp-88h] BYREF
  _QWORD v26[14]; // [xsp+20h] [xbp-70h] BYREF

  v26[13] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26[0] = 0x200000002LL;
  v26[1] = 3;
  v26[2] = a1;
  v26[3] = a2;
  v26[4] = a3;
  memset(&v26[5], 0, 56);
  v26[12] = 2;
  memset(v25, 0, sizeof(v25));
  result = qcom_scm_clk_enable();
  if ( !(_DWORD)result )
  {
    v11 = (__int64 *)_scm;
    if ( *(_QWORD *)(_scm + 32) )
    {
      mutex_lock(_scm + 280);
      v12 = _scm;
      v13 = *(_DWORD *)(_scm + 328);
      if ( v13 )
      {
        v14 = 0;
      }
      else
      {
        v15 = icc_set_bw(*(_QWORD *)(_scm + 32), 0, 0xFFFFFFFFLL);
        v12 = _scm;
        v14 = v15;
        if ( (v15 & 0x80000000) != 0 )
        {
          dev_err(*(_QWORD *)_scm, "failed to set bandwidth request\n");
          goto LABEL_17;
        }
        v13 = *(_DWORD *)(_scm + 328);
      }
      *(_DWORD *)(v12 + 328) = v13 + 1;
      result = mutex_unlock(v12 + 280);
      if ( v14 )
        goto LABEL_19;
      v11 = (__int64 *)_scm;
    }
    v16 = *v11;
    convention = _get_convention(result, v4, v5, v6, v7, v8, v9, v10);
    if ( (unsigned int)(convention - 2) >= 2 )
    {
      if ( convention != 1 )
      {
        printk(&unk_124E9, "qcom_scm_call", v18);
        v14 = -22;
        goto LABEL_14;
      }
      v19 = scm_legacy_call(v16, (__int64)v26, v25);
    }
    else
    {
      v19 = _scm_smc_call(v16, v26, qcom_scm_convention, v25, 0);
    }
    v14 = v19;
LABEL_14:
    if ( !*(_QWORD *)(_scm + 32) )
      goto LABEL_19;
    mutex_lock(_scm + 280);
    v20 = _scm;
    v21 = *(_DWORD *)(_scm + 328) - 1;
    *(_DWORD *)(_scm + 328) = v21;
    if ( v21 )
    {
LABEL_18:
      mutex_unlock(v20 + 280);
LABEL_19:
      v22 = *(_QWORD *)(_scm + 8);
      clk_disable(v22);
      clk_unprepare(v22);
      v23 = *(_QWORD *)(_scm + 16);
      clk_disable(v23);
      clk_unprepare(v23);
      v24 = *(_QWORD *)(_scm + 24);
      clk_disable(v24);
      clk_unprepare(v24);
      if ( v14 )
        result = v14;
      else
        result = LODWORD(v25[0]);
      goto LABEL_22;
    }
    icc_set_bw(*(_QWORD *)(v20 + 32), 0, 0);
LABEL_17:
    v20 = _scm;
    goto LABEL_18;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
