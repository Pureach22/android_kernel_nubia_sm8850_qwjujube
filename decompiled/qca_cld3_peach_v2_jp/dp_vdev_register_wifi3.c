__int64 __fastcall dp_vdev_register_wifi3(_QWORD *a1, unsigned __int8 a2, __int64 a3, __int64 (__fastcall **a4)())
{
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x20
  unsigned int v10; // w8
  unsigned int v17; // w10
  _QWORD *v18; // x8
  int v19; // w9
  __int64 (__fastcall *v20)(); // x22
  __int64 (__fastcall *v21)(); // x23
  __int64 v22; // x8
  __int64 (__fastcall *v23)(); // x8
  char v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int *v41; // x8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v53; // w9
  __int64 v54; // x8

  if ( a2 > 5u )
    return 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2366);
  }
  else
  {
    raw_spin_lock_bh(a1 + 2366);
    a1[2367] |= 1uLL;
  }
  v9 = a1[a2 + 1614];
  if ( v9 )
  {
    v10 = *(_DWORD *)(v9 + 42560);
    while ( v10 )
    {
      _X12 = (unsigned int *)(v9 + 42560);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v17 = __ldxr(_X12);
        if ( v17 != v10 )
          break;
        if ( !__stlxr(v10 + 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v17 == v10;
      v10 = v17;
      if ( _ZF )
      {
        _X8 = (unsigned int *)(v9 + 42592);
        __asm { PRFM            #0x11, [X8] }
        do
          v53 = __ldxr(_X8);
        while ( __stxr(v53 + 1, _X8) );
        v54 = a1[2367];
        if ( (v54 & 1) != 0 )
        {
          a1[2367] = v54 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 2366);
        }
        else
        {
          raw_spin_unlock(a1 + 2366);
        }
        *(_QWORD *)(v9 + 88) = a3;
        *(_QWORD *)(v9 + 160) = a4[6];
        *(_QWORD *)(v9 + 168) = a4[7];
        *(_QWORD *)(v9 + 192) = a4[8];
        *(_QWORD *)(v9 + 152) = a4[9];
        *(_QWORD *)(v9 + 200) = a4[13];
        *(_QWORD *)(v9 + 176) = a4[14];
        *(_QWORD *)(v9 + 184) = a4[15];
        v18 = *(_QWORD **)(v9 + 42696);
        *(_QWORD *)(v9 + 208) = a4[18];
        if ( v18 )
          *v18 = a4[11];
        v19 = *(_DWORD *)(v9 + 64);
        *(_QWORD *)(v9 + 216) = a4[3];
        *(_QWORD *)(v9 + 240) = a4[4];
        *(_QWORD *)(v9 + 42512) = a4[12];
        *(_QWORD *)(v9 + 256) = a4[5];
        *(_QWORD *)(v9 + 232) = a4[17];
        *(_QWORD *)(v9 + 248) = a4[19];
        *(_QWORD *)(v9 + 264) = a4[20];
        if ( v19 )
        {
          v20 = nullptr;
          v21 = dp_tx_send_mesh;
        }
        else if ( (wlan_cfg_is_tx_per_pkt_vdev_id_check_enabled(a1[5]) & 1) != 0 && *(_DWORD *)(v9 + 32) == 1 )
        {
          v21 = dp_tx_send_vdev_id_check;
          v20 = dp_tx_send_vdev_id_check;
        }
        else
        {
          v20 = (__int64 (__fastcall *)())a1[168];
          v21 = dp_tx_send;
        }
        if ( (wlan_cfg_is_tx_per_pkt_vdev_id_check_enabled(a1[5]) & 1) != 0 && *(_DWORD *)(v9 + 32) == 1 )
          v23 = dp_tx_send_exception_vdev_id_check;
        else
          v23 = (__int64 (__fastcall *)())dp_tx_send_exception;
        *a4 = v21;
        a4[1] = v20;
        a4[2] = v23;
        v24 = wlan_cfg_is_tx_per_pkt_vdev_id_check_enabled(a1[5]);
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: Configure tx_vdev_id_chk_handler Feature Flag: %d and mode:%d for vdev_id:%d",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "dp_vdev_register_tx_handler",
          v24 & 1,
          *(unsigned int *)(v9 + 32),
          *(unsigned __int8 *)(v9 + 59));
        qdf_trace_msg(
          0x7Cu,
          5u,
          "%s: %pK: DP Vdev Register success",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "dp_vdev_register_wifi3",
          a1);
        dp_vdev_unref_delete((__int64)a1, v9, 7u, v41, v42, v43, v44, v45, v46, v47, v48, v49);
        return v9;
      }
    }
  }
  v22 = a1[2367];
  if ( (v22 & 1) != 0 )
  {
    a1[2367] = v22 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2366);
  }
  else
  {
    raw_spin_unlock(a1 + 2366);
  }
  return 0;
}
