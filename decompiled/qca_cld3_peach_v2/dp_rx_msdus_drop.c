__int64 __fastcall dp_rx_msdus_drop(__int64 a1, unsigned int *a2, unsigned __int16 *a3, _BYTE *a4, char a5)
{
  unsigned int *v8; // x23
  __int64 v9; // x8
  __int64 v10; // x8
  void (__fastcall *v11)(unsigned int *, unsigned __int64 *); // x9
  void (__fastcall *v12)(unsigned int *, unsigned __int64 *); // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w8
  _QWORD *v22; // x8
  unsigned __int64 v23; // x25
  unsigned int v24; // w20
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x20
  __int64 (__fastcall *v34)(__int64, __int64); // x8
  __int64 v35; // x1
  unsigned __int8 *v36; // x28
  unsigned int v37; // w26
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  _QWORD *v46; // x25
  unsigned __int64 v47; // x23
  __int64 v48; // x8
  __int64 (*v49)(void); // x8
  unsigned int v50; // w0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x26
  unsigned int (__fastcall *v60)(_QWORD); // x8
  void (__fastcall *v61)(_QWORD); // x8
  __int64 v62; // x0
  __int64 v63; // x27
  void (__fastcall *v64)(__int64, __int64, __int64, __int64, __int64, __int64); // x23
  unsigned __int16 v65; // w0
  unsigned __int8 v66; // w8
  __int64 v67; // x8
  __int64 v68; // x0
  unsigned __int16 v69; // w26
  __int64 (*v70)(void); // x8
  void (__fastcall *v71)(__int64, __int64 *); // x8
  unsigned __int64 v72; // x8
  unsigned int v73; // w9
  unsigned __int64 v74; // x26
  unsigned int v75; // w8
  __int64 v76; // x1
  __int64 v77; // x8
  __int64 v78; // x2
  __int64 v79; // x1
  __int64 v80; // x8
  void *v81; // x25
  __int64 v82; // t1
  void (__fastcall *v83)(__int64 *, unsigned __int64 *); // x8
  unsigned int v84; // w9
  unsigned int v85; // w8
  _QWORD *v86; // x8
  __int64 v88; // [xsp+0h] [xbp-100h]
  __int16 v89; // [xsp+Ch] [xbp-F4h]
  unsigned __int64 v90; // [xsp+10h] [xbp-F0h]
  unsigned int *v91; // [xsp+18h] [xbp-E8h]
  unsigned int v92; // [xsp+20h] [xbp-E0h]
  unsigned __int64 StatusReg; // [xsp+28h] [xbp-D8h]
  __int64 v95; // [xsp+48h] [xbp-B8h] BYREF
  __int64 v96; // [xsp+50h] [xbp-B0h] BYREF
  unsigned __int64 v97; // [xsp+58h] [xbp-A8h] BYREF
  __int64 v98; // [xsp+60h] [xbp-A0h]
  __int64 v99; // [xsp+68h] [xbp-98h] BYREF
  _QWORD v100[6]; // [xsp+70h] [xbp-90h] BYREF
  _QWORD v101[12]; // [xsp+A0h] [xbp-60h] BYREF

  v8 = a2;
  v101[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 1128);
  v97 = 0;
  v98 = 0;
  v95 = 0;
  v96 = 0;
  v10 = *(_QWORD *)(v9 + 74392);
  v11 = *(void (__fastcall **)(unsigned int *, unsigned __int64 *))(v10 + 1464);
  if ( v11 )
  {
    if ( *((_DWORD *)v11 - 1) != 1721787685 )
      __break(0x8229u);
    v11(a2, &v97);
    v10 = *(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL);
  }
  v12 = *(void (__fastcall **)(unsigned int *, unsigned __int64 *))(v10 + 1456);
  if ( *((_DWORD *)v12 - 1) != -621572614 )
    __break(0x8228u);
  v12(v8, &v97);
  v21 = ((unsigned int)v98 >> 5) & 0x3FF;
  if ( v21 < *(unsigned __int16 *)(a1 + 1914)
    && (v22 = (_QWORD *)(*(_QWORD *)(a1 + 1920) + 24LL * v21), (v23 = *v22 + v97 - v22[2]) != 0) )
  {
    v24 = 0;
    memset(v101, 0, 80);
    StatusReg = _ReadStatusReg(SP_EL0);
    memset(v100, 0, sizeof(v100));
    while ( 1 )
    {
      hal_rx_msdu_list_get(*(_QWORD *)(a1 + 1128), v23, v100, a3);
      if ( *a3 )
        break;
LABEL_63:
      if ( v23 )
      {
        v82 = *(_QWORD *)(v23 + 4);
        v81 = (void *)(v23 + 4);
        v95 = v82;
        if ( !(_DWORD)v82 )
          goto LABEL_74;
        qdf_mem_set(v81, 8u, 0);
      }
      else
      {
        qdf_mem_set(&v95, 8u, 0);
        if ( !(_DWORD)v95 )
        {
LABEL_74:
          dp_rx_link_desc_return_by_addr(a1, v8, 0, v25, v26, v27, v28, v29, v30, v31, v32);
          goto LABEL_73;
        }
      }
      dp_rx_link_desc_return_by_addr(a1, v8, 0, v25, v26, v27, v28, v29, v30, v31, v32);
      v83 = *(void (__fastcall **)(__int64 *, unsigned __int64 *))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1456LL);
      v97 = (unsigned int)v95 | ((unsigned __int64)BYTE4(v95) << 32);
      if ( *((_DWORD *)v83 - 1) != -621572614 )
        __break(0x8228u);
      v83(&v95, &v97);
      v84 = *(unsigned __int16 *)(a1 + 1914);
      v23 = 0;
      v8 = (unsigned int *)&v96;
      v85 = ((unsigned int)v98 >> 5) & 0x3FF;
      v96 = v95;
      if ( v85 < v84 )
      {
        v86 = (_QWORD *)(*(_QWORD *)(a1 + 1920) + 24LL * v85);
        v8 = (unsigned int *)&v96;
        v23 = *v86 + v97 - v86[2];
      }
    }
    v92 = v24;
    v33 = 0;
    v90 = v23;
    v91 = v8;
    while ( 1 )
    {
      if ( v33 == 6 )
LABEL_75:
        __break(0x5512u);
      v34 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 1408);
      v35 = *((unsigned int *)v101 + v33);
      if ( *((_DWORD *)v34 - 1) != 207937137 )
        __break(0x8228u);
      v36 = (unsigned __int8 *)v34(a1, v35);
      if ( !v36 )
      {
        v68 = printk(
                &unk_AAA255,
                "rx_desc",
                "dp_rx_msdus_drop",
                "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx_err.c");
        dump_stack(v68);
      }
      v37 = v36[28];
      *a4 = v37;
      if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a1 + 40)) )
      {
        if ( (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a1 + 40), v37) )
          break;
      }
      v46 = *(_QWORD **)(a1 + 72);
      if ( !v46 )
        break;
      v47 = v36[28];
      if ( v47 > 4 )
        goto LABEL_75;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 18520);
      }
      else
      {
        raw_spin_lock_bh(a1 + 18520);
        *(_QWORD *)(a1 + 18528) |= 1uLL;
      }
      dp_rx_nbuf_unmap_pool(a1, a1 + 12416 + 120LL * (unsigned int)v47, *(_QWORD *)v36);
      v36[30] |= 2u;
      v48 = *(_QWORD *)(a1 + 18528);
      if ( (v48 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 18528) = v48 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 18520);
      }
      else
      {
        raw_spin_unlock(a1 + 18520);
      }
      *((_QWORD *)v36 + 1) = *(_QWORD *)(*(_QWORD *)v36 + 224LL);
      if ( (a5 & 1) != 0 )
      {
        v49 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 392LL);
        if ( *((_DWORD *)v49 - 1) != 855462014 )
          __break(0x8228u);
        v50 = v49();
        qdf_trace_msg(
          0x82u,
          2u,
          "%s: %pK: Packet with PN error for tid :%d",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          "dp_rx_msdus_drop",
          a1,
          v50);
        v59 = *(_QWORD *)(*(_QWORD *)v36 + 224LL);
        v60 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 544LL);
        if ( *((_DWORD *)v60 - 1) != 855462014 )
          __break(0x8228u);
        if ( v60(v59) )
        {
          v61 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 552LL);
          if ( *((_DWORD *)v61 - 1) != -821198918 )
            __break(0x8228u);
          v61(v59);
        }
      }
      v62 = *(_QWORD *)(a1 + 40);
      v63 = *(_QWORD *)v36;
      v64 = (void (__fastcall *)(__int64, __int64, __int64, __int64, __int64, __int64))v46[12064];
      v99 = 0;
      v65 = wlan_cfg_rx_buffer_size(v62);
      if ( v64 )
      {
        v69 = v65;
        v88 = *(_QWORD *)(v63 + 224);
        v70 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1272LL);
        if ( *((_DWORD *)v70 - 1) != 855462014 )
          __break(0x8228u);
        v89 = v70();
        v71 = *(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 880LL);
        if ( *((_DWORD *)v71 - 1) != -177782713 )
          __break(0x8228u);
        v71(v88, &v99);
        if ( a3[6] || (a3[3] & 0x10) != 0 )
          v72 = *(unsigned __int16 *)(a1 + 1138);
        else
          v72 = (unsigned __int16)v99 + (unsigned __int64)*(unsigned __int16 *)(a1 + 1138);
        v73 = v69;
        v74 = v72;
        v75 = (unsigned __int16)(v89 + v72);
        if ( v75 >= v73 )
          v76 = v73;
        else
          v76 = v75;
        qdf_nbuf_set_pktlen(v63, v76);
        v77 = *(_QWORD *)(v63 + 40);
        if ( v77 )
          *(_QWORD *)(v63 + 40) = v77 + v74;
        skb_pull(v63, (unsigned int)v74);
        v78 = *(unsigned __int8 *)(v63 + 86);
        v79 = *(unsigned __int8 *)v46;
        if ( *((_DWORD *)v64 - 1) != -915278510 )
          __break(0x8237u);
        v64(a1, v79, v78, v63, 4, 3);
        v80 = *(_QWORD *)(v63 + 40);
        if ( v80 )
          *(_QWORD *)(v63 + 40) = v80 - v74;
        skb_push(v63, (unsigned int)v74);
      }
      dp_rx_buffer_pool_nbuf_free(a1, *(_QWORD *)v36, (unsigned __int8)*a4);
      v66 = v36[30];
      *(_QWORD *)v36 = 0;
      v36[30] = v66 & 0xFE;
      *(_QWORD *)v36 = v46[12015];
      v67 = v46[12016];
      v46[12015] = v36;
      if ( !v67 || !*(_QWORD *)v36 )
        v46[12016] = v36;
      if ( ++v33 >= (unsigned __int64)*a3 )
      {
        v8 = v91;
        v23 = v90;
        v24 = v92 + v33;
        goto LABEL_63;
      }
    }
    qdf_trace_msg(
      0x82u,
      8u,
      "%s: %pK: pdev is null for pool_id = %d",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "dp_rx_msdus_drop",
      a1,
      v36[28],
      v88);
    v24 = v92 + v33;
  }
  else
  {
    qdf_trace_msg(
      0x82u,
      8u,
      "%s: link desc va is null, soc %pk",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "dp_rx_msdus_drop",
      a1);
    v24 = 0;
  }
LABEL_73:
  _ReadStatusReg(SP_EL0);
  return v24;
}
