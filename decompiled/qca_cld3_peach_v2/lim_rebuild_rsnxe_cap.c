_WORD *__fastcall lim_rebuild_rsnxe_cap(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _WORD *result; // x0
  const void *v10; // x20
  _WORD *v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _BYTE v20[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  result = wlan_crypto_parse_rsnxe_ie(a1, v20, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    v10 = result;
    result = (_WORD *)_qdf_mem_malloc(3u, "lim_rebuild_rsnxe_cap", 4259);
    if ( result )
    {
      v11 = result;
      *result = 500;
      qdf_mem_copy(result + 1, v10, 1u);
      *((_BYTE *)v11 + 2) &= 0xF0u;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: New RSNXE length %d",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "lim_rebuild_rsnxe_cap",
        1);
      ((void (__fastcall *)(__int64, __int64, _WORD *, __int64))qdf_trace_hex_dump)(53, 8, v11, 3);
      result = v11;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
