__int64 __fastcall sde_crtc_in_lb_transition(_QWORD *a1, __int64 a2)
{
  __int64 v2; // x19
  _QWORD *v3; // x20
  _QWORD *v4; // x8
  __int64 v5; // x0
  _QWORD *v6; // x8
  __int64 v7; // x0
  __int64 v9; // [xsp+8h] [xbp-18h] BYREF
  __int64 v10; // [xsp+10h] [xbp-10h]
  __int64 v11; // [xsp+18h] [xbp-8h]

  v2 = a2;
  v3 = a1;
  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_11;
  v4 = (_QWORD *)*a1;
  if ( *a1 )
  {
    v9 = 0;
    v10 = 0;
    drm_connector_list_iter_begin(*v4, &v9);
    v5 = drm_connector_list_iter_next(&v9);
    if ( v5 )
    {
      while ( ((*((_DWORD *)v3 + 4) >> *(_DWORD *)(v5 + 152)) & 1) == 0 || (*(_BYTE *)(v5 + 5129) & 1) == 0 )
      {
        v5 = drm_connector_list_iter_next(&v9);
        if ( !v5 )
          goto LABEL_9;
      }
      LODWORD(v3) = 1;
    }
    else
    {
LABEL_9:
      LODWORD(v3) = 0;
    }
    drm_connector_list_iter_end(&v9);
LABEL_11:
    if ( !v2 )
      goto LABEL_24;
    goto LABEL_12;
  }
  LODWORD(v3) = 0;
  if ( !a2 )
    goto LABEL_24;
LABEL_12:
  v6 = *(_QWORD **)v2;
  if ( *(_QWORD *)v2 )
  {
    v9 = 0;
    v10 = 0;
    drm_connector_list_iter_begin(*v6, &v9);
    v7 = drm_connector_list_iter_next(&v9);
    if ( v7 )
    {
      while ( ((*(_DWORD *)(v2 + 16) >> *(_DWORD *)(v7 + 152)) & 1) == 0 || (*(_BYTE *)(v7 + 5129) & 1) == 0 )
      {
        v7 = drm_connector_list_iter_next(&v9);
        if ( !v7 )
          goto LABEL_19;
      }
      LODWORD(v2) = 1;
    }
    else
    {
LABEL_19:
      LODWORD(v2) = 0;
    }
    drm_connector_list_iter_end(&v9);
  }
  else
  {
    LODWORD(v2) = 0;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v3 ^ (unsigned int)v2;
}
