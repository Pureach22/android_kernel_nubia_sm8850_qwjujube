__int64 __fastcall dp_wds_reset_ast_wifi3(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 a4)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v10; // x20
  unsigned int v11; // w9
  unsigned int v18; // w11
  unsigned int *v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x0
  unsigned int *v29; // x8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x21
  unsigned __int64 v39; // x8
  __int64 v40; // x1
  __int64 v41; // x8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x8
  int v51; // w8
  __int64 v52; // x23
  unsigned int v55; // w9
  __int64 v56; // x8
  unsigned __int8 *v57; // x23
  unsigned __int64 v58; // x8
  __int64 v59; // x0
  int v60; // w8
  __int64 v61; // x8

  result = 16;
  if ( a4 <= 5u && (*(_BYTE *)(a1 + 17706) & 1) == 0 )
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
    v10 = *(_QWORD *)(a1 + 8LL * a4 + 12960);
    if ( v10 )
    {
      v11 = *(_DWORD *)(v10 + 43384);
      do
      {
        if ( !v11 )
          goto LABEL_27;
        _X13 = (unsigned int *)(v10 + 43384);
        __asm { PRFM            #0x11, [X13] }
        while ( 1 )
        {
          v18 = __ldxr(_X13);
          if ( v18 != v11 )
            break;
          if ( !__stlxr(v11 + 1, _X13) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v18 == v11;
        v11 = v18;
      }
      while ( !_ZF );
      _X8 = (unsigned int *)(v10 + 43416);
      __asm { PRFM            #0x11, [X8] }
      do
        v55 = __ldxr(_X8);
      while ( __stxr(v55 + 1, _X8) );
      v56 = *(_QWORD *)(a1 + 18992);
      if ( (v56 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 18992) = v56 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 18984);
        if ( !a3 )
        {
LABEL_44:
          if ( a2 )
          {
            v57 = *(unsigned __int8 **)(v10 + 24);
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (v58 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v58 + 16) & 0xF0000) != 0)
              || (*(_DWORD *)(v58 + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(a1 + 17632);
            }
            else
            {
              raw_spin_lock_bh(a1 + 17632);
              *(_QWORD *)(a1 + 17640) |= 1uLL;
            }
            v59 = dp_peer_ast_hash_find_by_pdevid(a1, a2, *v57);
            if ( v59 )
            {
              v60 = *(_DWORD *)(v59 + 24);
              if ( v60 == 7 || v60 == 4 )
                dp_peer_del_ast(a1);
            }
            v61 = *(_QWORD *)(a1 + 17640);
            if ( (v61 & 1) != 0 )
            {
              *(_QWORD *)(a1 + 17640) = v61 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(a1 + 17632);
            }
            else
            {
              raw_spin_unlock(a1 + 17632);
            }
          }
          goto LABEL_55;
        }
      }
      else
      {
        raw_spin_unlock(a1 + 18984);
        if ( !a3 )
          goto LABEL_44;
      }
      v28 = dp_peer_find_hash_find(a1, a3);
      if ( !v28 )
      {
        dp_vdev_unref_delete(a1, v10, 7u, v29, v30, v31, v32, v33, v34, v35, v36, v37);
        return 16;
      }
      v38 = v28;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v39 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v39 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v39 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 17632);
        v40 = *(_QWORD *)(v38 + 216);
        if ( !v40 )
        {
LABEL_24:
          v41 = *(_QWORD *)(a1 + 17640);
          if ( (v41 & 1) != 0 )
          {
            *(_QWORD *)(a1 + 17640) = v41 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 17632);
          }
          else
          {
            raw_spin_unlock(a1 + 17632);
          }
          dp_peer_unref_delete(v38, 7u, v42, v43, v44, v45, v46, v47, v48, v49);
LABEL_55:
          dp_vdev_unref_delete(a1, v10, 7u, v19, v20, v21, v22, v23, v24, v25, v26, v27);
          return 0;
        }
      }
      else
      {
        raw_spin_lock_bh(a1 + 17632);
        *(_QWORD *)(a1 + 17640) |= 1uLL;
        v40 = *(_QWORD *)(v38 + 216);
        if ( !v40 )
          goto LABEL_24;
      }
      do
      {
        v51 = *(_DWORD *)(v40 + 24);
        v52 = *(_QWORD *)(v40 + 48);
        if ( v51 == 7 || v51 == 4 )
          dp_peer_del_ast(a1);
        v40 = v52;
      }
      while ( v52 );
      goto LABEL_24;
    }
LABEL_27:
    v50 = *(_QWORD *)(a1 + 18992);
    if ( (v50 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18992) = v50 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18984);
    }
    else
    {
      raw_spin_unlock(a1 + 18984);
    }
    return 16;
  }
  return result;
}
