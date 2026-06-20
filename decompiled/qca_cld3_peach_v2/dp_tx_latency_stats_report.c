__int64 __fastcall dp_tx_latency_stats_report(__int64 result, __int64 a2)
{
  __int64 v2; // x20
  unsigned __int64 v4; // x8
  __int64 v5; // x26
  __int64 v6; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x22
  __int64 v16; // x0
  unsigned int v17; // w8
  unsigned int v24; // w10
  int v26; // w8
  _QWORD *v27; // x8
  __int64 v28; // x24
  _QWORD *v29; // x25
  int inserted; // w8
  unsigned int v32; // w9
  __int64 v33; // x8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  _DWORD *v42; // x8
  __int64 v43; // x0
  _QWORD *v44; // x24
  _QWORD *v45; // x22
  __int64 v46; // x8
  unsigned __int64 StatusReg; // [xsp+8h] [xbp-28h]
  _QWORD v48[2]; // [xsp+10h] [xbp-20h] BYREF
  __int64 v49; // [xsp+20h] [xbp-10h]
  __int64 v50; // [xsp+28h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(result + 20256) )
  {
    v2 = result;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v4 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v4 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v4 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a2 + 312);
      v5 = *(_QWORD *)(a2 + 296);
      if ( v5 )
      {
LABEL_6:
        StatusReg = _ReadStatusReg(SP_EL0);
        while ( !*(_QWORD *)(v2 + 20256) || !*(_DWORD *)(v5 + 46180) )
        {
LABEL_7:
          v5 = *(_QWORD *)(v5 + 112);
          if ( !v5 )
            goto LABEL_53;
        }
        v48[0] = v48;
        v48[1] = v48;
        v6 = *(_QWORD *)(v5 + 24);
        v49 = 0;
        if ( !v6 || !*(_QWORD *)(v6 + 8) )
        {
LABEL_44:
          if ( !qdf_list_empty(v48) )
          {
            v42 = *(_DWORD **)(v2 + 20256);
            v43 = *(unsigned __int8 *)(v5 + 59);
            if ( *(v42 - 1) != -1977846623 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, _QWORD *))v42)(v43, v48);
            v44 = (_QWORD *)v48[0];
            if ( (_QWORD *)v48[0] != v48 )
            {
              do
              {
                v45 = (_QWORD *)*v44;
                qdf_list_remove_node((__int64)v48, v44);
                _qdf_mem_free((__int64)v44);
                v44 = v45;
              }
              while ( v45 != v48 );
            }
          }
          if ( (_DWORD)v49 )
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: list length not equal to zero",
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              "qdf_list_destroy");
          goto LABEL_7;
        }
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v5 + 144);
          v15 = *(_QWORD *)(v5 + 128);
          while ( v15 )
          {
LABEL_16:
            v16 = v15;
            v15 = *(_QWORD *)(v15 + 56);
            v17 = *(_DWORD *)(v16 + 40);
            while ( v17 )
            {
              _X12 = (unsigned int *)(v16 + 40);
              __asm { PRFM            #0x11, [X12] }
              while ( 1 )
              {
                v24 = __ldxr(_X12);
                if ( v24 != v17 )
                  break;
                if ( !__stlxr(v17 + 1, _X12) )
                {
                  __dmb(0xBu);
                  break;
                }
              }
              _ZF = v24 == v17;
              v17 = v24;
              if ( _ZF )
              {
                _X8 = (unsigned int *)(v16 + 292);
                __asm { PRFM            #0x11, [X8] }
                do
                  v32 = __ldxr(_X8);
                while ( __stxr(v32 + 1, _X8) );
                v26 = *(_DWORD *)(v16 + 408);
                if ( v26 != 2 && *(_DWORD *)(v16 + 124) == 3 )
                {
                  if ( v26 != 1 || (v27 = *(_QWORD **)(v16 + 416)) == nullptr )
                    v27 = (_QWORD *)v16;
                  if ( *v27 )
                  {
                    v28 = v16;
                    v29 = (_QWORD *)_qdf_mem_malloc(0x78u, "dp_tx_latency_stats_get_peer_iter", 3327);
                    v16 = v28;
                    if ( v29 )
                    {
                      if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD *))dp_tx_latency_stats_get_per_peer)(
                                           v28,
                                           v29)
                        || (inserted = qdf_list_insert_back(v48, v29), v16 = v28, inserted) )
                      {
                        _qdf_mem_free((__int64)v29);
                        v16 = v28;
                      }
                    }
                  }
                }
                dp_peer_unref_delete(v16, 7u, v7, v8, v9, v10, v11, v12, v13, v14);
                break;
              }
            }
          }
        }
        else
        {
          raw_spin_lock_bh(v5 + 144);
          *(_QWORD *)(v5 + 152) |= 1uLL;
          v15 = *(_QWORD *)(v5 + 128);
          if ( v15 )
            goto LABEL_16;
        }
        v33 = *(_QWORD *)(v5 + 152);
        if ( (v33 & 1) != 0 )
        {
          *(_QWORD *)(v5 + 152) = v33 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v5 + 144);
        }
        else
        {
          raw_spin_unlock(v5 + 144);
        }
        goto LABEL_44;
      }
    }
    else
    {
      raw_spin_lock_bh(a2 + 312);
      *(_QWORD *)(a2 + 320) |= 1uLL;
      v5 = *(_QWORD *)(a2 + 296);
      if ( v5 )
        goto LABEL_6;
    }
LABEL_53:
    v46 = *(_QWORD *)(a2 + 320);
    if ( (v46 & 1) != 0 )
    {
      *(_QWORD *)(a2 + 320) = v46 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(a2 + 312);
    }
    else
    {
      result = raw_spin_unlock(a2 + 312);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
