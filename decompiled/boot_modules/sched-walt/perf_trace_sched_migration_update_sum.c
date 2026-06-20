__int64 __fastcall perf_trace_sched_migration_update_sum(__int64 result, __int64 a2, int a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v5; // x23
  __int64 v8; // x19
  __int64 v10; // x24
  unsigned __int64 StatusReg; // x25
  _QWORD *v12; // x9
  __int64 v13; // x9
  __int64 v14; // x10
  __int64 v15; // x10
  __int64 v16; // x10
  __int64 v17; // x10
  __int64 v18; // x10
  __int64 v19; // x10
  __int64 v20; // x10
  __int64 v21; // x8
  __int64 v22; // x9
  __int64 v23; // x10
  __int64 v24; // x10
  __int64 v25; // x10
  __int64 v26; // x10
  __int64 v27; // x10
  __int64 v28; // x10
  __int64 v29; // x10
  __int64 v30; // x2
  __int64 v31; // x5
  __int64 v32; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v33; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v34[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v35; // [xsp+20h] [xbp+0h] BYREF

  v5 = v4;
  v8 = result;
  v34[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34[0] = 0;
  v10 = *(_QWORD *)(result + 104);
  v33 = 0;
  StatusReg = _ReadStatusReg(TPIDR_EL1);
  if ( *(_QWORD *)(result + 112) || *(_QWORD *)(StatusReg + v10) )
  {
    result = perf_trace_buf_alloc(92, v34, &v33);
    if ( result )
    {
      v12 = (_QWORD *)v34[0];
      *(_QWORD *)(v34[0] + 232LL) = &v35;
      v12[31] = &v32;
      v12[32] = v5;
      v12[33] = 5;
      *(_DWORD *)(result + 8) = *(_DWORD *)(a2 + 40);
      *(_DWORD *)(result + 12) = *(_DWORD *)(a2 + 1800);
      *(_DWORD *)(result + 16) = a3;
      if ( a3 )
      {
        if ( a3 != 1 )
        {
          v21 = -22;
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
          goto LABEL_25;
        }
        v13 = *(unsigned int *)(a4 + 3632);
        if ( (unsigned int)v13 < 0x20 )
        {
          *(_QWORD *)(result + 24) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v13) + 144];
          v14 = *(unsigned int *)(a4 + 3632);
          if ( (unsigned int)v14 < 0x20 )
          {
            *(_QWORD *)(result + 32) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v14) + 152];
            v15 = *(unsigned int *)(a4 + 3632);
            if ( (unsigned int)v15 < 0x20 )
            {
              *(_QWORD *)(result + 40) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v15) + 176];
              v16 = *(unsigned int *)(a4 + 3632);
              if ( (unsigned int)v16 < 0x20 )
              {
                *(_QWORD *)(result + 48) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v16) + 184];
                v17 = *(unsigned int *)(a4 + 3632);
                if ( (unsigned int)v17 < 0x20 )
                {
                  *(_QWORD *)(result + 56) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v17) + 160];
                  v18 = *(unsigned int *)(a4 + 3632);
                  if ( (unsigned int)v18 < 0x20 )
                  {
                    *(_QWORD *)(result + 64) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v18) + 168];
                    v19 = *(unsigned int *)(a4 + 3632);
                    if ( (unsigned int)v19 < 0x20 )
                    {
                      *(_QWORD *)(result + 72) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v19) + 192];
                      v20 = *(unsigned int *)(a4 + 3632);
                      if ( (unsigned int)v20 < 0x20 )
                      {
                        v21 = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v20) + 200];
LABEL_25:
                        v30 = v33;
                        v31 = v34[0];
                        *(_QWORD *)(result + 80) = v21;
                        result = perf_trace_run_bpf_submit(result, 92, v30, v8, 1, v31, StatusReg + v10, 0);
                        goto LABEL_26;
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
        v22 = *(unsigned int *)(a4 + 3632);
        if ( (unsigned int)v22 < 0x20 )
        {
          *(_QWORD *)(result + 24) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v22) + 176];
          v23 = *(unsigned int *)(a4 + 3632);
          if ( (unsigned int)v23 < 0x20 )
          {
            *(_QWORD *)(result + 32) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v23) + 184];
            v24 = *(unsigned int *)(a4 + 3632);
            if ( (unsigned int)v24 < 0x20 )
            {
              *(_QWORD *)(result + 40) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v24) + 144];
              v25 = *(unsigned int *)(a4 + 3632);
              if ( (unsigned int)v25 < 0x20 )
              {
                *(_QWORD *)(result + 48) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v25) + 152];
                v26 = *(unsigned int *)(a4 + 3632);
                if ( (unsigned int)v26 < 0x20 )
                {
                  *(_QWORD *)(result + 56) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v26) + 192];
                  v27 = *(unsigned int *)(a4 + 3632);
                  if ( (unsigned int)v27 < 0x20 )
                  {
                    *(_QWORD *)(result + 64) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v27) + 200];
                    v28 = *(unsigned int *)(a4 + 3632);
                    if ( (unsigned int)v28 < 0x20 )
                    {
                      *(_QWORD *)(result + 72) = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v28) + 160];
                      v29 = *(unsigned int *)(a4 + 3632);
                      if ( (unsigned int)v29 < 0x20 )
                      {
                        v21 = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v29) + 168];
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
      __break(0x5512u);
    }
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
