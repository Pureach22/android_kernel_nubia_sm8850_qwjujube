__int64 __fastcall tdls_process_mlo_choice_tdls_vdev(__int64 a1)
{
  __int64 v1; // x21
  __int64 v2; // x19
  unsigned int v3; // w22
  __int64 v4; // x20
  __int64 v5; // x0
  __int64 comp_private_obj; // x20
  __int64 v7; // x0
  __int64 v8; // x20

  v1 = *(_QWORD *)(a1 + 1360);
  v2 = *(_QWORD *)(v1 + 24);
  if ( !v2 )
  {
    v3 = 0;
    v4 = *(_QWORD *)(v1 + 32);
    if ( !v4 )
      goto LABEL_7;
    goto LABEL_5;
  }
  v3 = *(_DWORD *)(wlan_objmgr_vdev_get_comp_private_obj(*(_QWORD *)(v1 + 24), 0xAu) + 960);
  if ( !v3 )
    v2 = 0;
  v4 = *(_QWORD *)(v1 + 32);
  if ( v4 )
  {
LABEL_5:
    if ( v3 < *(_DWORD *)(wlan_objmgr_vdev_get_comp_private_obj(v4, 0xAu) + 960) )
      v2 = v4;
  }
LABEL_7:
  v5 = *(_QWORD *)(v1 + 24);
  if ( v5 && v5 != v2 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v5, 0xAu);
    _qdf_mem_free(*(_QWORD *)(comp_private_obj + 952));
    *(_QWORD *)(comp_private_obj + 952) = 0;
    *(_DWORD *)(comp_private_obj + 960) = 0;
  }
  v7 = *(_QWORD *)(v1 + 32);
  if ( v7 && v7 != v2 )
  {
    v8 = wlan_objmgr_vdev_get_comp_private_obj(v7, 0xAu);
    _qdf_mem_free(*(_QWORD *)(v8 + 952));
    *(_QWORD *)(v8 + 952) = 0;
    *(_DWORD *)(v8 + 960) = 0;
  }
  return v2;
}
