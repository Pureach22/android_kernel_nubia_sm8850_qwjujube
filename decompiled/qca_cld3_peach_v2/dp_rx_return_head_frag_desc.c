__int64 __fastcall dp_rx_return_head_frag_desc(
        __int64 result,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20
  __int64 v11; // x8
  __int64 v12; // x19
  unsigned __int64 v13; // x9
  char v14; // w11
  unsigned int *v15; // x1
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // [xsp+18h] [xbp-18h] BYREF
  unsigned int *v25[2]; // [xsp+20h] [xbp-10h] BYREF

  v25[1] = *(unsigned int **)(_ReadStatusReg(SP_EL0) + 1808);
  v25[0] = nullptr;
  v24 = 0;
  if ( a2 >= 0x11 )
    goto LABEL_9;
  v10 = result + 120LL * a2;
  v11 = *(_QWORD *)(v10 + 208);
  v12 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)result + 24LL) + 8LL);
  if ( v11 )
  {
    v13 = *(unsigned __int8 *)(v11 + 28);
    if ( v13 <= 1 )
    {
      v14 = *(_BYTE *)(v11 + 30);
      *(_QWORD *)v11 = 0;
      v25[0] = (unsigned int *)v11;
      *(_BYTE *)(v11 + 30) = v14 & 0xFE;
      v24 = v11;
      result = _dp_rx_buffers_replenish(
                 v12,
                 0,
                 (__int64 *)(v12 + 80LL * (unsigned int)v13 + 80),
                 v12 + 120LL * (unsigned int)v13 + 12416,
                 1u,
                 v25,
                 (__int64)&v24,
                 0,
                 0);
      goto LABEL_5;
    }
LABEL_9:
    __break(0x5512u);
  }
LABEL_5:
  v15 = *(unsigned int **)(v10 + 200);
  if ( v15 )
  {
    result = dp_rx_link_desc_return(v12, v15, 0, a3, a4, a5, a6, a7, a8, a9, a10);
    if ( (_DWORD)result )
      result = qdf_trace_msg(
                 0x45u,
                 2u,
                 "%s: Failed to return link desc",
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 "dp_rx_return_head_frag_desc");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
