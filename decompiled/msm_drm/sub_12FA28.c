// positive sp value has been detected, the output may be wrong!
__int64 __usercall sub_12FA28@<X0>(__int64 a1@<X0>, int a2@<W8>)
{
  __int64 v2; // x16
  __int64 *v3; // x19
  char v4; // w20
  unsigned __int64 v5; // x21
  unsigned __int64 v6; // x24
  unsigned int v8; // w22
  unsigned __int64 v9; // x8
  int v10; // w21
  unsigned __int64 v11; // x24
  char v12; // w0
  int v13; // w8
  unsigned __int64 v14; // t2
  unsigned int v15; // w8
  int v16; // w25
  int v17; // w22
  int v18; // w8
  int v19; // w22
  unsigned int v20; // w25
  int v21; // w26
  int v22; // w8
  int v23; // w10
  unsigned int v24; // w9
  __int64 v25; // x4
  unsigned int v26; // w11
  unsigned int v27; // w23
  char v28; // w0
  __int64 v29; // x4
  unsigned __int64 v30; // x5
  __int64 v31; // x23
  int v32; // w4
  __int64 v33; // x0
  char v34; // w0
  char v35; // w11
  int v36; // w7
  __int64 v37; // x9
  unsigned __int64 v38; // x10
  int v39; // w8
  __int64 v40; // x22
  _DWORD *v41; // x8
  __int64 v42; // x20
  __int64 v43; // x24
  unsigned __int64 v44; // x25
  unsigned __int64 v45; // x23
  _DWORD *v46; // x26
  int v47; // w5
  int v48; // w4
  int v49; // w6
  int v50; // w7
  __int64 v51; // x8
  char v52; // w10
  int v53; // w9
  int v54; // w11
  __int64 v55; // x8
  unsigned __int64 v56; // x9
  unsigned __int64 v57; // x5
  __int64 v58; // x9
  int v59; // w10
  char v60; // w11
  __int64 v61; // x6
  int v62; // w9
  __int64 v63; // x11
  unsigned int v64; // w10
  unsigned __int64 v65; // x8
  unsigned __int64 v66; // x11
  unsigned __int64 v67; // x8
  int v68; // w20
  unsigned __int64 v69; // x21
  int v70; // w22
  int v71; // w4
  __int64 v72; // x20
  __int64 v73; // x0
  unsigned __int64 v74; // x21
  __int64 v75; // x20
  __int64 v76; // x1
  __int64 v77; // x0
  _QWORD *v78; // x8
  _QWORD *v79; // x8
  _QWORD *v80; // x8
  __int64 v81; // x20
  int v82; // w4
  unsigned __int64 v83; // x8
  int v84; // w10
  unsigned __int64 v85; // x8
  unsigned __int64 v86; // x9
  int v87; // w0
  char v88; // w0
  int v89; // w8
  int v90; // w0
  int v91; // w20
  __int64 v92; // x8
  unsigned int v93; // w20
  __int64 v94; // x8
  __int64 v95; // x8
  int v96; // w22
  __int64 v97; // x8
  int v98; // w22
  __int64 v99; // x8
  int v100; // w22
  __int64 v101; // x8
  int v102; // w22

  if ( !v2 )
    return sde_connector_atomic_check();
  v8 = a2 & 0xFFFFFFFD;
  ((void (__fastcall *)(__int64, bool))dsi_pll_set_dsiclk_sel_0)(a1, (a2 & 0xFFFFFFFD) != 0);
  if ( v8 )
  {
    v9 = v6 / v5;
    v10 = 1;
    v11 = v9 >> 1;
  }
  else
  {
    v11 = v6 / v5;
    v10 = 0;
  }
  if ( !*((_DWORD *)v3 + 44) )
  {
    v18 = *((_DWORD *)v3 + 41);
    if ( v18 == 16 )
    {
      if ( *((_DWORD *)v3 + 42) == 3 )
      {
        v19 = 3;
        v20 = 8;
        goto LABEL_51;
      }
    }
    else if ( v18 == 18 )
    {
      v19 = *((_DWORD *)v3 + 42);
      if ( v19 == 2 || v19 == 4 )
      {
        v20 = 9;
        goto LABEL_51;
      }
    }
    else if ( v18 == 30 && *((_DWORD *)v3 + 42) == 4 )
    {
      v19 = 2;
      v20 = 3;
LABEL_51:
      v28 = ((__int64 (__fastcall *)(__int64))readl_relaxed_17)(v3[1] + 20);
      if ( v3 )
        v29 = *((unsigned int *)v3 + 25);
      else
        v29 = 0xFFFFFFFFLL;
      v27 = (((unsigned __int8)(*((_DWORD *)v3 + 41) % v20 * v19) / v20 + *((_DWORD *)v3 + 41) / v20 * v19) >> ((v28 & 3) == 1))
          / *((_DWORD *)v3 + 42);
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dsi-debug]: DSI_PLL_%d: bpp:%d lanes:%d m_val:%u n_val:%u dsiclk_sel:%u pclk_div: %u\n",
        v29);
      goto LABEL_55;
    }
    v20 = 1;
    v19 = 1;
    goto LABEL_51;
  }
  v12 = ((__int64 (__fastcall *)(__int64))readl_relaxed_17)(v3[1] + 16);
  HIDWORD(v14) = *((_DWORD *)v3 + 41) - 16;
  LODWORD(v14) = HIDWORD(v14);
  v13 = v14 >> 1;
  if ( v13 <= 3 )
  {
    if ( v13 )
    {
      if ( v13 == 1 )
      {
        v15 = *((_DWORD *)v3 + 42) - 1;
        if ( v15 < 3 )
        {
          v16 = dword_28FD58[v15];
          v17 = dword_28FD64[v15];
          goto LABEL_30;
        }
      }
    }
    else if ( *((_DWORD *)v3 + 42) == 3 )
    {
      v17 = 3;
      v16 = 7;
      goto LABEL_30;
    }
    goto LABEL_23;
  }
  if ( v13 != 7 )
  {
    if ( v13 == 4 && *((_DWORD *)v3 + 42) == 2 )
    {
      v17 = 2;
      v16 = 3;
      goto LABEL_30;
    }
LABEL_23:
    v16 = 1;
    v17 = 1;
    goto LABEL_30;
  }
  if ( *((_DWORD *)v3 + 42) == 1 )
    v16 = 15;
  else
    v16 = 35;
  if ( *((_DWORD *)v3 + 42) == 1 )
    v17 = 4;
  else
    v17 = 16;
