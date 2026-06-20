__int64 __fastcall sme_update_session_param(__int64 a1, unsigned __int8 a2, int a3, int a4)
{
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x0
  unsigned int v18; // w20

  result = qdf_mutex_acquire(a1 + 12776);
  if ( !(_DWORD)result )
  {
    if ( a2 <= 5u && *(_QWORD *)(a1 + 17224) + 96LL * a2 )
    {
      v17 = _qdf_mem_malloc(0x10u, "sme_update_session_param", 6553);
      if ( v17 )
      {
        *(_BYTE *)(v17 + 4) = a2;
        *(_DWORD *)(v17 + 8) = a3;
        *(_DWORD *)(v17 + 12) = a4;
        *(_DWORD *)v17 = 1053735;
        v18 = umac_send_mb_message_to_mac(v17);
      }
      else
      {
        v18 = 2;
      }
    }
    else
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Session: %d not found",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "sme_update_session_param");
      v18 = 0;
    }
    qdf_mutex_release(a1 + 12776);
    return v18;
  }
  return result;
}
