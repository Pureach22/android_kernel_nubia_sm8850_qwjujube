__int64 __fastcall mhi_irq_handler(__int64 a1, __int64 *a2)
{
  __int64 v2; // x8
  _QWORD *v3; // x9
  unsigned __int64 v4; // x12
  unsigned __int64 v5; // x11
  __int64 v6; // x9
  unsigned __int64 v7; // x10
  unsigned __int64 v8; // x12
  bool v9; // cc
  __int64 v10; // x0
  __int64 v11; // x8
  void (*v12)(void); // x8
  int v13; // w10
  __int64 v14; // x19
  __int64 v15; // x8
  unsigned __int64 v23; // x8
  unsigned __int64 v26; // x8

  v2 = *a2;
  v3 = *(_QWORD **)(*a2 + 264);
  if ( v3 )
  {
    v4 = a2[6];
    v5 = *(_QWORD *)(*v3 + 44LL * *((unsigned int *)a2 + 4) + 28);
    v6 = *(_QWORD *)(v2 + 16);
    v7 = v5 - v4;
    if ( v5 >= v4 && ((v8 = a2[13] + v4, (v5 & 0xF) == 0) ? (v9 = v8 > v5) : (v9 = 0), v9) )
    {
      if ( a2[10] != a2[9] + v7 )
      {
        if ( *((_BYTE *)a2 + 257) == 1 )
        {
          v10 = *(_QWORD *)(a2[1] + 272);
          if ( v10 )
          {
            v11 = *(_QWORD *)(v10 + 176);
            if ( v11 )
            {
              v12 = *(void (**)(void))(v11 - 8);
              if ( v12 )
              {
                if ( *((_DWORD *)v12 - 1) != -1699139795 )
                  __break(0x8228u);
                v12();
              }
            }
          }
        }
        else
        {
          v13 = *((_DWORD *)a2 + 8);
          if ( v13 )
          {
            if ( v13 == 2 )
            {
              queue_work_on(32, *(_QWORD *)(v2 + 448), a2 + 26);
            }
            else if ( v13 == 1 )
            {
              _X9 = (unsigned __int64 *)(a2 + 22);
              __asm { PRFM            #0x11, [X9] }
              do
                v23 = __ldxr(_X9);
              while ( __stlxr(v23 | 1, _X9) );
              __dmb(0xBu);
              if ( (v23 & 1) == 0 )
                _tasklet_hi_schedule(a2 + 21);
            }
            else
            {
              v15 = *(_QWORD *)(v6 + 192);
              if ( v15 && !*(_DWORD *)(v15 + 24) )
                ipc_log_string(*(_QWORD *)(v15 + 32), "[D][%s] skip unknown priority event\n", "mhi_irq_handler");
            }
          }
          else
          {
            _X9 = (unsigned __int64 *)(a2 + 22);
            __asm { PRFM            #0x11, [X9] }
            do
              v26 = __ldxr(_X9);
            while ( __stlxr(v26 | 1, _X9) );
            __dmb(0xBu);
            if ( (v26 & 1) == 0 )
              _tasklet_schedule(a2 + 21);
          }
        }
      }
    }
    else
    {
      v14 = *(_QWORD *)(v6 + 192);
      dev_err(v6 + 40, "[E][%s] Event ring rp points outside of the event ring\n", "mhi_irq_handler");
      if ( v14 && *(_DWORD *)(v14 + 24) <= 2u )
        ipc_log_string(
          *(_QWORD *)(v14 + 32),
          "[E][%s] Event ring rp points outside of the event ring\n",
          "mhi_irq_handler");
    }
  }
  return 1;
}