LABEL_30:
  v21 = v12 & 0xF;
  v22 = ((__int64 (__fastcall *)(__int64))readl_relaxed_17)(v3[1] + 20) & 3;
  v23 = *((_DWORD *)v3 + 41) * v17;
  v24 = *((_DWORD *)v3 + 42) * v16;
  if ( v22 )
  {
    if ( v22 != 2 )
    {
      if ( v22 == 3 )
      {
        v23 *= v21;
        v24 *= 8;
      }
      if ( v3 )
        goto LABEL_35;
LABEL_38:
      v25 = 0xFFFFFFFFLL;
      goto LABEL_39;
    }
    v23 *= v21;
  }
  v24 *= 16;
  v23 *= 7;
  if ( !v3 )
    goto LABEL_38;
LABEL_35:
  v25 = *((unsigned int *)v3 + 25);
LABEL_39:
  if ( v24 == 1 )
    v26 = 0;
  else
    v26 = v23;
  if ( v24 != 1 )
    v23 = 0;
  v27 = v26 / v24 + v23;
  _drm_dev_dbg(
    0,
    0,
    0,
    "[msm-dsi-debug]: DSI_PLL_%d: bpp:%d lanes:%d m_val:%u n_val:%u phy_post_div:%u dsiclk_sel:%u pclk_div:%u\n",
    v25);
