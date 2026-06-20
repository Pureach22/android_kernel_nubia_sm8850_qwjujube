__int64 __fastcall ieee80211_tx_8023(__int64 a1, __int64 *a2, __int64 a3, char a4)
{
  __int64 *v5; // x22
  char v8; // w27
  __int64 *v9; // x28
  __int64 v10; // x23
  unsigned __int64 v11; // x25
  __int64 v12; // x24
  __int64 v13; // x8
  _DWORD **v14; // x9
  _DWORD *v15; // x8
  _QWORD v17[2]; // [xsp+10h] [xbp-10h] BYREF

  v5 = a2;
  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 1;
  if ( (ieee80211_queue_skb(*(_QWORD *)(a1 + 1616), a1, a3, a2) & 1) == 0 && v5 )
  {
    while ( 1 )
    {
      v9 = (__int64 *)*v5;
      *v5 = 0;
      v10 = *(_QWORD *)(a1 + 1616);
      v11 = ((unsigned __int64)*((unsigned int *)v5 + 11) >> 17) & 0xF;
      v12 = raw_spin_lock_irqsave(v10 + 1312);
      if ( *(_QWORD *)(v10 + 8 * v11 + 480) )
      {
        if ( (a4 & 1) != 0 )
        {
          skb_queue_head(v10 + 24LL * (unsigned int)v11 + 2000, v5);
          goto LABEL_6;
        }
LABEL_5:
        skb_queue_tail(v10 + 24LL * (unsigned int)v11 + 2000);
LABEL_6:
        raw_spin_unlock_irqrestore(v10 + 1312, v12);
        v8 = 0;
        v5 = v9;
        if ( !v9 )
          break;
      }
      else
      {
        if ( (a4 & 1) == 0
          && *(_QWORD *)(v10 + 24LL * (unsigned int)v11 + 2000) != v10 + 24LL * (unsigned int)v11 + 2000 )
        {
          goto LABEL_5;
        }
        raw_spin_unlock_irqrestore(v10 + 1312, v12);
        if ( a3 )
        {
          v13 = a3 + 2688;
          if ( !*(_BYTE *)(a3 + 204) )
            v13 = 0;
        }
        else
        {
          v13 = 0;
        }
        v14 = *(_DWORD ***)(v10 + 464);
        v17[0] = v13;
        v15 = *v14;
        if ( *(*v14 - 1) != 638598288 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD *, __int64 *))v15)(v10, v17, v5);
        v5 = v9;
        if ( !v9 )
          break;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return v8 & 1;
}
