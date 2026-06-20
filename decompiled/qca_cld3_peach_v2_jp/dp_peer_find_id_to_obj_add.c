__int64 __fastcall dp_peer_find_id_to_obj_add(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned int v6; // w22
  unsigned __int64 StatusReg; // x8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w8
  unsigned int v23; // w10
  __int64 v24; // x9
  __int64 v25; // x8
  __int64 v26; // x8
  unsigned __int64 v27; // x8
  __int64 v28; // x23
  __int64 v29; // x8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x5
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned __int64 v47; // x8
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x8
  __int64 v57; // x8
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x8
  __int64 result; // x0
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  unsigned int v76; // w8
  unsigned int v79; // w10
  __int64 v80; // x8
  __int64 (__fastcall *v81)(_QWORD); // x8
  __int64 v82; // x0
  unsigned int v85; // w9
  unsigned int v88; // w9
  __int64 v89; // [xsp+0h] [xbp-40h]
  __int64 v90; // [xsp+8h] [xbp-38h]
  __int64 v91; // [xsp+10h] [xbp-30h]
  __int64 v92; // [xsp+18h] [xbp-28h]
  __int64 v93; // [xsp+20h] [xbp-20h]

  v6 = (unsigned __int16)a3;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 13256);
  }
  else
  {
    raw_spin_lock_bh(a1 + 13256);
    *(_QWORD *)(a1 + 13264) |= 1uLL;
  }
  *(_WORD *)(a2 + 16) = a3;
  v16 = *(_DWORD *)(a2 + 40);
  do
  {
    if ( !v16 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: unable to get peer ref at MAP mac: %02x:%02x:%02x:**:**:%02x peer_id %u",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "dp_peer_find_id_to_obj_add",
        *(unsigned __int8 *)(a2 + 44),
        *(unsigned __int8 *)(a2 + 45),
        *(unsigned __int8 *)(a2 + 46),
        *(unsigned __int8 *)(a2 + 49),
        v6);
      v66 = *(_QWORD *)(a1 + 13264);
      if ( (v66 & 1) == 0 )
        return raw_spin_unlock(a1 + 13256);
LABEL_56:
      *(_QWORD *)(a1 + 13264) = v66 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(a1 + 13256);
    }
    _X12 = (unsigned int *)(a2 + 40);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v23 = __ldxr(_X12);
      if ( v23 != v16 )
        break;
      if ( !__stlxr(v16 + 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v23 == v16;
    v16 = v23;
  }
  while ( !_ZF );
  _X8 = (unsigned int *)(a2 + 304);
  __asm { PRFM            #0x11, [X8] }
  do
    v85 = __ldxr(_X8);
  while ( __stxr(v85 + 1, _X8) );
  v24 = *(_QWORD *)(a1 + 13088);
  v25 = *(_QWORD *)(v24 + 8LL * (unsigned __int16)a3);
  if ( !v25 )
  {
    *(_QWORD *)(v24 + 8LL * (unsigned __int16)a3) = a2;
    if ( *(_QWORD *)a2 )
      *(_WORD *)(*(_QWORD *)a2 + 8LL) = a3;
    v66 = *(_QWORD *)(a1 + 13264);
    if ( (v66 & 1) == 0 )
      return raw_spin_unlock(a1 + 13256);
    goto LABEL_56;
  }
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: peer %pK(%02x:%02x:%02x:**:**:%02x)map failed, id %d mapped to peer %pK, Stats: peer(map %u unmap %u invalid unm"
    "ap %u) mld per(map %u unmap %u)",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "dp_peer_find_id_to_obj_add",
    a2,
    *(unsigned __int8 *)(a2 + 44),
    *(unsigned __int8 *)(a2 + 45),
    *(unsigned __int8 *)(a2 + 46),
    *(unsigned __int8 *)(a2 + 49),
    v6,
    v25,
    *(_DWORD *)(a1 + 17504),
    *(_DWORD *)(a1 + 17508) - *(_DWORD *)(a1 + 17520),
    *(_DWORD *)(a1 + 17512),
    *(_DWORD *)(a1 + 17516),
    *(_DWORD *)(a1 + 17520));
  v26 = *(_QWORD *)(a1 + 13264);
  if ( (v26 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 13264) = v26 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 13256);
    if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
      goto LABEL_18;
    goto LABEL_20;
  }
  raw_spin_unlock(a1 + 13256);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
    goto LABEL_20;
LABEL_18:
  v27 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v27 + 16) & 0xF0000) != 0 || (*(_DWORD *)(v27 + 16) & 0xFF00) != 0 )
  {
LABEL_20:
    raw_spin_lock(a1 + 13256);
  }
  else
  {
    raw_spin_lock_bh(a1 + 13256);
    *(_QWORD *)(a1 + 13264) |= 1uLL;
  }
  if ( *(_DWORD *)(a1 + 13276) <= v6 )
  {
LABEL_24:
    v28 = 0;
  }
  else
  {
    v28 = *(_QWORD *)(*(_QWORD *)(a1 + 13088) + 8LL * (unsigned __int16)a3);
    if ( v28 )
    {
      if ( *(unsigned __int8 *)(v28 + 380) <= 2u )
      {
        v76 = *(_DWORD *)(v28 + 40);
        while ( v76 )
        {
          _X12 = (unsigned int *)(v28 + 40);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v79 = __ldxr(_X12);
            if ( v79 != v76 )
              break;
            if ( !__stlxr(v76 + 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v79 == v76;
          v76 = v79;
          if ( _ZF )
          {
            _X8 = (unsigned int *)(v28 + 304);
            __asm { PRFM            #0x11, [X8] }
            do
              v88 = __ldxr(_X8);
            while ( __stxr(v88 + 1, _X8) );
            goto LABEL_25;
          }
        }
      }
      goto LABEL_24;
    }
  }
LABEL_25:
  v29 = *(_QWORD *)(a1 + 13264);
  if ( (v29 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 13264) = v29 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 13256);
    if ( !v28 )
      goto LABEL_60;
LABEL_27:
    if ( (*(_BYTE *)(v28 + 120) & 4) != 0 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: old_peer is still valid",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "dp_peer_id_unmap_and_add");
      dp_peer_unref_delete(v28, 0xCu, v68, v69, v70, v71, v72, v73, v74, v75);
      goto LABEL_61;
    }
    LODWORD(v93) = *(unsigned __int8 *)(a2 + 49);
    LODWORD(v92) = *(unsigned __int8 *)(a2 + 46);
    LODWORD(v91) = *(unsigned __int8 *)(a2 + 45);
    LODWORD(v90) = *(unsigned __int8 *)(a2 + 44);
    LODWORD(v89) = *(unsigned __int8 *)(v28 + 49);
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: peer id %d, unmap old peer(%02x:%02x:%02x:**:**:%02x), add new peer(%02x:%02x:%02x:**:**:%02x)",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "dp_peer_id_unmap_and_add",
      v6,
      *(unsigned __int8 *)(v28 + 44),
      *(unsigned __int8 *)(v28 + 45),
      *(unsigned __int8 *)(v28 + 46),
      v89,
      v90,
      v91,
      v92,
      v93);
    dp_rx_peer_unmap_handler(a1, a3, *(unsigned __int8 *)(*(_QWORD *)(v28 + 24) + 59LL), v28 + 44, 0, v38);
    dp_peer_unref_delete(v28, 0xCu, v39, v40, v41, v42, v43, v44, v45, v46);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v47 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v47 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v47 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 13256);
    }
    else
    {
      raw_spin_lock_bh(a1 + 13256);
      *(_QWORD *)(a1 + 13264) |= 1uLL;
    }
    v56 = *(_QWORD *)(a1 + 13088);
    if ( *(_QWORD *)(v56 + 8LL * (unsigned __int16)a3) )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: old_peer still not been unmapped",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "dp_peer_id_unmap_and_add");
      v57 = *(_QWORD *)(a1 + 13264);
      if ( (v57 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 13264) = v57 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 13256);
      }
      else
      {
        raw_spin_unlock(a1 + 13256);
      }
      goto LABEL_61;
    }
    *(_QWORD *)(v56 + 8LL * (unsigned __int16)a3) = a2;
    if ( *(_QWORD *)a2 )
      *(_WORD *)(*(_QWORD *)a2 + 8LL) = a3;
    v80 = *(_QWORD *)(a1 + 13264);
    if ( (v80 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 13264) = v80 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(a1 + 13256);
      if ( !a1 )
        return result;
    }
    else
    {
      result = raw_spin_unlock(a1 + 13256);
      if ( !a1 )
        return result;
    }
    ++*(_DWORD *)(a1 + 17524);
    return result;
  }
  raw_spin_unlock(a1 + 13256);
  if ( v28 )
    goto LABEL_27;
LABEL_60:
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: Fail to get old_peer by id %d",
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    "dp_peer_id_unmap_and_add",
    v6);
LABEL_61:
  *(_WORD *)(a2 + 16) = -1;
  dp_peer_unref_delete(a2, 0xCu, v58, v59, v60, v61, v62, v63, v64, v65);
  v81 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 8) + 208LL);
  if ( v81 )
  {
    if ( *((_DWORD *)v81 - 1) != 1514819199 )
      __break(0x8228u);
    return v81(45);
  }
  else
  {
    v82 = printk(
            &unk_9BB309,
            "0",
            "dp_trigger_recovery",
            "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_internal.h");
    return dump_stack(v82);
  }
}
