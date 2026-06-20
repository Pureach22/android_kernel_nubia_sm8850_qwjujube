__int64 __fastcall adreno_ringbuffer_waittimestamp(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v5; // x24
  __int64 result; // x0
  __int64 v8; // x22
  char v9; // w0
  __int64 v10; // x8
  __int64 v11; // x23
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 v14; // x3
  __int64 v15; // x4
  __int64 v16; // x5
  char v17; // w8
  __int64 v18; // x0
  __int64 v19; // x23
  char v20; // w8
  bool v21; // cc
  unsigned int v22; // w8
  int v23; // w8
  _QWORD v24[6]; // [xsp+0h] [xbp-30h] BYREF

  v24[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = a1 - 1320LL * *(int *)(a1 + 28);
  if ( a3 )
  {
    result = kgsl_add_event(v5 - 14352, a1 + 40, a2, adreno_ringbuffer_wait_callback, 0);
    if ( (_DWORD)result )
      goto LABEL_40;
    rt_mutex_unlock(v5 - 3264);
    v8 = _msecs_to_jiffies(a3);
    v9 = kgsl_event_pending(v5 - 14352, a1 + 40, a2, adreno_ringbuffer_wait_callback, 0);
    if ( v9 & 1 | (v8 != 0) )
      v10 = v8;
    else
      v10 = 1;
    if ( (v9 & 1) != 0 )
    {
      v11 = v10;
      if ( v10 )
      {
        memset(v24, 0, 40);
        init_wait_entry(v24, 0);
        prepare_to_wait_event(a1 + 1256, v24, 2);
        v17 = kgsl_event_pending(v5 - 14352, a1 + 40, a2, adreno_ringbuffer_wait_callback, 0);
        if ( v17 & 1 | (v8 != 0) )
          v18 = v8;
        else
          v18 = 1;
        if ( (v17 & 1) != 0 && v18 )
        {
          do
          {
            v19 = schedule_timeout(v18, v12, v13, v14, v15, v16);
            prepare_to_wait_event(a1 + 1256, v24, 2);
            v20 = kgsl_event_pending(v5 - 14352, a1 + 40, a2, adreno_ringbuffer_wait_callback, 0);
            if ( v20 & 1 | (v19 != 0) )
              v18 = v19;
            else
              v18 = 1;
          }
          while ( (v20 & 1) != 0 && v18 );
        }
        v11 = v18;
        finish_wait(a1 + 1256, v24);
      }
    }
    else
    {
      v11 = v10;
    }
    rt_mutex_lock(v5 - 3264);
    if ( !v11 )
    {
      result = 4294967186LL;
      goto LABEL_40;
    }
    v23 = *(_DWORD *)(a1 + 28);
    LODWORD(v24[0]) = 0;
    adreno_rb_readtimestamp(a1 - 1320LL * v23 - 14352, a1, 2, v24);
    if ( LODWORD(v24[0]) == a2 || LODWORD(v24[0]) > a2 && ((LODWORD(v24[0]) - a2) & 0x80000000) == 0 )
      goto LABEL_31;
    v21 = (LODWORD(v24[0]) ^ 0x80000000) - (a2 ^ 0x80000000) <= 0x80000000
       && (LODWORD(v24[0]) ^ 0x80000000) > (a2 ^ 0x80000000);
    v22 = -11;
  }
  else
  {
    LODWORD(v24[0]) = 0;
    adreno_rb_readtimestamp(v5 - 14352, a1, 2, v24);
    if ( LODWORD(v24[0]) == a2 || LODWORD(v24[0]) > a2 && ((LODWORD(v24[0]) - a2) & 0x80000000) == 0 )
    {
LABEL_31:
      result = 0;
      goto LABEL_40;
    }
    v21 = (LODWORD(v24[0]) ^ 0x80000000) - (a2 ^ 0x80000000) <= 0x80000000
       && (LODWORD(v24[0]) ^ 0x80000000) > (a2 ^ 0x80000000);
    v22 = -16;
  }
  if ( v21 )
    result = 0;
  else
    result = v22;
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}
