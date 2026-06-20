__int64 __fastcall extract_dbr_buf_release_entry_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        unsigned __int8 a11,
        _DWORD *a12)
{
  __int64 v12; // x20

  if ( !a10 )
    return 4;
  v12 = *(_QWORD *)(a10 + 16) + 12LL * a11;
  if ( v12 )
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: paddr_lo[%d] = %x",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_dbr_buf_release_entry_tlv",
      a11,
      *(unsigned int *)(v12 + 4));
    *a12 = *(_DWORD *)(v12 + 4);
    a12[1] = *(_DWORD *)(v12 + 8);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x31u, 2u, "%s: Entry is NULL", a1, a2, a3, a4, a5, a6, a7, a8, "extract_dbr_buf_release_entry_tlv");
    return 16;
  }
}
