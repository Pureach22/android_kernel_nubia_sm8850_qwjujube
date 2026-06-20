__int64 __fastcall dp_tu_mst_rg_calc(__int64 *a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x25
  __int64 v4; // x21
  __int64 v5; // x23
  __int64 v7; // x20
  __int64 v9; // x24
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x26
  __int64 v12; // x11
  __int64 v13; // x9
  __int64 v14; // x10
  unsigned __int64 v15; // x13
  unsigned __int64 v16; // x12
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x14
  int v19; // w13
  unsigned __int64 v20; // x14
  unsigned __int64 v21; // x16
  bool v22; // cf
  _BOOL8 v23; // x12
  __int64 v24; // x13
  __int64 v25; // x9
  int v26; // w10
  __int64 v27; // x13
  unsigned __int64 v28; // x16
  unsigned __int64 v29; // x15
  unsigned __int64 v30; // x14
  unsigned __int64 v31; // x16
  unsigned __int64 v32; // x16
  unsigned __int64 v33; // x0
  __int64 v34; // x10
  unsigned __int64 v35; // x8
  unsigned __int64 v36; // x11
  unsigned __int64 v37; // x20
  __int64 v38; // x9
  unsigned __int64 v39; // x21
  unsigned __int64 v40; // x8
  char v41; // w11
  bool v42; // cc
  __int64 v43; // x8
  __int64 v44; // x8
  char v45; // w9
  __int64 v46; // x8
  __int64 v47; // x9
  __int64 v48; // x10
  __int64 v49; // x11
  unsigned int v50; // w11
  unsigned int v51; // w10
  __int64 v52; // x9
  __int64 v53; // x10
  __int64 v54; // x11
  unsigned int v55; // w11
  unsigned int v56; // w10
  unsigned __int64 v57; // x9
  __int64 v58; // x10
  __int64 v59; // x11
  unsigned int v60; // w11
  unsigned int v61; // w10
  __int64 v62; // x8
  unsigned __int64 v63; // x10
  __int64 v64; // x11
  __int64 v65; // x8
  bool v66; // nf
  __int64 v67; // x8
  unsigned __int64 v68; // x10
  __int64 v69; // x8
  char v70; // w13
  signed __int64 v71; // x10
  __int64 v72; // x10
  char v73; // w9
  __int64 v74; // x22
  unsigned __int64 v75; // x9
  unsigned __int64 v76; // x10
  __int64 v77; // x11
  unsigned __int64 v78; // x9
  __int64 v79; // x23
  __int64 v80; // x10
  unsigned int v81; // w11
  unsigned int v82; // w10
  __int64 v83; // x8
  unsigned __int64 v84; // x24
  __int64 v85; // x10
  __int64 v86; // x9
  char v87; // w11
  __int64 v88; // x9
  __int64 v89; // x8
  unsigned int v90; // w9
  unsigned int v91; // w10
  unsigned __int64 v92; // x25
  __int64 v93; // x0

  v2 = 17;
  v3 = *((unsigned __int8 *)a1 + 16);
  v4 = *a1;
  v5 = a1[1];
  v7 = a1[5];
  if ( *((_BYTE *)a1 + 20) )
    v2 = 18;
  v9 = *((unsigned __int8 *)a1 + v2);
  ipc_log_context = get_ipc_log_context(a1);
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    ipc_log_context,
    "[d][%-4d]rg calc input: %llu %llu %llu %llu\n",
    *(_DWORD *)(StatusReg + 1800),
    v4,
    v5,
    v9,
    v7);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]rg calc input: %llu %llu %llu %llu\n",
      *(_DWORD *)(StatusReg + 1800),
      v4,
      v5,
      v9,
      v7);
  v12 = v4 * v3;
  v13 = 64000 * v5 * v9;
  v14 = 8000 * v4 * v3;
  if ( v13 >= 0 )
    v15 = 64000 * v5 * v9;
  else
    v15 = -64000 * v5 * v9;
  if ( v14 >= 0 )
    v16 = 8000 * v4 * v3;
  else
    v16 = -8000 * v4 * v3;
  v17 = v15 / v16;
  v18 = v15 % v16;
  v19 = -32;
  do
  {
    v20 = 2 * v18;
    if ( v20 < v16 )
      v21 = 0;
    else
      v21 = v16;
    v22 = __CFADD__(v19++, 1);
    v17 = (v20 >= v16) | (2 * v17);
    v18 = v20 - v21;
  }
  while ( !v22 );
  v23 = v16 <= 2 * v18;
  v24 = 54000;
  if ( *((_BYTE *)a1 + 48) )
    v24 = 54000000;
  v25 = v13 ^ v14;
  v26 = -32;
  v27 = v24 * v7;
  if ( *((_BYTE *)a1 + 48) )
    v12 *= 1006;
  if ( v27 >= 0 )
    v28 = v27;
  else
    v28 = -v27;
  if ( v12 >= 0 )
    v29 = v12;
  else
    v29 = -v12;
  v30 = v28 / v29;
  v31 = v28 % v29;
  do
  {
    v32 = 2 * v31;
    if ( v32 < v29 )
      v33 = 0;
    else
      v33 = v29;
    v22 = __CFADD__(v26++, 1);
    v30 = (v32 >= v29) | (2 * v30);
    v31 = v32 - v33;
  }
  while ( !v22 );
  v34 = v27 ^ v12;
  v35 = v17 + v23;
  if ( v29 > 2 * v31 )
    v36 = v30;
  else
    v36 = v30 + 1;
  if ( v34 >= 0 )
    v37 = v36;
  else
    v37 = -(__int64)v36;
  v66 = v25 < 0;
  v38 = 62;
  if ( v66 )
    v39 = -(__int64)v35;
  else
    v39 = v35;
  v40 = v37 + v39;
  do
  {
    if ( ((v40 >> v38) & 1) != (v37 + v39) >> 63 )
      break;
    --v38;
  }
  while ( v38 );
  v41 = v38 - 30;
  v42 = (unsigned int)(62 - v38) > 0x20;
  v43 = v40 << (62 - (unsigned __int8)v38);
  if ( (unsigned int)(62 - v38) >= 0x20 )
    v41 = 0;
  v44 = v43 / (__int64)(0x200000000uLL >> v41);
  v45 = 30 - v38;
  if ( !v42 )
    v45 = 0;
  v46 = v44 >> v45;
  if ( *((_BYTE *)a1 + 19) != 1 )
    goto LABEL_61;
  v47 = a1[3];
  v48 = 62;
  do
  {
    if ( (((unsigned __int64)v46 >> v48) & 1) != (unsigned __int64)v46 >> 63 )
      break;
    --v48;
  }
  while ( v48 );
  v49 = 62;
  do
  {
    if ( (((unsigned __int64)v47 >> v49) & 1) != (unsigned __int64)v47 >> 63 )
      break;
    --v49;
  }
  while ( v49 );
  v50 = v49 + v48;
  v51 = v50 - 61;
  if ( v50 <= 0x3D )
  {
    v46 *= v47;
    LOBYTE(v51) = 0;
LABEL_60:
    v46 >>= 32 - (unsigned __int8)v51;
    goto LABEL_61;
  }
  v46 = (v46 >> ((v51 >> 1) + (v51 & 1))) * (v47 >> (v51 >> 1));
  if ( v51 >= 0x21 )
  {
    v46 <<= (unsigned __int8)v50 - 93;
    goto LABEL_61;
  }
  if ( v50 != 93 )
    goto LABEL_60;
