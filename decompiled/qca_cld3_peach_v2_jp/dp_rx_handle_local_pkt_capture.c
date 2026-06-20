__int64 __fastcall dp_rx_handle_local_pkt_capture(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 a4, int a5)
{
  __int64 v5; // x29
  __int64 v6; // x30
  __int64 v9; // x26
  __int64 v10; // x24
  unsigned __int64 StatusReg; // x8
  __int64 *i; // x2
  __int64 v15; // x8
  __int64 *v16; // x8
  __int64 v17; // x0
  __int64 v18; // x20
  __int64 v19; // x8
  __int64 v20; // x1
  int v21; // w8
  __int64 v22; // x8
  __int64 *v23; // x8
  __int64 v24; // x8
  int v25; // w9
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  int v34; // w10
  _QWORD *v35; // x0
  _QWORD *v36; // x8
  __int64 v38; // [xsp+8h] [xbp-48h]

  if ( a4 < 3u )
  {
    v38 = v6;
    v9 = *(_QWORD *)(a1 + 95560);
    v10 = v9 + 18528LL * a4;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v10 + 18496);
      if ( a5 != 10 )
      {
LABEL_6:
        if ( a5 != 5 )
        {
          if ( a5 == 1 )
          {
            for ( i = *(__int64 **)(v10 + 18464); i; i = *(__int64 **)(v10 + 18464) )
            {
              v16 = *(__int64 **)(v10 + 18472);
              --*(_DWORD *)(v10 + 18480);
              if ( i == v16 )
              {
                v15 = 0;
                *(_QWORD *)(v10 + 18472) = 0;
              }
              else
              {
                v15 = *i;
              }
              *(_QWORD *)(v10 + 18464) = v15;
              *i = 0;
              dp_rx_mon_send_mpdu(a1, v10 + 8);
            }
            if ( dp_rx_mon_stitch_mpdu(v10 + 8, 0) )
              dp_rx_mon_send_mpdu(a1, v10 + 8);
            *(_BYTE *)(v10 + 18488) = 1;
            v22 = *(_QWORD *)(v10 + 18504);
            if ( (v22 & 1) != 0 )
              goto LABEL_43;
LABEL_40:
            raw_spin_unlock(v10 + 18496);
            return 0;
          }
          goto LABEL_39;
        }
        ++*(_DWORD *)(v10 + 18512);
        v17 = _qdf_nbuf_clone(a3);
        if ( !v17 )
        {
LABEL_39:
          v22 = *(_QWORD *)(v10 + 18504);
          if ( (v22 & 1) == 0 )
            goto LABEL_40;
          goto LABEL_43;
        }
        v18 = v17;
        v19 = *(_QWORD *)(v17 + 40);
        v20 = (unsigned __int16)(*(_WORD *)(a2 + 13296) - *(_WORD *)(v17 + 224) + *(unsigned __int8 *)(v9 + 39316));
        if ( v19 )
          *(_QWORD *)(v17 + 40) = v20 + v19;
        if ( !skb_pull(v17, v20) )
        {
          _qdf_nbuf_free(v18);
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: No header present",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "dp_rx_handle_local_pkt_capture",
            v5,
            v38);
          v22 = *(_QWORD *)(v10 + 18504);
          if ( (v22 & 1) == 0 )
            goto LABEL_40;
LABEL_43:
          *(_QWORD *)(v10 + 18504) = v22 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v10 + 18496);
          return 0;
        }
        if ( (*(_BYTE *)(v18 + 68) & 4) != 0 )
          v21 = *(unsigned __int16 *)(v18 + 66);
        else
          v21 = 0;
        skb_trim(v18, *(unsigned __int16 *)(a2 + 13304) - v21 - (unsigned int)*(unsigned __int8 *)(v9 + 39316));
        *(_QWORD *)v18 = 0;
        if ( *(_QWORD *)(v10 + 18440) )
          v23 = *(__int64 **)(v10 + 18448);
        else
          v23 = (__int64 *)(v10 + 18440);
        *v23 = v18;
        v24 = 18448;
        v25 = *(_DWORD *)(v10 + 18456);
        *(_QWORD *)(v10 + 18448) = v18;
LABEL_38:
        *(_DWORD *)(v10 + 8 + v24) = v25 + 1;
        goto LABEL_39;
      }
    }
    else
    {
      raw_spin_lock_bh(v10 + 18496);
      *(_QWORD *)(v10 + 18504) |= 1uLL;
      if ( a5 != 10 )
        goto LABEL_6;
    }
    v34 = *(unsigned __int8 *)(v10 + 18488);
    ++*(_DWORD *)(v10 + 18516);
    if ( v34 == 1 )
    {
      *(_BYTE *)(v10 + 18488) = 0;
      v22 = *(_QWORD *)(v10 + 18504);
      if ( (v22 & 1) == 0 )
        goto LABEL_40;
      goto LABEL_43;
    }
    v35 = (_QWORD *)dp_rx_mon_stitch_mpdu(v10 + 8, *(_QWORD *)(v10 + 18448));
    if ( !v35 )
      goto LABEL_39;
    *v35 = 0;
    if ( *(_QWORD *)(v10 + 18464) )
      v36 = *(_QWORD **)(v10 + 18472);
    else
      v36 = (_QWORD *)(v10 + 18464);
    *v36 = v35;
    v24 = 18472;
    v25 = *(_DWORD *)(v10 + 18480);
    *(_QWORD *)(v10 + 18472) = v35;
    goto LABEL_38;
  }
  __break(0x5512u);
  return ((__int64 (*)(void))dp_rx_mon_stitch_mpdu)();
}
