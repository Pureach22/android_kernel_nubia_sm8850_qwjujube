__int64 __fastcall wma_update_target_ext_he_cap(__int64 a1, _BYTE *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w9
  _DWORD *v13; // x24
  __int64 v14; // x9
  unsigned __int64 v15; // x26
  unsigned __int64 v16; // x25
  _DWORD *v17; // x27
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w27
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w23
  const char *v36; // x2
  unsigned int v37; // w1
  __int64 result; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  _QWORD v79[7]; // [xsp+8h] [xbp-88h] BYREF
  int v80; // [xsp+40h] [xbp-50h]
  _QWORD v81[7]; // [xsp+48h] [xbp-48h] BYREF
  int v82; // [xsp+80h] [xbp-10h]
  __int64 v83; // [xsp+88h] [xbp-8h]

  v83 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v82 = 0;
  memset(v81, 0, sizeof(v81));
  v80 = 0;
  memset(v79, 0, sizeof(v79));
  qdf_mem_set(a2 + 288, 0x3Cu, 0);
  qdf_mem_set(a2 + 348, 0x3Cu, 0);
  if ( !a1 )
    goto LABEL_34;
  v12 = *(_DWORD *)(a1 + 504);
  v13 = (_DWORD *)(a1 + 1072);
  if ( v12 <= 0xA )
  {
    if ( *v13 == v12 )
    {
      v14 = 0;
    }
    else if ( *(_DWORD *)(a1 + 1328) == v12 )
    {
      v14 = 1;
    }
    else if ( *(_DWORD *)(a1 + 1584) == v12 )
    {
      v14 = 2;
    }
    else if ( *(_DWORD *)(a1 + 1840) == v12 )
    {
      v14 = 3;
    }
    else if ( *(_DWORD *)(a1 + 2096) == v12 )
    {
      v14 = 4;
    }
    else if ( *(_DWORD *)(a1 + 2352) == v12 )
    {
      v14 = 5;
    }
    else if ( *(_DWORD *)(a1 + 2608) == v12 )
    {
      v14 = 6;
    }
    else
    {
      if ( *(_DWORD *)(a1 + 2864) != v12 )
      {
LABEL_34:
        v36 = "%s: Invalid MAC PHY capabilities handle";
LABEL_35:
        v37 = 2;
LABEL_36:
        result = qdf_trace_msg(0x36u, v37, v36, v4, v5, v6, v7, v8, v9, v10, v11, "wma_update_target_ext_he_cap");
        a2[176] = 0;
        goto LABEL_37;
      }
      v14 = 7;
    }
    v13 += 64 * v14;
  }
  if ( !v13 )
    goto LABEL_34;
  if ( !*(_DWORD *)(a1 + 824) )
  {
    v36 = "%s: No extended HE cap for current SOC";
    goto LABEL_35;
  }
  if ( a2[70] != 1 )
  {
    v36 = "%s: Target does not support 11AX";
    v37 = 4;
    goto LABEL_36;
  }
  if ( *(_BYTE *)(a1 + 486) )
  {
    v15 = (unsigned __int64)*(unsigned __int8 *)(a1 + 486) << 8;
    v16 = 0;
    do
    {
      qdf_mem_set(v81, 0x3Cu, 0);
      v17 = &v13[v16 / 4];
      if ( (v13[v16 / 4 + 6] & 1) != 0 )
      {
        wma_convert_he_cap(
          v81,
          v17 + 12,
          v17 + 26,
          (unsigned int)v17[14],
          (unsigned int)v17[15],
          (unsigned int)v17[16],
          a2 + 408);
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: 2g phy: nss: %d, ru_idx_msk: %d",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "wma_update_target_ext_he_cap",
          (unsigned int)v17[33],
          (unsigned int)v17[34]);
        wma_convert_he_ppet(a2 + 236, v17 + 33);
      }
      if ( LOBYTE(v81[0]) )
      {
        wma_derive_ext_he_cap(v79, v81, 0);
        wma_derive_ext_he_cap(a2 + 288, v81, 0);
      }
      qdf_mem_set(v81, 0x3Cu, 0);
      v26 = v17[6];
      if ( (v26 & 2) != 0 )
      {
        wma_convert_he_cap(
          v81,
          &v13[v16 / 4 + 21],
          &v13[v16 / 4 + 29],
          (unsigned int)v13[v16 / 4 + 23],
          (unsigned int)v13[v16 / 4 + 24],
          (unsigned int)v13[v16 / 4 + 25],
          a2 + 410);
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: 5g phy: nss: %d, ru_idx_msk: %d",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "wma_update_target_ext_he_cap",
          (unsigned int)v13[v16 / 4 + 43],
          (unsigned int)v13[v16 / 4 + 44]);
        wma_convert_he_ppet(a2 + 261, &v13[v16 / 4 + 43]);
      }
      if ( LOBYTE(v81[0]) )
      {
        v35 = (v26 >> 1) & 1;
        wma_derive_ext_he_cap(v79, v81, v35);
        wma_derive_ext_he_cap(a2 + 348, v81, v35);
      }
      v16 += 256LL;
    }
    while ( v15 != v16 );
  }
  qdf_mem_copy(a2 + 176, v79, 0x3Cu);
  wma_print_he_cap((__int64)(a2 + 176), v39, v40, v41, v42, v43, v44, v45, v46);
  qdf_trace_msg(0x36u, 8u, "%s: 5 GHz HE caps:", v47, v48, v49, v50, v51, v52, v53, v54, "wma_update_target_ext_he_cap");
  wma_print_he_cap((__int64)(a2 + 348), v55, v56, v57, v58, v59, v60, v61, v62);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: 2.4 GHz HE caps:",
    v63,
    v64,
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
    "wma_update_target_ext_he_cap");
  result = wma_print_he_cap((__int64)(a2 + 288), v71, v72, v73, v74, v75, v76, v77, v78);
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
