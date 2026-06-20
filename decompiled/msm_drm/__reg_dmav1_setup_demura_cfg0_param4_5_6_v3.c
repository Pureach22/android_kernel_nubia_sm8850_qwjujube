__int64 __fastcall _reg_dmav1_setup_demura_cfg0_param4_5_6_v3(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // w8
  int v7; // w9
  int v8; // w14
  int v9; // w10
  int v10; // w12
  int v11; // w9
  int v12; // w11
  int v13; // w13
  int v14; // w8
  int v15; // w14
  int v16; // w9
  int v17; // w11
  int v18; // w13
  int v20; // w9
  int v21; // w10
  int v22; // w11
  int v23; // w12
  int v24; // w13
  int v25; // w8
  int v26; // w10
  int v27; // w9
  int v28; // w12
  int v29; // w22
  int v30; // w8
  int v31; // w9
  int v32; // w8
  __int64 (__fastcall *v33)(_QWORD); // x10
  unsigned int v34; // w0
  unsigned int v35; // w21
  int v37; // w13
  int v38; // w10
  int v39; // w11
  int v40; // w9
  int v41; // w12
  int v42; // w10
  int v43; // w8
  int v44; // w12
  int v45; // w9
  int v46; // w13
  int v47; // w11
  int v48; // w12
  int v49; // w8
  int v50; // w10
  int v51; // w9
  int v52; // w11
  int v53; // w8
  int v54; // w10
  int v55; // w13
  int v56; // w11
  int v57; // w12
  int v58; // w8
  int v59; // w10
  int v60; // w8
  int v61; // w9
  int v62; // w8
  __int64 (__fastcall *v63)(_QWORD); // x10
  __int64 v64; // [xsp+8h] [xbp-38h] BYREF
  unsigned __int64 v65; // [xsp+10h] [xbp-30h]
  unsigned __int64 v66; // [xsp+18h] [xbp-28h]
  unsigned __int64 v67; // [xsp+20h] [xbp-20h]
  unsigned __int64 v68; // [xsp+28h] [xbp-18h]
  __int64 v69; // [xsp+30h] [xbp-10h]
  __int64 v70; // [xsp+38h] [xbp-8h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a2 + 12);
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  if ( !v4 )
  {
    _drm_dev_dbg(0, 0, 1, "dcfg->cfg0_en is disabled\n");
LABEL_9:
    v35 = 0;
    goto LABEL_10;
  }
  v7 = *(unsigned __int16 *)(a2 + 6368);
  v8 = *(_DWORD *)(a2 + 6372);
  v9 = *(unsigned __int16 *)(a2 + 6352) | (*(_DWORD *)(a2 + 6356) << 16);
  v10 = *(unsigned __int16 *)(a2 + 6360) | (*(_DWORD *)(a2 + 6364) << 16);
  LODWORD(v64) = *(unsigned __int16 *)(a2 + 6344) | (*(_DWORD *)(a2 + 6348) << 16);
  HIDWORD(v64) = v9;
  v11 = v7 | (v8 << 16);
  v12 = *(unsigned __int16 *)(a2 + 8392);
  v13 = *(_DWORD *)(a2 + 8396);
  v14 = *(unsigned __int16 *)(a2 + 8384) | (*(_DWORD *)(a2 + 8388) << 16);
  v15 = *(_DWORD *)(a1 + 8);
  v65 = __PAIR64__(v11, v10);
  v16 = v12 | (v13 << 16);
  v17 = *(_DWORD *)(a2 + 8404);
  v18 = *(_DWORD *)(a2 + 8412);
  v66 = __PAIR64__(v16, v14);
  v20 = *(unsigned __int16 *)(a2 + 8400) | (v17 << 16);
  v21 = *(unsigned __int16 *)(a2 + 8408) | (v18 << 16);
  v22 = *(unsigned __int16 *)(a2 + 8420) | (*(_DWORD *)(a2 + 8424) << 16);
  v23 = *(unsigned __int16 *)(a2 + 8428);
  v24 = *(_DWORD *)(a2 + 8432);
  v25 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 568LL);
  v67 = __PAIR64__(v21, v20);
  v26 = *(_DWORD *)(a2 + 8440);
  v27 = v23 | (v24 << 16);
  v28 = *(_DWORD *)(a2 + 8448);
  v29 = v15 + v25;
  v68 = __PAIR64__(v27, v22);
  v30 = *(unsigned __int16 *)(a2 + 8436);
  v31 = *(unsigned __int16 *)(a2 + 8444);
  *(_QWORD *)(a3 + 12) = 0;
  *(_DWORD *)a3 = 2;
  v32 = v30 | (v26 << 16);
  *(_DWORD *)(a3 + 20) = v29 + 240;
  *(_QWORD *)(a3 + 32) = &v64;
  *(_QWORD *)(a3 + 40) = 0x3000000000LL;
  v33 = *(__int64 (__fastcall **)(_QWORD))(a4 + 8);
  LODWORD(v69) = v32;
  HIDWORD(v69) = v31 | (v28 << 16);
  if ( *((_DWORD *)v33 - 1) != -1839634494 )
    __break(0x822Au);
  v34 = v33(a3);
  if ( v34 )
  {
    v35 = v34;
    _drm_err(
      "0xf0: REG_BLK_WRITE_SINGLE %d len %zd buf idx %d\n",
      v34,
      48,
      *(unsigned int *)(*(_QWORD *)(a3 + 24) + 20LL));
    goto LABEL_10;
  }
  if ( (*(_BYTE *)a2 & 1) == 0 )
    goto LABEL_9;
  v37 = *(_DWORD *)(a2 + 8476);
  v38 = *(unsigned __int16 *)(a2 + 8464) | (*(_DWORD *)(a2 + 8468) << 16);
  v39 = *(_DWORD *)(a2 + 8484);
  v40 = *(unsigned __int16 *)(a2 + 8480);
  v41 = *(unsigned __int16 *)(a2 + 8472);
  LODWORD(v64) = *(unsigned __int16 *)(a2 + 8456) | (*(_DWORD *)(a2 + 8460) << 16);
  HIDWORD(v64) = v38;
  v42 = *(_DWORD *)(a2 + 8496);
  v43 = v40 | (v39 << 16);
  v44 = v41 | (v37 << 16);
  v45 = *(unsigned __int16 *)(a2 + 8492);
  v46 = *(_DWORD *)(a2 + 8504);
  v47 = *(unsigned __int16 *)(a2 + 8500);
  v65 = __PAIR64__(v43, v44);
  v48 = *(_DWORD *)(a2 + 8532);
  v49 = v45 | (v42 << 16);
  v50 = v47 | (v46 << 16);
  v51 = *(unsigned __int16 *)(a2 + 8508);
  v52 = *(_DWORD *)(a2 + 8512);
  v66 = __PAIR64__(v50, v49);
  v53 = v51 | (v52 << 16);
  v54 = *(unsigned __int16 *)(a2 + 8536);
  v55 = *(_DWORD *)(a2 + 8540);
  v56 = *(unsigned __int16 *)(a2 + 8528) | (v48 << 16);
  v57 = *(_DWORD *)(a2 + 8556);
  v67 = __PAIR64__((unsigned int)*(unsigned __int16 *)(a2 + 8516) | (*(_DWORD *)(a2 + 8520) << 16), v53);
  v58 = v54 | (v55 << 16);
  v59 = *(_DWORD *)(a2 + 8548);
  v68 = __PAIR64__(v58, v56);
  v60 = *(unsigned __int16 *)(a2 + 8544);
  v61 = *(unsigned __int16 *)(a2 + 8552);
  *(_QWORD *)(a3 + 12) = 0;
  *(_DWORD *)a3 = 2;
  v62 = v60 | (v59 << 16);
  *(_DWORD *)(a3 + 20) = v29 + 288;
  *(_QWORD *)(a3 + 32) = &v64;
  *(_QWORD *)(a3 + 40) = 0x3000000000LL;
  v63 = *(__int64 (__fastcall **)(_QWORD))(a4 + 8);
  LODWORD(v69) = v62;
  HIDWORD(v69) = v61 | (v57 << 16);
  if ( *((_DWORD *)v63 - 1) != -1839634494 )
    __break(0x822Au);
  v35 = v63(a3);
  if ( v35 )
    _drm_err(
      "0x120: REG_BLK_WRITE_SINGLE %d len %zd buf idx %d\n",
      v35,
      48,
      *(unsigned int *)(*(_QWORD *)(a3 + 24) + 20LL));
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v35;
}
