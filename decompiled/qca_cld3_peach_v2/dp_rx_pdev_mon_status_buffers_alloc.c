__int64 __fastcall dp_rx_pdev_mon_status_buffers_alloc(
        unsigned __int8 *a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x4
  __int64 v11; // x19
  __int64 v13; // x20
  unsigned int v14; // w24
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x25
  __int64 v24; // x22
  unsigned __int16 free_desc_list; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w24
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w9
  unsigned int v44; // w10
  unsigned int v45; // w8
  unsigned int v46; // w21
  unsigned int v47; // w26
  unsigned int v48; // w8
  unsigned int v49; // w8
  __int64 v50; // x0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x8
  __int64 v60; // x28
  __int64 v61; // x12
  __int64 v62; // x24
  unsigned int v63; // w10
  __int64 *v64; // x9
  __int64 v65; // x20
  __int64 v66; // x0
  __int64 v67; // x2
  _DWORD *v68; // x8
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  unsigned int v85; // w23
  __int64 result; // x0
  __int64 v87; // x8
  __int64 v88; // x20
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  int v105; // w9
  unsigned int v106; // w10
  unsigned int v107; // w8
  __int64 v108; // x6
  __int64 v109; // x7
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  unsigned int v118; // w8
  int v119; // w10
  unsigned int v120; // w9
  __int64 v121; // x4
  __int64 v122; // x5
  unsigned int v123; // [xsp+10h] [xbp-30h]
  unsigned int v124; // [xsp+14h] [xbp-2Ch]
  __int64 v125; // [xsp+18h] [xbp-28h]
  unsigned int v126; // [xsp+20h] [xbp-20h]
  int v127; // [xsp+24h] [xbp-1Ch]
  __int64 *v128; // [xsp+28h] [xbp-18h] BYREF
  _QWORD v129[2]; // [xsp+30h] [xbp-10h] BYREF

  v129[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a1;
  v11 = *((_QWORD *)a1 + 1);
  v128 = nullptr;
  v129[0] = 0;
  if ( a2 >= 3 )
    __break(0x5512u);
  v13 = v11 + 80LL * a2;
  v14 = *(_DWORD *)(v13 + 852);
  qdf_trace_msg(
    0x45u,
    8u,
    "%s: Mon RX Desc Pool[%d] entries=%u",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "dp_rx_pdev_mon_status_buffers_alloc",
    v10,
    v14);
  v127 = *(unsigned __int8 *)(v11 + 20060);
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v11 + 40))
    && (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(v11 + 40), a2)
    || (v23 = *(_QWORD *)(v11 + 72)) == 0 )
  {
    qdf_trace_msg(
      0x84u,
      8u,
      "%s: %pK: pdev is null for mac_id = %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "dp_rx_mon_status_buffers_replenish",
      v11,
      a2);
    result = 16;
  }
  else
  {
    v24 = *(_QWORD *)(v13 + 800);
    qdf_trace_msg(
      0x84u,
      8u,
      "%s: %pK: requested %d buffers for replenish",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "dp_rx_mon_status_buffers_replenish",
      v11,
      v14);
    free_desc_list = dp_rx_get_free_desc_list(v11, a2, v11 + 120LL * a2 + 11936, v14, v129, &v128);
    if ( free_desc_list )
    {
      v34 = free_desc_list;
      qdf_trace_msg(
        0x84u,
        8u,
        "%s: %pK: %d rx desc allocated",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "dp_rx_mon_status_buffers_replenish",
        v11,
        free_desc_list);
      hal_srng_access_start_3(*(_QWORD *)(v11 + 1128), v24);
      v43 = *(_DWORD *)(v24 + 120);
      v123 = a2;
      v125 = v11 + 120LL * a2 + 11936;
      v44 = **(_DWORD **)(v24 + 128);
      v45 = v44 - v43;
      *(_DWORD *)(v24 + 136) = v44;
      if ( v44 <= v43 )
        v45 += *(_DWORD *)(v24 + 36);
      v46 = v45 / *(_DWORD *)(v24 + 44) - 1;
      qdf_trace_msg(
        0x84u,
        8u,
        "%s: %pK: no of available entries in rxdma ring: %d",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "dp_rx_mon_status_buffers_replenish",
        v11,
        v46);
      v47 = 0;
      if ( v46 >= v34 )
        v48 = v34;
      else
        v48 = v46;
      v126 = v48;
      v49 = (unsigned __int16)(v34 - v46);
      if ( v34 <= v46 )
        v49 = 0;
      v124 = v49;
      while ( 1 )
      {
        v50 = dp_rx_nbuf_prepare(v11, v23);
        if ( !v50 )
          break;
        v59 = *(unsigned int *)(v24 + 120);
        v60 = v50;
        v61 = 80;
        if ( (*(_BYTE *)(v50 + 68) & 4) == 0 )
          v61 = 40;
        v62 = *(_QWORD *)(v50 + v61);
        v63 = (unsigned int)(*(_DWORD *)(v24 + 44) + v59) % *(_DWORD *)(v24 + 36);
        v64 = (__int64 *)v129[0];
        v65 = *(_QWORD *)v129[0];
        if ( v63 != *(_DWORD *)(v24 + 136) )
          *(_DWORD *)(v24 + 120) = v63;
        v66 = *(_QWORD *)(v24 + 16) + 4 * v59;
        if ( !v66 )
        {
          qdf_trace_msg(
            0x84u,
            2u,
            "%s: %pK: rxdma_ring_entry is NULL, count - %d",
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            "dp_rx_mon_status_buffers_replenish",
            v11,
            v47);
          qdf_nbuf_unmap_nbytes_single_0(*(_QWORD *)(v11 + 24), v60, *(unsigned __int16 *)(v125 + 74));
          _qdf_nbuf_free(v60);
          goto LABEL_23;
        }
        *v64 = v60;
        ++v47;
        v67 = *(unsigned int *)(v129[0] + 24LL);
        *(_BYTE *)(v129[0] + 30LL) = *(_BYTE *)(v129[0] + 30LL) & 0xFC | 1;
        v68 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(v11 + 1128) + 74392LL) + 1472LL);
        if ( *(v68 - 1) != -1494657337 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v68)(v66, v62, v67, (unsigned int)(v127 + 3));
        qdf_trace_msg(
          0x84u,
          8u,
          "%s: %pK: rx_desc=%pK, cookie=%d, nbuf=%pK, paddr=%pK",
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          "dp_rx_mon_status_buffers_replenish",
          v11,
          v129[0],
          *(unsigned int *)(v129[0] + 24LL),
          v60,
          v62);
        v129[0] = v65;
        if ( v47 > v126 )
          goto LABEL_23;
      }
      v105 = *(_DWORD *)(v24 + 116);
      v106 = *(_DWORD *)(v24 + 120);
      v107 = **(_DWORD **)(v24 + 128);
      if ( v105 )
        v108 = v107;
      else
        v108 = v106;
      if ( v105 )
        v109 = v106;
      else
        v109 = v107;
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: %pK: qdf_nbuf allocate or map fail, count %d hp:%u tp:%u",
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        "dp_rx_mon_status_buffers_replenish",
        v11,
        v47,
        v108,
        v109);
      v118 = *(_DWORD *)(v24 + 120);
      if ( v118 != *(_DWORD *)(v24 + 136) )
      {
        if ( v118 )
          v118 = (v118 - *(_DWORD *)(v24 + 44)) % *(_DWORD *)(v24 + 36);
        else
          v118 = *(_DWORD *)(v24 + 36) - *(_DWORD *)(v24 + 44);
        *(_DWORD *)(v24 + 120) = v118;
      }
      v119 = *(_DWORD *)(v24 + 116);
      v120 = **(_DWORD **)(v24 + 128);
      if ( v119 )
        v121 = v120;
      else
        v121 = v118;
      if ( v119 )
        v122 = v118;
      else
        v122 = v120;
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: HP adjusted to proper buffer index, hp:%u tp:%u",
        v110,
        v111,
        v112,
        v113,
        v114,
        v115,
        v116,
        v117,
        "dp_rx_mon_status_buffers_replenish",
        v121,
        v122);
