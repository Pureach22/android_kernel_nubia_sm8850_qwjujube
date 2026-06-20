__int64 __fastcall sde_sync_aod_and_fod(__int64 result, int a2, unsigned int a3)
{
  __int64 v3; // x8
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x19
  __int64 v7; // x8
  unsigned int v8; // w20
  __int64 v9; // x21
  unsigned int v10; // w20
  __int64 v11; // x21
  __int64 v12; // x1

  if ( result )
  {
    v3 = *(_QWORD *)(result + 328);
    if ( v3 )
    {
      v4 = *(_QWORD *)(v3 + 8);
      if ( v4 )
      {
        if ( *(_DWORD *)(v4 + 2736) == 16 )
        {
          v5 = *(_QWORD *)(v4 + 2760);
          if ( v5 )
          {
            v6 = *(_QWORD *)(v5 + 264);
            if ( v6 )
            {
              if ( *(_DWORD *)(v6 + 2552) == 3 && *(_DWORD *)(v6 + 2324) != a2 )
              {
                v7 = *(_QWORD *)(v6 + 2536);
                *(_DWORD *)(v6 + 2324) = a2;
                v8 = a3;
                v9 = result;
                queue_work_on(32, v7, v6 + 2504);
                a3 = v8;
                result = v9;
              }
              v10 = (a3 >> 1) & 1;
              if ( (a3 & 1) != *(_BYTE *)(v6 + 2556) )
              {
                v11 = result;
                if ( (a3 & 1) != 0 )
                  v12 = 1;
                else
                  v12 = 2;
                *(_BYTE *)(v6 + 2556) = a3 & 1;
                zte_aod_handler(v6, v12);
                result = v11;
              }
              if ( v10 != *(unsigned __int8 *)(v6 + 2557) )
              {
                *(_BYTE *)(v6 + 2557) = v10;
                sync_te(result);
                return zte_fod_handler(v6, v10);
              }
            }
          }
        }
      }
    }
  }
  return result;
}
