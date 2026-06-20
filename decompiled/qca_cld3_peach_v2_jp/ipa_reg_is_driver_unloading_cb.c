__int64 __fastcall ipa_reg_is_driver_unloading_cb(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  const char *v10; // x2
  unsigned int v11; // w1
  __int64 result; // x0
  __int64 v13; // x19

  if ( !g_ipa_config || (*(_BYTE *)g_ipa_config & 1) == 0 )
  {
    v10 = "%s: ipa is disabled";
    v11 = 8;
    return qdf_trace_msg(0x61u, v11, v10, a3, a4, a5, a6, a7, a8, a9, a10, "ipa_reg_is_driver_unloading_cb");
  }
  v13 = *(_QWORD *)(a1 + 80);
  result = ipa_cb_is_ready();
  if ( (result & 1) != 0 )
  {
    result = wlan_objmgr_psoc_get_comp_private_obj(v13, 0x1Au);
    if ( result )
    {
      *(_QWORD *)(result + 7384) = a2;
      return result;
    }
    v10 = "%s: IPA object is NULL";
    v11 = 2;
    return qdf_trace_msg(0x61u, v11, v10, a3, a4, a5, a6, a7, a8, a9, a10, "ipa_reg_is_driver_unloading_cb");
  }
  return result;
}
