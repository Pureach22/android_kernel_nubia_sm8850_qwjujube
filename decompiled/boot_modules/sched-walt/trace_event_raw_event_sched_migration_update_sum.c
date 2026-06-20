__int64 __fastcall trace_event_raw_event_sched_migration_update_sum(__int64 a1, __int64 a2, int a3, __int64 a4)
{
  __int64 v7; // x1
  __int64 v8; // x8
  __int64 result; // x0
  __int64 v10; // x9
  __int64 v11; // x10
  __int64 v12; // x10
  __int64 v13; // x10
  __int64 v14; // x10
  __int64 v15; // x10
  __int64 v16; // x10
  __int64 v17; // x10
  __int64 v18; // x8
  __int64 v19; // x9
  __int64 v20; // x10
  __int64 v21; // x10
  __int64 v22; // x10
  __int64 v23; // x10
  __int64 v24; // x10
  __int64 v25; // x10
  __int64 v26; // x10
  _QWORD v28[7]; // [xsp+8h] [xbp-38h] BYREF

  v7 = a1;
  v28[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 72);
  memset(v28, 0, 48);
  if ( (v8 & 0x2C0) == 0 || (v8 & 0x100) != 0 || (result = _trace_trigger_soft_disabled(a1), v7 = a1, (result & 1) == 0) )
  {
    result = trace_event_buffer_reserve(v28, v7, 88);
    if ( result )
    {
      *(_DWORD *)(result + 8) = *(_DWORD *)(a2 + 40);
      *(_DWORD *)(result + 12) = *(_DWORD *)(a2 + 1800);
      *(_DWORD *)(result + 16) = a3;
      if ( a3 )
      {
        if ( a3 != 1 )
        {
          v18 = -22;
          __break(0x800u);
          *(_QWORD *)(result + 24) = -22;
          *(_QWORD *)(result + 32) = -22;
          __break(0x800u);
          __break(0x800u);
          *(_QWORD *)(result + 40) = -22;
          *(_QWORD *)(result + 48) = -22;
          __break(0x800u);
          __break(0x800u);
          *(_QWORD *)(result + 56) = -22;
          *(_QWORD *)(result + 64) = -22;
          __break(0x800u);
          __break(0x800u);
          *(_QWORD *)(result + 72) = -22;
          __break(0x800u);
          goto LABEL_24;
        }
        v10 = *(unsigned int *)(a4 + 3632);
        if ( (unsigned int)v10 < 0x20 )
        {
          *(_QWORD *)(result + 24) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v10) + 144];
          v11 = *(unsigned int *)(a4 + 3632);
          if ( (unsigned int)v11 < 0x20 )
          {
            *(_QWORD *)(result + 32) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v11) + 152];
            v12 = *(unsigned int *)(a4 + 3632);
            if ( (unsigned int)v12 < 0x20 )
            {
              *(_QWORD *)(result + 40) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v12) + 176];
              v13 = *(unsigned int *)(a4 + 3632);
              if ( (unsigned int)v13 < 0x20 )
              {
                *(_QWORD *)(result + 48) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v13) + 184];
                v14 = *(unsigned int *)(a4 + 3632);
                if ( (unsigned int)v14 < 0x20 )
                {
                  *(_QWORD *)(result + 56) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v14) + 160];
                  v15 = *(unsigned int *)(a4 + 3632);
                  if ( (unsigned int)v15 < 0x20 )
                  {
                    *(_QWORD *)(result + 64) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v15) + 168];
                    v16 = *(unsigned int *)(a4 + 3632);
                    if ( (unsigned int)v16 < 0x20 )
                    {
                      *(_QWORD *)(result + 72) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v16) + 192];
                      v17 = *(unsigned int *)(a4 + 3632);
                      if ( (unsigned int)v17 < 0x20 )
                      {
                        v18 = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v17) + 200];
LABEL_24:
                        *(_QWORD *)(result + 80) = v18;
                        result = trace_event_buffer_commit(v28);
                        goto LABEL_25;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else
      {
        v19 = *(unsigned int *)(a4 + 3632);
        if ( (unsigned int)v19 < 0x20 )
        {
          *(_QWORD *)(result + 24) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v19) + 176];
          v20 = *(unsigned int *)(a4 + 3632);
          if ( (unsigned int)v20 < 0x20 )
          {
            *(_QWORD *)(result + 32) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v20) + 184];
            v21 = *(unsigned int *)(a4 + 3632);
            if ( (unsigned int)v21 < 0x20 )
            {
              *(_QWORD *)(result + 40) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v21) + 144];
              v22 = *(unsigned int *)(a4 + 3632);
              if ( (unsigned int)v22 < 0x20 )
              {
                *(_QWORD *)(result + 48) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v22) + 152];
                v23 = *(unsigned int *)(a4 + 3632);
                if ( (unsigned int)v23 < 0x20 )
                {
                  *(_QWORD *)(result + 56) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v23) + 192];
                  v24 = *(unsigned int *)(a4 + 3632);
                  if ( (unsigned int)v24 < 0x20 )
                  {
                    *(_QWORD *)(result + 64) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v24) + 200];
                    v25 = *(unsigned int *)(a4 + 3632);
                    if ( (unsigned int)v25 < 0x20 )
                    {
                      *(_QWORD *)(result + 72) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v25) + 160];
                      v26 = *(unsigned int *)(a4 + 3632);
                      if ( (unsigned int)v26 < 0x20 )
                      {
                        v18 = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v26) + 168];
                        goto LABEL_24;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      __break(0x5512u);
    }
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
