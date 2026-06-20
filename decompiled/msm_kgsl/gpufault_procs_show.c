unsigned __int64 __fastcall gpufault_procs_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x22
  int v5; // w4
  signed int v6; // w0
  unsigned __int64 v7; // x19
  int v8; // w4
  int v9; // w4
  int v10; // w4
  int v11; // w4
  int v12; // w4
  int v13; // w4
  int v14; // w4
  int v15; // w4
  int v16; // w4

  v3 = *(_QWORD *)(a1 + 152);
  raw_read_lock(v3 + 24284);
  v5 = *(_DWORD *)(v3 + 24100);
  if ( v5 )
  {
    v6 = scnprintf(a3, 4095, "%s %u\n", (const char *)(v3 + 24084), v5);
    v7 = v6;
    if ( (unsigned int)v6 < 0xFFF )
    {
      v8 = *(_DWORD *)(v3 + 24120);
      if ( v8 )
      {
        v7 = v6 + (__int64)(int)scnprintf(a3 + v6, 4095LL - v6, "%s %u\n", (const char *)(v3 + 24104), v8);
        if ( v7 <= 0xFFE )
        {
          v9 = *(_DWORD *)(v3 + 24140);
          if ( v9 )
          {
            v7 += (int)scnprintf(a3 + v7, 4095 - v7, "%s %u\n", (const char *)(v3 + 24124), v9);
            if ( v7 <= 0xFFE )
            {
              v10 = *(_DWORD *)(v3 + 24160);
              if ( v10 )
              {
                v7 += (int)scnprintf(a3 + v7, 4095 - v7, "%s %u\n", (const char *)(v3 + 24144), v10);
                if ( v7 <= 0xFFE )
                {
                  v11 = *(_DWORD *)(v3 + 24180);
                  if ( v11 )
                  {
                    v7 += (int)scnprintf(a3 + v7, 4095 - v7, "%s %u\n", (const char *)(v3 + 24164), v11);
                    if ( v7 <= 0xFFE )
                    {
                      v12 = *(_DWORD *)(v3 + 24200);
                      if ( v12 )
                      {
                        v7 += (int)scnprintf(a3 + v7, 4095 - v7, "%s %u\n", (const char *)(v3 + 24184), v12);
                        if ( v7 <= 0xFFE )
                        {
                          v13 = *(_DWORD *)(v3 + 24220);
                          if ( v13 )
                          {
                            v7 += (int)scnprintf(a3 + v7, 4095 - v7, "%s %u\n", (const char *)(v3 + 24204), v13);
                            if ( v7 <= 0xFFE )
                            {
                              v14 = *(_DWORD *)(v3 + 24240);
                              if ( v14 )
                              {
                                v7 += (int)scnprintf(a3 + v7, 4095 - v7, "%s %u\n", (const char *)(v3 + 24224), v14);
                                if ( v7 <= 0xFFE )
                                {
                                  v15 = *(_DWORD *)(v3 + 24260);
                                  if ( v15 )
                                  {
                                    v7 += (int)scnprintf(a3 + v7, 4095 - v7, "%s %u\n", (const char *)(v3 + 24244), v15);
                                    if ( v7 <= 0xFFE )
                                    {
                                      v16 = *(_DWORD *)(v3 + 24280);
                                      if ( v16 )
                                        v7 += (int)scnprintf(
                                                     a3 + v7,
                                                     4095 - v7,
                                                     "%s %u\n",
                                                     (const char *)(v3 + 24264),
                                                     v16);
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
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
    v7 = 0;
  }
  raw_read_unlock(v3 + 24284);
  return v7;
}
