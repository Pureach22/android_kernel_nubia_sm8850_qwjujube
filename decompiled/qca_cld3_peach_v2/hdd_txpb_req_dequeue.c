__int64 __fastcall hdd_txpb_req_dequeue(__int64 a1, _DWORD *a2, _QWORD *a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _DWORD *v14; // x21
  unsigned int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w20
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 result; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  _QWORD *v50[2]; // [xsp+0h] [xbp-10h] BYREF

  v50[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v50[0] = nullptr;
  qdf_mutex_acquire(a1 + 8848);
  if ( qdf_list_empty((_QWORD *)(a1 + 8824)) )
  {
    qdf_mutex_release(a1 + 8848);
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: TPB: Failed to find req id",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "hdd_txpb_req_dequeue");
LABEL_10:
    result = 4;
    goto LABEL_11;
  }
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 8824), v50) )
  {
    qdf_mutex_release(a1 + 8848);
    goto LABEL_10;
  }
  while ( v50[0] != a3 )
  {
    if ( (unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 8824), v50[0], v50) )
    {
      qdf_mutex_release(a1 + 8848);
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: TPB: Failed to find matching cookie: %llx",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "hdd_txpb_req_dequeue",
        a3);
      goto LABEL_10;
    }
  }
  v14 = v50[0];
  v15 = qdf_list_remove_node(a1 + 8824, v50[0]);
  if ( v15 )
  {
    v24 = v15;
    qdf_mutex_release(a1 + 8848);
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to remove req_id: %d pending_reqs: %d",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "hdd_txpb_req_dequeue",
      (unsigned int)v14[14],
      *(unsigned int *)(a1 + 8840));
    result = v24;
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: TPB: Cookie match, req_id: %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "hdd_txpb_req_dequeue",
      (unsigned int)v14[14]);
    a2[4] = v14[4];
    a2[14] = v14[14];
    a2[5] = v14[5];
    a2[6] = v14[6];
    a2[7] = v14[7];
    a2[8] = v14[8];
    a2[9] = v14[9];
    a2[10] = v14[10];
    a2[11] = v14[11];
    a2[12] = v14[12];
    a2[13] = v14[13];
    _qdf_mem_free((__int64)v14);
    qdf_mutex_release(a1 + 8848);
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Removed req_id: %d pending_reqs: %d",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "hdd_txpb_req_dequeue",
      (unsigned int)a2[14],
      *(unsigned int *)(a1 + 8840));
    result = 0;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
