void __fastcall walt_find_new_ilb(__int64 a1, _DWORD *a2, _DWORD *a3)
{
  __int64 v5; // x25
  _QWORD *v6; // x8
  unsigned __int64 StatusReg; // x27
  char v8; // w9
  unsigned __int64 v9; // x9
  unsigned __int64 v10; // x21
  int v11; // w0
  _QWORD *v12; // x8
  __int64 v13; // x25
  unsigned __int64 v14; // x27
  char v15; // w9
  unsigned __int64 v16; // x9
  unsigned __int64 v17; // x20
  int v18; // w0

  if ( (walt_disabled & 1) == 0 )
  {
    *a3 = nr_cpu_ids;
    if ( num_sched_clusters - 1 >= 1 )
    {
      v5 = 0;
      v6 = (_QWORD *)cpu_array;
      StatusReg = _ReadStatusReg(SP_EL0);
      while ( 2 )
      {
        v8 = 0;
        do
        {
          v9 = (unsigned int)(-1LL << v8) & *a2 & *(_QWORD *)(*v6 + 8 * v5);
          if ( !v9 )
            break;
          v10 = __clz(__rbit64(v9));
          if ( *(_DWORD *)(StatusReg + 40) != (_DWORD)v10 )
          {
            v11 = available_idle_cpu((unsigned int)v10);
            v6 = (_QWORD *)cpu_array;
            if ( v11 )
            {
              if ( ((_cpu_online_mask >> v10) & 1) != 0 )
              {
LABEL_11:
                *a3 = v10;
                return;
              }
            }
          }
          v8 = v10 + 1;
        }
        while ( v10 < 0x1F );
        if ( ++v5 < num_sched_clusters - 1 )
          continue;
        break;
      }
      if ( num_sched_clusters - 1 >= 1 )
      {
        v12 = (_QWORD *)cpu_array;
        v13 = 0;
        v14 = _ReadStatusReg(SP_EL0);
        do
        {
          v15 = 0;
          do
          {
            v16 = (unsigned int)(-1LL << v15) & (unsigned int)*(_QWORD *)(*v12 + 8 * v13);
            if ( !(_DWORD)v16 )
              break;
            v17 = __clz(__rbit64(v16));
            if ( *(_DWORD *)(v14 + 40) != (_DWORD)v17 )
            {
              v18 = available_idle_cpu((unsigned int)v17);
              v12 = (_QWORD *)cpu_array;
              if ( v18 )
              {
                LODWORD(v10) = v17;
                if ( ((_cpu_online_mask >> v17) & 1) != 0 )
                  goto LABEL_11;
              }
            }
            v15 = v17 + 1;
          }
          while ( v17 < 0x1F );
          ++v13;
        }
        while ( v13 < num_sched_clusters - 1 );
      }
    }
  }
}
