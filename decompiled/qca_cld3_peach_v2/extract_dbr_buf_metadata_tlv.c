__int64 __fastcall extract_dbr_buf_metadata_tlv(
        int a1,
        __int64 a2,
        unsigned __int8 a3,
        _DWORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _DWORD *v12; // x19

  if ( !a2 )
    return 4;
  v12 = (_DWORD *)(*(_QWORD *)(a2 + 32) + 52LL * a3);
  if ( v12 )
  {
    qdf_mem_copy(a4, v12 + 1, 0x20u);
    a4[8] = v12[9];
    a4[9] = v12[10];
    a4[10] = v12[11];
    a4[11] = v12[12];
    return 0;
  }
  else
  {
    qdf_trace_msg(0x31u, 2u, "%s: Entry is NULL", a5, a6, a7, a8, a9, a10, a11, a12, "extract_dbr_buf_metadata_tlv");
    return 16;
  }
}
