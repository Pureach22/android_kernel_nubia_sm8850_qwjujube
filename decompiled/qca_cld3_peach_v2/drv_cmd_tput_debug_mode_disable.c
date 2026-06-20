__int64 __fastcall drv_cmd_tput_debug_mode_disable(__int64 *a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 bus_type; // x0
  int v4; // w19
  __int64 conparam; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 result; // x0
  __int64 v15; // x0
  __int64 v16; // x20
  __int64 v17; // x8
  __int64 v18; // x8
  __int64 v19; // x8
  __int64 v20; // x1
  __int64 v21; // [xsp+0h] [xbp-10h] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  bus_type = pld_get_bus_type(*(_QWORD *)(a2 + 96));
  v4 = bus_type;
  v21 = 0;
  conparam = hdd_get_conparam(bus_type);
  if ( (_DWORD)conparam != 5 && (unsigned int)hdd_get_conparam(conparam) != 4 )
  {
    v15 = *(unsigned __int8 *)(*(_QWORD *)(v2 + 52832) + 8LL);
    if ( (unsigned int)v15 >= 6 )
    {
      v16 = jiffies;
      if ( hdd_disable_unit_test_commands___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Invalid vdev id",
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          "hdd_disable_unit_test_commands",
          v21,
          v22);
        hdd_disable_unit_test_commands___last_ticks = v16;
      }
      goto LABEL_14;
    }
    if ( v4 == 1 )
    {
      v20 = 68;
      v21 = 7;
    }
    else
    {
      if ( v4 )
      {
LABEL_14:
        result = 4294967274LL;
        goto LABEL_4;
      }
      v21 = 360;
      LODWORD(result) = sme_send_unit_test_cmd(v15, 72, 2, &v21);
      if ( (_DWORD)result
        || (v17 = *(_QWORD *)(v2 + 52832),
            v21 = 361,
            LODWORD(result) = sme_send_unit_test_cmd(*(unsigned __int8 *)(v17 + 8), 72, 2, &v21),
            (_DWORD)result)
        || (v18 = *(_QWORD *)(v2 + 52832),
            v21 = 44,
            LODWORD(result) = sme_send_unit_test_cmd(*(unsigned __int8 *)(v18 + 8), 73, 2, &v21),
            (_DWORD)result) )
      {
LABEL_17:
        result = qdf_status_to_os_return(result);
        goto LABEL_4;
      }
      v19 = *(_QWORD *)(v2 + 52832);
      v21 = 84;
      v20 = 73;
      v15 = *(unsigned __int8 *)(v19 + 8);
    }
    result = sme_send_unit_test_cmd(v15, v20, 2, &v21);
    if ( !(_DWORD)result )
      goto LABEL_4;
    goto LABEL_17;
  }
  result = 0xFFFFFFFFLL;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
