__int64 __fastcall tdls_get_vdev(__int64 a1, unsigned int a2)
{
  unsigned int v4; // w21
  unsigned int v5; // w0

  v4 = policy_mgr_mode_specific_vdev_id(a1, 0);
  if ( v4 == 255
    && ((v5 = policy_mgr_mode_specific_vdev_id(a1, 2), v5 == 255)
     || (v4 = v5, (unsigned int)policy_mgr_get_connection_count_with_mlo(a1) != 1)) )
  {
    return 0;
  }
  else
  {
    return ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v4, a2);
  }
}
