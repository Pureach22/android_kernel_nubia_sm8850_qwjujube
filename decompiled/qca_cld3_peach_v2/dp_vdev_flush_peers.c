__int64 __fastcall dp_vdev_flush_peers(__int64 result, char a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 v4; // x20
  __int64 v5; // x23
  __int64 v6; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v8; // x10
  unsigned int v9; // w8
  __int64 v10; // x11
  unsigned int v11; // w12
  unsigned int v18; // w14
  unsigned int v21; // w13
  __int64 v22; // x8
  __int64 v23; // x3
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w24
  __int64 v33; // x22
  unsigned int v34; // w21
  unsigned __int64 v35; // x27
  __int64 v36; // x24
  unsigned int v37; // w8
  unsigned int v40; // w10
  __int64 v41; // x8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int v52; // w9
  __int64 v53; // x8

  v2 = *(_QWORD *)(result + 24);
  v3 = result;
  v4 = *(_QWORD *)(v2 + 8);
  if ( result )
  {
    if ( (a2 & 1) == 0 )
    {
      if ( v2 )
      {
        if ( v4 )
        {
          v5 = *(unsigned int *)(result + 43344);
          result = _qdf_mem_malloc(8 * v5, "dp_vdev_iterate_peer_lock_safe", 507);
          if ( result )
          {
            v6 = result;
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
              || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(v3 + 144);
              v8 = *(_QWORD *)(v3 + 128);
              if ( !v8 )
                goto LABEL_27;
            }
            else
            {
              raw_spin_lock_bh(v3 + 144);
              *(_QWORD *)(v3 + 152) |= 1uLL;
              v8 = *(_QWORD *)(v3 + 128);
              if ( !v8 )
                goto LABEL_27;
            }
            v9 = 0;
            do
            {
              if ( v9 >= (unsigned int)v5 )
                break;
              v10 = *(_QWORD *)(v8 + 56);
              v11 = *(_DWORD *)(v8 + 40);
              while ( v11 )
              {
                _X16 = (unsigned int *)(v8 + 40);
                __asm { PRFM            #0x11, [X16] }
                while ( 1 )
                {
                  v18 = __ldxr(_X16);
                  if ( v18 != v11 )
                    break;
                  if ( !__stlxr(v11 + 1, _X16) )
                  {
                    __dmb(0xBu);
                    break;
                  }
                }
                _ZF = v18 == v11;
                v11 = v18;
                if ( _ZF )
                {
                  _X12 = (unsigned int *)(v8 + 292);
                  __asm { PRFM            #0x11, [X12] }
                  do
                    v21 = __ldxr(_X12);
                  while ( __stxr(v21 + 1, _X12) );
                  *(_QWORD *)(v6 + 8LL * (int)v9++) = v8;
                  break;
                }
              }
              v8 = v10;
            }
            while ( v10 );
LABEL_27:
            v22 = *(_QWORD *)(v3 + 152);
            if ( (v22 & 1) != 0 )
            {
              *(_QWORD *)(v3 + 152) = v22 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(v3 + 144);
              if ( (_DWORD)v5 )
              {
LABEL_29:
                v32 = 0;
                do
                {
                  v33 = *(_QWORD *)(v6 + 8LL * v32);
                  if ( v33 )
                  {
                    if ( (*(_BYTE *)(v33 + 120) & 4) != 0 )
                      dp_peer_delete_wifi3(
                        (_QWORD *)v4,
                        *(unsigned __int8 *)(*(_QWORD *)(v33 + 24) + 59LL),
                        (unsigned __int8 *)(v33 + 44),
                        v24,
                        v25,
                        v26,
                        v27,
                        v28,
                        v29,
                        v30,
                        v31,
                        v23,
                        *(_DWORD *)(v33 + 408));
                    dp_peer_unref_delete(v33, 7u, v24, v25, v26, v27, v28, v29, v30, v31);
                  }
                  ++v32;
                }
                while ( (_DWORD)v5 != v32 );
              }
            }
            else
            {
              raw_spin_unlock(v3 + 144);
              if ( (_DWORD)v5 )
                goto LABEL_29;
            }
            result = _qdf_mem_free(v6);
          }
        }
      }
    }
  }
  if ( *(_DWORD *)(v4 + 13324) )
  {
    v34 = 0;
    v35 = _ReadStatusReg(SP_EL0);
    do
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v35 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v35 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v4 + 13304);
      }
      else
      {
        raw_spin_lock_bh(v4 + 13304);
        *(_QWORD *)(v4 + 13312) |= 1uLL;
      }
      if ( *(_DWORD *)(v4 + 13324) > (unsigned int)(unsigned __int16)v34 )
      {
        v36 = *(_QWORD *)(*(_QWORD *)(v4 + 13136) + 8LL * (unsigned __int16)v34);
        if ( v36 )
        {
          v37 = *(_DWORD *)(v36 + 40);
          while ( v37 )
          {
            _X12 = (unsigned int *)(v36 + 40);
            __asm { PRFM            #0x11, [X12] }
            while ( 1 )
            {
              v40 = __ldxr(_X12);
              if ( v40 != v37 )
                break;
              if ( !__stlxr(v37 + 1, _X12) )
              {
                __dmb(0xBu);
                break;
              }
            }
            _ZF = v40 == v37;
            v37 = v40;
            if ( _ZF )
            {
              _X8 = (unsigned int *)(v36 + 292);
              __asm { PRFM            #0x11, [X8] }
              do
                v52 = __ldxr(_X8);
              while ( __stxr(v52 + 1, _X8) );
              v53 = *(_QWORD *)(v4 + 13312);
              if ( (v53 & 1) != 0 )
              {
                *(_QWORD *)(v4 + 13312) = v53 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(v4 + 13304);
              }
              else
              {
                raw_spin_unlock(v4 + 13304);
              }
              if ( *(_QWORD *)(v36 + 24) == v3 )
              {
                qdf_trace_msg(
                  0x45u,
                  5u,
                  "%s: peer: %02x:%02x:%02x:**:**:%02x is getting unmap",
                  v43,
                  v44,
                  v45,
                  v46,
                  v47,
                  v48,
                  v49,
                  v50,
                  "dp_vdev_flush_peers",
                  *(unsigned __int8 *)(v36 + 44),
                  *(unsigned __int8 *)(v36 + 45),
                  *(unsigned __int8 *)(v36 + 46),
                  *(unsigned __int8 *)(v36 + 49));
                dp_rx_peer_unmap_handler(v4, v34, *(unsigned __int8 *)(v3 + 59), v36 + 44, 0, 0xFFFFFFFFLL);
                if ( *(_DWORD *)(v36 + 408) != 2 )
                  *(_DWORD *)(v36 + 40) = 1;
              }
              result = dp_peer_unref_delete(v36, 7u, v43, v44, v45, v46, v47, v48, v49, v50);
              goto LABEL_40;
            }
          }
        }
      }
      v41 = *(_QWORD *)(v4 + 13312);
      if ( (v41 & 1) != 0 )
      {
        *(_QWORD *)(v4 + 13312) = v41 & 0xFFFFFFFFFFFFFFFELL;
        result = raw_spin_unlock_bh(v4 + 13304);
      }
      else
      {
        result = raw_spin_unlock(v4 + 13304);
      }
LABEL_40:
      ++v34;
    }
    while ( v34 < *(_DWORD *)(v4 + 13324) );
  }
  return result;
}
