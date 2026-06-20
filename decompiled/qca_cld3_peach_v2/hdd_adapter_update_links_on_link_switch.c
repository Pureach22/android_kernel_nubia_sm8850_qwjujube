__int64 __fastcall hdd_adapter_update_links_on_link_switch(_QWORD *a1, _QWORD *a2)
{
  _QWORD *v2; // x19
  _QWORD *v3; // x20
  __int64 v4; // x22
  __int64 v5; // x21
  __int64 v6; // x8
  __int64 v8; // x9
  __int64 v9; // x10
  char v10; // w12
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x8
  __int64 v13; // x23
  unsigned __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x9
  unsigned __int64 v20; // x10
  unsigned __int64 v26; // x10

  v5 = *a1;
  v6 = 0x71B3F945A27B1F49LL * (((__int64)a2 - *a2 - 52840) >> 3);
  if ( (unsigned __int8)(73 * (((__int64)a1 - *a1 - 52840) >> 3)) > 2u
    || (unsigned __int8)(73 * (((__int64)a2 - *a2 - 52840) >> 3)) >= 3u )
  {
    __break(0x5512u);
  }
  else
  {
    v8 = (0x71B3F945A27B1F49LL * (((__int64)a1 - *a1 - 52840) >> 3)) & 3;
    v4 = v6 & 3;
    v9 = v5 + 1632;
    v6 = 1LL << v8;
    v2 = a2;
    v3 = a1;
    v10 = *(_BYTE *)(v5 + 1632 + v4);
    *(_BYTE *)(v9 + v4) = *(_BYTE *)(v5 + 1632 + v8);
    *(_BYTE *)(v9 + v8) = v10;
  }
  _X9 = (unsigned __int64 *)(v5 + 1640);
  __asm { PRFM            #0x11, [X9] }
  do
    v20 = __ldxr(_X9);
  while ( __stxr(v20 & ~v6, _X9) );
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v3 + 2);
    v12 = v3[3];
  }
  else
  {
    raw_spin_lock_bh(v3 + 2);
    v12 = v3[3] | 1LL;
    v3[3] = v12;
  }
  v13 = v3[4];
  v3[4] = 0;
  *((_BYTE *)v3 + 8) = -1;
  if ( (v12 & 1) != 0 )
  {
    v3[3] = v12 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v3 + 2);
    if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
      goto LABEL_11;
LABEL_13:
    raw_spin_lock(v2 + 2);
    v15 = v2[3];
    goto LABEL_14;
  }
  raw_spin_unlock(v3 + 2);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
    goto LABEL_13;
LABEL_11:
  v14 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v14 + 16) & 0xF0000) != 0 || (*(_DWORD *)(v14 + 16) & 0xFF00) != 0 )
    goto LABEL_13;
  raw_spin_lock_bh(v2 + 2);
  v15 = v2[3] | 1LL;
  v2[3] = v15;
LABEL_14:
  v2[4] = v13;
  *((_BYTE *)v2 + 8) = *(_BYTE *)(v13 + 168);
  if ( (v15 & 1) != 0 )
  {
    v2[3] = v15 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v2 + 2);
  }
  else
  {
    raw_spin_unlock(v2 + 2);
  }
  _X9 = (unsigned __int64 *)(v5 + 1640);
  __asm { PRFM            #0x11, [X9] }
  do
    v26 = __ldxr(_X9);
  while ( __stxr(v26 | (1LL << v4), _X9) );
  v16 = v2[746];
  v2[746] = v3[746];
  v3[746] = v16;
  *(_QWORD *)(*(_QWORD *)(v2[4] + 680LL) + 8LL) = v2;
  return 0;
}
