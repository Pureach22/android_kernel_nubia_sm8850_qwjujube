__int64 __fastcall ieee80211_key_disable_hw_accel(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 v5; // x21
  __int64 lock; // x0
  _QWORD *i; // x8
  int v8; // w8
  __int64 v9; // x21
  __int64 v10; // x3
  __int64 v11; // x22
  __int64 v12; // x8
  void *v13; // x3

  if ( result )
  {
    if ( *(_QWORD *)(*(_QWORD *)(*(_QWORD *)result + 464LL) + 152LL) )
    {
      if ( (*(_BYTE *)(result + 40) & 1) != 0 )
      {
        v2 = *(_QWORD *)(result + 8);
        v3 = *(_QWORD *)(result + 16);
        v4 = *(char *)(result + 554);
        if ( v4 < 0 || !*(_WORD *)(v2 + 5802) || (((unsigned __int64)*(unsigned __int16 *)(v2 + 5802) >> v4) & 1) != 0 )
        {
          if ( (*(_WORD *)(result + 552) & 0x184) == 0 )
          {
            if ( *(_DWORD *)(v2 + 4720) == 3 )
            {
              v5 = result;
              lock = _rcu_read_lock(result, a2);
              for ( i = *(_QWORD **)(v2 + 2264); i != (_QWORD *)(v2 + 2264); i = (_QWORD *)*i )
                ++*((_DWORD *)i - 184);
              _rcu_read_unlock(lock);
              result = v5;
            }
            v8 = *(_DWORD *)(v2 + 1528);
            *(_DWORD *)(v2 + 1528) = v8 + 1;
            if ( !v8 )
            {
              v9 = result;
              synchronize_net(result);
              result = v9;
            }
          }
          if ( v3 )
            v10 = v3 + 2688;
          else
            v10 = 0;
          v11 = result;
          v12 = *(_QWORD *)result;
          *(_DWORD *)(result + 40) &= ~1u;
          result = drv_set_key(v12, 1, v2, v10, result + 536);
          if ( (_DWORD)result )
          {
            if ( v3 )
              v13 = (void *)(v3 + 2688);
            else
              v13 = &bcast_addr;
            return printk(&unk_BBF30, v2 + 1640, (unsigned int)*(char *)(v11 + 551), v13);
          }
        }
      }
    }
  }
  return result;
}
