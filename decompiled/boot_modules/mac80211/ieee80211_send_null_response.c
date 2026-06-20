__int64 __fastcall ieee80211_send_null_response(__int64 a1, int a2, unsigned int a3, char a4, char a5)
{
  __int64 v5; // x20
  int v6; // w23
  __int64 v9; // x22
  __int64 v10; // x25
  unsigned int v11; // w28
  __int64 result; // x0
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // x21
  int v17; // w8
  __int16 v18; // w27
  __int64 v19; // x0
  __int64 v20; // x1
  __int64 v21; // x4
  __int16 v22; // w10
  __int16 v23; // w10
  int v24; // w8
  __int16 v25; // w9
  int v26; // w9
  _DWORD *v27; // x8
  __int64 lock; // x0
  _DWORD **v29; // x8
  __int64 v30; // x0
  unsigned __int64 StatusReg; // x23
  unsigned int v32; // w24
  __int64 v33; // x8

  v5 = *(_QWORD *)(a1 + 80);
  v6 = *(unsigned __int8 *)(a1 + 2698);
  v9 = *(_QWORD *)(v5 + 1616);
  LODWORD(v10) = a2;
  if ( *(_BYTE *)(a1 + 2698) )
    v11 = 26;
  else
    v11 = 24;
  result = _netdev_alloc_skb(0, v11 + *(_DWORD *)(v9 + 104), 2080);
  if ( result )
  {
    v14 = *(int *)(v9 + 104);
    v15 = *(_QWORD *)(result + 224) + v14;
    v16 = result;
    v17 = *(_DWORD *)(result + 208) + v14;
    *(_QWORD *)(result + 224) = v15;
    if ( v6 )
      v18 = 712;
    else
      v18 = 584;
    *(_DWORD *)(result + 208) = v17;
    v19 = skb_put(result, v11);
    *(_WORD *)v19 = v18;
    *(_WORD *)(v19 + 2) = 0;
    v22 = *(_WORD *)(a1 + 2692);
    *(_DWORD *)(v19 + 4) = *(_DWORD *)(a1 + 2688);
    *(_WORD *)(v19 + 8) = v22;
    v23 = *(_WORD *)(v5 + 5846);
    *(_DWORD *)(v19 + 10) = *(_DWORD *)(v5 + 5842);
    *(_WORD *)(v19 + 14) = v23;
    v24 = *(_DWORD *)(v5 + 5842);
    v25 = *(_WORD *)(v5 + 5846);
    *(_WORD *)(v19 + 22) = 0;
    *(_DWORD *)(v19 + 16) = v24;
    *(_WORD *)(v19 + 20) = v25;
    *(_DWORD *)(v16 + 144) = v10;
    if ( (unsigned int)v10 >= 8 )
    {
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                       + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
          & 1) != 0 )
      {
        v32 = v21;
        ++*(_DWORD *)(StatusReg + 16);
        v19 = _traceiter_drv_allow_buffered_frames(0, v9, a1 + 2688, (unsigned int)v10, 1, (unsigned int)v21, 0);
        v33 = *(_QWORD *)(StatusReg + 16) - 1LL;
        *(_DWORD *)(StatusReg + 16) = v33;
        if ( !v33 || (v21 = v32, !*(_QWORD *)(StatusReg + 16)) )
        {
          v19 = preempt_schedule_notrace(v19);
          v21 = v32;
        }
      }
    }
    else
    {
      v21 = a3;
      *(_WORD *)(v16 + 124) = ieee802_1d_to_ac[(unsigned int)v10];
      if ( v6 )
      {
        *(_WORD *)(v19 + 24) = v10;
        if ( a3 == 1 )
        {
          *(_WORD *)(v19 + 24) = v10 | 0x10;
          if ( (a5 & 1) != 0 )
            *(_WORD *)v19 |= 0x2000u;
        }
      }
      v26 = *(_DWORD *)(v16 + 80) | 2;
      *(_DWORD *)(v16 + 40) |= 0x10020001u;
      *(_DWORD *)(v16 + 80) = v26;
      if ( (a4 & 1) == 0 )
        goto LABEL_19;
      v10 = 1LL << v10;
    }
    v27 = *(_DWORD **)(*(_QWORD *)(v9 + 464) + 528LL);
    if ( v27 )
    {
      if ( *(v27 - 1) != 1853379195 )
        __break(0x8228u);
      v19 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, __int64, _QWORD))v27)(
              v9,
              a1 + 2688,
              (unsigned int)v10,
              1,
              v21,
              0);
    }
LABEL_19:
    *(_QWORD *)(v16 + 16) = *(_QWORD *)(v5 + 1608);
    lock = _rcu_read_lock(v19, v20);
    v29 = *(_DWORD ***)(v5 + 5640);
    if ( v29 )
    {
      *(_DWORD *)(v16 + 44) = *(_DWORD *)(v16 + 44) & 0xFFFFFFF8 | **v29 & 7;
      v30 = ieee80211_xmit(v5, a1, v16);
      return _rcu_read_unlock(v30);
    }
    else
    {
      __break(0x800u);
      _rcu_read_unlock(lock);
      return sk_skb_reason_drop(0);
    }
  }
  return result;
}
