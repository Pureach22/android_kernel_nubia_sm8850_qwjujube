unsigned __int64 __fastcall reg_dmav1_setup_dspp_pcc_common(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6)
{
  __int64 *v6; // x24
  __int64 v8; // x2
  unsigned int v9; // w4
  __int64 v10; // x8
  int v11; // w8
  _QWORD *v12; // x23
  unsigned __int64 result; // x0
  unsigned __int64 v14; // x20
  __int64 v15; // x8
  __int64 v16; // x9
  unsigned __int64 *v17; // x8
  void (__fastcall *v18)(_QWORD); // x9
  unsigned __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x9
  __int64 (__fastcall *v22)(_QWORD); // x8
  int v23; // w0
  int *v24; // x21
  __int64 v25; // x9
  int v26; // w8
  int v27; // w8
  __int64 (__fastcall *v28)(_QWORD); // x9
  unsigned int v29; // w0
  unsigned int v31; // w1
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  __int64 v36; // x8
  __int64 v37; // x9
  unsigned __int64 *v38; // x8
  void (__fastcall *v39)(_QWORD); // x9
  unsigned __int64 v40; // x0
  __int64 v41; // x8
  __int64 v42; // x9
  __int64 (__fastcall *v43)(_QWORD); // x8
  __int64 v44; // x8
  __int64 (__fastcall *v45)(_QWORD); // x8
  __int64 v46; // x8
  __int64 v47; // x9
  __int64 v48; // x1
  __int64 v49; // x9
  __int64 v50; // x11
  int v51; // w10
  unsigned __int64 v52; // x11
  __int64 v53; // x8
  int v54; // w10
  __int64 (__fastcall *v55)(_QWORD); // x8
  __int64 v56; // x8
  __int64 v57; // x9
  __int64 v58; // x8
  bool v59; // zf
  __int64 (__fastcall *v60)(_QWORD); // x9
  int v61; // w10
  unsigned int v62; // w0
  int v63; // w8
  __int64 v64; // x9
  int v65; // w8
  __int64 v66; // x4
  __int64 v67; // x5
  __int64 v68; // x11
  int v69; // w6
  unsigned int v70; // w10
  unsigned __int64 v71; // x9
  __int64 v72; // x8
  __int64 (__fastcall *v73)(__int64 *, __int64); // x8
  __int64 v74; // x1
  unsigned int v75; // w0
  unsigned __int64 StatusReg; // x25
  __int64 v77; // x26
  int v78; // [xsp+Ch] [xbp-144h] BYREF
  int v79; // [xsp+10h] [xbp-140h] BYREF
  int v80; // [xsp+14h] [xbp-13Ch] BYREF
  __int64 v81; // [xsp+18h] [xbp-138h] BYREF
  __int128 v82; // [xsp+20h] [xbp-130h]
  unsigned __int64 v83; // [xsp+30h] [xbp-120h]
  int *v84; // [xsp+38h] [xbp-118h]
  __int64 v85; // [xsp+40h] [xbp-110h]
  __int64 v86; // [xsp+48h] [xbp-108h]
  __int64 v87; // [xsp+50h] [xbp-100h]
  __int64 v88; // [xsp+58h] [xbp-F8h] BYREF
  __int64 v89; // [xsp+60h] [xbp-F0h]
  unsigned __int64 v90; // [xsp+68h] [xbp-E8h]
  __int64 v91; // [xsp+70h] [xbp-E0h]
  __int64 v92; // [xsp+78h] [xbp-D8h]
  __int64 v93; // [xsp+80h] [xbp-D0h]
  __int64 v94; // [xsp+88h] [xbp-C8h]
  unsigned __int64 v95; // [xsp+90h] [xbp-C0h]
  unsigned __int64 v96; // [xsp+98h] [xbp-B8h]
  __int64 v97; // [xsp+A0h] [xbp-B0h]
  int v98; // [xsp+ACh] [xbp-A4h] BYREF
  __int64 v99; // [xsp+B0h] [xbp-A0h] BYREF
  __int64 v100; // [xsp+B8h] [xbp-98h] BYREF
  __int128 v101; // [xsp+C0h] [xbp-90h]
  unsigned __int64 v102; // [xsp+D0h] [xbp-80h]
  char *v103; // [xsp+D8h] [xbp-78h]
  __int64 v104; // [xsp+E0h] [xbp-70h]
  __int64 v105; // [xsp+E8h] [xbp-68h]
  __int64 v106; // [xsp+F0h] [xbp-60h]
  __int64 v107; // [xsp+F8h] [xbp-58h] BYREF
  __int64 v108; // [xsp+100h] [xbp-50h]
  unsigned __int64 v109; // [xsp+108h] [xbp-48h]
  __int64 v110; // [xsp+110h] [xbp-40h]
  __int64 v111; // [xsp+118h] [xbp-38h]
  __int64 v112; // [xsp+120h] [xbp-30h]
  __int64 v113; // [xsp+128h] [xbp-28h]
  int v114; // [xsp+130h] [xbp-20h]
  __int64 v115; // [xsp+134h] [xbp-1Ch]
  int v116; // [xsp+13Ch] [xbp-14h]
  int v117; // [xsp+140h] [xbp-10h]
  int v118; // [xsp+144h] [xbp-Ch]
  __int64 v119; // [xsp+148h] [xbp-8h]

  v119 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v96 = 0;
  v97 = 0;
  v95 = 0;
  v93 = 0;
  v94 = 0;
  v91 = 0;
  v92 = 0;
  v89 = 0;
  v90 = 0;
  v87 = 0;
  v88 = 0;
  v85 = 0;
  v86 = 0;
  v83 = 0;
  v84 = nullptr;
  v82 = 0u;
  v81 = 0;
  v80 = 0;
  v78 = 0;
  if ( !a1 || !a2 )
  {
    result = _drm_err("invalid cfg %pK ctx %pK\n", a2, (const void *)a1);
    goto LABEL_36;
  }
  v8 = *(unsigned int *)(a1 + 64);
  v9 = *(_DWORD *)(a1 + 1496);
  if ( !a2[2] || (unsigned int)v8 > 4 || v9 >= 2 )
  {
    result = _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", (const void *)a2[2], v8, 3, v9);
    goto LABEL_36;
  }
  if ( &dspp_buf[2 * v8] == (unsigned __int64 *)-240LL )
  {
    result = _drm_err("invalid dma_buf\n");
    goto LABEL_36;
  }
  v10 = *a2;
  v79 = 0;
  *((_DWORD *)a2 + 42) = 2;
  if ( !v10 )
  {
    _drm_dev_dbg(0, 0, 1, "disable pcc feature\n");
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "reg_dmav1_setup_dspp_pcc_common",
      2016,
      -1,
      *(_DWORD *)(a1 + 64),
      *(_DWORD *)(a1 + 1496),
      *(_DWORD *)(a1 + 28),
      0,
      239);
    v31 = *(_DWORD *)(a1 + 64);
    v105 = 0;
    v106 = 0;
    v12 = a2;
    v103 = nullptr;
    v104 = 0;
    v102 = 0;
    v100 = 0;
    v101 = 0u;
    v99 = 0;
    v98 = 0;
    result = reg_dmav1_get_dspp_blk((__int64)a2, v31, &v98, &v99, v32, v33, v34, v35);
    if ( (_DWORD)result == -114 )
      goto LABEL_36;
    if ( (_DWORD)result != -22 )
    {
      result = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1496));
      if ( !result )
        goto LABEL_36;
      v14 = result;
      if ( result > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_36;
      v36 = *(unsigned int *)(a1 + 64);
      if ( (unsigned int)v36 >= 5 )
        goto LABEL_81;
      v37 = *(unsigned int *)(a1 + 1496);
      if ( (unsigned int)v37 > 1 )
        goto LABEL_81;
      if ( (unsigned __int64)(16 * v36 + 8 * v37 + 240) > 0x7D0 )
        goto LABEL_82;
      v38 = &dspp_buf[2 * v36 + v37];
      v39 = *(void (__fastcall **)(_QWORD))(result + 64);
      v40 = v38[30];
      if ( *((_DWORD *)v39 - 1) != -870478129 )
        __break(0x8229u);
      v39(v40);
      v41 = *(unsigned int *)(a1 + 64);
      LODWORD(v100) = 0;
      v101 = 3u;
      v102 = 0;
      v103 = nullptr;
      v104 = 0;
      v105 = 0;
      v106 = 0;
      HIDWORD(v100) = v98;
      if ( (unsigned int)v41 > 4 )
        goto LABEL_81;
      v42 = *(unsigned int *)(a1 + 1496);
      if ( (unsigned int)v42 > 1 )
        goto LABEL_81;
      if ( (unsigned __int64)(16 * v41 + 8 * v42 + 240) > 0x7D0 )
        goto LABEL_82;
      DWORD1(v101) = 0;
      v104 = 0;
      v102 = dspp_buf[2 * v41 + 30 + v42];
      v103 = nullptr;
      v43 = *(__int64 (__fastcall **)(_QWORD))(v14 + 8);
      if ( *((_DWORD *)v43 - 1) != -1839634494 )
        __break(0x8228u);
      v23 = v43(&v100);
      if ( !v23 )
      {
        v44 = *(_QWORD *)(a1 + 72);
        *(_QWORD *)((char *)&v101 + 4) = 0;
        HIDWORD(v101) = *(_DWORD *)(*(_QWORD *)(v44 + 48) + 56LL);
        v103 = (char *)&v99 + 4;
        v104 = 0x400000000LL;
        v45 = *(__int64 (__fastcall **)(_QWORD))(v14 + 8);
        HIDWORD(v99) = 0;
        LODWORD(v100) = 1;
        if ( *((_DWORD *)v45 - 1) != -1839634494 )
          __break(0x8228u);
        result = v45(&v100);
        if ( (_DWORD)result )
        {
          result = _drm_err("setting opcode failed ret %d\n", result);
        }
        else
        {
          v46 = *(unsigned int *)(a1 + 64);
          v47 = v12[2];
          v111 = 0;
          v112 = 0;
          v109 = 0;
          v110 = 0;
          v107 = v47;
          v108 = 0;
          if ( (unsigned int)v46 > 4 )
            goto LABEL_81;
          v48 = *(unsigned int *)(a1 + 1496);
          if ( (unsigned int)v48 > 1 )
            goto LABEL_81;
          if ( (unsigned __int64)(16 * v46 + 8 * v48 + 240) > 0x7D0 )
            goto LABEL_82;
          LODWORD(v108) = 1;
          v49 = *(_QWORD *)((char *)v12 + 164);
          v50 = v12[19];
          LODWORD(v112) = 3;
          v115 = v49;
          v51 = *((_DWORD *)v12 + 43);
          LODWORD(v49) = *((_DWORD *)v12 + 44);
          v113 = v50;
          v52 = dspp_buf[2 * v46 + 30 + v48];
          v53 = *(unsigned int *)(a1 + 28);
          v117 = v51;
          v118 = v49;
          LODWORD(v49) = *((_DWORD *)v12 + 40);
          v54 = *((_DWORD *)v12 + 7);
          v109 = v52;
          v114 = v49;
          v116 = v54;
          if ( (unsigned int)v53 > 2 )
            goto LABEL_81;
          v55 = *(__int64 (__fastcall **)(_QWORD))(v14 + 8 * v53 + 16);
          if ( v55 )
          {
            if ( *((_DWORD *)v55 - 1) != 1772228465 )
              __break(0x8228u);
            result = v55(&v107);
            if ( (_DWORD)result )
              result = _drm_err("failed to kick off ret %d\n", result);
          }
        }
        goto LABEL_36;
      }
      goto LABEL_50;
    }
