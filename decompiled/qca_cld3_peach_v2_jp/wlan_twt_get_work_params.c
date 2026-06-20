__int64 __fastcall wlan_twt_get_work_params(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  int v14; // w9

  result = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Cu);
  if ( !result )
    return qdf_trace_msg(
             0x96u,
             2u,
             "%s: twt vdev private obj is null",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "wlan_twt_get_work_params");
  v14 = *(_DWORD *)(result + 8);
  *(_WORD *)(a2 + 4) = *(_WORD *)(result + 12);
  *(_DWORD *)a2 = v14;
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(result + 4);
  *(_BYTE *)(a2 + 12) = *(_BYTE *)(result + 14);
  *a3 = *(_DWORD *)(result + 16);
  return result;
}