LABEL_61:
  if ( *((_BYTE *)a1 + 20) == 1 )
  {
    v52 = a1[4];
    v53 = 62;
    do
    {
      if ( (((unsigned __int64)v46 >> v53) & 1) != (unsigned __int64)v46 >> 63 )
        break;
      --v53;
    }
    while ( v53 );
    v54 = 62;
    do
    {
      if ( (((unsigned __int64)v52 >> v54) & 1) != (unsigned __int64)v52 >> 63 )
        break;
      --v54;
    }
    while ( v54 );
    v55 = v54 + v53;
    v56 = v55 - 61;
    if ( v55 <= 0x3D )
    {
      v46 *= v52;
      LOBYTE(v56) = 0;
    }
    else
    {
      v46 = (v46 >> ((v56 >> 1) + (v56 & 1))) * (v52 >> (v56 >> 1));
      if ( v56 >= 0x21 )
      {
        v46 <<= (unsigned __int8)v55 - 93;
        goto LABEL_73;
      }
      if ( v55 == 93 )
        goto LABEL_73;
    }
    v46 >>= 32 - (unsigned __int8)v56;
  }
LABEL_73:
  v57 = v3 << 40;
  v58 = 62;
  do
  {
    if ( (((unsigned __int64)v46 >> v58) & 1) != (unsigned __int64)v46 >> 63 )
      break;
    --v58;
  }
  while ( v58 );
  v59 = 62;
  do
  {
    if ( ((v57 >> v59) & 1) != 0 )
      break;
    --v59;
  }
  while ( v59 );
  v60 = v59 + v58;
  v61 = v60 - 61;
  if ( v60 <= 0x3D )
  {
    v62 = v57 * v46;
    LOBYTE(v61) = 0;
LABEL_83:
    v62 >>= 32 - (unsigned __int8)v61;
    goto LABEL_84;
  }
  v62 = (v46 >> ((v61 >> 1) + (v61 & 1))) * (v57 >> (v61 >> 1));
  if ( v61 >= 0x21 )
  {
    v62 <<= (unsigned __int8)v60 - 93;
    goto LABEL_84;
  }
  if ( v60 != 93 )
    goto LABEL_83;
