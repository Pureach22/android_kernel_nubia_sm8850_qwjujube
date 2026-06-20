__int64 __fastcall sde_crtc_get_num_datapath(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int lm_cnt_from_topology; // w5
  __int64 v6; // x0
  __int64 v7; // x20
  __int64 v8; // x21
  _QWORD v10[3]; // [xsp+8h] [xbp-18h] BYREF

  v10[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = 0;
  v10[1] = 0;
  if ( !a1 || !a2 || !a3 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "Invalid argument\n");
    goto LABEL_19;
  }
  lm_cnt_from_topology = *(_DWORD *)(a1 + 2192);
  if ( !lm_cnt_from_topology || *(_BYTE *)(a3 + 6921) == 1 && (lm_cnt_from_topology = *(_DWORD *)(a3 + 7084)) == 0 )
  {
    drm_connector_list_iter_begin(*(_QWORD *)a1, v10);
    do
    {
      v6 = drm_connector_list_iter_next(v10);
      if ( !v6 )
      {
        drm_connector_list_iter_end(v10);
        goto LABEL_19;
      }
    }
    while ( v6 == a2 || ((1 << *(_DWORD *)(v6 + 152)) & *(_DWORD *)(a3 + 16)) == 0 );
    v7 = v6;
    v8 = *(_QWORD *)(v6 + 2512);
    drm_connector_list_iter_end(v10);
    if ( !v8 || (lm_cnt_from_topology = *(_DWORD *)(v8 + 2244)) == 0 )
    {
      lm_cnt_from_topology = sde_connector_get_lm_cnt_from_topology(v7, a3 + 24);
      if ( (lm_cnt_from_topology & 0x80000000) != 0 )
      {
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "lm cnt fail for conn:%d num_lm:%d\n", *(_DWORD *)(v7 + 64), lm_cnt_from_topology);
LABEL_19:
        lm_cnt_from_topology = 0;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return lm_cnt_from_topology;
}
