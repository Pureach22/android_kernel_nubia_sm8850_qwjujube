__int64 __fastcall lim_objmgr_update_emlsr_caps(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int8 v4; // w21
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  unsigned int v15; // w9
  __int16 v16; // w8
  const char *v17; // x2
  __int64 assoc_link_vdev; // x0
  unsigned int *v20; // x8
  int v21; // w9
  int v22; // w8
  const char *v23; // x2
  unsigned __int64 StatusReg; // x8
  __int64 v25; // x8

  v4 = a2;
  v5 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 7);
  if ( !v5 )
    return qdf_trace_msg(
             0x35u,
             2u,
             "%s: vdev not found for id: %d",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "lim_objmgr_update_emlsr_caps",
             v4);
  v14 = v5;
  if ( (*(_BYTE *)(v5 + 60) & 2) == 0 )
  {
    v15 = *(_DWORD *)(v5 + 48);
    v16 = *(_WORD *)(a3 + 5358);
    if ( (v15 & 0x400) == 0 || (v16 & 1) == 0 )
    {
      v21 = (v15 >> 10) & 1;
      if ( (v16 & 1) != 0 )
        v22 = v21;
      else
        v22 = 1;
      if ( v22 )
        v23 = "%s: EML caps not present in assoc rsp";
      else
        v23 = "%s: No eMLSR STA supp but recvd EML caps in assc rsp";
      qdf_trace_msg(0x35u, 8u, v23, v6, v7, v8, v9, v10, v11, v12, v13, "lim_objmgr_update_emlsr_caps");
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v14 + 1344);
        v25 = *(_QWORD *)(v14 + 1352);
      }
      else
      {
        raw_spin_lock_bh(v14 + 1344);
        v25 = *(_QWORD *)(v14 + 1352) | 1LL;
        *(_QWORD *)(v14 + 1352) = v25;
      }
      *(_DWORD *)(v14 + 48) &= ~0x400u;
      if ( (v25 & 1) != 0 )
      {
        *(_QWORD *)(v14 + 1352) = v25 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v14 + 1344);
      }
      else
      {
        raw_spin_unlock(v14 + 1344);
      }
      return wlan_objmgr_vdev_release_ref(v14, 7u, v20, v6, v7, v8, v9, v10, v11, v12, v13);
    }
    v17 = "%s: EML caps present in assoc rsp";
    goto LABEL_13;
  }
  if ( wlan_cm_is_vdev_active(v5, v6, v7, v8, v9, v10, v11, v12, v13) || (*(_BYTE *)(v14 + 67) & 2) != 0 )
    goto LABEL_12;
  assoc_link_vdev = wlan_mlo_get_assoc_link_vdev(v14);
  if ( assoc_link_vdev )
  {
    if ( (*(_BYTE *)(assoc_link_vdev + 49) & 4) == 0 )
    {
      wlan_vdev_obj_lock_0(v14);
      *(_DWORD *)(v14 + 48) &= ~0x400u;
      wlan_vdev_obj_unlock_0(v14);
      v17 = "%s: Cleared link vdev EML caps.";
LABEL_13:
      qdf_trace_msg(0x35u, 8u, v17, v6, v7, v8, v9, v10, v11, v12, v13, "lim_objmgr_update_emlsr_caps");
      return wlan_objmgr_vdev_release_ref(v14, 7u, v20, v6, v7, v8, v9, v10, v11, v12, v13);
    }
LABEL_12:
    v17 = "%s: no change required for link vdev";
    goto LABEL_13;
  }
  return wlan_objmgr_vdev_release_ref(v14, 7u, v20, v6, v7, v8, v9, v10, v11, v12, v13);
}
