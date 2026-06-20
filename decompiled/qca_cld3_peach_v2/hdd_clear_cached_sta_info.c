__int64 __fastcall hdd_clear_cached_sta_info(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned __int64 StatusReg; // x8
  __int64 result; // x0
  __int64 v12; // x8
  char v13; // w24
  _QWORD *v14; // x20
  unsigned int v21; // w10
  unsigned int v24; // w9
  __int64 v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned __int64 v34; // x25
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x8
  unsigned int v46; // w9
  unsigned int v49; // w9
  unsigned int v52; // w9
  unsigned int v55; // w9
  _QWORD *v56; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v57[2]; // [xsp+10h] [xbp-10h] BYREF

  v57[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 38912);
    }
    else
    {
      raw_spin_lock_bh(a1 + 38912);
      *(_QWORD *)(a1 + 38920) |= 1uLL;
    }
    v56 = nullptr;
    v57[0] = 0;
    if ( (unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 38888), v57) )
      goto LABEL_21;
    v12 = v57[0];
    v56 = (_QWORD *)v57[0];
    if ( !v57[0] )
      goto LABEL_21;
    _X9 = (unsigned int *)(v57[0] + 280LL);
    __asm { PRFM            #0x11, [X9] }
    do
      v21 = __ldxr(_X9);
    while ( __stxr(v21 + 1, _X9) );
    _X8 = (unsigned int *)(v12 + 392);
    __asm { PRFM            #0x11, [X8] }
    do
      v24 = __ldxr(_X8);
    while ( __stxr(v24 + 1, _X8) );
    if ( v56 )
    {
      v57[0] = 0;
      if ( !(unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 38888), v56, v57) )
      {
        v14 = (_QWORD *)v57[0];
        if ( v57[0] )
        {
          _X8 = (unsigned int *)(v57[0] + 280LL);
          __asm { PRFM            #0x11, [X8] }
          do
            v52 = __ldxr(_X8);
          while ( __stxr(v52 + 1, _X8) );
          _X8 = (unsigned int *)(v14 + 49);
          __asm { PRFM            #0x11, [X8] }
          do
            v55 = __ldxr(_X8);
          while ( __stxr(v55 + 1, _X8) );
        }
        v13 = 0;
        goto LABEL_23;
      }
      v13 = 0;
    }
    else
    {
LABEL_21:
      v13 = 1;
    }
    v14 = nullptr;
LABEL_23:
    v25 = *(_QWORD *)(a1 + 38920);
    if ( (v25 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 38920) = v25 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(a1 + 38912);
      if ( (v13 & 1) != 0 )
        goto LABEL_25;
    }
    else
    {
      result = raw_spin_unlock(a1 + 38912);
      if ( (v13 & 1) != 0 )
        goto LABEL_25;
    }
    v34 = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      hdd_sta_info_detach(a1 + 38888, (__int64 *)&v56, v26, v27, v28, v29, v30, v31, v32, v33);
      hdd_put_sta_info_ref(a1 + 38888, (__int64 *)&v56, 1, 0x1Bu, v35, v36, v37, v38, v39, v40, v41, v42);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v34 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v34 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 38912);
        v56 = v14;
        if ( !v14 )
          goto LABEL_33;
      }
      else
      {
        raw_spin_lock_bh(a1 + 38912);
        *(_QWORD *)(a1 + 38920) |= 1uLL;
        v56 = v14;
        if ( !v14 )
          goto LABEL_33;
      }
      v57[0] = 0;
      if ( !(unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 38888), v14, v57) )
      {
        v14 = (_QWORD *)v57[0];
        if ( v57[0] )
        {
          _X8 = (unsigned int *)(v57[0] + 280LL);
          __asm { PRFM            #0x11, [X8] }
          do
            v46 = __ldxr(_X8);
          while ( __stxr(v46 + 1, _X8) );
          _X8 = (unsigned int *)(v14 + 49);
          __asm { PRFM            #0x11, [X8] }
          do
            v49 = __ldxr(_X8);
          while ( __stxr(v49 + 1, _X8) );
        }
        goto LABEL_34;
      }
LABEL_33:
      v14 = nullptr;
LABEL_34:
      v43 = *(_QWORD *)(a1 + 38920);
      if ( (v43 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 38920) = v43 & 0xFFFFFFFFFFFFFFFELL;
        result = raw_spin_unlock_bh(a1 + 38912);
        if ( !v56 )
          goto LABEL_25;
      }
      else
      {
        result = raw_spin_unlock(a1 + 38912);
        if ( !v56 )
          goto LABEL_25;
      }
    }
  }
  result = qdf_trace_msg(0x33u, 2u, "%s: Parameter null", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_clear_cached_sta_info");
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
