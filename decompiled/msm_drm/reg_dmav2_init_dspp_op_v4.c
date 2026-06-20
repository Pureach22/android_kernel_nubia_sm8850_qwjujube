__int64 __fastcall reg_dmav2_init_dspp_op_v4(signed int a1, __int64 a2, double a3, double a4, double a5, double a6)
{
  __int64 v6; // x15
  __int64 v7; // d14
  unsigned int v9; // w3
  __int64 v10; // x0
  __int64 result; // x0
  unsigned int v12; // w21
  _DWORD **ops; // x8
  __int64 v15; // x9
  _DWORD *v16; // x8
  __int64 v17; // x1
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  unsigned int v22; // w9
  unsigned int v23; // w21
  _BYTE v24[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_DWORD *)(a2 + 64);
  v24[0] = 0;
  if ( a1 > 24 || v9 > 4 || (v10 = *(unsigned int *)(a2 + 1496), (unsigned int)v10 >= 2) )
  {
    _drm_err(
      "invalid feature %d max %d dspp idx %d max %d dpu idx %d max %d\n",
      a1,
      25,
      v9,
      5,
      *(_DWORD *)(a2 + 1496),
      2);
LABEL_5:
    result = 4294966772LL;
LABEL_6:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( (unsigned int)a1 < 0x19 )
  {
    v12 = feature_map[a1];
    if ( ((0xB00uLL >> a1) & 1) != 0 )
    {
      _drm_err("invalid feature map %d for feature %d\n", v12, a1);
      goto LABEL_5;
    }
    ops = (_DWORD **)sde_reg_dma_get_ops(v10);
    result = 4294966772LL;
    if ( !ops || (unsigned __int64)ops > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_6;
    v15 = *(unsigned int *)(a2 + 64);
    if ( (unsigned int)v15 <= 4 )
    {
      v16 = *ops;
      v17 = dspp_mapping[v15];
      if ( *(v16 - 1) != -2032312541 )
        __break(0x8228u);
      LODWORD(result) = ((__int64 (__fastcall *)(_QWORD, __int64, _BYTE *))v16)(v12, v17, v24);
      if ( (v24[0] & 1) != 0 )
        v22 = 0;
      else
        v22 = -524;
      if ( (_DWORD)result )
        result = (unsigned int)result;
      else
        result = v22;
      if ( (v24[0] & 1) != 0 )
      {
        v23 = result;
        reg_dma_init_dspp_feature_buf(a1, a2, v18, v19, v20, v21);
        result = v23;
      }
      goto LABEL_6;
    }
  }
  __break(0x5512u);
  *(_QWORD *)(v6 - 24) = v7;
  *(double *)(v6 - 16) = a6;
  return reg_dmav2_setup_dspp_igcv4();
}
