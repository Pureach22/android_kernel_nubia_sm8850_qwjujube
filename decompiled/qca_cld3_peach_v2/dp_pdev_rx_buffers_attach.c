__int64 __fastcall dp_pdev_rx_buffers_attach(_QWORD *a1, unsigned int a2, __int64 *a3, __int64 a4, unsigned int a5)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w20
  __int64 v19; // x27
  __int64 v20; // x23
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x3
  unsigned int v38; // w9
  unsigned int v39; // w8
  unsigned int v40; // w19
  __int64 v41; // x8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w26
  unsigned __int16 free_desc_list; // w0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  unsigned __int64 v60; // x24
  int v61; // w21
  __int64 v62; // x0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  int v71; // w26
  _QWORD *v72; // x25
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  unsigned __int64 v81; // x26
  unsigned __int64 v82; // x19
  int v83; // w8
  unsigned int v84; // w8
  _QWORD *v85; // x27
  unsigned __int64 v86; // x26
  __int64 v87; // x8
  unsigned int v88; // w9
  __int64 v89; // x10
  __int64 v90; // x8
  __int64 v91; // x25
  __int64 v92; // x21
  char v93; // w9
  void (*v94)(void); // x8
  __int64 v95; // x0
  _DWORD *v96; // x2
  __int64 v97; // x8
  unsigned int v98; // w20
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  __int64 v108; // [xsp+8h] [xbp-38h]
  int v109; // [xsp+10h] [xbp-30h]
  int v110; // [xsp+14h] [xbp-2Ch]
  _QWORD *v111; // [xsp+18h] [xbp-28h]
  unsigned int v112; // [xsp+24h] [xbp-1Ch]
  __int64 v113; // [xsp+28h] [xbp-18h] BYREF
  _QWORD v114[2]; // [xsp+30h] [xbp-10h] BYREF

  v114[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(a1[5]) && (unsigned __int8)wlan_cfg_get_pdev_idx(a1[5], a2)
    || (v19 = a1[9], v20 = *a3, v113 = 0, v114[0] = 0, !v19) )
  {
    qdf_trace_msg(
      0x7Eu,
      2u,
      "%s: %pK: pdev is null for mac_id = %d",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "dp_pdev_rx_buffers_attach",
      a1,
      a2);
    v18 = 16;
    goto LABEL_59;
  }
  wlan_cfg_is_dp_buf_page_frag_alloc_enable(a1[5]);
  if ( !v20 )
  {
    v18 = 16;
    *(_DWORD *)(v19 + 432) += a5;
    goto LABEL_59;
  }
  qdf_trace_msg(
    0x45u,
    8u,
    "%s: requested %u RX buffers for driver attach",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "dp_pdev_rx_buffers_attach",
    a5);
  hal_srng_access_start(a1[141], v20, v29, v30, v31, v32, v33, v34, v35, v36);
  v37 = *(unsigned int *)(v20 + 120);
  v38 = **(_DWORD **)(v20 + 128);
  v39 = v38 - v37;
  *(_DWORD *)(v20 + 136) = v38;
  if ( v38 <= (unsigned int)v37 )
    v39 += *(_DWORD *)(v20 + 36);
  v40 = v39 / *(_DWORD *)(v20 + 44) - 1;
  if ( (*(_DWORD *)(v20 + 76) & 0x80000000) == 0 )
  {
    hal_delayed_reg_write(a1[141], v20, *(_QWORD *)(v20 + 144), v37);
    v41 = *(_QWORD *)(v20 + 88);
    if ( (v41 & 1) == 0 )
      goto LABEL_10;
LABEL_51:
    *(_QWORD *)(v20 + 88) = v41 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v20 + 80);
    if ( v40 )
      goto LABEL_11;
LABEL_52:
    v18 = 2;
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Num of available entries is zero, nothing to do",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "dp_pdev_rx_buffers_attach");
    goto LABEL_59;
  }
  **(_DWORD **)(v20 + 144) = v37;
  v41 = *(_QWORD *)(v20 + 88);
  if ( (v41 & 1) != 0 )
    goto LABEL_51;
LABEL_10:
  raw_spin_unlock(v20 + 80);
  if ( !v40 )
    goto LABEL_52;
