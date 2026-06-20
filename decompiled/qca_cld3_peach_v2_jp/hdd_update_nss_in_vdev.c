__int64 __fastcall hdd_update_nss_in_vdev(__int64 *a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v4; // x23
  unsigned int v8; // w20
  __int64 result; // x0
  __int64 v10; // x19

  v4 = *a1;
  v8 = a3;
  sme_update_nss_in_mlme_cfg(a2, a4, a3, *(unsigned int *)(*a1 + 40), 0);
  sme_update_vdev_type_nss(a2, 2, 0);
  sme_update_nss_in_mlme_cfg(a2, a4, v8, *(unsigned int *)(v4 + 40), 1);
  sme_update_vdev_type_nss(a2, 2, 1);
  result = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_update_nss_in_vdev");
  if ( result )
  {
    v10 = result;
    hdd_store_nss_chains_cfg_in_vdev(*(_QWORD *)(v4 + 24), result);
    return _hdd_objmgr_put_vdev_by_user(v10, 6, "hdd_update_nss_in_vdev");
  }
  return result;
}
