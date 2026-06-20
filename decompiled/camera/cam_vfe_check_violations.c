__int64 __fastcall cam_vfe_check_violations(__int64 result, __int64 a2, __int64 a3, _QWORD *a4, _BYTE *a5)
{
  __int64 v5; // x25
  unsigned int v6; // w8
  const char *v9; // x23
  unsigned int v10; // w19
  unsigned __int64 v11; // x26
  __int64 v12; // x24
  __int64 v13; // x20
  __int64 v14; // x8
  int v15; // w8
  __int64 v16; // x8
  int v17; // w8

  v5 = a3 + 0x8000;
  v6 = *(_DWORD *)(a3 + 34732);
  if ( v6 )
  {
    v9 = (const char *)result;
    v10 = 0;
    v11 = (unsigned int)a2;
    do
    {
      v12 = *(_QWORD *)(v5 + 1992) + 152LL * (int)v10;
      v13 = *(_QWORD *)(v12 + 24);
      if ( !v13 )
        return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 8,
                 1,
                 "cam_vfe_check_violations",
                 3444,
                 "VFE:%u out data is null, res_id: %d",
                 *(_DWORD *)(a3 + 8),
                 v10);
      if ( *(_DWORD *)(v13 + 32) )
      {
        v14 = *(_QWORD *)(v13 + 40);
        result = *(_QWORD *)(v14 + 24);
        if ( ((v11 >> *(_DWORD *)(result + 120)) & 1) != 0 )
        {
          result = cam_vfe_bus_ver3_print_wm_info(result, *(_QWORD *)(v13 + 16), a3, v14 + 128);
          *a4 |= 1LL << *(_BYTE *)(v12 + 4);
          v15 = *(_DWORD *)(v13 + 8);
          if ( v15 == 35 || v15 == 27 )
          {
            result = strcmp(v9, "Image Size");
            if ( !(_DWORD)result )
              *a5 = 1;
          }
        }
        if ( *(_DWORD *)(v13 + 32) >= 2u )
        {
          v16 = *(_QWORD *)(v13 + 48);
          result = *(_QWORD *)(v16 + 24);
          if ( ((v11 >> *(_DWORD *)(result + 120)) & 1) != 0 )
          {
            result = cam_vfe_bus_ver3_print_wm_info(result, *(_QWORD *)(v13 + 16), a3, v16 + 128);
            *a4 |= 1LL << *(_BYTE *)(v12 + 4);
            v17 = *(_DWORD *)(v13 + 8);
            if ( v17 == 35 || v17 == 27 )
            {
              result = strcmp(v9, "Image Size");
              if ( !(_DWORD)result )
                *a5 = 1;
            }
          }
          if ( *(_DWORD *)(v13 + 32) > 2u )
          {
            __break(0x5512u);
            return cam_vfe_bus_ver3_put_evt_payload(result, a2);
          }
        }
        v6 = *(_DWORD *)(v5 + 1964);
      }
      ++v10;
    }
    while ( v10 < v6 );
  }
  return result;
}