LABEL_84:
  v63 = 0xFFFFFFFF80000000LL;
  v64 = 62;
  if ( v62 >= 0 )
    v63 = 0x80000000LL;
  v65 = (__int64)(v63 + v62) >> 32;
  v66 = v65 < 0;
  if ( v65 < 0 )
    v65 = -v65;
  v67 = v65 << 32;
  if ( v66 )
    v68 = -v67;
  else
    v68 = v67;
  do
  {
    if ( ((v68 >> v64) & 1) != v68 >> 63 )
      break;
    --v64;
  }
  while ( v64 );
  v69 = 62;
  v70 = v64 - 30;
  v71 = v68 << (62 - (unsigned __int8)v64);
  if ( (unsigned int)(62 - v64) >= 0x20 )
    v70 = 0;
  v72 = v71 / (__int64)(v57 >> v70);
  v73 = 30 - v64;
  if ( (unsigned int)(62 - v64) <= 0x20 )
    v73 = 0;
  v74 = v72 >> v73;
  v75 = 0xFFFFFFFF00000001LL;
  v76 = (unsigned __int64)v72 >> 63;
  if ( v74 >= 0 )
    v75 = 0xFFFFFFFFLL;
  v77 = v75 + v74;
  v78 = v3 << 32;
  v79 = v77 >> 32;
  do
  {
    if ( (((unsigned __int64)v74 >> v69) & 1) != v76 )
      break;
    --v69;
  }
  while ( v69 );
  v80 = 62;
  do
  {
    if ( ((v78 >> v80) & 1) != 0 )
      break;
    --v80;
  }
  while ( v80 );
  v81 = v80 + v69;
  v82 = v80 + v69 - 61;
  if ( v81 <= 0x3D )
  {
    v83 = v78 * v74;
    LOBYTE(v82) = 0;
LABEL_109:
    v83 >>= 32 - (unsigned __int8)v82;
    goto LABEL_110;
  }
  v83 = (v74 >> ((v82 >> 1) + (v82 & 1))) * (v78 >> (v82 >> 1));
  if ( v82 >= 0x21 )
  {
    v83 <<= (unsigned __int8)v81 - 93;
    goto LABEL_110;
  }
  if ( v82 != 32 )
    goto LABEL_109;
LABEL_110:
  v84 = HIDWORD(v83);
  v85 = (v83 & 0xFFFFFFFF00000000LL) - v83;
  if ( (__int64)(v83 & 0xFFFFFFFF00000000LL) <= v83 )
  {
    v83 = (unsigned int)v83;
    goto LABEL_121;
  }
  v86 = 0;
  while ( (((unsigned __int64)v85 >> ((unsigned __int8)v86 + 62)) & 1) == (unsigned __int64)v85 >> 63 )
  {
    if ( --v86 == -62 )
      goto LABEL_119;
  }
  if ( (unsigned int)(v86 + 31) >= 0xFFFFFFC2 )
  {
LABEL_119:
    v83 = 0xFFFFFFFF00000000LL * v85;
    v87 = 0;
LABEL_120:
    v83 >>= 32 - v87;
    goto LABEL_121;
  }
  v87 = v86 + 32;
  v83 = (v85 >> (((unsigned int)(v86 + 32) >> 1) + ((v86 + 62) & 1)))
      * ((__int64)0xFFFFFFFF00000000LL >> ((unsigned int)(v86 + 32) >> 1));
  if ( (unsigned int)(v86 + 32) >= 0x21 )
  {
    v83 <<= v86;
    goto LABEL_121;
  }
  if ( (_DWORD)v86 )
    goto LABEL_120;
LABEL_121:
  v88 = 62;
  while ( (((unsigned __int64)v83 >> v88) & 1) == (unsigned __int64)v83 >> 63 )
  {
    if ( !--v88 )
      goto LABEL_124;
  }
  v91 = v88 + 40;
  v90 = v88 - 21;
  if ( v90 == 0 || v91 < 0x3D )
  {
LABEL_124:
    v89 = v83 << 40;
    LOBYTE(v90) = 0;
LABEL_125:
    v89 >>= 32 - (unsigned __int8)v90;
    goto LABEL_135;
  }
  v89 = (v83 >> ((v90 >> 1) + (v90 & 1))) * (0x10000000000uLL >> (v90 >> 1));
  if ( v90 < 0x21 )
  {
    if ( v90 != 32 )
      goto LABEL_125;
  }
  else
  {
    v89 <<= (unsigned __int8)v91 - 93;
  }
LABEL_135:
  v92 = HIDWORD(v89);
  *(_QWORD *)a2 = v39;
  *(_QWORD *)(a2 + 8) = v37;
  *(_QWORD *)(a2 + 16) = v74;
  *(_QWORD *)(a2 + 24) = v79;
  *(_DWORD *)(a2 + 32) = v84;
  *(_DWORD *)(a2 + 36) = HIDWORD(v89);
  v93 = get_ipc_log_context(v33);
  ipc_log_string(
    v93,
    "[i][%-4d]RG: 0x%llx 0x%llx 0x%llx %lld %d %d\n",
    *(_DWORD *)(StatusReg + 1800),
    v39,
    v37,
    v74,
    v79,
    v84,
    v92);
  if ( (_drm_debug & 4) != 0 )
    return printk(&unk_2598C2, *(unsigned int *)(StatusReg + 1800));
  else
    return printk(&unk_267BB6, "dp_tu_mst_rg_calc");
}
