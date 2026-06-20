void __fastcall simple_amp_shutdown(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 v4; // x0
  __int64 v6; // x10
  _QWORD *v7; // x19
  __int64 v8; // x20
  __int64 v9; // x2
  _BYTE v10[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned int *)(a2 + 8);
  if ( (unsigned int)v2 >= 4 )
    __break(0x5512u);
  v3 = *(_QWORD *)(a2 + 48);
  if ( v3 )
  {
    v4 = *(_QWORD *)(v3 + 56);
    v6 = *(_QWORD *)(*(_QWORD *)(a2 + 96) + 24LL);
    v10[0] = 0;
    v7 = *(_QWORD **)(v6 + 152);
    v8 = v7[v2 + 6];
    if ( (_DWORD)v2 == 3 )
      v9 = 517;
    else
      v9 = 261;
    swr_write(v4, *(unsigned __int8 *)(v4 + 64), v9, v10);
    regmap_write(
      *v7,
      (*(_DWORD *)(v8 + 288) << 15) & 0x200000
    | ((*(_DWORD *)(a2 + 8) & 7) << 22)
    | ((*(_DWORD *)(v8 + 288) & 0x3F) << 7)
    | 0x40000008u);
    wait_for_pde_state(v7, *(unsigned int *)(v8 + 288), *(unsigned int *)(v8 + 96), 3, *(unsigned int *)(a2 + 8));
    *(_QWORD *)(a2 + 48) = 0;
  }
  _ReadStatusReg(SP_EL0);
}
