__int64 __fastcall hdd_encrypt_decrypt_msg_cb(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x0
  __int64 v21; // x19
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x0
  __int64 v31; // x8
  __int64 v32; // x9
  __int64 v33; // x21
  __int64 v34; // x10
  size_t v35; // x0
  void *v36; // x0
  const char *v37; // x2
  unsigned int v38; // w1

  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_encrypt_decrypt_msg_cb");
  if ( !a2 )
  {
    v37 = "%s: rsp params is NULL";
LABEL_8:
    v38 = 2;
    return qdf_trace_msg(0x33u, v38, v37, v12, v13, v14, v15, v16, v17, v18, v19, "hdd_encrypt_decrypt_msg_cb");
  }
  v20 = osif_request_get(a1);
  if ( !v20 )
  {
    v37 = "%s: Obsolete request";
    goto LABEL_8;
  }
  v21 = v20;
  print_hex_dump(&unk_96007A, "Data in hdd_encrypt_decrypt_msg_cb: ", 0, 16, 1, *((_QWORD *)a2 + 2), a2[2], 0);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: vdev_id: %d status:%d data_length: %d",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    "hdd_encrypt_decrypt_msg_cb",
    *a2,
    a2[1],
    a2[2]);
  v30 = osif_request_priv(v21);
  v31 = *(_QWORD *)a2;
  v32 = *((_QWORD *)a2 + 1);
  v33 = v30;
  v34 = *((_QWORD *)a2 + 2);
  *(_DWORD *)v30 = 0;
  *(_QWORD *)(v30 + 120) = v31;
  *(_QWORD *)(v30 + 128) = v32;
  *(_QWORD *)(v30 + 136) = v34;
  v35 = a2[2];
  if ( (_DWORD)v35 )
  {
    v36 = (void *)_qdf_mem_malloc(v35, "hdd_encrypt_decrypt_msg_cb", 92);
    *(_QWORD *)(v33 + 136) = v36;
    if ( v36 )
      qdf_mem_copy(v36, *((const void **)a2 + 2), a2[2]);
    else
      *(_DWORD *)v33 = -12;
  }
  else
  {
    *(_QWORD *)(v33 + 136) = 0;
  }
  osif_request_complete(v21);
  osif_request_put(v21);
  v37 = "%s: exit";
  v38 = 8;
  return qdf_trace_msg(0x33u, v38, v37, v12, v13, v14, v15, v16, v17, v18, v19, "hdd_encrypt_decrypt_msg_cb");
}
