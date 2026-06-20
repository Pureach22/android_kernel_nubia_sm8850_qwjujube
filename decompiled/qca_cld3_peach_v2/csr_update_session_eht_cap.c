__int64 __fastcall csr_update_session_eht_cap(__int64 a1, unsigned __int8 *a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  __int64 ext_hdl; // x0
  unsigned int *v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21

  result = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
             *(_QWORD *)(a1 + 21624),
             *a2,
             11);
  if ( result )
  {
    v12 = result;
    ext_hdl = wlan_vdev_mlme_get_ext_hdl(result, v4, v5, v6, v7, v8, v9, v10, v11);
    if ( ext_hdl )
    {
      v23 = ext_hdl;
      qdf_mem_copy((void *)(ext_hdl + 24448), (const void *)(*(_QWORD *)(a1 + 8) + 1500LL), 0x5Cu);
      v14 = (_DWORD *)(&off_0 + 1);
      *(_BYTE *)(v23 + 24448) = 1;
    }
    return wlan_objmgr_vdev_release_ref(v12, 0xBu, v14, v15, v16, v17, v18, v19, v20, v21, v22);
  }
  return result;
}
