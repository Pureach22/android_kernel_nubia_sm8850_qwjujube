__int64 __fastcall dp_tx_desc_alloc(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x29
  __int64 v14; // x30
  unsigned int v15; // w22
  __int64 v17; // x8
  __int64 v18; // x19
  int v19; // w24
  unsigned __int64 StatusReg; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int16 v30; // w8
  __int64 *v31; // x20
  __int64 v32; // x9
  int v33; // w9
  int v34; // w8
  _BOOL4 v36; // w9
  __int64 v37; // x8
  __int64 v39; // x20
  unsigned __int64 v40; // x8
  unsigned __int64 v41; // x8
  __int64 v42; // x4
  __int64 v43; // x2
  __int64 v44; // x1
  int v45; // w8
  __int64 v46; // x22
  _DWORD *v47; // x8
  __int64 v48; // [xsp+8h] [xbp-38h]

  if ( (unsigned __int8)a2 < 7u )
  {
    v48 = v14;
    v15 = a2;
    v17 = a1 + 296LL * (unsigned __int8)a2;
    v18 = v17 + 2304;
    if ( v17 == -2304 )
    {
      v39 = jiffies;
      if ( dp_tx_desc_alloc___last_ticks_88 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: NULL desc pool pool_id %d",
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          "dp_tx_desc_alloc",
          (unsigned __int8)a2,
          v13,
          v14);
        dp_tx_desc_alloc___last_ticks_88 = v39;
      }
      v31 = nullptr;
      ++*(_WORD *)(a1 + 12932);
      return (__int64)v31;
    }
    v19 = *(_DWORD *)(v17 + 2548);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v18 + 256);
      v30 = *(_WORD *)(v18 + 60);
      if ( !v30 )
        goto LABEL_50;
    }
    else
    {
      raw_spin_lock_bh(v18 + 256);
      *(_QWORD *)(v18 + 264) |= 1uLL;
      v30 = *(_WORD *)(v18 + 60);
      if ( !v30 )
        goto LABEL_50;
    }
    if ( (unsigned int)(*(_DWORD *)(v18 + 64) - 7) <= 0xFFFFFFFD )
    {
      v31 = *(__int64 **)(v18 + 8);
      v32 = *v31;
      *(_WORD *)(v18 + 60) = v30 - 1;
      *(_QWORD *)(v18 + 8) = v32;
      *((_BYTE *)v31 + 67) = v15;
      *((_DWORD *)v31 + 8) = 512;
      *((_DWORD *)v31 + 5) = -1412623820;
      v33 = *(unsigned __int16 *)(v18 + 60);
      if ( *(unsigned __int16 *)(v18 + 72) == v33 && (v34 = *(_DWORD *)(v18 + 64)) == 0
        || *(unsigned __int16 *)(v18 + 74) == v33 && (v34 = *(_DWORD *)(v18 + 64), v34 == 2)
        || *(unsigned __int16 *)(v18 + 76) == v33 && (v34 = *(_DWORD *)(v18 + 64), v34 == 3) )
      {
        v36 = 1;
        if ( v19 != 6 )
        {
LABEL_22:
          if ( !v36 )
            goto LABEL_23;
          goto LABEL_40;
        }
      }
      else
      {
        v34 = *(_DWORD *)(v18 + 64);
        v36 = *(unsigned __int16 *)(v18 + 78) == v33 && v34 == 4;
        if ( v34 == 7 )
        {
          dp_tx_adjust_flow_pool_state(a1, v18);
          if ( v19 != 6 )
            goto LABEL_23;
          LOBYTE(v36) = 0;
        }
        else if ( v19 != 6 )
        {
          goto LABEL_22;
        }
      }
      v40 = *(unsigned __int8 *)(a3 + 61);
      if ( (unsigned int)v40 <= 0x9F )
      {
        v41 = v40 >> 5;
        if ( *(_WORD *)(v18 + 2 * v41 + 152) )
        {
          --*(_DWORD *)(v18 + 4 * v41 + 204);
          *((_DWORD *)v31 + 34) = v41;
        }
      }
      v34 = *(_DWORD *)(v18 + 64);
      if ( !v36 )
      {
        if ( !v34 )
          dp_tx_ndp_bw_queues_pause_flow_ctrl(a1, v18, v31);
        goto LABEL_23;
      }
LABEL_40:
      v42 = (unsigned int)v34;
      if ( v34 > 1 )
      {
        switch ( v34 )
        {
          case 4:
            v43 = 12;
            v44 = 11;
            v45 = 1;
            v42 = 3;
            goto LABEL_54;
          case 3:
            v43 = 11;
            v44 = 13;
            v45 = 4;
            v42 = 2;
            goto LABEL_54;
          case 2:
            v43 = 10;
            v44 = 15;
            v45 = 3;
            v42 = 1;
LABEL_54:
            *(_DWORD *)(v18 + 64) = v45;
            *(_QWORD *)(v18 + 8 * v42 + 120) = 1000 * (jiffies / 0xFAuLL) + 4 * (jiffies % 0xFAuLL);
            v47 = *(_DWORD **)(a1 + 12920);
            if ( *(v47 - 1) != 694643930 )
              __break(0x8228u);
            ((void (__fastcall *)(_QWORD, __int64, __int64))v47)(v15, v44, v43);
            goto LABEL_23;
        }
LABEL_47:
        v46 = jiffies;
        if ( dp_tx_desc_alloc___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: pool status is %d!",
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            "dp_tx_desc_alloc",
            (unsigned int)v34,
            v13,
            v48);
          dp_tx_desc_alloc___last_ticks = v46;
        }
        goto LABEL_23;
      }
      if ( !v34 )
      {
        v43 = 9;
        v44 = 16;
        v45 = 2;
        goto LABEL_54;
      }
      if ( v34 != 1 )
        goto LABEL_47;
LABEL_23:
      v37 = *(_QWORD *)(v18 + 264);
      if ( (v37 & 1) != 0 )
      {
        *(_QWORD *)(v18 + 264) = v37 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v18 + 256);
      }
      else
      {
        raw_spin_unlock(v18 + 256);
      }
      return (__int64)v31;
    }
LABEL_50:
    v31 = nullptr;
    ++*(_WORD *)(v18 + 250);
    goto LABEL_23;
  }
  __break(0x5512u);
  return dp_tx_trace_pkt(a1, a2, a3, a4, a5);
}
