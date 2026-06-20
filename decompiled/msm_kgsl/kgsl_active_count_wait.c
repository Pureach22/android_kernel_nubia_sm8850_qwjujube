__int64 __fastcall kgsl_active_count_wait(__int64 a1, int a2, __int64 a3)
{
  __int64 v6; // x24
  int v7; // w9
  bool v8; // cc
  __int64 v9; // x8
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x3
  __int64 v13; // x4
  __int64 v14; // x5
  int v15; // w8
  bool v16; // cc
  __int64 v17; // x0
  __int64 v18; // x21
  int v19; // w8
  bool v20; // cc
  __int64 result; // x0
  _QWORD v22[6]; // [xsp+0h] [xbp-30h] BYREF

  v22[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)(a1 + 11112) )
  {
    do
    {
      if ( *(_DWORD *)(a1 + 11128) <= a2 )
      {
        result = 0;
        goto LABEL_34;
      }
      rt_mutex_unlock(a1 + 11088);
      v7 = *(_DWORD *)(a1 + 11128);
      if ( a3 )
        v8 = 0;
      else
        v8 = v7 <= a2;
      if ( v8 )
        v9 = 1;
      else
        v9 = a3;
      if ( v7 <= a2 )
      {
        v6 = v9;
      }
      else
      {
        v6 = v9;
        if ( v9 )
        {
          memset(v22, 0, 40);
          init_wait_entry(v22, 0);
          prepare_to_wait_event(a1 + 11144, v22, 2);
          v15 = *(_DWORD *)(a1 + 11128);
          if ( a3 )
            v16 = 0;
          else
            v16 = v15 <= a2;
          if ( v16 )
            v17 = 1;
          else
            v17 = a3;
          if ( v15 > a2 && v17 )
          {
            do
            {
              v18 = schedule_timeout(v17, v10, v11, v12, v13, v14);
              prepare_to_wait_event(a1 + 11144, v22, 2);
              v19 = *(_DWORD *)(a1 + 11128);
              if ( v18 )
                v20 = 0;
              else
                v20 = v19 <= a2;
              if ( v20 )
                v17 = 1;
              else
                v17 = v18;
            }
            while ( v19 > a2 && v17 );
          }
          v6 = v17;
          finish_wait(a1 + 11144, v22);
        }
      }
      rt_mutex_lock(a1 + 11088);
      a3 = v6;
    }
    while ( v6 );
    result = 4294967186LL;
  }
  else
  {
    __break(0x800u);
    result = 4294967274LL;
  }
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
