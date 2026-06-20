__int64 __fastcall wlan_coap_vdev_obj_create_handler(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 result; // x0
  unsigned int v5; // w20

  if ( !a1 )
    return 4;
  v2 = _qdf_mem_malloc(0x18u, "wlan_coap_vdev_obj_create_handler", 44);
  if ( !v2 )
    return 2;
  v3 = v2;
  result = wlan_objmgr_vdev_component_obj_attach(a1, 0x30u, v2, 0);
  if ( (_DWORD)result )
  {
    v5 = result;
    _qdf_mem_free(v3);
    return v5;
  }
  return result;
}
