__int64 **__fastcall dp_2k_jump_handle(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, unsigned int a5)
{
  __int64 **result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 *v18; // x22
  __int64 v19; // x24
  __int64 v20; // x25
  __int64 v21; // x22
  __int64 v22; // x22
  __int64 **v23; // x23
  __int64 v24; // x25
  unsigned __int64 StatusReg; // x8
  __int64 v26; // x8
  char v27; // w8
  char v28; // w9
  __int64 v29; // x8
  __int64 v30; // x9
  _DWORD *v31; // x8
  __int64 v32; // x10
  __int64 v33; // x4
  __int64 v34; // x1
  __int64 v35; // x0

  result = (__int64 **)dp_peer_get_ref_by_id_2(a1, a4);
  if ( result )
  {
    v18 = *result;
    if ( *result )
    {
      if ( (unsigned __int8)a5 < 0x11u )
      {
        v24 = (__int64)&result[11][18 * (unsigned __int8)a5];
        v19 = (__int64)result;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v24 + 88);
        }
        else
        {
          raw_spin_lock_bh(v24 + 88);
          *(_QWORD *)(v24 + 96) |= 1uLL;
        }
        if ( *(_DWORD *)(v24 + 68) == 1 && !*(_BYTE *)(v24 + 108) )
        {
          v28 = *(_BYTE *)(v24 + 109);
          v29 = *(_QWORD *)(v24 + 96);
          *(_BYTE *)(v24 + 108) = 1;
          *(_BYTE *)(v24 + 120) = 38;
          *(_BYTE *)(v24 + 109) = v28 + 1;
          if ( (v29 & 1) != 0 )
          {
            *(_QWORD *)(v24 + 96) = v29 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v24 + 88);
          }
          else
          {
            raw_spin_unlock(v24 + 88);
          }
          v30 = *(_QWORD *)(a1 + 8);
          v31 = *(_DWORD **)(v30 + 168);
          if ( v31 )
          {
            if ( a1 )
            {
              ++*(_DWORD *)(a1 + 14060);
              v31 = *(_DWORD **)(v30 + 168);
            }
            v32 = *(_QWORD *)(v19 + 24);
            v33 = *(unsigned __int8 *)(v24 + 120);
            v34 = *(unsigned __int8 *)(v32 + 59);
            v35 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v32 + 24) + 8LL) + 16LL);
            if ( *(v31 - 1) != -1677196783 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64, __int64))v31)(
              v35,
              v34,
              v19 + 44,
              a5,
              v33,
              1);
          }
        }
        else
        {
          v26 = *(_QWORD *)(v24 + 96);
          if ( (v26 & 1) != 0 )
          {
            *(_QWORD *)(v24 + 96) = v26 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v24 + 88);
          }
          else
          {
            raw_spin_unlock(v24 + 88);
          }
        }
      }
      else
      {
        v19 = (__int64)result;
        v20 = jiffies;
        if ( dp_2k_jump_handle___last_ticks_16 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(0x45u, 5u, "%s: invalid tid", v10, v11, v12, v13, v14, v15, v16, v17, "dp_2k_jump_handle");
          dp_2k_jump_handle___last_ticks_16 = v20;
        }
      }
      v27 = dp_rx_deliver_special_frame(a1, v18, a2, 1, a3);
      result = (__int64 **)v19;
      if ( (v27 & 1) != 0 )
      {
        if ( a1 )
          ++*(_DWORD *)(a1 + 14064);
        return (__int64 **)dp_peer_unref_delete(v19, 4u, v10, v11, v12, v13, v14, v15, v16, v17);
      }
    }
    else
    {
      v22 = jiffies;
      if ( dp_2k_jump_handle___last_ticks_14 - jiffies + 125 < 0 )
      {
        v23 = result;
        qdf_trace_msg(
          0x82u,
          5u,
          "%s: %pK: txrx_peer not found",
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          "dp_2k_jump_handle",
          a1);
        result = v23;
        dp_2k_jump_handle___last_ticks_14 = v22;
      }
    }
    result = (__int64 **)dp_peer_unref_delete((__int64)result, 4u, v10, v11, v12, v13, v14, v15, v16, v17);
  }
  else
  {
    v21 = jiffies;
    if ( dp_2k_jump_handle___last_ticks - jiffies + 125 < 0 )
    {
      result = (__int64 **)qdf_trace_msg(
                             0x82u,
                             5u,
                             "%s: %pK: peer not found",
                             v10,
                             v11,
                             v12,
                             v13,
                             v14,
                             v15,
                             v16,
                             v17,
                             "dp_2k_jump_handle",
                             a1);
      dp_2k_jump_handle___last_ticks = v21;
    }
  }
  if ( a1 )
    ++*(_DWORD *)(a1 + 14068);
  if ( a2 )
    return (__int64 **)_qdf_nbuf_free(a2);
  return result;
}