LABEL_11:
  if ( v40 >= a5 )
    v50 = a5;
  else
    v50 = v40;
  free_desc_list = dp_rx_get_free_desc_list(a1, a2, a4, v50, v114, &v113);
  v60 = free_desc_list;
  if ( !free_desc_list )
  {
    v18 = 2;
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: no free rx_descs in freelist",
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      "dp_pdev_rx_buffers_attach");
    *(_DWORD *)(v19 + 484) += v50;
    goto LABEL_59;
  }
  qdf_trace_msg(
    0x45u,
    8u,
    "%s: got %u RX descs for driver attach",
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    "dp_pdev_rx_buffers_attach",
    free_desc_list);
  if ( (_BYTE)v60 )
    v61 = (v60 >> 8) + 1;
  else
    v61 = v60 >> 8;
  v62 = _qdf_mem_malloc(0x1000u, "dp_pdev_rx_buffers_attach", 3369);
  if ( !v62 )
  {
    v18 = 2;
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: failed to allocate nbuf array",
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      "dp_pdev_rx_buffers_attach");
    *(_DWORD *)(v19 + 432) += v50;
    goto LABEL_59;
  }
  v111 = (_QWORD *)v62;
  if ( !v61 )
  {
    v82 = 0;
    v98 = 0;
    goto LABEL_56;
  }
  v71 = 0;
  v112 = 0;
  v108 = v19;
  v109 = v61;
  do
  {
    v72 = v111;
    qdf_mem_set(v111, 0x1000u, 0);
    if ( v112 >= (unsigned int)v60 )
    {
      hal_srng_access_start(a1[141], v20, v73, v74, v75, v76, v77, v78, v79, v80);
      LODWORD(v82) = 0;
    }
    else
    {
      v110 = v71;
      v81 = 0;
      while ( (*(_BYTE *)(a4 + 77) & 1) != 0
           || !(unsigned int)dp_pdev_nbuf_alloc_and_map((__int64)a1, v72, v19, a4, 0, a2) )
      {
        v82 = v81 + 1;
        if ( v81 <= 0xFE )
        {
          v83 = v112 + v81;
          v72 += 2;
          ++v81;
          if ( v83 + 1 < (unsigned int)v60 )
            continue;
        }
        v84 = v112 + v82;
        goto LABEL_30;
      }
      v82 = v81;
      v84 = v112 + v81;
LABEL_30:
      v112 = v84;
      hal_srng_access_start(a1[141], v20, v73, v74, v75, v76, v77, v78, v79, v80);
      if ( (_DWORD)v82 )
      {
        v85 = v111;
        v86 = v82;
        do
        {
          v87 = *(unsigned int *)(v20 + 120);
          v88 = (unsigned int)(*(_DWORD *)(v20 + 44) + v87) % *(_DWORD *)(v20 + 36);
          if ( v88 == *(_DWORD *)(v20 + 136)
            || (v89 = *(_QWORD *)(v20 + 16), *(_DWORD *)(v20 + 120) = v88,
                                             *(_DWORD *)(v20 + 124) = v88,
                                             !(v89 + 4 * v87)) )
          {
            v95 = printk(
                    &unk_AAA255,
                    "rxdma_ring_entry",
                    "dp_pdev_rx_buffers_attach",
                    "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx.c");
            dump_stack(v95);
          }
          v90 = v114[0];
          v91 = v85[1];
          v92 = *(_QWORD *)v114[0];
          if ( (*(_BYTE *)(a4 + 77) & 1) == 0 )
          {
            *(_QWORD *)v114[0] = v91;
            v93 = *(_BYTE *)(v90 + 30) & 0xFD;
            *(_QWORD *)(v90 + 16) = *v85;
            *(_BYTE *)(v90 + 30) = v93;
            v90 = v114[0];
          }
          *(_BYTE *)(v90 + 30) |= 1u;
          v94 = *(void (**)(void))(*(_QWORD *)(a1[141] + 74392LL) + 1472LL);
          if ( *((_DWORD *)v94 - 1) != -1494657337 )
            __break(0x8228u);
          v94();
          dp_ipa_handle_rx_buf_smmu_mapping(
            a1,
            v91,
            *(unsigned __int16 *)(a4 + 74),
            1,
            "dp_pdev_rx_buffers_attach",
            3438,
            4);
          --v86;
          v85 += 2;
          v114[0] = v92;
        }
        while ( v86 );
        v19 = v108;
      }
      else
      {
        LODWORD(v82) = 0;
      }
      v61 = v109;
      v71 = v110;
    }
    v96 = *(_DWORD **)(v20 + 144);
    if ( (*(_DWORD *)(v20 + 76) & 0x80000000) != 0 )
    {
      *v96 = *(_DWORD *)(v20 + 120);
      v97 = *(_QWORD *)(v20 + 88);
      if ( (v97 & 1) == 0 )
      {
LABEL_45:
        raw_spin_unlock(v20 + 80);
        goto LABEL_46;
      }
    }
    else
    {
      hal_delayed_reg_write(a1[141], v20, v96, *(unsigned int *)(v20 + 120));
      v97 = *(_QWORD *)(v20 + 88);
      if ( (v97 & 1) == 0 )
        goto LABEL_45;
    }
    *(_QWORD *)(v20 + 88) = v97 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v20 + 80);
LABEL_46:
    ++v71;
  }
  while ( v71 != v61 );
  v98 = v112;
  v82 = (unsigned int)v82;
LABEL_56:
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: filled %u RX buffers for driver attach",
    v63,
    v64,
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
    "dp_pdev_rx_buffers_attach",
    v98);
  _qdf_mem_free((__int64)v111);
  if ( v98 )
  {
    v18 = 0;
    *(_QWORD *)(v19 + 416) += v82;
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: No nbuf's allocated",
      v99,
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      v106,
      "dp_pdev_rx_buffers_attach");
    v18 = 1;
  }
LABEL_59:
  _ReadStatusReg(SP_EL0);
  return v18;
}
