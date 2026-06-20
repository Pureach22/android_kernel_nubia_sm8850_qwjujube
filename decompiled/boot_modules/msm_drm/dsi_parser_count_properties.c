__int64 __fastcall dsi_parser_count_properties(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x1
  int v3; // w8
  __int64 v4; // x1
  __int64 v5; // x1
  __int64 v6; // x1
  __int64 v7; // x1
  __int64 v8; // x1
  __int64 v9; // x1
  __int64 v10; // x1
  __int64 v11; // x1
  __int64 v12; // x1
  __int64 v13; // x1
  __int64 v14; // x1
  __int64 v15; // x1
  __int64 v16; // x1
  __int64 v17; // x1
  __int64 v18; // x1
  __int64 v19; // x1
  __int64 v20; // x1
  __int64 v21; // x1
  __int64 v22; // x1

  if ( result )
  {
    v1 = result;
    result = *(_QWORD *)(result + 8);
    if ( *(_BYTE *)result )
    {
      result = dsi_parser_count((char *)result);
      v3 = *(_DWORD *)(v1 + 192);
      *(_DWORD *)(v1 + 24) = result;
      if ( v3 >= 1 )
      {
        result = dsi_parser_count_properties(*(_QWORD *)(v1 + 32), v2);
        if ( *(int *)(v1 + 192) >= 2 )
        {
          result = dsi_parser_count_properties(*(_QWORD *)(v1 + 40), v4);
          if ( *(int *)(v1 + 192) > 2 )
          {
            result = dsi_parser_count_properties(*(_QWORD *)(v1 + 48), v5);
            if ( *(int *)(v1 + 192) >= 4 )
            {
              result = dsi_parser_count_properties(*(_QWORD *)(v1 + 56), v6);
              if ( *(int *)(v1 + 192) >= 5 )
              {
                result = dsi_parser_count_properties(*(_QWORD *)(v1 + 64), v7);
                if ( *(int *)(v1 + 192) >= 6 )
                {
                  result = dsi_parser_count_properties(*(_QWORD *)(v1 + 72), v8);
                  if ( *(int *)(v1 + 192) >= 7 )
                  {
                    result = dsi_parser_count_properties(*(_QWORD *)(v1 + 80), v9);
                    if ( *(int *)(v1 + 192) >= 8 )
                    {
                      result = dsi_parser_count_properties(*(_QWORD *)(v1 + 88), v10);
                      if ( *(int *)(v1 + 192) >= 9 )
                      {
                        result = dsi_parser_count_properties(*(_QWORD *)(v1 + 96), v11);
                        if ( *(int *)(v1 + 192) >= 10 )
                        {
                          result = dsi_parser_count_properties(*(_QWORD *)(v1 + 104), v12);
                          if ( *(int *)(v1 + 192) >= 11 )
                          {
                            result = dsi_parser_count_properties(*(_QWORD *)(v1 + 112), v13);
                            if ( *(int *)(v1 + 192) >= 12 )
                            {
                              result = dsi_parser_count_properties(*(_QWORD *)(v1 + 120), v14);
                              if ( *(int *)(v1 + 192) >= 13 )
                              {
                                result = dsi_parser_count_properties(*(_QWORD *)(v1 + 128), v15);
                                if ( *(int *)(v1 + 192) >= 14 )
                                {
                                  result = dsi_parser_count_properties(*(_QWORD *)(v1 + 136), v16);
                                  if ( *(int *)(v1 + 192) >= 15 )
                                  {
                                    result = dsi_parser_count_properties(*(_QWORD *)(v1 + 144), v17);
                                    if ( *(int *)(v1 + 192) >= 16 )
                                    {
                                      result = dsi_parser_count_properties(*(_QWORD *)(v1 + 152), v18);
                                      if ( *(int *)(v1 + 192) >= 17 )
                                      {
                                        result = dsi_parser_count_properties(*(_QWORD *)(v1 + 160), v19);
                                        if ( *(int *)(v1 + 192) >= 18 )
                                        {
                                          result = dsi_parser_count_properties(*(_QWORD *)(v1 + 168), v20);
                                          if ( *(int *)(v1 + 192) >= 19 )
                                          {
                                            result = dsi_parser_count_properties(*(_QWORD *)(v1 + 176), v21);
                                            if ( *(int *)(v1 + 192) >= 20 )
                                            {
                                              result = dsi_parser_count_properties(*(_QWORD *)(v1 + 184), v22);
                                              if ( *(int *)(v1 + 192) > 20 )
                                              {
                                                __break(0x5512u);
                                                JUMPOUT(0x202D88);
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
          }
        }
      }
    }
  }
  return result;
}
