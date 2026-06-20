__int64 __fastcall peer_rssi_iterator(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  __int64 comp_private_obj; // x0
  __int64 v14; // x19
  unsigned __int64 StatusReg; // x8
  _QWORD *v16; // x10
  _QWORD *v17; // x9
  __int64 v18; // x11
  __int64 v19; // x13
  __int64 v20; // x14
  __int64 v21; // x11
  __int64 v22; // x13
  __int64 v23; // x14
  __int64 v24; // x11
  __int64 v25; // x12
  __int64 v26; // x11
  __int64 *v27; // x10
  _QWORD *v28; // x9
  __int64 v29; // x11
  __int64 v30; // x12
  __int64 v31; // x10
  __int64 v32; // x13
  __int64 v33; // x8

  if ( *(_DWORD *)(a10 + 68) == 1 )
    return qdf_trace_msg(
             0x62u,
             8u,
             "%s: ignore self peer: %02x:%02x:%02x:**:**:%02x",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             "peer_rssi_iterator",
             *(unsigned __int8 *)(a10 + 48),
             *(unsigned __int8 *)(a10 + 49),
             *(unsigned __int8 *)(a10 + 50),
             *(unsigned __int8 *)(a10 + 53));
  if ( !a10 )
    return qdf_trace_msg(
             0x62u,
             2u,
             "%s: peer cp stats object is null",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             "peer_rssi_iterator");
  comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(a10, 0x1Bu);
  if ( !comp_private_obj )
    return qdf_trace_msg(
             0x62u,
             2u,
             "%s: peer cp stats object is null",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             "peer_rssi_iterator");
  v14 = comp_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(comp_private_obj + 24);
  }
  else
  {
    raw_spin_lock_bh(comp_private_obj + 24);
    *(_QWORD *)(v14 + 32) |= 1uLL;
  }
  v16 = *(_QWORD **)(v14 + 8);
  v17 = (_QWORD *)(*(_QWORD *)(a11 + 40) + 88LL * *(unsigned int *)(a11 + 32));
  v18 = v16[6];
  v20 = v16[3];
  v19 = v16[4];
  v17[5] = v16[5];
  v17[6] = v18;
  v17[3] = v20;
  v17[4] = v19;
  v21 = v16[10];
  v23 = v16[7];
  v22 = v16[8];
  v17[9] = v16[9];
  v17[10] = v21;
  v17[7] = v23;
  v17[8] = v22;
  v25 = v16[1];
  v24 = v16[2];
  *v17 = *v16;
  v17[1] = v25;
  v17[2] = v24;
  v26 = *(unsigned int *)(a11 + 64);
  ++*(_DWORD *)(a11 + 32);
  v27 = (__int64 *)v16[2];
  v28 = (_QWORD *)(*(_QWORD *)(a11 + 72) + 32 * v26);
  v30 = v27[2];
  v29 = v27[3];
  v32 = *v27;
  v31 = v27[1];
  v28[2] = v30;
  v28[3] = v29;
  *v28 = v32;
  v28[1] = v31;
  ++*(_DWORD *)(a11 + 64);
  v33 = *(_QWORD *)(v14 + 32);
  if ( (v33 & 1) == 0 )
    return raw_spin_unlock(v14 + 24);
  *(_QWORD *)(v14 + 32) = v33 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(v14 + 24);
}
