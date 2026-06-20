__int64 __fastcall dp_rx_pdev_mon_buf_buffers_alloc(
        unsigned __int8 *a1,
        unsigned int a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *v13; // x19
  __int64 v14; // x4
  __int64 v15; // x26
  unsigned int v16; // w8
  _QWORD *v17; // x9
  __int64 v18; // x10
  __int64 *v19; // x21
  unsigned int *v20; // x9
  unsigned int v21; // w24
  __int64 v22; // x23
  __int64 result; // x0
  unsigned int *v24; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v25[2]; // [xsp+20h] [xbp-10h] BYREF

  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *((_QWORD **)a1 + 1);
  v14 = *a1;
  v15 = v13[5];
  if ( *(_BYTE *)(v15 + 633) == 1 )
  {
    v16 = (unsigned __int8)a2;
    if ( (unsigned __int8)a2 < 3u )
    {
      v17 = &v13[10 * (a2 & 3)];
      v18 = 1426;
      v19 = v17 + 60;
      v20 = (unsigned int *)v17 + 133;
      goto LABEL_6;
    }
LABEL_10:
    __break(0x5512u);
  }
  if ( (unsigned int)v14 > 4 )
    goto LABEL_10;
  v19 = v13 + 10;
  v20 = (unsigned int *)v13 + 33;
  v18 = 1546;
  v16 = *a1;
LABEL_6:
  v21 = *v20;
  v22 = (__int64)&v13[15 * v16 + v18];
  qdf_trace_msg(
    0x45u,
    8u,
    "%s: Mon RX Desc Pool[%d] entries=%u",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "dp_rx_pdev_mon_buf_buffers_alloc",
    v14,
    *v20);
  if ( (a3 & 1) != 0 )
  {
    result = dp_pdev_rx_buffers_attach(v13, a2, v19, v22, *(_DWORD *)(v15 + 716));
  }
  else
  {
    v25[0] = 0;
    v24 = nullptr;
    result = _dp_rx_buffers_replenish((__int64)v13, a2, v19, v22, v21, &v24, (__int64)v25, 0, 0);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
