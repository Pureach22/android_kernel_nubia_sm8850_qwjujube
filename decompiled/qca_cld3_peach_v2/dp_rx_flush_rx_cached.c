__int64 __fastcall dp_rx_flush_rx_cached(
        __int64 result,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x19
  int v12; // w8
  unsigned int v19; // w8
  signed int v20; // w8
  unsigned __int64 StatusReg; // x8
  __int64 v22; // x8
  __int64 v23; // x22
  unsigned __int64 v24; // x8
  __int64 v25; // x8
  unsigned __int64 v26; // x26
  int v27; // w9
  __int64 v28; // x8
  __int64 v29; // x8
  __int64 v30; // x0
  int v31; // w27
  __int64 v32; // x28
  __int64 v33; // x21
  __int64 v34; // x8
  __int64 v35; // x10
  unsigned __int64 v36; // x9
  __int64 v37; // x10
  __int64 v38; // x1
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x28
  __int64 v42; // x21
  __int64 v43; // x8
  __int64 v44; // x10
  __int64 v45; // x8
  unsigned int v48; // w10
  unsigned int v51; // w10
  unsigned int (__fastcall *v52)(__int64, __int64); // [xsp+8h] [xbp-18h]
  __int64 v53[2]; // [xsp+10h] [xbp-10h] BYREF

  v11 = result;
  v53[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_DWORD *)(result + 408);
  v53[0] = 0;
  if ( v12 != 1 || !*(_QWORD *)(result + 416) )
  {
    if ( *(_QWORD *)result )
    {
      _X9 = (unsigned int *)(*(_QWORD *)result + 92LL);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v19 = __ldxr(_X9);
        v20 = v19 + 1;
      }
      while ( __stlxr(v20, _X9) );
      __dmb(0xBu);
      if ( v20 >= 2 )
      {
        _X8 = (unsigned int *)(*(_QWORD *)result + 92LL);
        __asm { PRFM            #0x11, [X8] }
        do
          v48 = __ldxr(_X8);
        while ( __stxr(v48 - 1, _X8) );
      }
      else
      {
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(result + 136);
        }
        else
        {
LABEL_64:
          raw_spin_lock_bh(v11 + 136);
          *(_QWORD *)(v11 + 144) |= 1uLL;
        }
        if ( *(_DWORD *)(v11 + 124) < 2u
          || (v52 = *(unsigned int (__fastcall **)(__int64, __int64))(*(_QWORD *)(v11 + 24) + 168LL)) == nullptr )
        {
          a2 = 1;
          v52 = nullptr;
        }
        v22 = *(_QWORD *)(v11 + 144);
        if ( (v22 & 1) != 0 )
        {
          *(_QWORD *)(v11 + 144) = v22 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v11 + 136);
        }
        else
        {
          raw_spin_unlock(v11 + 136);
        }
        v23 = *(_QWORD *)v11;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (v24 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v24 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v24 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v23 + 120);
        }
        else
        {
          raw_spin_lock_bh(v23 + 120);
          *(_QWORD *)(v23 + 128) |= 1uLL;
        }
        qdf_list_remove_front((_DWORD *)(v23 + 96), v53);
        v25 = v53[0];
        if ( v53[0] )
        {
          v26 = _ReadStatusReg(SP_EL0);
          while ( 1 )
          {
            v27 = *(unsigned __int8 *)(*(_QWORD *)(v25 + 16) + 75LL);
            v28 = *(_QWORD *)(v23 + 128);
            *(_DWORD *)(v23 + 140) -= v27;
            if ( (v28 & 1) != 0 )
            {
              *(_QWORD *)(v23 + 128) = v28 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(v23 + 120);
            }
            else
            {
              raw_spin_unlock(v23 + 120);
            }
            v29 = v53[0];
            v30 = *(_QWORD *)(v53[0] + 16);
            if ( (a2 & 1) != 0 )
              break;
            v36 = *(unsigned int *)(v30 + 48);
            v37 = (v36 >> 18) & 0xF;
            if ( (unsigned int)v37 >= 5 )
            {
LABEL_63:
              __break(0x5512u);
              goto LABEL_64;
            }
            *(_DWORD *)(v30 + 48) = v36 & 0xFE3FFFFF | ((*(_BYTE *)(*(_QWORD *)v11 + v37 + 2221) & 7) << 22);
            v38 = *(_QWORD *)(v29 + 16);
            v39 = *(_QWORD *)(*(_QWORD *)(v11 + 24) + 88LL);
            if ( *((_DWORD *)v52 - 1) != 424933381 )
              __break(0x8228u);
            if ( v52(v39, v38) )
            {
              v40 = *(_QWORD *)(v53[0] + 16);
              if ( v40 )
              {
                v31 = 0;
                v41 = *(_QWORD *)(*(_QWORD *)(v11 + 24) + 24LL);
                while ( 1 )
                {
                  v42 = *(_QWORD *)v40;
                  if ( v41 )
                  {
                    if ( ((*(_QWORD *)(v40 + 72) >> 18) & 0xFuLL) > 7 || (*(_BYTE *)(v40 + 87) & 0xFu) >= 0xA )
                      goto LABEL_63;
                    v43 = v41
                        + 42680
                        + 5472 * ((*(_QWORD *)(v40 + 72) >> 18) & 0xFLL)
                        + 608LL * (*(_BYTE *)(v40 + 87) & 0xF);
                    v44 = *(_QWORD *)(v43 + 256) - 1LL;
                    ++*(_QWORD *)(v43 + 312);
                    *(_QWORD *)(v43 + 256) = v44;
                  }
                  _qdf_nbuf_free(v40);
                  ++v31;
                  v40 = v42;
                  if ( !v42 )
                    goto LABEL_48;
                }
              }
              v31 = 0;
              goto LABEL_48;
            }
LABEL_49:
            _qdf_mem_free(v53[0]);
            v53[0] = 0;
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (*(_DWORD *)(v26 + 16) & 0xF0000) != 0
              || (*(_DWORD *)(v26 + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(v23 + 120);
            }
            else
            {
              raw_spin_lock_bh(v23 + 120);
              *(_QWORD *)(v23 + 128) |= 1uLL;
            }
            qdf_list_remove_front((_DWORD *)(v23 + 96), v53);
            v25 = v53[0];
            if ( !v53[0] )
              goto LABEL_57;
          }
          v31 = 0;
          if ( v30 )
          {
            v32 = *(_QWORD *)(*(_QWORD *)(v11 + 24) + 24LL);
            do
            {
              v33 = *(_QWORD *)v30;
              if ( v32 )
              {
                if ( ((*(_QWORD *)(v30 + 72) >> 18) & 0xFuLL) > 7 || (*(_BYTE *)(v30 + 87) & 0xFu) >= 0xA )
                  goto LABEL_63;
                v34 = v32
                    + 42680
                    + 5472 * ((*(_QWORD *)(v30 + 72) >> 18) & 0xFLL)
                    + 608LL * (*(_BYTE *)(v30 + 87) & 0xF);
                v35 = *(_QWORD *)(v34 + 256) - 1LL;
                ++*(_QWORD *)(v34 + 312);
                *(_QWORD *)(v34 + 256) = v35;
              }
              _qdf_nbuf_free(v30);
              ++v31;
              v30 = v33;
            }
            while ( v33 );
          }
LABEL_48:
          *(_DWORD *)(v23 + 144) = v31;
          goto LABEL_49;
        }
LABEL_57:
        v45 = *(_QWORD *)(v23 + 128);
        if ( (v45 & 1) != 0 )
        {
          *(_QWORD *)(v23 + 128) = v45 & 0xFFFFFFFFFFFFFFFELL;
          result = raw_spin_unlock_bh(v23 + 120);
        }
        else
        {
          result = raw_spin_unlock(v23 + 120);
        }
        _X8 = (unsigned int *)(*(_QWORD *)v11 + 92LL);
        __asm { PRFM            #0x11, [X8] }
        do
          v51 = __ldxr(_X8);
        while ( __stxr(v51 - 1, _X8) );
      }
    }
    else
    {
      result = qdf_trace_msg(
                 0x45u,
                 2u,
                 "%s: txrx_peer NULL!! peer mac_addr(%02x:%02x:%02x:**:**:%02x)",
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 "dp_rx_flush_rx_cached",
                 *(unsigned __int8 *)(result + 44),
                 *(unsigned __int8 *)(result + 45),
                 *(unsigned __int8 *)(result + 46),
                 *(unsigned __int8 *)(result + 49));
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
