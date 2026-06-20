__int64 __fastcall cam_smmu_mini_dump_cb(_QWORD *a1, unsigned __int64 a2)
{
  __int64 v4; // x21
  unsigned __int64 v5; // x23
  __int64 v6; // x27
  __int64 v7; // x22
  __int64 v8; // x10
  __int64 v9; // x11
  __int64 v10; // x12
  __int64 v11; // x10
  __int64 v12; // x11
  __int64 v13; // x12
  __int64 v14; // x11
  __int64 v15; // x10
  __int64 v16; // x12
  __int64 v17; // x10
  __int64 v18; // x11
  __int64 v19; // x12
  __int64 v20; // x10
  __int64 v21; // x11
  __int64 v22; // x12
  __int64 v23; // x10
  __int64 v24; // x11
  __int64 v25; // x12
  __int64 v26; // x10
  __int64 v27; // x11
  __int64 v28; // x12
  __int64 v29; // x10
  __int64 v30; // x11
  __int64 v31; // x12
  __int64 v32; // x10
  __int64 v33; // x11
  __int64 v34; // x12
  __int64 v35; // x10
  __int64 v36; // x11
  __int64 v37; // x12
  __int64 v38; // x10
  __int64 v39; // x11
  __int64 v40; // x12
  __int64 v41; // x10
  __int64 v42; // x11
  __int64 v43; // x12
  __int64 v44; // x10
  __int64 v45; // x11
  __int64 v46; // x12
  __int64 v47; // x10
  __int64 v48; // x11
  __int64 v49; // x12
  __int64 v50; // x10
  __int64 v51; // x11
  __int64 v52; // x12
  __int64 v53; // x10
  __int64 v54; // x11
  __int64 v55; // x12
  __int64 v56; // x0
  __int64 v57; // x8
  unsigned int v58; // w9
  unsigned __int64 v59; // kr00_8
  _QWORD *v60; // x11
  _QWORD *v61; // x12
  __int64 v62; // x13
  __int64 v63; // x14
  __int64 v64; // x13
  __int64 v65; // x14
  __int64 v66; // x11
  __int64 v67; // x16

  if ( !a1 || a2 <= 0xF )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_mini_dump_cb",
      5455,
      "Invalid params dst: %pk len:%lu",
      a1,
      a2);
    return 0;
  }
  *(_DWORD *)a1 = 0;
  v4 = 16;
  a1[1] = a1 + 2;
  if ( !dword_394060 || (a2 - 16) >> 3 < 0x31B )
    return v4;
  v5 = 0;
  v4 = 16;
  while ( 1 )
  {
    v6 = a1[1] + 6360 * v5;
    v7 = iommu_cb_set + 14280 * v5;
    *(_BYTE *)(v6 + 6351) = *(_BYTE *)(v7 + 8616);
    *(_BYTE *)(v6 + 6352) = *(_BYTE *)(v7 + 80);
    *(_BYTE *)(v6 + 6353) = *(_BYTE *)(v7 + 104);
    *(_BYTE *)(v6 + 6355) = *(_BYTE *)(v7 + 105);
    *(_BYTE *)(v6 + 6344) = *(_BYTE *)(v7 + 81);
    *(_BYTE *)(v6 + 6345) = *(_BYTE *)(v7 + 82);
    *(_BYTE *)(v6 + 6346) = *(_BYTE *)(v7 + 83);
    *(_BYTE *)(v6 + 6347) = *(_BYTE *)(v7 + 84);
    *(_BYTE *)(v6 + 6349) = *(_BYTE *)(v7 + 86);
    *(_BYTE *)(v6 + 6350) = *(_BYTE *)(v7 + 87);
    *(_DWORD *)(v6 + 6336) = *(_DWORD *)(v7 + 8648);
    *(_DWORD *)(v6 + 6340) = *(_DWORD *)(v7 + 8484);
    *(_QWORD *)(v6 + 6312) = *(_QWORD *)(v7 + 16);
    *(_QWORD *)(v6 + 6320) = *(_QWORD *)(v7 + 8656);
    *(_QWORD *)(v6 + 6328) = *(_QWORD *)(v7 + 96);
    *(_QWORD *)(v6 + 6256) = *(_QWORD *)(v7 + 24);
    *(_QWORD *)(v6 + 6264) = *(_QWORD *)(v7 + 8600);
    *(_QWORD *)(v6 + 6272) = *(_QWORD *)(v7 + 8608);
    *(_QWORD *)(v6 + 6280) = *(_QWORD *)(v7 + 8664);
    *(_DWORD *)(v6 + 6288) = *(_DWORD *)(v7 + 8480);
    *(_DWORD *)(v6 + 6292) = *(_DWORD *)(v7 + 8620);
    *(_DWORD *)(v6 + 6296) = *(_DWORD *)(v7 + 8624);
    *(_DWORD *)(v6 + 6304) = *(_DWORD *)(v7 + 8588);
    *(_DWORD *)(v6 + 6300) = *(_DWORD *)(v7 + 8584);
    *(_DWORD *)(v6 + 6308) = *(_DWORD *)(v7 + 8592);
    v8 = *(_QWORD *)(v7 + 176);
    v9 = *(_QWORD *)(v7 + 160);
    v10 = *(_QWORD *)(v7 + 168);
    *(_QWORD *)(v6 + 5624) = *(_QWORD *)(v7 + 184);
    *(_QWORD *)(v6 + 5616) = v8;
    *(_QWORD *)(v6 + 5608) = v10;
    *(_QWORD *)(v6 + 5600) = v9;
    v11 = *(_QWORD *)(v7 + 208);
    v12 = *(_QWORD *)(v7 + 192);
    v13 = *(_QWORD *)(v7 + 200);
    *(_QWORD *)(v6 + 5656) = *(_QWORD *)(v7 + 216);
    *(_QWORD *)(v6 + 5648) = v11;
    *(_QWORD *)(v6 + 5640) = v13;
    *(_QWORD *)(v6 + 5632) = v12;
    v14 = *(_QWORD *)(v7 + 328);
    v16 = *(_QWORD *)(v7 + 336);
    v15 = *(_QWORD *)(v7 + 344);
    *(_QWORD *)(v6 + 5696) = *(_QWORD *)(v7 + 320);
    *(_QWORD *)(v6 + 5720) = v15;
    *(_QWORD *)(v6 + 5712) = v16;
    *(_QWORD *)(v6 + 5704) = v14;
    v17 = *(_QWORD *)(v7 + 304);
    v18 = *(_QWORD *)(v7 + 288);
    v19 = *(_QWORD *)(v7 + 296);
    *(_QWORD *)(v6 + 5688) = *(_QWORD *)(v7 + 312);
    *(_QWORD *)(v6 + 5680) = v17;
    *(_QWORD *)(v6 + 5672) = v19;
    *(_QWORD *)(v6 + 5664) = v18;
    v20 = *(_QWORD *)(v7 + 1696);
    v21 = *(_QWORD *)(v7 + 1680);
    v22 = *(_QWORD *)(v7 + 1688);
    *(_QWORD *)(v6 + 5760) = *(_QWORD *)(v7 + 1672);
    *(_QWORD *)(v6 + 5784) = v20;
    *(_QWORD *)(v6 + 5776) = v22;
    *(_QWORD *)(v6 + 5768) = v21;
    v23 = *(_QWORD *)(v7 + 1656);
    v24 = *(_QWORD *)(v7 + 1640);
    v25 = *(_QWORD *)(v7 + 1648);
    *(_QWORD *)(v6 + 5752) = *(_QWORD *)(v7 + 1664);
    *(_QWORD *)(v6 + 5744) = v23;
    *(_QWORD *)(v6 + 5736) = v25;
    *(_QWORD *)(v6 + 5728) = v24;
    v26 = *(_QWORD *)(v7 + 3008);
    v27 = *(_QWORD *)(v7 + 2992);
    v28 = *(_QWORD *)(v7 + 3000);
    *(_QWORD *)(v6 + 5816) = *(_QWORD *)(v7 + 3016);
    *(_QWORD *)(v6 + 5808) = v26;
    *(_QWORD *)(v6 + 5800) = v28;
    *(_QWORD *)(v6 + 5792) = v27;
    v29 = *(_QWORD *)(v7 + 3040);
    v30 = *(_QWORD *)(v7 + 3024);
    v31 = *(_QWORD *)(v7 + 3032);
    *(_QWORD *)(v6 + 5848) = *(_QWORD *)(v7 + 3048);
    *(_QWORD *)(v6 + 5840) = v29;
    *(_QWORD *)(v6 + 5832) = v31;
    *(_QWORD *)(v6 + 5824) = v30;
    v32 = *(_QWORD *)(v7 + 240);
    v33 = *(_QWORD *)(v7 + 224);
    v34 = *(_QWORD *)(v7 + 232);
    *(_QWORD *)(v6 + 5880) = *(_QWORD *)(v7 + 248);
    *(_QWORD *)(v6 + 5872) = v32;
    *(_QWORD *)(v6 + 5864) = v34;
    *(_QWORD *)(v6 + 5856) = v33;
    v35 = *(_QWORD *)(v7 + 272);
    v36 = *(_QWORD *)(v7 + 256);
    v37 = *(_QWORD *)(v7 + 264);
    *(_QWORD *)(v6 + 5912) = *(_QWORD *)(v7 + 280);
    *(_QWORD *)(v6 + 5904) = v35;
    *(_QWORD *)(v6 + 5896) = v37;
    *(_QWORD *)(v6 + 5888) = v36;
    v38 = *(_QWORD *)(v7 + 4360);
    v39 = *(_QWORD *)(v7 + 4344);
    v40 = *(_QWORD *)(v7 + 4352);
    *(_QWORD *)(v6 + 5944) = *(_QWORD *)(v7 + 4368);
    *(_QWORD *)(v6 + 5936) = v38;
    *(_QWORD *)(v6 + 5928) = v40;
    *(_QWORD *)(v6 + 5920) = v39;
    v41 = *(_QWORD *)(v7 + 4392);
    v42 = *(_QWORD *)(v7 + 4376);
    v43 = *(_QWORD *)(v7 + 4384);
    *(_QWORD *)(v6 + 5976) = *(_QWORD *)(v7 + 4400);
    *(_QWORD *)(v6 + 5968) = v41;
    *(_QWORD *)(v6 + 5960) = v43;
    *(_QWORD *)(v6 + 5952) = v42;
    v44 = *(_QWORD *)(v7 + 7064);
    v45 = *(_QWORD *)(v7 + 7048);
    v46 = *(_QWORD *)(v7 + 7056);
    *(_QWORD *)(v6 + 6072) = *(_QWORD *)(v7 + 7072);
    *(_QWORD *)(v6 + 6064) = v44;
    *(_QWORD *)(v6 + 6056) = v46;
    *(_QWORD *)(v6 + 6048) = v45;
    v47 = *(_QWORD *)(v7 + 7096);
    v48 = *(_QWORD *)(v7 + 7080);
    v49 = *(_QWORD *)(v7 + 7088);
    *(_QWORD *)(v6 + 6104) = *(_QWORD *)(v7 + 7104);
    *(_QWORD *)(v6 + 6096) = v47;
    *(_QWORD *)(v6 + 6088) = v49;
    *(_QWORD *)(v6 + 6080) = v48;
    v50 = *(_QWORD *)(v7 + 5712);
    v51 = *(_QWORD *)(v7 + 5696);
    v52 = *(_QWORD *)(v7 + 5704);
    *(_QWORD *)(v6 + 6008) = *(_QWORD *)(v7 + 5720);
    *(_QWORD *)(v6 + 6000) = v50;
    *(_QWORD *)(v6 + 5992) = v52;
    *(_QWORD *)(v6 + 5984) = v51;
    v53 = *(_QWORD *)(v7 + 5744);
    v54 = *(_QWORD *)(v7 + 5728);
    v55 = *(_QWORD *)(v7 + 5736);
    *(_QWORD *)(v6 + 6040) = *(_QWORD *)(v7 + 5752);
    *(_QWORD *)(v6 + 6032) = v53;
    *(_QWORD *)(v6 + 6024) = v55;
    *(_QWORD *)(v6 + 6016) = v54;
    if ( *(_DWORD *)(iommu_cb_set + 14280 * v5 + 8624) )
    {
      scnprintf(v6 + 6160, 16, *(const char **)(v7 + 32));
      if ( *(_DWORD *)(iommu_cb_set + 14280 * v5 + 8624) > 1u )
      {
        scnprintf(v6 + 6176, 16, *(const char **)(v7 + 40));
        if ( *(_DWORD *)(iommu_cb_set + 14280 * v5 + 8624) >= 3u )
        {
          scnprintf(v6 + 6192, 16, *(const char **)(v7 + 48));
          if ( *(_DWORD *)(iommu_cb_set + 14280 * v5 + 8624) >= 4u )
          {
            scnprintf(v6 + 6208, 16, *(const char **)(v7 + 56));
            if ( *(_DWORD *)(iommu_cb_set + 14280 * v5 + 8624) >= 5u )
            {
              scnprintf(v6 + 6224, 16, *(const char **)(v7 + 64));
              if ( *(_DWORD *)(iommu_cb_set + 14280 * v5 + 8624) >= 6u )
              {
                v56 = scnprintf(v6 + 6240, 16, *(const char **)(v7 + 72));
                if ( *(_DWORD *)(iommu_cb_set + 14280 * v5 + 8624) > 6u )
                  break;
              }
            }
          }
        }
      }
    }
    v57 = *(_QWORD *)(v7 + 8672);
    if ( v57 != -1 )
    {
      if ( v57 >= 100 )
      {
        v59 = v57 + 1;
        LODWORD(v57) = 100;
        v58 = v59 % 0x64;
        do
        {
LABEL_18:
          v60 = (_QWORD *)(v7 + 8680 + 56LL * v58);
          v61 = (_QWORD *)(v6 + 56LL * v58);
          v63 = v60[1];
          v62 = v60[2];
          *v61 = *v60;
          v61[1] = v63;
          v61[2] = v62;
          v65 = v60[5];
          v64 = v60[6];
          v67 = v60[3];
          v66 = v60[4];
          v61[5] = v65;
          v61[6] = v64;
          if ( v58 + 1 < 0x64 )
            ++v58;
          else
            v58 -= 99;
          LODWORD(v57) = v57 - 1;
          v61[3] = v67;
          v61[4] = v66;
        }
        while ( (_DWORD)v57 );
        goto LABEL_22;
      }
      if ( (_DWORD)v57 )
      {
        v58 = 0;
        goto LABEL_18;
      }
    }
LABEL_22:
    ++v5;
    v4 += 6360;
    ++*(_DWORD *)a1;
    if ( v5 >= (unsigned int)dword_394060 || (a2 - v4) >> 3 <= 0x31A )
      return v4;
  }
  __break(0x5512u);
  return cam_smmu_fatal_pf_mask_open(v56);
}
