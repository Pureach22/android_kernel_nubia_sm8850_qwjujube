__int64 __fastcall sde_vdc_populate_config(__int64 a1, __int64 a2, int a3)
{
  int v3; // w9
  int v4; // w12
  unsigned int v5; // w10
  unsigned int v6; // w8
  int v7; // w14
  unsigned int v8; // w13
  int v9; // w11
  __int64 v10; // x17
  __int64 v11; // x14
  unsigned int v12; // w13
  int v13; // w13
  char v14; // w3
  unsigned int v15; // w4
  __int16 v16; // w8
  int v17; // w12
  unsigned __int16 v18; // w15
  char v19; // w21
  unsigned int v20; // w10
  unsigned __int16 v21; // w16
  __int16 v22; // w9
  unsigned __int16 v23; // w14
  __int16 v24; // w20
  __int16 v25; // w8
  unsigned __int64 v26; // x4
  unsigned __int64 v27; // x17
  int v28; // w12
  unsigned __int64 v29; // x3
  int v30; // w17
  int v31; // w6
  char v32; // w7
  unsigned int v33; // w11
  __int16 v34; // w8
  unsigned int v35; // w19
  int v36; // w11
  char v37; // w10
  int v38; // w9
  int v39; // w10
  __int16 v40; // w8
  unsigned int v41; // w9
  unsigned int v42; // w8
  unsigned int v43; // w9
  void *v44; // x9
  void *v45; // x0
  unsigned int v46; // w19
  __int64 v47; // x8
  char v48; // w10
  char v49; // w10
  __int64 *v50; // x12
  __int64 *v51; // x10
  __int64 *v52; // x11
  __int64 v53; // x12
  __int64 v54; // x13
  __int64 v55; // x11
  __int64 v56; // x14
  __int64 *v57; // t2
  __int64 v58; // x10
  unsigned int v59; // w13
  int v60; // w16
  int v61; // w3
  unsigned int v62; // w14
  unsigned int v63; // w14
  int v64; // w15
  __int64 v65; // x17
  int v66; // w14
  int v67; // w9
  int v68; // w12
  int v69; // w17
  int v70; // w10
  int v71; // w8
  int v72; // w11
  int v73; // w15
  int v74; // w11
  unsigned int v75; // w13
  int v76; // w3
  int v77; // w11
  int v78; // w12
  int v79; // w13
  int v80; // w15
  unsigned int v81; // w14
  unsigned int v82; // w10
  int v83; // w16
  _BOOL4 v84; // w14
  int v85; // w16
  int v86; // w9
  int v87; // w12
  unsigned int v88; // w13
  int v89; // w11
  bool v90; // zf
  int v91; // w8
  int v92; // w9
  int v93; // w14
  int v94; // w11
  int v95; // w15
  unsigned int v96; // w12
  unsigned int v97; // w13
  int v98; // w14
  int v99; // w8
  int v100; // w8
  int v101; // w8
  int v102; // w9
  __int64 v104; // x1

  if ( !a1 )
    goto LABEL_49;
  v3 = *(_DWORD *)(a1 + 476);
  if ( !v3 || v3 > (int)a2 || (v4 = *(_DWORD *)(a1 + 472)) == 0 )
  {
    printk(&unk_25BF47, a2);
LABEL_49:
    v45 = &unk_221B59;
LABEL_50:
    v46 = -22;
    printk(v45, 4294967274LL);
    return v46;
  }
  v5 = *(_WORD *)(a1 + 454) & 0xFFF0;
  v6 = v4 * v3;
  v7 = v3 * v5;
  *(_DWORD *)(a1 + 628) = v4 * v3;
  v8 = ((v3 * v5) >> 4) + 7;
  *(_BYTE *)(a1 + 402) = (int)a2 / v3;
  *(_WORD *)(a1 + 414) = (((v3 * v5) >> 4) + 7) & 0xFFF8;
  *(_WORD *)(a1 + 412) = v8 >> 3;
  v9 = *(unsigned __int8 *)(a1 + 403);
  if ( (unsigned int)(v4 * v3) <= 0xFFF )
  {
    printk(&unk_232A6B, v6);
    goto LABEL_49;
  }
  *(_WORD *)(a1 + 416) = v5;
  *(_WORD *)(a1 + 418) = ((2 * v8) & 0xFFF0) - ((unsigned int)(2 * v7) >> 4);
  *(_WORD *)(a1 + 424) = ((2 * v8) & 0xFFF0) - ((unsigned int)(2 * v7) >> 4);
  *(_WORD *)(a1 + 420) = v5 + ((2 * v8) & 0xFFF0) - ((unsigned int)(2 * v7) >> 4) - 8;
  v10 = 477218589LL
      * ((unsigned int)(unsigned __int16)(v5 + ((2 * v8) & 0xFFF0) - ((unsigned int)(2 * v7) >> 4) - 8) + 8);
  v11 = (int)((v8 & 0x7FFF8) * v4);
  *(_QWORD *)(a1 + 648) = v11;
  *(_WORD *)(a1 + 422) = WORD2(v10);
  if ( v3 > 720 )
  {
    if ( (unsigned int)v3 > 0x800 )
      v12 = 10752;
    else
      v12 = 0x2000;
  }
  else
  {
    v12 = 4096;
  }
  *(_WORD *)(a1 + 426) = v12;
  v13 = v12 / v5;
  v14 = v11 + 8;
  v15 = (unsigned int)v3 >> 3;
  v16 = __clz(v6);
  v17 = v4 / 6;
  v18 = v5 * v13;
  *(_WORD *)(a1 + 428) = v13;
  *(_WORD *)(a1 + 450) = v17;
  v19 = 32 - v16;
  *(_WORD *)(a1 + 442) = 33 - v16;
  *(_WORD *)(a1 + 430) = v5 * v13;
  v20 = (unsigned __int16)(v5 * v13) / v5;
  v21 = 2 * v18 + 4 * v3;
  v22 = 128 - (((_BYTE)v11 + 8) & 0x78);
  v23 = v17 * v15;
  if ( (v14 & 0x78) == 0 )
    v22 = 0;
  v24 = 32 - v16;
  v25 = v16 ^ 0x1F;
  v26 = ((v21 & 0xFFFE) - (unsigned __int64)(v18 & 0xFFF0)) << 16;
  if ( (v23 & 0xFFFE) != 0 )
    v27 = v23;
  else
    v27 = 1;
  *(_WORD *)(a1 + 440) = v25;
  *(_WORD *)(a1 + 458) = v22;
  v28 = *(unsigned __int8 *)(a1 + 6);
  *(_WORD *)(a1 + 460) = v22 ^ 0x3F8;
  v29 = v26 / v27;
  v30 = *(unsigned __int8 *)(a1 + 3);
  *(_WORD *)(a1 + 432) = v20;
  *(_WORD *)(a1 + 434) = 16 * v20;
  if ( v30 == 1 )
    v31 = 8;
  else
    v31 = 4;
  if ( v30 == 1 )
    v32 = 3;
  else
    v32 = 2;
  if ( !v30 )
    v31 = 16;
  *(_WORD *)(a1 + 436) = v21;
  *(_WORD *)(a1 + 438) = v24;
  *(_BYTE *)(a1 + 14) = v31;
  *(_WORD *)(a1 + 452) = v23;
  *(_QWORD *)(a1 + 656) = v26;
  v33 = ((2 * v31 + 16) * v9) | 7;
  *(_WORD *)(a1 + 444) = v33;
  *(_DWORD *)(a1 + 636) = v29;
  *(_DWORD *)(a1 + 632) = 1 << v19;
  *(_WORD *)(a1 + 456) = 1016;
  v34 = 16 * *(unsigned __int8 *)(a1 + 4);
  v35 = ((v33 >> 1) + 4096) / v33;
  v36 = *(unsigned __int8 *)(a1 + 5);
  *(_WORD *)(a1 + 448) = 0x100000 / (v21 & 0xFFFEu);
  if ( v30 )
    v37 = v32;
  else
    v37 = 4;
  *(_WORD *)(a1 + 462) = v34;
  v38 = v36 << v37;
  v39 = v28 << v37;
  *(_WORD *)(a1 + 464) = v38;
  v40 = v38 + v34;
  v41 = *(unsigned __int16 *)(a1 + 454);
  *(_WORD *)(a1 + 466) = v39;
  LOWORD(v39) = v40 + v39 + 8;
  v42 = v41 >> 4;
  v43 = *(unsigned __int8 *)(a1 + 403);
  *(_WORD *)(a1 + 468) = v39;
  *(_WORD *)(a1 + 446) = v35;
  if ( v30 == 1 )
  {
    if ( v43 == 8 && v42 == 6 )
    {
      v44 = &unk_6;
      goto LABEL_66;
    }
    if ( v43 == 8 && v42 == 5 )
    {
      v44 = &unk_7;
      goto LABEL_66;
    }
    if ( v43 == 10 && v42 == 8 )
    {
      v44 = &unk_9;
      goto LABEL_66;
    }
    if ( v43 == 10 && v42 == 6 )
    {
      v44 = &unk_A;
      goto LABEL_66;
    }
    if ( v43 == 10 && v42 == 5 )
    {
      v44 = &_ksymtab___traceiter_tracing_mark_write;
      goto LABEL_66;
    }
    goto LABEL_98;
  }
  if ( v30 )
  {
LABEL_98:
    printk(&unk_216EDA, v43);
    printk(&unk_27B1A8, v104);
    v45 = &unk_23620F;
    goto LABEL_50;
  }
  if ( v43 != 8 || v42 != 8 )
  {
    if ( v43 == 8 && v42 == 6 )
    {
      v44 = (char *)&_ksymtab___SCK__tp_func_tracing_mark_write + 1;
      goto LABEL_66;
    }
    if ( v43 == 10 && v42 == 10 )
    {
      v44 = (char *)&_ksymtab___SCK__tp_func_tracing_mark_write + 2;
      goto LABEL_66;
    }
    if ( v43 == 10 && v42 == 8 )
    {
      v44 = (char *)&_ksymtab___SCK__tp_func_tracing_mark_write + 3;
      goto LABEL_66;
    }
    if ( v43 == 10 && v42 == 7 )
    {
      v44 = &unk_4;
      goto LABEL_66;
    }
    if ( v43 == 10 && v42 == 6 )
    {
      v44 = &unk_5;
      goto LABEL_66;
    }
    goto LABEL_98;
  }
  v44 = nullptr;
LABEL_66:
  v47 = 0;
  *(_BYTE *)(a1 + 4) = sde_vdc_mppf_bpc_r_y[(_QWORD)v44];
  *(_BYTE *)(a1 + 5) = sde_vdc_mppf_bpc_g_cb[(_QWORD)v44];
  *(_BYTE *)(a1 + 6) = sde_vdc_mppf_bpc_b_cr[(_QWORD)v44];
  *(_BYTE *)(a1 + 7) = sde_vdc_mppf_bpc_y[(_QWORD)v44];
  v48 = sde_vdc_mppf_bpc_cg[(_QWORD)v44];
  *(_BYTE *)(a1 + 8) = v48;
  *(_BYTE *)(a1 + 9) = v48;
  *(_BYTE *)(a1 + 10) = sde_vdc_flat_qp_vf_fbls[(_QWORD)v44];
  v49 = sde_vdc_flat_qp_sf_fbls[(_QWORD)v44];
  *(_BYTE *)(a1 + 11) = v49;
  *(_BYTE *)(a1 + 12) = v49;
  v50 = &sde_vdc_flat_qp_lut[2 * (_QWORD)v44];
  *(_BYTE *)(a1 + 13) = sde_vdc_flat_qp_sf_nbls[(_QWORD)v44];
  *(_QWORD *)(a1 + 18) = *v50;
  v51 = &sde_vdc_max_qp_lut[2 * (_QWORD)v44];
  *(_QWORD *)(a1 + 26) = v50[1];
  *(_QWORD *)(a1 + 34) = *v51;
  *(_QWORD *)(a1 + 42) = v51[1];
  *(_QWORD *)(a1 + 50) = sde_vdc_tar_del_lut[4 * (_QWORD)v44];
  *(_QWORD *)(a1 + 58) = sde_vdc_tar_del_lut[4 * (_QWORD)v44 + 1];
  *(_QWORD *)(a1 + 66) = sde_vdc_tar_del_lut[4 * (_QWORD)v44 + 2];
  *(_QWORD *)(a1 + 74) = sde_vdc_tar_del_lut[4 * (_QWORD)v44 + 3];
  *(_QWORD *)(a1 + 82) = sde_vdc_lbda_brate_lut[4 * (_QWORD)v44];
  *(_QWORD *)(a1 + 90) = sde_vdc_lbda_brate_lut[4 * (_QWORD)v44 + 1];
  *(_QWORD *)(a1 + 98) = sde_vdc_lbda_brate_lut[4 * (_QWORD)v44 + 2];
  v52 = &sde_vdc_lbda_bf_lut[4 * (_QWORD)v44];
  *(_QWORD *)(a1 + 106) = sde_vdc_lbda_brate_lut[4 * (_QWORD)v44 + 3];
  v53 = *v52;
  v54 = v52[1];
  v57 = v52 + 2;
  v55 = v52[2];
  v56 = v57[1];
  *(_QWORD *)(a1 + 114) = v53;
  v58 = a1 + 114;
  *(_QWORD *)(a1 + 130) = v55;
  *(_QWORD *)(a1 + 138) = v56;
  *(_QWORD *)(a1 + 122) = v54;
  do
  {
    v59 = (unsigned int)v47 >> 2;
    v60 = v47 & 3;
    v61 = 4 - v60;
    if ( (unsigned int)v47 >> 2 >= 0xE )
      v62 = 14;
    else
      v62 = (unsigned int)v47 >> 2;
    v63 = v62 + 1;
    v64 = v60 * *(unsigned __int16 *)(a1 + 82 + 2LL * v63)
        + v61 * *(unsigned __int16 *)(a1 + 82 + 2LL * ((unsigned int)v47 >> 2));
    v65 = a1 + 2 * v47++;
    v66 = v60 * *(unsigned __int16 *)(v58 + 2LL * v63);
    *(_WORD *)(v65 + 146) = (unsigned int)(v64 + 2) >> 2;
    *(_WORD *)(v65 + 274) = (v66 + v61 * (unsigned int)*(unsigned __int16 *)(v58 + 2LL * v59) + 2) >> 2;
  }
  while ( v47 != 64 );
  v67 = *(_DWORD *)(a1 + 476);
  v68 = *(_DWORD *)(a1 + 504);
  v69 = *(unsigned __int16 *)(a1 + 434) >> 1;
  v70 = ((int)a2 + v67 - 1) / v67;
  v71 = *(unsigned __int16 *)(a1 + 454) >> 4;
  v72 = v67 * v71 + 14;
  if ( v68 > v70 )
    v68 = 1;
  if ( v67 * v71 + 7 >= 0 )
    v72 = v67 * v71 + 7;
  v73 = v72 >> 3;
  v74 = (v72 >> 3) * v70;
  *(_DWORD *)(a1 + 488) = v73;
  v75 = 0x540u / (2 * v71) + 1;
  v76 = v75 + v69 + 1100;
  *(_DWORD *)(a1 + 528) = v75;
  *(_DWORD *)(a1 + 532) = v76;
  *(_DWORD *)(a1 + 492) = v73 * v68;
  *(_DWORD *)(a1 + 500) = (v74 + 2) / 3;
  *(_DWORD *)(a1 + 540) = 2 * v76;
  *(_DWORD *)(a1 + 496) = v74 % 3;
  v77 = (v67 + 2 * v76 - 1) / v67;
  *(_DWORD *)(a1 + 508) = v70 / v68;
  *(_QWORD *)(a1 + 512) = 0x8100000080LL;
  *(_QWORD *)(a1 + 520) = 0x4000000044CLL;
  v78 = 2 * (v69 + 1024);
  *(_DWORD *)(a1 + 536) = v69 + 1024;
  v79 = v77 * v67;
  *(_DWORD *)(a1 + 544) = v78;
  *(_DWORD *)(a1 + 548) = v77;
  v80 = v77 * v67 - 2 * v76;
  *(_DWORD *)(a1 + 552) = v80;
  if ( a3 != 2 )
  {
    v82 = *(unsigned __int8 *)(a1 + 402);
    *(_DWORD *)(a1 + 556) = 2 * v71;
    v86 = 0;
    *(_QWORD *)(a1 + 560) = 100;
    v84 = v82 > 1;
    *(_DWORD *)(a1 + 568) = v84;
LABEL_80:
    *(_DWORD *)(a1 + 572) = 0;
    goto LABEL_81;
  }
  *(_DWORD *)(a1 + 556) = 64;
  v81 = (unsigned int)(200 * v71) >> 6;
  v82 = *(unsigned __int8 *)(a1 + 402);
  v83 = v81 * v67;
  *(_DWORD *)(a1 + 560) = v81;
  v84 = v82 > 1;
  *(_DWORD *)(a1 + 568) = v84;
  v85 = (int)(v83 * v82) / 100;
  *(_DWORD *)(a1 + 564) = v85;
  if ( v85 + v80 >= v67 )
  {
    v86 = 0;
    goto LABEL_80;
  }
  v86 = 1;
  *(_DWORD *)(a1 + 572) = 1;
LABEL_81:
  v87 = v79 - v78;
  v88 = *(unsigned __int16 *)(a1 + 414);
  v89 = v77 + v84 + v86;
  v90 = !v84;
  v91 = v87 * v71;
  v92 = v86 * v88;
  v93 = *(unsigned __int16 *)(a1 + 436);
  *(_DWORD *)(a1 + 576) = v89 + 1;
  v94 = 2 * v88;
  v95 = *(_DWORD *)(a1 + 480);
  if ( v90 )
    v96 = 0;
  else
    v96 = v88;
  *(_DWORD *)(a1 + 580) = v91;
  v97 = v88 >> 8;
  v98 = v92 + v93;
  if ( v90 )
    v94 = 0;
  *(_DWORD *)(a1 + 592) = v92;
  v99 = v98 + v91;
  v46 = 0;
  *(_DWORD *)(a1 + 596) = v99 + v94;
  *(_DWORD *)(a1 + 600) = v99 + v96;
  if ( v97 <= 3 )
    v100 = 3;
  else
    v100 = v97;
  *(_DWORD *)(a1 + 604) = v100;
  if ( v82 == 2 )
    v101 = 911;
  else
    v101 = 1471;
  *(_DWORD *)(a1 + 588) = v96;
  if ( v82 == 2 )
    v102 = 735;
  else
    v102 = 0;
  *(_DWORD *)(a1 + 608) = v101;
  *(_DWORD *)(a1 + 612) = v102;
  *(_DWORD *)(a1 + 584) = v94;
  *(_DWORD *)(a1 + 616) = v95 / (int)v82;
  *(_QWORD *)(a1 + 620) = 0x28300000503LL;
  return v46;
}
