__int64 __fastcall qdf_dp_display_data_pkt_record(__int64 a1, unsigned __int16 a2, __int64 a3, unsigned int a4)
{
  unsigned int v7; // w0
  __int64 result; // x0
  _QWORD v9[7]; // [xsp+8h] [xbp-48h] BYREF
  int v10; // [xsp+40h] [xbp-10h]
  __int64 v11; // [xsp+48h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  memset(v9, 0, sizeof(v9));
  qdf_mem_set(v9, 0x3Cu, 0);
  v7 = qdf_dp_trace_fill_meta_str(v9, 60, a2, a4, a1);
  if ( v7 <= 0x3B )
    snprintf((char *)v9 + v7, 60LL - v7, "[%d]", *(unsigned __int16 *)(a1 + 9));
  result = dump_dp_hex_trace(v9, a1 + 11, *(unsigned __int8 *)(a1 + 75));
  _ReadStatusReg(SP_EL0);
  return result;
}
