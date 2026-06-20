__int64 __fastcall dp_rx_reo_err_entry_process(
        __int64 a1,
        __int64 a2,
        unsigned __int16 *a3,
        __int64 a4,
        unsigned int a5)
{
  __int64 v8; // x8
  __int64 (*v9)(void); // x8
  _BOOL4 v11; // w8
  __int64 v12; // x23
  _QWORD *v13; // x20
  __int64 v14; // x1
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned __int16 v23; // w26
  __int64 v24; // x24
  __int64 (__fastcall *v25)(__int64, __int64); // x8
  __int64 v26; // x1
  __int64 v27; // x0
  char v28; // w8
  __int64 v29; // x28
  __int64 *v30; // x27
  __int64 v31; // x9
  unsigned int v32; // w22
  __int64 v33; // x25
  __int64 v34; // x8
  _QWORD *v35; // x21
  char v36; // w8
  __int64 v37; // x9
  __int64 v38; // x9
  int v39; // w8
  unsigned __int64 v40; // x9
  unsigned __int64 v41; // x8
  char v42; // w8
  void (__fastcall *v43)(__int64, unsigned __int16 *); // x8
  __int64 v44; // x0
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x8
  unsigned int (__fastcall *v48)(_QWORD); // x8
  __int64 v49; // x8
  void (__fastcall *v50)(__int64, unsigned __int64 *); // x9
  __int64 v51; // x0
  _DWORD *v52; // x8
  __int64 (__fastcall *v53)(__int64, __int64); // x8
  __int64 v54; // x1
  __int64 v55; // x20
  __int64 v56; // x28
  _QWORD *ref_by_id_2; // x0
  __int64 v58; // x23
  int v59; // w26
  __int64 v60; // x21
  unsigned __int8 (__fastcall *v61)(_QWORD); // x8
  __int64 (__fastcall *v62)(_QWORD); // x8
  _DWORD *v63; // x8
  __int64 v64; // x20
  __int64 v65; // x20
  __int64 v66; // x0
  __int64 v67; // x21
  __int64 v68; // x0
  unsigned int *v69; // x22
  void (__fastcall *v70)(__int64 *, unsigned __int64 *); // x8
  unsigned int v71; // w8
  _QWORD *v72; // x8
  __int64 v74; // [xsp+8h] [xbp-158h]
  unsigned int *i; // [xsp+28h] [xbp-138h]
  __int64 v78; // [xsp+30h] [xbp-130h]
  unsigned int v79; // [xsp+38h] [xbp-128h]
  char v80; // [xsp+3Ch] [xbp-124h]
  int v81; // [xsp+40h] [xbp-120h]
  unsigned int v82; // [xsp+44h] [xbp-11Ch]
  __int64 v83; // [xsp+48h] [xbp-118h]
  unsigned __int64 StatusReg; // [xsp+50h] [xbp-110h]
  unsigned int v85; // [xsp+5Ch] [xbp-104h]
  char v86; // [xsp+6Ch] [xbp-F4h]
  unsigned __int16 v87; // [xsp+7Ch] [xbp-E4h]
  unsigned int v88; // [xsp+8Ch] [xbp-D4h]
  __int64 v89; // [xsp+90h] [xbp-D0h] BYREF
  __int64 v90; // [xsp+98h] [xbp-C8h] BYREF
  unsigned __int16 v91; // [xsp+A4h] [xbp-BCh] BYREF
  unsigned __int64 v92; // [xsp+A8h] [xbp-B8h] BYREF
  __int64 v93; // [xsp+B0h] [xbp-B0h]
  unsigned __int64 v94; // [xsp+B8h] [xbp-A8h] BYREF
  _QWORD v95[6]; // [xsp+C0h] [xbp-A0h] BYREF
  _QWORD v96[4]; // [xsp+F0h] [xbp-70h] BYREF
  _QWORD v97[6]; // [xsp+110h] [xbp-50h] BYREF
  _QWORD v98[4]; // [xsp+140h] [xbp-20h] BYREF

  v98[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 6352);
  v92 = 0;
  v93 = 0;
  v89 = 0;
  v90 = 0;
  v74 = v8;
  v9 = *(__int64 (**)(void))(a1 + 1432);
  if ( *((_DWORD *)v9 - 1) != 1020823628 )
    __break(0x8228u);
  v85 = v9();
  v82 = a5;
  if ( (*(_BYTE *)(a1 + 20040) & 1) != 0 )
  {
    if ( a5 > 0xC || (v81 = 1, ((1 << a5) & 0x10A0) == 0) )
    {
      v11 = a5 == 6 || a5 == 8;
      v81 = v11;
    }
  }
  else
  {
    v81 = 0;
  }
  v12 = 0;
  v13 = nullptr;
  v14 = a4;
  v83 = 0;
  v79 = 17;
  v80 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  v87 = 0;
  v86 = 0;
  v88 = 0;
  memset(v97, 0, sizeof(v97));
  memset(v96, 0, sizeof(v96));
  memset(v95, 0, sizeof(v95));
  v91 = 0;
  for ( i = (unsigned int *)a2; ; i = (unsigned int *)&v90 )
  {
    v78 = v14;
    hal_rx_msdu_list_get(*(_QWORD *)(a1 + 1128), v14, (__int64)v95, (__int16 *)&v91);
    v23 = v91;
    if ( v91 )
      break;
LABEL_126:
    if ( v78 )
    {
      v69 = i;
      v89 = *(_QWORD *)(v78 + 4);
      if ( !(_DWORD)v89 )
        goto LABEL_136;
      qdf_mem_set((void *)(v78 + 4), 8u, 0);
    }
    else
    {
      qdf_mem_set(&v89, 8u, 0);
      v69 = i;
      if ( !(_DWORD)v89 )
      {
LABEL_136:
        dp_rx_link_desc_return_by_addr(a1, v69, 0, v15, v16, v17, v18, v19, v20, v21, v22);
        if ( *a3 != v87 )
          goto LABEL_140;
        goto LABEL_137;
      }
    }
    dp_rx_link_desc_return_by_addr(a1, v69, 0, v15, v16, v17, v18, v19, v20, v21, v22);
    v70 = *(void (__fastcall **)(__int64 *, unsigned __int64 *))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1456LL);
    v92 = (unsigned int)v89 | ((unsigned __int64)BYTE4(v89) << 32);
    if ( *((_DWORD *)v70 - 1) != -621572614 )
      __break(0x8228u);
    v70(&v89, &v92);
    v71 = ((unsigned int)v93 >> 5) & 0x3FF;
    if ( v71 >= *(unsigned __int16 *)(a1 + 1866) )
    {
      v14 = 0;
    }
    else
    {
      v72 = (_QWORD *)(*(_QWORD *)(a1 + 1872) + 24LL * v71);
      v14 = *v72 + v92 - v72[2];
    }
    v90 = v89;
  }
  v24 = 0;
  while ( v24 != 6 )
  {
    v25 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 1408);
    v26 = *((unsigned int *)v96 + v24);
    if ( *((_DWORD *)v25 - 1) != 207937137 )
      __break(0x8228u);
    v27 = v25(a1, v26);
    if ( !v27 )
    {
      v68 = printk(
              &unk_9BB309,
              "expr",
              "__dp_assert_always_internal",
              "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_internal.h");
      dump_stack(v68);
      goto LABEL_19;
    }
    v28 = *(_BYTE *)(v27 + 30);
    v29 = v27;
    if ( (v28 & 1) == 0 || (v30 = *(__int64 **)v27) == nullptr )
    {
      if ( a1 )
        ++*(_DWORD *)(a1 + 14000);
      v67 = jiffies;
      if ( dp_rx_reo_err_entry_process___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: Reaping rx_desc not in use!",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "dp_rx_reo_err_entry_process");
        dp_rx_reo_err_entry_process___last_ticks = v67;
      }
      dp_rx_dump_info_and_assert(a1, v74, a2, v29);
      goto LABEL_36;
    }
    if ( (v24 & 0x1FFFFFFFFFFFFFFFLL) == 6 )
      goto LABEL_139;
    v31 = 10;
    if ( (*((_BYTE *)v30 + 68) & 4) == 0 )
      v31 = 5;
    if ( v30[v31] != v97[v24] )
    {
      if ( a1 )
      {
        ++*(_DWORD *)(a1 + 14108);
        v28 = *(_BYTE *)(v27 + 30);
      }
      *(_BYTE *)(v27 + 30) = v28 | 4;
LABEL_36:
      v86 = 1;
      goto LABEL_19;
    }
    v32 = *(unsigned __int8 *)(v27 + 28);
    if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a1 + 40))
      && (unsigned __int8)wlan_cfg_get_pdev_idx(*(_QWORD *)(a1 + 40), v32) )
    {
      v33 = 0;
    }
    else
    {
      v33 = *(_QWORD *)(a1 + 72);
    }
    if ( v32 > 4 )
      break;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 18464);
    }
    else
    {
      raw_spin_lock_bh(a1 + 18464);
      *(_QWORD *)(a1 + 18472) |= 1uLL;
    }
    dp_rx_nbuf_unmap_pool(a1, a1 + 12368 + 120LL * v32, (__int64)v30);
    *(_BYTE *)(v29 + 30) |= 2u;
    v34 = *(_QWORD *)(a1 + 18472);
    if ( (v34 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18472) = v34 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18464);
    }
    else
    {
      raw_spin_unlock(a1 + 18464);
    }
    v35 = &v95[v24];
    *((_WORD *)v30 + 30) = *((_WORD *)v35 + 2);
    v36 = *(_BYTE *)(v29 + 30);
    *(_QWORD *)v29 = 0;
    *(_BYTE *)(v29 + 30) = v36 & 0xFE;
    *(_QWORD *)v29 = *(_QWORD *)(v33 + 95224);
    v37 = *(_QWORD *)(v33 + 95232);
    *(_QWORD *)(v33 + 95224) = v29;
    if ( v37 && *(_QWORD *)v29 )
    {
      if ( v12 )
        goto LABEL_48;
    }
    else
    {
      *(_QWORD *)(v33 + 95232) = v29;
      if ( v12 )
      {
LABEL_48:
        *v13 = v30;
        v38 = *(_QWORD *)(v12 + 72);
        v39 = v38 + 0x1000000;
        v40 = v38 & 0xFFFFFFFF00FFFFFFLL;
        v41 = v39 & 0xFF000000;
        goto LABEL_51;
      }
    }
    v40 = 0x1000000;
    v12 = (__int64)v30;
    v41 = v30[9] & 0xFFFFFFFF00FFFFFFLL;
