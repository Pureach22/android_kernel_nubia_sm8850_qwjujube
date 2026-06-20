__int64 __fastcall qmp_send_data(__int64 a1, unsigned int *a2)
{
  __int64 result; // x0
  __int64 v4; // x22
  __int64 v6; // x23
  __int64 v7; // x20
  __int64 v8; // x19
  unsigned int v9; // w20
  __int64 v10; // x1
  unsigned int *v11; // x24
  __int64 v12; // x21
  int v13; // w0
  unsigned __int64 v14; // x8
  __int64 v15; // x9
  unsigned __int64 i; // x10

  result = 4294967274LL;
  if ( a2 )
  {
    v4 = *(_QWORD *)(a1 + 240);
    if ( v4 )
    {
      v6 = a1;
      if ( (completion_done(v4 + 360) & 1) != 0 )
      {
        v7 = *(_QWORD *)(v4 + 496);
        if ( (*(_BYTE *)(v7 + 153) & 1) != 0 || (*(_BYTE *)(v7 + 154) & 1) != 0 )
        {
          return 4294967290LL;
        }
        else
        {
          v8 = raw_spin_lock_irqsave(v4 + 320);
          if ( (*(_BYTE *)(v4 + 177) & 1) != 0 )
          {
            v9 = -11;
          }
          else if ( (unsigned __int64)*a2 + 4 <= *(unsigned int *)(v4 + 188) )
          {
            v10 = *((_QWORD *)a2 + 1);
            v11 = a2;
            v12 = *(_QWORD *)(v4 + 168) + *(unsigned int *)(v4 + 184);
            memcpy32_toio(v12 + 4, v10);
            writel(*v11, v12);
            v13 = readl(v12);
            v14 = *(unsigned int *)(v4 + 40);
            *(_BYTE *)(v4 + 177) = 1;
            if ( (int)v14 >= 1 )
            {
              v15 = *(_QWORD *)(v4 + 32);
              for ( i = 0; i < v14; ++i )
              {
                if ( v15 == v6 )
                  *(_DWORD *)(v4 + 180) = i;
                v15 += 248;
              }
            }
            ipc_log_string(
              *(_QWORD *)(v7 + 144),
              "[%s]: Copied buffer to msgram sz:%d i:%d\n",
              "qmp_send_data",
              v13,
              *(_DWORD *)(v4 + 180));
            send_irq(v7);
            queue_delayed_work_on(32, system_wq, v4 + 392, 250);
            v9 = 0;
          }
          else
          {
            v9 = -22;
          }
          raw_spin_unlock_irqrestore(v4 + 320, v8);
          return v9;
        }
      }
      else
      {
        return 4294967274LL;
      }
    }
  }
  return result;
}
