__int64 __fastcall drv_cmd_tput_debug_mode_enable(__int64 *a1, __int64 a2)
{
  __int64 v3; // x21
  __int64 bus_type; // x0
  int v5; // w20
  __int64 conparam; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 result; // x0
  __int64 v16; // x0
  __int64 v17; // x20
  __int64 v18; // x0
  __int64 v19; // x9
  __int64 v20; // x0
  int v21; // w8
  __int64 v22; // x0
  __int64 v23; // x1
  __int64 v24; // [xsp+8h] [xbp-18h] BYREF
  int v25; // [xsp+10h] [xbp-10h]
  __int64 v26; // [xsp+18h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  bus_type = pld_get_bus_type(*(_QWORD *)(a2 + 96));
  v5 = bus_type;
  v25 = 0;
  v24 = 0;
  conparam = hdd_get_conparam(bus_type);
  if ( (_DWORD)conparam != 5 && (unsigned int)hdd_get_conparam(conparam) != 4 )
  {
    v16 = *(unsigned __int8 *)(*(_QWORD *)(v3 + 52824) + 8LL);
    if ( (unsigned int)v16 >= 6 )
    {
      v17 = jiffies;
      if ( hdd_enable_unit_test_commands___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Invalid vdev id",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "hdd_enable_unit_test_commands");
        hdd_enable_unit_test_commands___last_ticks = v17;
      }
      goto LABEL_18;
    }
    if ( v5 == 1 )
    {
      v23 = 68;
      v24 = 0x100000007LL;
    }
    else
    {
      if ( v5 )
      {
LABEL_18:
        result = 4294967274LL;
        goto LABEL_4;
      }
      v24 = 0x100000168LL;
      LODWORD(result) = sme_send_unit_test_cmd(v16, 72, 2, &v24);
      if ( (_DWORD)result )
        goto LABEL_21;
      v18 = *(unsigned __int8 *)(*(_QWORD *)(v3 + 52824) + 8LL);
      v24 = 0x100000169LL;
      LODWORD(result) = sme_send_unit_test_cmd(v18, 72, 2, &v24);
      if ( (_DWORD)result
        || (v19 = *(_QWORD *)(v3 + 52824),
            v25 = 1,
            v20 = *(unsigned __int8 *)(v19 + 8),
            v24 = 0x100000054LL,
            LODWORD(result) = sme_send_unit_test_cmd(v20, 72, 3, &v24),
            (_DWORD)result) )
      {
LABEL_21:
        result = qdf_status_to_os_return(result);
        goto LABEL_4;
      }
      v21 = *(_DWORD *)(a2 + 528);
      if ( v21 == 23 )
      {
        v22 = *(unsigned __int8 *)(*(_QWORD *)(v3 + 52824) + 8LL);
        v24 = 0xBB800000025LL;
        LODWORD(result) = sme_send_unit_test_cmd(v22, 73, 2, &v24);
        if ( (_DWORD)result )
          goto LABEL_21;
        v21 = *(_DWORD *)(a2 + 528);
      }
      if ( v21 != 27 )
      {
        result = 0;
        goto LABEL_4;
      }
      v23 = 73;
      v16 = *(unsigned __int8 *)(*(_QWORD *)(v3 + 52824) + 8LL);
      v24 = 0xBB80000002CLL;
    }
    result = sme_send_unit_test_cmd(v16, v23, 2, &v24);
    if ( !(_DWORD)result )
      goto LABEL_4;
    goto LABEL_21;
  }
  result = 0xFFFFFFFFLL;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
