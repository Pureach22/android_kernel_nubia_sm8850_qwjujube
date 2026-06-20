__int64 __fastcall pmo_core_is_gtk_enabled_in_fwr(__int64 a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  int v23; // w20
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // [xsp+20h] [xbp-10h] BYREF
  __int16 v33; // [xsp+24h] [xbp-Ch]
  __int64 v34; // [xsp+28h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  v32 = 0;
  if ( (pmo_core_is_vdev_supports_offload(a1) & 1) != 0 )
  {
    if ( !(unsigned int)wlan_vdev_is_up() && !(unsigned int)pmo_get_vdev_bss_peer_mac_addr(a1, &v32) )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a2 + 1056);
      }
      else
      {
        raw_spin_lock_bh(a2 + 1056);
        *(_QWORD *)(a2 + 1064) |= 1uLL;
      }
      if ( (unsigned int)qdf_mem_cmp((const void *)(a2 + 992), &v32, 6u) )
      {
        v13 = *(_QWORD *)(a2 + 1064);
        if ( (v13 & 1) != 0 )
        {
          *(_QWORD *)(a2 + 1064) = v13 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a2 + 1056);
        }
        else
        {
          raw_spin_unlock(a2 + 1056);
        }
        qdf_trace_msg(
          0x4Du,
          2u,
          "%s: cache request mac:%02x:%02x:%02x:**:**:%02x, peer mac:%02x:%02x:%02x:**:**:%02x are not same",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "pmo_core_is_gtk_enabled_in_fwr",
          *(unsigned __int8 *)(a2 + 992),
          *(unsigned __int8 *)(a2 + 993),
          *(unsigned __int8 *)(a2 + 994),
          *(unsigned __int8 *)(a2 + 997),
          (unsigned __int8)v32,
          BYTE1(v32),
          BYTE2(v32),
          HIBYTE(v33));
      }
      else
      {
        v23 = *(_DWORD *)(a2 + 872);
        qdf_spin_unlock_bh_13(a2 + 1056);
        if ( !v23 )
        {
          result = 0;
          goto LABEL_14;
        }
        qdf_trace_msg(
          0x4Du,
          2u,
          "%s: gtk flag is disabled hence no gtk rsp required",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "pmo_core_is_gtk_enabled_in_fwr");
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Du,
      8u,
      "%s: vdev in invalid opmode for gtk offload enable %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "pmo_core_is_gtk_enabled_in_fwr",
      *(unsigned int *)(a1 + 16));
  }
  result = 4;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
