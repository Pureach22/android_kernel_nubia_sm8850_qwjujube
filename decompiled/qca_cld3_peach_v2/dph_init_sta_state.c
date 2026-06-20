_WORD *__fastcall dph_init_sta_state(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        const void *a10,
        unsigned __int16 a11,
        __int64 a12)
{
  _WORD *v13; // x20
  __int64 v15; // x22
  __int16 v16; // w8

  if ( *(unsigned __int16 *)(a12 + 16) <= (unsigned int)a11 )
  {
    qdf_trace_msg(0x35u, 2u, "%s: Invalid Assoc Id %d", a1, a2, a3, a4, a5, a6, a7, a8, "dph_init_sta_state", a11);
    return nullptr;
  }
  else
  {
    v13 = (_WORD *)(*(_QWORD *)(a12 + 8) + 1272LL * (unsigned __int8)a11);
    v15 = *((_QWORD *)v13 + 134);
    qdf_mem_set(v13, 0x4F8u, 0);
    *((_QWORD *)v13 + 134) = v15;
    v13[174] = a11;
    qdf_mem_copy(v13 + 175, a10, 6u);
    v16 = *v13;
    *((_BYTE *)v13 + 661) = 0;
    *v13 = v16 | 9;
    *(_WORD *)((char *)v13 + 657) = 0;
    return v13;
  }
}
