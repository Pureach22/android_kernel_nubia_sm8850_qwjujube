__int64 __fastcall qdf_trace_hex_ascii_dump(
        __int64 result,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24)
{
  __int64 v25; // x2
  char *v26; // x8
  unsigned int v27; // w22
  unsigned int v29; // w19
  char *v30; // x8
  unsigned __int64 v31; // x9
  int v32; // w8
  __int64 v33; // x23
  __int64 v34; // x1
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  bool v43; // cf
  void *v44; // x0
  _QWORD v45[26]; // [xsp+0h] [xbp-D0h] BYREF

  v45[25] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = (unsigned int)qdf_pidx;
  if ( (unsigned int)qdf_pidx >= 0x20 )
  {
    v44 = &unk_999B93;
LABEL_21:
    result = printk(v44, "qdf_print_is_verbose_enabled", v25, a4);
    goto LABEL_22;
  }
  v26 = (char *)&print_ctrl_obj + 392 * (unsigned int)qdf_pidx;
  if ( (v26[384] & 1) == 0 )
  {
    result = printk(&unk_9134FE, "qdf_print_is_verbose_enabled", (unsigned int)qdf_pidx, a4);
    goto LABEL_22;
  }
  v27 = result;
  if ( (unsigned int)result >= 0xA7 )
  {
    v44 = &unk_91E391;
    v25 = v27;
    goto LABEL_21;
  }
  if ( a2 - 11 < 0xFFFFFFF6 )
    goto LABEL_22;
  v29 = a4;
  v30 = v26 + 32;
  v31 = (392LL * (unsigned int)qdf_pidx + 2 * (unsigned __int64)(unsigned int)result + 32) >> 8;
  if ( a2 != 10 )
  {
    if ( v31 > 0x30 )
      goto LABEL_23;
    v32 = (*(unsigned __int16 *)&v30[2 * (unsigned int)result] >> a2) & 1;
    if ( (int)a4 >= 1 )
      goto LABEL_11;
LABEL_22:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( v31 <= 0x30 )
  {
    v32 = *(__int16 *)&v30[2 * (unsigned int)result] == -1;
    if ( (int)a4 < 1 )
      goto LABEL_22;
LABEL_11:
    if ( v32 )
    {
      v33 = 0;
      do
      {
        if ( v29 >= 0x10 )
          v34 = 16;
        else
          v34 = v29;
        memset(v45, 0, 199);
        hex_dump_to_buffer(a3 + v33, v34, 16, 1, v45, 199, 1);
        result = qdf_trace_msg(v27, a2, "%.8x: %s", v35, v36, v37, v38, v39, v40, v41, v42, (unsigned int)v33, v45);
        v43 = v29 >= 0x10;
        v29 -= 16;
        v33 += 16;
      }
      while ( v29 != 0 && v43 );
    }
    goto LABEL_22;
  }
LABEL_23:
  __break(1u);
  atomic_load_explicit((atomic_ullong *volatile)((char *)&a24 + 2), memory_order_acquire);
  return qdf_trace_enable();
}
