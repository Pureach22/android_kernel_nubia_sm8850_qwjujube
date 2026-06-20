__int64 __fastcall cpucp_log_work(__int64 a1)
{
  __int64 v2; // x9
  _QWORD *v3; // x22
  _QWORD *v4; // x20
  _QWORD *v5; // x8
  __int64 v6; // x10
  int v7; // w28
  int v8; // w23
  __int64 v9; // x25
  int v10; // w27
  const char *v11; // x3
  int v12; // w23
  int v13; // w8
  int v14; // w28
  int v15; // w10
  __int64 v16; // x9
  int v17; // w10
  void *v18; // x0
  __int64 v19; // x0
  _QWORD *v20; // x1
  __int64 v21; // x9
  __int64 result; // x0
  _QWORD *v23; // [xsp+0h] [xbp-420h]
  char s[1025]; // [xsp+Fh] [xbp-411h] BYREF
  __int64 v25; // [xsp+410h] [xbp-10h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v2 = raw_spin_lock_irqsave(a1 + 204);
  v3 = *(_QWORD **)(a1 + 184);
  v23 = (_QWORD *)(a1 + 184);
  if ( v3 != (_QWORD *)(a1 + 184) )
  {
    v4 = (_QWORD *)(a1 + 168);
    do
    {
      v5 = (_QWORD *)v3[1];
      if ( (_QWORD *)*v5 == v3 && (v6 = *v3, *(_QWORD **)(*v3 + 8LL) == v3) )
      {
        *(_QWORD *)(v6 + 8) = v5;
        *v5 = v6;
      }
      else
      {
        _list_del_entry_valid_or_report(v3);
      }
      *v3 = 0xDEAD000000000100LL;
      v3[1] = 0xDEAD000000000122LL;
      raw_spin_unlock_irqrestore(a1 + 204, v2);
      v7 = *((_DWORD *)v3 + 6);
      v8 = *(_DWORD *)(a1 + 160);
      v9 = v3[2];
      v10 = *((_DWORD *)v3 + 7) - v8;
      if ( v8 )
      {
        memcpy((void *)(v3[2] + v10), *(const void **)(a1 + 144), *(int *)(a1 + 160));
        *(_DWORD *)(a1 + 160) = 0;
      }
      v11 = (const char *)(v9 + v10);
      v12 = v7 + v8;
LABEL_12:
      v13 = 0;
      if ( v12 >= 1024 )
        v14 = 1024;
      else
        v14 = v12;
      v15 = v14 - 1;
      while ( ((v15 + v13) & 0x80000000) == 0 )
      {
        v16 = (v15 + v13--) & 0x7FFFFFFF;
        if ( v11[v16] == 10 )
        {
          v17 = v12;
          v11[v16] = 0;
          if ( v12 >= 1024LL )
            v17 = 1024;
          if ( v13 == -1 )
          {
LABEL_10:
            snprintf(s, v14 + 1, "%s", v11);
            print_to_trace(*(unsigned int *)(a1 + 112), s);
          }
          else
          {
            v14 = v17 + v13 + 1;
            print_to_trace(*(unsigned int *)(a1 + 112), v11);
          }
          v10 += v14;
          v12 -= v14;
          v11 = (const char *)(v3[2] + v10);
          if ( v12 <= 0 )
            goto LABEL_23;
          goto LABEL_12;
        }
      }
      if ( v12 > 1023 )
        goto LABEL_10;
      v18 = *(void **)(a1 + 144);
      *(_DWORD *)(a1 + 160) = v12;
      memcpy(v18, v11, v12);
LABEL_23:
      v19 = raw_spin_lock_irqsave(a1 + 200);
      v20 = *(_QWORD **)(a1 + 176);
      v21 = v19;
      if ( v3 == v4 || v20 == v3 || (_QWORD *)*v20 != v4 )
      {
        _list_add_valid_or_report(v3, v20, a1 + 168);
      }
      else
      {
        *(_QWORD *)(a1 + 176) = v3;
        *v3 = v4;
        v3[1] = v20;
        *v20 = v3;
      }
      raw_spin_unlock_irqrestore(a1 + 200, v21);
      v2 = raw_spin_lock_irqsave(a1 + 204);
      v3 = (_QWORD *)*v23;
    }
    while ( (_QWORD *)*v23 != v23 );
  }
  result = raw_spin_unlock_irqrestore(a1 + 204, v2);
  _ReadStatusReg(SP_EL0);
  return result;
}
