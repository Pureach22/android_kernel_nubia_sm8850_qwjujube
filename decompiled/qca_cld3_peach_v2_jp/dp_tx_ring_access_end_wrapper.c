__int64 __fastcall dp_tx_ring_access_end_wrapper(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x22
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  unsigned int v32; // w9
  __int64 v33; // x8
  unsigned __int64 v36; // x9
  unsigned int v38; // w9
  unsigned int v41; // w10
  unsigned __int64 v44; // x9

  v3 = a1 + 0x4000;
  if ( *(_DWORD *)(a1 + 20068) && (int)hif_rtpm_get_state() <= 1 )
    return dp_tx_ring_access_end(a1, a2, a3, v7, v8, v9, v10, v11, v12, v13, v14);
  if ( (unsigned int)hif_rtpm_get(0, 4u) )
  {
    _X8 = (unsigned int *)(a1 + 19928);
    __asm { PRFM            #0x11, [X8] }
    do
      v32 = __ldxr(_X8);
    while ( __stlxr(v32 + 1, _X8) );
    __dmb(0xBu);
    v33 = *(_QWORD *)(a2 + 88);
    if ( (v33 & 1) != 0 )
    {
      *(_QWORD *)(a2 + 88) = v33 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(a2 + 80);
    }
    else
    {
      result = raw_spin_unlock(a2 + 80);
    }
    _X8 = (unsigned __int64 *)(a2 + 176);
    __asm { PRFM            #0x11, [X8] }
    do
      v36 = __ldxr(_X8);
    while ( __stxr(v36 | 2, _X8) );
    _X8 = (unsigned int *)(v3 + 3548);
    __asm { PRFM            #0x11, [X8] }
    do
      v38 = __ldxr(_X8);
    while ( __stxr(v38 + 1, _X8) );
    ++*(_DWORD *)(a2 + 168);
    _X8 = (unsigned int *)(a1 + 19928);
    __asm { PRFM            #0x11, [X8] }
    do
      v41 = __ldxr(_X8);
    while ( __stlxr(v41 - 1, _X8) );
    __dmb(0xBu);
  }
  else
  {
    if ( (unsigned int)hif_system_pm_state_check(*(_QWORD *)(a1 + 64)) )
    {
      v25 = *(_QWORD *)(a2 + 88);
      if ( (v25 & 1) != 0 )
      {
        *(_QWORD *)(a2 + 88) = v25 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a2 + 80);
      }
      else
      {
        raw_spin_unlock(a2 + 80);
      }
      _X8 = (unsigned __int64 *)(a2 + 176);
      __asm { PRFM            #0x11, [X8] }
      do
        v44 = __ldxr(_X8);
      while ( __stxr(v44 | 2, _X8) );
      ++*(_DWORD *)(a2 + 168);
    }
    else
    {
      dp_tx_ring_access_end(a1, a2, a3, v17, v18, v19, v20, v21, v22, v23, v24);
    }
    return hif_rtpm_put(4, 4u);
  }
  return result;
}
