__int64 __fastcall qcom_scm_pas_init_image(unsigned int a1, const void *a2, size_t a3, _QWORD *a4, __int64 a5)
{
  __int64 v8; // x8
  __int64 v9; // x21
  void *v10; // x0
  void *v11; // x22
  __int64 v12; // x0
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x4
  __int64 v17; // x5
  __int64 v18; // x6
  __int64 v19; // x7
  unsigned int v20; // w23
  __int64 *v21; // x8
  __int64 v22; // x8
  int v23; // w9
  unsigned int v24; // w0
  __int64 v25; // x23
  int convention; // w0
  __int64 v27; // x2
  unsigned int v28; // w0
  __int64 v29; // x8
  int v30; // w9
  __int64 v31; // x24
  __int64 v32; // x24
  __int64 v33; // x24
  __int64 v34; // x8
  __int64 result; // x0
  __int64 v36; // [xsp+0h] [xbp-90h] BYREF
  _QWORD v37[3]; // [xsp+8h] [xbp-88h] BYREF
  __int64 v38; // [xsp+20h] [xbp-70h] BYREF
  int v39; // [xsp+28h] [xbp-68h]
  int v40; // [xsp+2Ch] [xbp-64h]
  __int64 v41; // [xsp+30h] [xbp-60h]
  __int64 v42; // [xsp+38h] [xbp-58h]
  __int64 v43; // [xsp+40h] [xbp-50h]
  __int64 v44; // [xsp+48h] [xbp-48h]
  __int64 v45; // [xsp+50h] [xbp-40h]
  __int64 v46; // [xsp+58h] [xbp-38h]
  __int64 v47; // [xsp+60h] [xbp-30h]
  __int64 v48; // [xsp+68h] [xbp-28h]
  __int64 v49; // [xsp+70h] [xbp-20h]
  __int64 v50; // [xsp+78h] [xbp-18h]
  int v51; // [xsp+80h] [xbp-10h]
  int v52; // [xsp+84h] [xbp-Ch]
  __int64 v53; // [xsp+88h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)_scm;
  v38 = 0x100000002LL;
  v40 = 0;
  v39 = 130;
  if ( a5 )
    v9 = a5;
  else
    v9 = v8;
  v41 = a1;
  v36 = 0;
  v50 = 0;
  v52 = 0;
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v51 = 2;
  memset(v37, 0, sizeof(v37));
  v10 = (void *)dma_alloc_attrs(v9, a3, &v36, 3264, 0);
  if ( !v10 )
  {
    dev_err(v9, "Allocation of metadata buffer failed.\n");
    result = 4294967284LL;
    goto LABEL_32;
  }
  v11 = v10;
  memcpy(v10, a2, a3);
  v12 = qcom_scm_clk_enable();
  v20 = v12;
  if ( !(_DWORD)v12 )
  {
    v21 = (__int64 *)_scm;
    if ( *(_QWORD *)(_scm + 32) )
    {
      mutex_lock(_scm + 280);
      v22 = _scm;
      v23 = *(_DWORD *)(_scm + 328);
      if ( v23 )
      {
        v20 = 0;
      }
      else
      {
        v24 = icc_set_bw(*(_QWORD *)(_scm + 32), 0, 0xFFFFFFFFLL);
        v22 = _scm;
        v20 = v24;
        if ( (v24 & 0x80000000) != 0 )
        {
          dev_err(*(_QWORD *)_scm, "failed to set bandwidth request\n");
          goto LABEL_23;
        }
        v23 = *(_DWORD *)(_scm + 328);
      }
      *(_DWORD *)(v22 + 328) = v23 + 1;
      v12 = mutex_unlock(v22 + 280);
      if ( v20 )
        goto LABEL_25;
      v21 = (__int64 *)_scm;
    }
    v42 = v36;
    v25 = *v21;
    convention = _get_convention(v12, v13, v14, v15, v16, v17, v18, v19);
    if ( (unsigned int)(convention - 2) >= 2 )
    {
      if ( convention != 1 )
      {
        printk(&unk_124E9, "qcom_scm_call", v27);
        v20 = -22;
        goto LABEL_20;
      }
      v28 = scm_legacy_call(v25, (__int64)&v38, v37);
    }
    else
    {
      v28 = _scm_smc_call(v25, &v38, qcom_scm_convention, v37, 0);
    }
    v20 = v28;
LABEL_20:
    if ( !*(_QWORD *)(_scm + 32) )
      goto LABEL_25;
    mutex_lock(_scm + 280);
    v29 = _scm;
    v30 = *(_DWORD *)(_scm + 328) - 1;
    *(_DWORD *)(_scm + 328) = v30;
    if ( v30 )
    {
LABEL_24:
      mutex_unlock(v29 + 280);
LABEL_25:
      v31 = *(_QWORD *)(_scm + 8);
      clk_disable(v31);
      clk_unprepare(v31);
      v32 = *(_QWORD *)(_scm + 16);
      clk_disable(v32);
      clk_unprepare(v32);
      v33 = *(_QWORD *)(_scm + 24);
      clk_disable(v33);
      clk_unprepare(v33);
      if ( !a4 )
        goto LABEL_28;
      goto LABEL_26;
    }
    icc_set_bw(*(_QWORD *)(v29 + 32), 0, 0);
LABEL_23:
    v29 = _scm;
    goto LABEL_24;
  }
  if ( !a4 )
    goto LABEL_28;
LABEL_26:
  if ( (v20 & 0x80000000) == 0 )
  {
    v34 = v36;
    a4[2] = a3;
    *a4 = v11;
    a4[1] = v34;
    goto LABEL_29;
  }
LABEL_28:
  dma_free_attrs(v9, a3, v11, v36, 0);
LABEL_29:
  if ( v20 )
    result = v20;
  else
    result = LODWORD(v37[0]);
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
