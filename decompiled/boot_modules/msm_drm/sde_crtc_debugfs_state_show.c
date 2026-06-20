__int64 __fastcall sde_crtc_debugfs_state_show(__int64 a1)
{
  __int64 *v1; // x20
  __int64 v3; // x8
  int v4; // w2
  int intf_mode; // w0
  const char *dbus_name; // x0
  const char *v7; // x0
  const char *v8; // x0
  const char *v9; // x0
  const char *v10; // x0
  const char *v11; // x0
  const char *v12; // x0
  const char *v13; // x0

  v1 = *(__int64 **)(a1 + 128);
  seq_printf(a1, "num_connectors: %d\n", *(_DWORD *)(v1[251] + 464));
  if ( v1 && (v3 = v1[251]) != 0 )
    v4 = 2 * (*(_QWORD *)(v3 + 472) != 0);
  else
    v4 = 0;
  seq_printf(a1, "client type: %d\n", v4);
  intf_mode = sde_crtc_get_intf_mode(v1, v1[251]);
  seq_printf(a1, "intf_mode: %d\n", intf_mode);
  seq_printf(a1, "core_clk_rate: %llu\n", v1[932]);
  dbus_name = (const char *)sde_power_handle_get_dbus_name(0);
  seq_printf(a1, "bw_ctl[%s]: %llu\n", dbus_name, v1[928]);
  v7 = (const char *)sde_power_handle_get_dbus_name(0);
  seq_printf(a1, "max_per_pipe_ib[%s]: %llu\n", v7, v1[924]);
  v8 = (const char *)sde_power_handle_get_dbus_name(1);
  seq_printf(a1, "bw_ctl[%s]: %llu\n", v8, v1[929]);
  v9 = (const char *)sde_power_handle_get_dbus_name(1);
  seq_printf(a1, "max_per_pipe_ib[%s]: %llu\n", v9, v1[925]);
  v10 = (const char *)sde_power_handle_get_dbus_name(2);
  seq_printf(a1, "bw_ctl[%s]: %llu\n", v10, v1[930]);
  v11 = (const char *)sde_power_handle_get_dbus_name(2);
  seq_printf(a1, "max_per_pipe_ib[%s]: %llu\n", v11, v1[926]);
  v12 = (const char *)sde_power_handle_get_dbus_name(3);
  seq_printf(a1, "bw_ctl[%s]: %llu\n", v12, v1[931]);
  v13 = (const char *)sde_power_handle_get_dbus_name(3);
  seq_printf(a1, "max_per_pipe_ib[%s]: %llu\n", v13, v1[927]);
  return 0;
}
