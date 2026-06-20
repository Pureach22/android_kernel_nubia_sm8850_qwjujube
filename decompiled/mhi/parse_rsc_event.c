__int64 __fastcall parse_rsc_event(unsigned int *a1, __int64 a2)
{
  unsigned __int64 v3; // x8
  unsigned int v4; // w9
  unsigned __int64 v5; // x20
  int v6; // w10
  __int64 v7; // x8
  int v8; // w9
  __int64 v9; // x8
  __int64 v10; // x0
  _DWORD *v11; // x8
  unsigned __int64 v12; // x8
  __int64 result; // x0
  _QWORD v14[2]; // [xsp+0h] [xbp-20h] BYREF
  int v15; // [xsp+10h] [xbp-10h]
  int v16; // [xsp+14h] [xbp-Ch]
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  v4 = a1[2];
  if ( v3 >= *(_QWORD *)(a2 + 72) )
    __break(0x800u);
  v5 = *(_QWORD *)(a2 + 40) + v3;
  if ( HIBYTE(v4) == 3 )
    v6 = -75;
  else
    v6 = 0;
  v16 = v6;
  if ( (unsigned __int16)v4 >= (unsigned int)*(unsigned __int16 *)(v5 + 40) )
    v7 = *(unsigned __int16 *)(v5 + 40);
  else
    v7 = (unsigned __int16)v4;
  v8 = *(_DWORD *)(a2 + 216);
  v14[1] = v7;
  v9 = *(_QWORD *)(v5 + 24);
  v15 = v8;
  v14[0] = v9;
  raw_read_lock_bh(a2 + 368);
  if ( *(_DWORD *)(a2 + 260) == 1 )
  {
    if ( (*(_BYTE *)(v5 + 52) & 1) == 0 )
      __break(0x800u);
    v10 = *(_QWORD *)(a2 + 272);
    v11 = *(_DWORD **)(a2 + 280);
    if ( *(v11 - 1) != -2026744486 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD *))v11)(v10, v14);
    v12 = *(_QWORD *)(a2 + 144) + *(_QWORD *)(a2 + 160);
    if ( v12 >= *(_QWORD *)(a2 + 136) + *(_QWORD *)(a2 + 168) )
      v12 = *(_QWORD *)(a2 + 136);
    *(_QWORD *)(a2 + 144) = v12;
    __dmb(0xAu);
    *(_BYTE *)(v5 + 52) = 0;
  }
  result = raw_read_unlock_bh(a2 + 368);
  _ReadStatusReg(SP_EL0);
  return result;
}
