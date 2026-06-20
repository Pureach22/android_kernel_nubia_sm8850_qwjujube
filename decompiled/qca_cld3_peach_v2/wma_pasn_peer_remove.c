__int64 __fastcall wma_pasn_peer_remove(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int8 *a10,
        unsigned __int8 a11,
        char a12)
{
  __int64 *context; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 *v24; // x21
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // w8
  unsigned int v34; // w0
  unsigned int v35; // w22
  __int64 result; // x0
  __int64 v37; // x4
  __int64 v38; // x5
  __int64 v39; // x6
  __int64 v40; // x7
  const char *v41; // x2
  int v42; // [xsp+8h] [xbp-28h]
  _BYTE v43[4]; // [xsp+14h] [xbp-1Ch] BYREF
  __int64 v44; // [xsp+18h] [xbp-18h]
  int v45; // [xsp+20h] [xbp-10h]
  __int64 v46; // [xsp+28h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(54, (__int64)"wma_pasn_peer_remove", a1, a2, a3, a4, a5, a6, a7, a8);
  v45 = 0;
  v44 = 0;
  v43[0] = 0;
  if ( !context )
  {
    qdf_trace_msg(0x36u, 2u, "%s: wma_handle is NULL", v16, v17, v18, v19, v20, v21, v22, v23, "wma_pasn_peer_remove");
    result = 4;
    goto LABEL_19;
  }
  v24 = context;
  if ( ((unsigned __int8)wma_objmgr_peer_exist((__int64)context, (__int64)a10, v43) & 1) == 0 )
  {
    if ( a10 )
    {
      v37 = *a10;
      v38 = a10[1];
      v39 = a10[2];
      v40 = a10[5];
    }
    else
    {
      v39 = 0;
      v37 = 0;
      v38 = 0;
      v40 = 0;
    }
    v33 = a11;
    v41 = "%s: peer doesn't exist peer_addr %02x:%02x:%02x:**:**:%02x vdevid %d";
    goto LABEL_18;
  }
  v33 = v43[0];
  if ( v43[0] != a11 )
  {
    if ( a10 )
    {
      v37 = *a10;
      v38 = a10[1];
      v39 = a10[2];
      v40 = a10[5];
    }
    else
    {
      v39 = 0;
      v37 = 0;
      v38 = 0;
      v40 = 0;
    }
    v41 = "%s: peer %02x:%02x:%02x:**:**:%02x is on vdev id %d but delete req on vdevid %d";
    v42 = a11;
LABEL_18:
    qdf_trace_msg(
      0x36u,
      2u,
      v41,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "wma_pasn_peer_remove",
      v37,
      v38,
      v39,
      v40,
      v33,
      v42);
    result = 4;
    goto LABEL_19;
  }
  if ( (a12 & 1) != 0 || (LOBYTE(v44) = a11, (v34 = wmi_unified_peer_delete_send(*v24)) == 0) )
  {
    v35 = 0;
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Peer delete could not be sent to firmware %d",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "wma_pasn_peer_remove",
      v34);
    v35 = 16;
  }
  wma_remove_objmgr_peer((__int64)v24, *(_QWORD *)(v24[65] + 488LL * a11), a10, v25, v26, v27, v28, v29, v30, v31, v32);
  result = v35;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
