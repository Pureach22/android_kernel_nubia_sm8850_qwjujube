__int64 __fastcall dp_ds_cfg_astidx_cache_mapping(__int64 result, unsigned __int8 a2)
{
  __int64 v3; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x20
  unsigned int v6; // w9
  unsigned int v13; // w11
  unsigned __int64 v14; // x8
  __int64 v15; // x8
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  unsigned int v28; // w9
  __int64 v29; // x8

  if ( a2 <= 5u )
  {
    v3 = result;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(result + 18984);
    }
    else
    {
      raw_spin_lock_bh(result + 18984);
      *(_QWORD *)(v3 + 18992) |= 1uLL;
    }
    v5 = *(_QWORD *)(v3 + 8LL * a2 + 12960);
    if ( v5 )
    {
      v6 = *(_DWORD *)(v5 + 43384);
      do
      {
        if ( !v6 )
          goto LABEL_24;
        _X13 = (unsigned int *)(v5 + 43384);
        __asm { PRFM            #0x11, [X13] }
        while ( 1 )
        {
          v13 = __ldxr(_X13);
          if ( v13 != v6 )
            break;
          if ( !__stlxr(v6 + 1, _X13) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v13 == v6;
        v6 = v13;
      }
      while ( !_ZF );
      _X8 = (unsigned int *)(v5 + 43416);
      __asm { PRFM            #0x11, [X8] }
      do
        v28 = __ldxr(_X8);
      while ( __stxr(v28 + 1, _X8) );
      v29 = *(_QWORD *)(v3 + 18992);
      if ( (v29 & 1) != 0 )
      {
        *(_QWORD *)(v3 + 18992) = v29 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v3 + 18984);
      }
      else
      {
        raw_spin_unlock(v3 + 18984);
      }
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v14 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v14 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v14 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v3 + 13304);
        v15 = *(_QWORD *)(v3 + 13312);
        if ( (v15 & 1) == 0 )
        {
LABEL_22:
          raw_spin_unlock(v3 + 13304);
          return dp_vdev_unref_delete(v3, v5, 7u, v16, v17, v18, v19, v20, v21, v22, v23, v24);
        }
      }
      else
      {
        raw_spin_lock_bh(v3 + 13304);
        v15 = *(_QWORD *)(v3 + 13312) | 1LL;
        *(_QWORD *)(v3 + 13312) = v15;
        if ( (v15 & 1) == 0 )
          goto LABEL_22;
      }
      *(_QWORD *)(v3 + 13312) = v15 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v3 + 13304);
      return dp_vdev_unref_delete(v3, v5, 7u, v16, v17, v18, v19, v20, v21, v22, v23, v24);
    }
LABEL_24:
    v25 = *(_QWORD *)(v3 + 18992);
    if ( (v25 & 1) != 0 )
    {
      *(_QWORD *)(v3 + 18992) = v25 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(v3 + 18984);
    }
    else
    {
      return raw_spin_unlock(v3 + 18984);
    }
  }
  return result;
}
