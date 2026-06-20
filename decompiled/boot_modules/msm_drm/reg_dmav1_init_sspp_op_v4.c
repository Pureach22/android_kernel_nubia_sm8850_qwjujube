__int64 __fastcall reg_dmav1_init_sspp_op_v4(int a1, __int64 a2)
{
  __int64 v2; // x22
  __int64 v3; // d8
  __int64 v4; // d30
  unsigned int v6; // w3
  __int64 v7; // x0
  __int64 result; // x0
  unsigned int v9; // w19
  _DWORD **ops; // x8
  __int64 v11; // x9
  _DWORD *v12; // x8
  __int64 v13; // x1
  int v14; // w8
  unsigned int v15; // w10
  __int64 v16; // x23
  __int64 v17; // x21
  unsigned int v18; // w20
  unsigned __int64 v19; // x0
  __int64 v20; // x1
  int v21; // w8
  unsigned __int64 v22; // x8
  unsigned __int64 *v23; // x24
  __int64 v24; // x9
  _DWORD *v25; // x8
  unsigned __int64 v26; // x0
  __int64 v27; // x24
  __int64 v28; // x21
  unsigned __int64 v29; // x0
  unsigned __int64 v30; // x8
  unsigned __int64 *v31; // x24
  __int64 v32; // x9
  _DWORD *v33; // x8
  unsigned __int64 v34; // x0
  __int64 v35; // x21
  unsigned __int64 v36; // x0
  unsigned __int64 v37; // x8
  unsigned __int64 *v38; // x19
  _DWORD *v39; // x8
  unsigned __int64 v40; // x0
  int v41; // w19
  unsigned int v42; // w19
  _BYTE v43[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v44; // [xsp+8h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_DWORD *)(a2 + 48);
  v43[0] = 0;
  if ( a1 > 44 || v6 > 0xE || (v7 = *(unsigned int *)(a2 + 1392), (unsigned int)v7 >= 2) )
  {
    _drm_err(
      "invalid feature %x max %x sspp idx %x max %xd dpu idx %x max %xd\n",
      a1,
      45,
      v6,
      15,
      *(_DWORD *)(a2 + 1392),
      2);
LABEL_5:
    result = 4294966772LL;
LABEL_6:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( (unsigned int)a1 >= 0x2D )
    goto LABEL_62;
  v9 = sspp_feature_map[a1];
  if ( v9 >= 0x19 )
  {
    _drm_err("invalid feature map %d for feature %d\n", v9, a1);
    goto LABEL_5;
  }
  v2 = a2;
  ops = (_DWORD **)sde_reg_dma_get_ops(v7);
  result = 4294966772LL;
  if ( !ops || (unsigned __int64)ops > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_6;
  v11 = *(unsigned int *)(v2 + 48);
  if ( (unsigned int)v11 > 0xE )
    goto LABEL_62;
  v12 = *ops;
  v13 = sspp_mapping[v11];
  if ( *(v12 - 1) != -2032312541 )
    __break(0x8228u);
  LODWORD(result) = ((__int64 (__fastcall *)(_QWORD, __int64, _BYTE *))v12)(v9, v13, v43);
  v14 = result;
  if ( (v43[0] & 1) != 0 )
    v15 = 0;
  else
    v15 = -524;
  if ( (_DWORD)result )
    result = (unsigned int)result;
  else
    result = v15;
  if ( v14 || (v43[0] & 1) == 0 )
    goto LABEL_6;
  v16 = *(unsigned int *)(v2 + 48);
  if ( (unsigned int)v16 > 0xE )
    goto LABEL_62;
  v17 = *(unsigned int *)(v2 + 1392);
  if ( (unsigned int)v17 > 2 )
    goto LABEL_62;
  v18 = sspp_feature_reg_dma_sz[a1];
  v19 = sde_reg_dma_get_ops((unsigned int)v17);
  v20 = 0;
  v21 = -524;
  if ( !v19 || v19 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_61;
  v22 = 16 * v16 + 240LL * v9 + 8 * v17;
  v23 = (unsigned __int64 *)((char *)&sspp_buf + v22);
  if ( !(_UNKNOWN *)((char *)&sspp_buf + v22) )
  {
    v41 = 0;
LABEL_60:
    _drm_err("invalid buf\n", v20);
    v21 = -22;
    LODWORD(v20) = v41;
    goto LABEL_61;
  }
  if ( v22 >> 4 > 0x464 )
    goto LABEL_63;
  v24 = v2;
  if ( !*v23 )
  {
    v25 = *(_DWORD **)(v19 + 48);
    if ( *(v25 - 1) != 70798817 )
      __break(0x8228u);
    v26 = ((__int64 (__fastcall *)(_QWORD, _QWORD))v25)(v18, (unsigned int)v17);
    LODWORD(v20) = 0;
    v21 = -22;
    *v23 = v26;
    if ( !v26 )
      goto LABEL_61;
    v24 = v2;
    if ( v26 >= 0xFFFFFFFFFFFFF001LL )
      goto LABEL_61;
  }
  v27 = *(unsigned int *)(v24 + 48);
  if ( (unsigned int)v27 > 0xE || (v28 = *(unsigned int *)(v24 + 1392), (unsigned int)v28 > 2) )
  {
LABEL_62:
    __break(0x5512u);
    goto LABEL_63;
  }
  v29 = sde_reg_dma_get_ops((unsigned int)v28);
  v21 = -524;
  v20 = 1;
  if ( !v29 || v29 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_61;
  v30 = 16 * v27 + 240LL * v9 + 8 * v28 + 6000;
  v31 = (unsigned __int64 *)((char *)&sspp_buf + v30);
  if ( !(_UNKNOWN *)((char *)&sspp_buf + v30) )
  {
    v41 = 1;
    goto LABEL_60;
  }
  if ( v30 >> 4 > 0x464 )
    goto LABEL_63;
  v32 = v2;
  if ( !*v31 )
  {
    v33 = *(_DWORD **)(v29 + 48);
    if ( *(v33 - 1) != 70798817 )
      __break(0x8228u);
    v34 = ((__int64 (__fastcall *)(_QWORD, _QWORD))v33)(v18, (unsigned int)v28);
    v21 = -22;
    LODWORD(v20) = 1;
    *v31 = v34;
    if ( !v34 )
      goto LABEL_61;
    v32 = v2;
    if ( v34 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_61;
  }
  v2 = *(unsigned int *)(v32 + 48);
  if ( (unsigned int)v2 > 0xE )
    goto LABEL_62;
  v35 = *(unsigned int *)(v32 + 1392);
  if ( (unsigned int)v35 > 2 )
    goto LABEL_62;
  v36 = sde_reg_dma_get_ops((unsigned int)v35);
  v21 = -524;
  v20 = 2;
  if ( !v36 || v36 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_61;
  v37 = 16 * v2 + 240LL * v9 + 8 * v35 + 12000;
  v38 = (unsigned __int64 *)((char *)&sspp_buf + v37);
  if ( !(_UNKNOWN *)((char *)&sspp_buf + v37) )
  {
    v41 = 2;
    goto LABEL_60;
  }
  if ( v37 >> 4 <= 0x464 )
  {
    if ( *v38 )
      goto LABEL_56;
    v39 = *(_DWORD **)(v36 + 48);
    if ( *(v39 - 1) != 70798817 )
      __break(0x8228u);
    v40 = ((__int64 (__fastcall *)(_QWORD, _QWORD))v39)(v18, (unsigned int)v35);
    v21 = -22;
    LODWORD(v20) = 2;
    *v38 = v40;
    if ( v40 )
    {
      if ( v40 <= 0xFFFFFFFFFFFFF000LL )
      {
LABEL_56:
        result = 0;
        goto LABEL_6;
      }
    }
LABEL_61:
    v42 = v21;
    _drm_err("rect %d buf init failed\n", v20);
    result = v42;
    goto LABEL_6;
  }
LABEL_63:
  __break(1u);
  *(_QWORD *)(v2 - 16) = v3;
  *(_QWORD *)(v2 - 8) = v4;
  return reg_dmav1_setup_vig_gamutv5();
}
