__int64 __fastcall clk_dyn_rcg_set_parent(__int64 a1, unsigned int a2)
{
  __int64 v4; // x19
  int v5; // w24
  int v6; // w22
  __int64 v7; // x0
  __int64 v8; // x1
  _BOOL8 v9; // x23
  __int64 v10; // x24
  __int64 v11; // x10
  int v12; // w8
  unsigned int v13; // w9
  __int64 result; // x0
  __int64 v15; // [xsp+0h] [xbp-30h] BYREF
  __int64 v16; // [xsp+8h] [xbp-28h]
  __int64 v17; // [xsp+10h] [xbp-20h]
  int v18; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v19[2]; // [xsp+20h] [xbp-10h] BYREF

  v4 = a1 - 80;
  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(unsigned __int8 *)(a1 - 47);
  v6 = *(unsigned __int8 *)(a1 - 42);
  v7 = *(_QWORD *)(a1 + 24);
  v8 = *(unsigned int *)(a1 - 64);
  v19[0] = 0;
  v18 = 0;
  v16 = 0;
  v17 = 0;
  v15 = 0;
  regmap_read(v7, v8, &v18);
  v9 = (v18 & (unsigned int)(1LL << *(_BYTE *)(a1 - 60))) != 0;
  regmap_read(*(_QWORD *)(a1 + 24), *(unsigned int *)(v4 + 4 * v9), (char *)v19 + 4);
  if ( v5 )
  {
    v10 = a1 - v9 + 8 * v9;
    regmap_read(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 + 4 * v9 - 72), v19);
    v11 = -1LL << *(_BYTE *)(v10 - 54);
    v12 = (LODWORD(v19[0]) >> *(_BYTE *)(v10 - 55)) & ~(_DWORD)v11;
    v13 = ((unsigned int)~HIDWORD(v19[0]) >> *(_BYTE *)(v10 - 56)) & ~(_DWORD)v11;
    WORD1(v16) = (LODWORD(v19[0]) >> *(_BYTE *)(v10 - 55)) & ~(_WORD)v11;
    WORD2(v16) = v13 + v12;
  }
  if ( v6 )
    BYTE1(v16) = ((HIDWORD(v19[0]) >> *(_BYTE *)(a1 - 45 + 2 * v9))
                & ~(unsigned __int8)(-1LL << *(_BYTE *)(a1 - 45 + 2 * v9 + 1)))
               + 1;
  LOBYTE(v16) = qcom_find_src_index(a1, *(_QWORD *)(a1 + 16 * v9 - 32), a2);
  result = configure_bank(v4, &v15);
  _ReadStatusReg(SP_EL0);
  return result;
}