LABEL_55:
  v30 = v11 / v27;
  v3[9] = v30;
  if ( v3 )
  {
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dsi-debug]: DSI_PLL_%d: pclk rate: %llu, dsiclk_sel: %d, pclk_div: %d\n",
      *((_DWORD *)v3 + 25),
      v30,
      v10,
      v27);
    if ( (v4 & 1) != 0 )
    {
      ((void (__fastcall *)(__int64 *, _QWORD))dsi_pll_set_pclk_div_0)(v3, v27);
      v31 = v3[18];
      v32 = *((_DWORD *)v3 + 25);
      if ( v31 )
        goto LABEL_58;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_PLL_%d: pll configuration not found\n", v32);
      return 0;
    }
    v40 = v3[18];
    if ( !v40 )
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: DSI_PLL_%d: pll configuration not found\n",
        *((_DWORD *)v3 + 25));
      return 0;
    }
    v41 = (_DWORD *)v3[19];
    v42 = v3[7];
    if ( !v41 || !*v41 )
    {
LABEL_71:
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: DSI_PLL_%d: cannot find pll codes rate=%u\n",
        *((_DWORD *)v3 + 25),
        v42);
      return 0;
    }
    v43 = 0;
    v44 = 0;
    v45 = (unsigned int)v3[7];
    while ( 1 )
    {
      if ( v44 == 17 )
      {
        __break(0x5512u);
        JUMPOUT(0x1C97D4);
      }
      v46 = &v41[v43];
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dsi-debug]: DSI_PLL_%d: valid=%d vco_rate=%d, code %d %d %d\n",
        *((_DWORD *)v3 + 25),
        v41[v43 + 1],
        v41[v43 + 2],
        v41[v43 + 3],
        v41[v43 + 4],
        v41[v43 + 5]);
      if ( v46[2] == (_DWORD)v42 || !v46[1] )
        break;
      v41 = (_DWORD *)v3[19];
      ++v44;
      v43 += 5;
      if ( v44 >= (unsigned int)*v41 )
        goto LABEL_71;
    }
    v47 = v46[3];
    v48 = *((_DWORD *)v3 + 25);
    *((_DWORD *)v3 + 22) = v47;
    v49 = v46[4];
    *((_DWORD *)v3 + 23) = v49;
    v50 = v46[5];
    *((_DWORD *)v3 + 24) = v50;
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dsi-debug]: DSI_PLL_%d: trim_code_0=0x%x trim_code_1=0x%x trim_code_2=0x%x\n",
      v48,
      v47,
      v49,
      v50);
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dsi-debug]: DSI_PLL_%d: ndx=%d, rate=%u\n",
      *((_DWORD *)v3 + 25),
      *((_DWORD *)v3 + 25),
      v42);
    v3[4] = v45;
    v51 = v3[5];
    v52 = *(_BYTE *)(v40 + 21);
    v53 = *(_DWORD *)(v40 + 28);
    if ( v45 >= 0x4D7C6D01 )
    {
      if ( v45 >= 0x9502F901 )
      {
        if ( v45 < 0xEE6B2801 )
        {
          *(_DWORD *)(v40 + 80) = 0;
LABEL_118:
          v83 = (unsigned int)(v51 << (v52 ^ 1u));
          v84 = (1LL << v53) - 1;
          v85 = v45 * (int)(1LL << v53) / v83;
          v86 = v85 >> v53;
          LODWORD(v85) = v85 & v84;
          *(_DWORD *)(v40 + 64) = v86;
          *(_DWORD *)(v40 + 68) = (unsigned __int8)v85;
          LODWORD(v86) = *(_DWORD *)(v40 + 32);
          *(_DWORD *)(v40 + 72) = BYTE1(v85);
          *(_DWORD *)(v40 + 76) = WORD1(v85) & 3;
          *(_DWORD *)(v40 + 56) = 10;
          *(_DWORD *)(v40 + 60) = v86;
          v87 = ((__int64 (__fastcall *)(__int64))readl_relaxed_17)(v3[1] + 20);
          ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)((v87 << 8) & 0xFFF0DFFA | 0xF0005, v3[3] + 20);
          ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(309264391, v3[3] + 24);
          ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(
            (*(_DWORD *)(v40 + 68) << 24) | (*(_DWORD *)(v40 + 64) << 8) | 0x790078u,
            v3[3] + 28);
          ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(
            (*(_DWORD *)(v40 + 76) << 24) | (*(_DWORD *)(v40 + 72) << 8) | 0x7B007Au,
            v3[3] + 32);
          ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(278315082, v3[3] + 36);
          v88 = ((__int64 (__fastcall *)(__int64))readl_relaxed_17)(*v3 + 340);
          ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(((v88 & 3) << 8) | 0x6A50095u, v3[3] + 40);
          if ( *(_BYTE *)(v40 + 112) )
            v89 = 0;
          else
            v89 = 4096;
          ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(
            v89 | (*(_DWORD *)(v40 + 80) << 24) | 0xD200D4u,
            v3[3] + 44);
          v90 = ((__int64 (__fastcall *)(__int64))readl_relaxed_17)(*v3 + 576);
          ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)((v90 << 24) | 0xD001D6u, v3[3] + 48);
          ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(54591814, v3[3] + 52);
          ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)((*((_DWORD *)v3 + 24) << 8) | 0x480044u, v3[3] + 56);
          ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(1079070281, v3[3] + 60);
          ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(207534682, v3[3] + 64);
          ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(7209066, v3[3] + 68);
          ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(
            (*(_DWORD *)(v40 + 56) << 24) | 0x980872u,
            v3[3] + 72);
          ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(2191311002LL, v3[3] + 76);
          ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(2158251166LL, v3[3] + 80);
          ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(1063594340, v3[3] + 84);
          ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(1146216522, v3[3] + 88);
          v91 = ((__int64 (__fastcall *)(__int64))readl_relaxed_17)(v3[1] + 16);
          ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)((v91 << 24) | 0x4400Bu, v3[3] + 92);
          v92 = v3[15];
          v93 = (v91 << 8) | 0x7F090004;
          if ( v92 )
            ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(v93, *(_QWORD *)(v92 + 24) + 60LL);
          v94 = v3[16];
          if ( v94 )
            ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(v93, *(_QWORD *)(v94 + 24) + 60LL);
          v95 = v3[17];
          if ( v95 )
            ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(v93, *(_QWORD *)(v95 + 24) + 60LL);
          ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(17760527, v3[3] + 128);
          ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(17760527, v3[3] + 132);
          ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(17760527, v3[3] + 136);
          v96 = ((__int64 (__fastcall *)(__int64))readl_relaxed_17)(v3[1] + 20) | 0x20;
          ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)((v96 << 8) | 0x1070005u, v3[3] + 140);
          ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)((v96 << 8) | (v96 << 24) | 0x50005u, v3[3] + 144);
          v97 = v3[15];
          if ( v97 )
          {
            v98 = ((__int64 (__fastcall *)(__int64))readl_relaxed_17)(*(_QWORD *)(v97 + 8) + 20LL) | 0x20;
            ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(
              (v98 << 8) | 0x1070005u,
              *(_QWORD *)(v3[15] + 24) + 140LL);
            ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(
              (v98 << 8) | (v98 << 24) | 0x50005u,
              *(_QWORD *)(v3[15] + 24) + 144LL);
          }
          v99 = v3[16];
          if ( v99 )
          {
            v100 = ((__int64 (__fastcall *)(__int64))readl_relaxed_17)(*(_QWORD *)(v99 + 8) + 20LL) | 0x20;
            ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(
              (v100 << 8) | 0x1070005u,
              *(_QWORD *)(v3[16] + 24) + 140LL);
            ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(
              (v100 << 8) | (v100 << 24) | 0x50005u,
              *(_QWORD *)(v3[16] + 24) + 144LL);
          }
          v101 = v3[17];
          if ( v101 )
          {
            v102 = ((__int64 (__fastcall *)(__int64))readl_relaxed_17)(*(_QWORD *)(v101 + 8) + 20LL) | 0x20;
            ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(
              (v102 << 8) | 0x1070005u,
              *(_QWORD *)(v3[17] + 24) + 140LL);
            ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(
              (v102 << 8) | (v102 << 24) | 0x50005u,
              *(_QWORD *)(v3[17] + 24) + 144LL);
          }
          ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(4294967288LL, v3[3] + 148);
          ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(15, v3[3] + 152);
          __dsb(0xEu);
          return 0;
        }
        v54 = 64;
      }
      else
      {
        v54 = 32;
      }
    }
    else
    {
      v54 = 160;
    }
    *(_DWORD *)(v40 + 80) = v54;
    goto LABEL_118;
  }
  _drm_dev_dbg(
    0,
    0,
    0,
    "[msm-dsi-debug]: DSI_PLL_%d: pclk rate: %llu, dsiclk_sel: %d, pclk_div: %d\n",
    -1,
    v30,
    v10,
    v27);
  if ( (v4 & 1) != 0 )
  {
    ((void (__fastcall *)(_QWORD, _QWORD))dsi_pll_set_pclk_div_0)(0, v27);
    v32 = -1;
    v31 = 0x29EC7400146298LL;
LABEL_58:
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_PLL_%d: rate=%llu\n", v32, v3[7]);
    v33 = v3[1] + 24;
    v3[4] = v3[7];
    v34 = ((__int64 (__fastcall *)(__int64))readl_relaxed_17)(v33);
    v35 = *(_BYTE *)(v31 + 21);
    v36 = *(_DWORD *)(v31 + 28);
    *(_BYTE *)(v31 + 112) = (v34 & 0x40) != 0;
    v38 = v3[4];
    v37 = v3[5];
    if ( v38 >= 0x4D7C6D01 )
    {
      if ( v38 >= 0x9502F901 )
      {
        if ( v38 < 0xEE6B2801 )
        {
          *(_DWORD *)(v31 + 80) = 0;
          goto LABEL_82;
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
    *(_DWORD *)(v31 + 80) = v39;
LABEL_82:
    v55 = (int)(1LL << v36);
    v56 = v38 * v55 / (unsigned int)(v37 << (v35 ^ 1u));
    v57 = v56 >> v36;
    v58 = v56 & ((1LL << v36) + 0xFFFFFFFFLL);
    *(_DWORD *)(v31 + 64) = v57;
    *(_DWORD *)(v31 + 68) = (unsigned __int8)v58;
    v59 = *(_DWORD *)(v31 + 32);
    *(_DWORD *)(v31 + 72) = BYTE1(v58);
    *(_DWORD *)(v31 + 76) = WORD1(v58) & 3;
    v60 = *(_BYTE *)(v31 + 22);
    *(_DWORD *)(v31 + 56) = 10;
    *(_DWORD *)(v31 + 60) = v59;
    if ( (v60 & 1) != 0 )
    {
      v61 = v58 & 0x3FFFF;
      v62 = *(_DWORD *)(v31 + 44);
      v63 = (unsigned int)(v62 + 1);
      v64 = ((unsigned int)(*(_DWORD *)(v31 + 8) + (*(_DWORD *)(v31 + 36) >> 1)) / *(_DWORD *)(v31 + 36)) >> 1;
      v65 = (v61 + (unsigned int)v57 * v55) * v63 * *(unsigned int *)(v31 + 40);
      v66 = v64 / (unsigned int)v63 * (unsigned int)v63;
      v67 = v65 / v66;
      LODWORD(v66) = ~(v64 - v66);
      v68 = v64 + v66;
      *(_DWORD *)(v31 + 100) = (unsigned __int8)v62;
      *(_DWORD *)(v31 + 104) = BYTE1(v62);
      *(_DWORD *)(v31 + 92) = (unsigned __int8)(v64 + v66);
      *(_DWORD *)(v31 + 96) = (unsigned __int8)((unsigned __int16)(v64 + v66) >> 8);
      v69 = (v67 + 500000) / 0xF4240;
      *(_DWORD *)(v31 + 108) = *(unsigned __int8 *)(v31 + 23);
      *(_DWORD *)(v31 + 84) = (unsigned __int8)v69;
      *(_DWORD *)(v31 + 88) = BYTE1(v69);
      if ( v3 )
      {
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dsi-debug]: DSI_PLL_%d: SCC: Dec:%d, frac:%llu, frac_bits:%d\n",
          *((_DWORD *)v3 + 25),
          v57,
          v61,
          v36);
        v70 = *((_DWORD *)v3 + 25);
      }
      else
      {
        v70 = -1;
        _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_PLL_%d: SCC: Dec:%d, frac:%llu, frac_bits:%d\n", -1, v57, v61, v36);
      }
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dsi-debug]: DSI_PLL_%d: SSC: div_per:0x%X, stepsize:0x%X, adjper:0x%X\n",
        v70,
        v68,
        v69,
        *(_DWORD *)(v31 + 44));
    }
    else
    {
      if ( v3 )
        v71 = *((_DWORD *)v3 + 25);
      else
        v71 = -1;
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_PLL_%d: SSC not enabled\n", v71);
    }
    v72 = *v3;
    ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(18, *v3 + 188);
    ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(*(unsigned int *)(v31 + 64), v72 + 224);
    ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(*(unsigned int *)(v31 + 68), v72 + 228);
    ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(*(unsigned int *)(v31 + 72), v72 + 232);
    ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(*(unsigned int *)(v31 + 76), v72 + 236);
    ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(*(unsigned int *)(v31 + 60), v72 + 344);
    ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(6, v72 + 404);
    if ( *(_BYTE *)(v31 + 112) )
      v73 = 0;
    else
      v73 = 16;
    ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(v73, v72 + 592);
    ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(*(unsigned int *)(v31 + 80), v72 + 584);
    v74 = v3[4];
    v75 = *v3;
    v76 = *v3 + 600;
    if ( v74 >= 0xB8C63F00 )
    {
      ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(3, v76);
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(1, v76);
      if ( v74 < 0x5CCDEF40 )
      {
        v77 = 8;
LABEL_99:
        ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(v77, v75 + 576);
        ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(1, v75 + 24);
        ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(3, v75 + 4);
        ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(0, v75 + 16);
        ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(0, v75 + 32);
        ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(78, v75 + 36);
        ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(64, v75 + 68);
        ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(186, v75 + 104);
        ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(12, v75 + 120);
        ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(0, v75 + 168);
        ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(0, v75 + 184);
        ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(8, v75 + 200);
        ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(10, v75 + 352);
        ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(192, v75 + 360);
        ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(132, v75 + 368);
        ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(130, v75 + 368);
        ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(76, v75 + 376);
        ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(128, v75 + 400);
        ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(41, v75 + 144);
        ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(47, v75 + 144);
        ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(42, v75 + 148);
        ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(63, v75 + 148);
        ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(34, v75 + 608);
        v78 = (_QWORD *)v3[15];
        if ( v78 )
          ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(34, *v78 + 608LL);
        v79 = (_QWORD *)v3[16];
        if ( v79 )
          ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(34, *v79 + 608LL);
        v80 = (_QWORD *)v3[17];
        if ( v80 )
          ((void (__fastcall *)(__int64, __int64))writel_relaxed_14)(34, *v80 + 608LL);
        if ( *(_BYTE *)(v31 + 22) == 1 )
        {
          v81 = *v3;
          if ( v3 )
            v82 = *((_DWORD *)v3 + 25);
          else
            v82 = -1;
          _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_PLL_%d: SSC is enabled\n", v82);
          ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(*(unsigned int *)(v31 + 84), v81 + 288);
          ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(*(unsigned int *)(v31 + 88), v81 + 292);
          ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(*(unsigned int *)(v31 + 92), v81 + 296);
          ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(*(unsigned int *)(v31 + 96), v81 + 300);
          ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(*(unsigned int *)(v31 + 100), v81 + 304);
          ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(*(unsigned int *)(v31 + 104), v81 + 308);
          ((void (__fastcall *)(_QWORD, __int64))writel_relaxed_14)(*(_DWORD *)(v31 + 108) | 2u, v81 + 336);
        }
        __dsb(0xEu);
        return 0;
      }
    }
    v77 = 1;
    goto LABEL_99;
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_PLL_%d: pll resource not found\n", -1);
  return 0;
}
