__int64 __fastcall reset_v1(_DWORD *a1)
{
  int v2; // w2
  __int64 v3; // x1
  __int64 result; // x0
  __int64 v5; // x9
  __int64 v6; // x8
  int v7; // w9
  int v8; // w8
  unsigned int v9; // w1
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x9
  __int64 v15; // x8
  int v16; // w9
  int v17; // w8
  unsigned int v18; // w1
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // [xsp+8h] [xbp-28h] BYREF
  __int64 v23; // [xsp+10h] [xbp-20h]
  __int64 v24; // [xsp+18h] [xbp-18h]
  __int64 v25; // [xsp+20h] [xbp-10h]
  __int64 v26; // [xsp+28h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v2 = 0;
    goto LABEL_6;
  }
  v2 = a1[16];
  if ( v2 >= 7 )
  {
LABEL_6:
    _drm_err("invalid ctl %pK ctl idx %d\n", a1, v2);
    goto LABEL_7;
  }
  LODWORD(v3) = a1[446];
  if ( (unsigned int)v3 >= 2 )
  {
    _drm_err("invalid dpu idx %d\n", v3);
LABEL_7:
    result = 4294967274LL;
LABEL_8:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v24 = 0;
  v25 = 0;
  v5 = reg_dma_0[(unsigned int)v3];
  v23 = 0;
  v6 = *(_QWORD *)(v5 + 16);
  if ( *(_BYTE *)v6
    && (v22 = *(_QWORD *)(v5 + 160),
        v7 = *(_DWORD *)(v6 + 4),
        v8 = *(_DWORD *)(v6 + 24),
        LODWORD(v23) = v7,
        HIDWORD(v24) = v8,
        LODWORD(v25) = 0x4000,
        v8) )
  {
    if ( reg_dma_opmode_offset )
      v9 = 4;
    else
      v9 = 0;
    v10 = sde_reg_write((__int64)&v22, v9, 1u, "reg_dma_opmode_offset");
    v11 = (unsigned int)a1[16];
    if ( (unsigned int)v11 > 6 )
      goto LABEL_36;
    sde_reg_write((__int64)&v22, reg_dma_ctl0_reset_offset[v11], 1u, "reg_dma_ctl0_reset_offset[ctl->idx][k]");
    v10 = _const_udelay(4295000);
    v12 = (unsigned int)a1[16];
    if ( (unsigned int)v12 > 6 )
      goto LABEL_36;
    v10 = sde_reg_read((__int64)&v22, reg_dma_ctl0_reset_offset[v12]);
    if ( (_DWORD)v10 )
    {
      v10 = _const_udelay(4295000);
      v13 = (unsigned int)a1[16];
      if ( (unsigned int)v13 > 6 )
        goto LABEL_36;
      v10 = sde_reg_read((__int64)&v22, reg_dma_ctl0_reset_offset[v13]);
    }
    v3 = (unsigned int)a1[446];
    v22 = 0;
    v23 = 0;
    v24 = 0;
    v25 = 0;
    if ( (unsigned int)v3 > 1 )
      goto LABEL_36;
  }
  else
  {
    v24 = 0;
    v25 = 0;
    v22 = 0;
    v23 = 0;
  }
  v14 = reg_dma_0[(unsigned int)v3];
  v15 = *(_QWORD *)(v14 + 16);
  if ( !*(_BYTE *)(v15 + 12) )
    goto LABEL_35;
  v22 = *(_QWORD *)(v14 + 160);
  v16 = *(_DWORD *)(v15 + 16);
  v17 = *(_DWORD *)(v15 + 24);
  LODWORD(v23) = v16;
  HIDWORD(v24) = v17;
  LODWORD(v25) = 0x4000;
  if ( !v17 )
    goto LABEL_35;
  if ( reg_dma_opmode_offset )
    v18 = 4;
  else
    v18 = 0;
  v10 = sde_reg_write((__int64)&v22, v18, 1u, "reg_dma_opmode_offset");
  v19 = (unsigned int)a1[16];
  if ( (unsigned int)v19 > 6 )
    goto LABEL_36;
  if ( ((8 * v19) | 4uLL) <= 0x38 )
  {
    sde_reg_write((__int64)&v22, HIDWORD(reg_dma_ctl0_reset_offset[v19]), 1u, "reg_dma_ctl0_reset_offset[ctl->idx][k]");
    v10 = _const_udelay(4295000);
    v20 = (unsigned int)a1[16];
    if ( (unsigned int)v20 <= 6 )
    {
      if ( ((8 * v20) | 4uLL) <= 0x38 )
      {
        result = sde_reg_read((__int64)&v22, HIDWORD(reg_dma_ctl0_reset_offset[v20]));
        if ( !(_DWORD)result )
          goto LABEL_8;
        v10 = _const_udelay(4295000);
        v21 = (unsigned int)a1[16];
        if ( (unsigned int)v21 > 6 )
          goto LABEL_36;
        if ( ((8 * v21) | 4uLL) <= 0x38 )
        {
          sde_reg_read((__int64)&v22, HIDWORD(reg_dma_ctl0_reset_offset[v21]));
LABEL_35:
          result = 0;
          goto LABEL_8;
        }
      }
      goto LABEL_37;
    }
LABEL_36:
    __break(0x5512u);
  }
LABEL_37:
  __break(1u);
  return dealloc_reg_dma_v1(v10, v3);
}
