__int64 __fastcall dp_reo_cmdlist_destroy(_QWORD *a1)
{
  unsigned __int64 StatusReg; // x8
  _QWORD *v3; // x20
  _QWORD *v4; // x8
  _QWORD *v5; // x23
  _QWORD *v6; // x9
  __int64 v7; // x1
  _DWORD *v8; // x8
  __int64 v9; // x8
  __int64 result; // x0
  _QWORD v11[13]; // [xsp+8h] [xbp-78h] BYREF
  int v12; // [xsp+70h] [xbp-10h]
  __int64 v13; // [xsp+78h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  memset(&v11[1], 0, 96);
  v11[0] = 0xFF00000000LL;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 1653);
    v3 = (_QWORD *)a1[1651];
    if ( !v3 )
      goto LABEL_10;
  }
  else
  {
    raw_spin_lock_bh(a1 + 1653);
    a1[1654] |= 1uLL;
    v3 = (_QWORD *)a1[1651];
    if ( !v3 )
      goto LABEL_10;
  }
  do
  {
    v5 = (_QWORD *)v3[3];
    v4 = (_QWORD *)v3[4];
    v6 = v5 + 4;
    if ( !v5 )
      v6 = a1 + 1652;
    *v6 = v4;
    *v4 = v3[3];
    v7 = v3[1];
    v8 = (_DWORD *)v3[2];
    v3[3] = 0;
    v3[4] = 0;
    if ( *(v8 - 1) != -1114182658 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, __int64, _QWORD *))v8)(a1, v7, v11);
    _qdf_mem_free((__int64)v3);
    v3 = v5;
  }
  while ( v5 );
LABEL_10:
  v9 = a1[1654];
  if ( (v9 & 1) != 0 )
  {
    a1[1654] = v9 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(a1 + 1653);
  }
  else
  {
    result = raw_spin_unlock(a1 + 1653);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
