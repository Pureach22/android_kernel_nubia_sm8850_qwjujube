__int64 __fastcall wlan_tdls_delete_all_peers(__int64 result, unsigned int a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 v5; // x20
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _DWORD *v14; // x8

  v2 = *(_QWORD *)(result + 216);
  if ( v2 )
  {
    v3 = *(_QWORD *)(v2 + 80);
    if ( v3 )
    {
      v5 = result;
      result = wlan_objmgr_psoc_get_comp_private_obj(v3, 0xAu);
      if ( result )
      {
        v14 = *(_DWORD **)(result + 640);
        if ( v14 )
        {
          if ( *(v14 - 1) != 349571447 )
            __break(0x8228u);
          return ((__int64 (__fastcall *)(__int64, _QWORD))v14)(v5, a2);
        }
      }
      else
      {
        return qdf_trace_msg(
                 0,
                 2u,
                 "%s: Failed to get tdls psoc component",
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 v13,
                 "wlan_tdls_delete_all_peers");
      }
    }
  }
  return result;
}
