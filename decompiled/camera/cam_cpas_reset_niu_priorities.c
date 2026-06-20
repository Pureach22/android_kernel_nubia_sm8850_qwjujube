__int64 __fastcall cam_cpas_reset_niu_priorities(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x9
  __int64 v7; // x9
  __int64 v8; // x9
  __int64 v9; // x9
  __int64 v10; // x9
  __int64 v11; // x9
  __int64 v12; // x9
  __int64 v13; // x9
  __int64 v14; // x9

  v4 = *(_QWORD *)(result + 3392);
  v5 = *(_QWORD *)(v4 + 1616);
  if ( *(_BYTE *)(v5 + 9) )
  {
    *(_DWORD *)(*(_QWORD *)(v5 + 16) + 140LL) = 0;
    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 1616) + 16LL) + 144LL) = 0;
    v6 = *(_QWORD *)(v4 + 1616);
    if ( *(unsigned __int8 *)(v6 + 9) > 1u )
    {
      *(_DWORD *)(*(_QWORD *)(v6 + 24) + 140LL) = 0;
      *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 1616) + 24LL) + 144LL) = 0;
      v7 = *(_QWORD *)(v4 + 1616);
      if ( *(unsigned __int8 *)(v7 + 9) >= 3u )
      {
        *(_DWORD *)(*(_QWORD *)(v7 + 32) + 140LL) = 0;
        *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 1616) + 32LL) + 144LL) = 0;
        v8 = *(_QWORD *)(v4 + 1616);
        if ( *(unsigned __int8 *)(v8 + 9) >= 4u )
        {
          *(_DWORD *)(*(_QWORD *)(v8 + 40) + 140LL) = 0;
          *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 1616) + 40LL) + 144LL) = 0;
          v9 = *(_QWORD *)(v4 + 1616);
          if ( *(unsigned __int8 *)(v9 + 9) >= 5u )
          {
            *(_DWORD *)(*(_QWORD *)(v9 + 48) + 140LL) = 0;
            *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 1616) + 48LL) + 144LL) = 0;
            v10 = *(_QWORD *)(v4 + 1616);
            if ( *(unsigned __int8 *)(v10 + 9) >= 6u )
            {
              *(_DWORD *)(*(_QWORD *)(v10 + 56) + 140LL) = 0;
              *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 1616) + 56LL) + 144LL) = 0;
              v11 = *(_QWORD *)(v4 + 1616);
              if ( *(unsigned __int8 *)(v11 + 9) >= 7u )
              {
                *(_DWORD *)(*(_QWORD *)(v11 + 64) + 140LL) = 0;
                *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 1616) + 64LL) + 144LL) = 0;
                v12 = *(_QWORD *)(v4 + 1616);
                if ( *(unsigned __int8 *)(v12 + 9) >= 8u )
                {
                  *(_DWORD *)(*(_QWORD *)(v12 + 72) + 140LL) = 0;
                  *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 1616) + 72LL) + 144LL) = 0;
                  v13 = *(_QWORD *)(v4 + 1616);
                  if ( *(unsigned __int8 *)(v13 + 9) >= 9u )
                  {
                    *(_DWORD *)(*(_QWORD *)(v13 + 80) + 140LL) = 0;
                    *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 1616) + 80LL) + 144LL) = 0;
                    v14 = *(_QWORD *)(v4 + 1616);
                    if ( *(unsigned __int8 *)(v14 + 9) >= 0xAu )
                    {
                      *(_DWORD *)(*(_QWORD *)(v14 + 88) + 140LL) = 0;
                      *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v4 + 1616) + 88LL) + 144LL) = 0;
                      if ( *(unsigned __int8 *)(*(_QWORD *)(v4 + 1616) + 9LL) > 0xAu )
                      {
                        __break(0x5512u);
                        return cam_cpas_util_apply_client_axi_vote(result, a2, a3, a4);
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
  return result;
}
