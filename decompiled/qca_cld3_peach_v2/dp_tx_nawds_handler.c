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
  __int64 i; // x28
  int v19; // w8
  __int64 *v20; // x9
  __int64 v21; // x24
  int v22; // w25
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 *v32; // x0
  __int64 v33; // x26
  int v34; // w8
  __int64 v35; // x8

  v5 = a5;
  if ( a5 != 0xFFFF )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a2 + 144);
      for ( i = *(_QWORD *)(a2 + 128); i; i = *(_QWORD *)(i + 56) )
      {
LABEL_9:
        v19 = *(_DWORD *)(i + 408);
        if ( v19 != 1 || (v20 = *(__int64 **)(i + 416)) == nullptr )
          v20 = (__int64 *)i;
        v21 = *v20;
        if ( *v20 )
        {
          if ( (*(_BYTE *)(v21 + 88) & 3) == 1 && v19 == 1 )
          {
            v22 = *(unsigned __int16 *)(i + 16);
            if ( !*(_QWORD *)(i + 416) || (*(_BYTE *)(i + 128) & 2) != 0 )
            {
              if ( *(unsigned __int16 *)(v21 + 8) == v5 )
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
                ++*(_DWORD *)(v21 + 2368);
              }
              else
              {
                v23 = _qdf_nbuf_clone(a4);
                if ( !v23 )
                {
                  qdf_trace_msg(
                    0x45u,
                    2u,
                    "%s: nbuf clone failed",
                    v24,
                    v25,
                    v26,
                    v27,
                    v28,
                    v29,
                    v30,
                    v31,
                    "dp_tx_nawds_handler");
                  break;
                }
                v32 = dp_tx_send_msdu_single(a2, v23, a3, v22, 0, v24, v25, v26, v27, v28, v29, v30, v31);
                if ( v32 )
                {
                  v33 = (__int64)v32;
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
                  _qdf_nbuf_free(v33);
                }
                else if ( v22 != 65534 )
                {
                  ++*(_QWORD *)(v21 + 2336);
                  if ( (*(_BYTE *)(a4 + 68) & 4) != 0 )
                    v34 = *(unsigned __int16 *)(a4 + 66);
                  else
                    v34 = 0;
                  *(_QWORD *)(v21 + 2344) += (unsigned int)(*(_DWORD *)(a4 + 112) + v34);
                }
              }
            }
          }
        }
      }
    }
    else
    {
      raw_spin_lock_bh(a2 + 144);
      *(_QWORD *)(a2 + 152) |= 1uLL;
      i = *(_QWORD *)(a2 + 128);
      if ( i )
        goto LABEL_9;
    }
    v35 = *(_QWORD *)(a2 + 152);
    if ( (v35 & 1) != 0 )
    {
      *(_QWORD *)(a2 + 152) = v35 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a2 + 144);
    }
    else
    {
      raw_spin_unlock(a2 + 144);
    }
  }
}
