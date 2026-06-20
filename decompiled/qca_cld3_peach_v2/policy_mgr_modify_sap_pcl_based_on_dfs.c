__int64 __fastcall policy_mgr_modify_sap_pcl_based_on_dfs(__int64 a1, __int64 a2, __int64 a3, _DWORD *a4)
{
  __int64 context; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  __int64 v18; // x22
  unsigned int v19; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w19
  __int64 v29; // x23
  unsigned __int64 v30; // x24
  _BYTE v31[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+8h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31[0] = 0;
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    if ( *a4 < 0x67u )
    {
      v18 = context;
      v19 = policy_mgr_skip_dfs_ch(a1, v31);
      if ( v19 )
      {
        v28 = v19;
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: failed to get dfs channel skip info",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "policy_mgr_modify_sap_pcl_based_on_dfs");
        result = v28;
      }
      else if ( v31[0] == 1 )
      {
        if ( *a4 )
        {
          v29 = 0;
          v30 = 0;
          do
          {
            if ( (wlan_reg_is_dfs_in_secondary_list_for_freq(
                    *(_QWORD *)(v18 + 8),
                    *(_DWORD *)(a2 + 4 * v30),
                    v20,
                    v21,
                    v22,
                    v23,
                    v24,
                    v25,
                    v26,
                    v27)
                & 1) == 0 )
            {
              *(_DWORD *)(a2 + 4 * v29) = *(_DWORD *)(a2 + 4 * v30);
              *(_BYTE *)(a3 + v29++) = *(_BYTE *)(a3 + v30);
            }
            ++v30;
          }
          while ( v30 < (unsigned int)*a4 );
        }
        else
        {
          LODWORD(v29) = 0;
        }
        result = 0;
        *a4 = v29;
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid PCL List Length %d",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "policy_mgr_modify_sap_pcl_based_on_dfs");
      result = 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "policy_mgr_modify_sap_pcl_based_on_dfs");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