LABEL_23:
      if ( v24 )
      {
        v85 = v124;
        if ( (*(_DWORD *)(v24 + 76) & 0x80000000) != 0 )
          **(_DWORD **)(v24 + 144) = *(_DWORD *)(v24 + 120);
        else
          hal_delayed_reg_write(
            *(_QWORD *)(v11 + 1128),
            (unsigned __int8 *)v24,
            *(_QWORD *)(v24 + 144),
            *(_DWORD *)(v24 + 120));
        v87 = *(_QWORD *)(v24 + 88);
        v88 = v125;
        if ( (v87 & 1) != 0 )
        {
          *(_QWORD *)(v24 + 88) = v87 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v24 + 80);
        }
        else
        {
          raw_spin_unlock(v24 + 80);
        }
      }
      else
      {
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: Error: Invalid hal_ring\n",
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          "hal_srng_access_end");
        v88 = v125;
        v85 = v124;
      }
      qdf_trace_msg(
        0x84u,
        8u,
        "%s: %pK: successfully replenished %d buffers",
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        v95,
        v96,
        "dp_rx_mon_status_buffers_replenish",
        v11,
        v126);
      qdf_trace_msg(
        0x84u,
        8u,
        "%s: %pK: %d rx desc added back to free list",
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        "dp_rx_mon_status_buffers_replenish",
        v11,
        v85);
      if ( v129[0] )
        dp_rx_add_desc_list_to_free_list(v11, v129, &v128, v123, v88);
      result = 0;
    }
    else
    {
      qdf_trace_msg(
        0x84u,
        2u,
        "%s: %pK: no free rx_descs in freelist",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "dp_rx_mon_status_buffers_replenish",
        v11);
      result = 2;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
