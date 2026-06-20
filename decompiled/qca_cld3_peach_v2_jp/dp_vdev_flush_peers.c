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
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  int v31; // w24
  __int64 v32; // x22
  unsigned int v33; // w21
  unsigned __int64 v34; // x27
  __int64 v35; // x24
  unsigned int v36; // w8
  unsigned int v39; // w10
  __int64 v40; // x8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v51; // w9
  __int64 v52; // x8

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
          v5 = *(unsigned int *)(result + 42520);
          result = _qdf_mem_malloc(8 * v5, "dp_vdev_iterate_peer_lock_safe", 507);
          if ( result )
          {
            v6 = result;
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
              || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(v3 + 136);
              v8 = *(_QWORD *)(v3 + 120);
              if ( !v8 )
                goto LABEL_27;
            }
            else
            {
              raw_spin_lock_bh(v3 + 136);
              *(_QWORD *)(v3 + 144) |= 1uLL;
              v8 = *(_QWORD *)(v3 + 120);
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
                  _X12 = (unsigned int *)(v8 + 284);
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
            v22 = *(_QWORD *)(v3 + 144);
            if ( (v22 & 1) != 0 )
            {
              *(_QWORD *)(v3 + 144) = v22 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(v3 + 136);
              if ( (_DWORD)v5 )
              {
LABEL_29:
                v31 = 0;
                do
                {
                  v32 = *(_QWORD *)(v6 + 8LL * v31);
                  if ( v32 )
                  {
                    if ( (*(_BYTE *)(v32 + 120) & 4) != 0 )
                      dp_peer_delete_wifi3(
                        (_QWORD *)v4,
                        *(unsigned __int8 *)(*(_QWORD *)(v32 + 24) + 59LL),
                        (unsigned __int8 *)(v32 + 44));
                    dp_peer_unref_delete(v32, 7u, v23, v24, v25, v26, v27, v28, v29, v30);
                  }
                  ++v31;
                }
                while ( (_DWORD)v5 != v31 );
              }
            }
            else
            {
              raw_spin_unlock(v3 + 136);
              if ( (_DWORD)v5 )
                goto LABEL_29;
            }
            result = _qdf_mem_free(v6);
          }
        }
      }
    }
  }
  if ( *(_DWORD *)(v4 + 13276) )
  {
    v33 = 0;
    v34 = _ReadStatusReg(SP_EL0);
    do
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v34 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v34 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v4 + 13256);
      }
      else
      {
        raw_spin_lock_bh(v4 + 13256);
        *(_QWORD *)(v4 + 13264) |= 1uLL;
      }
      if ( *(_DWORD *)(v4 + 13276) > (unsigned int)(unsigned __int16)v33 )
      {
        v35 = *(_QWORD *)(*(_QWORD *)(v4 + 13088) + 8LL * (unsigned __int16)v33);
        if ( v35 )
        {
          v36 = *(_DWORD *)(v35 + 40);
          while ( v36 )
          {
            _X12 = (unsigned int *)(v35 + 40);
            __asm { PRFM            #0x11, [X12] }
            while ( 1 )
            {
              v39 = __ldxr(_X12);
              if ( v39 != v36 )
                break;
              if ( !__stlxr(v36 + 1, _X12) )
              {
                __dmb(0xBu);
                break;
              }
            }
            _ZF = v39 == v36;
            v36 = v39;
            if ( _ZF )
            {
              _X8 = (unsigned int *)(v35 + 284);
              __asm { PRFM            #0x11, [X8] }
              do
                v51 = __ldxr(_X8);
              while ( __stxr(v51 + 1, _X8) );
              v52 = *(_QWORD *)(v4 + 13264);
              if ( (v52 & 1) != 0 )
              {
                *(_QWORD *)(v4 + 13264) = v52 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(v4 + 13256);
              }
              else
              {
                raw_spin_unlock(v4 + 13256);
              }
              if ( *(_QWORD *)(v35 + 24) == v3 )
              {
                qdf_trace_msg(
                  0x45u,
                  5u,
                  "%s: peer: %02x:%02x:%02x:**:**:%02x is getting unmap",
                  v42,
                  v43,
                  v44,
                  v45,
                  v46,
                  v47,
                  v48,
                  v49,
                  "dp_vdev_flush_peers",
                  *(unsigned __int8 *)(v35 + 44),
                  *(unsigned __int8 *)(v35 + 45),
                  *(unsigned __int8 *)(v35 + 46),
                  *(unsigned __int8 *)(v35 + 49));
                dp_rx_peer_unmap_handler(v4, v33, *(unsigned __int8 *)(v3 + 59), v35 + 44, 0, 0xFFFFFFFFLL);
                *(_DWORD *)(v35 + 40) = 1;
              }
              result = dp_peer_unref_delete(v35, 7u, v42, v43, v44, v45, v46, v47, v48, v49);
              goto LABEL_40;
            }
          }
        }
      }
      v40 = *(_QWORD *)(v4 + 13264);
      if ( (v40 & 1) != 0 )
      {
        *(_QWORD *)(v4 + 13264) = v40 & 0xFFFFFFFFFFFFFFFELL;
        result = raw_spin_unlock_bh(v4 + 13256);
      }
      else
      {
        result = raw_spin_unlock(v4 + 13256);
      }
LABEL_40:
      ++v33;
    }
    while ( v33 < *(_DWORD *)(v4 + 13276) );
  }
  return result;
}
