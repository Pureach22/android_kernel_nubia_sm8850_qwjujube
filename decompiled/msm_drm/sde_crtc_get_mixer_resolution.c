_QWORD *__fastcall sde_crtc_get_mixer_resolution(_QWORD *result, __int64 a2, __int64 a3, _DWORD *a4, _DWORD *a5)
{
  __int64 v7; // x9
  _QWORD *v10; // x22
  __int64 v11; // x8
  _QWORD *v12; // x9
  __int64 v13; // x24
  __int64 v14; // x0
  int v15; // w8
  int v16; // w8
  int v17; // w9
  _QWORD v18[3]; // [xsp+8h] [xbp-18h] BYREF

  v18[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *a4 = 0;
  *a5 = 0;
  if ( result && a2 && a3 )
  {
    v7 = *(_QWORD *)(a2 + 328);
    v10 = result;
    v18[0] = 0;
    v18[1] = 0;
    if ( v7 )
    {
      v11 = *(unsigned int *)(v7 + 40);
      if ( (int)v11 < 1 )
      {
LABEL_13:
        v13 = 0;
      }
      else
      {
        v12 = *(_QWORD **)(v7 + 48);
        while ( 1 )
        {
          if ( *v12 )
          {
            v13 = v12[3];
            if ( v13 )
            {
              if ( *(_QWORD **)(v13 + 8) == result && *(_DWORD *)(*v12 + 156LL) == 15 )
                break;
            }
          }
          --v11;
          v12 += 5;
          if ( !v11 )
            goto LABEL_13;
        }
      }
    }
    else
    {
      drm_connector_list_iter_begin(*result, v18);
      while ( 1 )
      {
        v14 = drm_connector_list_iter_next(v18);
        if ( !v14 )
          break;
        v13 = *(_QWORD *)(v14 + 2512);
        if ( v13 && *(_QWORD **)(v13 + 8) == v10 && *(_DWORD *)(v14 + 156) == 15 )
          goto LABEL_21;
      }
      v13 = 0;
LABEL_21:
      drm_connector_list_iter_end(v18);
    }
    result = (_QWORD *)sde_cp_get_ai_scaler_io_res(a2);
    v15 = *((_DWORD *)v10 + 548);
    if ( v15 && *(_BYTE *)(a2 + 6921) == 1 )
      v15 = *(_DWORD *)(a2 + 7084);
    if ( *(_DWORD *)(a2 + 2048) && (*(_BYTE *)(a2 + 6921) & 1) == 0 )
    {
      *a4 = *(_DWORD *)(a2 + 2064);
      v16 = *(_DWORD *)(a2 + 2068);
    }
    else if ( *((_BYTE *)v10 + 7956) == 1 )
    {
      *a4 = *((_DWORD *)v10 + 1990) / (unsigned int)v15;
      v16 = *((_DWORD *)v10 + 1991);
    }
    else if ( v13 && (v17 = *(_DWORD *)(v13 + 3264)) != 0 )
    {
      *a4 = *(_DWORD *)(v13 + 3284) * v17 / (unsigned int)v15;
      v16 = *(_DWORD *)(v13 + 3288);
    }
    else
    {
      *a4 = *(unsigned __int16 *)(a3 + 4) / v15;
      v16 = *(unsigned __int16 *)(a3 + 14);
    }
    *a5 = v16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