LABEL_51:
    *(_QWORD *)(v12 + 72) = v41 | v40;
    v42 = *(_BYTE *)v35;
    *v30 = 0;
    ++v88;
    if ( (v42 & 4) != 0 )
    {
      v13 = v30;
      *((_BYTE *)v30 + 84) |= 2u;
      goto LABEL_19;
    }
    if ( (((__int64 (__fastcall *)(__int64, __int64, _QWORD))dp_rx_buffer_pool_refill)(a1, v12, v32) & 1) == 0 )
    {
      if ( !v81 )
        goto LABEL_78;
      if ( (*(_BYTE *)v35 & 1) != 0 )
      {
        if ( (v80 & 1) == 0 )
        {
          v43 = *(void (__fastcall **)(__int64, unsigned __int16 *))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL)
                                                                   + 1600LL);
          if ( v43 )
          {
            v44 = v30[28];
            if ( *((_DWORD *)v43 - 1) != -177782713 )
              __break(0x8228u);
            v43(v44, a3);
          }
        }
      }
      else if ( (v80 & 1) == 0 )
      {
        if ( (v86 & 1) != 0 )
        {
          v80 = 0;
          v86 = 1;
        }
        else
        {
          v66 = printk(
                  &unk_9BB309,
                  "0",
                  "dp_rx_reo_err_entry_process",
                  "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_rx_err.c");
          dump_stack(v66);
          v80 = 0;
          v86 = 0;
        }
        do
        {
LABEL_105:
          v64 = *(_QWORD *)v12;
          _qdf_nbuf_free(v12);
          v12 = v64;
        }
        while ( v64 );
        goto LABEL_18;
      }
      v45 = *(_QWORD *)(a1 + 1128);
      v46 = v30[28];
      v94 = 0;
      v47 = *(_QWORD *)(v45 + 74392);
      v98[0] = 0;
      v98[1] = 0;
      v48 = *(unsigned int (__fastcall **)(_QWORD))(v47 + 544);
      if ( *((_DWORD *)v48 - 1) != 855462014 )
        __break(0x8228u);
      if ( !v48(v46) )
        goto LABEL_73;
      v49 = *(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL);
      v50 = *(void (__fastcall **)(__int64, unsigned __int64 *))(v49 + 1328);
      if ( v50 )
      {
        if ( *((_DWORD *)v50 - 1) != -153087695 )
          __break(0x8229u);
        v50(a2, &v94);
        v49 = *(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL);
      }
      v51 = v30[28];
      v52 = *(_DWORD **)(v49 + 1320);
      if ( *(v52 - 1) != 721645347 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD *))v52)(v51, v98);
      if ( v98[0] > v94 )
      {
LABEL_73:
        v53 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 1432);
        v54 = *((unsigned int *)a3 + 2);
        if ( *((_DWORD *)v53 - 1) != 1020823628 )
          __break(0x8228u);
        v85 = v53(a1, v54);
        if ( a3[6] )
          dp_rx_bar_frame_handle(a1, (__int64)a3, v79, 0, v82);
        v80 = 1;
