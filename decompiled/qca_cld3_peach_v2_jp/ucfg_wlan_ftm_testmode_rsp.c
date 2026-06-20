__int64 __fastcall ucfg_wlan_ftm_testmode_rsp(__int64 a1, _DWORD *a2)
{
  __int64 comp_private_obj; // x0
  __int64 v4; // x8
  __int64 v5; // x20

  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x17u);
  if ( !comp_private_obj )
    return 16;
  v4 = *(_QWORD *)(comp_private_obj + 24);
  if ( !v4 )
    return 16;
  *a2 = v4;
  v5 = comp_private_obj;
  qdf_mem_copy(a2 + 1, *(const void **)(comp_private_obj + 8), *(unsigned int *)(comp_private_obj + 24));
  *(_QWORD *)(v5 + 24) = 0;
  return 0;
}
