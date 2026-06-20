__int64 __fastcall lim_get_partner_link_info_from_rnr(
        __int64 a1,
        unsigned __int8 a2,
        _BYTE *a3,
        unsigned __int8 *a4,
        unsigned __int8 *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x29
  __int64 v14; // x30
  unsigned __int16 *v15; // x13
  unsigned __int64 v16; // x8
  unsigned __int16 *v18; // x12
  unsigned __int64 v19; // x17
  int v20; // w16
  unsigned __int64 v21; // x14
  int v22; // w15
  __int64 v23; // x0
  unsigned __int16 *v24; // x13
  unsigned int v25; // w16

  if ( !a1 )
    return 4;
  v15 = (unsigned __int16 *)(a1 + 6);
  v16 = a1 + *(unsigned __int8 *)(a1 + 1) + 2;
  if ( a1 + 6 > v16 )
    return 4;
  v18 = (unsigned __int16 *)(a1 + 2);
  while ( 1 )
  {
    *a4 = *((_BYTE *)v18 + 2);
    *a5 = *((_BYTE *)v18 + 3);
    v19 = *v18;
    v20 = (unsigned __int8)v19 >> 4;
    v21 = v19 >> 8;
    v22 = v20 + 1;
    v18 = (unsigned __int16 *)((char *)v18 + (v20 + 1) * (unsigned int)(v19 >> 8) + 4);
    if ( (unsigned __int64)v18 > v16 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: error about rnr length",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "lim_get_partner_link_info_from_rnr",
        v13,
        v14);
      return 4;
    }
    v23 = (unsigned int)v19 >= 0x1000 ? 13LL : 0LL;
    if ( (unsigned int)v19 >= 0x1000 && (v19 & 3) == 0 )
      break;
LABEL_5:
    v15 = v18 + 2;
    if ( (unsigned __int64)(v18 + 2) > v16 )
      return 4;
  }
  v18 = (unsigned __int16 *)((char *)v15 + (unsigned int)(v21 + v21 * v20));
  v24 = (unsigned __int16 *)((char *)v15 + v23 + 1);
  while ( 1 )
  {
    if ( !*((_BYTE *)v24 - 1) )
    {
      v25 = *v24;
      if ( (v25 & 0xF) == a2 )
        break;
    }
    --v22;
    v24 = (unsigned __int16 *)((char *)v24 + v21);
    if ( !v22 )
      goto LABEL_5;
  }
  *a3 = v25 >> 4;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: rnr bpcc %d, chan %d, opclass %d, linkid %d",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "lim_get_partner_link_info_from_rnr",
    (unsigned __int8)(v25 >> 4),
    *a5,
    *a4,
    a2,
    v13,
    v14);
  return 0;
}
