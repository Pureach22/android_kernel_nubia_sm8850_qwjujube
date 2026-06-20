__int64 __fastcall reg_dmav1_init_dspp_op_v4(unsigned int a1, __int64 a2)
{
  unsigned int v3; // w3
  __int64 v4; // x0
  __int64 result; // x0
  unsigned int v6; // w21
  _DWORD **ops; // x8
  __int64 v9; // x1
  __int64 v10; // x9
  _DWORD *v11; // x8
  unsigned int v12; // w9
  _BYTE v13[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a2 + 64);
  v13[0] = 0;
  if ( (int)a1 > 24 || v3 > 4 || (v4 = *(unsigned int *)(a2 + 1496), (unsigned int)v4 >= 2) )
  {
    _drm_err(
      "invalid feature %x max %x dspp idx %x max %xd dpu idx %x max %xd\n",
      a1,
      25,
      v3,
      5,
      *(_DWORD *)(a2 + 1496),
      2);
LABEL_5:
    result = 4294966772LL;
LABEL_6:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( a1 < 0x19 )
  {
    v6 = feature_map[a1];
    if ( ((0xB00uLL >> a1) & 1) != 0 )
    {
      _drm_err("invalid feature map %d for feature %d\n", v6, a1);
      goto LABEL_5;
    }
    ops = (_DWORD **)sde_reg_dma_get_ops(v4);
    result = 4294966772LL;
    if ( !ops || (unsigned __int64)ops > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_6;
    if ( a1 == 1 )
    {
      v9 = 0x20000;
LABEL_16:
      v11 = *ops;
      if ( *(v11 - 1) != -2032312541 )
        __break(0x8228u);
      LODWORD(result) = ((__int64 (__fastcall *)(_QWORD, __int64, _BYTE *))v11)(v6, v9, v13);
      if ( (v13[0] & 1) != 0 )
        v12 = 0;
      else
        v12 = -524;
      if ( (_DWORD)result )
        result = (unsigned int)result;
      else
        result = v12;
      if ( (v13[0] & 1) != 0 )
        result = reg_dma_init_dspp_feature_buf(a1, a2);
      goto LABEL_6;
    }
    v10 = *(unsigned int *)(a2 + 64);
    if ( (unsigned int)v10 <= 4 )
    {
      v9 = dspp_mapping[v10];
      goto LABEL_16;
    }
  }
  __break(0x5512u);
  return ((__int64 (*)(void))reg_dma_init_dspp_feature_buf)();
}
