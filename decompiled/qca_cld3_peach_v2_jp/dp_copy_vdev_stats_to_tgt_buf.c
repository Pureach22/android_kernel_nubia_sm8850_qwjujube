void *__fastcall dp_copy_vdev_stats_to_tgt_buf(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x10
  int v5; // w11
  int v7; // w14
  int v8; // w15
  __int64 v9; // x9
  int v10; // w17
  int v11; // w8
  __int64 v12; // x9
  __int64 v13; // x10
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // x10
  __int64 v17; // x8
  __int64 v18; // x9
  __int64 v19; // x10
  __int64 v20; // x8
  __int64 v21; // x9
  __int64 v22; // x10
  __int64 v23; // x8
  __int64 v24; // x9
  __int64 v25; // x10
  __int64 v26; // x8
  __int64 v27; // x9
  __int64 v28; // x10
  __int64 v29; // x9
  __int64 v30; // x10
  __int64 v31; // x8
  __int64 v32; // x9
  __int64 v33; // x10
  __int64 v34; // x8
  __int64 v35; // x9
  __int64 v36; // x10
  __int64 v37; // x9
  __int64 v38; // x10
  __int64 v39; // x9
  __int64 v40; // x13
  __int64 v41; // x8
  __int64 v42; // x9
  __int64 v43; // x10
  __int64 v44; // x8
  __int64 v45; // x9
  __int64 v46; // x10
  __int64 v47; // x8
  __int64 v48; // x9
  __int64 v49; // x10
  __int64 v50; // x8
  __int64 v51; // x9
  __int64 v52; // x8
  __int64 v53; // x8
  int v54; // w8
  int v55; // w9
  int v56; // w12
  int v57; // w11
  unsigned int v58; // w10
  unsigned int v59; // w11
  int v60; // w16
  int v61; // w15
  unsigned int v62; // w14
  unsigned int v63; // w15
  unsigned int v64; // w17
  __int64 v65; // x0
  __int64 v66; // x13
  int v67; // w1
  int v68; // w1
  int v69; // w1
  int v70; // w1
  __int64 v71; // x1
  __int64 v72; // x3
  __int64 v73; // x13
  __int64 v74; // x1
  __int64 v75; // x8
  __int64 v76; // x9
  __int64 v77; // x8
  __int64 v78; // x9
  __int64 v79; // x8
  __int64 v80; // x9
  __int64 v81; // x8
  __int64 v82; // x9
  __int64 v83; // x8
  __int64 v84; // x9
  __int64 v85; // x8
  __int64 v86; // x9

  v3 = *(_QWORD *)(a1 + 8);
  v5 = *(_DWORD *)(a1 + 352);
  v7 = *(_DWORD *)(a1 + 360);
  v8 = *(_DWORD *)(a1 + 364);
  v9 = *(_QWORD *)(a1 + 16);
  v10 = *(_DWORD *)(a1 + 372);
  *(_QWORD *)a1 += *(_QWORD *)a2;
  *(_QWORD *)(a1 + 8) = v3 + *(_QWORD *)(a2 + 8);
  *(_QWORD *)(a1 + 16) = v9 + *(_QWORD *)(a2 + 16);
  LODWORD(v3) = *(_DWORD *)(a1 + 28);
  *(_DWORD *)(a1 + 24) += *(_DWORD *)(a2 + 24);
  *(_DWORD *)(a1 + 28) = v3 + *(_DWORD *)(a2 + 28);
  LODWORD(v3) = *(_DWORD *)(a1 + 36);
  LODWORD(v9) = *(_DWORD *)(a1 + 40);
  *(_DWORD *)(a1 + 32) += *(_DWORD *)(a2 + 32);
  *(_DWORD *)(a1 + 36) = v3 + *(_DWORD *)(a2 + 36);
  v11 = v9 + *(_DWORD *)(a2 + 40);
  v12 = *(_QWORD *)(a1 + 48);
  v13 = *(_QWORD *)(a1 + 56);
  *(_DWORD *)(a1 + 40) = v11;
  *(_QWORD *)(a1 + 48) = v12 + *(_QWORD *)(a2 + 48);
  v14 = v13 + *(_QWORD *)(a2 + 56);
  v15 = *(_QWORD *)(a1 + 64);
  v16 = *(_QWORD *)(a1 + 72);
  *(_QWORD *)(a1 + 56) = v14;
  *(_QWORD *)(a1 + 64) = v15 + *(_QWORD *)(a2 + 64);
  v17 = v16 + *(_QWORD *)(a2 + 72);
  v18 = *(_QWORD *)(a1 + 80);
  v19 = *(_QWORD *)(a1 + 88);
  *(_QWORD *)(a1 + 72) = v17;
  *(_QWORD *)(a1 + 80) = v18 + *(_QWORD *)(a2 + 80);
  v20 = v19 + *(_QWORD *)(a2 + 88);
  v21 = *(_QWORD *)(a1 + 96);
  v22 = *(_QWORD *)(a1 + 104);
  *(_QWORD *)(a1 + 88) = v20;
  *(_QWORD *)(a1 + 96) = v21 + *(_QWORD *)(a2 + 96);
  v23 = v22 + *(_QWORD *)(a2 + 104);
  v24 = *(_QWORD *)(a1 + 112);
  v25 = *(_QWORD *)(a1 + 120);
  *(_QWORD *)(a1 + 104) = v23;
  *(_QWORD *)(a1 + 112) = v24 + *(_QWORD *)(a2 + 112);
  v26 = v25 + *(_QWORD *)(a2 + 120);
  v27 = *(_QWORD *)(a1 + 128);
  v28 = *(_QWORD *)(a1 + 136);
  *(_QWORD *)(a1 + 120) = v26;
  *(_QWORD *)(a1 + 128) = v27 + *(_QWORD *)(a2 + 128);
  *(_QWORD *)(a1 + 136) = v28 + *(_QWORD *)(a2 + 136);
  LODWORD(v28) = *(_DWORD *)(a1 + 148);
  LODWORD(v27) = *(_DWORD *)(a1 + 152);
  *(_DWORD *)(a1 + 144) += *(_DWORD *)(a2 + 144);
  *(_DWORD *)(a1 + 148) = v28 + *(_DWORD *)(a2 + 148);
  LODWORD(v26) = v27 + *(_DWORD *)(a2 + 152);
  v29 = *(_QWORD *)(a1 + 160);
  v30 = *(_QWORD *)(a1 + 168);
  *(_DWORD *)(a1 + 152) = v26;
  *(_QWORD *)(a1 + 160) = v29 + *(_QWORD *)(a2 + 160);
  v31 = v30 + *(_QWORD *)(a2 + 168);
  v32 = *(_QWORD *)(a1 + 176);
  v33 = *(_QWORD *)(a1 + 184);
  *(_QWORD *)(a1 + 168) = v31;
  *(_QWORD *)(a1 + 176) = v32 + *(_QWORD *)(a2 + 176);
  v34 = v33 + *(_QWORD *)(a2 + 184);
  v35 = *(_QWORD *)(a1 + 192);
  v36 = *(_QWORD *)(a1 + 200);
  *(_QWORD *)(a1 + 184) = v34;
  *(_QWORD *)(a1 + 192) = v35 + *(_QWORD *)(a2 + 192);
  *(_QWORD *)(a1 + 200) = v36 + *(_QWORD *)(a2 + 200);
  LODWORD(v36) = *(_DWORD *)(a1 + 212);
  *(_DWORD *)(a1 + 208) += *(_DWORD *)(a2 + 208);
  LODWORD(v34) = v36 + *(_DWORD *)(a2 + 212);
  v37 = *(_QWORD *)(a1 + 216);
  v38 = *(_QWORD *)(a1 + 224);
  *(_DWORD *)(a1 + 212) = v34;
  *(_QWORD *)(a1 + 216) = v37 + *(_QWORD *)(a2 + 216);
  *(_QWORD *)(a1 + 224) = v38 + *(_QWORD *)(a2 + 224);
  LODWORD(v38) = *(_DWORD *)(a1 + 236);
  *(_DWORD *)(a1 + 232) += *(_DWORD *)(a2 + 232);
  *(_DWORD *)(a1 + 236) = v38 + *(_DWORD *)(a2 + 236);
  LODWORD(v38) = *(_DWORD *)(a1 + 244);
  *(_DWORD *)(a1 + 240) += *(_DWORD *)(a2 + 240);
  *(_DWORD *)(a1 + 244) = v38 + *(_DWORD *)(a2 + 244);
  LODWORD(v38) = *(_DWORD *)(a1 + 252);
  LODWORD(v37) = *(_DWORD *)(a1 + 256);
  *(_DWORD *)(a1 + 248) += *(_DWORD *)(a2 + 248);
  *(_DWORD *)(a1 + 252) = v38 + *(_DWORD *)(a2 + 252);
  LODWORD(v34) = v37 + *(_DWORD *)(a2 + 256);
  LODWORD(v37) = *(_DWORD *)(a1 + 260);
  *(_DWORD *)(a1 + 256) = v34;
  LODWORD(v34) = v37 + *(_DWORD *)(a2 + 260);
  v40 = *(_QWORD *)(a1 + 272);
  v39 = *(_QWORD *)(a1 + 280);
  *(_DWORD *)(a1 + 260) = v34;
  v41 = v39 + *(_QWORD *)(a2 + 280);
  v42 = *(_QWORD *)(a1 + 288);
  v43 = *(_QWORD *)(a1 + 296);
  *(_QWORD *)(a1 + 280) = v41;
  *(_QWORD *)(a1 + 288) = v42 + *(_QWORD *)(a2 + 288);
  v44 = v43 + *(_QWORD *)(a2 + 296);
  v45 = *(_QWORD *)(a1 + 304);
  v46 = *(_QWORD *)(a1 + 312);
  *(_QWORD *)(a1 + 296) = v44;
  *(_QWORD *)(a1 + 304) = v45 + *(_QWORD *)(a2 + 304);
  v47 = v46 + *(_QWORD *)(a2 + 312);
  v48 = *(_QWORD *)(a1 + 320);
  v49 = *(_QWORD *)(a1 + 328);
  *(_QWORD *)(a1 + 312) = v47;
  v50 = v48 + *(_QWORD *)(a2 + 320);
  v51 = *(_QWORD *)(a1 + 336);
  *(_QWORD *)(a1 + 320) = v50;
  v52 = v49 + *(_QWORD *)(a2 + 328);
  LODWORD(v49) = *(_DWORD *)(a1 + 348);
  *(_QWORD *)(a1 + 328) = v52;
  v53 = v51 + *(_QWORD *)(a2 + 336);
  LODWORD(v51) = *(_DWORD *)(a1 + 344);
  *(_QWORD *)(a1 + 336) = v53;
  v54 = v51 + *(_DWORD *)(a2 + 344);
  *(_DWORD *)(a1 + 344) = v54;
  v55 = v49 + *(_DWORD *)(a2 + 348);
  *(_DWORD *)(a1 + 348) = v55;
  v56 = v5 + *(_DWORD *)(a2 + 352);
  v57 = *(_DWORD *)(a1 + 356);
  *(_DWORD *)(a1 + 352) = v56;
  v58 = v57 + *(_DWORD *)(a2 + 356);
  *(_DWORD *)(a1 + 356) = v58;
  v59 = v7 + *(_DWORD *)(a2 + 360);
  *(_DWORD *)(a1 + 360) = v59;
  v60 = v8 + *(_DWORD *)(a2 + 364);
  v61 = *(_DWORD *)(a1 + 368);
  *(_DWORD *)(a1 + 364) = v60;
  v62 = v61 + *(_DWORD *)(a2 + 368);
  *(_DWORD *)(a1 + 368) = v62;
  v63 = v10 + *(_DWORD *)(a2 + 372);
  *(_DWORD *)(a1 + 372) = v63;
  v64 = *(_DWORD *)(a1 + 376) + *(_DWORD *)(a2 + 376);
  *(_DWORD *)(a1 + 376) = v64;
  v65 = (unsigned int)(*(_DWORD *)(a1 + 380) + *(_DWORD *)(a2 + 380));
  *(_DWORD *)(a1 + 380) = v65;
  v66 = v40 + *(_QWORD *)(a2 + 272);
  v67 = *(_DWORD *)(a1 + 400);
  *(_QWORD *)(a1 + 272) = v66;
  LODWORD(v66) = v67 + *(_DWORD *)(a2 + 400);
  v68 = *(_DWORD *)(a1 + 404);
  *(_DWORD *)(a1 + 400) = v66;
  LODWORD(v66) = v68 + *(_DWORD *)(a2 + 404);
  v69 = *(_DWORD *)(a1 + 408);
  *(_DWORD *)(a1 + 404) = v66;
  LODWORD(v66) = v69 + *(_DWORD *)(a2 + 408);
  v70 = *(_DWORD *)(a1 + 412);
  *(_DWORD *)(a1 + 408) = v66;
  LODWORD(v66) = v70 + *(_DWORD *)(a2 + 412);
  v71 = *(_QWORD *)(a1 + 416);
  v72 = *(_QWORD *)(a1 + 424);
  *(_DWORD *)(a1 + 412) = v66;
  v73 = v71 + *(_QWORD *)(a2 + 416);
  LODWORD(v71) = *(_DWORD *)(a1 + 384);
  *(_QWORD *)(a1 + 416) = v73;
  *(_QWORD *)(a1 + 424) = v72 + *(_QWORD *)(a2 + 424);
  LODWORD(v73) = v71 + *(_DWORD *)(a2 + 384);
  LODWORD(v71) = *(_DWORD *)(a1 + 388);
  *(_DWORD *)(a1 + 384) = v73;
  LODWORD(v73) = v71 + *(_DWORD *)(a2 + 388);
  v74 = *(unsigned int *)(a1 + 392);
  *(_DWORD *)(a1 + 388) = v73;
  *(_DWORD *)(a1 + 392) = v74 + *(_DWORD *)(a2 + 392);
  if ( a3 >= 3 )
  {
    __break(0x5512u);
    return (void *)dp_update_vdev_rate_stats(v65, v74);
  }
  else
  {
    v75 = (unsigned int)(v54 + v56 + v55 + v60);
    v76 = *(_QWORD *)(a1 + 2424);
    *(_QWORD *)(a1 + 264) = *(_QWORD *)(a1 + 280) + v75 + v58 + v62 + v59 + v63 + v64 + (unsigned int)v65;
    v77 = v76 + *(_QWORD *)(a2 + 2424);
    v78 = *(_QWORD *)(a1 + 2432);
    *(_QWORD *)(a1 + 2424) = v77;
    v79 = v78 + *(_QWORD *)(a2 + 2432);
    v80 = *(_QWORD *)(a1 + 2440);
    *(_QWORD *)(a1 + 2432) = v79;
    v81 = v80 + *(_QWORD *)(a2 + 2440);
    v82 = *(_QWORD *)(a1 + 2448);
    *(_QWORD *)(a1 + 2440) = v81;
    v83 = v82 + *(_QWORD *)(a2 + 2448);
    v84 = *(_QWORD *)(a1 + 2456);
    *(_QWORD *)(a1 + 2448) = v83;
    v85 = v84 + *(_QWORD *)(a2 + 2456);
    v86 = *(_QWORD *)(a1 + 2464);
    *(_QWORD *)(a1 + 2456) = v85;
    *(_QWORD *)(a1 + 2464) = v86 + *(_QWORD *)(a2 + 2464);
    qdf_mem_copy((void *)(a1 + 2424), (const void *)(a2 + 2424), 0x30u);
    qdf_mem_copy((void *)(a1 + 2472), (const void *)(a2 + 2472), 0x8F8u);
    qdf_mem_copy((void *)(a1 + 4768), (const void *)(a2 + 4768), 0x590u);
    qdf_mem_copy((void *)(a1 + 6192), (const void *)(a2 + 6192), 0x7C8u);
    return qdf_mem_copy((void *)(a1 + 8184), (const void *)(a2 + 8184), 0x8430u);
  }
}
