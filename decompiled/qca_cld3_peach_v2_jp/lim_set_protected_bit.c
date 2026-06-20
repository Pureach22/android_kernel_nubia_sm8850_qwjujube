unsigned __int16 *__fastcall lim_set_protected_bit(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
        _WORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned __int16 *result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w8
  unsigned int v23; // w9
  __int16 v24; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+8h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  result = (unsigned __int16 *)dph_lookup_hash_entry(a5, a6, a7, a8, a9, a10, a11, a12, a1, a3, &v24, a2 + 360);
  if ( result )
  {
    v22 = *result;
    if ( (v22 & 0x400) != 0 )
    {
      v23 = (unsigned __int16)*a4;
      if ( *((_BYTE *)result + 641) )
      {
        v23 |= 0x4000u;
        *a4 = v23;
        v22 = *result;
      }
    }
    else
    {
      v23 = (unsigned __int16)*a4;
    }
    result = (unsigned __int16 *)qdf_trace_msg(
                                   0x35u,
                                   8u,
                                   "%s: wep:%d rmf:%d is_key_set:%d",
                                   v14,
                                   v15,
                                   v16,
                                   v17,
                                   v18,
                                   v19,
                                   v20,
                                   v21,
                                   "lim_set_protected_bit",
                                   (v23 >> 14) & 1,
                                   (v22 >> 10) & 1,
                                   *((unsigned __int8 *)result + 641));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
