void __fastcall tdls_del_peer_serialize_callback(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int *v10; // x8
  __int64 *v11; // x19
  double v12; // d0
  __int64 v13; // x8
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // [xsp+8h] [xbp-28h] BYREF
  __int64 *v30; // [xsp+10h] [xbp-20h]
  __int64 v31; // [xsp+18h] [xbp-18h]
  __int64 v32; // [xsp+20h] [xbp-10h]
  unsigned int *v33; // [xsp+28h] [xbp-8h]

  v10 = *(unsigned int **)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = v10;
  if ( a1 && (v11 = *(__int64 **)(a1 + 40)) != nullptr )
  {
    if ( a2 > 1 )
    {
      if ( a2 == 2 )
      {
        wlan_objmgr_vdev_release_ref(*v11, 0x11u, v10, a3, a4, a5, a6, a7, a8, a9, a10);
        _qdf_mem_free((__int64)v11);
        goto LABEL_14;
      }
      if ( a2 == 3 )
        goto LABEL_10;
    }
    else
    {
      if ( a2 )
      {
        if ( a2 != 1 )
          goto LABEL_14;
LABEL_10:
        tdls_internal_del_peer_rsp(*(_QWORD *)(a1 + 40));
        goto LABEL_14;
      }
      v31 = 0;
      v29 = *v11;
      v30 = v11 + 1;
      if ( (unsigned int)tdls_pe_del_peer((__int64)&v29) )
      {
        v12 = tdls_internal_del_peer_rsp(v11);
        v13 = *v11;
        v29 = 0xF00000000LL;
        v30 = nullptr;
        v31 = v13;
        v32 = 0;
        qdf_trace_msg(
          0,
          8u,
          "%s: release %s",
          v12,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "tdls_release_serialization_command",
          "TDLS_DEL_PEER_CMD");
        wlan_serialization_remove_cmd((unsigned int *)&v29, v21, v22, v23, v24, v25, v26, v27, v28);
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: cmd: %pK, reason: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "tdls_del_peer_serialize_callback",
      a1,
      (unsigned int)a2);
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
}
