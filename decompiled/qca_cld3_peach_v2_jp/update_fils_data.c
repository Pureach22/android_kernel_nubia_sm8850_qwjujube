_BYTE *__fastcall update_fils_data(
        _BYTE *result,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w21
  _BYTE *v12; // x19
  char *v13; // x22
  unsigned int v14; // w8
  int v15; // w5
  size_t v16; // x2

  v10 = (unsigned __int8)a2[3];
  *result = 1;
  v12 = result;
  v13 = a2 + 4;
  result[1] = (a2[1] & 0x40) != 0;
  result[2] = (*(_WORD *)(a2 + 1) & 0x200) != 0;
  result[3] = (*(_WORD *)(a2 + 1) & 0x400) != 0;
  result[4] = (*(_WORD *)(a2 + 1) & 0x800) != 0;
  v14 = *(unsigned __int16 *)(a2 + 1);
  if ( (v14 & 0x80) != 0 )
  {
    if ( v10 <= 1 )
      return (_BYTE *)qdf_trace_msg(
                        0x35u,
                        2u,
                        "%s: Failed to copy Cache Identifier, Invalid remaining data %d",
                        a3,
                        a4,
                        a5,
                        a6,
                        a7,
                        a8,
                        a9,
                        a10,
                        "update_fils_data",
                        v10);
    result[5] = 1;
    result = qdf_mem_copy(result + 6, a2 + 4, 2u);
    v14 = *(unsigned __int16 *)(a2 + 1);
    v13 = a2 + 6;
    LOBYTE(v10) = v10 - 2;
  }
  if ( (v14 & 0x100) != 0 )
  {
    if ( (unsigned __int8)v10 <= 5u )
      return (_BYTE *)qdf_trace_msg(
                        0x35u,
                        2u,
                        "%s: Failed to copy HESSID, Invalid remaining data %d",
                        a3,
                        a4,
                        a5,
                        a6,
                        a7,
                        a8,
                        a9,
                        a10,
                        "update_fils_data");
    v12[8] = 1;
    result = qdf_mem_copy(v12 + 9, v13, 6u);
    v14 = *(unsigned __int16 *)(a2 + 1);
    v13 += 6;
    LOBYTE(v10) = v10 - 6;
  }
  v15 = (v14 >> 3) & 7;
  if ( v15 )
  {
    if ( (unsigned __int8)v10 >= (unsigned int)(2 * v15) )
    {
      v12[15] = 1;
      v16 = 2 * (((unsigned __int8)a2[1] >> 3) & 7u);
      v12[16] = (a2[1] >> 3) & 7;
      return qdf_mem_copy(v12 + 17, v13, v16);
    }
    else
    {
      return (_BYTE *)qdf_trace_msg(
                        0x35u,
                        2u,
                        "%s: Failed to copy Realm Identifier, Invalid remaining data %d realm_cnt %d",
                        a3,
                        a4,
                        a5,
                        a6,
                        a7,
                        a8,
                        a9,
                        a10,
                        "update_fils_data");
    }
  }
  return result;
}
