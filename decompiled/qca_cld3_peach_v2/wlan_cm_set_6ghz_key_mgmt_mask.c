__int64 __fastcall wlan_cm_set_6ghz_key_mgmt_mask(__int64 a1, unsigned int a2)
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
  __int64 v12; // x20

  result = wlan_psoc_mlme_get_cmpt_obj(a1);
  if ( result )
  {
    v12 = result;
    result = qdf_trace_msg(
               0x68u,
               8u,
               "%s: key_mgmt_mask_6ghz %x",
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               "wlan_cm_set_6ghz_key_mgmt_mask",
               a2);
    *(_DWORD *)(v12 + 2052) = a2;
  }
  return result;
}
