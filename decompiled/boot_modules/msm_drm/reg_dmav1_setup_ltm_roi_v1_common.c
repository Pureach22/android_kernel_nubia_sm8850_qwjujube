unsigned __int64 __fastcall reg_dmav1_setup_ltm_roi_v1_common(_DWORD *a1, __int64 a2, __int64 a3, int a4)
{
  __int64 v4; // d14
  __int64 v9; // x24
  unsigned __int64 result; // x0
  int v11; // w26
  __int64 v12; // x15
  __int64 v13; // d3
  unsigned __int64 v14; // x21
  __int64 v15; // x8
  __int64 v16; // x25
  _QWORD *v17; // x24
  void (__fastcall *v18)(_QWORD); // x9
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 (__fastcall *v22)(_QWORD); // x8
  unsigned int v23; // w0
  __int64 (__fastcall *v24)(_QWORD); // x9
  unsigned int v25; // w0
  __int64 v26; // x8
  __int64 v27; // x9
  __int64 v28; // x9
  __int64 v29; // x5
  __int64 v30; // x8
  int v31; // w4
  int v32; // w6
  __int64 v33; // x10
  __int64 v34; // x8
  int v35; // w9
  __int64 v36; // x8
  __int64 (__fastcall *v37)(__int64 *, __int64); // x8
  __int64 v38; // x1
  int v39; // [xsp+Ch] [xbp-B4h] BYREF
  __int64 v40; // [xsp+10h] [xbp-B0h] BYREF
  __int64 v41; // [xsp+18h] [xbp-A8h]
  __int64 v42; // [xsp+20h] [xbp-A0h]
  _QWORD v43[5]; // [xsp+28h] [xbp-98h] BYREF
  int v44; // [xsp+50h] [xbp-70h]
  int v45; // [xsp+54h] [xbp-6Ch]
  int v46; // [xsp+58h] [xbp-68h]
  int v47; // [xsp+5Ch] [xbp-64h]
  __int64 v48; // [xsp+60h] [xbp-60h] BYREF
  __int128 v49; // [xsp+68h] [xbp-58h]
  __int64 v50; // [xsp+78h] [xbp-48h]
  __int64 v51; // [xsp+80h] [xbp-40h]
  __int64 v52; // [xsp+88h] [xbp-38h]
  __int64 v53; // [xsp+90h] [xbp-30h]
  __int64 v54; // [xsp+98h] [xbp-28h]
  __int64 v55; // [xsp+A0h] [xbp-20h] BYREF
  __int64 v56; // [xsp+A8h] [xbp-18h]
  unsigned int v57; // [xsp+B0h] [xbp-10h]
  __int64 v58; // [xsp+B8h] [xbp-8h]

  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = (unsigned int)a1[16];
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v50 = 0;
  v48 = 0;
  v49 = 0u;
  v57 = 0;
  v55 = 0;
  v56 = 0;
  v39 = 0;
  result = reg_dmav1_get_ltm_blk(a2, (unsigned int)v9, &v55, &v39);
  if ( (_DWORD)result == -114 )
    goto LABEL_21;
  if ( (_DWORD)result )
  {
    result = _drm_err("failed to get the blk info\n");
    goto LABEL_21;
  }
  v11 = *(_DWORD *)(a2 + 28);
  result = sde_reg_dma_get_ops((unsigned int)a1[374]);
  if ( !result )
    goto LABEL_21;
  v14 = result;
  if ( result > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_21;
  if ( (unsigned int)v9 > 4 )
    goto LABEL_49;
  v15 = (unsigned int)a1[374];
  if ( (unsigned int)v15 > 1 )
    goto LABEL_49;
  v16 = 16 * v9;
  if ( ((16 * v9) | (8 * v15) | 0x500uLL) <= 0x7D0 )
  {
    v17 = &ltm_buf[2 * v9];
    v18 = *(void (__fastcall **)(_QWORD))(result + 64);
    v19 = v17[v15 + 160];
    if ( *((_DWORD *)v18 - 1) != -870478129 )
      __break(0x8229u);
    v18(v19);
    v20 = (unsigned int)a1[374];
    LODWORD(v48) = 0;
    v50 = 0;
    v51 = 0;
    v52 = 0;
    v53 = 0;
    v54 = 0;
    HIDWORD(v48) = v39;
    v49 = 0x10u;
    if ( (unsigned int)v20 > 1 )
      goto LABEL_49;
    if ( (v16 | (8 * v20) | 0x500uLL) <= 0x7D0 )
    {
      HIDWORD(v49) = 0;
      DWORD1(v49) = 0;
      v21 = v17[v20 + 160];
      v52 = 0;
      v50 = v21;
      v51 = 0;
      v22 = *(__int64 (__fastcall **)(_QWORD))(v14 + 8);
      if ( *((_DWORD *)v22 - 1) != -1839634494 )
        __break(0x8228u);
      v23 = v22(&v48);
      if ( v23 )
      {
        result = _drm_err("write decode select failed ret %d\n", v23);
LABEL_21:
        _ReadStatusReg(SP_EL0);
        return result;
      }
      v51 = a3;
      HIDWORD(v49) = 176;
      *(_QWORD *)((char *)&v49 + 4) = 0;
      LODWORD(v52) = 0;
      HIDWORD(v52) = 4 * a4;
      v24 = *(__int64 (__fastcall **)(_QWORD))(v14 + 8);
      LODWORD(v48) = 2;
      if ( *((_DWORD *)v24 - 1) != -1839634494 )
        __break(0x8229u);
      v25 = v24(&v48);
      if ( v25 )
      {
        result = _drm_err("write roi data failed ret %d\n", v25);
        goto LABEL_21;
      }
      if ( !v11 )
      {
        LODWORD(v26) = a1[374];
        v28 = *(_QWORD *)(a2 + 16);
        v42 = 0;
        memset(v43, 0, 24);
        v40 = v28;
        v41 = 0;
        if ( (unsigned int)v26 <= 1 )
        {
LABEL_41:
          v29 = (unsigned int)v26;
          v30 = v16 | (8LL * (unsigned int)v26);
          if ( (v30 | 0x500uLL) > 0x7D0 || v30 == 720 )
            goto LABEL_50;
          LODWORD(v41) = 1;
          v31 = a1[16];
          v32 = a1[7];
          *(_QWORD *)((char *)&v43[1] + 4) = 0x1000000000LL;
          v33 = *(_QWORD *)(a2 + 160);
          v34 = v17[v29 + 160];
          v43[3] = *(_QWORD *)(a2 + 152);
          v43[4] = v33;
          v35 = *(_DWORD *)(a2 + 172);
          LODWORD(v33) = *(_DWORD *)(a2 + 176);
          v42 = v34;
          LODWORD(v34) = *(_DWORD *)(a2 + 168);
          *(_QWORD *)((char *)v43 + 4) = 0;
          v46 = v35;
          v47 = v33;
          LODWORD(v33) = *(_DWORD *)(a2 + 28);
          v44 = v34;
          v45 = v33;
          result = sde_evtlog_log(
                     sde_dbg_base_evtlog,
                     "reg_dmav1_setup_ltm_roi_v1_common",
                     5374,
                     -1,
                     v31,
                     v29,
                     v32,
                     1,
                     239);
          v36 = (unsigned int)a1[7];
          if ( (unsigned int)v36 <= 2 )
          {
            v37 = *(__int64 (__fastcall **)(__int64 *, __int64))(v14 + 8 * v36 + 16);
            if ( v37 )
            {
              v38 = (unsigned int)a1[374];
              if ( *((_DWORD *)v37 - 1) != 1772228465 )
                __break(0x8228u);
              result = v37(&v40, v38);
              if ( (_DWORD)result )
                result = _drm_err("failed to kick off ret %d\n", (unsigned int)result);
            }
            goto LABEL_21;
          }
          goto LABEL_49;
        }
        goto LABEL_49;
      }
      if ( (unsigned int)v55 >= 5 )
        goto LABEL_49;
      v26 = (unsigned int)a1[374];
      if ( (unsigned int)v26 > 1 )
        goto LABEL_49;
      if ( ((8LL * (unsigned int)v55) | (unsigned __int64)(4 * v26)) <= 0x27 )
      {
        ltm_vlut_ops_mask[2 * (unsigned int)v55 + v26] |= 4u;
        if ( v11 == 1 )
          goto LABEL_39;
        if ( HIDWORD(v55) > 4 )
          goto LABEL_49;
        if ( ((8LL * HIDWORD(v55)) | (unsigned __int64)(4 * v26)) > 0x27 )
          goto LABEL_50;
        ltm_vlut_ops_mask[2 * HIDWORD(v55) + v26] |= 4u;
        if ( v11 == 2 )
          goto LABEL_39;
        if ( (unsigned int)v56 > 4 )
          goto LABEL_49;
        if ( ((8LL * (unsigned int)v56) | (unsigned __int64)(4 * v26)) > 0x27 )
          goto LABEL_50;
        ltm_vlut_ops_mask[2 * (unsigned int)v56 + v26] |= 4u;
        if ( v11 == 3 )
          goto LABEL_39;
        if ( HIDWORD(v56) > 4 )
          goto LABEL_49;
        if ( ((8LL * HIDWORD(v56)) | (unsigned __int64)(4 * v26)) > 0x27 )
          goto LABEL_50;
        ltm_vlut_ops_mask[2 * HIDWORD(v56) + v26] |= 4u;
        if ( v11 == 4 )
        {
LABEL_39:
          v27 = *(_QWORD *)(a2 + 16);
          v42 = 0;
          memset(v43, 0, 24);
          v40 = v27;
          v41 = 0;
          goto LABEL_41;
        }
        if ( v57 > 4 )
          goto LABEL_49;
        if ( ((8LL * v57) | (unsigned __int64)(4 * v26)) <= 0x27 )
        {
          ltm_vlut_ops_mask[2 * v57 + v26] |= 4u;
          if ( v11 == 5 )
            goto LABEL_39;
LABEL_49:
          __break(0x5512u);
        }
      }
    }
  }
LABEL_50:
  __break(1u);
  *(_QWORD *)(v12 - 24) = v4;
  *(_QWORD *)(v12 - 16) = v13;
  return reg_dmav1_setup_ltm_roiv1_3();
}
