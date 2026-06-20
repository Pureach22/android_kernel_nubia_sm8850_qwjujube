__int64 __fastcall hfi_setup_dspp_spr_dither_v2(__int64 a1, _DWORD *a2)
{
  int v3; // w3
  const void *v4; // x2
  __int64 v5; // x8
  int v6; // w9
  int v7; // w12
  int v8; // w17
  int v9; // w0
  __int64 v10; // x10
  int v11; // w25
  int v12; // w27
  int v13; // w22
  int v14; // w26
  __int64 v15; // x11
  int v16; // w23
  int v17; // w20
  int v18; // w24
  __int64 v19; // x10
  int v20; // w28
  int v21; // w21
  __int64 v22; // x9
  __int64 v23; // x9
  __int64 v24; // x9
  __int64 v25; // x11
  __int64 v26; // x12
  __int64 v27; // x12
  __int64 v28; // x9
  __int64 v29; // x10
  int v30; // w6
  int v31; // w7
  int v32; // w5
  int v33; // w15
  int v34; // w4
  int v35; // w13
  int v36; // w25
  int v37; // w23
  int v38; // w24
  int v39; // w16
  int v40; // w30
  int v41; // w14
  __int64 result; // x0
  int v43; // w8
  __int64 v44; // x20
  __int64 v45; // x1
  unsigned int v46; // w2
  unsigned int v47; // w10
  unsigned int v48; // w9
  __int64 v49; // x9
  __int64 v50; // x8
  __int64 v51; // x10
  __int64 v52; // x8
  __int64 v53; // x11
  __int64 v54; // x8
  __int64 v55; // x10
  __int64 v56; // x8
  __int64 v57; // x11
  __int64 v58; // x10
  __int64 v59; // x8
  __int64 v60; // x11
  __int64 v61; // x10
  int v62; // w8
  int *v63; // x0
  __int64 v64; // x10
  void *v65; // x0
  unsigned int v66; // w19
  int v67; // [xsp+0h] [xbp-420h]
  int v68; // [xsp+4h] [xbp-41Ch]
  int v69; // [xsp+8h] [xbp-418h]
  int v70; // [xsp+Ch] [xbp-414h]
  int v71; // [xsp+10h] [xbp-410h]
  int v72; // [xsp+14h] [xbp-40Ch]
  int v73; // [xsp+18h] [xbp-408h]
  int v74; // [xsp+1Ch] [xbp-404h]
  int v75; // [xsp+20h] [xbp-400h]
  int v76; // [xsp+24h] [xbp-3FCh]
  __int64 v77; // [xsp+28h] [xbp-3F8h]
  __int64 v78; // [xsp+30h] [xbp-3F0h]
  __int64 src; // [xsp+38h] [xbp-3E8h] BYREF
  __int64 v80; // [xsp+40h] [xbp-3E0h]
  int v81; // [xsp+48h] [xbp-3D8h]
  _BYTE s[816]; // [xsp+50h] [xbp-3D0h] BYREF
  __int64 v83; // [xsp+380h] [xbp-A0h]
  __int64 v84; // [xsp+388h] [xbp-98h]
  __int64 v85; // [xsp+390h] [xbp-90h]
  __int64 v86; // [xsp+398h] [xbp-88h]
  __int64 v87; // [xsp+3A0h] [xbp-80h]
  __int64 v88; // [xsp+3A8h] [xbp-78h]
  __int64 v89; // [xsp+3B0h] [xbp-70h]
  __int64 v90; // [xsp+3B8h] [xbp-68h]
  __int64 v91; // [xsp+3C0h] [xbp-60h]
  __int64 v92; // [xsp+3C8h] [xbp-58h]
  __int64 v93; // [xsp+3D0h] [xbp-50h]
  __int64 v94; // [xsp+3D8h] [xbp-48h]
  __int64 v95; // [xsp+3E0h] [xbp-40h]
  __int64 v96; // [xsp+3E8h] [xbp-38h]
  __int64 v97; // [xsp+3F0h] [xbp-30h]
  __int64 v98; // [xsp+3F8h] [xbp-28h]
  __int64 v99; // [xsp+400h] [xbp-20h]
  __int64 v100; // [xsp+408h] [xbp-18h]
  __int64 v101; // [xsp+410h] [xbp-10h]

  v101 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v95 = 0;
  v96 = 0;
  v97 = 0;
  v98 = 0;
  v99 = 0;
  v100 = 0;
  v89 = 0;
  v90 = 0;
  v91 = 0;
  v92 = 0;
  v93 = 0;
  v94 = 0;
  v83 = 0;
  v84 = 0;
  v85 = 0;
  v86 = 0;
  v87 = 0;
  v88 = 0;
  memset(s, 0, sizeof(s));
  if ( !a2 )
  {
    v4 = nullptr;
    v3 = 0;
    goto LABEL_11;
  }
  v3 = a2[2];
  v4 = *(const void **)a2;
  if ( v3 != 1120 )
  {
    if ( !v4 )
      goto LABEL_12;
LABEL_11:
    result = _drm_err("hw %pK payload %pK size %d expected sz %zd\n", a2, v4, v3, 0x460u);
    goto LABEL_30;
  }
  if ( !v4 )
  {
LABEL_12:
    _drm_dev_dbg(0, 0, 1, "Disable DSPP SPR dither feature\n");
    v43 = 0;
    v7 = 0;
    v77 = 0;
    v78 = 0;
    v8 = 0;
    v9 = 0;
    v34 = 0;
    v32 = 0;
    v33 = 0;
    v39 = 0;
    v30 = 0;
    v31 = 0;
    v37 = 0;
    v38 = 0;
    v36 = 0;
    v35 = 0;
    v41 = 0;
    v13 = 0;
    v12 = 0;
    v40 = 0;
    v20 = 0;
    v21 = 0;
    goto LABEL_15;
  }
  _drm_dev_dbg(0, 0, 1, "Enable DSPP SPR dither feature\n");
  v5 = *(_QWORD *)a2;
  v6 = *(_DWORD *)(*(_QWORD *)a2 + 92LL);
  v7 = **(_DWORD **)a2;
  v8 = *(_DWORD *)(*(_QWORD *)a2 + 24LL);
  LODWORD(v78) = *(_DWORD *)(*(_QWORD *)a2 + 12LL);
  HIDWORD(v78) = *(_DWORD *)(*(_QWORD *)a2 + 8LL);
  LODWORD(v77) = *(_DWORD *)(*(_QWORD *)a2 + 20LL);
  HIDWORD(v77) = *(_DWORD *)(*(_QWORD *)a2 + 16LL);
  if ( v6 )
    v9 = v6 - 1;
  else
    v9 = 0;
  if ( v6 )
  {
    v10 = *(_QWORD *)(v5 + 136);
    v11 = v9;
    v76 = **(_DWORD **)a2;
    v12 = *(_DWORD *)(v5 + 288);
    v14 = *(_DWORD *)(v5 + 232);
    v13 = *(_DWORD *)(v5 + 236);
    v97 = *(_QWORD *)(v5 + 128);
    v98 = v10;
    v15 = *(_QWORD *)(v5 + 152);
    v16 = *(_DWORD *)(v5 + 96);
    LODWORD(v10) = *(_DWORD *)(v5 + 100);
    v17 = *(_DWORD *)(v5 + 292);
    v99 = *(_QWORD *)(v5 + 144);
    v100 = v15;
    v18 = v8;
    v75 = v10;
    v19 = *(_QWORD *)(v5 + 120);
    v74 = *(_DWORD *)(v5 + 104);
    LODWORD(v15) = *(_DWORD *)(v5 + 108);
    v20 = *(_DWORD *)(v5 + 296);
    v21 = *(_DWORD *)(v5 + 300);
    v95 = *(_QWORD *)(v5 + 112);
    v96 = v19;
    v22 = *(_QWORD *)(v5 + 216);
    v73 = v15;
    LODWORD(v15) = *(_DWORD *)(v5 + 160);
    v93 = *(_QWORD *)(v5 + 208);
    v94 = v22;
    v23 = *(_QWORD *)(v5 + 200);
    v72 = v15;
    v71 = *(_DWORD *)(v5 + 164);
    LODWORD(v15) = *(_DWORD *)(v5 + 168);
    v91 = *(_QWORD *)(v5 + 192);
    v92 = v23;
    v24 = *(_QWORD *)(v5 + 184);
    v70 = v15;
    v69 = *(_DWORD *)(v5 + 172);
    v25 = *(_QWORD *)(v5 + 240);
    v26 = *(_QWORD *)(v5 + 248);
    v89 = *(_QWORD *)(v5 + 176);
    v90 = v24;
    LODWORD(v19) = *(_DWORD *)(v5 + 224);
    LODWORD(v24) = *(_DWORD *)(v5 + 228);
    v83 = v25;
    v84 = v26;
    v27 = *(_QWORD *)(v5 + 264);
    v67 = v19;
    v68 = v24;
    v28 = *(_QWORD *)(v5 + 272);
    v29 = *(_QWORD *)(v5 + 280);
    v85 = *(_QWORD *)(v5 + 256);
    v86 = v27;
    v87 = v28;
    v88 = v29;
    memcpy(s, (const void *)(v5 + 304), sizeof(s));
    v31 = v71;
    v30 = v72;
    v33 = v74;
    v32 = v75;
    v34 = v16;
    v9 = v11;
    v8 = v18;
    v36 = v67;
    v35 = v68;
    v38 = v69;
    v37 = v70;
    v39 = v73;
    v7 = v76;
    v40 = v17;
    v41 = v14;
  }
  else
  {
    v34 = *(_DWORD *)(v5 + 28);
    v32 = *(_DWORD *)(v5 + 32);
    v33 = *(_DWORD *)(v5 + 36);
    v39 = *(_DWORD *)(v5 + 40);
    v30 = *(_DWORD *)(v5 + 44);
    v31 = *(_DWORD *)(v5 + 48);
    v37 = *(_DWORD *)(v5 + 52);
    v38 = *(_DWORD *)(v5 + 56);
    v36 = *(_DWORD *)(v5 + 60);
    v35 = *(_DWORD *)(v5 + 64);
    v41 = *(_DWORD *)(v5 + 68);
    v13 = *(_DWORD *)(v5 + 72);
    v12 = *(_DWORD *)(v5 + 76);
    v40 = *(_DWORD *)(v5 + 80);
    v20 = *(_DWORD *)(v5 + 84);
    v21 = *(_DWORD *)(v5 + 88);
  }
  v43 = 1;
LABEL_15:
  v44 = *((_QWORD *)a2 + 23);
  v81 = 0;
  src = 0;
  v80 = 0;
  if ( !v44 || !*(_QWORD *)v44 || !*(_QWORD *)(v44 + 8) )
  {
    printk(&unk_21D2DE, v44);
LABEL_28:
    v66 = -22;
LABEL_29:
    result = printk(&unk_22DE8A, v66);
    goto LABEL_30;
  }
  v46 = a2[43];
  v45 = (unsigned int)a2[44];
  if ( (unsigned int)v45 < v46 )
  {
    v65 = &unk_276AA5;
LABEL_27:
    printk(v65, v45);
    goto LABEL_28;
  }
  v47 = *(_DWORD *)(v44 + 16);
  v48 = 1056 * (v45 - v46);
  if ( v48 + 1056 > v47 )
  {
    v45 = v47 - v48;
    v65 = &unk_279DBA;
    goto LABEL_27;
  }
  v49 = *(_QWORD *)(v44 + 8) + v48;
  *(_DWORD *)v49 = v43;
  *(_DWORD *)(v49 + 4) = v7;
  *(_DWORD *)(v49 + 24) = v8;
  *(_DWORD *)(v49 + 28) = v9;
  *(_DWORD *)(v49 + 32) = v34;
  *(_DWORD *)(v49 + 36) = v32;
  *(_DWORD *)(v49 + 8) = HIDWORD(v78);
  *(_DWORD *)(v49 + 12) = v78;
  *(_DWORD *)(v49 + 40) = v33;
  *(_DWORD *)(v49 + 44) = v39;
  *(_DWORD *)(v49 + 96) = v30;
  *(_DWORD *)(v49 + 100) = v31;
  *(_DWORD *)(v49 + 16) = HIDWORD(v77);
  *(_DWORD *)(v49 + 20) = v77;
  v50 = v97;
  v51 = v98;
  *(_DWORD *)(v49 + 104) = v37;
  *(_DWORD *)(v49 + 108) = v38;
  *(_DWORD *)(v49 + 160) = v36;
  *(_DWORD *)(v49 + 164) = v35;
  *(_QWORD *)(v49 + 64) = v50;
  *(_QWORD *)(v49 + 72) = v51;
  v53 = v99;
  v52 = v100;
  *(_DWORD *)(v49 + 168) = v41;
  *(_DWORD *)(v49 + 172) = v13;
  *(_DWORD *)(v49 + 224) = v12;
  *(_DWORD *)(v49 + 228) = v40;
  *(_QWORD *)(v49 + 80) = v53;
  *(_QWORD *)(v49 + 88) = v52;
  v55 = v95;
  v54 = v96;
  *(_DWORD *)(v49 + 232) = v20;
  *(_DWORD *)(v49 + 236) = v21;
  *(_QWORD *)(v49 + 48) = v55;
  *(_QWORD *)(v49 + 56) = v54;
  v56 = v90;
  *(_QWORD *)(v49 + 112) = v89;
  *(_QWORD *)(v49 + 120) = v56;
  v57 = v94;
  *(_QWORD *)(v49 + 144) = v93;
  *(_QWORD *)(v49 + 152) = v57;
  v58 = v92;
  *(_QWORD *)(v49 + 128) = v91;
  *(_QWORD *)(v49 + 136) = v58;
  v59 = v84;
  *(_QWORD *)(v49 + 176) = v83;
  *(_QWORD *)(v49 + 184) = v59;
  v60 = v88;
  *(_QWORD *)(v49 + 208) = v87;
  *(_QWORD *)(v49 + 216) = v60;
  v61 = v86;
  *(_QWORD *)(v49 + 192) = v85;
  *(_QWORD *)(v49 + 200) = v61;
  result = (__int64)memcpy((void *)(v49 + 240), s, 0x330u);
  v62 = a2[7];
  if ( a2[44] != a2[43] + v62 - 1 )
    goto LABEL_30;
  v63 = *((int **)a2 + 19);
  v64 = HIDWORD(*(_QWORD *)v44);
  LODWORD(src) = *(_QWORD *)v44;
  HIDWORD(src) = v64;
  LODWORD(v80) = 264 * v62;
  result = hfi_util_u32_prop_helper_add_prop(v63, 139536, 2, &src, 0x14u);
  if ( (_DWORD)result )
  {
    v66 = result;
    printk(&unk_26C3A5, 131344);
    goto LABEL_29;
  }
  if ( (_drm_debug & 4) != 0 )
    result = _drm_dev_dbg(0, 0, 0, "non-broadcast feature: submitted to prop_helper\n");
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
