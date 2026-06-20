__int64 __fastcall wlan_mlo_ap_vdev_del_assoc_entry(
        __int64 result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20
  __int64 v11; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  _QWORD *v22; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v24; // x8

  v10 = *(_QWORD *)(result + 1360);
  if ( v10 )
  {
    if ( *(_DWORD *)(result + 16) == 1 )
    {
      v11 = result;
      result = wlan_vdev_mlme_is_mlo_vdev(result, a3, a4, a5, a6, a7, a8, a9, a10);
      if ( (result & 1) != 0 )
      {
        v21 = *(_QWORD *)(v10 + 2232);
        result = wlan_mlo_ap_vdev_find_assoc_entry(v11, a2, v13, v14, v15, v16, v17, v18, v19, v20);
        if ( result )
        {
          v22 = (_QWORD *)result;
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v21 + 184);
          }
          else
          {
            raw_spin_lock_bh(v21 + 184);
            *(_QWORD *)(v21 + 192) |= 1uLL;
          }
          qdf_list_remove_node(v21 + 96, v22);
          _qdf_mem_free((__int64)v22);
          if ( qdf_list_empty((_QWORD *)(v21 + 96)) && *(_BYTE *)(v21 + 120) == 1 )
          {
            *(_BYTE *)(v21 + 120) = 0;
            timer_delete((timer_t)(v21 + 128));
          }
          v24 = *(_QWORD *)(v21 + 192);
          if ( (v24 & 1) != 0 )
          {
            *(_QWORD *)(v21 + 192) = v24 & 0xFFFFFFFFFFFFFFFELL;
            return raw_spin_unlock_bh(v21 + 184);
          }
          else
          {
            return raw_spin_unlock(v21 + 184);
          }
        }
      }
    }
  }
  return result;
}
