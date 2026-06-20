__int64 __fastcall cm_delete_req_from_list(__int64 a1, unsigned int a2)
{
  _QWORD *v4; // x1
  unsigned int v5; // w22
  _QWORD *v6; // x20
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  _QWORD *v24; // [xsp+8h] [xbp-18h] BYREF
  _QWORD *v25[2]; // [xsp+10h] [xbp-10h] BYREF

  v25[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = nullptr;
  v25[0] = nullptr;
  qdf_mutex_acquire(a1 + 120);
  qdf_list_peek_front((_QWORD *)(a1 + 96), v25);
  v4 = v25[0];
  if ( !v25[0] )
    goto LABEL_11;
  v5 = a2 & 0xF000000;
  while ( 1 )
  {
    qdf_list_peek_next((_QWORD *)(a1 + 96), v4, &v24);
    v6 = v25[0];
    if ( *((_DWORD *)v25[0] + 4) == a2 )
      break;
    v4 = v24;
    v24 = nullptr;
    v25[0] = v4;
    if ( !v4 )
      goto LABEL_11;
  }
  if ( v25[0] )
  {
    qdf_list_remove_node(a1 + 96, v25[0]);
    switch ( v5 )
    {
      case 0xF000000u:
        cm_free_roam_req_mem(v6 + 3);
        break;
      case 0xD000000u:
        --*(_BYTE *)(a1 + 184);
        break;
      case 0xC000000u:
        --*(_BYTE *)(a1 + 185);
        cm_free_connect_req_mem(v6 + 3);
        break;
      default:
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: vdev %d cm_id 0x%x: Invalid prefix %x",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "cm_delete_req_from_list",
          *(unsigned __int8 *)(*(_QWORD *)a1 + 104LL),
          *((unsigned int *)v6 + 4),
          v5);
        break;
    }
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: vdev %d cm_id 0x%x: ",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "cm_delete_req_from_list",
      *(unsigned __int8 *)(*(_QWORD *)a1 + 104LL),
      *((unsigned int *)v6 + 4));
    _qdf_mem_free((__int64)v6);
    qdf_mutex_release(a1 + 120);
    result = 0;
  }
  else
  {
LABEL_11:
    qdf_mutex_release(a1 + 120);
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x:  req not found",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "cm_delete_req_from_list",
      *(unsigned __int8 *)(*(_QWORD *)a1 + 104LL),
      a2);
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
