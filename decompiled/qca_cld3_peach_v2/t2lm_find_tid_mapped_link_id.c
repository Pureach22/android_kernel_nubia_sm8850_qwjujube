__int64 __fastcall t2lm_find_tid_mapped_link_id(
        __int64 a1,
        _WORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v11; // w8

  if ( !a1 )
    return 29;
  if ( *(_BYTE *)(a1 + 4) == 1 )
  {
    qdf_trace_msg(
      0x99u,
      8u,
      "%s: T2LM ie has default link mapping",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "t2lm_find_tid_mapped_link_id");
    LOWORD(v11) = -1;
LABEL_4:
    *a2 = v11;
    return 0;
  }
  v11 = *(unsigned __int16 *)(a1 + 16);
  if ( v11 == *(unsigned __int16 *)(a1 + 18)
    && v11 == *(unsigned __int16 *)(a1 + 20)
    && v11 == *(unsigned __int16 *)(a1 + 22)
    && v11 == *(unsigned __int16 *)(a1 + 24)
    && v11 == *(unsigned __int16 *)(a1 + 26)
    && v11 == *(unsigned __int16 *)(a1 + 28)
    && v11 == *(unsigned __int16 *)(a1 + 30) )
  {
    goto LABEL_4;
  }
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: all tids are not mapped to same link set",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "t2lm_find_tid_mapped_link_id");
  return 16;
}
