__int64 __fastcall hal_srng_src_hw_init_generic(
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
  __int64 v16; // x0
  __int64 v17; // x10
  __int64 v18; // x11
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v27; // w0
  __int64 v28; // x0
  __int64 v29; // x8
  __int64 v30; // x1
  __int64 v31; // x0
  __int64 v32; // x2
  __int64 v33; // x1
  __int64 v34; // x0
  int v35; // w8
  __int64 v36; // x1
  __int64 v37; // x0
  __int64 v38; // x2
  __int64 v39; // x1
  __int64 v40; // x0
  __int64 v41; // x2
  __int64 v42; // x1
  __int64 v43; // x0
  __int64 v44; // x2
  __int64 v45; // x1
  __int64 v46; // x0
  __int64 v47; // x1
  int v48; // w8
  __int64 v49; // x2
  __int64 v50; // x0
  __int64 v51; // x1
  __int64 v52; // x2
  __int64 v53; // x0
  __int64 v54; // x1
  int v55; // w21
  __int64 v56; // x0
  unsigned __int64 v57; // x21
  __int64 v58; // x1
  __int64 v59; // x0
  __int64 v60; // x1
  __int64 v61; // x0
  __int64 v62; // x2
  __int64 v63; // x1
  __int64 v64; // x0
  __int64 v65; // x2
  __int64 v66; // x1
  __int64 v67; // x0
  __int64 v68; // x10
  __int64 v69; // x1

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
    "hal_srng_src_hw_init_generic",
    *a2);
  v16 = *((_QWORD *)a2 + 20);
  v17 = *((_QWORD *)a2 + 12);
  v18 = *(int *)(v16 + 74348);
  if ( (a3 & 1) != 0 )
  {
    if ( (*(_BYTE *)(v16 + 74224) & 1) != 0 )
    {
      if ( (hal_read32_mb_1() & 0x80) == 0 )
      {
LABEL_8:
        qdf_trace_msg(
          0x46u,
          2u,
          "%s: ring_id %d not in idle state",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "hal_srng_src_hw_init_generic",
          *a2);
        v28 = printk(
                &unk_9BB309,
                "0",
                "hal_srng_src_hw_init_generic",
                "/proc/self/cwd/vendor/qcom/opensource/wlan/qcacld-3.0/cmn/hal/wifi3.0/hal_generic_api.h");
        dump_stack(v28);
        if ( (a2[78] & 2) == 0 )
          goto LABEL_25;
        goto LABEL_14;
      }
    }
    else if ( (readl_8(v17 + v18) & 0x80) == 0 )
    {
      goto LABEL_8;
    }
  }
  else
  {
    if ( (*(_BYTE *)(v16 + 74224) & 1) != 0 )
      v27 = hal_read32_mb_1();
    else
      v27 = readl_8(v17 + v18);
    v29 = *((_QWORD *)a2 + 20);
    v30 = *((_QWORD *)a2 + 12) + *(int *)(v29 + 74348);
    if ( (*(_BYTE *)(v29 + 74224) & 1) == 0 )
    {
      writel_7(v27 & 0xFFFFFFBF, v30);
      if ( (a2[78] & 2) == 0 )
        goto LABEL_25;
      goto LABEL_14;
    }
    hal_write32_mb_1(*((_QWORD *)a2 + 20), (unsigned int)(v30 - *(_DWORD *)(v29 + 16)), v27 & 0xFFFFFFBF);
  }
  if ( (a2[78] & 2) == 0 )
    goto LABEL_25;
LABEL_14:
  v31 = *((_QWORD *)a2 + 20);
  v32 = *((unsigned int *)a2 + 16);
  v33 = *((_QWORD *)a2 + 12) + *(int *)(v31 + 74360);
  if ( (*(_BYTE *)(v31 + 74224) & 1) != 0 )
    hal_write32_mb_1(v31, (unsigned int)(v33 - *(_DWORD *)(v31 + 16)), v32);
  else
    writel_7((unsigned int)v32, v33);
  v34 = *((_QWORD *)a2 + 20);
  v35 = a2[68];
  v36 = *((_QWORD *)a2 + 12) + *(int *)(v34 + 74364);
  if ( (*(_BYTE *)(v34 + 74224) & 1) != 0 )
    hal_write32_mb_1(v34, (unsigned int)(v36 - *(_DWORD *)(v34 + 16)), v35 | 0x100u);
  else
    writel_7(v35 | 0x100u, v36);
  v37 = *((_QWORD *)a2 + 20);
  v38 = *((unsigned int *)a2 + 18);
  v39 = *((_QWORD *)a2 + 12) + *(int *)(v37 + 74368);
  if ( (*(_BYTE *)(v37 + 74224) & 1) != 0 )
    hal_write32_mb_1(v37, (unsigned int)(v39 - *(_DWORD *)(v37 + 16)), v38);
  else
    writel_7((unsigned int)v38, v39);
