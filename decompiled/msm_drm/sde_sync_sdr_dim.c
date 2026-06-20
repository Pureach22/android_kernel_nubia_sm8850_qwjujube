__int64 __fastcall sde_sync_sdr_dim(__int64 result, int a2, unsigned __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x8
  __int64 v5; // x22
  __int64 v6; // x19
  __int64 v7; // x21
  int v8; // w8
  unsigned __int64 v9; // x20

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
              v7 = v4 + 4096;
              v8 = a2 != 0;
              *(_BYTE *)(v7 + 1267) = v8;
              v9 = a3 % *(unsigned int *)(v6 + 1488) * *(unsigned int *)(v6 + 1484) / *(unsigned int *)(v6 + 1488)
                 + a3 / *(unsigned int *)(v6 + 1488) * *(unsigned int *)(v6 + 1484);
              if ( *(unsigned __int8 *)(v7 + 1266) == v8 )
              {
                if ( a2 )
                {
                  dsi_panel_dim_handle(*(_QWORD *)(v5 + 264), 1, 0, 0);
                  return zte_set_disp_parameter(v6, 9, v9);
                }
              }
              else
              {
                sync_te(result);
                dsi_panel_dim_handle(*(_QWORD *)(v5 + 264), 0, 0, 0);
                result = zte_set_disp_parameter(v6, 9, v9);
                *(_BYTE *)(v7 + 1266) = *(_BYTE *)(v7 + 1267);
              }
            }
          }
        }
      }
    }
  }
  return result;
}
