__int64 __fastcall msm_get_conn_state(__int64 a1)
{
  _QWORD *v1; // x8
  __int64 v3; // x0
  __int64 i; // x20
  _QWORD v6[3]; // [xsp+8h] [xbp-18h] BYREF

  v6[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && (v1 = *(_QWORD **)a1) != nullptr )
  {
    v6[0] = 0;
    v6[1] = 0;
    drm_connector_list_iter_begin(*v1, v6);
    v3 = drm_connector_list_iter_next(v6);
    for ( i = 0; v3; v3 = drm_connector_list_iter_next(v6) )
    {
      if ( ((*(_DWORD *)(a1 + 16) >> *(_DWORD *)(v3 + 152)) & 1) != 0 && (!i || *(_DWORD *)(v3 + 156) != 15) )
        i = *(_QWORD *)(v3 + 2512);
    }
    drm_connector_list_iter_end(v6);
  }
  else
  {
    i = 0;
  }
  _ReadStatusReg(SP_EL0);
  return i;
}
