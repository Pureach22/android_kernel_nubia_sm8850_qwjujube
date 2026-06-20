__int64 __fastcall wlan_crypto_set_peer_wep_keys(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x27
  int v12; // w20
  unsigned __int64 StatusReg; // x8
  __int64 v16; // x9
  __int64 v17; // x8
  _BYTE *comp_private_obj; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  _BYTE *v27; // x21
  __int64 bsspeer; // x22
  __int64 v29; // x0
  __int64 v30; // x23
  __int64 v31; // x25
  __int64 v32; // x22
  __int64 v33; // x26
  _WORD *v34; // x0
  _WORD *v35; // x24
  __int16 v36; // w8
  _DWORD *v37; // x8
  __int64 v38; // x3
  _DWORD *v39; // x8
  __int64 v40; // x3
  __int64 result; // x0
  const char *v42; // x2
  unsigned int v43; // w1
  const char *v44; // x2
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v53; // w19
  __int64 v54; // [xsp+0h] [xbp-20h]
  __int64 v55; // [xsp+8h] [xbp-18h]
  __int64 v56; // [xsp+10h] [xbp-10h]

  if ( !a1 )
    return 29;
  if ( !a2 )
    goto LABEL_36;
  v10 = *(_QWORD *)(a1 + 216);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    v44 = "%s: psoc NULL";
LABEL_39:
    qdf_trace_msg(0x1Cu, 2u, v44, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_crypto_set_peer_wep_keys");
    return 29;
  }
  v12 = *(_DWORD *)(a1 + 16);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a2 + 768);
    v16 = *(_QWORD *)(a2 + 776);
    v17 = a2;
    if ( (v16 & 1) == 0 )
    {
LABEL_9:
      raw_spin_unlock(v17 + 768);
      goto LABEL_10;
    }
  }
  else
  {
    raw_spin_lock_bh(a2 + 768);
    v17 = a2;
    v16 = *(_QWORD *)(a2 + 776) | 1LL;
    *(_QWORD *)(a2 + 776) = v16;
    if ( (v16 & 1) == 0 )
      goto LABEL_9;
  }
  *(_QWORD *)(v17 + 776) = v16 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(v17 + 768);
LABEL_10:
  comp_private_obj = (_BYTE *)wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: crypto_priv NULL",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "wlan_crypto_vdev_get_comp_params");
    v44 = "%s: crypto_priv NULL";
    goto LABEL_39;
  }
  v27 = comp_private_obj;
  if ( (*comp_private_obj & 8) != 0 )
    return 4;
  bsspeer = a2;
  if ( !v12 )
  {
    bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a1, 19);
    if ( !bsspeer )
    {
LABEL_36:
      v42 = "%s: peer NULL";
      v43 = 8;
      goto LABEL_37;
    }
  }
  v29 = wlan_objmgr_peer_get_comp_private_obj(bsspeer, 14);
  if ( !v29 )
  {
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: crypto_priv NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_crypto_peer_get_comp_params");
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: sta priv is null",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "wlan_crypto_set_peer_wep_keys");
    result = 4;
LABEL_46:
    if ( !v12 )
    {
      v53 = result;
      wlan_objmgr_peer_release_ref(bsspeer, 19);
      return v53;
    }
    return result;
  }
  v30 = 0;
  v54 = bsspeer;
  v55 = v29;
  v56 = v29 + 288;
  while ( 1 )
  {
    v31 = *(_QWORD *)&v27[8 * v30 + 288];
    if ( !v31 )
      goto LABEL_16;
    if ( *(_BYTE *)(v31 + 1) != 1 )
      goto LABEL_16;
    v32 = *(_QWORD *)(v31 + 32);
    if ( !v32 || *(_DWORD *)(v32 + 8) )
      goto LABEL_16;
    v33 = *(_QWORD *)(v11 + 2128);
    if ( !v33 )
      break;
    v34 = (_WORD *)_qdf_mem_malloc(0x1B0u, "wlan_crypto_set_peer_wep_keys", 3819);
    if ( !v34 )
    {
      result = 2;
      goto LABEL_44;
    }
    v35 = v34;
    *(_QWORD *)(v56 + 8 * v30) = v34;
    qdf_mem_copy(v34, (const void *)v31, 0x1B0u);
    v36 = v35[1];
    v35[1] = v36 & 0xFF7F;
    if ( v30 == (unsigned __int8)v27[420] )
    {
      v35[1] = v36 | 0x80;
      *(_BYTE *)(v55 + 420) = v27[420];
    }
    if ( v12 == 5 || !v12 )
    {
      v37 = *(_DWORD **)(v33 + 712);
      if ( v37 )
      {
        v38 = *(unsigned int *)(v32 + 8);
        if ( *(v37 - 1) != -871156935 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _WORD *, __int64, __int64))v37)(a1, v35, a2 + 48, v38);
      }
    }
    v35[1] &= ~4u;
    v39 = *(_DWORD **)(v33 + 712);
    if ( v39 )
    {
      v40 = *(unsigned int *)(v32 + 8);
      if ( *(v39 - 1) != -871156935 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _WORD *, __int64, __int64))v39)(a1, v35, a2 + 48, v40);
    }
LABEL_16:
    if ( ++v30 == 4 )
    {
      result = 0;
LABEL_44:
      bsspeer = v54;
      goto LABEL_46;
    }
  }
  v42 = "%s: tx_ops is NULL";
  v43 = 2;
LABEL_37:
  qdf_trace_msg(0x1Cu, v43, v42, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_crypto_set_peer_wep_keys", v54);
  return 4;
}