LABEL_78:
        v55 = *(_QWORD *)(v12 + 224);
        v56 = v30[28];
        if ( (__int64 *)v12 != v30 )
        {
          *(_WORD *)(v12 + 60) = *((_WORD *)v30 + 30);
          v30 = dp_rx_sg_create(a1, (__int64 *)v12);
          *((_BYTE *)v30 + 84) |= 0x80u;
          if ( a1 )
            ++*(_DWORD *)(a1 + 14088);
        }
        ref_by_id_2 = (_QWORD *)dp_peer_get_ref_by_id_2(a1, v85);
        if ( ref_by_id_2 )
        {
          v58 = (__int64)ref_by_id_2;
          if ( *ref_by_id_2 )
          {
            v59 = 1;
            goto LABEL_87;
          }
          dp_peer_unref_delete((__int64)ref_by_id_2, 4u, v15, v16, v17, v18, v19, v20, v21, v22);
        }
        v60 = jiffies;
        if ( dp_rx_reo_err_entry_process___last_ticks_21 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: txrx_peer is null peer_id %u",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            "dp_rx_reo_err_entry_process",
            (unsigned __int16)v85);
          v59 = 0;
          dp_rx_reo_err_entry_process___last_ticks_21 = v60;
        }
        else
        {
          v59 = 0;
        }
        v58 = v83;
