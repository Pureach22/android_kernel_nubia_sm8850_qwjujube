__int64 __fastcall dp_rx_mon_send_mpdu(
        __int64 result,
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
  __int64 v11; // x20
  __int64 v13; // x24
  unsigned __int64 v14; // x21
  __int64 v16; // x22
  unsigned __int64 StatusReg; // x8
  __int64 v18; // x21
  unsigned int v19; // w8
  unsigned int v26; // w10
  _DWORD *v27; // x8
  __int64 v28; // x0
  double v29; // d0
  unsigned int *v30; // x8
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x8
  __int64 v39; // x23
  unsigned int v42; // w9
  __int64 v43; // x8

  v11 = *(_QWORD *)(result + 8);
  v13 = a2 + 0x4000;
  if ( v11 )
  {
    v14 = *(unsigned __int8 *)(a2 + 1);
    if ( v14 <= 5 )
    {
      v16 = result;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v11 + 18984);
      }
      else
      {
        raw_spin_lock_bh(v11 + 18984);
        *(_QWORD *)(v11 + 18992) |= 1uLL;
      }
      v18 = *(_QWORD *)(v11 + 8 * v14 + 12960);
      if ( v18 )
      {
        v19 = *(_DWORD *)(v18 + 43384);
        while ( v19 )
        {
          _X12 = (unsigned int *)(v18 + 43384);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v26 = __ldxr(_X12);
            if ( v26 != v19 )
              break;
            if ( !__stlxr(v19 + 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v26 == v19;
          v19 = v26;
          if ( _ZF )
          {
            _X8 = (unsigned int *)(v18 + 43472);
            __asm { PRFM            #0x11, [X8] }
            do
              v42 = __ldxr(_X8);
            while ( __stxr(v42 + 1, _X8) );
            v43 = *(_QWORD *)(v11 + 18992);
            if ( (v43 & 1) != 0 )
            {
              *(_QWORD *)(v11 + 18992) = v43 & 0xFFFFFFFFFFFFFFFELL;
              result = raw_spin_unlock_bh(v11 + 18984);
            }
            else
            {
              result = raw_spin_unlock(v11 + 18984);
            }
            if ( *(_QWORD *)(a2 + 8) != v18 )
              goto LABEL_29;
            *(_WORD *)(a2 + 3462) = *(_DWORD *)(a2 + 3264);
            *(_WORD *)(a2 + 3464) = *(_DWORD *)(*(_QWORD *)(v16 + 8) + 1904LL);
            *(_WORD *)(a2 + 3466) = *(_WORD *)(v16 + 95958);
            if ( !(unsigned int)qdf_nbuf_update_radiotap(a2 + 3336, a3, *(_DWORD *)(a3 + 224) - *(_DWORD *)(a3 + 216)) )
            {
              if ( v16 )
                ++*(_DWORD *)(v16 + 404);
              qdf_trace_msg(
                0x45u,
                2u,
                "%s: radiotap_update_err",
                a4,
                a5,
                a6,
                a7,
                a8,
                a9,
                a10,
                a11,
                "dp_rx_mon_send_mpdu");
              goto LABEL_32;
            }
            v27 = *(_DWORD **)(v18 + 43520);
            if ( !v27 )
              goto LABEL_32;
            v27 = *(_DWORD **)v27;
            if ( !v27 )
              goto LABEL_32;
            v28 = *(_QWORD *)(v18 + 88);
            if ( *(v27 - 1) != 1866648346 )
              __break(0x8228u);
            v29 = ((double (__fastcall *)(__int64, __int64, _QWORD))v27)(v28, a3, 0);
            v30 = (unsigned int *)(unsigned int)(*(_DWORD *)(v13 + 2128) + 1);
            *(_DWORD *)(v13 + 2128) = (_DWORD)v30;
            return dp_vdev_unref_delete(v11, v18, 0x15u, v30, v29, v31, v32, v33, v34, v35, v36, v37);
          }
        }
      }
      v38 = *(_QWORD *)(v11 + 18992);
      if ( (v38 & 1) != 0 )
      {
        *(_QWORD *)(v11 + 18992) = v38 & 0xFFFFFFFFFFFFFFFELL;
        result = raw_spin_unlock_bh(v11 + 18984);
      }
      else
      {
        result = raw_spin_unlock(v11 + 18984);
      }
    }
    v18 = 0;
LABEL_29:
    v39 = jiffies;
    v27 = (_DWORD *)(dp_rx_mon_send_mpdu___last_ticks - jiffies);
    if ( dp_rx_mon_send_mpdu___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x45u,
                 5u,
                 "%s: Monitor vdev is invalid !!",
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 "dp_rx_mon_send_mpdu");
      dp_rx_mon_send_mpdu___last_ticks = v39;
    }
    if ( v18 )
LABEL_32:
      result = dp_vdev_unref_delete(v11, v18, 0x15u, v27, a4, a5, a6, a7, a8, a9, a10, a11);
  }
  if ( a3 )
    result = _qdf_nbuf_free(a3);
  ++*(_DWORD *)(v13 + 2132);
  return result;
}
