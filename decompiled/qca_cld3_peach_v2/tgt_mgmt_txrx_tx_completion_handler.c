__int64 __fastcall tgt_mgmt_txrx_tx_completion_handler(__int64 a1, unsigned int a2, unsigned int a3, __int64 a4)
{
  __int64 comp_private_obj; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v18; // x25
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x26
  __int64 v21; // x23
  __int64 v22; // x24
  __int64 v23; // x22
  __int64 v24; // x1

  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 1);
  if ( comp_private_obj )
  {
    if ( a2 < 0x40 )
    {
      v18 = *(_QWORD *)(comp_private_obj + 32) + 72LL * a2;
      if ( v18 && (*(_BYTE *)(v18 + 65) & 1) != 0 )
      {
        v19 = *(_QWORD *)(v18 + 16);
        v20 = *(_QWORD *)(v18 + 24);
        v21 = *(_QWORD *)(v18 + 56);
        if ( !v21 )
          v21 = *(_QWORD *)(v18 + 48);
        v22 = *(_QWORD *)(v18 + 32);
        v23 = comp_private_obj;
        if ( v19 | v20 )
        {
          if ( v19 )
          {
            v24 = *(_QWORD *)(v18 + 32);
            if ( *(_DWORD *)(v19 - 4) != 1402114878 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, __int64, bool))v19)(v21, v24, a3 != 0);
          }
          if ( v20 )
          {
            if ( *(_DWORD *)(v20 - 4) != -1755906178 )
              __break(0x823Au);
            ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))v20)(v21, v22, a3, a4);
          }
        }
        else if ( v22 )
        {
          _qdf_nbuf_free(*(_QWORD *)(v18 + 32));
        }
        wlan_objmgr_peer_release_ref(*(_QWORD *)(v18 + 48), 4);
        wlan_mgmt_txrx_desc_put(v23, a2);
        return 0;
      }
      else
      {
        qdf_trace_msg(
          0x4Bu,
          2u,
          "%s: Mgmt desc empty for id %d pdev %pK ",
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          "tgt_mgmt_txrx_tx_completion_handler",
          a2,
          a1);
        return 29;
      }
    }
    else
    {
      qdf_trace_msg(
        0x4Bu,
        2u,
        "%s: desc_id:%u is out of bounds",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "tgt_mgmt_txrx_tx_completion_handler",
        a2);
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Bu,
      2u,
      "%s: Mgmt txrx context empty for pdev %pK",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "tgt_mgmt_txrx_tx_completion_handler",
      a1);
    return 29;
  }
}
