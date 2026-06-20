__int64 __fastcall dp_get_peer_mac_list(__int64 a1, unsigned __int8 a2, __int64 a3, unsigned __int16 a4, char a5)
{
  unsigned __int64 StatusReg; // x8
  __int64 v11; // x21
  unsigned int v12; // w24
  unsigned int v13; // w8
  unsigned int v20; // w10
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int *v29; // x8
  unsigned int v30; // w22
  __int64 v31; // x8
  unsigned int v34; // w9
  __int64 v35; // x8
  unsigned __int64 v36; // x8
  __int64 v37; // x23
  __int64 v38; // x8
  unsigned int *v39; // x8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7

  if ( a2 <= 5u )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 18984);
    }
    else
    {
      raw_spin_lock_bh(a1 + 18984);
      *(_QWORD *)(a1 + 18992) |= 1uLL;
    }
    v11 = *(_QWORD *)(a1 + 8LL * a2 + 12960);
    if ( v11 )
    {
      v12 = a4;
      v13 = *(_DWORD *)(v11 + 43384);
      do
      {
        if ( !v13 )
          goto LABEL_20;
        _X12 = (unsigned int *)(v11 + 43384);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v20 = __ldxr(_X12);
          if ( v20 != v13 )
            break;
          if ( !__stlxr(v13 + 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v20 == v13;
        v13 = v20;
      }
      while ( !_ZF );
      _X8 = (unsigned int *)(v11 + 43416);
      __asm { PRFM            #0x11, [X8] }
      do
        v34 = __ldxr(_X8);
      while ( __stxr(v34 + 1, _X8) );
      v35 = *(_QWORD *)(a1 + 18992);
      if ( (v35 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 18992) = v35 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 18984);
        if ( (a5 & 1) == 0 )
          goto LABEL_28;
      }
      else
      {
        raw_spin_unlock(a1 + 18984);
        if ( (a5 & 1) == 0 )
          goto LABEL_28;
      }
      v29 = (unsigned int *)*(unsigned int *)(v11 + 43344);
      if ( (unsigned int)v29 > a4 )
      {
        dp_vdev_unref_delete(a1, v11, 7u, v29, v21, v22, v23, v24, v25, v26, v27, v28);
        return 0;
      }
LABEL_28:
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v36 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v36 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v36 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v11 + 144);
        v37 = *(_QWORD *)(v11 + 128);
        if ( v37 )
          goto LABEL_32;
      }
      else
      {
        raw_spin_lock_bh(v11 + 144);
        *(_QWORD *)(v11 + 152) |= 1uLL;
        v37 = *(_QWORD *)(v11 + 128);
        if ( v37 )
        {
LABEL_32:
          v30 = 0;
          do
          {
            if ( (*(_BYTE *)(v37 + 120) & 1) == 0 && v30 < v12 )
              qdf_mem_copy((void *)(a3 + 6LL * v30++), (const void *)(v37 + 44), 6u);
            v37 = *(_QWORD *)(v37 + 56);
          }
          while ( v37 );
          goto LABEL_39;
        }
      }
      v30 = 0;
LABEL_39:
      v38 = *(_QWORD *)(v11 + 152);
      if ( (v38 & 1) != 0 )
      {
        *(_QWORD *)(v11 + 152) = v38 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v11 + 144);
      }
      else
      {
        raw_spin_unlock(v11 + 144);
      }
      dp_vdev_unref_delete(a1, v11, 7u, v39, v40, v41, v42, v43, v44, v45, v46, v47);
      return v30;
    }
LABEL_20:
    v31 = *(_QWORD *)(a1 + 18992);
    if ( (v31 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18992) = v31 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18984);
      return 0;
    }
    raw_spin_unlock(a1 + 18984);
  }
  return 0;
}
