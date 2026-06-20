__int64 *__fastcall lim_update_add_ie_buffer(
        __int64 *result,
        unsigned __int16 *a2,
        const void *a3,
        unsigned __int16 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v12; // w20
  __int64 *v14; // x21
  const void *v15; // x22
  unsigned __int16 v16; // w23
  __int64 v17; // x0
  __int64 v18; // x8

  if ( !a3 )
    return (__int64 *)qdf_trace_msg(
                        0x35u,
                        2u,
                        "%s: src buffer is null",
                        a5,
                        a6,
                        a7,
                        a8,
                        a9,
                        a10,
                        a11,
                        a12,
                        "lim_update_add_ie_buffer");
  v12 = a4;
  if ( *a2 >= (unsigned int)a4 )
    goto LABEL_4;
  *a2 = a4;
  v14 = result;
  v15 = a3;
  v16 = a4;
  _qdf_mem_free(*result);
  v17 = _qdf_mem_malloc(*a2, "lim_update_add_ie_buffer", 10722);
  a4 = v16;
  a3 = v15;
  v18 = v17;
  result = v14;
  *v14 = v18;
  if ( v18 )
  {
LABEL_4:
    *a2 = a4;
    return (__int64 *)qdf_mem_copy((void *)*result, a3, v12);
  }
  else
  {
    *a2 = 0;
  }
  return result;
}
