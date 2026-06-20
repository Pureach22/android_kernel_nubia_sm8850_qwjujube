__int64 __fastcall p2p_set_rand_mac_for_p2p_dev(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        __int64 a4,
        unsigned int a5)
{
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x1
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x24
  unsigned int *v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 result; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w20
  int v49; // [xsp+0h] [xbp-20h]
  int v50; // [xsp+8h] [xbp-18h]
  int v51; // [xsp+10h] [xbp-10h] BYREF
  __int16 v52; // [xsp+14h] [xbp-Ch]
  __int64 v53; // [xsp+18h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v52 = 0;
  v51 = 0;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 5u);
  if ( comp_private_obj )
  {
    v19 = *(unsigned int *)(comp_private_obj + 292);
  }
  else
  {
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: p2p soc context is NULL",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "p2p_psoc_priv_get_sta_vdev_id");
    v19 = 255;
  }
  v20 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v19, 15);
  if ( v20 )
  {
    v29 = v20;
    wlan_mlme_get_p2p_device_mac_addr(v20, (__int64)&v51, v21, v22, v23, v24, v25, v26, v27, v28);
    wlan_objmgr_vdev_release_ref(v29, 0xFu, v30, v31, v32, v33, v34, v35, v36, v37, v38);
    result = p2p_request_random_mac(a1, a2, &v51, a3, a4, a5);
    if ( (_DWORD)result )
    {
      v50 = result;
      v48 = result;
      v49 = HIBYTE(v52);
      qdf_trace_msg(
        0x4Eu,
        2u,
        "%s: vdev %d failed to set rand mac%02x:%02x:%02x:**:**:%02x status: %d",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "p2p_set_rand_mac_for_p2p_dev",
        a2,
        (unsigned __int8)v51,
        BYTE1(v51),
        BYTE2(v51),
        v49,
        v50);
      result = v48;
    }
  }
  else
  {
    qdf_trace_msg(0x4Eu, 2u, "%s: Invalid vdev", v21, v22, v23, v24, v25, v26, v27, v28, "p2p_set_rand_mac_for_p2p_dev");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
