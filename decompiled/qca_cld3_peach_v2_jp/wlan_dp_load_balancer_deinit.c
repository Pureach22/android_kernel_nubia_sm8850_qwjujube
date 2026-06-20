_QWORD **__fastcall wlan_dp_load_balancer_deinit(__int64 a1)
{
  _QWORD **result; // x0

  result = (_QWORD **)wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( *((_BYTE *)result + 222) == 1 )
    return qdf_cpuhp_unregister(result + 366);
  return result;
}
