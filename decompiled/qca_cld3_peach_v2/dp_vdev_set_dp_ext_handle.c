__int64 __fastcall dp_vdev_set_dp_ext_handle(__int64 a1, unsigned __int8 a2, unsigned __int16 a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x21
  unsigned int v8; // w8
  unsigned int v15; // w10
  __int64 v16; // x0
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v27; // x8
  unsigned int v30; // w9
  __int64 v31; // x8

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
    v7 = *(_QWORD *)(a1 + 8LL * a2 + 12960);
    if ( v7 )
    {
      v8 = *(_DWORD *)(v7 + 43384);
      while ( v8 )
      {
        _X12 = (unsigned int *)(v7 + 43384);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v15 = __ldxr(_X12);
          if ( v15 != v8 )
            break;
          if ( !__stlxr(v8 + 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v15 == v8;
        v8 = v15;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v7 + 43416);
          __asm { PRFM            #0x11, [X8] }
          do
            v30 = __ldxr(_X8);
          while ( __stxr(v30 + 1, _X8) );
          v31 = *(_QWORD *)(a1 + 18992);
          if ( (v31 & 1) != 0 )
          {
            *(_QWORD *)(a1 + 18992) = v31 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 18984);
          }
          else
          {
            raw_spin_unlock(a1 + 18984);
          }
          v16 = _qdf_mem_malloc(a3, "dp_vdev_set_dp_ext_handle", 12381);
          if ( v16 )
          {
            *(_QWORD *)(v7 + 43328) = v16;
            dp_vdev_unref_delete(a1, v7, 7u, v17, v18, v19, v20, v21, v22, v23, v24, v25);
            return 0;
          }
          dp_vdev_unref_delete(a1, v7, 7u, v17, v18, v19, v20, v21, v22, v23, v24, v25);
          return 16;
        }
      }
    }
    v27 = *(_QWORD *)(a1 + 18992);
    if ( (v27 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18992) = v27 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18984);
    }
    else
    {
      raw_spin_unlock(a1 + 18984);
    }
  }
  return 16;
}
