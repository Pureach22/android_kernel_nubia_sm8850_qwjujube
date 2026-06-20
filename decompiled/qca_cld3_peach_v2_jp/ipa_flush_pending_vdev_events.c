__int64 __fastcall ipa_flush_pending_vdev_events(__int64 result, unsigned __int8 a2)
{
  __int64 v2; // x20
  __int64 comp_private_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  if ( g_ipa_config )
  {
    if ( (*(_BYTE *)g_ipa_config & 1) != 0 )
    {
      v2 = *(_QWORD *)(result + 80);
      result = ipa_cb_is_ready(result);
      if ( (result & 1) != 0 )
      {
        comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v2, 0x1Au);
        if ( comp_private_obj )
          return wlan_ipa_flush_pending_vdev_events(comp_private_obj, a2);
        else
          return qdf_trace_msg(
                   0x61u,
                   2u,
                   "%s: IPA object is NULL",
                   v5,
                   v6,
                   v7,
                   v8,
                   v9,
                   v10,
                   v11,
                   v12,
                   "ipa_flush_pending_vdev_events");
      }
    }
  }
  return result;
}
