__int64 __fastcall wlan_coap_offload_reply_disable(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 comp_private_obj; // x0

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x30u);
    *(_DWORD *)comp_private_obj = a2;
    *(_QWORD *)(comp_private_obj + 8) = a3;
    *(_QWORD *)(comp_private_obj + 16) = a4;
    return tgt_send_coap_offload_reply_disable(a1, a2);
  }
  else
  {
    qdf_trace_msg(0x9Cu, 2u, "%s: Vdev NULL", a5, a6, a7, a8, a9, a10, a11, a12, "wlan_coap_offload_reply_disable");
    return 4;
  }
}
