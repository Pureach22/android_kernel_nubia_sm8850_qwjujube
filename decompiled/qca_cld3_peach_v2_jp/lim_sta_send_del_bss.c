__int64 __fastcall lim_sta_send_del_bss(__int64 a1)
{
  __int64 v1; // x20
  __int16 *hash_entry; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x4
  unsigned int v22; // w19

  v1 = *(_QWORD *)(a1 + 8608);
  hash_entry = (__int16 *)dph_get_hash_entry(v1, 1u, a1 + 360);
  if ( hash_entry )
  {
    result = lim_del_bss(v1, hash_entry, 0, a1);
    if ( (_DWORD)result )
    {
      v21 = *(unsigned __int8 *)(a1 + 10);
      v22 = result;
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: delBss failed for bss %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "lim_sta_send_del_bss",
        v21);
      return v22;
    }
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: DPH Entry for STA is missing, failed to send delbss",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "lim_sta_send_del_bss");
    return 16;
  }
  return result;
}
