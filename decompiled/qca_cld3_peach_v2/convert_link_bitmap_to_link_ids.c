__int64 __fastcall convert_link_bitmap_to_link_ids(
        __int64 result,
        unsigned __int8 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w5
  unsigned int v12; // w4
  bool v13; // cc
  unsigned int v14; // w19

  if ( !(_DWORD)result )
    return result;
  v11 = result;
  v12 = 0;
  result = 0;
  while ( 1 )
  {
    if ( (v11 & 1) == 0 )
      goto LABEL_4;
    if ( v12 >= 0xF )
    {
      v14 = result;
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: linkid invalid %d 0x%x",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "convert_link_bitmap_to_link_ids");
      return v14;
    }
    if ( a3 )
      break;
LABEL_3:
    result = (unsigned int)(result + 1);
LABEL_4:
    v13 = v11 > 1;
    ++v12;
    v11 >>= 1;
    if ( !v13 )
      return result;
  }
  if ( (unsigned int)result < a2 )
  {
    *(_BYTE *)(a3 + (unsigned int)result) = v12;
    goto LABEL_3;
  }
  v14 = result;
  qdf_trace_msg(
    0x8Fu,
    2u,
    "%s: linkid buff overflow 0x%x",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "convert_link_bitmap_to_link_ids",
    v11);
  return v14;
}
