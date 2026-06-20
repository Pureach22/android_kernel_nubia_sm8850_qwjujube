unsigned __int64 __fastcall reg_dmav2_setup_dspp_igc_common(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        int *a4,
        int a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // d14
  unsigned int v15; // w1
  unsigned __int64 result; // x0
  __int64 *v17; // x25
  __int64 v18; // x15
  __int64 v19; // d3
  unsigned __int64 v20; // x21
  __int64 v21; // x8
  __int64 v22; // x9
  unsigned __int64 *v23; // x8
  void (__fastcall *v24)(_QWORD); // x9
  unsigned __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x9
  __int64 (__fastcall *v28)(_QWORD); // x8
  int v29; // w0
  __int64 (__fastcall *v30)(_QWORD); // x9
  int v31; // w0
  __int64 v32; // x8
  int v33; // w9
  int v34; // w9
  int v35; // w10
  __int64 v36; // x8
  __int64 (__fastcall *v37)(_QWORD); // x9
  int v38; // w0
  __int64 v39; // x3
  unsigned int v40; // [xsp+Ch] [xbp-54h] BYREF
  unsigned int v41; // [xsp+10h] [xbp-50h] BYREF
  int v42; // [xsp+14h] [xbp-4Ch] BYREF
  _DWORD v43[3]; // [xsp+18h] [xbp-48h] BYREF
  __int64 v44; // [xsp+24h] [xbp-3Ch]
  int v45; // [xsp+2Ch] [xbp-34h]
  unsigned __int64 v46; // [xsp+30h] [xbp-30h]
  int *v47; // [xsp+38h] [xbp-28h]
  __int64 v48; // [xsp+40h] [xbp-20h]
  __int64 v49; // [xsp+48h] [xbp-18h]
  __int64 v50; // [xsp+50h] [xbp-10h]
  __int64 v51; // [xsp+58h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = *(_DWORD *)(a1 + 64);
  v40 = 0;
  v41 = 0;
  result = reg_dmav1_get_dspp_blk(a2, v15, &v40, &v41, a6, a7, a8, a9);
  if ( (_DWORD)result == -114 )
    goto LABEL_34;
  if ( (_DWORD)result == -22 )
  {
    result = _drm_err("unable to determine LUTDMA DSPP blocks\n");
LABEL_34:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( v41 >= 6 )
  {
    result = _drm_err("unable to process more than %d DSPP blocks\n", 5);
    goto LABEL_34;
  }
  v17 = *(__int64 **)a2;
  result = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1496));
  if ( !result )
    goto LABEL_34;
  v20 = result;
  if ( result > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_34;
  v21 = *(unsigned int *)(a1 + 64);
  if ( (unsigned int)v21 >= 5 )
    goto LABEL_35;
  v22 = *(unsigned int *)(a1 + 1496);
  if ( (unsigned int)v22 > 1 )
    goto LABEL_35;
  if ( (unsigned __int64)(16 * v21 + 8 * v22 + 160) > 0x7D0 )
    goto LABEL_36;
  v23 = &dspp_buf[2 * v21 + v22];
  v24 = *(void (__fastcall **)(_QWORD))(result + 64);
  v25 = v23[20];
  if ( *((_DWORD *)v24 - 1) != -870478129 )
    __break(0x8229u);
  v24(v25);
  v26 = *(unsigned int *)(a1 + 64);
  v49 = 0;
  v50 = 0;
  v43[1] = v40;
  v43[2] = 2;
  if ( (unsigned int)v26 > 4 || (v27 = *(unsigned int *)(a1 + 1496), (unsigned int)v27 > 1) )
  {
LABEL_35:
    __break(0x5512u);
    goto LABEL_36;
  }
  if ( (unsigned __int64)(16 * v26 + 8 * v27 + 160) <= 0x7D0 )
  {
    v45 = 0;
    v44 = 0;
    v48 = 0;
    v43[0] = 0;
    v46 = dspp_buf[2 * v26 + 20 + v27];
    v47 = nullptr;
    v28 = *(__int64 (__fastcall **)(_QWORD))(v20 + 8);
    if ( *((_DWORD *)v28 - 1) != -1839634494 )
      __break(0x8228u);
    v29 = v28(v43);
    if ( v29 )
    {
      result = _drm_err("write decode select failed ret %d\n", v29);
    }
    else
    {
      v45 = 0;
      v47 = a4;
      v44 = 0;
      LODWORD(v48) = 0;
      HIDWORD(v48) = a3;
      v49 = 0;
      LODWORD(v50) = 3;
      HIDWORD(v50) = a3 / 0xC;
      v30 = *(__int64 (__fastcall **)(_QWORD))(v20 + 8);
      v43[0] = 6;
      if ( *((_DWORD *)v30 - 1) != -1839634494 )
        __break(0x8229u);
      v31 = v30(v43);
      if ( v31 )
      {
        result = _drm_err("lut write failed ret %d\n", v31);
      }
      else
      {
        v32 = *v17;
        v42 = 256;
        if ( (v32 & 1) != 0 )
        {
          v34 = a5 | v17[385] & 0xF;
          v35 = v34 | 0x110;
          v33 = v34 | 0x10110;
          v42 = v35;
        }
        else
        {
          v33 = 65792;
        }
        if ( (v32 & 2) != 0 )
          v42 = v33;
        v36 = *(_QWORD *)(a1 + 72);
        v44 = 0;
        v45 = *(_DWORD *)(*(_QWORD *)(v36 + 48) + 20LL) + 4;
        v47 = &v42;
        v48 = 0x400000000LL;
        v37 = *(__int64 (__fastcall **)(_QWORD))(v20 + 8);
        v43[0] = 1;
        if ( *((_DWORD *)v37 - 1) != -1839634494 )
          __break(0x8229u);
        v38 = v37(v43);
        if ( v38 )
        {
          result = _drm_err("setting opcode failed ret %d\n", v38);
        }
        else
        {
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "reg_dmav2_setup_dspp_igc_common",
            6076,
            -1,
            *(_DWORD *)(a1 + 64),
            *(_DWORD *)(a1 + 1496),
            *(_DWORD *)(a1 + 28),
            1,
            239);
          v39 = v40;
          *(_DWORD *)(a2 + 168) = 3;
          result = ((__int64 (__fastcall *)(__int64, __int64, unsigned __int64, __int64, __int64))perform_sbdma_kickoff)(
                     a1,
                     a2,
                     v20,
                     v39,
                     2);
        }
      }
    }
    goto LABEL_34;
  }
LABEL_36:
  __break(1u);
  *(_QWORD *)(v18 - 24) = v9;
  *(_QWORD *)(v18 - 16) = v19;
  return reg_dmav2_setup_dspp_igcv5();
}
