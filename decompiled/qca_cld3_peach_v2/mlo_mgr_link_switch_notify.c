__int64 __fastcall mlo_mgr_link_switch_notify(__int64 a1, __int64 a2)
{
  __int64 mlo_ctx; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x22
  __int64 v14; // x23
  unsigned int v15; // w21
  char v16; // w27
  unsigned int v17; // w24
  __int64 v18; // x22
  _BYTE *v19; // x28
  _DWORD *v20; // x8
  unsigned int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w26

  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  if ( mlo_ctx )
  {
    v13 = *(_QWORD *)(a1 + 1360);
    v14 = mlo_ctx;
    qdf_mutex_acquire(v13 + 1656);
    v15 = *(_DWORD *)(*(_QWORD *)(v13 + 3880) + 164LL);
    qdf_mutex_release(v13 + 1656);
    if ( v15 )
    {
      if ( v15 == 5 )
      {
        v16 = 0;
        v15 = 3;
      }
      else
      {
        v16 = 0;
        if ( v15 != 1 )
          v15 = 2;
      }
    }
    else
    {
      v16 = 1;
    }
    v18 = 0;
    v17 = 0;
    v19 = (_BYTE *)(v14 + 392);
    do
    {
      if ( *(v19 - 8) == 1 )
      {
        v20 = *(_DWORD **)v19;
        if ( *(_DWORD *)(*(_QWORD *)v19 - 4LL) != 1523735030 )
          __break(0x8228u);
        v21 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v20)(a1, a2, v15);
        if ( v21 )
        {
          v30 = v21;
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: Link switch notify %d failed in %d",
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            "mlo_mgr_link_switch_notify",
            v15,
            (unsigned int)v18);
          v17 = v30;
          if ( (v16 & 1) != 0 )
            break;
        }
      }
      ++v18;
      v19 += 16;
    }
    while ( v18 != 54 );
  }
  else
  {
    qdf_trace_msg(0x8Fu, 2u, "%s: Global mlo mgr NULL", v5, v6, v7, v8, v9, v10, v11, v12, "mlo_mgr_link_switch_notify");
    return 29;
  }
  return v17;
}
