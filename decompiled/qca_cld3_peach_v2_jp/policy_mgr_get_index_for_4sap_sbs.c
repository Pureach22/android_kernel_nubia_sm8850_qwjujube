__int64 __fastcall policy_mgr_get_index_for_4sap_sbs(__int64 *a1, int *a2, unsigned int *a3)
{
  unsigned int sbs_cut_off_freq; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w21
  unsigned int v15; // w22
  unsigned int v16; // w24
  unsigned int v17; // w23
  __int64 result; // x0
  const char *v19; // x2
  unsigned int v20; // w10
  int v21; // w8
  int v22; // w9
  int v23; // w11
  int v24; // w9
  int v25; // w8
  int v26; // w8

  sbs_cut_off_freq = policy_mgr_get_sbs_cut_off_freq(*a1);
  if ( !sbs_cut_off_freq )
  {
    v19 = "%s: Invalid cutoff freq";
    return qdf_trace_msg(0x4Fu, 2u, v19, v6, v7, v8, v9, v10, v11, v12, v13, "policy_mgr_get_index_for_4sap_sbs");
  }
  v14 = sbs_cut_off_freq;
  if ( wlan_reg_is_24ghz_ch_freq(*a3)
    || (v15 = *a3, wlan_reg_is_24ghz_ch_freq(a3[1]))
    || (v16 = a3[1], wlan_reg_is_24ghz_ch_freq(a3[2]))
    || (v17 = a3[2], result = wlan_reg_is_24ghz_ch_freq(a3[3]), (result & 1) != 0) )
  {
    v19 = "%s: Invalid 2.4 GHz freq in sbs";
    return qdf_trace_msg(0x4Fu, 2u, v19, v6, v7, v8, v9, v10, v11, v12, v13, "policy_mgr_get_index_for_4sap_sbs");
  }
  v20 = a3[3];
  v21 = v16 < v14;
  v22 = v16 >= v14;
  if ( v15 < v14 )
    ++v21;
  else
    ++v22;
  if ( v17 < v14 )
    v23 = v22;
  else
    v23 = v22 + 1;
  if ( v17 < v14 )
    ++v21;
  if ( v20 >= v14 )
    v24 = v21;
  else
    v24 = v21 + 1;
  if ( v20 < v14 )
    v25 = v23;
  else
    v25 = v23 + 1;
  if ( v24 == 2 && v25 == 2 )
  {
    v26 = 6;
LABEL_33:
    *a2 = v26;
    return result;
  }
  if ( v24 == 1 && v25 == 3 )
  {
    v26 = 8;
    goto LABEL_33;
  }
  if ( v24 == 3 && v25 == 1 )
  {
    v26 = 7;
    goto LABEL_33;
  }
  return result;
}
