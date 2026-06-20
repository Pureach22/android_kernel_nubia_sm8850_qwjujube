__int64 __fastcall sme_deregister_mgmt_frame(
        __int64 a1,
        unsigned __int8 a2,
        __int16 a3,
        const void *a4,
        unsigned __int16 a5)
{
  unsigned int v5; // w23
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  unsigned int v21; // w20
  __int64 v22; // x0
  __int64 v23; // x22

  v5 = a2;
  qdf_trace(52, 0x37u, a2, 0);
  result = qdf_mutex_acquire(a1 + 12848);
  if ( !(_DWORD)result )
  {
    if ( v5 > 5 )
      v20 = 0;
    else
      v20 = *(_QWORD *)(a1 + 17296) + 96LL * a2;
    if ( a2 == 50 || v20 )
    {
      if ( a2 == 50 || (*(_BYTE *)(v20 + 1) & 1) != 0 )
      {
        v22 = _qdf_mem_malloc((unsigned __int16)(a5 + 12), "sme_deregister_mgmt_frame", 5740);
        if ( v22 )
        {
          *(_WORD *)(v22 + 2) = a5 + 12;
          *(_WORD *)v22 = 5175;
          *(_BYTE *)(v22 + 5) = 0;
          *(_WORD *)(v22 + 6) = a3;
          v23 = v22;
          *(_WORD *)(v22 + 8) = a5;
          qdf_mem_copy((void *)(v22 + 10), a4, a5);
          v21 = umac_send_mb_message_to_mac(v23);
        }
        else
        {
          v21 = 2;
        }
        goto LABEL_14;
      }
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Invalid Sessionid",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "sme_deregister_mgmt_frame");
    }
    else
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Session %d not found",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "sme_deregister_mgmt_frame",
        v5);
    }
    v21 = 16;
LABEL_14:
    qdf_mutex_release(a1 + 12848);
    return v21;
  }
  return result;
}
