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
  __int64 v16; // x24
  unsigned int v17; // w8
  unsigned int v24; // w10
  __int64 v26; // x0
  _QWORD *v27; // x25
  unsigned int v29; // w9
  __int64 v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  _DWORD *v39; // x8
  __int64 v40; // x0
  _QWORD *v41; // x24
  _QWORD *v42; // x22
  __int64 v43; // x8
  unsigned __int64 StatusReg; // [xsp+8h] [xbp-28h]
  _QWORD v45[2]; // [xsp+10h] [xbp-20h] BYREF
  __int64 v46; // [xsp+20h] [xbp-10h]
  __int64 v47; // [xsp+28h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(result + 20200) )
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
        while ( !*(_QWORD *)(v2 + 20200) || !*(_DWORD *)(v5 + 45356) )
        {
LABEL_7:
          v5 = *(_QWORD *)(v5 + 104);
          if ( !v5 )
            goto LABEL_49;
        }
        v45[0] = v45;
        v45[1] = v45;
        v6 = *(_QWORD *)(v5 + 24);
        v46 = 0;
        if ( !v6 || !*(_QWORD *)(v6 + 8) )
        {
LABEL_40:
          if ( !qdf_list_empty(v45) )
          {
            v39 = *(_DWORD **)(v2 + 20200);
            v40 = *(unsigned __int8 *)(v5 + 59);
            if ( *(v39 - 1) != -1977846623 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, _QWORD *))v39)(v40, v45);
            v41 = (_QWORD *)v45[0];
            if ( (_QWORD *)v45[0] != v45 )
            {
              do
              {
                v42 = (_QWORD *)*v41;
                qdf_list_remove_node((__int64)v45, v41);
                _qdf_mem_free((__int64)v41);
                v41 = v42;
              }
              while ( v42 != v45 );
            }
          }
          if ( (_DWORD)v46 )
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: list length not equal to zero",
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              "qdf_list_destroy");
          goto LABEL_7;
        }
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v5 + 136);
          v15 = *(_QWORD *)(v5 + 120);
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
                _X8 = (unsigned int *)(v16 + 284);
                __asm { PRFM            #0x11, [X8] }
                do
                  v29 = __ldxr(_X8);
                while ( __stxr(v29 + 1, _X8) );
                if ( *(_DWORD *)(v16 + 124) == 3 )
                {
                  if ( *(_QWORD *)v16 )
                  {
                    v26 = _qdf_mem_malloc(0x78u, "dp_tx_latency_stats_get_peer_iter", 3327);
                    if ( v26 )
                    {
                      v27 = (_QWORD *)v26;
                      if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64))dp_tx_latency_stats_get_per_peer)(
                                           v16,
                                           v26)
                        || (unsigned int)qdf_list_insert_back(v45, v27) )
                      {
                        _qdf_mem_free((__int64)v27);
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
          raw_spin_lock_bh(v5 + 136);
          *(_QWORD *)(v5 + 144) |= 1uLL;
          v15 = *(_QWORD *)(v5 + 120);
          if ( v15 )
            goto LABEL_16;
        }
        v30 = *(_QWORD *)(v5 + 144);
        if ( (v30 & 1) != 0 )
        {
          *(_QWORD *)(v5 + 144) = v30 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v5 + 136);
        }
        else
        {
          raw_spin_unlock(v5 + 136);
        }
        goto LABEL_40;
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
LABEL_49:
    v43 = *(_QWORD *)(a2 + 320);
    if ( (v43 & 1) != 0 )
    {
      *(_QWORD *)(a2 + 320) = v43 & 0xFFFFFFFFFFFFFFFELL;
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
