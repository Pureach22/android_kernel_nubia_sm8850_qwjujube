__int64 __fastcall wlan_mlo_ap_vdev_add_assoc_entry(
        __int64 result,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x21
  __int64 v12; // x20
  __int64 v13; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x4
  __int64 v23; // x5
  __int64 v24; // x6
  __int64 v25; // x7
  int v26; // w9
  _QWORD *v27; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v29; // x19
  __int64 v30; // x8

  v10 = *(_QWORD *)(result + 1360);
  if ( v10 )
  {
    if ( *(_DWORD *)(result + 16) == 1 )
    {
      v12 = result;
      result = wlan_vdev_mlme_is_mlo_vdev(result, a3, a4, a5, a6, a7, a8, a9, a10);
      if ( (result & 1) != 0 )
      {
        v13 = *(_QWORD *)(v10 + 2232);
        if ( wlan_mlo_ap_vdev_find_assoc_entry(v12, a2) )
        {
          if ( a2 )
          {
            v22 = *a2;
            v23 = a2[1];
            v24 = a2[2];
            v25 = a2[5];
          }
          else
          {
            v24 = 0;
            v22 = 0;
            v23 = 0;
            v25 = 0;
          }
          return qdf_trace_msg(
                   0x8Fu,
                   2u,
                   "%s: Duplicate entry %02x:%02x:%02x:**:**:%02x",
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   "wlan_mlo_ap_vdev_add_assoc_entry",
                   v22,
                   v23,
                   v24,
                   v25);
        }
        else
        {
          result = _qdf_mem_malloc(0x20u, "wlan_mlo_ap_vdev_add_assoc_entry", 2881);
          if ( result )
          {
            v26 = *(_DWORD *)a2;
            v27 = (_QWORD *)result;
            *(_WORD *)(result + 28) = *((_WORD *)a2 + 2);
            *(_DWORD *)(result + 24) = v26;
            *(_QWORD *)(result + 16) = (unsigned int)jiffies_to_msecs(jiffies);
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
              || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(v13 + 184);
            }
            else
            {
              raw_spin_lock_bh(v13 + 184);
              *(_QWORD *)(v13 + 192) |= 1uLL;
            }
            qdf_list_insert_back((_QWORD *)(v13 + 96), v27);
            if ( (*(_BYTE *)(v13 + 120) & 1) == 0 )
            {
              v29 = jiffies;
              *(_QWORD *)(v13 + 144) = v29 + 750LL * (unsigned int)qdf_timer_get_multiplier();
              add_timer(v13 + 128);
              *(_BYTE *)(v13 + 120) = 1;
            }
            v30 = *(_QWORD *)(v13 + 192);
            if ( (v30 & 1) != 0 )
            {
              *(_QWORD *)(v13 + 192) = v30 & 0xFFFFFFFFFFFFFFFELL;
              return raw_spin_unlock_bh(v13 + 184);
            }
            else
            {
              return raw_spin_unlock(v13 + 184);
            }
          }
        }
      }
    }
  }
  return result;
}
