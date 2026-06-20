__int64 __fastcall hdd_adapter_restore_link_vdev_map(__int64 a1, char a2)
{
  char v2; // w19
  __int64 v3; // x13
  __int64 v4; // x12
  __int64 v5; // x24
  __int64 v6; // x25
  __int64 v7; // x22
  __int64 v8; // x9
  __int64 v9; // x8
  unsigned int v10; // w20
  __int64 v11; // x27
  unsigned int v12; // w8
  __int64 v13; // x9
  __int64 v14; // x8
  int v15; // w10
  __int64 v16; // x28
  __int64 v17; // x21
  __int64 v18; // x8
  __int64 v19; // x23
  char v20; // w26
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 v23; // x8
  __int64 v24; // x8
  __int64 v25; // x8
  __int16 v26; // w11
  __int64 v29; // [xsp+8h] [xbp-28h]
  unsigned __int64 StatusReg; // [xsp+10h] [xbp-20h]
  int v32; // [xsp+20h] [xbp-10h]
  __int16 v33; // [xsp+24h] [xbp-Ch]

  v2 = 0;
  _ReadStatusReg(SP_EL0);
  if ( a1 )
  {
    v3 = a1 + 52840;
    if ( a1 != -52840 )
    {
      v4 = 0;
      v2 = 0;
      v5 = a1 + 1632;
      v6 = a1 + 1633;
      v7 = a1 + 52840;
      v29 = a1 + 52840;
      StatusReg = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        if ( (unsigned __int64)(0x71B3F945A27B1F49LL * ((v7 - v3) >> 3)) > 2 )
          goto LABEL_43;
        v9 = 0x71B3F945A27B1F49LL * ((v7 - *(_QWORD *)v7 - 52840) >> 3);
        v10 = (unsigned __int8)(73 * ((v7 - *(_QWORD *)v7 - 52840) >> 3));
        if ( v10 > 2 )
          __break(0x5512u);
        v11 = v9 & 3;
        if ( *(unsigned __int8 *)(v5 + v11) != v10 )
          break;
LABEL_7:
        v7 += 6088;
        if ( !v7 )
          goto LABEL_43;
      }
      v12 = v9 & 3;
      if ( v12 <= 2 )
        v13 = 2;
      else
        v13 = v12;
      v14 = v11;
      while ( v13 != v14 )
      {
        v15 = *(unsigned __int8 *)(v6 + v14++);
        if ( v15 == v10 )
        {
          v4 = (unsigned __int8)v14;
          goto LABEL_19;
        }
      }
      if ( (_DWORD)v14 == 2 )
        goto LABEL_7;
LABEL_19:
      v16 = v3 + 6088 * v4;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v17 = v4;
        raw_spin_lock(v16 + 16);
        v18 = *(_QWORD *)(v16 + 24);
      }
      else
      {
        v17 = v4;
        raw_spin_lock_bh(v16 + 16);
        v18 = *(_QWORD *)(v16 + 24) | 1LL;
        *(_QWORD *)(v16 + 24) = v18;
      }
      v19 = *(_QWORD *)(v16 + 32);
      v20 = *(_BYTE *)(v16 + 8);
      *(_QWORD *)(v16 + 32) = *(_QWORD *)(v7 + 32);
      *(_BYTE *)(v16 + 8) = *(_BYTE *)(v7 + 8);
      if ( (v18 & 1) != 0 )
      {
        *(_QWORD *)(v16 + 24) = v18 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v16 + 16);
        v21 = *(_QWORD *)(v16 + 32);
        if ( v21 )
        {
LABEL_25:
          v22 = *(_QWORD *)(v21 + 680);
          if ( v22 )
            *(_QWORD *)(v22 + 8) = v16;
        }
      }
      else
      {
        raw_spin_unlock(v16 + 16);
        v21 = *(_QWORD *)(v16 + 32);
        if ( v21 )
          goto LABEL_25;
      }
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v7 + 16);
        v23 = *(_QWORD *)(v7 + 24);
      }
      else
      {
        raw_spin_lock_bh(v7 + 16);
        v23 = *(_QWORD *)(v7 + 24) | 1LL;
        *(_QWORD *)(v7 + 24) = v23;
      }
      *(_QWORD *)(v7 + 32) = v19;
      *(_BYTE *)(v7 + 8) = v20;
      if ( (v23 & 1) != 0 )
      {
        *(_QWORD *)(v7 + 24) = v23 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v7 + 16);
      }
      else
      {
        raw_spin_unlock(v7 + 16);
      }
      v3 = v29;
      v24 = *(_QWORD *)(v7 + 32);
      v4 = v17;
      if ( v24 )
      {
        v25 = *(_QWORD *)(v24 + 680);
        if ( v25 )
          *(_QWORD *)(v25 + 8) = v7;
      }
      if ( (a2 & 1) != 0 )
      {
        v26 = *(_WORD *)(v7 + 76);
        v32 = *(_DWORD *)(v16 + 72);
        v33 = *(_WORD *)(v16 + 76);
        *(_DWORD *)(v16 + 72) = *(_DWORD *)(v7 + 72);
        *(_WORD *)(v16 + 76) = v26;
        *(_DWORD *)(v7 + 72) = v32;
        *(_WORD *)(v7 + 76) = v33;
      }
      v8 = *(_QWORD *)(v16 + 5968);
      if ( (v2 & 1) == 0 )
        v2 = 1;
      *(_QWORD *)(v16 + 5968) = *(_QWORD *)(v7 + 5968);
      *(_QWORD *)(v7 + 5968) = v8;
      *(_BYTE *)(v5 + v17) = *(_BYTE *)(v5 + v11);
      *(_BYTE *)(v5 + v11) = v10;
      goto LABEL_7;
    }
  }
LABEL_43:
  hdd_adapter_disable_all_links(a1, (a2 & 1) == 0);
  _ReadStatusReg(SP_EL0);
  return v2 & 1;
}
