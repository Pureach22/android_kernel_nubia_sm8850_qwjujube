__int64 __fastcall qdf_dp_display_ptr_record(__int64 a1, unsigned __int16 a2, __int64 a3, unsigned int a4)
{
  char v7; // w23
  unsigned int v8; // w0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  const char *v17; // x4
  __int64 result; // x0
  _QWORD v19[12]; // [xsp+0h] [xbp-70h] BYREF
  int v20; // [xsp+60h] [xbp-10h]
  __int64 v21; // [xsp+68h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_BYTE *)(a1 + 8);
  v20 = 0;
  memset(v19, 0, sizeof(v19));
  qdf_mem_set(v19, 0x64u, 0);
  v8 = qdf_dp_trace_fill_meta_str(v19, 100, a2, a4, a1);
  if ( v8 <= 0x63 )
  {
    if ( (v7 & 0xFE) == 0x14 )
      v17 = "status";
    else
      v17 = "vdev_id";
    scnprintf(
      (char *)v19 + v8,
      100LL - v8,
      "[msdu id %d %s %d]",
      *(unsigned __int16 *)(a1 + 17),
      v17,
      *(unsigned __int16 *)(a1 + 19));
  }
  if ( (a4 & 1) != 0 )
    result = qdf_trace_msg(0x38u, 8u, "%s", v9, v10, v11, v12, v13, v14, v15, v16, v19);
  else
    result = dump_dp_hex_trace(v19, a1 + 9, 8);
  _ReadStatusReg(SP_EL0);
  return result;
}
