__int64 __fastcall hal_srng_dst_hw_init_peach(
        __int64 a1,
        unsigned __int8 *a2,
        char a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v16; // w2
  __int64 v17; // x0
  __int64 v18; // x1
  __int64 v19; // x0
  __int64 v20; // x10
  __int64 v21; // x11
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // w0
  __int64 v31; // x0
  __int64 v32; // x8
  __int64 v33; // x1
  __int64 v34; // x0
  __int64 v35; // x2
  __int64 v36; // x1
  __int64 v37; // x0
  int v38; // w8
  __int64 v39; // x1
  __int64 v40; // x0
  __int64 v41; // x2
  __int64 v42; // x1
  __int64 v43; // x0
  __int64 v44; // x2
  __int64 v45; // x1
  __int64 v46; // x0
  __int64 v47; // x2
  __int64 v48; // x1
  __int64 v49; // x0
  __int64 v50; // x2
  __int64 v51; // x1
  int v52; // w8
  __int64 v53; // x2
  __int64 v54; // x0
  __int64 v55; // x21
  __int64 v56; // x1
  __int64 v57; // x0
  unsigned __int64 v58; // x21
  __int64 v59; // x1
  __int64 v60; // x0
  __int64 v61; // x1
  __int64 v62; // x0
  __int64 v63; // x2
  __int64 v64; // x1
  __int64 v65; // x0
  __int64 v66; // x2
  __int64 v67; // x1
  __int64 v68; // x0
  __int64 v69; // x10
  __int64 v70; // x1

  v16 = a2[306] & 0x3F | (*((unsigned __int16 *)a2 + 152) << 16);
  if ( v16 )
  {
    v17 = *((_QWORD *)a2 + 20);
    v18 = *((_QWORD *)a2 + 12) + *(int *)(v17 + 74300);
    if ( (*(_BYTE *)(v17 + 74224) & 1) != 0 )
      ((void (*)(void))hal_write32_mb_1)();
    else
      writel_7(v16, v18);
  }
  qdf_trace_msg(
    0x46u,
    8u,
    "%s: hw_init srng %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "hal_srng_dst_hw_init_generic",
    *a2);
  v19 = *((_QWORD *)a2 + 20);
  v20 = *((_QWORD *)a2 + 12);
  v21 = *(int *)(v19 + 74276);
  if ( (a3 & 1) != 0 )
  {
    if ( (*(_BYTE *)(v19 + 74224) & 1) != 0 )
    {
      if ( (hal_read32_mb_1() & 0x80) == 0 )
      {
LABEL_12:
        qdf_trace_msg(
          0x46u,
          2u,
          "%s: ring_id %d not in idle state",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "hal_srng_dst_hw_init_generic",
          *a2);
        v31 = printk(
                &unk_9BB309,
                "0",
                "hal_srng_dst_hw_init_generic",
                "/proc/self/cwd/vendor/qcom/opensource/wlan/qcacld-3.0/cmn/hal/wifi3.0/hal_generic_api.h");
        dump_stack(v31);
        if ( (a2[78] & 2) == 0 )
          goto LABEL_29;
        goto LABEL_18;
      }
    }
    else if ( (readl_8(v20 + v21) & 0x80) == 0 )
    {
      goto LABEL_12;
    }
  }
  else
  {
    if ( (*(_BYTE *)(v19 + 74224) & 1) != 0 )
      v30 = hal_read32_mb_1();
    else
      v30 = readl_8(v20 + v21);
    v32 = *((_QWORD *)a2 + 20);
    v33 = *((_QWORD *)a2 + 12) + *(int *)(v32 + 74276);
    if ( (*(_BYTE *)(v32 + 74224) & 1) == 0 )
    {
      writel_7(v30 & 0xFFFFFFBF, v33);
      if ( (a2[78] & 2) == 0 )
        goto LABEL_29;
      goto LABEL_18;
    }
    hal_write32_mb_1(*((_QWORD *)a2 + 20), (unsigned int)(v33 - *(_DWORD *)(v32 + 16)), v30 & 0xFFFFFFBF);
  }
  if ( (a2[78] & 2) == 0 )
    goto LABEL_29;
LABEL_18:
  v34 = *((_QWORD *)a2 + 20);
  v35 = *((unsigned int *)a2 + 16);
  v36 = *((_QWORD *)a2 + 12) + *(int *)(v34 + 74288);
  if ( (*(_BYTE *)(v34 + 74224) & 1) != 0 )
    hal_write32_mb_1(v34, (unsigned int)(v36 - *(_DWORD *)(v34 + 16)), v35);
  else
    writel_7((unsigned int)v35, v36);
  v37 = *((_QWORD *)a2 + 20);
  v38 = a2[68];
  v39 = *((_QWORD *)a2 + 12) + *(int *)(v37 + 74292);
  if ( (*(_BYTE *)(v37 + 74224) & 1) != 0 )
    hal_write32_mb_1(v37, (unsigned int)(v39 - *(_DWORD *)(v37 + 16)), v38 | 0x100u);
  else
    writel_7(v38 | 0x100u, v39);
  v40 = *((_QWORD *)a2 + 20);
  v41 = *((unsigned int *)a2 + 18);
  v42 = *((_QWORD *)a2 + 12) + *(int *)(v40 + 74296);
  if ( (*(_BYTE *)(v40 + 74224) & 1) != 0 )
    hal_write32_mb_1(v40, (unsigned int)(v42 - *(_DWORD *)(v40 + 16)), v41);
  else
    writel_7((unsigned int)v41, v42);
LABEL_29:
  v43 = *((_QWORD *)a2 + 20);
  v44 = *((unsigned int *)a2 + 2);
  v45 = *((_QWORD *)a2 + 12) + *(int *)(v43 + 74316);
  if ( (*(_BYTE *)(v43 + 74224) & 1) != 0 )
    hal_write32_mb_1(v43, (unsigned int)(v45 - *(_DWORD *)(v43 + 16)), v44);
  else
    writel_7((unsigned int)v44, v45);
  v46 = *((_QWORD *)a2 + 20);
  v47 = a2[12] | (((*((_DWORD *)a2 + 11) * *((_DWORD *)a2 + 8)) & 0xFFFFFu) << 8);
  v48 = *((_QWORD *)a2 + 12) + *(int *)(v46 + 74320);
  if ( (*(_BYTE *)(v46 + 74224) & 1) != 0 )
    hal_write32_mb_1(v46, (unsigned int)(v48 - *(_DWORD *)(v46 + 16)), v47);
  else
    writel_7((unsigned int)v47, v48);
  v49 = *((_QWORD *)a2 + 20);
  v50 = a2[44] | (*a2 << 8);
  v51 = *((_QWORD *)a2 + 12) + *(int *)(v49 + 74272);
  if ( (*(_BYTE *)(v49 + 74224) & 1) != 0 )
    hal_write32_mb_1(v49, (unsigned int)(v51 - *(_DWORD *)(v49 + 16)), v50);
  else
    writel_7((unsigned int)v50, v51);
  v52 = *((_DWORD *)a2 + 13);
  v53 = (*((_DWORD *)a2 + 12) << 13) & 0xFFFF0000;
  if ( v52 )
    v53 = ((unsigned __int16)*((_DWORD *)a2 + 11) * (_WORD)v52) & 0x7FFF | (unsigned int)v53;
  v54 = *((_QWORD *)a2 + 20);
  v55 = a1 + 73728;
  v56 = *((_QWORD *)a2 + 12) + *(int *)(v54 + 74324);
  if ( (*(_BYTE *)(v54 + 74224) & 1) != 0 )
    hal_write32_mb_1(v54, (unsigned int)(v56 - *(_DWORD *)(v54 + 16)), v53);
  else
    writel_7((unsigned int)v53, v56);
  v57 = *((_QWORD *)a2 + 20);
  v58 = *((_QWORD *)a2 + 16) - *(_QWORD *)(v55 + 288) + *(_QWORD *)(v55 + 296);
  v59 = *((_QWORD *)a2 + 12) + *(int *)(v57 + 74280);
  if ( (*(_BYTE *)(v57 + 74224) & 1) != 0 )
    hal_write32_mb_1(v57, (unsigned int)(v59 - *(_DWORD *)(v57 + 16)), (unsigned int)v58);
  else
    writel_7((unsigned int)v58, v59);
  v60 = *((_QWORD *)a2 + 20);
  v61 = *((_QWORD *)a2 + 12) + *(int *)(v60 + 74284);
  if ( (*(_BYTE *)(v60 + 74224) & 1) != 0 )
    hal_write32_mb_1(v60, (unsigned int)(v61 - *(_DWORD *)(v60 + 16)), HIDWORD(v58));
  else
    writel_7(HIDWORD(v58), v61);
  v62 = *((_QWORD *)a2 + 20);
  v63 = (unsigned int)(*((_DWORD *)a2 + 11) * a4);
  v64 = *((_QWORD *)a2 + 13) + *(int *)(v62 + 74264);
  if ( (*(_BYTE *)(v62 + 74224) & 1) != 0 )
    hal_write32_mb_1(v62, (unsigned int)(v64 - *(_DWORD *)(v62 + 16)), v63);
  else
    writel_7((unsigned int)v63, v64);
  v65 = *((_QWORD *)a2 + 20);
  v66 = (unsigned int)(*((_DWORD *)a2 + 11) * a4);
  v67 = *((_QWORD *)a2 + 13) + *(int *)(v65 + 74268);
  if ( (*(_BYTE *)(v65 + 74224) & 1) != 0 )
    hal_write32_mb_1(v65, (unsigned int)(v67 - *(_DWORD *)(v65 + 16)), v66);
  else
    writel_7((unsigned int)v66, v67);
  **((_DWORD **)a2 + 16) = *((_DWORD *)a2 + 11) * a4;
  v68 = *((_QWORD *)a2 + 20);
  v69 = *((_QWORD *)a2 + 12);
  *((_DWORD *)a2 + 30) = *((_DWORD *)a2 + 11) * a4;
  v70 = v69 + *(int *)(v68 + 74276);
  if ( (*(_BYTE *)(v68 + 74224) & 1) != 0 )
    return hal_write32_mb_1(v68, (unsigned int)(v70 - *(_DWORD *)(v68 + 16)), *((_DWORD *)a2 + 19) & 0x38 | 0x40u);
  else
    return writel_7(*((_DWORD *)a2 + 19) & 0x38 | 0x40u, v70);
}
