__int64 __fastcall adreno_hwsched_log_remove_pending_hw_fences(__int64 a1, __int64 a2)
{
  __int64 next; // x0
  __int64 v5; // x22
  unsigned int v6; // w20
  _QWORD *v7; // x1
  _QWORD *v8; // x1
  _QWORD *v9; // x28
  _QWORD *v10; // t1
  _QWORD *v11; // x8
  __int64 v12; // x10
  __int64 v13; // x11
  __int64 v14; // x9
  __int64 v15; // x9
  __int64 v16; // x9
  __int64 v17; // x9
  __int64 result; // x0
  const char *v19; // x3
  int v20; // [xsp+Ch] [xbp-1F4h] BYREF
  _OWORD s[30]; // [xsp+10h] [xbp-1F0h] BYREF
  __int64 v22; // [xsp+1F0h] [xbp-10h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  raw_read_lock(a1 + 11208);
  v20 = 0;
  next = idr_get_next(a1 + 11184, &v20);
  if ( next )
  {
    v5 = next;
    memset(s, 0, sizeof(s));
    v6 = 0;
    do
    {
      raw_spin_lock(v5 + 404);
      v7 = *(_QWORD **)(v5 + 2056);
      if ( v7 != (_QWORD *)(v5 + 2056) )
      {
        do
        {
          v10 = (_QWORD *)*v7;
          v8 = v7 - 8;
          v9 = v10;
          if ( v6 <= 4 )
          {
            v11 = &s[6 * v6];
            v12 = v8[9];
            v11[8] = v8[8];
            v11[9] = v12;
            v13 = v8[11];
            v11[10] = v8[10];
            v11[11] = v13;
            v14 = v8[5];
            v11[4] = v8[4];
            v11[5] = v14;
            v15 = v8[7];
            v11[6] = v8[6];
            v11[7] = v15;
            v16 = v8[1];
            *v11 = *v8;
            v11[1] = v16;
            v17 = v8[3];
            v11[2] = v8[2];
            v11[3] = v17;
          }
          ++v6;
          adreno_hwsched_remove_hw_fence_entry(a1, v8);
          v7 = v9;
        }
        while ( v9 != (_QWORD *)(v5 + 2056) );
      }
      raw_spin_unlock(v5 + 404);
      ++v20;
      v5 = idr_get_next(a1 + 11184, &v20);
    }
    while ( v5 );
    result = raw_read_unlock(a1 + 11208);
    if ( v6 )
    {
      if ( v6 <= 5 )
        v19 = "They";
      else
        v19 = "First 5";
      dev_err(a2, "%d hw fences may not be signaled. %s are:\n", v6, v19);
      result = dev_err(a2, "%d: ctx=%llu seqno=%llu\n", 0, *(_QWORD *)&s[1], *((_QWORD *)&s[1] + 1));
      if ( v6 != 1 )
      {
        result = dev_err(a2, "%d: ctx=%llu seqno=%llu\n", 1, *(_QWORD *)&s[7], *((_QWORD *)&s[7] + 1));
        if ( v6 != 2 )
        {
          result = dev_err(a2, "%d: ctx=%llu seqno=%llu\n", 2, *(_QWORD *)&s[13], *((_QWORD *)&s[13] + 1));
          if ( v6 != 3 )
          {
            result = dev_err(a2, "%d: ctx=%llu seqno=%llu\n", 3, *(_QWORD *)&s[19], *((_QWORD *)&s[19] + 1));
            if ( v6 != 4 )
              result = dev_err(a2, "%d: ctx=%llu seqno=%llu\n", 4, *(_QWORD *)&s[25], *((_QWORD *)&s[25] + 1));
          }
        }
      }
    }
  }
  else
  {
    result = raw_read_unlock(a1 + 11208);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
