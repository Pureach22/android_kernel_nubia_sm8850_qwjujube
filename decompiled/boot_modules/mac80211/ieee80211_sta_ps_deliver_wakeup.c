_QWORD *__fastcall ieee80211_sta_ps_deliver_wakeup(_QWORD *result)
{
  __int64 v1; // x19
  __int64 v2; // x8
  int v3; // w9
  __int64 v4; // x20
  __int64 v5; // x8
  __int64 v6; // x24
  void (__fastcall *v7)(__int64, __int64, __int64, __int64); // x9
  __int64 v8; // x26
  __int64 v9; // x10
  __int64 v10; // x21
  __int64 v11; // x1
  unsigned __int64 v14; // x9
  _QWORD *v15; // x22
  __int64 v16; // x21
  _DWORD *v17; // x8
  __int64 v18; // x8
  __int64 v19; // x1
  __int64 v20; // x23
  int v21; // w21
  __int64 v22; // x25
  _QWORD *v23; // x26
  __int64 v24; // x0
  _QWORD *v25; // x8
  __int64 *v26; // x9
  __int64 *v27; // x10
  int v28; // w8
  int v29; // w26
  __int64 v30; // x1
  _QWORD *v31; // x8
  __int64 v32; // x9
  __int64 v33; // x11
  __int64 *v34; // x10
  __int64 *v35; // x12
  int v36; // w9
  unsigned __int64 v43; // x11
  unsigned __int64 v46; // x10
  unsigned __int64 v49; // x10
  unsigned __int64 v52; // x10
  unsigned int v55; // w10
  __int64 v56; // [xsp+0h] [xbp-20h] BYREF
  __int64 *v57; // [xsp+8h] [xbp-18h]
  __int64 v58; // [xsp+10h] [xbp-10h]
  __int64 v59; // [xsp+18h] [xbp-8h]

  v1 = (__int64)result;
  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = result[10];
  v57 = nullptr;
  v58 = 0;
  v56 = 0;
  v3 = *(_DWORD *)(v2 + 4720);
  v4 = *(_QWORD *)(v2 + 1616);
  if ( v3 == 4 )
  {
    v5 = *(_QWORD *)(v2 + 2032);
    v3 = *(_DWORD *)(v5 + 2456);
    v2 = v5 - 2264;
  }
  if ( v3 == 3 )
  {
    v6 = *(_QWORD *)(v2 + 2032);
    _X9 = result + 27;
    __asm { PRFM            #0x11, [X9] }
    do
      v43 = __ldxr(_X9);
    while ( __stxr(v43 & 0xFFFFFFFFFFFBFFFFLL, _X9) );
    result[53] = 0;
    result[54] = 0;
    if ( (*(_QWORD *)(v4 + 96) & 0x100000) == 0 )
    {
      if ( v2 && *(_DWORD *)(v2 + 4720) == 4 )
        v2 = *(_QWORD *)(v2 + 2032) - 2264LL;
      if ( (*(_BYTE *)(*(_QWORD *)(v2 + 1616) + 1471LL) & 1) != 0
        || (*(_DWORD *)(v2 + 1624) & 0x20) != 0
        || (drv_sta_notify___already_done_0 & 1) != 0 )
      {
        if ( (*(_BYTE *)(v2 + 1624) & 0x20) != 0 )
          goto LABEL_13;
      }
      else
      {
        v9 = *(_QWORD *)(v2 + 1608);
        drv_sta_notify___already_done_0 = 1;
        v10 = v2;
        if ( v9 )
          v11 = v9 + 296;
        else
          v11 = v2 + 1640;
        _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v11);
        v2 = v10;
        __break(0x800u);
        if ( (*(_BYTE *)(v10 + 1624) & 0x20) != 0 )
        {
LABEL_13:
          v7 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(*(_QWORD *)(v4 + 464) + 280LL);
          if ( v7 )
          {
            if ( *((_DWORD *)v7 - 1) != -1905637554 )
              __break(0x8229u);
            v7(v4, v2 + 4720, 1, v1 + 2688);
          }
        }
      }
    }
    v8 = 2736;
    _ReadStatusReg(SP_EL0);
    do
    {
      v15 = *(_QWORD **)(v1 + v8);
      if ( v15 && ((_QWORD *)*(v15 - 4) != v15 - 4 || *((_DWORD *)v15 - 31)) )
      {
        _ieee80211_schedule_txq(v4, *(_QWORD *)(v1 + v8), 1);
        if ( *(_BYTE *)(v4 + 1470) == 1 )
        {
          _X8 = v15 - 1;
          __asm { PRFM            #0x11, [X8] }
          do
            v14 = __ldxr(_X8);
          while ( __stxr(v14 | 8, _X8) );
        }
        else
        {
          v16 = *v15;
          if ( (*(_BYTE *)(*(_QWORD *)(*v15 - 3104LL) + 1471LL) & 1) == 0
            && (*(_DWORD *)(v16 - 3096) & 0x20) == 0
            && (drv_wake_tx_queue___already_done_0 & 1) == 0 )
          {
            v18 = *(_QWORD *)(v16 - 3112);
            if ( v18 )
              v19 = v18 + 296;
            else
              v19 = v16 - 3080;
            drv_wake_tx_queue___already_done_0 = 1;
            _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v19);
            __break(0x800u);
          }
          if ( (*(_BYTE *)(v16 - 3096) & 0x20) != 0 )
          {
            v17 = *(_DWORD **)(*(_QWORD *)(v4 + 464) + 752LL);
            if ( *(v17 - 1) != -1212882962 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, _QWORD *))v17)(v4, v15);
          }
        }
      }
      v8 += 8;
    }
    while ( v8 != 2872 );
    v58 = 0;
    v56 = (__int64)&v56;
    v57 = &v56;
    raw_spin_lock_bh(v1 + 224);
    v20 = 0;
    v21 = 0;
    do
    {
      v22 = v1 + v20;
      v23 = (_QWORD *)(v1 + v20 + 328);
      v24 = raw_spin_lock_irqsave(v1 + v20 + 348);
      v25 = (_QWORD *)*v23;
      if ( v23 != (_QWORD *)*v23 )
      {
        v26 = v57;
        v27 = *(__int64 **)(v22 + 336);
        v25[1] = v57;
        *v26 = (__int64)v25;
        *v27 = (__int64)&v56;
        v57 = v27;
        v28 = *(_DWORD *)(v22 + 344);
        LODWORD(v26) = v58;
        *v23 = v23;
        *(_QWORD *)(v22 + 336) = v23;
        *(_DWORD *)(v22 + 344) = 0;
        LODWORD(v58) = (_DWORD)v26 + v28;
      }
      raw_spin_unlock_irqrestore(v22 + 348, v24);
      v29 = v58;
      v30 = raw_spin_lock_irqsave(v22 + 252);
      v31 = (_QWORD *)(v22 + 232);
      v32 = *(_QWORD *)(v22 + 232);
      if ( v22 + 232 != v32 )
      {
        v33 = v1 + v20;
        v34 = v57;
        v35 = *(__int64 **)(v1 + v20 + 240);
        *(_QWORD *)(v32 + 8) = v57;
        *v34 = v32;
        *v35 = (__int64)&v56;
        v57 = v35;
        v36 = *(_DWORD *)(v1 + v20 + 248);
        LODWORD(v34) = v58;
        *v31 = v31;
        *(_QWORD *)(v33 + 240) = v31;
        *(_DWORD *)(v33 + 248) = 0;
        LODWORD(v58) = (_DWORD)v34 + v36;
      }
      raw_spin_unlock_irqrestore(v22 + 252, v30);
      v20 += 24;
      v21 = v21 - v29 + v58;
    }
    while ( v20 != 96 );
    ieee80211_add_pending_skbs(v4, &v56);
    _X8 = (unsigned __int64 *)(v1 + 216);
    __asm { PRFM            #0x11, [X8] }
    do
      v46 = __ldxr(_X8);
    while ( __stxr(v46 & 0xFFFFFFFFFDFFFFFFLL, _X8) );
    _X8 = (unsigned __int64 *)(v1 + 216);
    __asm { PRFM            #0x11, [X8] }
    do
      v49 = __ldxr(_X8);
    while ( __stxr(v49 & 0xFFFFFFFFFFFFFBFFLL, _X8) );
    _X8 = (unsigned __int64 *)(v1 + 216);
    __asm { PRFM            #0x11, [X8] }
    do
      v52 = __ldxr(_X8);
    while ( __stxr(v52 & 0xFFFFFFFFFFFDFFFFLL, _X8) );
    raw_spin_unlock_bh(v1 + 224);
    _X8 = (unsigned int *)(v6 + 296);
    __asm { PRFM            #0x11, [X8] }
    do
      v55 = __ldxr(_X8);
    while ( __stxr(v55 - 1, _X8) );
    *(_DWORD *)(v4 + 5000) -= v21;
    _sta_info_recalc_tim(v1, 0);
    result = (_QWORD *)ieee80211_check_fast_xmit(v1);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
