__int64 __fastcall lim_decide_eht_op(
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
        __int64 a11)
{
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 result; // x0
  unsigned __int16 v31; // w22
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  _QWORD v40[3]; // [xsp+8h] [xbp-18h] BYREF

  v40[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v40, 0, 15);
  qdf_trace_msg(0x35u, 8u, "%s: beacon ie:", a1, a2, a3, a4, a5, a6, a7, a8, "lim_decide_eht_op");
  ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))qdf_trace_hex_dump)(
    53,
    8,
    *(_QWORD *)(a11 + 7328),
    *(unsigned __int16 *)(a11 + 7320));
  qdf_mem_set(v40, 0xFu, 0);
  v21 = wlan_strip_ie(
          *(unsigned __int8 **)(a11 + 7328),
          (unsigned __int16 *)(a11 + 7320),
          0xFFu,
          1,
          "j",
          1u,
          (char *)v40,
          13,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20);
  if ( v21 )
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Failed to strip EHT OP IE status: %d",
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               "lim_decide_eht_op",
               v21);
  }
  else
  {
    qdf_trace_msg(0x35u, 8u, "%s: eht op:", v22, v23, v24, v25, v26, v27, v28, v29, "lim_decide_eht_op");
    ((void (__fastcall *)(__int64, __int64, _QWORD *, __int64))qdf_trace_hex_dump)(53, 8, v40, 13);
    *(_BYTE *)(a11 + 10164) = 1;
    qdf_mem_copy((void *)(a11 + 10165), (char *)v40 + 3, 0xAu);
    v31 = *(_WORD *)(a11 + 10173);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: puncture bitmap: %d, ch width: %d, ccfs0: %d, ccfs1: %d",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "lim_decide_eht_op",
      v31,
      *(_BYTE *)(a11 + 10170) & 7,
      *(unsigned __int8 *)(a11 + 10171),
      *(unsigned __int8 *)(a11 + 10172));
    *(_WORD *)(a11 + 7184) = v31;
    result = wma_update_vdev_eht_ops(a10, a11 + 10164);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
