__int64 __fastcall ieee80211_tdls_prep_mgmt_packet(
        _QWORD *a1,
        const void *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        int a7,
        __int64 a8,
        __int64 a9)
{
  unsigned __int64 v17; // x0
  char v18; // w28
  unsigned int v19; // w27
  __int64 v20; // x0
  __int64 v21; // x1
  __int64 v22; // x2
  __int64 v23; // x21
  unsigned __int64 v24; // x0
  __int64 v25; // x20
  __int64 v26; // x0
  unsigned __int64 StatusReg; // x8
  __int64 started; // x0
  unsigned __int64 v36; // x9
  unsigned __int64 v39; // x10

  _rcu_read_lock(a1, a2);
  v17 = sta_info_get((__int64)(a1 + 336), a2);
  if ( (unsigned __int8)a4 <= 0xEu )
  {
    if ( ((1 << a4) & 0x68) != 0 )
      goto LABEL_14;
    if ( ((1 << a4) & 0x404) != 0 )
      goto LABEL_9;
    if ( (unsigned __int8)a4 == 14 )
    {
LABEL_13:
      a7 = 0;
LABEL_14:
      v18 = 0;
      v19 = 0;
      if ( !v17 )
        goto LABEL_16;
      goto LABEL_15;
    }
  }
  if ( (unsigned __int8)a4 == 1 )
  {
    if ( v17 )
    {
      _X8 = (unsigned __int64 *)(v17 + 216);
      __asm { PRFM            #0x11, [X8] }
      do
        v39 = __ldxr(_X8);
      while ( __stxr(v39 & 0xFFFFFFFFFFFFDFFFLL, _X8) );
      *(_BYTE *)(v17 + 2713) = 1;
    }
    goto LABEL_13;
  }
  if ( !(_BYTE)a4 )
  {
    if ( v17 )
    {
      _X8 = (unsigned __int64 *)(v17 + 216);
      __asm { PRFM            #0x11, [X8] }
      do
        v36 = __ldxr(_X8);
      while ( __stxr(v36 | 0x2000, _X8) );
      *(_BYTE *)(v17 + 2713) = 0;
    }
LABEL_9:
    v18 = 0;
    v19 = 0;
    a7 = 1;
    if ( !v17 )
      goto LABEL_16;
LABEL_15:
    a7 |= (*(_QWORD *)(v17 + 216) >> 13) & 1;
    goto LABEL_16;
  }
  v19 = -95;
  v18 = 1;
  if ( v17 )
    goto LABEL_15;
LABEL_16:
  _rcu_read_unlock(v17);
  if ( (v18 & 1) == 0 )
  {
    v20 = ieee80211_tdls_build_mgmt_packet_data(a1 + 336, a2, a3, a4, a5, a6, a7 & 1, a8, a9, 0, 0);
    if ( v20 )
    {
      if ( (unsigned __int8)a4 >= 2u )
      {
        if ( (unsigned __int8)a4 == 14 )
        {
          ieee80211_tx_skb_tid(a1 + 336, v20, 7, a3);
          return 0;
        }
        *(_DWORD *)(v20 + 144) = 261;
        if ( (unsigned __int8)a4 == 3 && (*(_QWORD *)(a1[538] + 96LL) & 0x10000) != 0 )
        {
          v23 = v20;
          _rcu_read_lock(v20, v21);
          v24 = sta_info_get((__int64)(a1 + 336), a2);
          if ( v24 )
            v25 = (*(_QWORD *)(v24 + 216) >> 12) & 1LL;
          else
            LODWORD(v25) = 0;
          _rcu_read_unlock(v24);
          raw_spin_lock_bh(a1 + 678);
          if ( (_DWORD)v25 )
          {
            if ( a1[677] )
            {
              LODWORD(v25) = 0;
            }
            else
            {
              v26 = skb_copy(v23, 2080);
              a1[676] = v23;
              LODWORD(v25) = 1048577;
              a1[677] = v26;
            }
          }
          raw_spin_unlock_bh(a1 + 678);
          v20 = v23;
          v22 = (unsigned int)v25;
        }
        else
        {
          v22 = 0;
        }
      }
      else
      {
        v22 = 0;
        *(_DWORD *)(v20 + 144) = 258;
      }
      StatusReg = _ReadStatusReg(SP_EL0);
      *(_DWORD *)(StatusReg + 16) += 512;
      started = _ieee80211_subif_start_xmit(v20, a1, v22, 4026531840LL, 0);
      local_bh_enable_2(started);
      return 0;
    }
    v19 = -22;
  }
  consume_skb(0);
  return v19;
}
