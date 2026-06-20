_QWORD *__fastcall wma_find_req(__int64 a1, char a2, unsigned __int8 a3, __int64 a4)
{
  unsigned int v6; // w21
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
  bool v18; // w23
  _QWORD *v20; // x22
  int v21; // w0
  __int64 v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x2
  __int64 v32; // x5
  unsigned int v33; // w1
  __int64 v34; // x8
  _QWORD *result; // x0
  _QWORD *v36; // [xsp+0h] [xbp-10h] BYREF
  __int64 v37; // [xsp+8h] [xbp-8h]

  LOBYTE(v6) = a2;
  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = nullptr;
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
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 576), &v36) )
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
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: unable to get msg node from request queue",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "wma_find_req",
      v36,
      v37);
LABEL_29:
    result = nullptr;
  }
  else
  {
    while ( *((unsigned __int8 *)v36 + 36) != (unsigned __int8)v6 || *((unsigned __int8 *)v36 + 37) != a3 )
    {
      if ( (unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 576), v36, &v36) )
      {
        v34 = *(_QWORD *)(a1 + 608);
        v6 = (unsigned __int8)v6;
        if ( (v34 & 1) != 0 )
        {
          *(_QWORD *)(a1 + 608) = v34 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 600);
        }
        else
        {
          raw_spin_unlock(a1 + 600);
        }
LABEL_27:
        v31 = "%s: target request not found for vdev_id %d type %d";
        v32 = a3;
        v33 = 2;
LABEL_28:
        qdf_trace_msg(0x36u, v33, v31, v23, v24, v25, v26, v27, v28, v29, v30, "wma_find_req", v6, v32, v36, v37);
        goto LABEL_29;
      }
    }
    v6 = (unsigned __int8)v6;
    v18 = 1;
    if ( a3 == 8 && a4 )
      v18 = *((_DWORD *)v36 + 6) == *(_DWORD *)a4 && *((unsigned __int16 *)v36 + 14) == *(unsigned __int16 *)(a4 + 4);
    v20 = v36;
    v21 = qdf_list_remove_node(a1 + 576, v36);
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
      v31 = "%s: Failed to remove request for vdev_id %d type %d";
      v32 = a3;
      v33 = 8;
      goto LABEL_28;
    }
    if ( (v22 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 608) = v22 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 600);
      if ( !v18 )
        goto LABEL_27;
    }
    else
    {
      raw_spin_unlock(a1 + 600);
      if ( !v18 )
        goto LABEL_27;
    }
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: target request found for vdev id: %d type %d",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wma_find_req",
      (unsigned __int8)v6,
      a3,
      v36,
      v37);
    result = v20 - 21;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
