__int64 __fastcall mlo_mgr_update_link_info_mac_addr(__int64 result, _BYTE *a2)
{
  __int64 v3; // x8
  unsigned __int8 *v4; // x20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  int v13; // w8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  int v31; // w8
  __int64 v32; // [xsp+0h] [xbp-10h]
  __int64 v33; // [xsp+0h] [xbp-10h]

  if ( result )
  {
    if ( a2 )
    {
      v3 = *(_QWORD *)(result + 1360);
      if ( v3 )
      {
        v4 = *(unsigned __int8 **)(v3 + 3880);
        qdf_mem_copy(v4, a2 + 5, 6u);
        v4[12] = a2[4];
        if ( v4 )
          v13 = v4[5];
        else
          v13 = 0;
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: Update STA Link info for vdev_id %d, link_addr:%02x:%02x:%02x:**:**:%02x",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "mlo_mgr_update_link_info_mac_addr",
          v13);
        qdf_mem_copy(v4 + 48, a2 + 12, 6u);
        v4[60] = a2[11];
        if ( v4 == (unsigned __int8 *)-48LL )
          v22 = 0;
        else
          v22 = v4[53];
        LODWORD(v32) = v22;
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: Update STA Link info for vdev_id %d, link_addr:%02x:%02x:%02x:**:**:%02x",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "mlo_mgr_update_link_info_mac_addr",
          v32);
        qdf_mem_copy(v4 + 96, a2 + 19, 6u);
        v4[108] = a2[18];
        if ( v4 == (unsigned __int8 *)-96LL )
          v31 = 0;
        else
          v31 = v4[101];
        LODWORD(v33) = v31;
        return qdf_trace_msg(
                 0x8Fu,
                 8u,
                 "%s: Update STA Link info for vdev_id %d, link_addr:%02x:%02x:%02x:**:**:%02x",
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 "mlo_mgr_update_link_info_mac_addr",
                 v33);
      }
    }
  }
  return result;
}
