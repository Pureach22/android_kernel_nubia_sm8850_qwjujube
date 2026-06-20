__int64 __fastcall mlme_set_peer_pmf_status(__int64 a1, char a2)
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

  result = wlan_objmgr_peer_get_comp_private_obj(a1, 0);
  if ( !result )
    return qdf_trace_msg(
             0x1Fu,
             2u,
             "%s:  peer mlme component object is NULL",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "mlme_set_peer_pmf_status");
  *(_BYTE *)(result + 20) = a2 & 1;
  return result;
}
