__int64 __fastcall dp_mon_soc_cfg_init(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x21
  unsigned int target_type; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x5
  void (__fastcall *v14)(__int64, __int64); // x8
  __int64 v16; // x0

  v2 = *(_QWORD *)(a1 + 20056);
  v3 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
  target_type = hal_get_target_type(*(__int64 **)(a1 + 1128));
  v13 = target_type;
  switch ( target_type )
  {
    case 0x14u:
      wlan_cfg_set_mon_delayed_replenish_entries(*(_QWORD *)(a1 + 40), 64);
      break;
    case 0x15u:
    case 0x17u:
    case 0x1Bu:
    case 0x1Cu:
    case 0x1Fu:
    case 0x22u:
    case 0x25u:
    case 0x26u:
    case 0x28u:
    case 0x2Au:
    case 0x2Bu:
      break;
    case 0x18u:
    case 0x19u:
    case 0x1Du:
    case 0x1Eu:
    case 0x21u:
    case 0x24u:
      wlan_cfg_set_mon_delayed_replenish_entries(*(_QWORD *)(a1 + 40), 64);
      *(_BYTE *)(v2 + 256) = 1;
      break;
    case 0x1Au:
      wlan_cfg_set_mon_delayed_replenish_entries(*(_QWORD *)(a1 + 40), 64);
      *(_BYTE *)(v2 + 256) = 1;
      if ( *(_BYTE *)(cfg_psoc_get_values(*(_QWORD *)(a1 + 16)) + 608) == 1 )
      {
        if ( v3 )
        {
          v14 = *(void (__fastcall **)(__int64, __int64))(v3 + 24);
          if ( v14 )
          {
            if ( *((_DWORD *)v14 - 1) != 261447488 )
              __break(0x8228u);
            v14(a1, 1);
          }
        }
      }
      break;
    case 0x20u:
    case 0x23u:
    case 0x27u:
    case 0x29u:
      wlan_cfg_set_mon_delayed_replenish_entries(*(_QWORD *)(a1 + 40), 64);
      *(_BYTE *)(v2 + 256) = 1;
      *(_BYTE *)(v2 + 424) = 1;
      break;
    default:
      qdf_trace_msg(
        0x92u,
        5u,
        "%s: %s: Unknown tgt type %d\n",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "dp_mon_soc_cfg_init",
        "dp_mon_soc_cfg_init",
        target_type);
      v16 = printk(
              &unk_9BB309,
              "0",
              "dp_mon_soc_cfg_init",
              "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/dp_mon.c");
      dump_stack(v16);
      break;
  }
  qdf_trace_msg(
    0x92u,
    5u,
    "%s: hw_nac_monitor_support = %d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "dp_mon_soc_cfg_init",
    *(unsigned __int8 *)(v2 + 256),
    v13);
  return 0;
}
