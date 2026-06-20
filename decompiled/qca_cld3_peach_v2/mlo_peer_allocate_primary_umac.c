__int64 __fastcall mlo_peer_allocate_primary_umac(__int64 a1, _BYTE *a2, __int64 *a3)
{
  __int64 mlo_ctx; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _BYTE *v15; // x1
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x8
  __int64 v19; // x8
  char v20; // w8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x4
  __int64 v31; // x5
  const char *v32; // x2

  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  v15 = a2 + 16;
  v16 = *((_QWORD *)a2 + 2);
  if ( !v16 )
    return 16;
  if ( mlo_ctx )
  {
    if ( *(_BYTE *)(mlo_ctx + 378) == 1 && a2[97] )
    {
      v17 = *a3;
      if ( *a3 && *(_QWORD *)(v16 + 96) != v17 || (v17 = a3[1]) != 0 && *(_QWORD *)(v16 + 96) != v17 )
      {
        v18 = *(_QWORD *)(v17 + 216);
        if ( v18 && (v19 = *(_QWORD *)(v18 + 80)) != 0 )
          v20 = *(_BYTE *)(v19 + 48);
        else
          v20 = -1;
        a2[186] = v20;
      }
      mlo_peer_assign_primary_umac(a2, v15);
      v30 = *(unsigned __int8 *)(a1 + 16);
      v31 = (unsigned __int8)a2[104];
      v32 = "%s: MLD ID %d ML Peer %02x:%02x:%02x:**:**:%02x primary umac soc %d ";
    }
    else
    {
      mlo_peer_assign_primary_umac(a2, v15);
      v30 = *(unsigned __int8 *)(a1 + 16);
      v31 = (unsigned __int8)a2[104];
      v32 = "%s: MLD ID %d Assoc peer %02x:%02x:%02x:**:**:%02x primary umac soc %d ";
    }
    qdf_trace_msg(
      0x8Fu,
      4u,
      v32,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "mlo_peer_allocate_primary_umac",
      v30,
      v31,
      (unsigned __int8)a2[105],
      (unsigned __int8)a2[106],
      (unsigned __int8)a2[109],
      (unsigned __int8)a2[186]);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: MLO context is Null",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "mlo_peer_allocate_primary_umac");
    return 4;
  }
}
