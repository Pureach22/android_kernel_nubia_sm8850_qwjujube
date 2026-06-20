__int64 __fastcall tdls_update_peer_kickout_count(__int64 a1, unsigned __int8 *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x2
  __int64 result; // x0
  _QWORD *peer; // x0
  __int64 v15; // x5
  __int64 v16; // x6
  __int64 v17; // x7
  int v18; // w8
  __int64 v19; // [xsp+8h] [xbp-18h] BYREF
  __int64 v20[2]; // [xsp+10h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v20[0] = 0;
  if ( (unsigned int)tdls_get_vdev_objects(a1, &v19, v20) )
  {
    v12 = "%s: Error getting TDLS priv objects";
LABEL_3:
    qdf_trace_msg(0, 2u, v12, v4, v5, v6, v7, v8, v9, v10, v11, "tdls_update_peer_kickout_count");
    result = 16;
    goto LABEL_10;
  }
  peer = tdls_find_peer(v19, a2);
  if ( !peer )
  {
    v12 = "%s: tdls peer not found for mac:";
    goto LABEL_3;
  }
  ++*((_BYTE *)peer + 674);
  if ( a2 )
  {
    v15 = *a2;
    v16 = a2[1];
    v17 = a2[2];
    v18 = a2[5];
  }
  else
  {
    v17 = 0;
    v15 = 0;
    v16 = 0;
    v18 = 0;
  }
  qdf_trace_msg(
    0,
    8u,
    "%s: vdev:%d TDLS peer: %02x:%02x:%02x:**:**:%02x",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "tdls_update_peer_kickout_count",
    *(unsigned __int8 *)(a1 + 168),
    v15,
    v16,
    v17,
    v18);
  result = 0;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
