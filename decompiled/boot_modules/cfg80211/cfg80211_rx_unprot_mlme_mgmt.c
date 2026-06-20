__int64 __fastcall cfg80211_rx_unprot_mlme_mgmt(__int64 result, _WORD *a2, unsigned __int64 a3)
{
  __int64 v3; // x19
  __int64 *v4; // x21
  __int64 v5; // x20
  int v6; // w8
  __int64 v7; // x8
  unsigned __int64 StatusReg; // x20
  __int64 v9; // x21
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x8
  _QWORD v13[3]; // [xsp+0h] [xbp-40h] BYREF
  int v14; // [xsp+18h] [xbp-28h]
  __int64 v15; // [xsp+1Ch] [xbp-24h]
  __int64 v16; // [xsp+24h] [xbp-1Ch]
  __int64 v17; // [xsp+2Ch] [xbp-14h]
  int v18; // [xsp+34h] [xbp-Ch]
  __int64 v19; // [xsp+38h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(__int64 **)(result + 992);
  v5 = *v4;
  if ( !*v4 )
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      v9 = result;
      ++*(_DWORD *)(StatusReg + 16);
      result = _traceiter_cfg80211_rx_unprot_mlme_mgmt(0, v3, a2, a3);
      v12 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v12;
      if ( !v12 || (result = v9, !*(_QWORD *)(StatusReg + 16)) )
      {
        preempt_schedule_notrace(result, v10, v11);
        result = v9;
      }
    }
    goto LABEL_12;
  }
  v13[0] = 0;
  v13[1] = a2;
  v13[2] = a3;
  v14 = -1;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  if ( a3 <= 1 )
  {
    __break(0x800u);
    goto LABEL_13;
  }
  v3 = result;
  v6 = *a2 & 0xFC;
  switch ( v6 )
  {
    case 128:
      v7 = v4[34];
      if ( !v7 || (result = jiffies_to_msecs(jiffies - v7), (unsigned int)result >> 4 >= 0x271) )
      {
        LODWORD(v13[0]) = 138;
        v4[34] = jiffies;
        goto LABEL_11;
      }
      break;
    case 160:
      LODWORD(v13[0]) = 71;
      goto LABEL_11;
    case 192:
      LODWORD(v13[0]) = 70;
LABEL_11:
      result = v5 - 992;
LABEL_12:
      result = nl80211_send_mlme_event(result, v3, (unsigned int *)v13, 0x820u);
      break;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
