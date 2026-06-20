__int64 __fastcall wlan_dp_fb_update_num_rx_rings(__int64 a1)
{
  __int64 comp_private_obj; // x19
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x0
  __int64 v11; // x8
  unsigned int (*v12)(void); // x8
  __int64 v13; // x20
  int v14; // w23
  __int64 result; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 (*v18)(void); // x8
  __int64 v19; // [xsp+0h] [xbp-20h]
  __int64 v20; // [xsp+8h] [xbp-18h]
  __int64 v21; // [xsp+10h] [xbp-10h]
  __int64 v22; // [xsp+18h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  v10 = *(_QWORD *)(comp_private_obj + 240);
  v20 = 0;
  v21 = 0;
  v19 = 0;
  if ( v10 && *(_QWORD *)v10 )
  {
    v11 = *(_QWORD *)(*(_QWORD *)v10 + 8LL);
    if ( v11 )
    {
      v12 = *(unsigned int (**)(void))(v11 + 192);
      if ( v12 )
      {
        if ( *((_DWORD *)v12 - 1) != 875927212 )
          __break(0x8228u);
        if ( !v12() )
        {
          v13 = 0;
          v14 = 0;
          while ( 1 )
          {
            if ( (((unsigned __int64)(unsigned int)v19 >> v13) & 1) != 0 && !dp_rx_is_ring_latency_sensitive_reo(v13) )
            {
              v16 = *(_QWORD *)(comp_private_obj + 240);
              if ( v16 && *(_QWORD *)v16 && (v17 = *(_QWORD *)(*(_QWORD *)v16 + 152LL)) != 0 )
              {
                v18 = *(__int64 (**)(void))(v17 + 264);
                if ( v18 )
                {
                  if ( *((_DWORD *)v18 - 1) != -1653155309 )
                    __break(0x8228u);
                  v14 += (v18() & 1) == 0;
                  goto LABEL_14;
                }
              }
              else
              {
                qdf_trace_msg(
                  0x45u,
                  1u,
                  "%s invalid instance",
                  v2,
                  v3,
                  v4,
                  v5,
                  v6,
                  v7,
                  v8,
                  v9,
                  "cdp_ipa_check_is_ring_ipa_rx",
                  v19,
                  v20,
                  v21,
                  v22);
              }
              ++v14;
            }
LABEL_14:
            if ( ++v13 == 8 )
            {
              *(_BYTE *)(comp_private_obj + 2912) = v14;
              result = qdf_trace_msg(
                         0x45u,
                         5u,
                         "%s: fb: num_host_used_rx_rings %d",
                         v2,
                         v3,
                         v4,
                         v5,
                         v6,
                         v7,
                         v8,
                         v9,
                         "wlan_dp_fb_update_num_rx_rings",
                         (unsigned __int8)v14);
              goto LABEL_11;
            }
          }
        }
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x89u,
      8u,
      "%s: Invalid Instance:",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "cdp_txrx_get_psoc_param",
      0,
      0,
      0,
      v22);
  }
  result = qdf_trace_msg(
             0x45u,
             2u,
             "%s: Unable to fetch rx rings mapping",
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             "wlan_dp_fb_update_num_rx_rings",
             v19);
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
