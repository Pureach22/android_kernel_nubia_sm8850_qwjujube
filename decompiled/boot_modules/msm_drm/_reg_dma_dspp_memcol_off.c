unsigned __int64 __fastcall reg_dma_dspp_memcol_off(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7)
{
  unsigned int v10; // w1
  unsigned __int64 result; // x0
  __int64 v12; // x26
  unsigned __int64 v13; // x22
  __int64 v14; // x8
  __int64 v15; // x9
  void (__fastcall *v16)(_QWORD); // x10
  unsigned __int64 v17; // x0
  __int64 v18; // x8
  unsigned int v19; // w24
  unsigned int v20; // w25
  unsigned __int64 v21; // x27
  __int64 v22; // x26
  __int64 v23; // x8
  unsigned int v24; // w9
  __int64 v25; // x8
  __int64 v26; // x9
  __int64 (__fastcall *v27)(_QWORD); // x8
  unsigned int v28; // w0
  __int64 v29; // x8
  __int64 v30; // x8
  __int64 (__fastcall *v31)(_QWORD); // x8
  __int64 v32; // x9
  __int64 v33; // x8
  __int64 v34; // x1
  int v35; // w10
  int v36; // w12
  __int64 v37; // x11
  int v38; // w9
  int v39; // w10
  unsigned __int64 v40; // x11
  __int64 v41; // x8
  int v42; // w10
  __int64 (__fastcall *v43)(_QWORD); // x8
  __int64 v44; // [xsp+8h] [xbp-D8h] BYREF
  __int64 v45; // [xsp+10h] [xbp-D0h] BYREF
  __int64 v46; // [xsp+18h] [xbp-C8h] BYREF
  __int64 v47; // [xsp+20h] [xbp-C0h]
  unsigned __int64 v48; // [xsp+28h] [xbp-B8h]
  __int64 v49; // [xsp+30h] [xbp-B0h]
  __int64 v50; // [xsp+38h] [xbp-A8h]
  __int64 v51; // [xsp+40h] [xbp-A0h]
  __int64 v52; // [xsp+48h] [xbp-98h]
  int v53; // [xsp+50h] [xbp-90h]
  int v54; // [xsp+54h] [xbp-8Ch]
  int v55; // [xsp+58h] [xbp-88h]
  int v56; // [xsp+5Ch] [xbp-84h]
  int v57; // [xsp+60h] [xbp-80h]
  int v58; // [xsp+64h] [xbp-7Ch]
  __int64 v59; // [xsp+68h] [xbp-78h] BYREF
  __int128 v60; // [xsp+70h] [xbp-70h]
  unsigned __int64 v61; // [xsp+80h] [xbp-60h]
  char *v62; // [xsp+88h] [xbp-58h]
  __int64 v63; // [xsp+90h] [xbp-50h]
  __int64 v64; // [xsp+98h] [xbp-48h]
  __int64 v65; // [xsp+A0h] [xbp-40h]
  _QWORD dest[7]; // [xsp+A8h] [xbp-38h] BYREF

  dest[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_DWORD *)(a1 + 64);
  v64 = 0;
  v65 = 0;
  v62 = nullptr;
  v63 = 0;
  v61 = 0;
  v59 = 0;
  v60 = 0u;
  v44 = 0;
  v45 = 0;
  result = reg_dmav1_get_dspp_blk(a2, v10, &v44, (_DWORD *)&v44 + 1, a4, a5, a6, a7);
  if ( (_DWORD)result != -114 )
  {
    if ( (_DWORD)result == -22 )
    {
      result = _drm_err("unable to determine LUTDMA DSPP blocks\n");
      goto LABEL_6;
    }
    v12 = HIDWORD(v44);
    if ( HIDWORD(v44) >= 6 )
    {
      result = _drm_err("unable to process more than %d DSPP blocks\n", 5);
      goto LABEL_6;
    }
    memset(dest, 0, 40);
    if ( HIDWORD(v44) < 2 )
      dest[0] = a1;
    else
      memcpy(dest, (const void *)(a2 + 48), 8LL * HIDWORD(v44));
    result = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1496));
    if ( result )
    {
      v13 = result;
      if ( result <= 0xFFFFFFFFFFFFF000LL )
      {
        v14 = *(unsigned int *)(a1 + 64);
        if ( (unsigned int)v14 <= 4 )
        {
          v15 = *(unsigned int *)(a1 + 1496);
          if ( (unsigned int)v15 <= 1 )
          {
            if ( ((16 * v14 + 80LL * a3) | (unsigned __int64)(8 * v15)) > 0x7CF )
              goto LABEL_46;
            v16 = *(void (__fastcall **)(_QWORD))(result + 64);
            v17 = dspp_buf[10 * a3 + 2 * v14 + v15];
            if ( *((_DWORD *)v16 - 1) != -870478129 )
              __break(0x822Au);
            v16(v17);
            v18 = (int)a3 - 5LL;
            v19 = dword_29D23C[(int)v18];
            result = cp_feature_get_curr_mode(dword_29D28C[v18], *(_QWORD *)(a2 + 200), &v45);
            if ( (v45 & 0x3F) != 0 )
              v20 = v19;
            else
              v20 = v19 & 0xFFEFFFFF;
            if ( (_DWORD)v12 )
            {
              v21 = 0;
              v22 = 8 * v12;
              while ( 1 )
              {
                if ( v21 > 0x27 )
                  goto LABEL_46;
                v23 = *(unsigned int *)(dest[v21 / 8] + 64LL);
                if ( (unsigned int)v23 > 4 )
                  goto LABEL_45;
                v59 = 0;
                v60 = 0u;
                v24 = dspp_mapping[v23];
                v25 = *(unsigned int *)(a1 + 64);
                v61 = 0;
                v62 = nullptr;
                v63 = 0;
                LODWORD(v44) = v24;
                v64 = 0;
                v65 = 0;
                HIDWORD(v59) = v24;
                LODWORD(v60) = a3;
                if ( (unsigned int)v25 > 4 )
                  goto LABEL_45;
                v26 = *(unsigned int *)(a1 + 1496);
                if ( (unsigned int)v26 > 1 )
                  goto LABEL_45;
                if ( ((80LL * a3 + 16 * v25) | (unsigned __int64)(8 * v26)) > 0x7CF )
                  goto LABEL_46;
                HIDWORD(v60) = 0;
                DWORD1(v60) = 0;
                v62 = nullptr;
                v63 = 0;
                v61 = dspp_buf[10 * a3 + 2 * v25 + v26];
                v27 = *(__int64 (__fastcall **)(_QWORD))(v13 + 8);
                if ( *((_DWORD *)v27 - 1) != -1839634494 )
                  __break(0x8228u);
                v28 = v27(&v59);
                if ( v28 )
                {
                  result = _drm_err("write decode select failed ret %d\n", v28);
                  goto LABEL_6;
                }
                v29 = *(_QWORD *)(a1 + 72);
                *(_QWORD *)((char *)&v60 + 4) = 0;
                v62 = (char *)&v45 + 4;
                v30 = *(_QWORD *)(v29 + 48);
                LODWORD(v59) = 5;
                HIDWORD(v60) = *(_DWORD *)(v30 + 128);
                v63 = v20 | 0x400000000LL;
                v31 = *(__int64 (__fastcall **)(_QWORD))(v13 + 8);
                if ( *((_DWORD *)v31 - 1) != -1839634494 )
                  __break(0x8228u);
                result = v31(&v59);
                if ( (_DWORD)result )
                  break;
                v21 += 8LL;
                if ( v22 == v21 )
                  goto LABEL_34;
              }
              result = _drm_err("setting reg failed ret %d\n", (unsigned int)result);
              goto LABEL_6;
            }
LABEL_34:
            v32 = *(_QWORD *)(a2 + 16);
            v48 = 0;
            v49 = 0;
            *(_DWORD *)(a2 + 168) = 2;
            v33 = *(unsigned int *)(a1 + 64);
            v50 = 0;
            v51 = 0;
            v46 = v32;
            v47 = 0;
            if ( (unsigned int)v33 <= 4 )
            {
              v34 = *(unsigned int *)(a1 + 1496);
              if ( (unsigned int)v34 <= 1 )
              {
                if ( ((16 * v33 + 80LL * a3) | (unsigned __int64)(8 * v34)) > 0x7CF )
                  goto LABEL_46;
                LODWORD(v47) = 1;
                v35 = *(_DWORD *)(a2 + 160);
                v36 = *(_DWORD *)(a2 + 164);
                v37 = *(_QWORD *)(a2 + 152);
                LODWORD(v50) = 0;
                LODWORD(v51) = a3;
                v53 = v35;
                v54 = v36;
                v38 = *(_DWORD *)(a2 + 172);
                v39 = *(_DWORD *)(a2 + 176);
                v52 = v37;
                v40 = dspp_buf[10 * a3 + 2 * v33 + v34];
                v41 = *(unsigned int *)(a1 + 28);
                v57 = v38;
                v58 = v39;
                v42 = *(_DWORD *)(a2 + 28);
                v48 = v40;
                v55 = 2;
                v56 = v42;
                if ( (unsigned int)v41 <= 2 )
                {
                  v43 = *(__int64 (__fastcall **)(_QWORD))(v13 + 8 * v41 + 16);
                  if ( v43 )
                  {
                    if ( *((_DWORD *)v43 - 1) != 1772228465 )
                      __break(0x8228u);
                    result = v43(&v46);
                    if ( (_DWORD)result )
                      result = _drm_err("failed to kick off ret %d\n", (unsigned int)result);
                  }
                  goto LABEL_6;
                }
              }
            }
          }
        }
LABEL_45:
        __break(0x5512u);
LABEL_46:
        __break(1u);
      }
    }
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
