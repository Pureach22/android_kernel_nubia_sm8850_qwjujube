__int64 __fastcall populate_dot11f_wmmtclas(
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
  int v12; // w4
  int v14; // w8
  void *v15; // x0
  const void *v17; // x1

  *(_BYTE *)(a11 + 1) = 1;
  *(_BYTE *)(a11 + 2) = *(_BYTE *)(a10 + 2);
  v12 = *(unsigned __int8 *)(a10 + 3);
  *(_BYTE *)(a11 + 3) = v12;
  *(_BYTE *)(a11 + 4) = *(_BYTE *)(a10 + 4);
  if ( v12 == 2 )
  {
    *(_WORD *)(a11 + 6) = *(_WORD *)(a10 + 6);
  }
  else if ( v12 == 1 )
  {
    v14 = *(unsigned __int8 *)(a10 + 5);
    v15 = (void *)(a11 + 8);
    v17 = (const void *)(a10 + 7);
    *(_BYTE *)(a11 + 6) = v14;
    if ( v14 == 4 )
    {
      qdf_mem_copy(v15, v17, 4u);
      qdf_mem_copy((void *)(a11 + 12), (const void *)(a10 + 11), 4u);
      *(_WORD *)(a11 + 16) = *(_WORD *)(a10 + 15);
      *(_WORD *)(a11 + 18) = *(_WORD *)(a10 + 17);
      *(_BYTE *)(a11 + 20) = *(_BYTE *)(a10 + 19);
      *(_BYTE *)(a11 + 21) = *(_BYTE *)(a10 + 20);
      *(_BYTE *)(a11 + 22) = *(_BYTE *)(a10 + 21);
    }
    else
    {
      qdf_mem_copy(v15, v17, 0x10u);
      qdf_mem_copy((void *)(a11 + 24), (const void *)(a10 + 23), 0x10u);
      *(_WORD *)(a11 + 40) = *(_WORD *)(a10 + 39);
      *(_WORD *)(a11 + 42) = *(_WORD *)(a10 + 41);
      qdf_mem_copy((void *)(a11 + 44), (const void *)(a10 + 43), 3u);
    }
  }
  else
  {
    if ( v12 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Bad TCLAS type %d in populate_dot11f_tclas",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "populate_dot11f_wmmtclas");
      return 16;
    }
    qdf_mem_copy((void *)(a11 + 6), (const void *)(a10 + 6), 6u);
    qdf_mem_copy((void *)(a11 + 12), (const void *)(a10 + 12), 6u);
    *(_WORD *)(a11 + 18) = *(_WORD *)(a10 + 18);
  }
  *(_BYTE *)a11 = 1;
  return 0;
}
