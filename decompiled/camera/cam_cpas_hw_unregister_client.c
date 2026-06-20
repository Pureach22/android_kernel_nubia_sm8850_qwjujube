__int64 __fastcall cam_cpas_hw_unregister_client(__int64 a1, unsigned int a2)
{
  __int64 v2; // x22
  __int64 v5; // x21
  __int64 v6; // x7
  const char *v7; // x5
  __int64 v8; // x4
  unsigned int v9; // w20

  if ( a2 <= 0x2A )
  {
    v2 = *(_QWORD *)(a1 + 3680);
    mutex_lock(a1);
    v5 = v2 + 48LL * a2;
    mutex_lock(v5 + 664);
    v6 = *(_QWORD *)(v2 + 320 + 8LL * a2);
    if ( (*(_BYTE *)(v6 + 168) & 1) != 0 )
    {
      if ( *(_BYTE *)(v6 + 169) != 1 )
      {
        if ( (debug_mdl & 4) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 4,
            4,
            "cam_cpas_hw_unregister_client",
            3387,
            "client=[%d][%s][%d], registered_clients=%d",
            a2,
            (const char *)v6,
            *(_DWORD *)(v6 + 128),
            *(_DWORD *)(v2 + 2788));
          v6 = *(_QWORD *)(v2 + 320 + 8LL * a2);
        }
        *(_BYTE *)(v6 + 168) = 0;
        v9 = 0;
        --*(_DWORD *)(v2 + 2788);
        goto LABEL_12;
      }
      v7 = "Client=[%d][%s][%d] is not stopped";
      v8 = 3377;
    }
    else
    {
      v7 = "Client=[%d][%s][%d] not registered";
      v8 = 3368;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_unregister_client",
      v8,
      v7,
      a2);
    v9 = -1;
LABEL_12:
    mutex_unlock(v5 + 664);
    mutex_unlock(a1);
    return v9;
  }
  return (unsigned int)-22;
}
