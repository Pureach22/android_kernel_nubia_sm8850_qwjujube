void __fastcall dp_tx_nawds_handler(__int64 a1, __int64 a2, __int64 a3, __int64 a4, unsigned __int16 a5)
{
  int v5; // w27
  unsigned __int64 StatusReg; // x8
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 *i; // x28
  __int64 v19; // x24
  int v20; // w25
  unsigned __int16 *v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  char *v30; // x0
  __int64 v31; // x26
  int v32; // w8
  __int64 v33; // x8

  v5 = a5;
  if ( a5 != 0xFFFF )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a2 + 136);
      for ( i = *(__int64 **)(a2 + 120); i; i = (__int64 *)i[7] )
      {
LABEL_9:
        v19 = *i;
        if ( *i && (*(_BYTE *)(v19 + 88) & 3) == 1 )
        {
          if ( *(unsigned __int16 *)(v19 + 8) == v5 )
          {
            qdf_trace_msg(
              0x7Du,
              8u,
              "%s: multicast packet",
              v10,
              v11,
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              "dp_tx_nawds_handler");
            ++*(_DWORD *)(v19 + 2304);
          }
          else
          {
            v20 = *((unsigned __int16 *)i + 8);
            v21 = (unsigned __int16 *)_qdf_nbuf_clone(a4);
            if ( !v21 )
            {
              qdf_trace_msg(
                0x45u,
                2u,
                "%s: nbuf clone failed",
                v22,
                v23,
                v24,
                v25,
                v26,
                v27,
                v28,
                v29,
                "dp_tx_nawds_handler");
              break;
            }
            v30 = dp_tx_send_msdu_single(a2, v21, a3, v20, 0, v22, v23, v24, v25, v26, v27, v28, v29);
            if ( v30 )
            {
              v31 = (__int64)v30;
              qdf_trace_msg(
                0x7Du,
                8u,
                "%s: pkt send failed",
                v10,
                v11,
                v12,
                v13,
                v14,
                v15,
                v16,
                v17,
                "dp_tx_nawds_handler");
              _qdf_nbuf_free(v31);
            }
            else if ( v20 != 65534 )
            {
              ++*(_QWORD *)(v19 + 2272);
              if ( (*(_BYTE *)(a4 + 68) & 4) != 0 )
                v32 = *(unsigned __int16 *)(a4 + 66);
              else
                v32 = 0;
              *(_QWORD *)(v19 + 2280) += (unsigned int)(*(_DWORD *)(a4 + 112) + v32);
            }
          }
        }
      }
    }
    else
    {
      raw_spin_lock_bh(a2 + 136);
      *(_QWORD *)(a2 + 144) |= 1uLL;
      i = *(__int64 **)(a2 + 120);
      if ( i )
        goto LABEL_9;
    }
    v33 = *(_QWORD *)(a2 + 144);
    if ( (v33 & 1) != 0 )
    {
      *(_QWORD *)(a2 + 144) = v33 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a2 + 136);
    }
    else
    {
      raw_spin_unlock(a2 + 136);
    }
  }
}
