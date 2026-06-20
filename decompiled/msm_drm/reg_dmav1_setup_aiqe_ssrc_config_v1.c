void __fastcall reg_dmav1_setup_aiqe_ssrc_config_v1(__int64 a1, __int64 *a2, __int64 a3)
{
  __int64 v6; // x24
  int v7; // w25
  int v8; // w26
  char *ops; // x0
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x3
  __int64 v13; // x4
  __int64 v14; // x8
  __int64 v15; // x9
  char *v16; // x21
  unsigned __int64 v17; // x23
  void (__fastcall *v18)(_QWORD); // x8
  __int64 (__fastcall *v19)(_QWORD); // x9
  int v20; // w0
  __int64 v21; // x23
  int *v22; // x23
  char v23; // t1
  int v24; // w24
  __int64 v25; // x23
  __int64 v26; // x8
  int v27; // w25
  __int64 (__fastcall *v28)(_QWORD); // x8
  __int64 (__fastcall *v29)(_QWORD); // x9
  __int64 v30; // x8
  __int64 v31; // x8
  int v32; // w9
  _DWORD *v33; // x8
  __int64 v34; // x1
  int v35; // w0
  int v36; // w4
  int v37; // w5
  size_t v38; // x0
  int v39; // w6
  char *v40; // x1
  int v41; // w2
  int v42; // w7
  __int64 v43; // x8
  __int64 v44; // x9
  __int64 (__fastcall *v45)(__int64 *, __int64); // x8
  __int64 v46; // x1
  __int64 v47; // [xsp+10h] [xbp-F0h] BYREF
  __int64 v48; // [xsp+18h] [xbp-E8h]
  unsigned __int64 v49; // [xsp+20h] [xbp-E0h]
  __int64 v50; // [xsp+28h] [xbp-D8h]
  __int64 v51; // [xsp+30h] [xbp-D0h]
  __int64 v52; // [xsp+38h] [xbp-C8h]
  __int64 v53; // [xsp+40h] [xbp-C0h]
  __int64 v54; // [xsp+48h] [xbp-B8h]
  unsigned __int64 v55; // [xsp+50h] [xbp-B0h]
  __int64 v56; // [xsp+58h] [xbp-A8h]
  unsigned __int64 v57; // [xsp+60h] [xbp-A0h] BYREF
  __int128 v58; // [xsp+68h] [xbp-98h]
  unsigned __int64 v59; // [xsp+78h] [xbp-88h]
  int *v60; // [xsp+80h] [xbp-80h]
  __int64 v61; // [xsp+88h] [xbp-78h]
  __int64 v62; // [xsp+90h] [xbp-70h]
  __int64 v63; // [xsp+98h] [xbp-68h]
  _QWORD v64[8]; // [xsp+A0h] [xbp-60h] BYREF
  int v65; // [xsp+E0h] [xbp-20h]
  int v66; // [xsp+E4h] [xbp-1Ch]
  int v67; // [xsp+E8h] [xbp-18h]
  int v68; // [xsp+ECh] [xbp-14h]
  int v69; // [xsp+F4h] [xbp-Ch] BYREF
  __int64 v70; // [xsp+F8h] [xbp-8h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(unsigned int *)(a1 + 28);
  v62 = 0;
  v63 = 0;
  v60 = nullptr;
  v61 = 0;
  v59 = 0;
  v57 = 0;
  v58 = 0u;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  if ( (unsigned int)reg_dma_dspp_check((unsigned int *)a1, a2, 0x17u) )
    goto LABEL_2;
  v7 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 604LL);
  if ( !v7 )
  {
    _drm_dev_dbg(0, 0, 1, "AIQE not present on DSPP idx %d", *(_DWORD *)(a1 + 64));
    goto LABEL_2;
  }
  v8 = *(_DWORD *)(a1 + 8);
  ops = sde_reg_dma_get_ops(*(_DWORD *)(a1 + 1496));
  v14 = *(unsigned int *)(a1 + 64);
  if ( (unsigned int)v14 < 5 )
  {
    v15 = *(unsigned int *)(a1 + 1496);
    if ( (unsigned int)v15 <= 1 )
    {
      v16 = ops;
      v17 = dspp_buf[2 * v14 + 230 + v15];
      v18 = *((void (__fastcall **)(_QWORD))ops + 8);
      if ( *((_DWORD *)v18 - 1) != -870478129 )
        __break(0x8228u);
      v18(v17);
      v62 = 0;
      v63 = 0;
      v58 = 0x17u;
      v59 = v17;
      v60 = nullptr;
      v61 = 0;
      v19 = *((__int64 (__fastcall **)(_QWORD))v16 + 1);
      v57 = 0x8000000000000000LL;
      if ( *((_DWORD *)v19 - 1) != -1839634494 )
        __break(0x8229u);
      v20 = v19(&v57);
      if ( v20 )
      {
        _drm_err("write decode select failed ret %d\n", v20);
LABEL_2:
        _ReadStatusReg(SP_EL0);
        return;
      }
      v21 = *a2;
      if ( *a2 && (v23 = *(_BYTE *)(v21 + 4), v22 = (int *)(v21 + 4), (v23 & 1) != 0) )
      {
        if ( (unsigned int)reg_dmav1_aiqe_write_top_level_v1(&v57, a1, a2, v16, a3) )
          goto LABEL_2;
        *(_QWORD *)((char *)&v58 + 4) = 0;
        HIDWORD(v58) = v7 + v8 + 896;
        v60 = v22;
        v61 = 0x4000000000LL;
        v29 = *((__int64 (__fastcall **)(_QWORD))v16 + 1);
        LODWORD(v57) = 2;
        if ( *((_DWORD *)v29 - 1) != -1839634494 )
          __break(0x8229u);
        ops = (char *)v29(&v57);
        if ( (_DWORD)ops )
        {
          _drm_err("write config failed ret %d\n", (_DWORD)ops);
          goto LABEL_2;
        }
        v43 = a2[2];
        v44 = a2[19];
        v51 = 0;
        v47 = v43;
        v53 = v44;
        v49 = v59;
        v50 = 0;
        v48 = 1;
        v52 = 23;
        LODWORD(v44) = *((_DWORD *)a2 + 41);
        LODWORD(v54) = *((_DWORD *)a2 + 40);
        HIDWORD(v54) = v44;
        LODWORD(v44) = *((_DWORD *)a2 + 42);
        LODWORD(v43) = *((_DWORD *)a2 + 44);
        LODWORD(v56) = *((_DWORD *)a2 + 43);
        HIDWORD(v56) = v43;
        v55 = __PAIR64__(*((_DWORD *)a2 + 7), v44);
        if ( (unsigned int)v6 <= 2 )
        {
          v45 = *(__int64 (__fastcall **)(__int64 *, __int64))&v16[8 * v6 + 16];
          if ( !v45 )
            goto LABEL_2;
          v46 = *(unsigned int *)(a1 + 1496);
          if ( *((_DWORD *)v45 - 1) != 1772228465 )
            __break(0x8228u);
          v35 = v45(&v47, v46);
          if ( !v35 )
          {
            v36 = *(_DWORD *)(a1 + 64);
            v37 = *(_DWORD *)(a1 + 1496);
            v38 = sde_dbg_base_evtlog;
            v39 = *(_DWORD *)(a1 + 28);
            v40 = "reg_dmav1_setup_aiqe_ssrc_config_v1";
            v41 = 571;
            v42 = 1;
            goto LABEL_38;
          }
LABEL_36:
          _drm_err("failed to kick off ret %d\n", v35);
          goto LABEL_2;
        }
      }
      else
      {
        v24 = *(_DWORD *)(a1 + 8);
        v25 = *(unsigned int *)(a1 + 28);
        v26 = *(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL);
        v69 = 0;
        v27 = *(_DWORD *)(v26 + 604);
        if ( (unsigned int)reg_dmav1_aiqe_write_top_level_v1(&v57, a1, a2, v16, a3) )
          goto LABEL_2;
        *(_QWORD *)((char *)&v58 + 4) = 0;
        HIDWORD(v58) = v24 + v27 + 896;
        v60 = &v69;
        v61 = 0x400000000LL;
        v28 = *((__int64 (__fastcall **)(_QWORD))v16 + 1);
        LODWORD(v57) = 1;
        if ( *((_DWORD *)v28 - 1) != -1839634494 )
          __break(0x8228u);
        ops = (char *)v28(&v57);
        if ( (_DWORD)ops )
        {
          _drm_err("write SSRC off failed ret %d\n", (_DWORD)ops);
          goto LABEL_2;
        }
        v30 = a2[2];
        v64[4] = 0;
        v64[5] = 23;
        v64[0] = v30;
        v64[1] = 1;
        v64[2] = v59;
        v64[3] = 0;
        v31 = a2[20];
        v64[6] = a2[19];
        v64[7] = v31;
        v32 = *((_DWORD *)a2 + 42);
        LODWORD(v31) = *((_DWORD *)a2 + 44);
        v67 = *((_DWORD *)a2 + 43);
        v68 = v31;
        LODWORD(v31) = *((_DWORD *)a2 + 7);
        v65 = v32;
        v66 = v31;
        if ( (unsigned int)v25 < 3 )
        {
          v33 = *(_DWORD **)&v16[8 * v25 + 16];
          if ( !v33 )
            goto LABEL_2;
          v34 = *(unsigned int *)(a1 + 1496);
          if ( *(v33 - 1) != 1772228465 )
            __break(0x8228u);
          v35 = ((__int64 (__fastcall *)(_QWORD *, __int64))v33)(v64, v34);
          if ( !v35 )
          {
            v36 = *(_DWORD *)(a1 + 64);
            v37 = *(_DWORD *)(a1 + 1496);
            v38 = sde_dbg_base_evtlog;
            v39 = *(_DWORD *)(a1 + 28);
            v40 = "_aiqe_ssrc_config_off_v1";
            v41 = 505;
            v42 = 0;
LABEL_38:
            sde_evtlog_log(v38, v40, v41, -1, v36, v37, v39, v42, 239);
            goto LABEL_2;
          }
          goto LABEL_36;
        }
      }
    }
  }
  __break(0x5512u);
  reg_dmav1_aiqe_write_top_level_v1(ops, v10, v11, v12, v13);
}
