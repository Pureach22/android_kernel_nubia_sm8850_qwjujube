__int64 __fastcall cam_cpastop_notify_clients(__int64 result, _DWORD *a2, char a3)
{
  __int64 v5; // x21
  unsigned __int64 v6; // x8
  unsigned __int64 i; // x22
  __int64 v8; // x28
  _DWORD *v9; // x9
  __int64 v10; // x0
  __int64 v11; // x1

  v5 = result;
  if ( (debug_mdl & 4) != 0 && !debug_priority )
  {
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               debug_mdl & 4,
               4,
               "cam_cpastop_notify_clients",
               888,
               "Notify CB : num_clients=%d, registered=%d, started=%d",
               *(_DWORD *)(result + 2776),
               *(_DWORD *)(result + 2788),
               *(_DWORD *)(result + 2792));
    v6 = *(unsigned int *)(v5 + 2776);
    if ( (_DWORD)v6 )
      goto LABEL_4;
  }
  else
  {
    v6 = *(unsigned int *)(result + 2776);
    if ( (_DWORD)v6 )
    {
LABEL_4:
      for ( i = 0; i < v6; ++i )
      {
        if ( i <= 0x2A )
        {
          v8 = *(_QWORD *)(v5 + 320 + 8 * i);
          if ( *(_BYTE *)(v8 + 168) == 1 && *(_BYTE *)(v8 + 169) == 1 )
          {
            v9 = *(_DWORD **)(v8 + 152);
            if ( v9 )
            {
              if ( (debug_mdl & 4) != 0 && !debug_priority )
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 4,
                  4,
                  "cam_cpastop_notify_clients",
                  896,
                  "Calling client CB %d : %d",
                  i,
                  *a2);
                v9 = *(_DWORD **)(v8 + 152);
              }
              v10 = *(unsigned int *)(v8 + 160);
              v11 = *(_QWORD *)(v8 + 144);
              if ( *(v9 - 1) != 605523998 )
                __break(0x8229u);
              result = ((__int64 (__fastcall *)(__int64, __int64, _DWORD *))v9)(v10, v11, a2);
              if ( (result & 1) != 0 && (a3 & 1) == 0 )
                return result;
              v6 = *(unsigned int *)(v5 + 2776);
            }
          }
        }
      }
    }
  }
  return result;
}
