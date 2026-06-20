__int64 __fastcall tdls_update_rx_pkt_cnt(__int64 a1, _BYTE *a2, _BYTE *a3)
{
  __int64 result; // x0
  unsigned int v7; // w24
  __int64 v8; // x23
  __int64 v9; // x25
  _DWORD *v10; // x22
  __int64 bsspeer; // x0
  __int64 v12; // x20
  int v13; // w21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w21
  __int64 v23; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v24[2]; // [xsp+10h] [xbp-10h] BYREF

  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v24[0] = 0;
  result = tdls_get_vdev_objects(a1, v24, &v23);
  if ( !(_DWORD)result && *(_BYTE *)(v23 + 212) == 1 )
  {
    v7 = *(unsigned __int8 *)(v24[0] + 944LL);
    v8 = v24[0] + 784LL;
    if ( *(_BYTE *)(v24[0] + 944LL) )
    {
      v9 = *(unsigned __int8 *)(v24[0] + 944LL);
      v10 = (_DWORD *)(v24[0] + 784LL);
      while ( 1 )
      {
        result = qdf_mem_cmp(v10, a2, 6u);
        if ( !(_DWORD)result )
          break;
        --v9;
        v10 += 5;
        if ( !v9 )
          goto LABEL_7;
      }
      ++v10[3];
    }
    else
    {
LABEL_7:
      if ( (*a2 & 1) == 0 && (*a3 & 1) == 0 )
      {
        result = qdf_mem_cmp((const void *)(a1 + 74), a2, 6u);
        if ( (_DWORD)result )
        {
          bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a1, 0x11u);
          if ( !bsspeer
            || (v12 = bsspeer,
                v13 = qdf_mem_cmp((const void *)(bsspeer + 48), a2, 6u),
                result = wlan_objmgr_peer_release_ref(v12, 0x11u, v14, v15, v16, v17, v18, v19, v20, v21),
                v13) )
          {
            qdf_spin_lock_bh_13(v23 + 352);
            if ( *(_BYTE *)(v24[0] + 944LL) )
              v22 = v7;
            else
              v22 = 0;
            if ( v22 <= 7 )
            {
              qdf_mem_copy((void *)(v8 + 20LL * v22), a2, 6u);
              *(_BYTE *)(v24[0] + 944LL) = v22 + 1;
              *(_DWORD *)(v8 + 20LL * v22 + 12) = 1;
            }
            result = qdf_spin_unlock_bh_13(v23 + 352);
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
