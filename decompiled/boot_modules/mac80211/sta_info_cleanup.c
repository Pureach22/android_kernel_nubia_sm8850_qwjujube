__int64 __fastcall sta_info_cleanup(__int64 a1, __int64 a2)
{
  __int64 lock; // x0
  __int64 v4; // x20
  int v5; // w8
  int v6; // w10
  __int64 v7; // x26
  _BOOL4 v8; // w8
  __int64 v9; // x25
  __int64 v10; // x0
  __int64 *v11; // x22
  __int64 v12; // x1
  __int64 v14; // x23
  __int64 v15; // x0
  __int64 *v16; // x22
  __int64 v17; // x1
  __int64 v19; // x8
  __int64 v20; // x8
  _QWORD *v21; // x9
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x8
  _QWORD *v25; // x9
  __int64 v26; // x0
  char v27; // w20
  __int64 result; // x0
  __int64 v29; // x0
  int v30; // [xsp+14h] [xbp-1Ch]
  int v31; // [xsp+2Ch] [xbp-4h]

  lock = _rcu_read_lock(a1, a2);
  v4 = *(_QWORD *)(a1 - 336);
  if ( v4 == a1 - 336 )
  {
    v27 = 1;
  }
  else
  {
    v5 = 0;
    do
    {
      v30 = v5;
      if ( *(_QWORD *)(*(_QWORD *)(v4 + 80) + 2032LL) )
      {
        v7 = 0;
        v6 = 0;
        do
        {
          v9 = v4 + 328 + 24 * v7;
          v31 = v6;
          v10 = raw_spin_lock_irqsave(v9 + 20);
          v11 = *(__int64 **)v9;
          v12 = v10;
          if ( *(_QWORD *)v9 != v9 && v11 != nullptr )
          {
            do
            {
              v19 = 36028797024LL
                  * *(unsigned __int16 *)(v4 + 200)
                  * *(unsigned __int16 *)(*(_QWORD *)(v4 + 80) + 4858LL);
              LODWORD(v19) = 250 * ((v19 >> 44) + ((unsigned __int64)v19 >> 63));
              if ( (int)v19 <= 2500 )
                v19 = 2500;
              else
                v19 = (unsigned int)v19;
              if ( v11[6] - jiffies + v19 >= 0 )
                break;
              --*(_DWORD *)(v9 + 16);
              v20 = *v11;
              v21 = (_QWORD *)v11[1];
              *v11 = 0;
              v11[1] = 0;
              *(_QWORD *)(v20 + 8) = v21;
              *v21 = v20;
              raw_spin_unlock_irqrestore(v9 + 20, v12);
              ieee80211_free_txskb(a1 - 1952);
              v22 = raw_spin_lock_irqsave(v9 + 20);
              v11 = *(__int64 **)v9;
              v12 = v22;
              if ( *(_QWORD *)v9 == v9 )
                break;
            }
            while ( v11 );
          }
          raw_spin_unlock_irqrestore(v9 + 20, v12);
          v14 = v4 + 232 + 24 * v7;
          v15 = raw_spin_lock_irqsave(v14 + 20);
          v16 = *(__int64 **)v14;
          v17 = v15;
          if ( *(_QWORD *)v14 != v14 && v16 != nullptr )
          {
            do
            {
              v23 = 36028797024LL
                  * *(unsigned __int16 *)(v4 + 200)
                  * *(unsigned __int16 *)(*(_QWORD *)(v4 + 80) + 4858LL);
              LODWORD(v23) = 250 * ((v23 >> 44) + ((unsigned __int64)v23 >> 63));
              if ( (int)v23 <= 2500 )
                v23 = 2500;
              else
                v23 = (unsigned int)v23;
              if ( v16[6] - jiffies + v23 >= 0 )
                break;
              --*(_DWORD *)(v14 + 16);
              v24 = *v16;
              v25 = (_QWORD *)v16[1];
              *v16 = 0;
              v16[1] = 0;
              *(_QWORD *)(v24 + 8) = v25;
              *v25 = v24;
              raw_spin_unlock_irqrestore(v14 + 20, v17);
              --*(_DWORD *)(a1 + 3048);
              ieee80211_free_txskb(a1 - 1952);
              v26 = raw_spin_lock_irqsave(v14 + 20);
              v16 = *(__int64 **)v14;
              v17 = v26;
              if ( *(_QWORD *)v14 == v14 )
                break;
            }
            while ( v16 );
          }
          raw_spin_unlock_irqrestore(v14 + 20, v17);
          lock = _sta_info_recalc_tim(v4, 0);
          v8 = *(_QWORD *)v14 != v14 || *(_QWORD *)v9 != v9;
          ++v7;
          v6 = v31 | v8;
        }
        while ( v7 != 4 );
      }
      else
      {
        v6 = 0;
      }
      v4 = *(_QWORD *)v4;
      v5 = v6 | v30;
    }
    while ( v4 != a1 - 336 );
    v27 = v5 ^ 1;
  }
  result = _rcu_read_unlock(lock);
  if ( (*(_BYTE *)(a1 - 484) & 1) == 0 && (v27 & 1) == 0 )
  {
    v29 = round_jiffies(jiffies + 2500LL);
    return mod_timer(a1, v29);
  }
  return result;
}
