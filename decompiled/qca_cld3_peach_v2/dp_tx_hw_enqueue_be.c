__int64 __fastcall dp_tx_hw_enqueue_be(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        __int64 a5,
        unsigned __int8 *a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 v18; // x27
  __int64 v19; // x8
  __int64 v20; // x23
  __int64 v21; // x24
  int v22; // w25
  __int16 v23; // w28
  __int64 v24; // x8
  int v25; // w12
  int v26; // w10
  int v27; // w11
  char v28; // w13
  __int64 v29; // x0
  int v30; // w28
  int v31; // w9
  int v32; // w24
  int v33; // w10
  int v34; // w12
  int v35; // w25
  __int64 v36; // x8
  unsigned int v37; // w25
  int v38; // w8
  __int64 v39; // x8
  __int64 v40; // x8
  unsigned __int64 StatusReg; // x8
  int v42; // w9
  int v43; // w8
  __int64 v44; // x9
  __int64 v51; // x9
  unsigned int v52; // w10
  unsigned int v53; // w25
  unsigned int v54; // w22
  __int64 v55; // x8
  unsigned int v56; // w8
  int v58; // w25
  __int64 v59; // x28
  int v60; // w8
  _BOOL8 v61; // x0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  int v70; // w8
  _BOOL8 v71; // x0
  char v72; // w0
  __int64 v73; // [xsp+8h] [xbp-38h]
  int v74; // [xsp+14h] [xbp-2Ch]
  _DWORD v75[2]; // [xsp+18h] [xbp-28h] BYREF
  __int64 v76; // [xsp+20h] [xbp-20h]
  __int64 v77; // [xsp+28h] [xbp-18h]
  __int64 v78; // [xsp+30h] [xbp-10h]
  __int64 v79; // [xsp+38h] [xbp-8h]

  v18 = a2 + 43268;
  v79 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = *(_QWORD *)(a1 + 40);
  v20 = a6[5];
  v77 = 0;
  v78 = 0;
  v76 = 0;
  LODWORD(v21) = *(unsigned __int8 *)(*(_QWORD *)(v19 + 776) + 4 * v20 + 2);
  if ( is_dp_verbose_debug_enabled == 1 )
    goto LABEL_51;
  while ( 1 )
  {
    v22 = *(unsigned __int16 *)(a2 + 78);
    v23 = *(_WORD *)(a2 + 76);
    if ( a5 )
    {
      v60 = *(unsigned __int16 *)(a5 + 4);
      v74 = a4;
      v73 = a5;
      v61 = v60 == 6 || (unsigned __int64)(*(_DWORD *)(a2 + 40) == v60);
      if ( (_dp_assert_always_internal(v61) & 1) != 0
        || (a4 = v74, !*(_WORD *)(v73 + 4))
        && ((v70 = *(_DWORD *)(v73 + 8), v70 != 12) ? (v71 = v70 == *(_DWORD *)v18) : (v71 = 1),
            v72 = _dp_assert_always_internal(v71),
            a4 = v74,
            (v72 & 1) != 0) )
      {
        v54 = 4;
        goto LABEL_48;
      }
    }
    v24 = *(_QWORD *)(a3 + 40);
    v25 = *(unsigned __int8 *)(a3 + 66);
    v27 = *(_DWORD *)(a3 + 32);
    v26 = *(_DWORD *)(a3 + 36);
    v28 = *(_BYTE *)(a2 + 62);
    v29 = *(_QWORD *)(a3 + 8);
    LODWORD(v78) = v22 & 0xFF0FFFFF | ((v23 & 0xF) << 20);
    v30 = (v28 & 3) << 9;
    v31 = BYTE4(v24) | (v26 << 12) | ((v21 & 0xF) << 8);
    v32 = 2 * (v27 & 1);
    v33 = (v27 << 20) & 0x200000 | (v25 << 23);
    v34 = *(unsigned __int16 *)(a3 + 16);
    v75[0] = v24;
    v75[1] = v31;
    v35 = v33 | v34;
    HIDWORD(v76) = a4 << 16;
    LODWORD(v77) = v33 | v34;
    if ( (unsigned int)_qdf_nbuf_get_tx_cksum(v29) == 2
      || (v36 = *(_QWORD *)(*(_QWORD *)(a3 + 8) + 216LL) + *(unsigned int *)(*(_QWORD *)(a3 + 8) + 212LL),
          *(_WORD *)(v36 + 4))
      && (*(_BYTE *)(v36 + 24) & 0x11) != 0 )
    {
      LODWORD(v77) = v35 | 0x1F0000;
    }
    v37 = a6[12];
    LODWORD(v21) = v32 & 0xFFFFFF03 | (4 * (*(_BYTE *)(a2 + 63) & 0x3F));
    v38 = v30 | (*(unsigned __int8 *)(a2 + 59) << 24);
    LODWORD(v76) = v21;
    HIDWORD(v77) = v38;
    if ( v37 != 31 )
    {
      v38 |= (16 * (v37 & 0xF)) | 1;
      HIDWORD(v77) = v38;
    }
    if ( *(char *)(*(_QWORD *)(a3 + 8) + 68LL) < 0 )
    {
      HIDWORD(v77) = v38 | 6;
      LODWORD(v76) = v21 | 0x300;
    }
    v39 = *(_QWORD *)(a2 + 24);
    if ( (*(_BYTE *)(v39 + 95938) & 1) != 0
      || (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v39 + 8) + 40LL) + 732LL) & 1) != 0
      || (v40 = *(_QWORD *)(*(_QWORD *)(a2 + 24) + 8LL), (*(_BYTE *)(v40 + 18728) & 1) != 0)
      || *(_BYTE *)(v18 + 2873)
      || (wlan_cfg_is_peer_jitter_stats_enabled(*(_QWORD *)(v40 + 40)) & 1) != 0 )
    {
      *(_QWORD *)(a3 + 80) = ktime_get_with_offset(0);
      if ( (unsigned int)v20 >= 5 )
        goto LABEL_50;
    }
    else if ( (unsigned int)v20 >= 5 )
    {
      goto LABEL_50;
    }
    v21 = *(_QWORD *)(a1 + 80LL * (unsigned int)v20 + 6800);
    if ( v21 )
    {
      v18 = *(_QWORD *)(a1 + 1128);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v21 + 80);
      }
      else
      {
        raw_spin_lock_bh(v21 + 80);
        *(_QWORD *)(v21 + 88) |= 1uLL;
      }
      v42 = *(_DWORD *)(v21 + 116);
      v43 = **(_DWORD **)(v21 + 128);
      *(_DWORD *)(v21 + 136) = v43;
      if ( v42 )
      {
        if ( (*(_BYTE *)(v21 + 78) & 4) != 0 )
        {
          v44 = *(unsigned int *)(v21 + 120);
          if ( (_DWORD)v44 != v43 )
          {
            if ( *(_QWORD *)(v21 + 16) + 4 * v44 )
            {
              if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v18 + 8) + 40LL) + 844LL) & 0x40) == 0 )
                _dma_sync_single_for_cpu();
              __asm { PRFM            #0, [X28] }
              v43 = *(_DWORD *)(v21 + 136);
            }
          }
        }
      }
      v51 = *(unsigned int *)(v21 + 120);
      v52 = (unsigned int)(*(_DWORD *)(v21 + 44) + v51) % *(_DWORD *)(v21 + 36);
      if ( v52 != v43 )
      {
        v55 = *(_QWORD *)(v21 + 16);
        *(_DWORD *)(v21 + 120) = v52;
        *(_DWORD *)(v21 + 124) = v52;
        if ( v55 + 4 * v51 )
        {
          *(_DWORD *)(a3 + 32) |= 0x20u;
          qdf_mem_copy((void *)(v55 + 4 * v51), v75, 0x20u);
          dp_tx_update_proto_stats(a2, *(_QWORD *)(a3 + 8), (unsigned int)v20, 2);
          v53 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD, unsigned __int8 *, _QWORD))dp_tx_attempt_coalescing)(
                  a1,
                  a2,
                  a3,
                  v37,
                  a6,
                  (unsigned int)v20);
          if ( !a2 )
            goto LABEL_44;
          if ( !a6[94] )
          {
            ++*(_QWORD *)(a2 + 456);
            v56 = *(_BYTE *)(a3 + 65) == 1
                ? *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a3 + 72) + 40LL) + 36LL)
                : *(unsigned __int16 *)(a3 + 16);
            if ( !a6[94] )
            {
              *(_QWORD *)(a2 + 464) += v56;
LABEL_44:
              if ( a1 )
                ++*(_DWORD *)(a1 + 4 * v20 + 13480);
              dp_tx_update_stats(a1, a3, (unsigned int)v20);
              v54 = 0;
LABEL_47:
              dp_tx_ring_access_end_wrapper(a1, v21, v53);
              __isb(0xFu);
              dp_pkt_add_timestamp_0(a2, 1, _ReadStatusReg(CNTVCT_EL0), *(_QWORD *)(a3 + 8));
              goto LABEL_48;
            }
          }
          goto LABEL_50;
        }
      }
      if ( is_dp_verbose_debug_enabled == 1 )
      {
        qdf_trace_msg(
          0x45u,
          8u,
          "%s: TCL ring full ring_id:%d",
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          a14,
          "dp_tx_hw_enqueue_be",
          (unsigned int)v20);
        if ( !a1 )
        {
LABEL_33:
          if ( !a2 )
          {
            v53 = 0;
            v54 = 1;
            goto LABEL_47;
          }
          if ( !a6[94] )
          {
            v53 = 0;
            v54 = 1;
            ++*(_DWORD *)(a2 + 756);
            goto LABEL_47;
          }
          goto LABEL_50;
        }
      }
      else if ( !a1 )
      {
        goto LABEL_33;
      }
      ++*(_DWORD *)(a1 + 4 * v20 + 13520);
      goto LABEL_33;
    }
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Error: Invalid hal_ring\n",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "hal_srng_access_start");
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: HAL RING Access Failed -- %pK",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      "dp_tx_hw_enqueue_be",
      0);
    if ( a1 )
      ++*(_DWORD *)(a1 + 4 * v20 + 13520);
    if ( !a2 )
      break;
    if ( !a6[94] )
    {
      v54 = 1;
      ++*(_DWORD *)(a2 + 756);
      goto LABEL_48;
    }
LABEL_50:
    __break(0x5512u);
LABEL_51:
    v58 = a4;
    v59 = a5;
    qdf_trace_msg(
      0x45u,
      8u,
      "%s: tcl_id %u rbm %u",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "dp_tx_get_rbm_id_be",
      (unsigned int)v20,
      (unsigned int)v21);
    a5 = v59;
    a4 = v58;
  }
  v54 = 1;
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return v54;
}
