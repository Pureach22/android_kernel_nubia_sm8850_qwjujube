__int64 __fastcall sme_register_mgmt_frame(
        __int64 a1,
        unsigned __int8 a2,
        __int16 a3,
        const void *a4,
        unsigned __int16 a5)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  unsigned int v20; // w20
  __int64 v21; // x0
  __int64 v22; // x22

  result = qdf_mutex_acquire(a1 + 12776);
  if ( !(_DWORD)result )
  {
    if ( a2 > 5u )
    {
      v19 = 0;
      if ( a2 == 50 )
        goto LABEL_8;
    }
    else
    {
      v19 = *(_QWORD *)(a1 + 17224) + 96LL * a2;
    }
    if ( !v19 )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Session %d not found",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "sme_register_mgmt_frame");
      goto LABEL_7;
    }
LABEL_8:
    if ( a2 == 50 || (*(_BYTE *)(v19 + 1) & 1) != 0 )
    {
      v21 = _qdf_mem_malloc((unsigned __int16)(a5 + 12), "sme_register_mgmt_frame", 5680);
      if ( v21 )
      {
        *(_WORD *)(v21 + 2) = a5 + 12;
        *(_WORD *)v21 = 5175;
        *(_BYTE *)(v21 + 4) = a2;
        *(_BYTE *)(v21 + 5) = 1;
        *(_WORD *)(v21 + 6) = a3;
        v22 = v21;
        *(_WORD *)(v21 + 8) = a5;
        qdf_mem_copy((void *)(v21 + 10), a4, a5);
        v20 = umac_send_mb_message_to_mac(v22);
      }
      else
      {
        v20 = 2;
      }
      goto LABEL_13;
    }
    qdf_trace_msg(0x34u, 2u, "%s: Invalid Sessionid", v11, v12, v13, v14, v15, v16, v17, v18, "sme_register_mgmt_frame");
LABEL_7:
    v20 = 16;
LABEL_13:
    qdf_mutex_release(a1 + 12776);
    return v20;
  }
  return result;
}
