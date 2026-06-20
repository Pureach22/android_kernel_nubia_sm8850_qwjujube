__int64 __fastcall dp_set_vdev_dscp_tid_map_wifi3(__int64 a1, unsigned __int8 a2, char a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x21
  unsigned int v8; // w9
  unsigned int v15; // w11
  void (__fastcall *v16)(__int64, __int64, __int64, char *); // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int *v25; // x8
  __int64 result; // x0
  __int64 v27; // x8
  unsigned int v30; // w9
  __int64 v31; // x8
  char v32; // [xsp+0h] [xbp-20h] BYREF
  __int64 v33; // [xsp+1h] [xbp-1Fh]
  _BYTE v34[23]; // [xsp+9h] [xbp-17h]

  *(_QWORD *)&v34[15] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 <= 5u )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 18928);
    }
    else
    {
      raw_spin_lock_bh(a1 + 18928);
      *(_QWORD *)(a1 + 18936) |= 1uLL;
    }
    v7 = *(_QWORD *)(a1 + 8LL * a2 + 12912);
    if ( v7 )
    {
      v8 = *(_DWORD *)(v7 + 42560);
      while ( v8 )
      {
        _X13 = (unsigned int *)(v7 + 42560);
        __asm { PRFM            #0x11, [X13] }
        while ( 1 )
        {
          v15 = __ldxr(_X13);
          if ( v15 != v8 )
            break;
          if ( !__stlxr(v8 + 1, _X13) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v15 == v8;
        v8 = v15;
        if ( _ZF )
        {
          _X8 = (unsigned int *)(v7 + 42592);
          __asm { PRFM            #0x11, [X8] }
          do
            v30 = __ldxr(_X8);
          while ( __stxr(v30 + 1, _X8) );
          v31 = *(_QWORD *)(a1 + 18936);
          if ( (v31 & 1) != 0 )
          {
            *(_QWORD *)(a1 + 18936) = v31 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 18928);
          }
          else
          {
            raw_spin_unlock(a1 + 18928);
          }
          *(_BYTE *)(v7 + 72) = a3;
          v16 = *(void (__fastcall **)(__int64, __int64, __int64, char *))(a1 + 1448);
          v32 = a3;
          v33 = 0;
          *(_QWORD *)v34 = 0;
          *(_QWORD *)&v34[7] = 0;
          if ( *((_DWORD *)v16 - 1) != 608967745 )
            __break(0x8228u);
          v16(a1, v7, 22, &v32);
          if ( *(unsigned __int8 *)(v7 + 72) >= (unsigned int)*(unsigned __int8 *)(a1 + 1122) )
            v25 = (unsigned int *)(*(_BYTE *)(v7 + 74) & 0xFE);
          else
            v25 = (unsigned int *)((*(_BYTE *)(v7 + 74) & 0xFEu) + 1);
          *(_BYTE *)(v7 + 74) = (_BYTE)v25;
          dp_vdev_unref_delete(a1, v7, 7u, v25, v17, v18, v19, v20, v21, v22, v23, v24);
          result = 0;
          goto LABEL_27;
        }
      }
    }
    v27 = *(_QWORD *)(a1 + 18936);
    if ( (v27 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 18936) = v27 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 18928);
    }
    else
    {
      raw_spin_unlock(a1 + 18928);
    }
  }
  result = 16;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
