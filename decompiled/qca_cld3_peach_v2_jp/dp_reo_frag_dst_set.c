__int64 __fastcall dp_reo_frag_dst_set(__int64 a1, _BYTE *a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  result = wlan_cfg_get_dp_soc_nss_cfg(*(_QWORD *)(a1 + 40));
  if ( (unsigned __int8)result > 2u )
  {
    if ( (unsigned __int8)result != 3 && (unsigned __int8)result != 7 )
      return qdf_trace_msg(
               0x7Cu,
               2u,
               "%s: %pK: dp_reo_frag_dst_set invalid offload radio config",
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               "dp_reo_frag_dst_set",
               a1);
    goto LABEL_7;
  }
  if ( (_BYTE)result )
  {
    if ( (unsigned __int8)result != 1 )
      return qdf_trace_msg(
               0x7Cu,
               2u,
               "%s: %pK: dp_reo_frag_dst_set invalid offload radio config",
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               "dp_reo_frag_dst_set",
               a1);
LABEL_7:
    *a2 = 7;
    return result;
  }
  *a2 = 0;
  return result;
}
