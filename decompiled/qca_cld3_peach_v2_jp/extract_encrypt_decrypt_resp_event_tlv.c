__int64 __fastcall extract_encrypt_decrypt_resp_event_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        __int64 a11)
{
  __int64 v11; // x8
  unsigned int v12; // w4
  __int64 result; // x0

  if ( !a10 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: encrypt decrypt resp evt_buf is NULL",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_encrypt_decrypt_resp_event_tlv");
    return 4;
  }
  v11 = *a10;
  *(_DWORD *)a11 = *(_DWORD *)(*a10 + 4);
  *(_DWORD *)(a11 + 4) = *(_DWORD *)(v11 + 8);
  v12 = *(_DWORD *)(v11 + 12);
  if ( v12 > 0x5EC || v12 > *((_DWORD *)a10 + 6) )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: FW msg data_len %d more than TLV hdr %d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_encrypt_decrypt_resp_event_tlv");
    return 4;
  }
  result = 0;
  *(_DWORD *)(a11 + 8) = v12;
  if ( v12 )
    *(_QWORD *)(a11 + 16) = a10[2];
  return result;
}
