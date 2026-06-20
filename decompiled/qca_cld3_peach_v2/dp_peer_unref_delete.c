__int64 __fastcall dp_peer_unref_delete(
        __int64 result,
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
  __int64 v10; // x21
  __int64 v11; // x19
  __int64 *v12; // x20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v23; // x8
  __int64 v24; // x8
  _QWORD *v25; // x9
  _QWORD *v26; // x8
  __int64 v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x8
  __int64 v37; // x8
  void (__fastcall *v38)(_QWORD); // x8
  __int64 v39; // x22
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x8
  char v49; // w8
  __int64 v50; // x3
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned int v61; // w8
  unsigned int v62; // w8
  unsigned int v68; // w10
  __int64 v69; // [xsp+10h] [xbp-20h] BYREF
  __int64 v70; // [xsp+18h] [xbp-18h]
  __int64 v71; // [xsp+20h] [xbp-10h]
  __int64 v72; // [xsp+28h] [xbp-8h]

  v10 = result;
  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(result + 24);
  v12 = *(__int64 **)(*(_QWORD *)(v11 + 24) + 8LL);
  if ( a2 >= 3 )
  {
    if ( a2 >= 0x20 )
    {
      __break(0x5512u);
    }
    else
    {
      _X8 = (unsigned int *)(result + 4LL * a2 + 264);
      __asm { PRFM            #0x11, [X8] }
      do
        v68 = __ldxr(_X8);
      while ( __stlxr(v68 - 1, _X8) );
      __dmb(0xBu);
    }
  }
  _X9 = (unsigned int *)(result + 40);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v61 = __ldxr(_X9);
    v62 = v61 - 1;
  }
  while ( __stlxr(v62, _X9) );
  __dmb(0xBu);
  if ( !v62 )
  {
    qdf_trace_msg(
      0x81u,
      5u,
      "%s: Deleting peer %pK (%02x:%02x:%02x:**:**:%02x)",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "dp_peer_unref_delete",
      result,
      *(unsigned __int8 *)(result + 44),
      *(unsigned __int8 *)(result + 45),
      *(unsigned __int8 *)(result + 46),
      *(unsigned __int8 *)(result + 49));
    wlan_minidump_remove(v14, v15, v16, v17, v18, v19, v20, v21, v10, 520, v12[2]);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v12 + 2367);
    }
    else
    {
      raw_spin_lock_bh(v12 + 2367);
      v12[2368] |= 1uLL;
    }
    v23 = v12[2365];
    if ( v23 )
    {
      while ( v23 != v10 )
      {
        v23 = *(_QWORD *)(v23 + 248);
        if ( !v23 )
          goto LABEL_17;
      }
      v24 = *(_QWORD *)(v10 + 248);
      v25 = *(_QWORD **)(v10 + 256);
      if ( v24 )
        v26 = (_QWORD *)(v24 + 256);
      else
        v26 = v12 + 2366;
      *v26 = v25;
      *v25 = *(_QWORD *)(v10 + 248);
      *(_QWORD *)(v10 + 248) = 0;
      *(_QWORD *)(v10 + 256) = 0;
    }
LABEL_17:
    v27 = v12[2368];
    if ( (v27 & 1) != 0 )
    {
      v12[2368] = v27 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v12 + 2367);
      if ( !*(_QWORD *)(v10 + 216) )
        goto LABEL_20;
    }
    else
    {
      raw_spin_unlock(v12 + 2367);
      if ( !*(_QWORD *)(v10 + 216) )
      {
LABEL_20:
        dp_peer_update_state(v10, 5);
        dp_peer_cleanup(v11, v10);
        v36 = v12[2514];
        if ( v36 )
        {
          v37 = *(_QWORD *)(v36 + 416);
          if ( v37 && (v38 = *(void (__fastcall **)(_QWORD))(v37 + 144)) != nullptr )
          {
            if ( *((_DWORD *)v38 - 1) != -291477605 )
              __break(0x8228u);
            v38(v10);
          }
          else
          {
            qdf_trace_msg(
              0x92u,
              8u,
              "%s: callback not registered",
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              "dp_monitor_peer_detach");
          }
        }
        v70 = 0;
        v71 = 0;
        v69 = 0;
        raw_spin_lock(v10 + 152);
        v39 = *(_QWORD *)v10;
        if ( *(_QWORD *)v10 )
        {
          dp_peer_set_bw(v12, *(_QWORD *)v10, 5);
          v48 = *(_QWORD *)(v10 + 24);
          *(_QWORD *)v10 = 0;
          if ( *(_DWORD *)(v48 + 32) != 3 && (*(_BYTE *)(v10 + 120) & 1) == 0 )
          {
            v49 = *(_BYTE *)(v48 + 59);
            v70 = v10 + 44;
            v50 = *(unsigned __int16 *)(v10 + 16);
            LOBYTE(v69) = v49;
            dp_wdi_event_handler(301, v12, &v69, v50, 0xFFFFFFFFLL);
          }
          if ( *(_DWORD *)(v39 + 112) )
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: list length not equal to zero",
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              "qdf_list_destroy");
          wlan_minidump_remove(v40, v41, v42, v43, v44, v45, v46, v47, v39, 2288, v12[2]);
          _qdf_mem_free(v39);
        }
        raw_spin_unlock(v10 + 152);
        _qdf_mem_free(v10);
        qdf_trace_msg(
          0x81u,
          5u,
          "%s: Deleted peer. Unref vdev %pK, vdev_ref_cnt %d",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          "dp_peer_unref_delete",
          v11,
          *(unsigned int *)(v11 + 43384));
        result = dp_vdev_unref_delete(v12, v11, 17);
        goto LABEL_35;
      }
    }
    DP_PRINT_STATS("AST Stats not available.Enable FEATURE_AST");
    goto LABEL_20;
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
