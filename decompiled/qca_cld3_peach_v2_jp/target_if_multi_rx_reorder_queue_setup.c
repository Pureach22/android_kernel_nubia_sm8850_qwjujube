__int64 __fastcall target_if_multi_rx_reorder_queue_setup(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  __int64 pdev_by_id; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20
  __int64 pdev_wmi_handle; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int16 v30; // w11
  unsigned __int64 v31; // x9
  char v32; // w12
  char v33; // w8
  unsigned __int64 v34; // x10
  _QWORD *v35; // x14
  __int64 result; // x0
  unsigned int *v37; // x8
  unsigned int v38; // w21
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  _QWORD s[37]; // [xsp+8h] [xbp-128h] BYREF

  s[36] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x120u);
  v10 = *(_QWORD *)(a1 + 8);
  if ( v10 )
  {
    pdev_by_id = wlan_objmgr_get_pdev_by_id(*(_QWORD *)(v10 + 280), *(_BYTE *)(v10 + 289), 0x2Du);
    if ( pdev_by_id )
    {
      v20 = pdev_by_id;
      pdev_wmi_handle = lmac_get_pdev_wmi_handle(pdev_by_id, v12, v13, v14, v15, v16, v17, v18, v19);
      if ( pdev_wmi_handle )
      {
        v30 = *(unsigned __int8 *)(v10 + 288);
        v31 = *(unsigned int *)(v10 + 292);
        v32 = *(_BYTE *)(v10 + 290);
        v33 = 0;
        s[34] = v10 + 272;
        HIWORD(s[35]) = v30;
        v34 = -272;
        LODWORD(s[35]) = v31;
        BYTE4(s[35]) = v32;
        do
        {
          if ( ((v31 >> v33) & 1) != 0 )
          {
            v35 = &s[v34 / 8];
            v35[34] = *(_QWORD *)(v10 + v34 + 272);
            *((_WORD *)v35 + 140) = *(_WORD *)(v10 + v34 + 280);
            *((_BYTE *)v35 + 284) = *(_BYTE *)(v10 + v34 + 284);
            *((_WORD *)v35 + 141) = *(_WORD *)(v10 + v34 + 282);
          }
          v34 += 16LL;
          ++v33;
        }
        while ( v34 );
        v38 = wmi_unified_peer_multi_rx_reorder_queue_setup_send(pdev_wmi_handle);
      }
      else
      {
        qdf_trace_msg(
          0x49u,
          2u,
          "%s: pdev wmi handle NULL",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "target_if_multi_rx_reorder_queue_setup");
        v38 = 16;
      }
      wlan_objmgr_pdev_release_ref(v20, 0x2Du, v37, v39, v40, v41, v42, v43, v44, v45, v46);
      _qdf_mem_free(v10);
      result = v38;
    }
    else
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: pdev with id %d is NULL",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "target_if_multi_rx_reorder_queue_setup",
        *(unsigned __int8 *)(v10 + 289));
      result = 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: rx_reorder: Invalid message body",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "target_if_multi_rx_reorder_queue_setup");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