LABEL_25:
  v40 = *((_QWORD *)a2 + 20);
  v41 = *((unsigned int *)a2 + 2);
  v42 = *((_QWORD *)a2 + 12) + *(int *)(v40 + 74372);
  if ( (*(_BYTE *)(v40 + 74224) & 1) != 0 )
    hal_write32_mb_1(v40, (unsigned int)(v42 - *(_DWORD *)(v40 + 16)), v41);
  else
    writel_7((unsigned int)v41, v42);
  v43 = *((_QWORD *)a2 + 20);
  v44 = a2[12] | (((*((_DWORD *)a2 + 11) * *((_DWORD *)a2 + 8)) & 0xFFFFFu) << 8);
  v45 = *((_QWORD *)a2 + 12) + *(int *)(v43 + 74376);
  if ( (*(_BYTE *)(v43 + 74224) & 1) != 0 )
    hal_write32_mb_1(v43, (unsigned int)(v45 - *(_DWORD *)(v43 + 16)), v44);
  else
    writel_7((unsigned int)v44, v45);
  v46 = *((_QWORD *)a2 + 20);
  v47 = *((_QWORD *)a2 + 12) + *(int *)(v46 + 74344);
  if ( (*(_BYTE *)(v46 + 74224) & 1) != 0 )
    hal_write32_mb_1(v46, (unsigned int)(v47 - *(_DWORD *)(v46 + 16)), a2[44]);
  else
    writel_7(a2[44], v47);
  v48 = *((_DWORD *)a2 + 13);
  v49 = (*((_DWORD *)a2 + 12) << 13) & 0xFFFF0000;
  if ( v48 )
    v49 = ((unsigned __int16)*((_DWORD *)a2 + 11) * (_WORD)v48) & 0x7FFF | (unsigned int)v49;
  v50 = *((_QWORD *)a2 + 20);
  v51 = *((_QWORD *)a2 + 12) + *(int *)(v50 + 74380);
  if ( (*(_BYTE *)(v50 + 74224) & 1) != 0 )
  {
    hal_write32_mb_1(v50, (unsigned int)(v51 - *(_DWORD *)(v50 + 16)), v49);
    if ( (a2[78] & 1) != 0 )
    {
LABEL_38:
      v52 = *((unsigned __int16 *)a2 + 76);
      goto LABEL_41;
    }
  }
  else
  {
    writel_7((unsigned int)v49, v51);
    if ( (a2[78] & 1) != 0 )
      goto LABEL_38;
  }
  v52 = 0;
LABEL_41:
  v53 = *((_QWORD *)a2 + 20);
  v54 = *((_QWORD *)a2 + 12) + *(int *)(v53 + 74384);
  if ( (*(_BYTE *)(v53 + 74224) & 1) != 0 )
    hal_write32_mb_1(v53, (unsigned int)(v54 - *(_DWORD *)(v53 + 16)), v52);
  else
    writel_7((unsigned int)v52, v54);
  if ( *a2 == 120 )
  {
    v55 = 67;
  }
  else
  {
    v56 = *((_QWORD *)a2 + 20);
    v57 = *((_QWORD *)a2 + 16) - *(_QWORD *)(a1 + 74016) + *(_QWORD *)(a1 + 74024);
    v58 = *((_QWORD *)a2 + 12) + *(int *)(v56 + 74352);
    if ( (*(_BYTE *)(v56 + 74224) & 1) != 0 )
      hal_write32_mb_1(v56, (unsigned int)(v58 - *(_DWORD *)(v56 + 16)), (unsigned int)v57);
    else
      writel_7((unsigned int)v57, v58);
    v59 = *((_QWORD *)a2 + 20);
    v60 = *((_QWORD *)a2 + 12) + *(int *)(v59 + 74356);
    if ( (*(_BYTE *)(v59 + 74224) & 1) != 0 )
      hal_write32_mb_1(v59, (unsigned int)(v60 - *(_DWORD *)(v59 + 16)), HIDWORD(v57));
    else
      writel_7(HIDWORD(v57), v60);
    v55 = 66;
  }
  v61 = *((_QWORD *)a2 + 20);
  v62 = (unsigned int)(*((_DWORD *)a2 + 11) * a4);
  v63 = *((_QWORD *)a2 + 13) + *(int *)(v61 + 74336);
  if ( (*(_BYTE *)(v61 + 74224) & 1) != 0 )
    hal_write32_mb_1(v61, (unsigned int)(v63 - *(_DWORD *)(v61 + 16)), v62);
  else
    writel_7((unsigned int)v62, v63);
  v64 = *((_QWORD *)a2 + 20);
  v65 = (unsigned int)(*((_DWORD *)a2 + 11) * a4);
  v66 = *((_QWORD *)a2 + 13) + *(int *)(v64 + 74340);
  if ( (*(_BYTE *)(v64 + 74224) & 1) != 0 )
    hal_write32_mb_1(v64, (unsigned int)(v66 - *(_DWORD *)(v64 + 16)), v65);
  else
    writel_7((unsigned int)v65, v66);
  **((_DWORD **)a2 + 16) = *((_DWORD *)a2 + 11) * a4;
  v67 = *((_QWORD *)a2 + 20);
  v68 = *((_QWORD *)a2 + 12);
  *((_DWORD *)a2 + 30) = *((_DWORD *)a2 + 11) * a4;
  v69 = v68 + *(int *)(v67 + 74348);
  if ( (*(_BYTE *)(v67 + 74224) & 1) != 0 )
    return hal_write32_mb_1(v67, (unsigned int)(v69 - *(_DWORD *)(v67 + 16)), v55 | *((_DWORD *)a2 + 19) & 0x38u);
  else
    return writel_7(v55 | *((_DWORD *)a2 + 19) & 0x38u, v69);
}
