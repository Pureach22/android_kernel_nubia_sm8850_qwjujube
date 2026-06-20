_QWORD *__fastcall lim_set_cfg_protection(
        _QWORD *result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  unsigned int v11; // w8
  int v12; // w10
  void *v13; // x0

  v10 = result[1];
  if ( a2 && *(_DWORD *)(a2 + 88) == 1 )
  {
    if ( *(_BYTE *)(a2 + 428) )
    {
      v11 = *(unsigned __int16 *)(a2 + 432);
      return (_QWORD *)qdf_trace_msg(
                         0x35u,
                         8u,
                         "%s: frm11a = %d, from11b = %d, frm11g = %d, ht20 = %d, nongf = %d, lsigTxop = %d, rifs = %d, obss = %d",
                         a3,
                         a4,
                         a5,
                         a6,
                         a7,
                         a8,
                         a9,
                         a10,
                         "lim_set_cfg_protection",
                         (v11 >> 8) & 1,
                         (v11 >> 9) & 1,
                         (v11 >> 10) & 1,
                         (v11 >> 11) & 1,
                         (v11 >> 12) & 1,
                         (v11 >> 13) & 1,
                         (v11 >> 14) & 1,
                         v11 >> 15);
    }
    v13 = (void *)(a2 + 432);
  }
  else
  {
    v12 = *(unsigned __int8 *)(v10 + 3190);
    *((_BYTE *)result + 8884) = v12;
    if ( v12 )
    {
      *((_BYTE *)result + 8881) = *(_BYTE *)(v10 + 3196);
      return result;
    }
    v13 = result + 1110;
  }
  return qdf_mem_set(v13, 4u, 0);
}
