__int64 __fastcall wlan_crypto_get_ml_sta_link_key(
        __int64 a1,
        unsigned __int8 a2,
        __int64 a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x23
  unsigned int v14; // w19
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 comp_private_obj; // x0
  __int64 result; // x0
  int v27; // w2
  unsigned int v28; // w8
  const char *v29; // x2
  __int64 vars0; // [xsp+0h] [xbp+0h] BYREF

  v14 = a2;
  qdf_trace_msg(
    0x1Cu,
    8u,
    "%s: crypto get key index %d link_id %d ",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "wlan_crypto_get_ml_sta_link_key",
    a2,
    (unsigned __int8)a4);
  if ( !a1 )
  {
    v29 = "%s: psoc NULL";
LABEL_10:
    qdf_trace_msg(0x1Cu, 2u, v29, v17, v18, v19, v20, v21, v22, v23, v24, "wlan_crypto_get_ml_sta_link_key");
    return 0;
  }
  if ( !a3 )
  {
    v29 = "%s: link_addr NULL";
    goto LABEL_10;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 14);
  if ( !comp_private_obj )
  {
    v29 = "%s: crypto_psoc_obj NULL";
    goto LABEL_10;
  }
  result = crypto_hash_find_by_linkid_and_macaddr(comp_private_obj, a4, a3);
  if ( result )
  {
    v28 = v14 - 4;
    if ( v14 < 4 )
      return *(_QWORD *)(result + 8LL * v14 + 16);
    if ( (v14 & 0xFE) == 4 )
    {
      if ( v28 <= 1 )
        return *(_QWORD *)(result + 8LL * v28 + 48);
    }
    else if ( v14 - 6 <= 1 )
    {
      return *(_QWORD *)(result + 8LL * (v14 - 6) + 64);
    }
    __break(0x5512u);
    *(_DWORD *)(v12 + 8) = v27;
    *(_DWORD *)(v12 + 12) = (unsigned int)&vars0;
    return wlan_crypto_set_key_req();
  }
  return result;
}
