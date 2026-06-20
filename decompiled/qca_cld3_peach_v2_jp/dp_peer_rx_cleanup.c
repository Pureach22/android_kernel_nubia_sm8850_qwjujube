void __fastcall dp_peer_rx_cleanup(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  unsigned int v11; // w20
  __int64 v12; // x26
  __int64 v13; // x27
  const char *v14; // x21
  unsigned __int64 StatusReg; // x28
  unsigned __int16 *v16; // x24
  __int64 v17; // x22
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x8
  __int64 v35; // x23
  __int64 v36; // x25
  __int64 v37; // x8
  __int64 v38; // x8
  __int64 v39; // x24
  __int64 v40; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned __int64 v49; // x22
  const char *v50; // x28
  __int64 v51; // x21
  __int64 v52; // x25
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x8
  __int64 v62; // [xsp+0h] [xbp-B0h]
  _QWORD v63[13]; // [xsp+8h] [xbp-A8h] BYREF
  int v64; // [xsp+70h] [xbp-40h]
  _QWORD v65[7]; // [xsp+78h] [xbp-38h] BYREF

  v65[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)a10 )
  {
    qdf_trace_msg(0x45u, 5u, "%s: Remove tids for peer: %pK", a1, a2, a3, a4, a5, a6, a7, a8, "dp_peer_rx_cleanup", a10);
    v11 = 0;
    v12 = 128;
    v13 = 96;
    v14 = "dp_rx_tid_delete_wifi3";
    StatusReg = _ReadStatusReg(SP_EL0);
    do
    {
      v16 = *(unsigned __int16 **)a10;
      v17 = *(_QWORD *)(a10 + 88);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(&v16[v12 - 4]);
        if ( (*(_BYTE *)(a10 + 120) & 1) != 0 )
          goto LABEL_7;
      }
      else
      {
        raw_spin_lock_bh(&v16[v12 - 4]);
        *(_QWORD *)&v16[v12] |= 1uLL;
        if ( (*(_BYTE *)(a10 + 120) & 1) != 0 )
        {
LABEL_7:
          if ( *(_DWORD *)(*(_QWORD *)(a10 + 24) + 32LL) != 3 )
            goto LABEL_9;
        }
      }
      dp_rx_defrag_waitlist_remove(*(unsigned __int16 **)a10, v11, v18, v19, v20, v21, v22, v23, v24, v25);
      dp_rx_reorder_flush_frag(*(_QWORD *)a10, v11, v26, v27, v28, v29, v30, v31, v32, v33);
LABEL_9:
      v34 = *(_QWORD *)&v16[v12];
      if ( (v34 & 1) != 0 )
      {
        *(_QWORD *)&v16[v12] = v34 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(&v16[v12 - 4]);
      }
      else
      {
        raw_spin_unlock(&v16[v12 - 4]);
      }
      v35 = v17 + v13 - 8;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v17 + v13 - 8);
      }
      else
      {
        raw_spin_lock_bh(v17 + v13 - 8);
        *(_QWORD *)(v17 + v13) |= 1uLL;
      }
      v36 = *(_QWORD *)(a10 + 88);
      if ( !*(_QWORD *)(v36 + v13 - 64) )
        goto LABEL_18;
      v37 = *(_QWORD *)(a10 + 24);
      memset(v63, 0, sizeof(v63));
      v38 = *(_QWORD *)(v37 + 24);
      memset(v65, 0, 40);
      v39 = *(_QWORD *)(v38 + 8);
      v64 = 0;
      v40 = _qdf_mem_malloc(0xB0u, v14, 1155);
      if ( v40 )
      {
        v62 = v17;
        v49 = StatusReg;
        v50 = v14;
        v51 = v36 + v13;
        v52 = v40;
        memcpy((void *)(v40 + 24), (const void *)(v51 - 96), 0x90u);
        *(_BYTE *)(v52 + 168) = 0;
        qdf_mem_set(v65, 0x28u, 0);
        HIDWORD(v63[0]) = 0;
        dp_rx_tid_delete_cb(v39, v52, v63, v53, v54, v55, v56, v57, v58, v59, v60);
        *(_QWORD *)(v51 - 64) = 0;
        *(_DWORD *)(v51 - 32) = 0;
        *(_QWORD *)(v51 - 40) = 0;
        v14 = v50;
        StatusReg = v49;
        v17 = v62;
LABEL_18:
        v61 = *(_QWORD *)(v17 + v13);
        if ( (v61 & 1) != 0 )
          goto LABEL_23;
        goto LABEL_19;
      }
      qdf_trace_msg(
        0x81u,
        2u,
        "%s: %pK: malloc failed for freedesc: tid %d",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v14,
        v39,
        v11);
      v61 = *(_QWORD *)(v17 + v13);
      if ( (v61 & 1) != 0 )
      {
LABEL_23:
        *(_QWORD *)(v17 + v13) = v61 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v35);
        goto LABEL_20;
      }
LABEL_19:
      raw_spin_unlock(v35);
LABEL_20:
      v13 += 144;
      ++v11;
      v12 += 60;
    }
    while ( v13 != 2544 );
  }
  _ReadStatusReg(SP_EL0);
}
