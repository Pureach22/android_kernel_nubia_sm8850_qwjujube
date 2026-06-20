__int64 __fastcall dp_mlo_peer_find_hash_find_be(
        __int64 result,
        unsigned __int16 *a2,
        int a3,
        unsigned int a4,
        unsigned __int8 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x19
  unsigned __int16 *v16; // x23
  __int64 v17; // x24
  unsigned __int64 StatusReg; // x8
  __int64 v19; // x21
  unsigned int v21; // w9
  unsigned int v27; // w11
  unsigned int v28; // w8
  unsigned int v29; // w25
  unsigned __int64 v30; // x8
  __int64 v31; // x12
  unsigned int v32; // w9
  unsigned int v35; // w11
  __int64 v36; // x8
  __int64 v38; // x8
  __int64 v39; // x8
  unsigned int v41; // w9
  __int64 v42; // x8
  __int64 v43; // x22
  unsigned int v45; // w8
  __int64 v46; // [xsp+0h] [xbp-10h] BYREF
  __int64 v47; // [xsp+8h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !result )
    goto LABEL_57;
  v13 = result;
  if ( !*(_QWORD *)(result + 23448) )
  {
LABEL_56:
    result = 0;
    goto LABEL_57;
  }
  v16 = a2;
  v46 = 0;
  if ( !a3 )
  {
    qdf_mem_copy(&v46, a2, 6u);
    v16 = (unsigned __int16 *)&v46;
  }
  if ( a5 != 0xFF )
  {
    if ( a5 <= 5u )
    {
      v17 = 18984;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v13 + 18984);
      }
      else
      {
        raw_spin_lock_bh(v13 + 18984);
        *(_QWORD *)(v13 + 18992) |= 1uLL;
      }
      v19 = *(_QWORD *)(v13 + 8LL * a5 + 12960);
      if ( v19 )
      {
        _X8 = v19 + 43384;
        v21 = *(_DWORD *)(v19 + 43384);
        while ( v21 )
        {
          __asm { PRFM            #0x11, [X8] }
          while ( 1 )
          {
            v27 = __ldxr((unsigned int *)_X8);
            if ( v27 != v21 )
              break;
            if ( !__stlxr(v21 + 1, (unsigned int *)_X8) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v27 == v21;
          v21 = v27;
          if ( _ZF )
          {
            if ( a4 >= 0x20 )
LABEL_70:
              __break(0x5512u);
            else
              _X8 = v19 + 4LL * a4 + 43388;
            __asm { PRFM            #0x11, [X8] }
            do
              v41 = __ldxr((unsigned int *)_X8);
            while ( __stxr(v41 + 1, (unsigned int *)_X8) );
            v42 = *(_QWORD *)(v13 + 18992);
            if ( (v42 & 1) != 0 )
            {
              *(_QWORD *)(v13 + 18992) = v42 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(v13 + v17);
            }
            else
            {
              raw_spin_unlock(v13 + v17);
            }
            goto LABEL_25;
          }
        }
      }
      v38 = *(_QWORD *)(v13 + 18992);
      if ( (v38 & 1) != 0 )
      {
        *(_QWORD *)(v13 + 18992) = v38 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v13 + 18984);
      }
      else
      {
        raw_spin_unlock(v13 + 18984);
      }
    }
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: vdev is null",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "dp_mlo_peer_find_hash_find_be",
      v46,
      v47);
    goto LABEL_56;
  }
  v19 = 0;
LABEL_25:
  v17 = 23424;
  v28 = v16[1] ^ *v16 ^ v16[2];
  v29 = ((v28 >> *(_DWORD *)(v13 + 23444)) ^ v28) & *(_DWORD *)(v13 + 23440);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v30 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v30 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v30 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v13 + 23424);
  }
  else
  {
    raw_spin_lock_bh(v13 + 23424);
    *(_QWORD *)(v13 + 23432) |= 1uLL;
  }
  _X8 = *(_QWORD *)(*(_QWORD *)(v13 + 23448) + 16LL * v29);
  if ( !_X8 )
  {
LABEL_46:
    if ( v19 )
      dp_vdev_unref_delete(v13, v19, a4);
    v36 = *(_QWORD *)(v13 + 23432);
    if ( (v36 & 1) != 0 )
    {
      *(_QWORD *)(v13 + 23432) = v36 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v13 + 23424);
    }
    else
    {
      raw_spin_unlock(v13 + 23424);
    }
    goto LABEL_56;
  }
  while ( 1 )
  {
    if ( *(_DWORD *)v16 == *(_DWORD *)(_X8 + 44) && v16[2] == *(unsigned __int16 *)(_X8 + 48) )
    {
      if ( a5 == 0xFF )
        break;
      v31 = *(_QWORD *)(_X8 + 24);
      if ( *(_DWORD *)(v31 + 104) == *(_DWORD *)(v19 + 104)
        && *(unsigned __int16 *)(v31 + 108) == *(unsigned __int16 *)(v19 + 108) )
      {
        break;
      }
    }
    _X8 = *(_QWORD *)(_X8 + 72);
    if ( !_X8 )
      goto LABEL_46;
  }
  v32 = *(_DWORD *)(_X8 + 40);
  do
  {
    if ( !v32 )
    {
      v43 = 0;
      goto LABEL_59;
    }
    _X13 = (unsigned int *)(_X8 + 40);
    __asm { PRFM            #0x11, [X13] }
    while ( 1 )
    {
      v35 = __ldxr(_X13);
      if ( v35 != v32 )
        break;
      if ( !__stlxr(v32 + 1, _X13) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v35 == v32;
    v32 = v35;
  }
  while ( !_ZF );
  if ( a4 < 3 )
  {
    v43 = _X8;
  }
  else
  {
    if ( a4 >= 0x20 )
      goto LABEL_70;
    _X9 = (unsigned int *)(_X8 + 4LL * a4 + 264);
    v43 = _X8;
    __asm { PRFM            #0x11, [X9] }
    do
      v45 = __ldxr(_X9);
    while ( __stxr(v45 + 1, _X9) );
  }
LABEL_59:
  if ( v19 )
    dp_vdev_unref_delete(v13, v19, a4);
  v39 = *(_QWORD *)(v13 + 23432);
  if ( (v39 & 1) != 0 )
  {
    *(_QWORD *)(v13 + 23432) = v39 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v13 + 23424);
  }
  else
  {
    raw_spin_unlock(v13 + 23424);
  }
  result = v43;
LABEL_57:
  _ReadStatusReg(SP_EL0);
  return result;
}
