__int64 __fastcall _ieee80211_flush_queues(__int64 result, unsigned __int8 *a2, unsigned int a3, char a4)
{
  __int64 v5; // x19
  unsigned __int8 *v6; // x22
  int v7; // w9
  int v8; // w11
  int v9; // w13
  int v10; // w14
  int v11; // w8
  __int64 v12; // x12
  bool v13; // zf
  __int64 v14; // x9
  __int64 v15; // x11
  __int64 v16; // x13
  __int64 v17; // x10
  int v18; // w8
  int v19; // w9
  __int64 v20; // x21
  __int64 v21; // x23
  int i; // w8
  signed int next_bit; // w24
  _QWORD *j; // x23
  __int64 v25; // x8
  unsigned __int8 *v26; // x1
  _DWORD *v27; // x8
  __int64 v28; // x0
  int v29; // w8
  signed int v30; // w20
  __int64 v31; // x9
  unsigned __int8 *v32; // x23
  unsigned __int8 *v33; // x8
  __int64 v34; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v35[2]; // [xsp+10h] [xbp-10h] BYREF

  v35[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(*(_QWORD *)(result + 464) + 432LL) )
  {
    v5 = result;
    v6 = a2;
    if ( !a3 || (*(_QWORD *)(result + 96) & 0x40000) == 0 )
    {
      if ( a2 && (*(_QWORD *)(result + 96) & 0x40000) != 0 )
      {
        v7 = a2[5850];
        v8 = a2[5851];
        v9 = a2[5852];
        v10 = a2[5853];
        v11 = a2[5849];
        v12 = 1LL << v7;
        v13 = v7 == 255;
        v14 = 1LL << v8;
        if ( v13 )
          LODWORD(v12) = 0;
        v13 = v8 == 255;
        v15 = 1LL << v9;
        if ( v13 )
          LODWORD(v14) = 0;
        v13 = v9 == 255;
        v16 = 1LL << v10;
        if ( v13 )
          LODWORD(v15) = 0;
        v17 = 1LL << v11;
        if ( v10 == 255 )
          LODWORD(v16) = 0;
        v13 = v11 == 255;
        v18 = v14 | v12 | v15 | v16;
        if ( v13 )
          v19 = 0;
        else
          v19 = v17;
        a3 = v18 | v19;
      }
      else
      {
        a3 = ~(-1 << *(_WORD *)(result + 128));
      }
    }
    v20 = a3;
    v35[0] = a3;
    v21 = raw_spin_lock_irqsave(result + 1312);
    for ( i = 0; ; i = next_bit + 1 )
    {
      next_bit = find_next_bit(v35, *(unsigned __int16 *)(v5 + 128), i);
      if ( next_bit >= *(unsigned __int16 *)(v5 + 128) )
        break;
      _ieee80211_stop_queue(v5, next_bit, 7u, 0);
    }
    raw_spin_unlock_irqrestore(v5 + 1312, v21);
    if ( (a4 & 1) != 0 )
    {
      for ( j = *(_QWORD **)(v5 + 1616); j != (_QWORD *)(v5 + 1616); j = (_QWORD *)*j )
      {
        if ( (unsigned __int8 *)j[10] == v6 )
          ieee80211_purge_sta_txqs((__int64)j);
      }
    }
    if ( v6 )
    {
      if ( *((_DWORD *)v6 + 1180) != 4 )
      {
        v26 = v6 + 4720;
        goto LABEL_34;
      }
      v25 = *((_QWORD *)v6 + 254);
      v6 = (unsigned __int8 *)(v25 - 2264);
      if ( v25 != 2264 )
      {
        v26 = (unsigned __int8 *)(v25 + 2456);
LABEL_34:
        if ( (*(_BYTE *)(*((_QWORD *)v6 + 202) + 1471LL) & 1) != 0
          || (*((_DWORD *)v6 + 406) & 0x20) != 0
          || (drv_flush___already_done & 1) != 0 )
        {
          if ( (v6[1624] & 0x20) != 0 )
            goto LABEL_38;
        }
        else
        {
          v31 = *((_QWORD *)v6 + 201);
          drv_flush___already_done = 1;
          v32 = v26;
          if ( v31 )
            v33 = (unsigned __int8 *)(v31 + 296);
          else
            v33 = v6 + 1640;
          _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v33);
          v26 = v32;
          __break(0x800u);
          if ( (v6[1624] & 0x20) != 0 )
          {
LABEL_38:
            v27 = *(_DWORD **)(*(_QWORD *)(v5 + 464) + 432LL);
            if ( v27 )
            {
              if ( *(v27 - 1) != 407287956 )
                __break(0x8228u);
              ((void (__fastcall *)(__int64, unsigned __int8 *, _QWORD, _QWORD))v27)(v5, v26, (unsigned int)v20, a4 & 1);
            }
          }
        }
        v35[0] = v20;
        v28 = raw_spin_lock_irqsave(v5 + 1312);
        v29 = 0;
        v34 = v28;
        while ( 1 )
        {
          v30 = find_next_bit(v35, *(unsigned __int16 *)(v5 + 128), v29);
          if ( v30 >= *(unsigned __int16 *)(v5 + 128) )
            break;
          _ieee80211_wake_queue(v5, v30, 7u, 0, (__int64)&v34);
          v29 = v30 + 1;
        }
        result = raw_spin_unlock_irqrestore(v5 + 1312, v34);
        goto LABEL_46;
      }
    }
    v26 = nullptr;
    goto LABEL_38;
  }
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
