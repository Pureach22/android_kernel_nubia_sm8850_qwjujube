_QWORD *__fastcall wma_find_remove_req_msgtype(__int64 a1, unsigned __int8 a2, __int64 a3, unsigned int a4)
{
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x8
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  const char *v18; // x2
  _QWORD *v20; // x22
  int v21; // w0
  __int64 v22; // x8
  __int64 v23; // x8
  _QWORD *result; // x0
  _QWORD *v25; // x22
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  _QWORD *v34[3]; // [xsp+8h] [xbp-18h] BYREF

  v34[2] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v34[0] = nullptr;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 600);
  }
  else
  {
    raw_spin_lock_bh(a1 + 600);
    *(_QWORD *)(a1 + 608) |= 1uLL;
  }
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 576), v34) )
  {
    v9 = *(_QWORD *)(a1 + 608);
    if ( (v9 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 608) = v9 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 600);
    }
    else
    {
      raw_spin_unlock(a1 + 600);
    }
    v18 = "%s: unable to get msg node from request queue for vdev_id %d type %d";
LABEL_27:
    qdf_trace_msg(0x36u, 8u, v18, v10, v11, v12, v13, v14, v15, v16, v17, "wma_find_remove_req_msgtype", a2, a4);
    result = nullptr;
    goto LABEL_28;
  }
  while ( 1 )
  {
    if ( *((unsigned __int8 *)v34[0] + 36) == a2 && *((_DWORD *)v34[0] + 8) == a4 )
    {
      if ( !a3 || !(*((_DWORD *)v34[0] + 6) | *((unsigned __int16 *)v34[0] + 14)) )
        break;
      if ( *(_DWORD *)a3 == *((_DWORD *)v34[0] + 6)
        && *(unsigned __int16 *)(a3 + 4) == *((unsigned __int16 *)v34[0] + 14) )
      {
        break;
      }
    }
    if ( (unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 576), v34[0], v34) )
    {
      v23 = *(_QWORD *)(a1 + 608);
      if ( (v23 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 608) = v23 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 600);
      }
      else
      {
        raw_spin_unlock(a1 + 600);
      }
      v18 = "%s: target request not found for vdev_id %d type %d";
      goto LABEL_27;
    }
  }
  v20 = v34[0];
  v21 = qdf_list_remove_node(a1 + 576, v34[0]);
  v22 = *(_QWORD *)(a1 + 608);
  if ( v21 )
  {
    if ( (v22 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 608) = v22 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 600);
    }
    else
    {
      raw_spin_unlock(a1 + 600);
    }
    v18 = "%s: Failed to remove request. vdev_id %d type %d";
    goto LABEL_27;
  }
  v25 = v20 - 21;
  if ( (v22 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 608) = v22 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 600);
  }
  else
  {
    raw_spin_unlock(a1 + 600);
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: target request found for vdev id: %d type %d",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "wma_find_remove_req_msgtype",
    a2,
    a4);
  result = v25;
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
