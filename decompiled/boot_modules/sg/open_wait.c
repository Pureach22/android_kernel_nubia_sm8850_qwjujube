__int64 __fastcall open_wait(__int64 a1, char a2)
{
  __int64 v3; // x0
  unsigned int v4; // w20
  __int64 result; // x0
  __int64 v6; // x0
  __int64 v7; // x20
  __int64 v8; // [xsp+0h] [xbp-30h] BYREF
  __int64 v9; // [xsp+8h] [xbp-28h]
  __int64 v10; // [xsp+10h] [xbp-20h]
  __int64 v11; // [xsp+18h] [xbp-18h]
  __int64 v12; // [xsp+20h] [xbp-10h]
  __int64 v13; // [xsp+28h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 < 0 )
  {
    while ( *(int *)(a1 + 120) >= 1 )
    {
      mutex_unlock(a1 + 32);
      if ( *(_DWORD *)(a1 + 112) || !*(_DWORD *)(a1 + 120) )
      {
LABEL_25:
        mutex_lock(a1 + 32);
      }
      else
      {
        v11 = 0;
        v12 = 0;
        v9 = 0;
        v10 = 0;
        v8 = 0;
        init_wait_entry(&v8, 0);
        while ( 1 )
        {
          v6 = prepare_to_wait_event(a1 + 8, &v8, 1);
          if ( *(_DWORD *)(a1 + 112) || !*(_DWORD *)(a1 + 120) )
          {
            finish_wait(a1 + 8, &v8);
            goto LABEL_25;
          }
          if ( v6 )
            break;
          schedule(0);
        }
        v7 = v6;
        mutex_lock(a1 + 32);
        result = v7;
        if ( (_DWORD)v7 )
          goto LABEL_32;
      }
      if ( *(_DWORD *)(a1 + 112) )
      {
LABEL_31:
        result = 4294967277LL;
        goto LABEL_32;
      }
    }
  }
  else
  {
    while ( *(_BYTE *)(a1 + 116) == 1 )
    {
      mutex_unlock(a1 + 32);
      if ( *(_DWORD *)(a1 + 112) || *(_BYTE *)(a1 + 116) != 1 )
      {
LABEL_11:
        mutex_lock(a1 + 32);
      }
      else
      {
        v11 = 0;
        v12 = 0;
        v9 = 0;
        v10 = 0;
        v8 = 0;
        init_wait_entry(&v8, 0);
        while ( 1 )
        {
          v3 = prepare_to_wait_event(a1 + 8, &v8, 1);
          if ( *(_DWORD *)(a1 + 112) || *(_BYTE *)(a1 + 116) != 1 )
          {
            finish_wait(a1 + 8, &v8);
            goto LABEL_11;
          }
          if ( v3 )
            break;
          schedule(0);
        }
        v4 = v3;
        mutex_lock(a1 + 32);
        result = v4;
        if ( v4 )
          goto LABEL_32;
      }
      if ( *(_DWORD *)(a1 + 112) )
        goto LABEL_31;
    }
  }
  result = 0;
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
