__int64 __fastcall wlan_mlo_ap_vdev_find_assoc_entry(
        __int64 a1,
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
  __int64 v12; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned __int64 StatusReg; // x8
  _QWORD *v23; // x1
  __int64 v24; // x8
  __int64 v26; // x8
  _QWORD v27[2]; // [xsp+0h] [xbp-10h] BYREF

  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 1360);
  if ( v10 )
  {
    if ( *(_DWORD *)(a1 + 16) == 1 && (wlan_vdev_mlme_is_mlo_vdev(a1, a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0 )
    {
      v12 = *(_QWORD *)(v10 + 2232);
      if ( qdf_list_empty((_QWORD *)(v12 + 96)) )
      {
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: list is empty",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "wlan_mlo_ap_vdev_find_assoc_entry");
      }
      else
      {
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v12 + 184);
        }
        else
        {
          raw_spin_lock_bh(v12 + 184);
          *(_QWORD *)(v12 + 192) |= 1uLL;
        }
        v27[0] = 0;
        if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(v12 + 96), v27) )
        {
          do
          {
            v10 = v27[0];
            if ( !v27[0] )
              break;
            if ( *(_DWORD *)((char *)&off_18 + v27[0]) == *(_DWORD *)a2
              && *(unsigned __int16 *)((char *)&off_18 + v27[0] + 4) == *(unsigned __int16 *)(a2 + 4) )
            {
              v26 = *(_QWORD *)(v12 + 192);
              if ( (v26 & 1) != 0 )
              {
                *(_QWORD *)(v12 + 192) = v26 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(v12 + 184);
              }
              else
              {
                raw_spin_unlock(v12 + 184);
              }
              goto LABEL_20;
            }
            v23 = (_QWORD *)v27[0];
            v27[0] = 0;
          }
          while ( !(unsigned int)qdf_list_peek_next((_QWORD *)(v12 + 96), v23, v27) );
        }
        v24 = *(_QWORD *)(v12 + 192);
        if ( (v24 & 1) != 0 )
        {
          *(_QWORD *)(v12 + 192) = v24 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v12 + 184);
        }
        else
        {
          raw_spin_unlock(v12 + 184);
        }
      }
    }
    v10 = 0;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return v10;
}
