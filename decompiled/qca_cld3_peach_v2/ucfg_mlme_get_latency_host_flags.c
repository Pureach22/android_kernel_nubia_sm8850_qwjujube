__int64 __fastcall ucfg_mlme_get_latency_host_flags(__int64 a1, unsigned __int8 a2, _DWORD *a3)
{
  char v3; // w25
  __int64 psoc_ext_obj_fl; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
  {
    if ( a2 >= 4u )
    {
      __break(0x5512u);
      if ( (v3 & 0x40) != 0 )
        JUMPOUT(0x2DC6B4);
      return ucfg_mlme_get_mws_coex_4g_quick_tdm();
    }
    else
    {
      *a3 = *(_DWORD *)(psoc_ext_obj_fl + 4LL * a2 + 5920);
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: mlme obj null",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "ucfg_mlme_get_latency_host_flags");
    return 4;
  }
}
