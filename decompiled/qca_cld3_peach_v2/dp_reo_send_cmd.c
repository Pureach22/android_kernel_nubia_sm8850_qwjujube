__int64 __fastcall dp_reo_send_cmd(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        __int64 a11,
        __int64 a12,
        __int64 a13)
{
  __int64 v14; // x0
  __int64 v15; // x9
  __int64 (*v16)(void); // x9
  __int64 v20; // x21
  int v21; // w0
  __int64 v22; // x9
  __int16 v23; // w24
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x20
  unsigned __int64 StatusReg; // x8
  __int64 *v35; // x8
  __int64 v36; // x8
  unsigned int v44; // w10
  unsigned int v45; // w10

  v14 = *(_QWORD *)(a1 + 1128);
  if ( !v14 || (v15 = *(_QWORD *)(v14 + 74392)) == 0 )
  {
    qdf_trace_msg(0x46u, 2u, "%s: hal handle is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "hal_reo_send_cmd");
    return 4;
  }
  v16 = *(__int64 (**)(void))(v15 + 1648);
  if ( !v16 )
    return 4;
  v20 = a1;
  if ( *((_DWORD *)v16 - 1) != 1330011301 )
    __break(0x8229u);
  v21 = v16();
  if ( v21 < 0 )
    return 4;
  _X11 = (unsigned int *)(v20 + 16528);
  __asm { PRFM            #0x11, [X11] }
  do
  {
    v44 = __ldxr(_X11);
    v45 = v44 + 1;
  }
  while ( __stlxr(v45, _X11) );
  __dmb(0xBu);
  v22 = v20 + 16LL * (v45 & 0x3F);
  *(_DWORD *)(v22 + 16536) = a2;
  *(_BYTE *)(v22 + 16540) = v21;
  __isb(0xFu);
  *(_QWORD *)(v22 + 16544) = _ReadStatusReg(CNTVCT_EL0);
  if ( !a12 )
    return 0;
  v23 = v21;
  v24 = _qdf_mem_malloc(0x28u, "dp_reo_send_cmd", 107);
  if ( v24 )
  {
    v33 = v24;
    *(_DWORD *)(v24 + 4) = a2;
    *(_WORD *)v24 = v23;
    *(_QWORD *)(v24 + 8) = a13;
    *(_QWORD *)(v24 + 16) = a12;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v20 + 13224);
    }
    else
    {
      raw_spin_lock_bh(v20 + 13224);
      *(_QWORD *)(v20 + 13232) |= 1uLL;
    }
    *(_QWORD *)(v33 + 24) = 0;
    v35 = *(__int64 **)(v20 + 13216);
    *(_QWORD *)(v33 + 32) = v35;
    *v35 = v33;
    v36 = *(_QWORD *)(v20 + 13232);
    *(_QWORD *)(v20 + 13216) = v33 + 24;
    if ( (v36 & 1) != 0 )
    {
      *(_QWORD *)(v20 + 13232) = v36 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v20 + 13224);
    }
    else
    {
      raw_spin_unlock(v20 + 13224);
    }
    return 0;
  }
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: alloc failed for REO cmd:%d!!",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "dp_reo_send_cmd",
    a2);
  return 2;
}
