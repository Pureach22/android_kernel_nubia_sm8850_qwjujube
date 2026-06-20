__int64 __fastcall ucfg_wlan_vdev_mgr_get_tsf_adjust(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  result = wlan_vdev_mlme_get_cmpt_obj(a1);
  if ( !result )
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: VDEV MLME is NULL",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "ucfg_wlan_vdev_mgr_get_tsf_adjust");
  *a2 = *(_QWORD *)(result + 32);
  return result;
}
