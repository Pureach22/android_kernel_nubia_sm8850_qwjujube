__int64 __fastcall wlan_tdls_increment_discovery_attempts(__int64 a1, __int64 a2, unsigned __int8 *a3)
{
  unsigned __int8 v4; // w20
  __int64 result; // x0
  __int64 v6; // x19
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  const char *v15; // x2
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _QWORD *peer; // x0
  unsigned __int16 v26; // w9
  __int64 v27; // x5
  __int64 v28; // x6
  __int64 v29; // x7
  int v30; // w8
  __int64 *v31; // [xsp+18h] [xbp-18h] BYREF
  __int64 v32[2]; // [xsp+20h] [xbp-10h] BYREF

  v4 = a2;
  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32[0] = 0;
  v31 = nullptr;
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 17);
  if ( result )
  {
    v6 = result;
    if ( (unsigned int)tdls_get_vdev_objects(result, (__int64 *)&v31, v32) )
    {
      v15 = "%s: Failed to get TDLS objects";
    }
    else
    {
      peer = tdls_get_peer(v31, a3);
      if ( peer )
      {
        v26 = *((_WORD *)peer + 21) + 1;
        *((_WORD *)peer + 21) = v26;
        if ( a3 )
        {
          v27 = *a3;
          v28 = a3[1];
          v29 = a3[2];
          v30 = a3[5];
        }
        else
        {
          v29 = 0;
          v27 = 0;
          v28 = 0;
          v30 = 0;
        }
        qdf_trace_msg(
          0,
          8u,
          "%s: vdev:%d peer: %02x:%02x:%02x:**:**:%02x discovery attempts:%d ",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "wlan_tdls_increment_discovery_attempts",
          v4,
          v27,
          v28,
          v29,
          v30,
          v26);
        goto LABEL_11;
      }
      v15 = "%s: tdls_peer is NULL";
    }
    qdf_trace_msg(0, 2u, v15, v7, v8, v9, v10, v11, v12, v13, v14, "wlan_tdls_increment_discovery_attempts");
LABEL_11:
    result = wlan_objmgr_vdev_release_ref(v6, 0x11u, v16, v17, v18, v19, v20, v21, v22, v23, v24);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
