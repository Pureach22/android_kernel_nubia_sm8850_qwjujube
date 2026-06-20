__int64 __fastcall tdls_update_tx_pkt_cnt(__int64 a1, _BYTE *a2)
{
  __int64 result; // x0
  unsigned int v5; // w23
  __int64 v6; // x22
  __int64 v7; // x24
  _DWORD *v8; // x21
  __int64 bsspeer; // x0
  __int64 v10; // x20
  int v11; // w21
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20
  unsigned __int64 StatusReg; // x8
  unsigned int v22; // w8
  _DWORD *v23; // x20
  __int64 v24; // x9
  __int64 v25; // x0
  __int64 v26; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v27[2]; // [xsp+10h] [xbp-10h] BYREF

  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v27[0] = 0;
  result = tdls_get_vdev_objects(a1, v27, &v26);
  if ( !(_DWORD)result && *(_BYTE *)(v26 + 212) == 1 )
  {
    v5 = *(unsigned __int8 *)(v27[0] + 944LL);
    v6 = v27[0] + 784LL;
    if ( *(_BYTE *)(v27[0] + 944LL) )
    {
      v7 = *(unsigned __int8 *)(v27[0] + 944LL);
      v8 = (_DWORD *)(v27[0] + 784LL);
      while ( 1 )
      {
        result = qdf_mem_cmp(v8, a2, 6u);
        if ( !(_DWORD)result )
          break;
        --v7;
        v8 += 5;
        if ( !v7 )
          goto LABEL_7;
      }
      ++v8[2];
    }
    else
    {
LABEL_7:
      if ( (*a2 & 1) == 0 )
      {
        result = qdf_mem_cmp((const void *)(a1 + 74), a2, 6u);
        if ( (_DWORD)result )
        {
          bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a1, 0x11u);
          if ( !bsspeer
            || (v10 = bsspeer,
                v11 = qdf_mem_cmp((const void *)(bsspeer + 48), a2, 6u),
                result = wlan_objmgr_peer_release_ref(v10, 0x11u, v12, v13, v14, v15, v16, v17, v18, v19),
                v11) )
          {
            v20 = v26;
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
              || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(v26 + 352);
            }
            else
            {
              raw_spin_lock_bh(v26 + 352);
              *(_QWORD *)(v20 + 360) |= 1uLL;
            }
            if ( *(_BYTE *)(v27[0] + 944LL) )
              v22 = v5;
            else
              v22 = 0;
            if ( v22 <= 7 )
            {
              v23 = (_DWORD *)(v6 + 20LL * v22);
              qdf_mem_copy(v23, a2, 6u);
              v23[2] = 1;
              ++*(_BYTE *)(v27[0] + 944LL);
            }
            v24 = *(_QWORD *)(v26 + 360);
            if ( (v24 & 1) != 0 )
            {
              v25 = v26 + 352;
              *(_QWORD *)(v26 + 360) = v24 & 0xFFFFFFFFFFFFFFFELL;
              result = raw_spin_unlock_bh(v25);
            }
            else
            {
              result = raw_spin_unlock(v26 + 352);
            }
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
