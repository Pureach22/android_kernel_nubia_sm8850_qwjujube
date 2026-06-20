__int64 __fastcall csr_roam_get_session_id_from_bssid(__int64 a1, int *a2, _DWORD *a3)
{
  __int16 v4; // w9
  __int64 v5; // x0
  int v6; // w8
  bool v7; // cc
  int v8; // w8
  int v10; // [xsp+0h] [xbp-10h] BYREF
  __int16 v11; // [xsp+4h] [xbp-Ch]
  unsigned __int8 v12; // [xsp+6h] [xbp-Ah]
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *((_WORD *)a2 + 2);
  v5 = *(_QWORD *)(a1 + 21560);
  v10 = *a2;
  v11 = v4;
  v12 = 6;
  wlan_objmgr_pdev_iterate_obj_list(
    v5,
    2,
    (void (__fastcall *)(__int64, __int64, __int64))csr_get_vdev_id_from_bssid,
    (__int64)&v10,
    0,
    0xBu);
  v6 = v12;
  v7 = v12 > 5u;
  if ( v12 > 5u )
    v6 = 0;
  *a3 = v6;
  _ReadStatusReg(SP_EL0);
  v8 = v7;
  return (unsigned int)(16 * v8);
}
