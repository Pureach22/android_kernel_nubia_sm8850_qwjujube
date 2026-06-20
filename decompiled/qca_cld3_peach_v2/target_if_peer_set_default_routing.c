__int64 __fastcall target_if_peer_set_default_routing(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 *a3,
        unsigned __int8 a4,
        char a5,
        unsigned __int8 a6,
        char a7)
{
  __int64 pdev_by_id; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x19
  __int64 pdev_wmi_handle; // x0
  unsigned int *v24; // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x25
  int v34; // w8
  unsigned int *v35; // x8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x4
  __int64 v45; // x5
  __int64 v46; // x6
  __int64 v47; // x7
  __int64 result; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // [xsp+8h] [xbp-18h] BYREF
  int v58; // [xsp+10h] [xbp-10h]
  __int64 v59; // [xsp+18h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v58 = 0;
  v57 = 0;
  pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, a2, 0x2Du);
  if ( pdev_by_id )
  {
    v22 = pdev_by_id;
    pdev_wmi_handle = lmac_get_pdev_wmi_handle(pdev_by_id, v14, v15, v16, v17, v18, v19, v20, v21);
    if ( pdev_wmi_handle )
    {
      v33 = pdev_wmi_handle;
      qdf_mem_set(&v57, 0xCu, 0);
      v34 = a5 & 1 | (2 * a6);
      if ( a7 )
        v34 = a5 & 1 | (2 * a6) & 0xFF3F | ((a7 & 3) << 6);
      LODWORD(v57) = 19;
      HIDWORD(v57) = v34;
      v58 = a4;
      if ( (unsigned int)wmi_set_peer_param_send(v33) )
      {
        if ( a3 )
        {
          v44 = *a3;
          v45 = a3[1];
          v46 = a3[2];
          v47 = a3[5];
        }
        else
        {
          v46 = 0;
          v44 = 0;
          v45 = 0;
          v47 = 0;
        }
        qdf_trace_msg(
          0x49u,
          2u,
          "%s: Unable to set default routing for peer %02x:%02x:%02x:**:**:%02x",
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          "target_if_peer_set_default_routing",
          v44,
          v45,
          v46,
          v47);
      }
      result = wlan_objmgr_pdev_release_ref(v22, 0x2Du, v35, v36, v37, v38, v39, v40, v41, v42, v43);
    }
    else
    {
      wlan_objmgr_pdev_release_ref(v22, 0x2Du, v24, v25, v26, v27, v28, v29, v30, v31, v32);
      result = qdf_trace_msg(
                 0x49u,
                 2u,
                 "%s: pdev wmi handle NULL",
                 v49,
                 v50,
                 v51,
                 v52,
                 v53,
                 v54,
                 v55,
                 v56,
                 "target_if_peer_set_default_routing");
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x49u,
               2u,
               "%s: pdev with id %d is NULL",
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               "target_if_peer_set_default_routing",
               a2);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
