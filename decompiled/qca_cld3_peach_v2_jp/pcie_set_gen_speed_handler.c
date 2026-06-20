__int64 __fastcall pcie_set_gen_speed_handler(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int v5; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w19
  __int64 v15; // x21
  _QWORD *context; // x20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x22
  __int64 v34; // x19
  _QWORD v35[2]; // [xsp+0h] [xbp-10h] BYREF

  v35[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35[0] = 0;
  result = _osif_driver_sync_op_start(v35, "pcie_set_gen_speed_handler");
  if ( !(_DWORD)result )
  {
    v5 = param_set_int(a1, a2);
    if ( v5 )
    {
      v14 = v5;
      v15 = jiffies;
      if ( pcie_set_gen_speed_handler___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: param set int failed %d",
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          "pcie_set_gen_speed_handler",
          v5);
        pcie_set_gen_speed_handler___last_ticks = v15;
      }
    }
    else
    {
      context = _cds_get_context(51, (__int64)"__pcie_set_gen_speed_handler", v6, v7, v8, v9, v10, v11, v12, v13);
      v14 = _wlan_hdd_validate_context(
              (__int64)context,
              (__int64)"__pcie_set_gen_speed_handler",
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24);
      if ( !v14 )
      {
        v33 = jiffies;
        if ( _pcie_set_gen_speed_handler___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            4u,
            "%s: Received PCIe gen speed %d",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "__pcie_set_gen_speed_handler",
            (unsigned int)pcie_gen_speed);
          _pcie_set_gen_speed_handler___last_ticks = v33;
        }
        if ( (unsigned int)(pcie_gen_speed - 4) > 0xFFFFFFFC )
        {
          v14 = 0;
          *((_DWORD *)context + 1708) = pcie_gen_speed;
        }
        else
        {
          v34 = jiffies;
          if ( _pcie_set_gen_speed_handler___last_ticks_951 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: invalid pcie gen speed %d",
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              "__pcie_set_gen_speed_handler");
            _pcie_set_gen_speed_handler___last_ticks_951 = v34;
          }
          v14 = -22;
        }
      }
    }
    _osif_driver_sync_op_stop(v35[0], "pcie_set_gen_speed_handler");
    result = v14;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
