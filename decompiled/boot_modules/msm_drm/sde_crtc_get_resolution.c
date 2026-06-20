__int64 __fastcall sde_crtc_get_resolution(__int64 result, __int64 a2, __int64 a3, _DWORD *a4, _DWORD *a5)
{
  __int64 v7; // x22
  __int64 v10; // x9
  __int64 v11; // x8
  _QWORD *v12; // x9
  __int64 v13; // x24
  int v14; // w8
  __int64 v15; // x0
  int v16; // w8
  int v17; // w8
  _QWORD v18[3]; // [xsp+8h] [xbp-18h] BYREF

  v18[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *a4 = 0;
  *a5 = 0;
  if ( result && a2 && a3 )
  {
    v7 = result;
    result = sde_cp_get_ai_scaler_io_res(a2);
    v10 = *(_QWORD *)(a2 + 328);
    v18[0] = 0;
    v18[1] = 0;
    if ( v10 )
    {
      v11 = *(unsigned int *)(v10 + 40);
      if ( (int)v11 < 1 )
      {
LABEL_13:
        v13 = 0;
        v14 = *(_DWORD *)(a2 + 2048);
        if ( v14 )
          goto LABEL_26;
        goto LABEL_14;
      }
      v12 = *(_QWORD **)(v10 + 48);
      while ( 1 )
      {
        if ( *v12 )
        {
          v13 = v12[3];
          if ( v13 )
          {
            if ( *(_QWORD *)(v13 + 8) == v7 && *(_DWORD *)(*v12 + 156LL) == 15 )
              break;
          }
        }
        --v11;
        v12 += 5;
        if ( !v11 )
          goto LABEL_13;
      }
    }
    else
    {
      drm_connector_list_iter_begin(*(_QWORD *)v7, v18);
      while ( 1 )
      {
        v15 = drm_connector_list_iter_next(v18);
        if ( !v15 )
          break;
        v13 = *(_QWORD *)(v15 + 2512);
        if ( v13 && *(_QWORD *)(v13 + 8) == v7 && *(_DWORD *)(v15 + 156) == 15 )
          goto LABEL_24;
      }
      v13 = 0;
LABEL_24:
      result = drm_connector_list_iter_end(v18);
    }
    v14 = *(_DWORD *)(a2 + 2048);
    if ( v14 )
    {
LABEL_26:
      if ( (*(_BYTE *)(a2 + 6921) & 1) != 0 )
        goto LABEL_27;
      goto LABEL_29;
    }
LABEL_14:
    if ( (*(_BYTE *)(a2 + 2060) & 1) == 0 || (*(_BYTE *)(a2 + 6921) & 1) != 0 )
    {
LABEL_27:
      if ( *(_BYTE *)(v7 + 7956) == 1 )
      {
        *a4 = *(_DWORD *)(v7 + 7960);
        v16 = *(_DWORD *)(v7 + 7964);
      }
      else if ( v13 && (v17 = *(_DWORD *)(v13 + 3264)) != 0 )
      {
        *a4 = *(_DWORD *)(v13 + 3284) * v17;
        v16 = *(_DWORD *)(v13 + 3288);
      }
      else
      {
        *a4 = *(unsigned __int16 *)(a3 + 4);
        v16 = *(unsigned __int16 *)(a3 + 14);
      }
      goto LABEL_34;
    }
    v14 = *(_DWORD *)(a2 + 2044);
LABEL_29:
    *a4 = *(_DWORD *)(a2 + 2064) * v14;
    v16 = *(_DWORD *)(a2 + 2068);
LABEL_34:
    *a5 = v16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
