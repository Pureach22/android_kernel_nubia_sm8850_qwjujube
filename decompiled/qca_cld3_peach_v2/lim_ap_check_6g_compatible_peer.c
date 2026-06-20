__int64 __fastcall lim_ap_check_6g_compatible_peer(__int64 result, __int64 a2)
{
  __int64 v3; // x20
  unsigned __int16 i; // w22
  __int64 v5; // x25
  __int64 hash_entry; // x0
  __int64 v7; // x1
  __int64 v8; // x2
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned __int8 *v17; // x24
  unsigned __int64 v18; // x8
  char v19; // w2

  if ( *(_DWORD *)(a2 + 88) != 1 )
    return result;
  v3 = result;
  if ( *(unsigned __int16 *)(a2 + 376) >= 2u )
  {
    for ( i = 1; *(unsigned __int16 *)(a2 + 376) > (unsigned int)i; ++i )
    {
      hash_entry = dph_get_hash_entry(v3, i, a2 + 360);
      if ( hash_entry )
      {
        v17 = (unsigned __int8 *)hash_entry;
        if ( *(_BYTE *)(hash_entry + 356) == 1 )
        {
          if ( !*(_BYTE *)(hash_entry + 1036) )
            goto LABEL_20;
          LODWORD(v18) = *(unsigned __int8 *)(hash_entry + 1037);
          if ( *(_BYTE *)(hash_entry + 1037) )
          {
            v5 = 0;
            while ( v5 != 32 )
            {
              hash_entry = wlan_reg_is_6ghz_op_class(*(_QWORD *)(v3 + 21632), v17[v5 + 1038]);
              v18 = v17[1037];
              if ( (hash_entry & 1) == 0 && ++v5 < v18 )
                continue;
              goto LABEL_5;
            }
            __break(0x5512u);
            return lim_update_he_6ghz_band_caps(hash_entry, v7, v8);
          }
          LOWORD(v5) = 0;
LABEL_5:
          if ( (unsigned int)v18 <= (unsigned __int16)v5 )
          {
LABEL_20:
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: peer %02x:%02x:%02x:**:**:%02x 6ghz not supported",
              v9,
              v10,
              v11,
              v12,
              v13,
              v14,
              v15,
              v16,
              "lim_ap_check_6g_compatible_peer",
              v17[350],
              v17[351],
              v17[352],
              v17[355]);
            v19 = 0;
            return policy_mgr_set_ap_6ghz_capable(*(_QWORD *)(v3 + 21624), *(_BYTE *)(a2 + 10), v19, 8u);
          }
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: peer %02x:%02x:%02x:**:**:%02x 6ghz supported",
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            "lim_ap_check_6g_compatible_peer",
            v17[350],
            v17[351],
            v17[352],
            v17[355]);
        }
      }
    }
  }
  v19 = 1;
  return policy_mgr_set_ap_6ghz_capable(*(_QWORD *)(v3 + 21624), *(_BYTE *)(a2 + 10), v19, 8u);
}
