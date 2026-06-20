__int64 __fastcall hdd_sysfs_ipa_opt_dp_ctrl_rm_create(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  const char *v10; // x2

  if ( a1 )
  {
    result = sysfs_create_file_ns(a1, &ipaoptdpctrlrm_attribute, 0);
    if ( !(_DWORD)result )
      return result;
    v10 = "%s: could not create ipaoptdpctrlrm sysfs file";
  }
  else
  {
    v10 = "%s: could not get wifi kobject!";
  }
  return qdf_trace_msg(0x33u, 2u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_sysfs_ipa_opt_dp_ctrl_rm_create");
}
