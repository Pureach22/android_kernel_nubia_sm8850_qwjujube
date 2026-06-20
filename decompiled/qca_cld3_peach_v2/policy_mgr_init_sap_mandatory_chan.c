__int64 __fastcall policy_mgr_init_sap_mandatory_chan(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  __int64 v5; // x1
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // x9
  __int64 v17; // x0
  __int64 v18; // x1

  if ( wlan_reg_is_5ghz_ch_freq(a2) )
  {
    policy_mgr_init_sap_mandatory_chan_by_band(a1, 3);
    result = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
    if ( result )
    {
      v14 = *(unsigned int *)(result + 960);
      if ( (_DWORD)v14 )
      {
        v15 = 0;
        do
        {
          if ( v15 == 408 )
          {
            __break(0x5512u);
            return policy_mgr_init_sap_mandatory_chan_by_band(result, v5);
          }
          if ( *(_DWORD *)(result + 552 + v15) == a2 )
            return result;
          v15 += 4;
        }
        while ( 4 * v14 != v15 );
        v16 = *(unsigned int *)(result + 960);
        if ( (unsigned int)v14 < 0x66 )
          goto LABEL_16;
        return qdf_trace_msg(
                 0x4Fu,
                 2u,
                 "%s: mand list overflow (%u)",
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 v13,
                 "policy_mgr_add_sap_mandatory_chan",
                 a2);
      }
      else
      {
        v16 = 0;
LABEL_16:
        *(_DWORD *)(result + 960) = v14 + 1;
        *(_DWORD *)(result + 4 * v16 + 552) = a2;
      }
    }
    else
    {
      return qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: Invalid Context",
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               "policy_mgr_add_sap_mandatory_chan");
    }
  }
  else
  {
    if ( wlan_reg_is_6ghz_chan_freq(a2) )
    {
      v17 = a1;
      v18 = 7;
    }
    else
    {
      v17 = a1;
      v18 = 1;
    }
    return policy_mgr_init_sap_mandatory_chan_by_band(v17, v18);
  }
  return result;
}
