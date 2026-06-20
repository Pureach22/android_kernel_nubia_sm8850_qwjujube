__int64 __fastcall wlan_crypto_getkey(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int16 v11; // w24
  unsigned __int64 StatusReg; // x8
  __int64 v16; // x8
  __int64 v17; // x22
  __int64 v18; // x8
  __int64 v19; // x26
  __int64 v20; // x25
  int v21; // w27
  __int64 peer_by_mac_n_vdev; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x22
  __int64 v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned __int8 *v41; // x23
  __int64 v42; // x8
  const char *v43; // x2
  __int64 result; // x0
  __int64 v45; // x0
  __int16 v46; // w8
  bool v47; // zf
  unsigned __int8 *v48; // x8
  int v49; // w8
  __int16 v50; // w2
  unsigned int v51; // w19
  __int64 *v52; // x1
  _DWORD *v53; // x8
  _DWORD *v54; // x8
  __int64 v55; // x2
  __int64 v56; // [xsp+0h] [xbp-10h] BYREF
  __int64 v57; // [xsp+8h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  WORD2(v56) = -1;
  LODWORD(v56) = -1;
  if ( !a2 )
  {
    v43 = "%s: req_key NULL";
LABEL_19:
    qdf_trace_msg(0x1Cu, 2u, v43, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_crypto_getkey", v56, v57);
    goto LABEL_20;
  }
  v11 = *(_WORD *)(a2 + 6);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 168);
  }
  else
  {
    raw_spin_lock_bh(a1 + 168);
    a1[169] |= 1uLL;
  }
  qdf_mem_copy(&v56, (char *)a1 + 74, 6u);
  v16 = a1[27];
  if ( !v16 || (v17 = *(_QWORD *)(v16 + 80)) == 0 )
  {
    v42 = a1[169];
    if ( (v42 & 1) != 0 )
    {
      a1[169] = v42 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 168);
    }
    else
    {
      raw_spin_unlock(a1 + 168);
    }
    v43 = "%s: psoc NULL";
    goto LABEL_19;
  }
  v18 = a1[169];
  if ( (v18 & 1) == 0 )
  {
    raw_spin_unlock(a1 + 168);
    v19 = *(_QWORD *)(v17 + 2128);
    if ( v19 )
      goto LABEL_10;
LABEL_53:
    v43 = "%s: tx_ops is NULL";
    goto LABEL_19;
  }
  a1[169] = v18 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 168);
  v19 = *(_QWORD *)(v17 + 2128);
  if ( !v19 )
    goto LABEL_53;
LABEL_10:
  v20 = *(_QWORD *)(v17 + 2136);
  if ( !v20 )
  {
    v43 = "%s: rx_ops is NULL";
    goto LABEL_19;
  }
  v21 = *(unsigned __int16 *)(a3 + 4) ^ 0xFFFF | ~*(_DWORD *)a3;
  if ( !v21 )
  {
    v45 = ((__int64 (__fastcall *)(_QWORD *, _QWORD))wlan_crypto_vdev_getkey)(a1, *(unsigned __int16 *)(a2 + 2));
    if ( v45 )
    {
      v41 = (unsigned __int8 *)v45;
      v31 = 0;
      goto LABEL_25;
    }
LABEL_20:
    result = 4;
    goto LABEL_21;
  }
  peer_by_mac_n_vdev = wlan_objmgr_get_peer_by_mac_n_vdev(v17, *(unsigned __int8 *)(a1[27] + 40LL), &v56, a3, 19);
  if ( !peer_by_mac_n_vdev )
  {
    qdf_trace_msg(0x1Cu, 2u, "%s: peer NULL", v23, v24, v25, v26, v27, v28, v29, v30, "wlan_crypto_getkey", v56, v57);
    result = 17;
    goto LABEL_21;
  }
  v31 = peer_by_mac_n_vdev;
  v32 = ((__int64 (__fastcall *)(__int64, _QWORD))wlan_crypto_peer_getkey)(
          peer_by_mac_n_vdev,
          *(unsigned __int16 *)(a2 + 2));
  if ( !v32 )
  {
    qdf_trace_msg(0x1Cu, 2u, "%s: Key is NULL", v33, v34, v35, v36, v37, v38, v39, v40, "wlan_crypto_getkey", v56, v57);
    v51 = 4;
LABEL_50:
    wlan_objmgr_peer_release_ref(v31, 19);
    result = v51;
    goto LABEL_21;
  }
  v41 = (unsigned __int8 *)v32;
LABEL_25:
  if ( v41[1] == 1 )
  {
    qdf_mem_copy((void *)(a2 + 32), v41 + 384, *v41);
    *(_BYTE *)(a2 + 4) = *v41;
    v46 = *((_WORD *)v41 + 2);
    *(_WORD *)(a2 + 2) = v46;
    v47 = (v46 & 0xFFFC | 2) == 6;
    v48 = v41;
    *(_WORD *)(a2 + 6) = *((_WORD *)v41 + 1);
    if ( v47 || (v48 = *((unsigned __int8 **)v41 + 4)) != nullptr )
    {
      v49 = *((_DWORD *)v48 + 2);
      *(_BYTE *)a2 = v49;
      if ( (unsigned __int8)v49 == 4 )
      {
        qdf_mem_copy((void *)(a2 + 80), v41 + 80, 0x10u);
        qdf_mem_copy((void *)(a2 + 96), v41 + 64, 0x10u);
      }
      if ( (v11 & 0x400) != 0 )
      {
        v50 = *(_WORD *)(a2 + 2);
        if ( (unsigned __int16)(v50 - 1) >= 2u )
        {
          if ( !v21 && (v50 & 0xFFFE) == 6 )
            goto LABEL_38;
        }
        else if ( !v21 )
        {
LABEL_38:
          v52 = &v56;
LABEL_40:
          v53 = *(_DWORD **)(v19 + 744);
          if ( v53 )
          {
            if ( *(v53 - 1) != -1033694463 )
              __break(0x8228u);
            ((void (__fastcall *)(_QWORD *, __int64 *))v53)(a1, v52);
          }
          v54 = *(_DWORD **)(v20 + 368);
          if ( v54 )
          {
            v55 = *(unsigned __int16 *)(a2 + 2);
            if ( *(v54 - 1) != 1035671014 )
              __break(0x8228u);
            ((void (__fastcall *)(_QWORD *, __int64, __int64))v54)(a1, a3, v55);
          }
          qdf_mem_copy((void *)(a2 + 24), v41 + 96, 8u);
          qdf_mem_copy((void *)(a2 + 16), v41 + 104, 8u);
          goto LABEL_49;
        }
        v52 = (__int64 *)a3;
        goto LABEL_40;
      }
    }
  }
LABEL_49:
  v51 = 0;
  result = 0;
  if ( v31 )
    goto LABEL_50;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
