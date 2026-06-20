__int64 __fastcall dp_txrx_nss_request(__int64 a1, unsigned __int8 a2, _DWORD **a3)
{
  __int64 v6; // x0
  _DWORD *v7; // x19
  unsigned int v8; // w25
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x23
  unsigned __int64 StatusReg; // x8
  _DWORD *v19; // x24
  unsigned int v21; // w8
  unsigned int v27; // w10
  unsigned int *v28; // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x8
  __int64 v38; // x21
  unsigned int v42; // w9
  __int64 v43; // x8

  v6 = _qdf_mem_malloc(0xA428u, "dp_txrx_nss_request", 11526);
  if ( v6 )
  {
    v7 = (_DWORD *)v6;
    v8 = 1;
    if ( !(unsigned int)dp_txrx_get_vdev_stats(a1, a2, v6, 1) )
    {
      **a3 = v7[751];
      (*a3)[1] = v7[1377];
      *a3[1] = v7[752];
      a3[1][1] = v7[1378];
      if ( *(_BYTE *)(a1 + 20047) == 1 )
      {
        v17 = *(_QWORD *)(a1 + 72);
        if ( (*(_BYTE *)(v17 + 95416) & 1) != 0 )
        {
          v8 = 6;
        }
        else
        {
          if ( a2 <= 5u )
          {
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
              || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(a1 + 18928);
            }
            else
            {
              raw_spin_lock_bh(a1 + 18928);
              *(_QWORD *)(a1 + 18936) |= 1uLL;
            }
            v19 = *(_DWORD **)(a1 + 8LL * a2 + 12912);
            if ( v19 )
            {
              _X27 = v19 + 10640;
              v21 = v19[10640];
              while ( v21 )
              {
                __asm { PRFM            #0x11, [X27] }
                while ( 1 )
                {
                  v27 = __ldxr(_X27);
                  if ( v27 != v21 )
                    break;
                  if ( !__stlxr(v21 + 1, _X27) )
                  {
                    __dmb(0xBu);
                    break;
                  }
                }
                _ZF = v27 == v21;
                v21 = v27;
                if ( _ZF )
                {
                  _X8 = v19 + 10648;
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v42 = __ldxr(_X8);
                  while ( __stxr(v42 + 1, _X8) );
                  v43 = *(_QWORD *)(a1 + 18936);
                  if ( (v43 & 1) != 0 )
                  {
                    *(_QWORD *)(a1 + 18936) = v43 & 0xFFFFFFFFFFFFFFFELL;
                    raw_spin_unlock_bh(a1 + 18928);
                  }
                  else
                  {
                    raw_spin_unlock(a1 + 18928);
                  }
                  *(_BYTE *)(v17 + 95416) = 1;
                  qdf_event_reset(v17 + 95376);
                  v8 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, __int64, _BYTE))dp_h2t_ext_stats_msg_send)(
                         v17,
                         69,
                         (unsigned __int8)(2 * a2) | 1u,
                         0,
                         0,
                         0,
                         0,
                         128,
                         0);
                  if ( !v8 )
                  {
                    v8 = qdf_wait_single_event(v17 + 95376, 0x64u);
                    if ( !v8 )
                    {
                      **a3 = v19[11347];
                      v28 = (unsigned int *)(unsigned int)v19[11348];
                      *a3[1] = (_DWORD)v28;
                    }
                  }
                  dp_vdev_unref_delete(a1, (__int64)v19, 7u, v28, v29, v30, v31, v32, v33, v34, v35, v36);
                  *(_BYTE *)(v17 + 95416) = 0;
                  goto LABEL_34;
                }
              }
            }
            v37 = *(_QWORD *)(a1 + 18936);
            if ( (v37 & 1) != 0 )
            {
              *(_QWORD *)(a1 + 18936) = v37 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(a1 + 18928);
            }
            else
            {
              raw_spin_unlock(a1 + 18928);
            }
          }
          v38 = jiffies;
          if ( dp_tx_get_fw_nss_stats___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x45u,
              2u,
              "%s: unable to get vdev for vdev id %d",
              v9,
              v10,
              v11,
              v12,
              v13,
              v14,
              v15,
              v16,
              "dp_tx_get_fw_nss_stats",
              a2);
            dp_tx_get_fw_nss_stats___last_ticks = v38;
          }
          v8 = 4;
        }
      }
      else
      {
        v8 = 0;
      }
    }
LABEL_34:
    _qdf_mem_free((__int64)v7);
  }
  else
  {
    return 2;
  }
  return v8;
}
