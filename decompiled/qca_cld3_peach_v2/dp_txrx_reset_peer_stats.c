__int64 __fastcall dp_txrx_reset_peer_stats(__int64 a1, unsigned __int8 a2, unsigned __int8 *a3)
{
  __int64 v5; // x20
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  __int64 v16; // x8
  unsigned int v17; // w9
  unsigned int v24; // w11
  __int64 v25; // x4
  __int64 v26; // x5
  __int64 v27; // x6
  __int64 v28; // x7
  __int64 v30; // x21
  __int64 v31; // x8
  int v32; // w9
  __int64 v33; // x21
  __int64 v34; // x8
  __int64 v35; // x8
  void (__fastcall *v36)(_QWORD); // x8
  __int64 v37; // x8
  __int64 v38; // x8
  void (__fastcall *v39)(_QWORD); // x8
  __int64 result; // x0
  __int64 v41; // x21
  __int64 v42; // x8
  __int64 v43; // x8
  void (__fastcall *v44)(_QWORD); // x8
  __int64 v45; // x21
  __int64 v46; // x8
  __int64 v47; // x8
  void (__fastcall *v48)(_QWORD); // x8
  __int64 v49; // x21
  __int64 v50; // x8
  __int64 v51; // x8
  void (__fastcall *v52)(_QWORD); // x8
  unsigned int v54; // w9
  __int64 v55; // [xsp+10h] [xbp-30h] BYREF
  __int64 v56; // [xsp+18h] [xbp-28h]
  __int64 v57; // [xsp+20h] [xbp-20h]
  __int64 v58; // [xsp+28h] [xbp-18h]
  __int64 v59; // [xsp+30h] [xbp-10h]
  __int64 v60; // [xsp+38h] [xbp-8h]

  v5 = a1;
  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = dp_peer_find_hash_find(a1, (int)a3);
  if ( v6 )
  {
    v15 = v6;
    if ( *(_DWORD *)(v6 + 408) != 1 )
      goto LABEL_17;
    v16 = *(_QWORD *)(v6 + 416);
    if ( !v16 )
      goto LABEL_17;
    v17 = *(_DWORD *)(v16 + 40);
    do
    {
      if ( !v17 )
      {
        dp_peer_unref_delete(v6, 7u, v7, v8, v9, v10, v11, v12, v13, v14);
        result = 16;
        goto LABEL_77;
      }
      _X13 = (unsigned int *)(v16 + 40);
      __asm { PRFM            #0x11, [X13] }
      while ( 1 )
      {
        v24 = __ldxr(_X13);
        if ( v24 != v17 )
          break;
        if ( !__stlxr(v17 + 1, _X13) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v24 == v17;
      v17 = v24;
    }
    while ( !_ZF );
    _X8 = (unsigned int *)(v16 + 292);
    while ( 1 )
    {
      __asm { PRFM            #0x11, [X8] }
      do
        v54 = __ldxr(_X8);
      while ( __stxr(v54 + 1, _X8) );
      v30 = *(_QWORD *)(v15 + 416);
      dp_peer_unref_delete(v15, 7u, v7, v8, v9, v10, v11, v12, v13, v14);
      v15 = v30;
      if ( !v30 )
      {
        result = 16;
        goto LABEL_77;
      }
LABEL_17:
      qdf_mem_set((void *)(v15 + 168), 0x30u, 0);
      v31 = *(_QWORD *)v15;
      if ( *(_QWORD *)v15 )
      {
        v32 = *(unsigned __int8 *)(v31 + 2281);
        *(_DWORD *)(v31 + 44) = 0;
        *(_QWORD *)(v31 + 36) = 0;
        *(_QWORD *)(v31 + 28) = 0;
        *(_QWORD *)(v31 + 20) = 0;
        *(_QWORD *)(v31 + 12) = 0;
        qdf_mem_set((void *)(v31 + 2288), (unsigned int)(4072 * v32), 0);
      }
      if ( *(_DWORD *)(v15 + 408) != 2 )
        break;
      v58 = 0;
      v59 = 0;
      v56 = 0;
      v57 = 0;
      v55 = 0;
      dp_get_link_peers_ref_from_mld_peer(v5, v15, &v55);
      if ( !(_BYTE)v59 )
        goto LABEL_76;
      v5 = v55;
      v33 = *(_QWORD *)((*(_QWORD **)((char *)&off_18 + v55))[3] + 8LL);
      qdf_mem_set((void *)(v55 + 168), 0x30u, 0);
      v34 = *(_QWORD *)(v33 + 20112);
      if ( v34 )
      {
        v35 = *(_QWORD *)(v34 + 416);
        if ( v35 && (v36 = *(void (__fastcall **)(_QWORD))(v35 + 160)) != nullptr )
        {
          if ( *((_DWORD *)v36 - 1) != 1810062434 )
            __break(0x8228u);
          v36(v5);
        }
        else
        {
          qdf_trace_msg(
            0x92u,
            8u,
            "%s: callback not registered",
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            "dp_monitor_peer_reset_stats");
        }
      }
      _X8 = (unsigned int *)(unsigned __int8)v59;
      if ( (unsigned __int8)v59 < 2u )
        goto LABEL_85;
      v5 = v56;
      v41 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v56 + 24) + 24LL) + 8LL);
      qdf_mem_set((void *)(v56 + 168), 0x30u, 0);
      v42 = *(_QWORD *)(v41 + 20112);
      if ( v42 )
      {
        v43 = *(_QWORD *)(v42 + 416);
        if ( v43 && (v44 = *(void (__fastcall **)(_QWORD))(v43 + 160)) != nullptr )
        {
          if ( *((_DWORD *)v44 - 1) != 1810062434 )
            __break(0x8228u);
          v44(v5);
        }
        else
        {
          qdf_trace_msg(
            0x92u,
            8u,
            "%s: callback not registered",
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            "dp_monitor_peer_reset_stats");
        }
      }
      _X8 = (unsigned int *)(unsigned __int8)v59;
      if ( (unsigned __int8)v59 < 3u )
        goto LABEL_85;
      v5 = v57;
      v45 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v57 + 24) + 24LL) + 8LL);
      qdf_mem_set((void *)(v57 + 168), 0x30u, 0);
      v46 = *(_QWORD *)(v45 + 20112);
      if ( v46 )
      {
        v47 = *(_QWORD *)(v46 + 416);
        if ( v47 && (v48 = *(void (__fastcall **)(_QWORD))(v47 + 160)) != nullptr )
        {
          if ( *((_DWORD *)v48 - 1) != 1810062434 )
            __break(0x8228u);
          v48(v5);
        }
        else
        {
          qdf_trace_msg(
            0x92u,
            8u,
            "%s: callback not registered",
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            "dp_monitor_peer_reset_stats");
        }
      }
      _X8 = (unsigned int *)(unsigned __int8)v59;
      if ( (unsigned __int8)v59 < 4u )
        goto LABEL_85;
      v5 = v58;
      v49 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v58 + 24) + 24LL) + 8LL);
      qdf_mem_set((void *)(v58 + 168), 0x30u, 0);
      v50 = *(_QWORD *)(v49 + 20112);
      if ( v50 )
      {
        v51 = *(_QWORD *)(v50 + 416);
        if ( v51 && (v52 = *(void (__fastcall **)(_QWORD))(v51 + 160)) != nullptr )
        {
          if ( *((_DWORD *)v52 - 1) != 1810062434 )
            __break(0x8228u);
          v52(v5);
        }
        else
        {
          qdf_trace_msg(
            0x92u,
            8u,
            "%s: callback not registered",
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            "dp_monitor_peer_reset_stats");
        }
      }
      _X8 = (unsigned int *)(unsigned __int8)v59;
      if ( (unsigned __int8)v59 <= 4u )
      {
LABEL_85:
        if ( !(_DWORD)_X8 )
          goto LABEL_76;
        if ( v55 )
        {
          dp_peer_unref_delete(v55, 7u, v7, v8, v9, v10, v11, v12, v13, v14);
          _X8 = (unsigned int *)(unsigned __int8)v59;
        }
        v55 = 0;
        if ( (unsigned int)_X8 < 2 )
          goto LABEL_76;
        if ( v56 )
        {
          dp_peer_unref_delete(v56, 7u, v7, v8, v9, v10, v11, v12, v13, v14);
          _X8 = (unsigned int *)(unsigned __int8)v59;
        }
        v56 = 0;
        if ( (unsigned int)_X8 < 3 )
          goto LABEL_76;
        if ( v57 )
        {
          dp_peer_unref_delete(v57, 7u, v7, v8, v9, v10, v11, v12, v13, v14);
          _X8 = (unsigned int *)(unsigned __int8)v59;
        }
        v57 = 0;
        if ( (unsigned int)_X8 < 4 )
          goto LABEL_76;
        if ( v58 )
        {
          dp_peer_unref_delete(v58, 7u, v7, v8, v9, v10, v11, v12, v13, v14);
          _X8 = (unsigned int *)(unsigned __int8)v59;
        }
        v58 = 0;
        if ( (unsigned int)_X8 <= 4 )
          goto LABEL_76;
      }
      __break(0x5512u);
    }
    v37 = *(_QWORD *)(v5 + 20112);
    if ( v37 )
    {
      v38 = *(_QWORD *)(v37 + 416);
      if ( v38 && (v39 = *(void (__fastcall **)(_QWORD))(v38 + 160)) != nullptr )
      {
        if ( *((_DWORD *)v39 - 1) != 1810062434 )
          __break(0x8228u);
        v39(v15);
      }
      else
      {
        qdf_trace_msg(
          0x92u,
          8u,
          "%s: callback not registered",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "dp_monitor_peer_reset_stats");
      }
    }
LABEL_76:
    dp_peer_unref_delete(v15, 7u, v7, v8, v9, v10, v11, v12, v13, v14);
    result = 0;
  }
  else
  {
    if ( a3 )
    {
      v25 = *a3;
      v26 = a3[1];
      v27 = a3[2];
      v28 = a3[5];
    }
    else
    {
      v27 = 0;
      v25 = 0;
      v26 = 0;
      v28 = 0;
    }
    qdf_trace_msg(
      0x81u,
      5u,
      "%s: fail to find peer:%02x:%02x:%02x:**:**:%02x vdev_id: %u",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "dp_peer_get_tgt_peer_hash_find",
      v25,
      v26,
      v27,
      v28,
      a2);
    result = 16;
  }
LABEL_77:
  _ReadStatusReg(SP_EL0);
  return result;
}
