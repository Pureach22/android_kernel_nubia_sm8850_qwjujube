void __fastcall wlan_pdev_chan_match(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x8
  __int64 v7; // x0
  int is_active; // w0
  __int64 v9; // x8
  const void *v10; // x1
  __int64 v11; // x8
  __int64 v12; // x8
  unsigned __int64 v13; // x9
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  _BYTE *v23; // x9
  __int64 v24; // x20
  _BYTE *v25; // x21
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x9
  __int64 v51; // x21
  __int64 v52; // [xsp+8h] [xbp-28h] BYREF
  __int64 v53; // [xsp+10h] [xbp-20h]
  __int64 v54; // [xsp+18h] [xbp-18h]
  __int64 v55; // [xsp+20h] [xbp-10h]
  __int64 v56; // [xsp+28h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_BYTE *)a3 && *(_QWORD *)(a3 + 8) != a2 )
  {
    v54 = 0;
    v55 = 0;
    v52 = 0;
    v53 = 0;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a2 + 1272);
    }
    else
    {
      raw_spin_lock_bh(a2 + 1272);
      *(_QWORD *)(a2 + 1280) |= 1uLL;
    }
    if ( (unsigned int)wlan_vdev_chan_config_valid(a2) )
      goto LABEL_8;
    is_active = wlan_vdev_mlme_is_active(a2);
    v9 = 40;
    if ( !is_active )
      v9 = 32;
    v10 = *(const void **)(a2 + v9);
    if ( !v10 )
    {
LABEL_8:
      v6 = *(_QWORD *)(a2 + 1280);
      if ( (v6 & 1) != 0 )
      {
        *(_QWORD *)(a2 + 1280) = v6 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a2 + 1272);
        goto LABEL_25;
      }
      v7 = a2 + 1272;
    }
    else
    {
      qdf_mem_copy(&v52, v10, 0x20u);
      v11 = *(_QWORD *)(a2 + 1280);
      if ( (v11 & 1) != 0 )
      {
        *(_QWORD *)(a2 + 1280) = v11 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a2 + 1272);
      }
      else
      {
        raw_spin_unlock(a2 + 1272);
      }
      v12 = *(_QWORD *)(a3 + 8);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v13 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v13 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v13 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v12 + 1272);
      }
      else
      {
        v51 = v12;
        raw_spin_lock_bh(v12 + 1272);
        *(_QWORD *)(v51 + 1280) |= 1uLL;
      }
      v22 = *(_QWORD *)(a3 + 8);
      v23 = (_BYTE *)a3;
      v24 = *(_QWORD *)(v22 + 40);
      if ( BYTE2(v52) != *(unsigned __int8 *)(v24 + 2) || BYTE4(v52) != *(unsigned __int8 *)(v24 + 4) )
      {
        *v23 = 1;
        v25 = v23;
        qdf_trace_msg(
          0x38u,
          8u,
          "%s: ==> iter vdev id: %d: ieee %d, mode %d",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "wlan_pdev_chan_match",
          *(unsigned __int8 *)(a2 + 104));
        qdf_trace_msg(
          0x38u,
          8u,
          "%s: fl %016llx, fl-ext %08x, s1 %d, s2 %d ",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "wlan_pdev_chan_match",
          v53,
          HIWORD(v52),
          BYTE3(v52),
          BYTE4(v52));
        qdf_trace_msg(
          0x38u,
          8u,
          "%s: ==> base vdev id: %d: ieee %d mode %d",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "wlan_pdev_chan_match",
          *(unsigned __int8 *)(*((_QWORD *)v25 + 1) + 104LL),
          *(unsigned __int8 *)(v24 + 2),
          *(unsigned int *)(v24 + 28));
        qdf_trace_msg(
          0x38u,
          8u,
          "%s: fl %016llx, fl-ext %08x s1 %d, s2 %d",
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          "wlan_pdev_chan_match",
          *(_QWORD *)(v24 + 8),
          *(unsigned __int16 *)(v24 + 6),
          *(unsigned __int8 *)(v24 + 3),
          *(unsigned __int8 *)(v24 + 4));
        v22 = *((_QWORD *)v25 + 1);
      }
      v50 = *(_QWORD *)(v22 + 1280);
      if ( (v50 & 1) != 0 )
      {
        *(_QWORD *)(v22 + 1280) = v50 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v22 + 1272);
        goto LABEL_25;
      }
      v7 = v22 + 1272;
    }
    raw_spin_unlock(v7);
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
}
