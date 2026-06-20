unsigned __int64 __fastcall dspp_igcv4_off(__int64 a1, __int64 a2, double a3, double a4, double a5, double a6)
{
  unsigned int v8; // w1
  unsigned __int64 result; // x0
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x3
  __int64 v13; // x4
  unsigned __int64 v14; // x21
  __int64 v15; // x8
  __int64 v16; // x9
  unsigned __int64 *v17; // x8
  __int64 (__fastcall *v18)(_QWORD); // x9
  unsigned __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x9
  __int64 (__fastcall *v22)(_QWORD); // x8
  int v23; // w0
  __int64 v24; // x8
  __int64 (__fastcall *v25)(_QWORD); // x9
  int v26; // w0
  __int64 v27; // x3
  unsigned int v28; // [xsp+Ch] [xbp-54h] BYREF
  int v29; // [xsp+10h] [xbp-50h] BYREF
  int v30; // [xsp+14h] [xbp-4Ch] BYREF
  _DWORD v31[3]; // [xsp+18h] [xbp-48h] BYREF
  __int64 v32; // [xsp+24h] [xbp-3Ch]
  int v33; // [xsp+2Ch] [xbp-34h]
  unsigned __int64 v34; // [xsp+30h] [xbp-30h]
  int *v35; // [xsp+38h] [xbp-28h]
  __int64 v36; // [xsp+40h] [xbp-20h]
  __int64 v37; // [xsp+48h] [xbp-18h]
  __int64 v38; // [xsp+50h] [xbp-10h]
  __int64 v39; // [xsp+58h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_DWORD *)(a1 + 64);
  v28 = 0;
  v29 = 0;
  result = reg_dmav1_get_dspp_blk(a2, v8, &v28, &v29, a3, a4, a5, a6);
  if ( (_DWORD)result == -114 )
    goto LABEL_23;
  if ( (_DWORD)result == -22 )
  {
    result = _drm_err("unable to determine LUTDMA DSPP blocks\n");
LABEL_23:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  result = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1496));
  if ( !result )
    goto LABEL_23;
  v14 = result;
  if ( result > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_23;
  v15 = *(unsigned int *)(a1 + 64);
  if ( (unsigned int)v15 >= 5 )
    goto LABEL_24;
  v16 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v16 > 1 )
    goto LABEL_24;
  if ( (unsigned __int64)(16 * v15 + 8 * v16 + 160) > 0x7D0 )
    goto LABEL_25;
  v17 = &dspp_buf[2 * v15 + v16];
  v18 = *(__int64 (__fastcall **)(_QWORD))(result + 64);
  v19 = v17[20];
  if ( *((_DWORD *)v18 - 1) != -870478129 )
    __break(0x8229u);
  result = v18(v19);
  v20 = *(unsigned int *)(a1 + 64);
  v37 = 0;
  v38 = 0;
  v31[1] = v28;
  v31[2] = 2;
  if ( (unsigned int)v20 > 4 || (v21 = *(unsigned int *)(a1 + 1496), (unsigned int)v21 > 1) )
  {
LABEL_24:
    __break(0x5512u);
    goto LABEL_25;
  }
  if ( (unsigned __int64)(16 * v20 + 8 * v21 + 160) <= 0x7D0 )
  {
    v33 = 0;
    v32 = 0;
    v36 = 0;
    v31[0] = 0;
    v34 = dspp_buf[2 * v20 + 20 + v21];
    v35 = nullptr;
    v22 = *(__int64 (__fastcall **)(_QWORD))(v14 + 8);
    if ( *((_DWORD *)v22 - 1) != -1839634494 )
      __break(0x8228u);
    v23 = v22(v31);
    if ( v23 )
    {
      result = _drm_err("write decode select failed ret %d\n", v23);
    }
    else
    {
      v24 = *(_QWORD *)(a1 + 72);
      v32 = 0;
      v33 = *(_DWORD *)(*(_QWORD *)(v24 + 48) + 20LL) + 4;
      v35 = &v30;
      v36 = 0x400000000LL;
      v25 = *(__int64 (__fastcall **)(_QWORD))(v14 + 8);
      v30 = 0;
      v31[0] = 1;
      if ( *((_DWORD *)v25 - 1) != -1839634494 )
        __break(0x8229u);
      v26 = v25(v31);
      if ( v26 )
      {
        result = _drm_err("setting opcode failed ret %d\n", v26);
      }
      else
      {
        v27 = v28;
        *(_DWORD *)(a2 + 168) = 2;
        result = ((__int64 (__fastcall *)(__int64, __int64, unsigned __int64, __int64, __int64))perform_sbdma_kickoff)(
                   a1,
                   a2,
                   v14,
                   v27,
                   2);
      }
    }
    goto LABEL_23;
  }
LABEL_25:
  __break(1u);
  return reg_dmav2_setup_dspp_igc_common(result, v10, v11, v12, v13);
}
