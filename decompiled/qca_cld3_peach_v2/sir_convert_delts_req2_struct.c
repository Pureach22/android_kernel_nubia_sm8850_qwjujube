__int64 __fastcall sir_convert_delts_req2_struct(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned int a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  int v12; // w4
  __int64 v17; // x5
  __int64 v18; // x6
  __int64 v19; // x7
  int v20; // w4
  unsigned int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x4
  __int64 result; // x0
  int v32; // w9
  const char *v33; // x2
  unsigned int v34; // w0
  __int64 v35; // [xsp+8h] [xbp-58h] BYREF
  int v36; // [xsp+10h] [xbp-50h]
  _QWORD v37[9]; // [xsp+18h] [xbp-48h] BYREF

  v37[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = a2[1];
  v36 = 0;
  v35 = 0;
  memset(v37, 0, 64);
  if ( v12 != 2 )
  {
    v33 = "%s: sirConvertDeltsRsp2Struct invoked with an Action of %d; this is not supported & is probably an error";
    goto LABEL_13;
  }
  qdf_mem_set((void *)a4, 0x3Fu, 0);
  v20 = *a2;
  if ( v20 != 17 )
  {
    if ( v20 == 1 )
    {
      v21 = dot11f_unpack_del_ts(a1, (__int64)a2, a3, (__int64)&v35, 0, v17, v18, v19);
      v30 = v21;
      if ( (v21 & 0x10000000) == 0 )
        goto LABEL_5;
      goto LABEL_11;
    }
    v33 = "%s: sirConvertDeltsRsp2Struct invoked with a Category of %d; this is not supported & is probably an error";
LABEL_13:
    qdf_trace_msg(0x35u, 2u, v33, a5, a6, a7, a8, a9, a10, a11, a12, "sir_convert_delts_req2_struct");
    goto LABEL_14;
  }
  v34 = dot11f_unpack_wmm_del_ts(a1, (__int64)a2, a3, (__int64)v37, 0, v17, v18, v19);
  v30 = v34;
  if ( (v34 & 0x10000000) != 0 )
  {
LABEL_11:
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to parse an Del TS Request frame (0x%08x, %d bytes):",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "sir_convert_delts_req2_struct",
      v30,
      a3);
    ((void (__fastcall *)(__int64, __int64, unsigned __int8 *, _QWORD))qdf_trace_hex_dump)(53, 2, a2, a3);
LABEL_14:
    result = 16;
    goto LABEL_15;
  }
LABEL_5:
  if ( (_DWORD)v30 )
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: There were warnings while unpacking an Del TS Request frame (0x%08x,%d bytes):",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "sir_convert_delts_req2_struct",
      v30,
      a3);
  if ( *a2 != 1 )
  {
    if ( BYTE4(v37[0]) )
    {
      *(_BYTE *)(a4 + 62) |= 1u;
      convert_wmmtspec(a1, a4 + 4, (char *)v37 + 4);
      result = 0;
      goto LABEL_15;
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Mandatory WME TSPEC element missing!",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "sir_convert_delts_req2_struct");
    goto LABEL_14;
  }
  result = 0;
  v32 = *(_BYTE *)(a4 + 3) & 0xFE | HIWORD(HIDWORD(v35)) & 1;
  *(_WORD *)(a4 + 1) = WORD2(v35);
  *(_BYTE *)(a4 + 3) = v32;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
