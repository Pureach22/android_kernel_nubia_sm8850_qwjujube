__int64 __fastcall policy_mgr_soc_set_dual_mac_cfg_cb(
        unsigned int a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  return qdf_trace_msg(
           0x4Fu,
           8u,
           "%s: Status:%d for scan_config:%x fw_mode_config:%x",
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           "policy_mgr_soc_set_dual_mac_cfg_cb",
           a1,
           a2,
           a3);
}
