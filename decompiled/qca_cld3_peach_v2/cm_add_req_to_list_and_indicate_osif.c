__int64 __fastcall cm_add_req_to_list_and_indicate_osif(_QWORD *a1, __int64 a2, unsigned int a3)
{
  int v3; // w22
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  int v16; // w22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  v3 = *(_DWORD *)(a2 + 16);
  qdf_mutex_acquire((__int64)(a1 + 15));
  if ( *((_DWORD *)a1 + 28) < 5u )
  {
    v16 = v3 & 0xF000000;
    qdf_list_insert_front(a1 + 12, (_QWORD *)a2);
    if ( v16 == 218103808 )
    {
      ++*((_BYTE *)a1 + 184);
    }
    else if ( v16 == 201326592 )
    {
      ++*((_BYTE *)a1 + 185);
    }
    qdf_mutex_release((__int64)(a1 + 15));
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: vdev %d cm_id 0x%x: ",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "cm_add_req_to_list_and_indicate_osif",
      *(unsigned __int8 *)(*a1 + 168LL),
      *(unsigned int *)(a2 + 16));
    mlme_cm_osif_update_id_and_src(*a1, a3, *(unsigned int *)(a2 + 16));
    return 0;
  }
  else
  {
    qdf_mutex_release((__int64)(a1 + 15));
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: List full size %d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "cm_add_req_to_list_and_indicate_osif",
      *(unsigned __int8 *)(*a1 + 168LL),
      *(unsigned int *)(a2 + 16),
      *((unsigned int *)a1 + 28));
    return 16;
  }
}
