__int64 __fastcall dp_rx_desc_nbuf_sanity_check(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x9
  _DWORD *v5; // x9
  __int64 v6; // x8
  __int64 v7; // x10
  __int64 v8; // x9
  _QWORD v10[3]; // [xsp+8h] [xbp-18h] BYREF

  v10[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 1128);
  v10[0] = 0;
  v10[1] = 0;
  v5 = *(_DWORD **)(*(_QWORD *)(v4 + 74392) + 1464LL);
  if ( v5 )
  {
    if ( *(v5 - 1) != 1721787685 )
      __break(0x8229u);
    ((void (__fastcall *)(__int64, _QWORD *))v5)(a2, v10);
    v6 = v10[0];
  }
  else
  {
    v6 = 0;
  }
  v7 = 80;
  if ( (*(_BYTE *)(*(_QWORD *)a3 + 68LL) & 4) == 0 )
    v7 = 40;
  v8 = *(_QWORD *)(*(_QWORD *)a3 + v7);
  _ReadStatusReg(SP_EL0);
  return 16 * (unsigned int)(v8 != v6);
}
