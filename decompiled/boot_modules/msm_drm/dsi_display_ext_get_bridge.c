__int64 __fastcall dsi_display_ext_get_bridge(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 i; // x20
  __int64 v6; // x8
  int v7; // w9
  __int64 v8; // x9
  __int64 v9; // x8
  _QWORD v10[3]; // [xsp+8h] [xbp-18h] BYREF

  v10[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = 0;
  v10[1] = 0;
  if ( a1 && *(_QWORD *)(a1 + 112) )
  {
    drm_connector_list_iter_begin(
      *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 104) + 56LL) + 8LL) + 136LL),
      v10);
    v3 = drm_connector_list_iter_next(v10);
    for ( i = 0; v3; v3 = drm_connector_list_iter_next(v10) )
    {
      if ( *(_QWORD *)(v3 + 2744) == *(_QWORD *)(a1 + 112) )
      {
        v6 = *(_QWORD *)(v3 + 2760);
        v7 = *(_DWORD *)(v6 + 160);
        if ( v7 )
        {
          if ( *(_QWORD *)(v6 + 304) == a1 )
          {
            i = v6 + 288;
          }
          else if ( v7 != 1 )
          {
            v8 = *(_QWORD *)(v6 + 568);
            v9 = v6 + 552;
            if ( v8 == a1 )
              i = v9;
          }
        }
      }
    }
    drm_connector_list_iter_end(v10);
  }
  else
  {
    printk(&unk_26A841, a2);
    i = 0;
  }
  _ReadStatusReg(SP_EL0);
  return i;
}
