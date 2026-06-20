__int64 __fastcall reg_dmav1_setup_spr_udc_cfgv2(__int64 a1, __int64 *a2)
{
  _DWORD *v4; // x19
  __int64 v5; // x24
  int v6; // w1
  const void *v7; // x1
  __int64 v8; // x2
  unsigned int v9; // w4
  unsigned __int64 ops; // x0
  unsigned __int64 v11; // x22
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x9
  __int64 v15; // x25
  int v16; // w26
  unsigned __int64 v17; // x23
  void (__fastcall *v18)(_QWORD); // x8
  int v19; // w27
  __int64 (__fastcall *v20)(_QWORD); // x9
  int v21; // w0
  __int64 result; // x0
  int v23; // w23
  __int16 v24; // w8
  __int16 v25; // w10
  __int16 v26; // w11
  __int16 v27; // w9
  __int64 (__fastcall *v28)(_QWORD); // x9
  int v29; // w0
  __int64 (__fastcall *v30)(_QWORD); // x9
  int v31; // w0
  __int64 (__fastcall *v32)(_QWORD); // x9
  int v33; // w1
  __int64 v34; // x8
  __int64 v35; // x9
  unsigned int v36; // w11
  __int64 v37; // x8
  __int64 (__fastcall *v38)(__int64 *, __int64); // x8
  __int64 v39; // x1
  int v40; // w0
  int v41; // w2
  int v42; // w7
  int v43; // w26
  __int64 v44; // x8
  unsigned __int16 *v45; // x9
  int v46; // w10
  int v47; // w11
  int v48; // w12
  unsigned int v49; // w2
  unsigned int v50; // w2
  unsigned __int64 v51; // x15
  unsigned __int16 *v52; // x5
  unsigned __int64 v53; // x17
  __int64 v54; // x17
  int v55; // w6
  int v56; // t1
  __int64 (__fastcall *v57)(_QWORD); // x9
  int v58; // w0
  unsigned __int64 StatusReg; // x22
  __int64 v60; // x23
  unsigned __int64 v61; // [xsp+8h] [xbp-A8h] BYREF
  __int128 v62; // [xsp+10h] [xbp-A0h]
  unsigned __int64 v63; // [xsp+20h] [xbp-90h]
  _DWORD *v64; // [xsp+28h] [xbp-88h]
  __int64 v65; // [xsp+30h] [xbp-80h]
  __int64 v66; // [xsp+38h] [xbp-78h]
  __int64 v67; // [xsp+40h] [xbp-70h]
  __int64 v68; // [xsp+48h] [xbp-68h] BYREF
  __int64 v69; // [xsp+50h] [xbp-60h]
  unsigned __int64 v70; // [xsp+58h] [xbp-58h]
  __int64 v71; // [xsp+60h] [xbp-50h]
  __int128 v72; // [xsp+68h] [xbp-48h]
  __int64 v73; // [xsp+78h] [xbp-38h]
  __int64 v74; // [xsp+80h] [xbp-30h]
  unsigned __int64 v75; // [xsp+88h] [xbp-28h]
  __int64 v76; // [xsp+90h] [xbp-20h]
  _DWORD v77[3]; // [xsp+9Ch] [xbp-14h]
  __int64 v78; // [xsp+A8h] [xbp-8h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v75 = 0;
  v76 = 0;
  v73 = 0;
  v74 = 0;
  v72 = 0u;
  v70 = 0;
  v71 = 0;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  v64 = nullptr;
  v65 = 0;
  v63 = 0;
  v61 = 0;
  v62 = 0u;
  v4 = (_DWORD *)_kvmalloc_node_noprof(1536, 0, 3520, 0xFFFFFFFFLL);
  if ( !v4 )
  {
LABEL_72:
    result = _drm_err("Unable to allocate memory for UDC mask programming\n");
    goto LABEL_73;
  }
  while ( 1 )
  {
    v5 = *a2;
    if ( *a2 )
    {
      v6 = *((_DWORD *)a2 + 2);
      if ( v6 != 3144 )
      {
        _drm_err("invalid payload size len %d exp %zd\n", v6, 0xC48u);
        goto LABEL_26;
      }
    }
    if ( !a1 || !a2 )
    {
      _drm_err("invalid cfg %pK ctx %pK\n", a2, (const void *)a1);
      goto LABEL_26;
    }
    v7 = (const void *)a2[2];
    v8 = *(unsigned int *)(a1 + 64);
    v9 = *(_DWORD *)(a1 + 1496);
    if ( !v7 || (unsigned int)v8 > 4 || v9 >= 2 )
    {
      _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", v7, v8, 13, v9);
      goto LABEL_26;
    }
    if ( &dspp_buf[2 * v8] == (unsigned __int64 *)-1040LL )
    {
      _drm_err("invalid dma_buf\n");
      goto LABEL_26;
    }
    ops = sde_reg_dma_get_ops(v9);
    if ( !ops )
      goto LABEL_26;
    v11 = ops;
    if ( ops > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_26;
    v12 = *((unsigned int *)a2 + 44);
    *((_DWORD *)a2 + 40) = a2[20] & 0xFF0F0FFF | 0x2000;
    if ( (unsigned int)v12 >= 5 )
      goto LABEL_70;
    *((_DWORD *)a2 + 42) = hfi_dspp_idx_map[v12] | (v5 != 0);
    v13 = *(unsigned int *)(a1 + 64);
    if ( (unsigned int)v13 > 4 )
      goto LABEL_70;
    v14 = *(unsigned int *)(a1 + 1496);
    if ( (unsigned int)v14 > 1 )
      goto LABEL_70;
    if ( (unsigned __int64)(16 * v13 + 8 * v14 + 1040) <= 0x7D0 )
      break;
LABEL_71:
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v60 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &reg_dmav1_setup_spr_udc_cfgv2__alloc_tag;
    v4 = (_DWORD *)_kvmalloc_node_noprof(1536, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v60;
    if ( !v4 )
      goto LABEL_72;
  }
  v15 = *a2;
  v16 = *(_DWORD *)(a1 + 8);
  v17 = dspp_buf[2 * v13 + 130 + v14];
  v18 = *(void (__fastcall **)(_QWORD))(ops + 64);
  v19 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 416LL);
  if ( *((_DWORD *)v18 - 1) != -870478129 )
    __break(0x8228u);
  v18(v17);
  v66 = 0;
  v67 = 0;
  v62 = 0xDu;
  v63 = v17;
  v64 = nullptr;
  v65 = 0;
  v20 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8);
  v61 = 0x8000000000000000LL;
  if ( *((_DWORD *)v20 - 1) != -1839634494 )
    __break(0x8229u);
  v21 = v20(&v61);
  if ( v21 )
  {
    _drm_err("spr write decode select failed ret %d\n", v21);
    goto LABEL_26;
  }
  v23 = v19 + v16;
  if ( v5 )
  {
    *v4 = *(_DWORD *)(v15 + 18);
    v24 = *(_WORD *)(v15 + 24);
    v4[1] = *(_WORD *)(v15 + 22) & 0x3FF | ((v24 & 0x1FF) << 16);
    v4[2] = *(_WORD *)(v15 + 26) & 0xF
          | ((*(_WORD *)(v15 + 28) & 0xF) << 8)
          | ((*(_WORD *)(v15 + 30) & 0xF) << 16) & 0xF0FFFFFF
          | ((*(_WORD *)(v15 + 32) & 0xF) << 24);
    v4[3] = *(_WORD *)(v15 + 34) & 0x7FF;
    v4[4] = *(_DWORD *)(v15 + 36);
    v25 = *(_WORD *)(v15 + 42);
    v4[5] = *(_WORD *)(v15 + 40) & 0x3FF | ((v25 & 0x1FF) << 16);
    v4[6] = *(_WORD *)(v15 + 44) & 0xF
          | ((*(_WORD *)(v15 + 46) & 0xF) << 8)
          | ((*(_WORD *)(v15 + 48) & 0xF) << 16) & 0xF0FFFFFF
          | ((*(_WORD *)(v15 + 50) & 0xF) << 24);
    v4[7] = *(_WORD *)(v15 + 52) & 0x7FF;
    v4[8] = *(_DWORD *)(v15 + 54);
    v26 = *(_WORD *)(v15 + 60);
    v4[9] = *(_WORD *)(v15 + 58) & 0x3FF | ((v26 & 0x1FF) << 16);
    v4[10] = *(_WORD *)(v15 + 62) & 0xF
           | ((*(_WORD *)(v15 + 64) & 0xF) << 8)
           | ((*(_WORD *)(v15 + 66) & 0xF) << 16) & 0xF0FFFFFF
           | ((*(_WORD *)(v15 + 68) & 0xF) << 24);
    v77[0] = v24 & 0x1FF;
    v77[1] = v25 & 0x1FF;
    v27 = *(_WORD *)(v15 + 70);
    HIDWORD(v62) = v23 + 288;
    *(_QWORD *)((char *)&v62 + 4) = 0;
    v4[11] = v27 & 0x7FF;
    v64 = v4;
    v65 = 0x3000000000LL;
    v77[2] = v26 & 0x1FF;
    v28 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8);
    LODWORD(v61) = 2;
    if ( *((_DWORD *)v28 - 1) != -1839634494 )
      __break(0x8229u);
    v29 = v28(&v61);
    if ( v29 )
    {
      _drm_err("write spr udc cfg p1 failed ret %d\n", v29);
      goto LABEL_26;
    }
    *v4 = 0;
    HIDWORD(v62) = v23 + 336;
    *(_QWORD *)((char *)&v62 + 4) = 0;
    v64 = v4;
    v65 = 0x400000000LL;
    v32 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8);
    LODWORD(v61) = 1;
    if ( *((_DWORD *)v32 - 1) != -1839634494 )
      __break(0x8229u);
    v33 = v32(&v61);
    if ( v33 )
    {
      _drm_err("write spr udc cfg p2 failed - ret %d\n", v33);
      goto LABEL_26;
    }
    v43 = 1536;
    memset(v4, 0, 0x600u);
    v44 = 0;
    v45 = (unsigned __int16 *)(v15 + 78);
    v46 = 1539;
    v47 = 1538;
    v48 = 1537;
    do
    {
      v49 = v77[v44] + 1;
      if ( v49 >= 2 )
      {
        v50 = v49 >> 1;
        v51 = 0;
        v52 = v45;
        if ( v44 )
          v53 = (unsigned __int64)(v44 != 1) << 7;
        else
          v53 = 256;
        v54 = v53;
        while ( (v46 & 0xFFFFFFFC) != (_DWORD)v51
             && (v47 & 0xFFFFFFFC) != (_DWORD)v51
             && (v48 & 0xFFFFFFFC) != (_DWORD)v51
             && (v43 & 0xFFFFFFFC) != (_DWORD)v51 )
        {
          if ( v54 * 4 + v51 > 0x5FF )
            goto LABEL_71;
          --v50;
          v55 = *((unsigned __int8 *)v52 - 6)
              | ((unsigned __int8)*(v52 - 2) << 8)
              | (*((unsigned __int8 *)v52 - 2) << 16);
          v56 = *v52;
          v52 += 4;
          v4[v54 + v51 / 4] = v55 | (v56 << 24);
          v51 += 4LL;
          if ( !v50 )
            goto LABEL_50;
        }
        goto LABEL_70;
      }
LABEL_50:
      ++v44;
      v46 -= 512;
      v47 -= 512;
      v45 += 512;
      v43 -= 512;
      v48 -= 512;
    }
    while ( v44 != 3 );
    *(_QWORD *)((char *)&v62 + 4) = 0;
    HIDWORD(v62) = v23 + 340;
    v64 = v4;
    v65 = 0x60000000000LL;
    v57 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8);
    LODWORD(v61) = 3;
    if ( *((_DWORD *)v57 - 1) != -1839634494 )
      __break(0x8229u);
    v58 = v57(&v61);
    if ( v58 )
    {
      _drm_err("write spr udc cfg p3 failed - L%d\t ret %d\n", 3, v58);
      goto LABEL_26;
    }
    *v4 = 0x2000000;
  }
  else
  {
    *v4 = 0;
  }
  *(_QWORD *)((char *)&v62 + 4) = 0;
  HIDWORD(v62) = v23 + 4;
  v64 = v4;
  v65 = 0x4FDFFFFFFLL;
  v30 = *(__int64 (__fastcall **)(_QWORD))(v11 + 8);
  LODWORD(v61) = 5;
  if ( *((_DWORD *)v30 - 1) != -1839634494 )
    __break(0x8229u);
  v31 = v30(&v61);
  if ( v31 )
  {
    _drm_err("write spr udc config failed ret %d\n", v31);
    goto LABEL_26;
  }
  v34 = a2[2];
  v35 = a2[19];
  v72 = 0u;
  v36 = *((_DWORD *)a2 + 42);
  v68 = v34;
  v73 = v35;
  v70 = v63;
  v71 = 0;
  v69 = 1;
  DWORD2(v72) = 13;
  LODWORD(v35) = *((_DWORD *)a2 + 41);
  LODWORD(v74) = *((_DWORD *)a2 + 40);
  HIDWORD(v74) = v35;
  v37 = *(unsigned int *)(a1 + 28);
  LODWORD(v35) = *((_DWORD *)a2 + 44);
  LODWORD(v76) = *((_DWORD *)a2 + 43);
  HIDWORD(v76) = v35;
  v75 = __PAIR64__(*((_DWORD *)a2 + 7), v36);
  if ( (unsigned int)v37 > 2 )
  {
LABEL_70:
    __break(0x5512u);
    goto LABEL_71;
  }
  v38 = *(__int64 (__fastcall **)(__int64 *, __int64))(v11 + 8 * v37 + 16);
  if ( !v38 )
    goto LABEL_47;
  v39 = *(unsigned int *)(a1 + 1496);
  if ( *((_DWORD *)v38 - 1) != 1772228465 )
    __break(0x8228u);
  v40 = v38(&v68, v39);
  if ( v40 )
  {
    _drm_err("failed to kick off ret %d\n", v40);
  }
  else
  {
LABEL_47:
    if ( v5 )
    {
      v41 = 7233;
      v42 = 1;
    }
    else
    {
      v41 = 7231;
      v42 = 0;
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "reg_dmav1_setup_spr_udc_cfgv2",
      v41,
      -1,
      *(_DWORD *)(a1 + 64),
      *(_DWORD *)(a1 + 1496),
      *(_DWORD *)(a1 + 28),
      v42,
      239);
  }
LABEL_26:
  result = kvfree(v4);
LABEL_73:
  _ReadStatusReg(SP_EL0);
  return result;
}
