__int64 __fastcall rmnet_get_packets(__int64 result, _QWORD *a2, __int64 *a3)
{
  __int64 v3; // x21
  __int64 lock; // x0
  __int64 i; // x8
  __int64 j; // x13
  __int64 v9; // x13
  __int64 v10; // x14
  char v11; // w15
  unsigned __int64 v12; // x15
  unsigned __int64 v13; // x15
  __int64 v14; // x16
  bool v15; // cf
  _QWORD *v16; // x16

  if ( a2 )
  {
    v3 = result;
    if ( result )
    {
      if ( a3 )
      {
        *a3 = 0;
        *a2 = 0;
        lock = _rcu_read_lock();
        for ( i = 0; i != 255; ++i )
        {
          for ( j = *(_QWORD *)(v3 + 16 + 8 * i); j; j = *(_QWORD *)(v9 + 16) )
          {
            v9 = j - 16;
            if ( !v9 )
              break;
            v10 = *(_QWORD *)(v9 + 8);
            if ( v10 )
            {
              v11 = 0;
              do
              {
                v12 = (unsigned int)(-1LL << v11) & _cpu_possible_mask;
                if ( !(_DWORD)v12 )
                  break;
                lock = *a3;
                v13 = __clz(__rbit64(v12));
                v14 = _per_cpu_offset[v13];
                v15 = v13 >= 0x1F;
                v11 = v13 + 1;
                v16 = (_QWORD *)(v14 + *(_QWORD *)(v10 + 2704));
                *a3 += v16[2];
                *a2 += *v16;
              }
              while ( !v15 );
            }
          }
        }
        return _rcu_read_unlock(lock);
      }
    }
  }
  return result;
}
