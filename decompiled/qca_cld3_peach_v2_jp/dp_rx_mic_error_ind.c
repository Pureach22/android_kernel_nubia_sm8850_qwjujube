__int64 __fastcall dp_rx_mic_error_ind(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v4; // x19
  __int64 comp_private_obj; // x0
  unsigned int *v6; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x22
  __int64 v16; // x0
  int v17; // w9
  __int64 v18; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v20; // x1
  __int64 v21; // x8
  __int64 v22; // x8

  if ( result )
  {
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
               result,
               *(unsigned __int8 *)(a3 + 36),
               97);
    if ( result )
    {
      v4 = result;
      comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(result, 0x2Eu);
      if ( comp_private_obj )
      {
        v15 = *(_QWORD *)(comp_private_obj + 32);
        v16 = _qdf_mem_malloc(0x10u, "dp_rx_mic_error_ind", 1061);
        if ( v16 )
        {
          v17 = *(_DWORD *)(a3 + 16);
          v18 = v16;
          *(_WORD *)(v16 + 4) = *(_WORD *)(a3 + 20);
          *(_DWORD *)v16 = v17;
          *(_BYTE *)(v16 + 6) = *(_BYTE *)(a3 + 35);
          *(_BYTE *)(v16 + 7) = *(_BYTE *)(a3 + 34);
          qdf_mem_copy((void *)(v16 + 8), (const void *)(a3 + 28), 6u);
          *(_WORD *)(v18 + 14) = *(_WORD *)(a3 + 36);
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v15 + 3464);
          }
          else
          {
            raw_spin_lock_bh(v15 + 3464);
            *(_QWORD *)(v15 + 3472) |= 1uLL;
          }
          if ( *(_DWORD *)(v15 + 3448) == 1 )
          {
            v20 = system_wq;
            *(_DWORD *)(v15 + 3448) = 2;
            *(_QWORD *)(v15 + 3456) = v18;
            queue_work_on(32, v20, v15 + 3400);
            v21 = *(_QWORD *)(v15 + 3472);
            if ( (v21 & 1) != 0 )
            {
              *(_QWORD *)(v15 + 3472) = v21 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(v15 + 3464);
            }
            else
            {
              raw_spin_unlock(v15 + 3464);
            }
          }
          else
          {
            v22 = *(_QWORD *)(v15 + 3472);
            if ( (v22 & 1) != 0 )
            {
              *(_QWORD *)(v15 + 3472) = v22 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(v15 + 3464);
            }
            else
            {
              raw_spin_unlock(v15 + 3464);
            }
            _qdf_mem_free(v18);
          }
        }
      }
      return wlan_objmgr_vdev_release_ref(v4, 0x61u, v6, v7, v8, v9, v10, v11, v12, v13, v14);
    }
  }
  return result;
}
