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
  __int64 v10; // x19
  __int64 v11; // x8
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
  __int64 v36; // x1
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x28
  __int64 v40; // x21
  __int64 v41; // x8
  __int64 v42; // x10
  __int64 v43; // x8
  unsigned int v46; // w10
  unsigned int v49; // w10
  unsigned int (__fastcall *v50)(__int64, __int64); // [xsp+8h] [xbp-18h]
  __int64 v51[2]; // [xsp+10h] [xbp-10h] BYREF

  v10 = result;
  v51[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)result;
  v51[0] = 0;
  if ( v11 )
  {
    _X9 = (unsigned int *)(v11 + 92);
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
        v46 = __ldxr(_X8);
      while ( __stxr(v46 - 1, _X8) );
    }
    else
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(result + 128);
      }
      else
      {
LABEL_60:
        raw_spin_lock_bh(v10 + 128);
        *(_QWORD *)(v10 + 136) |= 1uLL;
      }
      if ( *(_DWORD *)(v10 + 124) < 2u
        || (v50 = *(unsigned int (__fastcall **)(__int64, __int64))(*(_QWORD *)(v10 + 24) + 160LL)) == nullptr )
      {
        a2 = 1;
        v50 = nullptr;
      }
      v22 = *(_QWORD *)(v10 + 136);
      if ( (v22 & 1) != 0 )
      {
        *(_QWORD *)(v10 + 136) = v22 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v10 + 128);
      }
      else
      {
        raw_spin_unlock(v10 + 128);
      }
      v23 = *(_QWORD *)v10;
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
      qdf_list_remove_front((_DWORD *)(v23 + 96), v51);
      v25 = v51[0];
      if ( v51[0] )
      {
        v26 = _ReadStatusReg(SP_EL0);
        do
        {
          v27 = *(unsigned __int8 *)(*(_QWORD *)(v25 + 16) + 75LL);
          v28 = *(_QWORD *)(v23 + 128);
          *(_DWORD *)(v23 + 140) -= v27;
          if ( (v28 & 1) != 0 )
          {
            *(_QWORD *)(v23 + 128) = v28 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v23 + 120);
            v29 = v51[0];
            if ( (a2 & 1) != 0 )
            {
LABEL_24:
              v30 = *(_QWORD *)(v29 + 16);
              if ( v30 )
              {
                v31 = 0;
                v32 = *(_QWORD *)(*(_QWORD *)(v10 + 24) + 24LL);
                while ( 1 )
                {
                  v33 = *(_QWORD *)v30;
                  if ( v32 )
                  {
                    if ( ((*(_QWORD *)(v30 + 72) >> 18) & 0xFuLL) > 7 || (*(_BYTE *)(v30 + 87) & 0xFu) >= 0xA )
                      goto LABEL_59;
                    v34 = v32
                        + 41856
                        + 5472 * ((*(_QWORD *)(v30 + 72) >> 18) & 0xFLL)
                        + 608LL * (*(_BYTE *)(v30 + 87) & 0xF);
                    v35 = *(_QWORD *)(v34 + 256) - 1LL;
                    ++*(_QWORD *)(v34 + 312);
                    *(_QWORD *)(v34 + 256) = v35;
                  }
                  _qdf_nbuf_free(v30);
                  ++v31;
                  v30 = v33;
                  if ( !v33 )
                    goto LABEL_45;
                }
              }
LABEL_44:
              v31 = 0;
LABEL_45:
              *(_DWORD *)(v23 + 144) = v31;
              goto LABEL_46;
            }
          }
          else
          {
            raw_spin_unlock(v23 + 120);
            v29 = v51[0];
            if ( (a2 & 1) != 0 )
              goto LABEL_24;
          }
          v36 = *(_QWORD *)(v29 + 16);
          v37 = *(_QWORD *)(*(_QWORD *)(v10 + 24) + 88LL);
          if ( *((_DWORD *)v50 - 1) != 424933381 )
            __break(0x8228u);
          if ( v50(v37, v36) )
          {
            v38 = *(_QWORD *)(v51[0] + 16);
            if ( v38 )
            {
              v31 = 0;
              v39 = *(_QWORD *)(*(_QWORD *)(v10 + 24) + 24LL);
              while ( 1 )
              {
                v40 = *(_QWORD *)v38;
                if ( v39 )
                {
                  if ( ((*(_QWORD *)(v38 + 72) >> 18) & 0xFuLL) > 7 || (*(_BYTE *)(v38 + 87) & 0xFu) >= 0xA )
                  {
LABEL_59:
                    __break(0x5512u);
                    goto LABEL_60;
                  }
                  v41 = v39
                      + 41856
                      + 5472 * ((*(_QWORD *)(v38 + 72) >> 18) & 0xFLL)
                      + 608LL * (*(_BYTE *)(v38 + 87) & 0xF);
                  v42 = *(_QWORD *)(v41 + 256) - 1LL;
                  ++*(_QWORD *)(v41 + 312);
                  *(_QWORD *)(v41 + 256) = v42;
                }
                _qdf_nbuf_free(v38);
                ++v31;
                v38 = v40;
                if ( !v40 )
                  goto LABEL_45;
              }
            }
            goto LABEL_44;
          }
LABEL_46:
          _qdf_mem_free(v51[0]);
          v51[0] = 0;
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
          qdf_list_remove_front((_DWORD *)(v23 + 96), v51);
          v25 = v51[0];
        }
        while ( v51[0] );
      }
      v43 = *(_QWORD *)(v23 + 128);
      if ( (v43 & 1) != 0 )
      {
        *(_QWORD *)(v23 + 128) = v43 & 0xFFFFFFFFFFFFFFFELL;
        result = raw_spin_unlock_bh(v23 + 120);
      }
      else
      {
        result = raw_spin_unlock(v23 + 120);
      }
      _X8 = (unsigned int *)(*(_QWORD *)v10 + 92LL);
      __asm { PRFM            #0x11, [X8] }
      do
        v49 = __ldxr(_X8);
      while ( __stxr(v49 - 1, _X8) );
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
  _ReadStatusReg(SP_EL0);
  return result;
}
