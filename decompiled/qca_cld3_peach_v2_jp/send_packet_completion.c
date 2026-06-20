__int64 __fastcall send_packet_completion(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w8
  __int64 v6; // x22
  int v7; // w8
  __int64 v8; // x21
  int v9; // w8
  __int64 v10; // x0
  unsigned int v11; // w8
  __int64 v12; // x8
  __int64 result; // x0
  __int64 (__fastcall *v14)(__int64, __int64); // x8
  __int64 v15; // x0

  v3 = *(_DWORD *)(a2 + 48);
  if ( v3 >= 0xA )
  {
    __break(0x5512u);
    return htc_try_send(a1, a2, a3);
  }
  v6 = a1 + 328LL * v3;
  v7 = *(_DWORD *)(a2 + 72);
  if ( (v7 & 1) != 0 )
  {
    if ( *(_BYTE *)(v6 + 308) == 1 )
    {
      v8 = *(_QWORD *)(a2 + 96);
    }
    else
    {
      ++*(_DWORD *)(a1 + 3576);
      v9 = *(_DWORD *)(a2 + 72);
      v8 = *(_QWORD *)(a2 + 96);
      if ( (v9 & 1) == 0 )
      {
        if ( (v9 & 2) != 0 )
          goto LABEL_12;
        goto LABEL_9;
      }
    }
    _qdf_nbuf_unmap(*(_QWORD *)(a1 + 3456), v8, 1);
    v11 = *(_DWORD *)(a2 + 72) & 0xFFFFFFFE;
    *(_DWORD *)(a2 + 72) = v11;
    if ( (v11 & 2) != 0 )
      goto LABEL_12;
LABEL_9:
    v10 = *(_QWORD *)a1;
    if ( *(_QWORD *)a1 )
      goto LABEL_15;
    goto LABEL_17;
  }
  v8 = *(_QWORD *)(a2 + 96);
  if ( (v7 & 2) == 0 )
    goto LABEL_9;
LABEL_12:
  v12 = *(_QWORD *)(v8 + 40);
  if ( v12 )
    *(_QWORD *)(v8 + 40) = v12 + 8;
  skb_pull(v8, 8);
  *(_DWORD *)(a2 + 72) &= ~2u;
  v10 = *(_QWORD *)a1;
  if ( *(_QWORD *)a1 )
  {
LABEL_15:
    if ( (unsigned int)hif_get_target_status(v10) )
      return htc_free_control_tx_packet(a1, a2);
  }
LABEL_17:
  if ( (dword_B0B4 & 0x100) != 0 )
    qdf_trace_msg(
      56,
      2,
      "%s: HTC calling ep %d send complete callback on packet %pK\n",
      "send_packet_completion",
      *(_DWORD *)(v6 + 8),
      (const void *)a2);
  v14 = *(__int64 (__fastcall **)(__int64, __int64))(v6 + 24);
  if ( v14 )
  {
    v15 = *(_QWORD *)(v6 + 16);
    if ( *((_DWORD *)v14 - 1) != 1226475842 )
      __break(0x8228u);
    return v14(v15, a2);
  }
  else
  {
    result = *(_QWORD *)(a2 + 16);
    if ( result )
      return _qdf_nbuf_free(result);
  }
  return result;
}