LABEL_87:
        if ( v82 <= 0xC )
        {
          if ( ((1 << v82) & 0x1060) != 0 )
          {
            v61 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 560LL);
            if ( *((_DWORD *)v61 - 1) != -1147376687 )
              __break(0x8228u);
            if ( v61(v56) )
            {
              v62 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 392LL);
              if ( *((_DWORD *)v62 - 1) != 855462014 )
                __break(0x8228u);
              v79 = v62(v55);
            }
            dp_2k_jump_handle(a1, (__int64)v30, v56, v85, v79);
            goto LABEL_111;
          }
          if ( ((1 << v82) & 0x180) != 0 )
          {
            dp_rx_oor_handle(a1, v30, v85, v56);
LABEL_111:
            if ( v59 )
              dp_txrx_peer_unref_delete(v58, 4u, v15, v16, v17, v18, v19, v20, v21, v22);
            v83 = v58;
            goto LABEL_18;
          }
          if ( !v82 )
          {
            v63 = *(_DWORD **)(a1 + 1720);
            if ( *(v63 - 1) != 450902238 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, __int64 *, __int64, _QWORD))v63)(a1, v30, v56, v32);
            goto LABEL_111;
          }
        }
        v65 = jiffies;
        if ( dp_rx_reo_err_entry_process___last_ticks_23 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: Non-support error code %d",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            "dp_rx_reo_err_entry_process",
            v82);
          dp_rx_reo_err_entry_process___last_ticks_23 = v65;
        }
        if ( v30 )
          _qdf_nbuf_free((__int64)v30);
        goto LABEL_111;
      }
      if ( a1 )
        ++*(_DWORD *)(a1 + 14132);
      v80 = 1;
      goto LABEL_105;
    }
    v86 = 1;
LABEL_18:
    v23 = v91;
    v12 = 0;
    v13 = nullptr;
    ++v87;
LABEL_19:
    if ( ++v24 >= (unsigned __int64)v23 )
      goto LABEL_126;
  }
  __break(0x5512u);
LABEL_139:
  __break(1u);
LABEL_140:
  if ( a1 )
    ++*(_DWORD *)(a1 + 14096);
LABEL_137:
  _ReadStatusReg(SP_EL0);
  return v88;
}
