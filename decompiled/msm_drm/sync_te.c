__int64 __fastcall sync_te(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 v4; // x9
  __int64 v5; // x9
  __int64 v6; // x0
  unsigned int v7; // w9
  __int64 v8; // x20
  __int64 v9; // x21
  __int64 v10; // x19
  __int64 v11; // x8
  __int64 v12; // x9

  if ( result )
  {
    v1 = *(_QWORD *)(result + 328);
    if ( v1 )
    {
      v2 = *(_QWORD *)(v1 + 8);
      if ( v2 )
      {
        v3 = *(_QWORD *)(result + 200);
        if ( v3 )
        {
          if ( *(_DWORD *)(v2 + 2736) == 16 )
          {
            v4 = *(_QWORD *)(v2 + 2760);
            if ( v4 )
            {
              v5 = *(_QWORD *)(v4 + 264);
              if ( v5 )
              {
                v6 = *(_QWORD *)(v2 + 2744);
                v7 = *(_DWORD *)(*(_QWORD *)(v5 + 1424) + 44LL);
                v8 = 0xF4240 / v7;
                if ( v7 <= 0x77 )
                  v9 = 9000;
                else
                  v9 = 200;
                if ( v6 )
                  v6 = sde_encoder_wait_for_event(v6, 2u);
                v10 = *(_QWORD *)(*(_QWORD *)(v3 + 2776) + 16LL);
                v11 = (ktime_get(v6) - v10) / 1000 % v8;
                if ( v11 >= v9 )
                  v12 = v8;
                else
                  v12 = 0;
                return usleep_range_state(v12 - v11 + v9, v12 - v11 + v9 + 10, 2);
              }
            }
          }
        }
      }
    }
  }
  return result;
}
