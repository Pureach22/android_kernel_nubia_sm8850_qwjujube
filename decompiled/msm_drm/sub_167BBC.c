// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_167BBC(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v4; // w8
  __int64 v5; // x8
  __int64 v6; // x10
  __int64 v7; // x11
  __int64 v8; // x12
  __int64 v9; // x16
  __int64 v10; // x19
  __int64 v11; // x21

  if ( (v9 & 0x1000000000000LL) != 0 )
    return sde_edid_init();
  sde_reg_write(a1, a2, a3, a4);
  v4 = *(_DWORD *)(v10 + 64);
  if ( v4 > 4 )
  {
    __break(0x5512u);
    __break(1u);
    JUMPOUT(0x167064);
  }
  v5 = v11 + 144LL * v4;
  v6 = *(_QWORD *)(v5 + 116);
  v7 = *(_QWORD *)(v5 + 124);
  v8 = *(_QWORD *)(v5 + 132);
  *(_QWORD *)(v5 + 116) = -1;
  *(_QWORD *)(v5 + 124) = -1;
  *(_QWORD *)(v5 + 92) = v6;
  *(_QWORD *)(v5 + 100) = v7;
  *(_QWORD *)(v5 + 108) = v8;
  *(_QWORD *)(v5 + 132) = -1;
  return 0;
}
