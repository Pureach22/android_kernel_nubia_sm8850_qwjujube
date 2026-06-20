__int64 __fastcall sde_crtc_state_in_lb_mode(_QWORD *a1)
{
  _QWORD *v1; // x19
  _QWORD *v2; // x8
  __int64 v3; // x0
  _QWORD v5[3]; // [xsp+8h] [xbp-18h] BYREF

  v1 = a1;
  v5[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v2 = (_QWORD *)*a1;
    if ( *a1 )
    {
      v5[0] = 0;
      v5[1] = 0;
      drm_connector_list_iter_begin(*v2, v5);
      v3 = drm_connector_list_iter_next(v5);
      if ( v3 )
      {
        while ( ((*((_DWORD *)v1 + 4) >> *(_DWORD *)(v3 + 152)) & 1) == 0 || (*(_BYTE *)(v3 + 5129) & 1) == 0 )
        {
          v3 = drm_connector_list_iter_next(v5);
          if ( !v3 )
            goto LABEL_9;
        }
        LODWORD(v1) = 1;
      }
      else
      {
LABEL_9:
        LODWORD(v1) = 0;
      }
      drm_connector_list_iter_end(v5);
    }
    else
    {
      LODWORD(v1) = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v1;
}
