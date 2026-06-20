__int64 __fastcall wlan_ftm_pdev_obj_destroy_notification(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 comp_private_obj; // x0
  _QWORD *v5; // x19
  __int64 v6; // x0

  v1 = *(_QWORD *)(a1 + 80);
  if ( !v1 )
    return 5;
  v2 = *(_QWORD *)(v1 + 2800);
  if ( v2 )
  {
    if ( *(_DWORD *)(v2 + 5768) != 5 )
      return 0;
    comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x17u);
    if ( comp_private_obj )
    {
      v5 = (_QWORD *)comp_private_obj;
      wlan_objmgr_pdev_component_obj_detach(a1, 0x17u, comp_private_obj);
      v6 = v5[1];
      if ( v6 )
      {
        _qdf_mem_free(v6);
        v5[1] = 0;
        v5[3] = 0;
      }
      *v5 = 0;
      _qdf_mem_free((__int64)v5);
      return 0;
    }
  }
  return 5;
}
