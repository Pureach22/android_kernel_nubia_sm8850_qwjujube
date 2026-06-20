void __fastcall dsi_panel_bl_handoff(__int64 a1)
{
  int v2; // w20
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 (*v5)(void); // x8

  v2 = *(_DWORD *)(a1 + 1484) >> 1;
  if ( *(_DWORD *)(a1 + 1472) == 1 )
  {
    v3 = *(_QWORD *)(a1 + 1568);
    if ( v3 )
    {
      v4 = *(_QWORD *)(v3 + 120);
      if ( v4 )
      {
        v5 = *(__int64 (**)(void))(v4 + 16);
        if ( v5 )
        {
          if ( *((_DWORD *)v5 - 1) != 1345616862 )
            __break(0x8228u);
          v2 = v5();
        }
      }
    }
  }
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: cur_bl_level=%d\n", v2);
  *(_DWORD *)(a1 + 1496) = v2;
}
