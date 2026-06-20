_QWORD *__fastcall ieee80211_bss_info_update(__int64 a1, __int64 a2, _WORD *a3, __int64 a4, __int64 a5)
{
  char v10; // w8
  __int64 v11; // x9
  int v12; // w8
  bool v13; // zf
  char v14; // w8
  int v15; // w8
  __int64 lock; // x0
  __int64 v17; // x8
  unsigned __int64 v18; // x9
  __int64 v19; // x24
  __int64 v20; // x8
  _QWORD *result; // x0
  __int64 v22; // [xsp+0h] [xbp-50h] BYREF
  char v23; // [xsp+8h] [xbp-48h]
  _BYTE v24[7]; // [xsp+9h] [xbp-47h] BYREF
  __int64 v25; // [xsp+10h] [xbp-40h] BYREF
  __int64 v26; // [xsp+18h] [xbp-38h]
  __int64 v27; // [xsp+20h] [xbp-30h]
  __int64 v28; // [xsp+28h] [xbp-28h]
  __int64 v29; // [xsp+30h] [xbp-20h]
  __int64 v30; // [xsp+38h] [xbp-18h]
  __int64 *v31; // [xsp+40h] [xbp-10h]
  __int64 v32; // [xsp+48h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a3;
  v30 = 0;
  v31 = &v22;
  v11 = *(_QWORD *)(a2 + 8);
  v22 = a2;
  v12 = v10 & 0xFC;
  memset(v24, 0, sizeof(v24));
  v13 = v12 == 128 || v12 == 28;
  v26 = 0;
  v27 = v11;
  v14 = v13;
  v28 = 0;
  v29 = 0;
  v23 = v14;
  if ( (*(_BYTE *)(a2 + 25) & 1) == 0 )
  {
    if ( (*(_QWORD *)(a1 + 96) & 0x10) != 0 )
    {
      v15 = 100 * *(char *)(a2 + 38);
      goto LABEL_12;
    }
    if ( (*(_QWORD *)(a1 + 96) & 8) != 0 )
    {
      v15 = (__int16)(100 * *(char *)(a2 + 38) / *(char *)(a1 + 132));
LABEL_12:
      LODWORD(v26) = v15;
    }
  }
  v25 = a5;
  lock = _rcu_read_lock(a1, a2);
  v17 = *(_QWORD *)(a1 + 4968);
  if ( v17 && *(_DWORD *)(v17 + 4720) == 2 && *(_BYTE *)(v17 + 4728) == 1 && (*(_BYTE *)(a2 + 26) & 3) != 0 )
  {
    if ( *(_WORD *)(v17 + 5800) )
    {
      v18 = *(unsigned __int8 *)(a2 + 46);
      if ( (v18 & 1) == 0 )
        goto LABEL_23;
      v19 = *(_QWORD *)(v17 + 8 * ((v18 >> 1) & 0xF) + 5680);
    }
    else
    {
      v19 = v17 + 4808;
    }
    if ( v19 )
    {
      lock = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64))ieee80211_calculate_rx_timestamp)(
               a1,
               a2,
               (unsigned int)(a4 + 4),
               24);
      v28 = lock;
      v20 = *(_QWORD *)(v19 + 16);
      LODWORD(v29) = *(_DWORD *)v20;
      WORD2(v29) = *(_WORD *)(v20 + 4);
    }
  }
LABEL_23:
  _rcu_read_unlock(lock);
  result = (_QWORD *)cfg80211_inform_bss_frame_data(*(_QWORD *)(a1 + 72), &v25, a3, a4, 2080);
  if ( result )
  {
    if ( *result != a5 )
      *(_DWORD *)(a2 + 24) |= 0x100u;
    result += 12;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
