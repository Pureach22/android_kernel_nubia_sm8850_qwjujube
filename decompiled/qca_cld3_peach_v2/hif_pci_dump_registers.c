__int64 __fastcall hif_pci_dump_registers(_QWORD *a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x27
  int v11; // w0
  _DWORD *v12; // x8
  int v13; // w0
  _DWORD *v14; // x8
  unsigned int v15; // w21
  unsigned int v16; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // w0
  _DWORD *v34; // x8
  unsigned __int64 i; // x28
  unsigned int v36; // w0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  int v53; // w0
  _DWORD *v54; // x8
  unsigned int v55; // w24
  unsigned int v56; // w25
  unsigned int v57; // w0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  unsigned int j; // w25
  unsigned int *v67; // x8
  __int64 v68; // x23
  int v69; // w0
  unsigned int v70; // w26
  unsigned int v71; // w0
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  int v80; // w0
  _DWORD *v81; // x8
  int k; // w24
  int v83; // w0
  _DWORD *v84; // x8
  int v85; // w0
  unsigned int *v86; // x8
  unsigned int v87; // w22
  unsigned int v88; // w23
  unsigned int v89; // w0
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7

  if ( (unsigned int)hif_dump_ce_registers((__int64)a1) )
    qdf_trace_msg(0x3Du, 2u, "%s: Dump CE Registers Failed", v2, v3, v4, v5, v6, v7, v8, v9, "hif_pci_dump_registers");
  v10 = a1[3840];
  if ( (hif_target_sleep_state_adjust((__int64)a1) & 0x80000000) == 0 )
  {
    v11 = hif_read32_mb_reg_window(
            (__int64)a1,
            v10 + *(unsigned int *)(a1[77] + 56LL) + *(unsigned int *)(a1[77] + 888LL));
    v12 = (_DWORD *)a1[77];
    hif_write32_mb_reg_window((__int64)a1, v10 + v12[14] + v12[222], (6 << v12[224]) & v12[225] | v11 & ~v12[225]);
    v13 = hif_read32_mb_reg_window(
            (__int64)a1,
            v10 + *(unsigned int *)(a1[77] + 56LL) + *(unsigned int *)(a1[77] + 904LL));
    v14 = (_DWORD *)a1[77];
    hif_write32_mb_reg_window((__int64)a1, v10 + v14[14] + v14[226], (1 << v14[228]) & v14[229] | v13 & ~v14[229]);
    v15 = hif_read32_mb_reg_window(
            (__int64)a1,
            v10 + *(unsigned int *)(a1[77] + 56LL) + *(unsigned int *)(a1[77] + 888LL));
    v16 = hif_read32_mb_reg_window(
            (__int64)a1,
            v10 + *(unsigned int *)(a1[77] + 56LL) + *(unsigned int *)(a1[77] + 904LL));
    qdf_trace_msg(
      0x3Du,
      8u,
      "%s: Debug: inputsel: %x dbgctrl: %x",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "__hif_pci_dump_registers",
      v15,
      v16);
    qdf_trace_msg(0x3Du, 8u, "%s: Debug CE", v25, v26, v27, v28, v29, v30, v31, v32, "__hif_pci_dump_registers");
    v33 = hif_read32_mb_reg_window(
            (__int64)a1,
            v10 + *(unsigned int *)(a1[77] + 56LL) + *(unsigned int *)(a1[77] + 936LL));
    v34 = (_DWORD *)a1[77];
    hif_write32_mb_reg_window((__int64)a1, v10 + v34[14] + v34[234], (12 << v34[239]) & v34[240] | v33 & ~v34[240]);
    for ( i = 0; i != 9; ++i )
    {
      v53 = hif_read32_mb_reg_window(
              (__int64)a1,
              v10 + *(unsigned int *)(a1[78] + 60LL) + *(unsigned int *)(a1[78] + 224LL));
      v54 = (_DWORD *)a1[78];
      v55 = dword_B2D728[i];
      hif_write32_mb_reg_window((__int64)a1, v10 + v54[15] + v54[56], (v55 << v54[58]) & v54[59] | v53 & ~v54[59]);
      v56 = hif_read32_mb_reg_window(
              (__int64)a1,
              v10 + *(unsigned int *)(a1[77] + 56LL) + *(unsigned int *)(a1[77] + 936LL));
      v57 = hif_read32_mb_reg_window(
              (__int64)a1,
              v10 + *(unsigned int *)(a1[78] + 60LL) + *(unsigned int *)(a1[78] + 224LL));
      qdf_trace_msg(
        0x3Du,
        8u,
        "%s: ce wrapper: %d amdbg: %x cewdbg: %x",
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        "__hif_pci_dump_registers",
        v55,
        v56,
        v57);
      if ( i > 6 )
      {
        v36 = hif_read32_mb_reg_window(
                (__int64)a1,
                v10 + *(unsigned int *)(a1[77] + 56LL) + *(unsigned int *)(a1[77] + 920LL));
        qdf_trace_msg(
          0x3Du,
          8u,
          "%s: out: %x",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "__hif_pci_dump_registers",
          (*(_DWORD *)(a1[77] + 932LL) & v36) >> *(_DWORD *)(a1[77] + 928LL));
      }
      else
      {
        for ( j = 0; j != 6; ++j )
        {
          v67 = (unsigned int *)a1[78];
          v68 = v10 + v67[64] + (v67[65] - v67[64]) * v55;
          v69 = hif_read32_mb_reg_window((__int64)a1, v68 + v67[60]);
          hif_write32_mb_reg_window(
            (__int64)a1,
            v68 + *(_DWORD *)(a1[78] + 240LL),
            (j << *(_DWORD *)(a1[78] + 248LL)) & *(_DWORD *)(a1[78] + 252LL) | v69 & ~*(_DWORD *)(a1[78] + 252LL));
          v70 = (*(_DWORD *)(a1[77] + 932LL)
               & (unsigned int)hif_read32_mb_reg_window(
                                 (__int64)a1,
                                 v10 + *(unsigned int *)(a1[77] + 56LL) + *(unsigned int *)(a1[77] + 920LL))) >> *(_DWORD *)(a1[77] + 928LL);
          v71 = hif_read32_mb_reg_window((__int64)a1, v68 + *(unsigned int *)(a1[78] + 240LL));
          qdf_trace_msg(
            0x3Du,
            8u,
            "%s: module%d: cedbg: %x out: %x",
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            "__hif_pci_dump_registers",
            j,
            v71,
            v70);
        }
      }
    }
    qdf_trace_msg(0x3Du, 8u, "%s: Debug PCIe:", v45, v46, v47, v48, v49, v50, v51, v52, "__hif_pci_dump_registers");
    v80 = hif_read32_mb_reg_window(
            (__int64)a1,
            v10 + *(unsigned int *)(a1[77] + 56LL) + *(unsigned int *)(a1[77] + 936LL));
    v81 = (_DWORD *)a1[77];
    hif_write32_mb_reg_window((__int64)a1, v10 + v81[14] + v81[234], (28 << v81[239]) & v81[240] | v80 & ~v81[240]);
    for ( k = 0; k != 9; ++k )
    {
      v83 = hif_read32_mb_reg_window(
              (__int64)a1,
              v10 + *(unsigned int *)(a1[77] + 56LL) + *(unsigned int *)(a1[77] + 936LL));
      v84 = (_DWORD *)a1[77];
      hif_write32_mb_reg_window((__int64)a1, v10 + v84[14] + v84[234], (k << v84[236]) & v84[237] | v83 & ~v84[237]);
      v85 = hif_read32_mb_reg_window(
              (__int64)a1,
              v10 + *(unsigned int *)(a1[77] + 56LL) + *(unsigned int *)(a1[77] + 920LL));
      v86 = (unsigned int *)a1[77];
      v87 = (v86[233] & v85) >> v86[232];
      v88 = hif_read32_mb_reg_window((__int64)a1, v10 + v86[14] + v86[230]);
      v89 = hif_read32_mb_reg_window(
              (__int64)a1,
              v10 + *(unsigned int *)(a1[77] + 56LL) + *(unsigned int *)(a1[77] + 920LL));
      qdf_trace_msg(
        0x3Du,
        8u,
        "%s: amdbg: %x out: %x %x",
        v90,
        v91,
        v92,
        v93,
        v94,
        v95,
        v96,
        v97,
        "__hif_pci_dump_registers",
        v88,
        v87,
        v89);
    }
    hif_target_sleep_state_adjust((__int64)a1);
  }
  return 0;
}
