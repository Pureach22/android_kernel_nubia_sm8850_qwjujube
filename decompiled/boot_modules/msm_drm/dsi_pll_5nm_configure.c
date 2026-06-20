__int64 __fastcall dsi_pll_5nm_configure(__int64 a1, char a2)
{
  __int64 v2; // x19
  __int64 v4; // x1
  __int64 v5; // x21
  const char *v6; // x5
  int v7; // w0
  _QWORD *v8; // x21
  int v9; // w0
  _QWORD *v10; // x21
  int v11; // w0
  _QWORD *v12; // x21
  int v13; // w0
  __int64 v14; // x20
  __int64 v15; // x23
  int v16; // w4
  __int64 v17; // x22
  _DWORD *v18; // x8
  __int64 v19; // x20
  __int64 v20; // x24
  unsigned __int64 v21; // x25
  unsigned __int64 v22; // x23
  _DWORD *v23; // x26
  int v24; // w3
  __int64 v25; // x0
  char v26; // w0
  char v27; // w11
  int v28; // w7
  __int64 v29; // x9
  unsigned __int64 v30; // x10
  int v31; // w8
  int v32; // w5
  int v33; // w4
  int v34; // w6
  int v35; // w7
  __int64 v36; // x8
  char v37; // w10
  int v38; // w9
  int v39; // w11
  __int64 v40; // x8
  unsigned __int64 v41; // x9
  unsigned __int64 v42; // x5
  __int64 v43; // x9
  int v44; // w10
  char v45; // w11
  __int64 v46; // x6
  int v47; // w9
  __int64 v48; // x11
  unsigned int v49; // w10
  unsigned __int64 v50; // x8
  unsigned __int64 v51; // x11
  unsigned __int64 v52; // x8
  int v53; // w20
  unsigned __int64 v54; // x21
  int v55; // w22
  int v56; // w4
  __int64 v57; // x20
  __int64 v58; // x0
  unsigned __int64 v59; // x21
  __int64 v60; // x20
  __int64 v61; // x1
  __int64 v62; // x0
  _QWORD *v63; // x8
  _QWORD *v64; // x8
  _QWORD *v65; // x8
  __int64 v66; // x20
  int v67; // w4
  unsigned __int64 v69; // x8
  int v70; // w10
  unsigned __int64 v71; // x8
  unsigned __int64 v72; // x9
  int v73; // w0
  char v74; // w0
  int v75; // w8
  int v76; // w0
  int v77; // w20
  __int64 v78; // x8
  unsigned int v79; // w20
  __int64 v80; // x8
  __int64 v81; // x8
  int v82; // w22
  __int64 v83; // x8
  int v84; // w22
  __int64 v85; // x8
  int v86; // w22
  __int64 v87; // x8
  int v88; // w22

  v2 = a1;
  if ( !a1 )
    goto LABEL_11;
  v4 = *(unsigned int *)(a1 + 100);
  if ( ((unsigned int)v4 | 2) != 2 )
    goto LABEL_11;
  *(_QWORD *)(a1 + 120) = 0;
  if ( (unsigned int)v4 <= 2 )
  {
    v5 = pll_rsc_db[v4 + 1];
    if ( v5 )
    {
      if ( (readl_relaxed_16(*(_QWORD *)(v5 + 8) + 20LL) & 0xC) == 4 )
      {
        v6 = "configured";
        *(_QWORD *)(v2 + 120) = v5;
      }
      else if ( *(_QWORD *)(v2 + 120) )
      {
        v6 = "configured";
      }
      else
      {
        v6 = "absent";
      }
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_PLL_%d: Slave PLL %s\n", *(_DWORD *)(v2 + 100), v6);
    }
    else
    {
      printk(&unk_25C2BA, v4);
    }
LABEL_11:
    v7 = readl_relaxed_16(*(_QWORD *)(v2 + 8) + 36LL);
    writel_relaxed_13(v7 | 0x20u, *(_QWORD *)(v2 + 8) + 36LL);
    writel_relaxed_13(192, *(_QWORD *)v2 + 40LL);
    _const_udelay(1250);
    v8 = *(_QWORD **)(v2 + 120);
    if ( v8 )
    {
      v9 = readl_relaxed_16(v8[1] + 36LL);
      writel_relaxed_13(v9 | 0x20u, v8[1] + 36LL);
      writel_relaxed_13(192, *v8 + 40LL);
      _const_udelay(1250);
    }
    v10 = *(_QWORD **)(v2 + 128);
    if ( v10 )
    {
      v11 = readl_relaxed_16(v10[1] + 36LL);
      writel_relaxed_13(v11 | 0x20u, v10[1] + 36LL);
      writel_relaxed_13(192, *v10 + 40LL);
      _const_udelay(1250);
    }
    v12 = *(_QWORD **)(v2 + 136);
    if ( v12 )
    {
      v13 = readl_relaxed_16(v12[1] + 36LL);
      writel_relaxed_13(v13 | 0x20u, v12[1] + 36LL);
      writel_relaxed_13(192, *v12 + 40LL);
      _const_udelay(1250);
    }
    if ( (a2 & 1) != 0 )
    {
      v14 = *(_QWORD *)v2;
      writel_relaxed_13(0, *(_QWORD *)v2);
      writel_relaxed_13(63, v14 + 8);
      writel_relaxed_13(0, v14 + 12);
      writel_relaxed_13(0, v14 + 20);
      writel_relaxed_13(128, v14 + 28);
      writel_relaxed_13(0, v14 + 40);
      writel_relaxed_13(0, v14 + 44);
      writel_relaxed_13(16, v14 + 48);
      writel_relaxed_13(32, v14 + 52);
      writel_relaxed_13(16, v14 + 56);
      writel_relaxed_13(2, v14 + 60);
      writel_relaxed_13(28, v14 + 64);
      writel_relaxed_13(0, v14 + 72);
      writel_relaxed_13(2, v14 + 76);
      writel_relaxed_13(32, v14 + 80);
      writel_relaxed_13(0, v14 + 84);
      writel_relaxed_13(255, v14 + 88);
      writel_relaxed_13(0, v14 + 92);
      writel_relaxed_13(10, v14 + 96);
      writel_relaxed_13(37, v14 + 100);
      writel_relaxed_13(186, v14 + 104);
      writel_relaxed_13(79, v14 + 108);
      writel_relaxed_13(10, v14 + 112);
      writel_relaxed_13(0, v14 + 116);
      writel_relaxed_13(12, v14 + 120);
      writel_relaxed_13(32, v14 + 124);
      writel_relaxed_13(0, v14 + 128);
      writel_relaxed_13(255, v14 + 132);
      writel_relaxed_13(16, v14 + 136);
      writel_relaxed_13(70, v14 + 140);
      writel_relaxed_13(84, v14 + 152);
      writel_relaxed_13(0, v14 + 156);
      writel_relaxed_13(0, v14 + 160);
      writel_relaxed_13(64, v14 + 164);
      writel_relaxed_13(4, v14 + 172);
      writel_relaxed_13(0, v14 + 176);
      writel_relaxed_13(0, v14 + 180);
      writel_relaxed_13(0, v14 + 184);
      writel_relaxed_13(16, v14 + 188);
      writel_relaxed_13(0, v14 + 192);
      writel_relaxed_13(8, v14 + 196);
      writel_relaxed_13(8, v14 + 200);
      writel_relaxed_13(0, v14 + 220);
      writel_relaxed_13(3, v14 + 256);
      writel_relaxed_13(0, v14 + 260);
      writel_relaxed_13(0, v14 + 264);
      writel_relaxed_13(0, v14 + 268);
      writel_relaxed_13(0, v14 + 272);
      writel_relaxed_13(0, v14 + 276);
      writel_relaxed_13(0, v14 + 280);
      writel_relaxed_13(0, v14 + 284);
      writel_relaxed_13(0, v14 + 288);
      writel_relaxed_13(0, v14 + 292);
      writel_relaxed_13(0, v14 + 296);
      writel_relaxed_13(0, v14 + 300);
      writel_relaxed_13(0, v14 + 304);
      writel_relaxed_13(0, v14 + 308);
      writel_relaxed_13(0, v14 + 312);
      writel_relaxed_13(0, v14 + 316);
      writel_relaxed_13(0, v14 + 320);
      writel_relaxed_13(0, v14 + 324);
      writel_relaxed_13(0, v14 + 328);
      writel_relaxed_13(0, v14 + 332);
      writel_relaxed_13(0, v14 + 336);
      writel_relaxed_13(0, v14 + 340);
      writel_relaxed_13(64, v14 + 344);
      writel_relaxed_13(64, v14 + 348);
      writel_relaxed_13(12, v14 + 352);
      writel_relaxed_13(10, v14 + 356);
      writel_relaxed_13(192, v14 + 360);
      writel_relaxed_13(0, v14 + 364);
      writel_relaxed_13(84, v14 + 368);
      writel_relaxed_13(84, v14 + 372);
      writel_relaxed_13(76, v14 + 376);
      writel_relaxed_13(76, v14 + 380);
      writel_relaxed_13(3, v14 + 384);
      writel_relaxed_13(0, v14 + 388);
      writel_relaxed_13(0, v14 + 392);
      writel_relaxed_13(0, v14 + 396);
      writel_relaxed_13(128, v14 + 400);
      writel_relaxed_13(6, v14 + 404);
      writel_relaxed_13(25, v14 + 408);
      writel_relaxed_13(0, v14 + 412);
      writel_relaxed_13(0, v14 + 416);
      writel_relaxed_13(64, v14 + 420);
      writel_relaxed_13(32, v14 + 424);
      writel_relaxed_13(0, v14 + 428);
      writel_relaxed_13(0, v14 + 432);
      writel_relaxed_13(0, v14 + 436);
      writel_relaxed_13(0, v14 + 440);
      writel_relaxed_13(0, v14 + 444);
      writel_relaxed_13(0, v14 + 448);
      writel_relaxed_13(0, v14 + 452);
      writel_relaxed_13(0, v14 + 456);
      writel_relaxed_13(0, v14 + 460);
      writel_relaxed_13(0, v14 + 464);
      writel_relaxed_13(2, v14 + 468);
      writel_relaxed_13(17, v14 + 472);
      writel_relaxed_13(0, v14 + 476);
      writel_relaxed_13(0, v14 + 480);
      writel_relaxed_13(128, v14 + 484);
      writel_relaxed_13(0, v14 + 488);
      writel_relaxed_13(0, v14 + 492);
      writel_relaxed_13(0, v14 + 496);
      writel_relaxed_13(0, v14 + 500);
      writel_relaxed_13(0, v14 + 504);
      writel_relaxed_13(0, v14 + 508);
      writel_relaxed_13(0, v14 + 512);
      writel_relaxed_13(0, v14 + 516);
      writel_relaxed_13(0, v14 + 520);
      writel_relaxed_13(0, v14 + 524);
      writel_relaxed_13(0, v14 + 528);
      writel_relaxed_13(0, v14 + 532);
      writel_relaxed_13(0, v14 + 536);
      writel_relaxed_13(0, v14 + 540);
      writel_relaxed_13(0, v14 + 544);
      writel_relaxed_13(0, v14 + 548);
      writel_relaxed_13(29, v14 + 552);
      writel_relaxed_13(28, v14 + 556);
      writel_relaxed_13(255, v14 + 560);
      writel_relaxed_13(34, v14 + 564);
      writel_relaxed_13(9, v14 + 568);
      writel_relaxed_13(0, v14 + 572);
      writel_relaxed_13(0, v14 + 576);
      writel_relaxed_13(0, v14 + 580);
      writel_relaxed_13(64, v14 + 584);
      writel_relaxed_13(0, v14 + 588);
      writel_relaxed_13(16, v14 + 592);
      writel_relaxed_13(16, v14 + 596);
      writel_relaxed_13(3, v14 + 604);
      dsi_pll_5nm_set_byteclk_div(v2, 1);
      dsi_pll_5nm_set_pclk_div(v2, 1);
      v15 = *(_QWORD *)(v2 + 144);
      if ( v15 )
      {
        if ( v2 )
          v16 = *(_DWORD *)(v2 + 100);
        else
          v16 = -1;
        _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_PLL_%d: rate=%llu\n", v16, *(_QWORD *)(v2 + 56));
        v25 = *(_QWORD *)(v2 + 8) + 24LL;
        *(_QWORD *)(v2 + 32) = *(_QWORD *)(v2 + 56);
        v26 = readl_relaxed_16(v25);
        v27 = *(_BYTE *)(v15 + 21);
        v28 = *(_DWORD *)(v15 + 28);
        *(_BYTE *)(v15 + 112) = (v26 & 0x40) != 0;
        v30 = *(_QWORD *)(v2 + 32);
        v29 = *(_QWORD *)(v2 + 40);
        if ( v30 >= 0x3B9ACA01 )
        {
          if ( v30 >= 0x9502F901 )
          {
            if ( v30 < 0xD09DC301 )
            {
              *(_DWORD *)(v15 + 80) = 0;
              goto LABEL_47;
            }
            v31 = 64;
          }
          else
          {
            v31 = 32;
          }
        }
        else
        {
          v31 = 160;
        }
        *(_DWORD *)(v15 + 80) = v31;
LABEL_47:
        v40 = (int)(1LL << v28);
        v41 = v30 * v40 / (unsigned int)(v29 << (v27 ^ 1u));
        v42 = v41 >> v28;
        v43 = v41 & ((1LL << v28) + 0xFFFFFFFFLL);
        *(_DWORD *)(v15 + 64) = v42;
        *(_DWORD *)(v15 + 68) = (unsigned __int8)v43;
        v44 = *(_DWORD *)(v15 + 32);
        *(_DWORD *)(v15 + 72) = BYTE1(v43);
        *(_DWORD *)(v15 + 76) = WORD1(v43) & 3;
        v45 = *(_BYTE *)(v15 + 22);
        *(_DWORD *)(v15 + 56) = 10;
        *(_DWORD *)(v15 + 60) = v44;
        if ( (v45 & 1) != 0 )
        {
          v46 = v43 & 0x3FFFF;
          v47 = *(_DWORD *)(v15 + 44);
          v48 = (unsigned int)(v47 + 1);
          v49 = ((unsigned int)(*(_DWORD *)(v15 + 8) + (*(_DWORD *)(v15 + 36) >> 1)) / *(_DWORD *)(v15 + 36)) >> 1;
          v50 = (v46 + (unsigned int)v42 * v40) * v48 * *(unsigned int *)(v15 + 40);
          v51 = v49 / (unsigned int)v48 * (unsigned int)v48;
          v52 = v50 / v51;
          LODWORD(v51) = ~(v49 - v51);
          v53 = v49 + v51;
          *(_DWORD *)(v15 + 100) = (unsigned __int8)v47;
          *(_DWORD *)(v15 + 104) = BYTE1(v47);
          *(_DWORD *)(v15 + 92) = (unsigned __int8)(v49 + v51);
          *(_DWORD *)(v15 + 96) = (unsigned __int8)((unsigned __int16)(v49 + v51) >> 8);
          v54 = (v52 + 500000) / 0xF4240;
          *(_DWORD *)(v15 + 108) = *(unsigned __int8 *)(v15 + 23);
          *(_DWORD *)(v15 + 84) = (unsigned __int8)v54;
          *(_DWORD *)(v15 + 88) = (unsigned __int8)((v52 + 500000) / 0xF424000);
          if ( v2 )
          {
            _drm_dev_dbg(
              0,
              0,
              0,
              "[msm-dsi-debug]: DSI_PLL_%d: SCC: Dec:%d, frac:%llu, frac_bits:%d\n",
              *(_DWORD *)(v2 + 100),
              v42,
              v46,
              v28);
            v55 = *(_DWORD *)(v2 + 100);
          }
          else
          {
            v55 = -1;
            _drm_dev_dbg(
              0,
              0,
              0,
              "[msm-dsi-debug]: DSI_PLL_%d: SCC: Dec:%d, frac:%llu, frac_bits:%d\n",
              -1,
              v42,
              v46,
              v28);
          }
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dsi-debug]: DSI_PLL_%d: SSC: div_per:0x%X, stepsize:0x%X, adjper:0x%X\n",
            v55,
            v53,
            v54,
            *(_DWORD *)(v15 + 44));
        }
        else
        {
          if ( v2 )
            v56 = *(_DWORD *)(v2 + 100);
          else
            v56 = -1;
          _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_PLL_%d: SSC not enabled\n", v56);
        }
        v57 = *(_QWORD *)v2;
        writel_relaxed_13(18, *(_QWORD *)v2 + 188LL);
        writel_relaxed_13(*(unsigned int *)(v15 + 64), v57 + 224);
        writel_relaxed_13(*(unsigned int *)(v15 + 68), v57 + 228);
        writel_relaxed_13(*(unsigned int *)(v15 + 72), v57 + 232);
        writel_relaxed_13(*(unsigned int *)(v15 + 76), v57 + 236);
        writel_relaxed_13(*(unsigned int *)(v15 + 60), v57 + 344);
        writel_relaxed_13(6, v57 + 404);
        if ( *(_BYTE *)(v15 + 112) )
          v58 = 0;
        else
          v58 = 16;
        writel_relaxed_13(v58, v57 + 592);
        writel_relaxed_13(*(unsigned int *)(v15 + 80), v57 + 584);
        v59 = *(_QWORD *)(v2 + 32);
        v60 = *(_QWORD *)v2;
        v61 = *(_QWORD *)v2 + 600LL;
        if ( v59 >= 0xB8C63F00 )
        {
          writel_relaxed_13(3, v61);
        }
        else
        {
          writel_relaxed_13(1, v61);
          if ( v59 < 0x5A995C00 )
          {
            v62 = 8;
LABEL_64:
            writel_relaxed_13(v62, v60 + 576);
            writel_relaxed_13(1, v60 + 24);
            writel_relaxed_13(3, v60 + 4);
            writel_relaxed_13(0, v60 + 16);
            writel_relaxed_13(0, v60 + 32);
            writel_relaxed_13(78, v60 + 36);
            writel_relaxed_13(64, v60 + 68);
            writel_relaxed_13(186, v60 + 104);
            writel_relaxed_13(12, v60 + 120);
            writel_relaxed_13(0, v60 + 168);
            writel_relaxed_13(0, v60 + 184);
            writel_relaxed_13(8, v60 + 200);
            writel_relaxed_13(10, v60 + 352);
            writel_relaxed_13(192, v60 + 360);
            writel_relaxed_13(132, v60 + 368);
            writel_relaxed_13(130, v60 + 368);
            writel_relaxed_13(76, v60 + 376);
            writel_relaxed_13(128, v60 + 400);
            writel_relaxed_13(41, v60 + 144);
            writel_relaxed_13(47, v60 + 144);
            writel_relaxed_13(42, v60 + 148);
            writel_relaxed_13(63, v60 + 148);
            writel_relaxed_13(34, v60 + 608);
            v63 = *(_QWORD **)(v2 + 120);
            if ( v63 )
              writel_relaxed_13(34, *v63 + 608LL);
            v64 = *(_QWORD **)(v2 + 128);
            if ( v64 )
              writel_relaxed_13(34, *v64 + 608LL);
            v65 = *(_QWORD **)(v2 + 136);
            if ( v65 )
              writel_relaxed_13(34, *v65 + 608LL);
            if ( *(_BYTE *)(v15 + 22) == 1 )
            {
              v66 = *(_QWORD *)v2;
              if ( v2 )
                v67 = *(_DWORD *)(v2 + 100);
              else
                v67 = -1;
              _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_PLL_%d: SSC is enabled\n", v67);
              writel_relaxed_13(*(unsigned int *)(v15 + 84), v66 + 288);
              writel_relaxed_13(*(unsigned int *)(v15 + 88), v66 + 292);
              writel_relaxed_13(*(unsigned int *)(v15 + 92), v66 + 296);
              writel_relaxed_13(*(unsigned int *)(v15 + 96), v66 + 300);
              writel_relaxed_13(*(unsigned int *)(v15 + 100), v66 + 304);
              writel_relaxed_13(*(unsigned int *)(v15 + 104), v66 + 308);
              writel_relaxed_13(*(_DWORD *)(v15 + 108) | 2u, v66 + 336);
            }
            __dsb(0xEu);
            return 0;
          }
          if ( v59 < 0xB237C780 )
          {
            v62 = 0;
            goto LABEL_64;
          }
        }
        v62 = 1;
        goto LABEL_64;
      }
      if ( !v2 )
      {
        v24 = -1;
        goto LABEL_42;
      }
LABEL_32:
      v24 = *(_DWORD *)(v2 + 100);
LABEL_42:
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_PLL_%d: pll configuration not found\n", v24);
      return 0;
    }
    dsi_pll_5nm_set_byteclk_div(v2, 0);
    a1 = dsi_pll_5nm_set_pclk_div(v2, 0);
    if ( v2 )
    {
      v17 = *(_QWORD *)(v2 + 144);
      if ( !v17 )
        goto LABEL_32;
      v18 = *(_DWORD **)(v2 + 152);
      v19 = *(_QWORD *)(v2 + 56);
      if ( v18 && *v18 )
      {
        v20 = 0;
        v21 = 0;
        v22 = (unsigned int)*(_QWORD *)(v2 + 56);
        while ( 1 )
        {
          if ( v21 == 17 )
          {
            __break(0x5512u);
            goto LABEL_103;
          }
          v23 = &v18[v20];
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dsi-debug]: DSI_PLL_%d: valid=%d vco_rate=%d, code %d %d %d\n",
            *(_DWORD *)(v2 + 100),
            v18[v20 + 1],
            v18[v20 + 2],
            v18[v20 + 3],
            v18[v20 + 4],
            v18[v20 + 5]);
          if ( v23[2] == (_DWORD)v19 || !v23[1] )
            break;
          v18 = *(_DWORD **)(v2 + 152);
          ++v21;
          v20 += 5;
          if ( v21 >= (unsigned int)*v18 )
            goto LABEL_30;
        }
        v32 = v23[3];
        v33 = *(_DWORD *)(v2 + 100);
        *(_DWORD *)(v2 + 88) = v32;
        v34 = v23[4];
        *(_DWORD *)(v2 + 92) = v34;
        v35 = v23[5];
        *(_DWORD *)(v2 + 96) = v35;
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dsi-debug]: DSI_PLL_%d: trim_code_0=0x%x trim_code_1=0x%x trim_code_2=0x%x\n",
          v33,
          v32,
          v34,
          v35);
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dsi-debug]: DSI_PLL_%d: ndx=%d, rate=%u\n",
          *(_DWORD *)(v2 + 100),
          *(_DWORD *)(v2 + 100),
          v19);
        *(_QWORD *)(v2 + 32) = v22;
        v36 = *(_QWORD *)(v2 + 40);
        v37 = *(_BYTE *)(v17 + 21);
        v38 = *(_DWORD *)(v17 + 28);
        if ( v22 >= 0x3B9ACA01 )
        {
          if ( v22 >= 0x9502F901 )
          {
            if ( v22 < 0xD09DC301 )
            {
              *(_DWORD *)(v17 + 80) = 0;
LABEL_86:
              v69 = (unsigned int)(v36 << (v37 ^ 1u));
              v70 = (1LL << v38) - 1;
              v71 = v22 * (int)(1LL << v38) / v69;
              v72 = v71 >> v38;
              LODWORD(v71) = v71 & v70;
              *(_DWORD *)(v17 + 64) = v72;
              *(_DWORD *)(v17 + 68) = (unsigned __int8)v71;
              LODWORD(v72) = *(_DWORD *)(v17 + 32);
              *(_DWORD *)(v17 + 72) = BYTE1(v71);
              *(_DWORD *)(v17 + 76) = WORD1(v71) & 3;
              *(_DWORD *)(v17 + 56) = 10;
              *(_DWORD *)(v17 + 60) = v72;
              v73 = readl_relaxed_16(*(_QWORD *)(v2 + 8) + 20LL);
              writel_relaxed_13((v73 << 8) & 0xFFF0DFFA | 0xF0005, *(_QWORD *)(v2 + 24) + 20LL);
              writel_relaxed_13(309264391, *(_QWORD *)(v2 + 24) + 24LL);
              writel_relaxed_13(
                (*(_DWORD *)(v17 + 68) << 24) | (*(_DWORD *)(v17 + 64) << 8) | 0x790078u,
                *(_QWORD *)(v2 + 24) + 28LL);
              writel_relaxed_13(
                (*(_DWORD *)(v17 + 76) << 24) | (*(_DWORD *)(v17 + 72) << 8) | 0x7B007Au,
                *(_QWORD *)(v2 + 24) + 32LL);
              writel_relaxed_13(278315082, *(_QWORD *)(v2 + 24) + 36LL);
              v74 = readl_relaxed_16(*(_QWORD *)v2 + 340LL);
              writel_relaxed_13(((v74 & 3) << 8) | 0x6A50095u, *(_QWORD *)(v2 + 24) + 40LL);
              if ( *(_BYTE *)(v17 + 112) )
                v75 = 0;
              else
                v75 = 4096;
              writel_relaxed_13(v75 | (*(_DWORD *)(v17 + 80) << 24) | 0xD200D4u, *(_QWORD *)(v2 + 24) + 44LL);
              v76 = readl_relaxed_16(*(_QWORD *)v2 + 576LL);
              writel_relaxed_13((v76 << 24) | 0xD001D6u, *(_QWORD *)(v2 + 24) + 48LL);
              writel_relaxed_13(54591814, *(_QWORD *)(v2 + 24) + 52LL);
              writel_relaxed_13((*(_DWORD *)(v2 + 96) << 8) | 0x480044u, *(_QWORD *)(v2 + 24) + 56LL);
              writel_relaxed_13(1079070281, *(_QWORD *)(v2 + 24) + 60LL);
              writel_relaxed_13(207534682, *(_QWORD *)(v2 + 24) + 64LL);
              writel_relaxed_13(7209066, *(_QWORD *)(v2 + 24) + 68LL);
              writel_relaxed_13((*(_DWORD *)(v17 + 56) << 24) | 0x980872u, *(_QWORD *)(v2 + 24) + 72LL);
              writel_relaxed_13(2191311002LL, *(_QWORD *)(v2 + 24) + 76LL);
              writel_relaxed_13(2158251166LL, *(_QWORD *)(v2 + 24) + 80LL);
              writel_relaxed_13(1063594340, *(_QWORD *)(v2 + 24) + 84LL);
              writel_relaxed_13(1146216522, *(_QWORD *)(v2 + 24) + 88LL);
              v77 = readl_relaxed_16(*(_QWORD *)(v2 + 8) + 16LL);
              writel_relaxed_13((v77 << 24) | 0x4400Bu, *(_QWORD *)(v2 + 24) + 92LL);
              v78 = *(_QWORD *)(v2 + 120);
              v79 = (v77 << 8) | 0x7F090004;
              if ( v78 )
                writel_relaxed_13(v79, *(_QWORD *)(v78 + 24) + 60LL);
              v80 = *(_QWORD *)(v2 + 128);
              if ( v80 )
                writel_relaxed_13(v79, *(_QWORD *)(v80 + 24) + 60LL);
              v81 = *(_QWORD *)(v2 + 136);
              if ( v81 )
                writel_relaxed_13(v79, *(_QWORD *)(v81 + 24) + 60LL);
              writel_relaxed_13(17760527, *(_QWORD *)(v2 + 24) + 128LL);
              writel_relaxed_13(17760527, *(_QWORD *)(v2 + 24) + 132LL);
              writel_relaxed_13(17760527, *(_QWORD *)(v2 + 24) + 136LL);
              v82 = readl_relaxed_16(*(_QWORD *)(v2 + 8) + 20LL) | 0x20;
              writel_relaxed_13((v82 << 8) | 0x1070005u, *(_QWORD *)(v2 + 24) + 140LL);
              writel_relaxed_13((v82 << 8) | (v82 << 24) | 0x50005u, *(_QWORD *)(v2 + 24) + 144LL);
              v83 = *(_QWORD *)(v2 + 120);
              if ( v83 )
              {
                v84 = readl_relaxed_16(*(_QWORD *)(v83 + 8) + 20LL) | 0x20;
                writel_relaxed_13((v84 << 8) | 0x1070005u, *(_QWORD *)(*(_QWORD *)(v2 + 120) + 24LL) + 140LL);
                writel_relaxed_13(
                  (v84 << 8) | (v84 << 24) | 0x50005u,
                  *(_QWORD *)(*(_QWORD *)(v2 + 120) + 24LL) + 144LL);
              }
              v85 = *(_QWORD *)(v2 + 128);
              if ( v85 )
              {
                v86 = readl_relaxed_16(*(_QWORD *)(v85 + 8) + 20LL) | 0x20;
                writel_relaxed_13((v86 << 8) | 0x1070005u, *(_QWORD *)(*(_QWORD *)(v2 + 128) + 24LL) + 140LL);
                writel_relaxed_13(
                  (v86 << 8) | (v86 << 24) | 0x50005u,
                  *(_QWORD *)(*(_QWORD *)(v2 + 128) + 24LL) + 144LL);
              }
              v87 = *(_QWORD *)(v2 + 136);
              if ( v87 )
              {
                v88 = readl_relaxed_16(*(_QWORD *)(v87 + 8) + 20LL) | 0x20;
                writel_relaxed_13((v88 << 8) | 0x1070005u, *(_QWORD *)(*(_QWORD *)(v2 + 136) + 24LL) + 140LL);
                writel_relaxed_13(
                  (v88 << 8) | (v88 << 24) | 0x50005u,
                  *(_QWORD *)(*(_QWORD *)(v2 + 136) + 24LL) + 144LL);
              }
              writel_relaxed_13(4294967288LL, *(_QWORD *)(v2 + 24) + 148LL);
              writel_relaxed_13(15, *(_QWORD *)(v2 + 24) + 152LL);
              __dsb(0xEu);
              return 0;
            }
            v39 = 64;
          }
          else
          {
            v39 = 32;
          }
        }
        else
        {
          v39 = 160;
        }
        *(_DWORD *)(v17 + 80) = v39;
        goto LABEL_86;
      }
LABEL_30:
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: DSI_PLL_%d: cannot find pll codes rate=%u\n",
        *(_DWORD *)(v2 + 100),
        v19);
    }
    else
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_PLL_%d: pll resource not found\n", -1);
    }
    return 0;
  }
LABEL_103:
  __break(1u);
  return dsi_pll_5nm_set_byteclk_div(a1, v4);
}
