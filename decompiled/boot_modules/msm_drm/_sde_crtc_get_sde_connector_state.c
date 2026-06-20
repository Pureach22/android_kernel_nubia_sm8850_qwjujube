__int64 __fastcall sde_crtc_get_sde_connector_state(_QWORD *a1, __int64 a2)
{
  __int64 v3; // x8
  _QWORD *v4; // x9
  __int64 v5; // x20
  __int64 v6; // x0
  _QWORD v8[3]; // [xsp+8h] [xbp-18h] BYREF

  v8[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  v8[1] = 0;
  if ( a2 )
  {
    v3 = *(unsigned int *)(a2 + 40);
    if ( (int)v3 < 1 )
    {
LABEL_10:
      v5 = 0;
    }
    else
    {
      v4 = *(_QWORD **)(a2 + 48);
      while ( 1 )
      {
        if ( *v4 )
        {
          v5 = v4[3];
          if ( v5 )
          {
            if ( *(_QWORD **)(v5 + 8) == a1 && *(_DWORD *)(*v4 + 156LL) != 15 )
              break;
          }
        }
        --v3;
        v4 += 5;
        if ( !v3 )
          goto LABEL_10;
      }
    }
  }
  else
  {
    drm_connector_list_iter_begin(*a1, v8);
    v6 = drm_connector_list_iter_next(v8);
    if ( v6 )
    {
      while ( 1 )
      {
        v5 = *(_QWORD *)(v6 + 2512);
        if ( (!v5 || *(_QWORD **)(v5 + 8) == a1) && *(_DWORD *)(v6 + 156) != 15 )
          break;
        v6 = drm_connector_list_iter_next(v8);
        if ( !v6 )
          goto LABEL_12;
      }
    }
    else
    {
LABEL_12:
      v5 = 0;
    }
    drm_connector_list_iter_end(v8);
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
