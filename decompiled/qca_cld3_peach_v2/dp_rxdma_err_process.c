__int64 __fastcall dp_rxdma_err_process(__int64 a1, __int64 a2, unsigned int a3, int a4)
{
  __int64 v4; // x25
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x24
  int v18; // w26
  __int64 v19; // x20
  char v20; // w11
  __int64 v21; // x21
  unsigned int v22; // w9
  __int64 v24; // x0
  __int64 v25; // x9
  unsigned __int64 v26; // x13
  __int64 v27; // x10
  __int64 v28; // x9
  __int64 v29; // x1
  unsigned int *v35; // x20
  __int64 v36; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x8
  unsigned int *v46; // x22
  unsigned int *v47; // x0
  unsigned int v48; // w20
  void (__fastcall *v49)(unsigned int *, unsigned __int64 *); // x8
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int v58; // w8
  int v59; // w8
  unsigned __int64 v60; // x1
  __int64 v61; // x2
  __int64 v62; // x3
  void (__fastcall *v63)(__int64 *, unsigned __int64, __int64, __int64); // x8
  double (__fastcall *v64)(__int64, unsigned __int64 *); // x8
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  unsigned int v73; // w8
  _QWORD *v74; // x8
  __int64 v75; // x22
  __int64 v76; // x24
  __int64 (__fastcall *v77)(__int64, __int64); // x8
  __int64 v78; // x1
  __int64 v79; // x0
  __int64 v80; // x20
  __int64 v81; // x21
  unsigned __int64 v82; // x28
  __int64 v83; // x8
  unsigned int *v84; // x8
  char v85; // w9
  __int64 v86; // x10
  __int64 v87; // x0
  __int64 v88; // x0
  int v89; // w0
  unsigned __int64 v90; // x10
  __int64 v91; // x4
  __int64 v92; // x5
  __int64 v94; // [xsp+0h] [xbp-140h]
  __int64 v95; // [xsp+18h] [xbp-128h]
  unsigned int v96; // [xsp+20h] [xbp-120h]
  __int64 v97; // [xsp+28h] [xbp-118h]
  __int64 v98; // [xsp+38h] [xbp-108h]
  __int64 v99; // [xsp+40h] [xbp-100h]
  unsigned int v100; // [xsp+4Ch] [xbp-F4h]
  __int64 v101; // [xsp+50h] [xbp-F0h]
  int v102; // [xsp+58h] [xbp-E8h]
  int v103; // [xsp+5Ch] [xbp-E4h]
  __int64 v104; // [xsp+60h] [xbp-E0h]
  unsigned int v105; // [xsp+68h] [xbp-D8h]
  unsigned int v106; // [xsp+6Ch] [xbp-D4h]
  unsigned __int64 StatusReg; // [xsp+70h] [xbp-D0h]
  __int64 v108; // [xsp+80h] [xbp-C0h] BYREF
  unsigned int *v109; // [xsp+88h] [xbp-B8h] BYREF
  unsigned __int64 v110; // [xsp+90h] [xbp-B0h] BYREF
  __int64 v111; // [xsp+98h] [xbp-A8h]
  unsigned __int16 v112; // [xsp+A4h] [xbp-9Ch] BYREF
  __int64 v113; // [xsp+A8h] [xbp-98h] BYREF
  _QWORD v114[6]; // [xsp+B0h] [xbp-90h] BYREF
  _QWORD v115[3]; // [xsp+E0h] [xbp-60h] BYREF
  __int64 v116; // [xsp+F8h] [xbp-48h]
  __int64 v117; // [xsp+100h] [xbp-40h]
  __int64 v118; // [xsp+108h] [xbp-38h]
  __int64 v119; // [xsp+110h] [xbp-30h]
  __int64 v120; // [xsp+118h] [xbp-28h]
  __int64 v121; // [xsp+120h] [xbp-20h]
  __int64 v122; // [xsp+128h] [xbp-18h]
  __int64 v123; // [xsp+130h] [xbp-10h]

  v123 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a2 + 40))
    && (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a2 + 40), a3) )
  {
    goto LABEL_82;
  }
  v17 = *(_QWORD *)(a2 + 72);
  v108 = 0;
  v109 = nullptr;
  if ( v17 )
  {
    if ( a3 >= 2 )
    {
LABEL_85:
      __break(0x5512u);
      goto LABEL_86;
    }
    v4 = *(_QWORD *)(a2 + 80LL * a3 + 320);
    if ( !v4 )
    {
      v91 = a2;
      v92 = 0;
LABEL_81:
      qdf_trace_msg(
        0x82u,
        2u,
        "%s: %pK: HAL Monitor Destination Ring Init Failed -- %pK",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "dp_rxdma_err_process",
        v91,
        v92);
LABEL_82:
      LODWORD(v17) = 0;
      goto LABEL_83;
    }
    v99 = *(_QWORD *)(a2 + 1128);
    if ( (unsigned int)dp_srng_access_start(a1, a2, (char *)v4) )
    {
LABEL_86:
      v91 = a2;
      v92 = v4;
      goto LABEL_81;
    }
    if ( !a4 )
    {
      dp_srng_access_end(a1, a2, (char *)v4, v9, v10, v11, v12, v13, v14, v15, v16);
      goto LABEL_82;
    }
    v103 = a4;
    v95 = v17;
    v96 = a3;
    LODWORD(v17) = 0;
    v97 = a1;
    StatusReg = _ReadStatusReg(SP_EL0);
    v100 = a3;
    v101 = v4;
    do
    {
      v19 = *(unsigned int *)(v4 + 120);
      if ( (_DWORD)v19 == *(_DWORD *)(v4 + 136) )
        break;
      v20 = *(_BYTE *)(v4 + 78);
      v21 = *(_QWORD *)(v4 + 16);
      if ( *(_DWORD *)(v4 + 44) + (_DWORD)v19 == *(_DWORD *)(v4 + 36) )
        v22 = 0;
      else
        v22 = *(_DWORD *)(v4 + 44) + v19;
      *(_DWORD *)(v4 + 120) = v22;
      if ( (v20 & 4) != 0 )
      {
        _X22 = v21 + 4LL * v22;
        v24 = *(_QWORD *)(*(_QWORD *)(v99 + 8) + 40LL);
        if ( (*(_BYTE *)(v24 + 844) & 0x40) == 0 )
        {
          v25 = _X22 << 8 >> 8;
          v26 = (unsigned __int64)(v25 + 0x8000000000LL) >> 38;
          v27 = memstart_addr + v25 + 0x8000000000LL;
          v28 = v25 - kimage_voffset;
          if ( v26 )
            v29 = v28;
          else
            v29 = v27;
          _dma_sync_single_for_cpu(v24, v29);
        }
        __asm { PRFM            #0, [X22] }
        a3 = v100;
      }
      v35 = (unsigned int *)(v21 + 4 * v19);
      if ( !v35 )
        break;
      v36 = *(_QWORD *)(a2 + 40);
      v121 = 0;
      v122 = 0;
      v119 = 0;
      v120 = 0;
      v117 = 0;
      v118 = 0;
      v116 = 0;
      memset(v115, 0, sizeof(v115));
      memset(v114, 0, sizeof(v114));
      v112 = 0;
      v110 = 0;
      v111 = 0;
      v102 = v17;
      if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(v36)
        && (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a2 + 40), a3)
        || (v45 = *(_QWORD *)(a2 + 72), v113 = 0, (v104 = v45) == 0) )
      {
        qdf_trace_msg(
          0x82u,
          8u,
          "%s: %pK: pdev is null for mac_id = %d",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "dp_rx_err_mpdu_pop",
          a2,
          a3);
        v18 = 0;
        goto LABEL_10;
      }
      v46 = v35;
      v47 = v35;
      v48 = v35[7] >> 28;
      v49 = *(void (__fastcall **)(unsigned int *, unsigned __int64 *))(*(_QWORD *)(*(_QWORD *)(a2 + 1128) + 74392LL)
                                                                      + 1456LL);
      if ( *((_DWORD *)v49 - 1) != -621572614 )
        __break(0x8228u);
      v49(v47, &v110);
      v110 = *v46 | ((unsigned __int64)*((unsigned __int8 *)v46 + 4) << 32);
      LODWORD(v94) = v48;
      qdf_trace_msg(
        0x45u,
        8u,
        "[%s][%d] ReoAddr=%pK, addrInfo=%pK, paddr=0x%llx, loopcnt=%d",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "hal_rx_reo_ent_buf_paddr_get",
        427,
        v46,
        v46,
        v94);
      v58 = *((unsigned __int8 *)v46 + 24);
      v18 = 0;
      v98 = (__int64)v46;
      if ( (v58 & 3) != 0 )
        v59 = 0;
      else
        v59 = (v58 >> 2) & 0x1F;
      v105 = v59;
      v106 = 0;
      do
      {
        v73 = ((unsigned int)v111 >> 5) & 0x3FF;
        if ( v73 >= *(unsigned __int16 *)(a2 + 1914)
          || (v74 = (_QWORD *)(*(_QWORD *)(a2 + 1920) + 24LL * v73), (v75 = *v74 + v110 - v74[2]) == 0) )
        {
          v88 = printk(
                  &unk_AAA255,
                  "rx_msdu_link_desc",
                  "dp_rx_err_mpdu_pop",
                  "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx_err.c");
          dump_stack(v88);
          v75 = 0;
        }
        hal_rx_msdu_list_get(*(_QWORD *)(a2 + 1128), v75, (__int64)v114, (__int16 *)&v112);
        if ( LODWORD(v115[0]) == 0x1FFFFF )
        {
          v105 = 31;
          goto LABEL_33;
        }
        if ( *(_DWORD *)(a2 + 20060) + 3 != (unsigned __int8)v116
          && (unsigned int)wlan_cfg_get_dp_pdev_nss_enabled(*(_QWORD *)(v104 + 288)) )
        {
          v106 = 1;
          goto LABEL_33;
        }
        if ( v112 )
        {
          v76 = 4LL * v112;
          v4 = 0;
          while ( 1 )
          {
            if ( v4 == 24 )
              goto LABEL_85;
            v77 = *(__int64 (__fastcall **)(__int64, __int64))(a2 + 1408);
            v78 = *(unsigned int *)((char *)v115 + v4);
            if ( *((_DWORD *)v77 - 1) != 207937137 )
              __break(0x8228u);
            v79 = v77(a2, v78);
            v80 = v79;
            if ( !v79 )
              break;
            if ( (*(_BYTE *)(v79 + 30) & 1) == 0 )
              goto LABEL_65;
            v81 = *(_QWORD *)v79;
            if ( (*(_BYTE *)(v79 + 30) & 2) == 0 )
            {
              v82 = *(unsigned __int8 *)(v79 + 28);
              if ( v82 > 4 )
                goto LABEL_85;
              if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
                || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
              {
                raw_spin_lock(a2 + 18520);
              }
              else
              {
                raw_spin_lock_bh(a2 + 18520);
                *(_QWORD *)(a2 + 18528) |= 1uLL;
              }
              dp_rx_nbuf_unmap_pool(a2, a2 + 12416 + 120LL * (unsigned int)v82, v81);
              *(_BYTE *)(v80 + 30) |= 2u;
              v83 = *(_QWORD *)(a2 + 18528);
              if ( (v83 & 1) != 0 )
              {
                *(_QWORD *)(a2 + 18528) = v83 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(a2 + 18520);
              }
              else
              {
                raw_spin_unlock(a2 + 18520);
              }
            }
            qdf_trace_msg(
              0x82u,
              8u,
              "%s: %pK: msdu_nbuf=%pK ",
              v9,
              v10,
              v11,
              v12,
              v13,
              v14,
              v15,
              v16,
              "dp_rx_err_mpdu_pop",
              a2,
              v81);
            dp_rx_buffer_pool_nbuf_free(a2, v81, *(unsigned __int8 *)(v80 + 28));
            v84 = v109;
            v85 = *(_BYTE *)(v80 + 30);
            ++v18;
            *(_QWORD *)v80 = v109;
            v86 = v108;
            *(_BYTE *)(v80 + 30) = v85 & 0xFE;
            v109 = (unsigned int *)v80;
            if ( !v86 || !v84 )
              v108 = v80;
LABEL_47:
            v4 += 4;
            if ( v76 == v4 )
              goto LABEL_33;
          }
          v87 = printk(
                  &unk_AAA255,
                  "rx_desc",
                  "dp_rx_err_mpdu_pop",
                  "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx_err.c");
          dump_stack(v87);
LABEL_65:
          if ( a2 )
            ++*(_DWORD *)(a2 + 14064);
          dp_rx_dump_info_and_assert(a2, *(_QWORD *)(a2 + 6720), v98, v80);
          goto LABEL_47;
        }
LABEL_33:
        v60 = v110;
        v61 = (unsigned int)v111;
        v62 = BYTE4(v111);
        v63 = *(void (__fastcall **)(__int64 *, unsigned __int64, __int64, __int64))(*(_QWORD *)(*(_QWORD *)(a2 + 1128)
                                                                                               + 74392LL)
                                                                                   + 1472LL);
        if ( *((_DWORD *)v63 - 1) != -1494657337 )
          __break(0x8228u);
        v63(&v113, v60, v61, v62);
        v64 = *(double (__fastcall **)(__int64, unsigned __int64 *))(*(_QWORD *)(*(_QWORD *)(a2 + 1128) + 74392LL)
                                                                   + 1456LL);
        if ( *((_DWORD *)v64 - 1) != -621572614 )
          __break(0x8228u);
        v65 = v64(v75 + 4, &v110);
        v110 = *(unsigned int *)(v75 + 4) | ((unsigned __int64)*(unsigned __int8 *)(v75 + 8) << 32);
        dp_rx_link_desc_return_by_addr(a2, (unsigned int *)&v113, v106, v65, v66, v67, v68, v69, v70, v71, v72);
      }
      while ( v110 );
      if ( a2 )
        ++*(_DWORD *)(a2 + 13832 + 4LL * v105);
      a3 = v100;
      ++*(_DWORD *)(v104 + 500);
      if ( v105 == 3 )
        qdf_trace_msg(
          0x82u,
          2u,
          "%s: %pK: Packet received with Decrypt error",
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          "dp_rx_err_mpdu_pop",
          a2);
LABEL_10:
      v4 = v101;
      LODWORD(v17) = v18 + v102;
      --v103;
    }
    while ( v103 );
    dp_srng_access_end(v97, a2, (char *)v4, v9, v10, v11, v12, v13, v14, v15, v16);
    if ( (_DWORD)v17 )
    {
      v89 = wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a2 + 40));
      LODWORD(v90) = v96;
      if ( v89 || (v90 = *(unsigned __int8 *)(v95 + 1), v90 <= 1) )
      {
        _dp_rx_buffers_replenish(
          a2,
          a3,
          (__int64 *)(a2 + 80LL * (unsigned int)v90 + 80),
          a2 + 120LL * (unsigned int)v90 + 12416,
          v17,
          &v109,
          (__int64)&v108,
          0,
          0);
        goto LABEL_83;
      }
      goto LABEL_85;
    }
  }
LABEL_83:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v17;
}
