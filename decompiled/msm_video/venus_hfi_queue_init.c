__int64 __fastcall venus_hfi_queue_init(__int64 a1)
{
  __int64 v2; // x8
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x8
  int v7; // w10
  _DWORD *v8; // x8
  int v9; // w9
  int v10; // w10
  char *v11; // x8
  void *v12; // x0
  int v13; // w9
  __int64 v14; // x10
  __int64 v15; // x11
  __int64 v16; // x10
  __int64 v17; // x11
  __int64 v18; // x11
  __int64 v19; // x10
  __int64 v20; // x12
  __int128 v21; // kr00_16
  __int64 v22; // x10
  __int64 v23; // x13
  __int64 v24; // x11
  __int64 v25; // x12
  __int64 v26; // x10
  int v27; // w8
  char *v28; // x14
  char *v29; // x8
  __int64 v30; // x14
  char *v31; // x14
  __int64 v32; // x13
  __int64 v33; // x8
  __int64 v34; // x8
  _DWORD *v35; // x8
  int v36; // w9
  char *v37; // x8
  int v38; // w9
  __int64 v39; // x9
  __int64 v40; // x10
  __int64 v41; // x9
  __int64 v42; // x11
  __int64 v43; // x9
  char *v44; // x10
  __int64 v45; // x10
  __int64 v46; // x12
  __int128 v47; // kr10_16
  __int64 v48; // x9
  __int64 v49; // x11
  __int64 v50; // x10
  __int64 v51; // x12
  __int64 v52; // x9
  __int64 v53; // x8
  unsigned int (__fastcall *v54)(__int64, __int64); // x8
  __int64 v55; // x8
  char *v56; // x0
  __int64 v57; // x8
  __int64 v58; // x9
  __int64 v59; // x9
  __int64 v60; // x9
  __int64 v61; // x8
  __int64 v62; // x10
  __int128 v63; // kr20_16
  __int64 v64; // x8
  __int64 v65; // x11
  __int64 v66; // x9
  __int64 v67; // x10
  __int64 v68; // x8
  _DWORD *v69; // x8
  __int64 v70; // x9
  __int64 v71; // x9
  __int64 v72; // x9
  __int64 v73; // x9
  __int64 v74; // [xsp+0h] [xbp-80h] BYREF
  __int64 v75; // [xsp+8h] [xbp-78h]
  __int64 v76; // [xsp+10h] [xbp-70h]
  __int128 v77; // [xsp+18h] [xbp-68h]
  __int64 v78; // [xsp+28h] [xbp-58h]
  __int64 v79; // [xsp+30h] [xbp-50h]
  char *v80; // [xsp+38h] [xbp-48h]
  __int64 v81; // [xsp+40h] [xbp-40h]
  __int64 v82; // [xsp+48h] [xbp-38h]
  __int64 v83; // [xsp+50h] [xbp-30h]
  __int64 v84; // [xsp+58h] [xbp-28h]
  __int64 v85; // [xsp+60h] [xbp-20h]
  __int64 v86; // [xsp+68h] [xbp-18h]
  __int64 v87; // [xsp+70h] [xbp-10h]
  __int64 v88; // [xsp+78h] [xbp-8h]

  v88 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v86 = 0;
  v87 = 0;
  v84 = 0;
  v85 = 0;
  v82 = 0;
  v83 = 0;
  v80 = nullptr;
  v81 = 0;
  v78 = 0;
  v79 = 0;
  v77 = 0u;
  v75 = 0;
  v76 = 0;
  v74 = 0;
  if ( (msm_vidc_debug & 2) != 0 )
  {
    printk(&unk_92979, "high", 0xFFFFFFFFLL, "codec", "venus_hfi_queue_init");
    if ( *(_QWORD *)(a1 + 4944) )
      goto LABEL_3;
  }
  else if ( *(_QWORD *)(a1 + 4944) )
  {
LABEL_3:
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_8ADAD, "high", 0xFFFFFFFFLL, "codec", "venus_hfi_queue_init");
    v2 = *(_QWORD *)(a1 + 5656);
    result = 0;
    *(_DWORD *)v2 = 1;
    *(_QWORD *)(v2 + 8) = 0x3200001010000LL;
    *(_DWORD *)(v2 + 16) = 0;
    *(_QWORD *)(v2 + 24) = 0x100000001LL;
    *(_DWORD *)(v2 + 32) = 1;
    *(_QWORD *)(v2 + 36) = 0;
    *(_QWORD *)(v2 + 44) = 0;
    *(_DWORD *)(v2 + 52) = 0;
    v4 = *(_QWORD *)(a1 + 5808);
    *(_DWORD *)v4 = 1;
    *(_QWORD *)(v4 + 8) = 0x3200001010000LL;
    *(_DWORD *)(v4 + 16) = 0;
    *(_QWORD *)(v4 + 24) = 0x100000001LL;
    *(_DWORD *)(v4 + 32) = 1;
    *(_QWORD *)(v4 + 36) = 0;
    *(_QWORD *)(v4 + 44) = 0;
    *(_DWORD *)(v4 + 52) = 0;
    v5 = *(_QWORD *)(a1 + 5960);
    *(_QWORD *)(v5 + 8) = 0x3200001010000LL;
    *(_DWORD *)v5 = 1;
    *(_DWORD *)(v5 + 16) = 0;
    *(_QWORD *)(v5 + 24) = 0x100000001LL;
    *(_DWORD *)(v5 + 32) = 1;
    *(_QWORD *)(v5 + 36) = 0;
    *(_QWORD *)(v5 + 44) = 0;
    *(_DWORD *)(v5 + 52) = 0;
    *(_DWORD *)(*(_QWORD *)(a1 + 5656) + 4LL) = *(_DWORD *)(a1 + 5664);
    v6 = *(_QWORD *)(a1 + 5808);
    v7 = *(_DWORD *)(v6 + 8) | 1;
    *(_DWORD *)(v6 + 4) = *(_DWORD *)(a1 + 5816);
    *(_DWORD *)(v6 + 8) = v7;
    v8 = *(_DWORD **)(a1 + 5960);
    v9 = *(_DWORD *)(a1 + 5968);
    v10 = v8[2];
    v8[8] = 0;
    v8[1] = v9;
    v8[2] = v10 | 2;
    goto LABEL_6;
  }
  v86 = 0;
  v87 = 0;
  v84 = 0;
  v85 = 0;
  v82 = 0;
  v83 = 0;
  v80 = nullptr;
  v81 = 0;
  v78 = 0;
  v79 = 0;
  HIDWORD(v77) = 0;
  v74 = 0;
  v75 = 0;
  v76 = 0x200000006LL;
  LODWORD(v77) = 3133440;
  *(_QWORD *)((char *)&v77 + 4) = 2;
  if ( a1 )
  {
    v11 = *(char **)(a1 + 6568);
    if ( v11 && (v11 = *((char **)v11 + 7)) != nullptr )
    {
      if ( *((_DWORD *)v11 - 1) != 481270700 )
        __break(0x8228u);
      if ( ((unsigned int (__fastcall *)(__int64, __int64 *))v11)(a1, &v74) )
      {
        if ( (msm_vidc_debug & 1) != 0 )
        {
          v12 = &unk_83C40;
LABEL_62:
          printk(v12, "err ", 0xFFFFFFFFLL, "codec", "venus_hfi_queue_init");
          result = 4294967284LL;
          goto LABEL_6;
        }
        goto LABEL_36;
      }
      v11 = v80;
      v13 = v81;
    }
    else
    {
      v13 = 0;
    }
  }
  else
  {
    v13 = 0;
    v11 = nullptr;
  }
  v14 = v84;
  v15 = v85;
  *(_DWORD *)(a1 + 4936) = v13;
  *(_QWORD *)(a1 + 4944) = v11;
  *(_DWORD *)(a1 + 5664) = v13 + 456;
  *(_QWORD *)(a1 + 5048) = v14;
  *(_QWORD *)(a1 + 5056) = v15;
  v16 = v86;
  v17 = v87;
  *(_QWORD *)(a1 + 5672) = v11 + 456;
  *(_QWORD *)(a1 + 5656) = v11 + 288;
  *(_QWORD *)(a1 + 5064) = v16;
  *(_QWORD *)(a1 + 5072) = v17;
  v18 = v81;
  *(_QWORD *)(a1 + 5016) = v80;
  v19 = v82;
  v20 = v83;
  *(_QWORD *)(a1 + 5024) = v18;
  *(_QWORD *)(a1 + 5032) = v19;
  v21 = v77;
  *(_QWORD *)(a1 + 5040) = v20;
  *(_QWORD *)(a1 + 4984) = v21;
  v22 = v78;
  v23 = v79;
  *(_QWORD *)(a1 + 4992) = *((_QWORD *)&v21 + 1);
  v24 = v75;
  v25 = v76;
  *(_QWORD *)(a1 + 5000) = v22;
  v26 = v74;
  *(_QWORD *)(a1 + 4968) = v24;
  *(_QWORD *)(a1 + 4960) = v26;
  *(_DWORD *)(a1 + 4952) = 456;
  *(_QWORD *)(a1 + 5008) = v23;
  *(_QWORD *)(a1 + 4976) = v25;
  *(_DWORD *)(a1 + 5680) = 819200;
  *((_DWORD *)v11 + 72) = 1;
  *((_QWORD *)v11 + 37) = 0x3200001010000LL;
  *((_DWORD *)v11 + 76) = 0;
  *((_QWORD *)v11 + 39) = 0x100000001LL;
  *((_DWORD *)v11 + 80) = 1;
  *(_QWORD *)(v11 + 324) = 0;
  *(_QWORD *)(v11 + 332) = 0;
  *((_DWORD *)v11 + 85) = 0;
  v27 = v81;
  v28 = v80;
  *(_DWORD *)(a1 + 5832) = 819200;
  *(_DWORD *)(a1 + 5816) = v27 + 819656;
  v29 = v28 + 819656;
  v30 = *(_QWORD *)(a1 + 4944);
  *(_QWORD *)(a1 + 5824) = v29;
  *(_QWORD *)(a1 + 5808) = v30 + 344;
  *(_DWORD *)(v30 + 344) = 1;
  *(_QWORD *)(v30 + 352) = 0x3200001010000LL;
  *(_DWORD *)(v30 + 360) = 0;
  *(_QWORD *)(v30 + 368) = 0x100000001LL;
  *(_DWORD *)(v30 + 376) = 1;
  *(_QWORD *)(v30 + 380) = 0;
  *(_QWORD *)(v30 + 388) = 0;
  *(_DWORD *)(v30 + 396) = 0;
  LODWORD(v29) = v81;
  v31 = v80;
  *(_DWORD *)(a1 + 5984) = 819200;
  *(_DWORD *)(a1 + 5968) = (_DWORD)v29 + 1638856;
  v32 = *(_QWORD *)(a1 + 4944);
  *(_QWORD *)(a1 + 5976) = v31 + 1638856;
  *(_QWORD *)(a1 + 5960) = v32 + 400;
  *(_DWORD *)(v32 + 400) = 1;
  *(_QWORD *)(v32 + 408) = 0x3200001010000LL;
  *(_DWORD *)(v32 + 416) = 0;
  *(_QWORD *)(v32 + 424) = 0x100000001LL;
  *(_DWORD *)(v32 + 432) = 1;
  *(_QWORD *)(v32 + 436) = 0;
  *(_QWORD *)(v32 + 444) = 0;
  *(_DWORD *)(v32 + 452) = 0;
  v33 = *(_QWORD *)(a1 + 4944);
  *(_QWORD *)(v33 + 24) = a1;
  strcpy((char *)(v33 + 32), "msm_v4l2_vidc");
  *(_QWORD *)v33 = 0x1C800000000LL;
  *(_QWORD *)(v33 + 8) = 0x3800000120LL;
  *(_QWORD *)(v33 + 16) = 0x300000003LL;
  *(_DWORD *)(*(_QWORD *)(a1 + 5656) + 4LL) = *(_DWORD *)(a1 + 5664);
  v34 = *(_QWORD *)(a1 + 5808);
  LODWORD(v26) = *(_DWORD *)(v34 + 8) | 1;
  *(_DWORD *)(v34 + 4) = *(_DWORD *)(a1 + 5816);
  *(_DWORD *)(v34 + 8) = v26;
  v35 = *(_DWORD **)(a1 + 5960);
  v36 = *(_DWORD *)(a1 + 5968);
  LODWORD(v26) = v35[2];
  v35[8] = 0;
  v35[1] = v36;
  v35[2] = v26 | 2;
  v76 = 0x200000006LL;
  HIDWORD(v77) = 0;
  v78 = 0;
  v79 = 0;
  v80 = nullptr;
  v81 = 0;
  v82 = 0;
  v83 = 0;
  v84 = 0;
  v85 = 0;
  v86 = 0;
  v87 = 0;
  v74 = 0;
  v75 = 0;
  LODWORD(v77) = 4096;
  *(_QWORD *)((char *)&v77 + 4) = 2;
  if ( a1 )
  {
    v37 = *(char **)(a1 + 6568);
    if ( v37 && (v37 = *((char **)v37 + 7)) != nullptr )
    {
      if ( *((_DWORD *)v37 - 1) != 481270700 )
        __break(0x8228u);
      if ( ((unsigned int (__fastcall *)(__int64, __int64 *))v37)(a1, &v74) )
      {
        if ( (msm_vidc_debug & 1) != 0 )
        {
          v12 = &unk_81B0E;
          goto LABEL_62;
        }
LABEL_36:
        result = 4294967284LL;
        goto LABEL_6;
      }
      v37 = v80;
      v38 = v81;
    }
    else
    {
      v38 = 0;
    }
  }
  else
  {
    v38 = 0;
    v37 = nullptr;
  }
  *(_DWORD *)(a1 + 4792) = v38;
  v40 = v84;
  v39 = v85;
  *(_QWORD *)(a1 + 4800) = v37;
  *(_DWORD *)(a1 + 4808) = 4096;
  *(_QWORD *)(a1 + 4912) = v39;
  v42 = v86;
  v41 = v87;
  *(_QWORD *)(a1 + 4904) = v40;
  *(_QWORD *)(a1 + 4928) = v41;
  v44 = v80;
  v43 = v81;
  *(_QWORD *)(a1 + 4920) = v42;
  *(_QWORD *)(a1 + 4872) = v44;
  v45 = v82;
  v46 = v83;
  *(_QWORD *)(a1 + 4880) = v43;
  *(_QWORD *)(a1 + 4888) = v45;
  v47 = v77;
  *(_QWORD *)(a1 + 4896) = v46;
  *(_QWORD *)(a1 + 4840) = v47;
  v48 = v78;
  v49 = v79;
  *(_QWORD *)(a1 + 4848) = *((_QWORD *)&v47 + 1);
  v50 = v75;
  v51 = v76;
  *(_QWORD *)(a1 + 4856) = v48;
  v52 = v74;
  *(_QWORD *)(a1 + 4864) = v49;
  *(_QWORD *)(a1 + 4816) = v52;
  *(_QWORD *)(a1 + 4824) = v50;
  *(_QWORD *)(a1 + 4832) = v51;
  *(_DWORD *)v37 = 4096;
  if ( a1 )
  {
    if ( *(_QWORD *)(a1 + 4624) )
    {
      v53 = *(_QWORD *)(a1 + 6568);
      if ( v53 )
      {
        v54 = *(unsigned int (__fastcall **)(__int64, __int64))(v53 + 72);
        if ( v54 )
        {
          if ( *((_DWORD *)v54 - 1) != 481270700 )
            __break(0x8228u);
          if ( v54(a1, a1 + 6640) )
          {
            if ( (msm_vidc_debug & 1) != 0 )
            {
              v12 = &unk_83C75;
              goto LABEL_62;
            }
            goto LABEL_36;
          }
        }
      }
    }
  }
  result = venus_hfi_iommu_map_registers(a1, 1, a1 + 5224);
  if ( (_DWORD)result )
    goto LABEL_6;
  result = venus_hfi_iommu_map_registers(a1, 2, a1 + 5368);
  if ( (_DWORD)result )
    goto LABEL_6;
  result = venus_hfi_iommu_map_registers(a1, 3, a1 + 5512);
  if ( (_DWORD)result )
    goto LABEL_6;
  v86 = 0;
  v87 = 0;
  v84 = 0;
  v85 = 0;
  v76 = 0x200000006LL;
  v82 = 0;
  v83 = 0;
  v80 = nullptr;
  v81 = 0;
  v78 = 0;
  v79 = 0;
  HIDWORD(v77) = 0;
  v74 = 0;
  v75 = 0;
  LODWORD(v77) = 4096;
  *(_QWORD *)((char *)&v77 + 4) = 2;
  if ( a1 )
  {
    v55 = *(_QWORD *)(a1 + 6568);
    if ( v55 && (v55 = *(_QWORD *)(v55 + 56)) != 0 )
    {
      if ( *(_DWORD *)(v55 - 4) != 481270700 )
        __break(0x8228u);
      if ( ((unsigned int (__fastcall *)(__int64, __int64 *))v55)(a1, &v74) )
      {
        if ( (msm_vidc_debug & 1) != 0 )
        {
          v12 = &unk_8EB6E;
          goto LABEL_62;
        }
        goto LABEL_36;
      }
      v56 = v80;
      LODWORD(v55) = v81;
    }
    else
    {
      v56 = nullptr;
    }
  }
  else
  {
    LODWORD(v55) = 0;
    v56 = nullptr;
  }
  *(_DWORD *)(a1 + 5080) = v55;
  v57 = v84;
  v58 = v85;
  *(_DWORD *)(a1 + 5096) = 4096;
  *(_QWORD *)(a1 + 5088) = v56;
  *(_QWORD *)(a1 + 5192) = v57;
  *(_QWORD *)(a1 + 5200) = v58;
  v59 = v87;
  *(_QWORD *)(a1 + 5208) = v86;
  *(_QWORD *)(a1 + 5216) = v59;
  v60 = v81;
  *(_QWORD *)(a1 + 5160) = v80;
  v61 = v82;
  v62 = v83;
  *(_QWORD *)(a1 + 5168) = v60;
  *(_QWORD *)(a1 + 5176) = v61;
  v63 = v77;
  *(_QWORD *)(a1 + 5184) = v62;
  *(_QWORD *)(a1 + 5128) = v63;
  v64 = v78;
  v65 = v79;
  *(_QWORD *)(a1 + 5136) = *((_QWORD *)&v63 + 1);
  v66 = v75;
  v67 = v76;
  *(_QWORD *)(a1 + 5144) = v64;
  v68 = v74;
  *(_QWORD *)(a1 + 5152) = v65;
  *(_QWORD *)(a1 + 5104) = v68;
  *(_QWORD *)(a1 + 5112) = v66;
  *(_QWORD *)(a1 + 5120) = v67;
  memset(v56, 0, 0x1000u);
  v69 = *(_DWORD **)(a1 + 5088);
  *v69 = 1;
  v70 = *(_QWORD *)(a1 + 5312);
  if ( v70 )
  {
    v69[11] = v70;
    v69[12] = *(_DWORD *)(a1 + 5272);
  }
  v71 = *(_QWORD *)(a1 + 6704);
  if ( v71 )
  {
    v69[13] = v71;
    v69[14] = *(_DWORD *)(a1 + 6664);
  }
  v72 = *(_QWORD *)(a1 + 5456);
  if ( v72 )
  {
    v69[19] = v72;
    v69[20] = *(_DWORD *)(a1 + 5416);
  }
  v73 = *(_QWORD *)(a1 + 5600);
  if ( v73 )
  {
    v69[21] = v73;
    result = 0;
    v69[22] = *(_DWORD *)(a1 + 5560);
  }
  else
  {
    result = 0;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