LABEL_34:
    result = _drm_err("unable to determine LUTDMA DSPP blocks\n");
    goto LABEL_36;
  }
  v11 = *((_DWORD *)a2 + 2);
  if ( v11 != 144 )
  {
    result = _drm_err("invalid size of payload len %d exp %zd\n", v11, 0x90u);
    goto LABEL_36;
  }
  v12 = a2;
  result = reg_dmav1_get_dspp_blk((__int64)a2, *(_DWORD *)(a1 + 64), &v78, &v79, a3, a4, a5, a6);
  if ( (_DWORD)result != -114 )
  {
    if ( (_DWORD)result != -22 )
    {
      v6 = (__int64 *)*v12;
      result = sde_reg_dma_get_ops(*(unsigned int *)(a1 + 1496));
      if ( !result )
        goto LABEL_36;
      v14 = result;
      if ( result > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_36;
      v15 = *(unsigned int *)(a1 + 64);
      if ( (unsigned int)v15 >= 5 )
        goto LABEL_81;
      v16 = *(unsigned int *)(a1 + 1496);
      if ( (unsigned int)v16 > 1 )
        goto LABEL_81;
      if ( (unsigned __int64)(16 * v15 + 8 * v16 + 240) > 0x7D0 )
        goto LABEL_82;
      v17 = &dspp_buf[2 * v15 + v16];
      v18 = *(void (__fastcall **)(_QWORD))(result + 64);
      v19 = v17[30];
      if ( *((_DWORD *)v18 - 1) != -870478129 )
        __break(0x8229u);
      v18(v19);
      v20 = *(unsigned int *)(a1 + 64);
      LODWORD(v81) = 0;
      v83 = 0;
      v84 = nullptr;
      v85 = 0;
      v86 = 0;
      v87 = 0;
      HIDWORD(v81) = v78;
      v82 = 3u;
      if ( (unsigned int)v20 > 4 )
        goto LABEL_81;
      v21 = *(unsigned int *)(a1 + 1496);
      if ( (unsigned int)v21 > 1 )
        goto LABEL_81;
      if ( (unsigned __int64)(16 * v20 + 8 * v21 + 240) > 0x7D0 )
        goto LABEL_82;
      HIDWORD(v82) = 0;
      DWORD1(v82) = 0;
      v85 = 0;
      v83 = dspp_buf[2 * v20 + 30 + v21];
      v84 = nullptr;
      v22 = *(__int64 (__fastcall **)(_QWORD))(v14 + 8);
      if ( *((_DWORD *)v22 - 1) != -1839634494 )
        __break(0x8228u);
      v23 = v22(&v81);
      if ( !v23 )
      {
        result = _kvmalloc_node_noprof(132, 0, 3520, 0xFFFFFFFFLL);
        v24 = (int *)result;
        if ( !result )
          goto LABEL_36;
        while ( 1 )
        {
          v25 = *(_QWORD *)(a1 + 72);
          v24[24] = *((_DWORD *)v6 + 26);
          v24[27] = *((_DWORD *)v6 + 27);
          v24[30] = *((_DWORD *)v6 + 28);
          *v24 = *((_DWORD *)v6 + 2);
          v24[3] = *((_DWORD *)v6 + 3);
          v26 = *((_DWORD *)v6 + 4);
          *(_QWORD *)((char *)&v82 + 4) = 0;
          v24[6] = v26;
          v24[9] = *((_DWORD *)v6 + 5);
          v24[12] = *((_DWORD *)v6 + 6);
          v24[15] = *((_DWORD *)v6 + 8);
          v24[18] = *((_DWORD *)v6 + 7);
          v27 = *((_DWORD *)v6 + 9);
          v84 = v24;
          v24[21] = v27;
          v24[25] = *((_DWORD *)v6 + 29);
          v24[28] = *((_DWORD *)v6 + 30);
          v24[31] = *((_DWORD *)v6 + 31);
          v24[1] = *((_DWORD *)v6 + 10);
          v24[4] = *((_DWORD *)v6 + 11);
          v24[7] = *((_DWORD *)v6 + 12);
          v24[10] = *((_DWORD *)v6 + 13);
          v24[13] = *((_DWORD *)v6 + 14);
          v24[16] = *((_DWORD *)v6 + 16);
          v24[19] = *((_DWORD *)v6 + 15);
          v24[22] = *((_DWORD *)v6 + 17);
          v24[26] = *((_DWORD *)v6 + 32);
          v24[29] = *((_DWORD *)v6 + 33);
          v24[32] = *((_DWORD *)v6 + 34);
          v24[2] = *((_DWORD *)v6 + 18);
          v24[5] = *((_DWORD *)v6 + 19);
          v24[8] = *((_DWORD *)v6 + 20);
          v24[11] = *((_DWORD *)v6 + 21);
          v24[14] = *((_DWORD *)v6 + 22);
          v24[17] = *((_DWORD *)v6 + 24);
          v24[20] = *((_DWORD *)v6 + 23);
          v24[23] = *((_DWORD *)v6 + 25);
          HIDWORD(v82) = *(_DWORD *)(*(_QWORD *)(v25 + 48) + 56LL) + 4;
          v85 = 0x8400000000LL;
          v28 = *(__int64 (__fastcall **)(_QWORD))(v14 + 8);
          LODWORD(v81) = 2;
          if ( *((_DWORD *)v28 - 1) != -1839634494 )
            __break(0x8229u);
          v29 = v28(&v81);
          if ( v29 )
          {
            _drm_err("write pcc lut failed ret %d\n", v29);
            goto LABEL_71;
          }
          v56 = *(_QWORD *)(a1 + 72);
          v57 = *v6;
          *(_QWORD *)((char *)&v82 + 4) = 0;
          v58 = *(_QWORD *)(v56 + 48);
          v59 = (v57 & 1) == 0;
          v84 = &v80;
          v85 = 0x400000000LL;
          HIDWORD(v82) = *(_DWORD *)(v58 + 56);
          v60 = *(__int64 (__fastcall **)(_QWORD))(v14 + 8);
          if ( v59 )
            v61 = 1;
          else
            v61 = 65537;
          v80 = v61;
          LODWORD(v81) = 1;
          if ( *((_DWORD *)v60 - 1) != -1839634494 )
            __break(0x8229u);
          v62 = v60(&v81);
          if ( v62 )
          {
            _drm_err("setting opcode failed ret %d\n", v62);
            goto LABEL_71;
          }
          v63 = *((_DWORD *)v12 + 42);
          v64 = v12[2];
          v90 = 0;
          v91 = 0;
          v92 = 0;
          v93 = 0;
          v65 = v63 | 1;
          v88 = v64;
          v89 = 0;
          *((_DWORD *)v12 + 42) = v65;
          v66 = *(unsigned int *)(a1 + 64);
          if ( (unsigned int)v66 > 4 )
            goto LABEL_81;
          v67 = *(unsigned int *)(a1 + 1496);
          if ( (unsigned int)v67 > 1 )
            goto LABEL_81;
          if ( (unsigned __int64)(16 * v66 + 8 * v67 + 240) <= 0x7D0 )
            break;
LABEL_82:
          __break(1u);
          StatusReg = _ReadStatusReg(SP_EL0);
          v77 = *(_QWORD *)(StatusReg + 80);
          *(_QWORD *)(StatusReg + 80) = &reg_dmav1_setup_dspp_pcc_common__alloc_tag;
          result = _kvmalloc_node_noprof(132, 0, 3520, 0xFFFFFFFFLL);
          v24 = (int *)result;
          *(_QWORD *)(StatusReg + 80) = v77;
          if ( !result )
            goto LABEL_36;
        }
        v68 = v12[19];
        LODWORD(v89) = 1;
        v69 = *(_DWORD *)(a1 + 28);
        LODWORD(v93) = 3;
        v94 = v68;
        v70 = *((_DWORD *)v12 + 40);
        LODWORD(v68) = *((_DWORD *)v12 + 41);
        v71 = dspp_buf[2 * v66 + 30 + v67];
        LODWORD(v92) = 0;
        v95 = __PAIR64__(v68, v70);
        v90 = v71;
        LODWORD(v71) = *((_DWORD *)v12 + 44);
        LODWORD(v97) = *((_DWORD *)v12 + 43);
        HIDWORD(v97) = v71;
        v96 = __PAIR64__(*((_DWORD *)v12 + 7), v65);
        sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_dspp_pcc_common", 2120, -1, v66, v67, v69, 1, 239);
        v72 = *(unsigned int *)(a1 + 28);
        if ( (unsigned int)v72 <= 2 )
        {
          v73 = *(__int64 (__fastcall **)(__int64 *, __int64))(v14 + 8 * v72 + 16);
          if ( v73 )
          {
            v74 = *(unsigned int *)(a1 + 1496);
            if ( *((_DWORD *)v73 - 1) != 1772228465 )
              __break(0x8228u);
            v75 = v73(&v88, v74);
            if ( v75 )
              _drm_err("failed to kick off ret %d\n", v75);
          }
LABEL_71:
          result = kvfree(v24);
          goto LABEL_36;
        }
LABEL_81:
        __break(0x5512u);
        goto LABEL_82;
      }
LABEL_50:
      result = _drm_err("write decode select failed ret %d\n", v23);
      goto LABEL_36;
    }
    goto LABEL_34;
  }
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
