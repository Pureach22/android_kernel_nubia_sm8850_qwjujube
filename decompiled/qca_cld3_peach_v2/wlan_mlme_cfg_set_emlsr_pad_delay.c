__int64 __fastcall wlan_mlme_cfg_set_emlsr_pad_delay(__int64 a1, unsigned __int8 a2)
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
  unsigned int v12; // w9

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( !result )
    return qdf_trace_msg(
             0x1Fu,
             2u,
             "%s: No psoc object",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "wlan_mlme_cfg_set_emlsr_pad_delay");
  if ( a2 <= 4u )
  {
    v12 = *(unsigned __int16 *)(result + 7334);
    if ( ((v12 >> 1) & 7) < a2 )
    {
      *(_WORD *)(result + 7334) = v12 & 0xFFF1 | (2 * (a2 & 0x7F));
      return qdf_trace_msg(
               0x68u,
               8u,
               "%s: EMLSR padding delay configured to %d",
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               "wlan_mlme_cfg_set_emlsr_pad_delay",
               a2);
    }
  }
  return result;
}
