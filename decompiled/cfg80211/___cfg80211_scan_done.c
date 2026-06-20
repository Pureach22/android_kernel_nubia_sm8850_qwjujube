_QWORD *__fastcall __cfg80211_scan_done(_QWORD *result, char a2)
{
  __int64 v2; // x19
  __int64 v3; // x8
  __int64 v4; // x21
  __int64 v5; // x9
  __int64 v7; // x0
  __int64 v8; // x22
  __int64 *v9; // x1
  __int64 v10; // x24
  int v11; // w25
  __int64 *v12; // x26
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // x2
  __int64 v16; // x9
  __int64 v17; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v19; // x9
  unsigned int *v20; // x9
  unsigned int v21; // w12
  __int64 v22; // x9
  __int64 v23; // x0

  v2 = (__int64)result;
  if ( result[30] )
  {
    result = (_QWORD *)nl80211_send_scan_msg((__int64)result, result[30]);
    *(_QWORD *)(v2 + 240) = 0;
    return result;
  }
  v3 = result[28];
  if ( v3 )
  {
    v4 = *(_QWORD *)(v3 + 64);
    v5 = result[29];
    v7 = *(_QWORD *)(v4 + 32);
    if ( v5 )
      v8 = *(_QWORD *)(v2 + 232);
    else
      v8 = *(_QWORD *)(v2 + 224);
    if ( v7 )
    {
      if ( (*(_QWORD *)(v7 + 168) & 1) == 0 )
      {
LABEL_18:
        cfg80211_sme_scan_done();
LABEL_19:
        if ( (*(_BYTE *)(v8 + 126) & 1) == 0 && (*(_BYTE *)(v8 + 36) & 2) != 0 )
        {
          raw_spin_lock_bh(v2 + 184);
          v9 = *(__int64 **)(v2 + 192);
          if ( v9 != (__int64 *)(v2 + 192) )
          {
            v10 = *(_QWORD *)(v8 + 104);
            v11 = 0;
            do
            {
              v12 = (__int64 *)*v9;
              if ( !*((_DWORD *)v9 + 20) && v9[8] - v10 < 0 )
                v11 |= _cfg80211_unlink_bss(v2);
              v9 = v12;
            }
            while ( v12 != (__int64 *)(v2 + 192) );
            if ( (v11 & 1) != 0 )
              ++*(_DWORD *)(v2 + 216);
          }
          raw_spin_unlock_bh(v2 + 184);
        }
        v13 = nl80211_build_scan_msg();
        v16 = *(_QWORD *)(v4 + 32);
        v17 = v13;
        if ( v16 )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          ++*(_DWORD *)(StatusReg + 16);
          v19 = *(_QWORD *)(v16 + 1320);
          v20 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v19);
          do
            v21 = __ldxr(v20);
          while ( __stxr(v21 - 1, v20) );
          v22 = *(_QWORD *)(StatusReg + 16) - 1LL;
          *(_DWORD *)(StatusReg + 16) = v22;
          if ( !v22 || !*(_QWORD *)(StatusReg + 16) )
            preempt_schedule_notrace(v13, v14, v15);
        }
        kfree(*(_QWORD *)(v2 + 232));
        v23 = *(_QWORD *)(v2 + 224);
        *(_QWORD *)(v2 + 232) = 0;
        result = (_QWORD *)kfree(v23);
        *(_QWORD *)(v2 + 224) = 0;
        if ( (a2 & 1) != 0 )
          return (_QWORD *)nl80211_send_scan_msg(v2, v17);
        *(_QWORD *)(v2 + 240) = v17;
        return result;
      }
    }
    else if ( *(_BYTE *)(v4 + 66) != 1 )
    {
      goto LABEL_19;
    }
    if ( (*(_BYTE *)(v2 + 1092) & 4) != 0 && (*(_BYTE *)(v3 + 130) & 1) == 0 && (*(_BYTE *)(v8 + 126) & 1) == 0 )
    {
      result = (_QWORD *)((__int64 (__fastcall *)(__int64))cfg80211_scan_6ghz)(v2);
      if ( !(_DWORD)result )
        return result;
      v7 = *(_QWORD *)(v4 + 32);
    }
    if ( !v7 )
      goto LABEL_19;
    goto LABEL_18;
  }
  return result;
}
