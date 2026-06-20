__int64 __fastcall dp_soc_iterate_peer(__int64 result, _DWORD *a2)
{
  __int64 v2; // x22
  unsigned __int64 v4; // x8
  _QWORD *v5; // x23
  unsigned __int64 StatusReg; // x24
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x20
  __int64 v10; // x26
  __int64 v11; // x21
  unsigned int v12; // w8
  unsigned int v19; // w10
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v30; // w9
  __int64 v31; // x8

  if ( result )
  {
    v2 = *(_QWORD *)(result + 72);
    if ( v2 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v4 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v4 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v4 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v2 + 312);
        v5 = *(_QWORD **)(v2 + 296);
        if ( v5 )
        {
LABEL_7:
          StatusReg = _ReadStatusReg(SP_EL0);
          do
          {
            v8 = v5[3];
            if ( !v8 )
              goto LABEL_10;
            v9 = *(_QWORD *)(v8 + 8);
            if ( !v9 )
              goto LABEL_10;
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
              || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(v5 + 18);
              v10 = v5[16];
              if ( v10 )
                goto LABEL_17;
            }
            else
            {
              raw_spin_lock_bh(v5 + 18);
              v5[19] |= 1uLL;
              v10 = v5[16];
              while ( v10 )
              {
LABEL_17:
                v11 = v10;
                v10 = *(_QWORD *)(v10 + 56);
                v12 = *(_DWORD *)(v11 + 40);
                while ( v12 )
                {
                  _X12 = (unsigned int *)(v11 + 40);
                  __asm { PRFM            #0x11, [X12] }
                  while ( 1 )
                  {
                    v19 = __ldxr(_X12);
                    if ( v19 != v12 )
                      break;
                    if ( !__stlxr(v12 + 1, _X12) )
                    {
                      __dmb(0xBu);
                      break;
                    }
                  }
                  _ZF = v19 == v12;
                  v12 = v19;
                  if ( _ZF )
                  {
                    _X8 = (unsigned int *)(v11 + 292);
                    __asm { PRFM            #0x11, [X8] }
                    do
                      v30 = __ldxr(_X8);
                    while ( __stxr(v30 + 1, _X8) );
                    if ( *(a2 - 1) != 1081739458 )
                      __break(0x8233u);
                    v21 = ((double (__fastcall *)(__int64, __int64, _QWORD))a2)(v9, v11, 0);
                    dp_peer_unref_delete(v11, 7u, v21, v22, v23, v24, v25, v26, v27, v28);
                    break;
                  }
                }
              }
            }
            v7 = v5[19];
            if ( (v7 & 1) != 0 )
            {
              v5[19] = v7 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(v5 + 18);
            }
            else
            {
              raw_spin_unlock(v5 + 18);
            }
LABEL_10:
            v5 = (_QWORD *)v5[14];
          }
          while ( v5 );
        }
      }
      else
      {
        raw_spin_lock_bh(v2 + 312);
        *(_QWORD *)(v2 + 320) |= 1uLL;
        v5 = *(_QWORD **)(v2 + 296);
        if ( v5 )
          goto LABEL_7;
      }
      v31 = *(_QWORD *)(v2 + 320);
      if ( (v31 & 1) != 0 )
      {
        *(_QWORD *)(v2 + 320) = v31 & 0xFFFFFFFFFFFFFFFELL;
        return raw_spin_unlock_bh(v2 + 312);
      }
      else
      {
        return raw_spin_unlock(v2 + 312);
      }
    }
  }
  return result;
}
