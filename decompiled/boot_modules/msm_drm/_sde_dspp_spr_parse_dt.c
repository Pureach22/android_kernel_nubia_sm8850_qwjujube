unsigned __int64 __fastcall sde_dspp_spr_parse_dt(__int64 a1, __int64 a2)
{
  unsigned __int64 result; // x0
  __int64 v4; // x1
  unsigned int v5; // w3
  unsigned int v6; // w4
  signed __int64 v7; // x8
  unsigned __int64 v9; // x21
  int v10; // w4
  unsigned __int64 v11; // x19
  unsigned __int64 v17; // x14
  _DWORD *v18; // x14
  unsigned __int64 v20; // x15
  unsigned __int64 v22; // x14
  int v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  result = sde_get_dt_props(a1, 5, (__int64)&spr_prop, 5u, (unsigned int *)&v23);
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_8;
  v5 = v23;
  v6 = *(_DWORD *)(a2 + 8160);
  *(_DWORD *)(a2 + 19976) = v23;
  if ( v5 > v6 )
  {
    v9 = result;
    printk(&unk_25B97A, "_sde_dspp_spr_parse_dt");
    v10 = *(_DWORD *)(a2 + 8160);
    result = v9;
    *(_DWORD *)(a2 + 19976) = v10;
    if ( v10 )
      goto LABEL_4;
    goto LABEL_6;
  }
  if ( !v6 )
  {
LABEL_6:
    if ( result )
    {
      v11 = result;
      kvfree(*(_QWORD *)(result + 320));
      kvfree(v11);
      result = 0;
    }
LABEL_8:
    _ReadStatusReg(SP_EL0);
    return result;
  }
LABEL_4:
  v7 = 0;
  _X10 = (unsigned __int64 *)(a2 + 8200);
  while ( v7 != 12 )
  {
    v18 = (_DWORD *)_X10[2];
    v18[103] = 13;
    if ( *(_BYTE *)result == 1 && v7 < v23 )
    {
      v18[104] = *(_DWORD *)(*(_QWORD *)(result + 320) + 4 * v7);
      v18[105] = *(_DWORD *)(*(_QWORD *)(result + 320) + 768LL);
      v18[107] = *(_DWORD *)(*(_QWORD *)(result + 320) + 1536LL);
      __asm { PRFM            #0x11, [X10] }
      do
        v20 = __ldxr(_X10);
      while ( __stxr(v20 | 0x2000, _X10) );
    }
    v18[112] = 13;
    if ( *(_BYTE *)(result + 3) == 1 && v7 < v23 )
    {
      v18[113] = *(_DWORD *)(*(_QWORD *)(result + 320) + 4 * v7 + 2304);
      v18[116] = *(_DWORD *)(*(_QWORD *)(result + 320) + 3072LL);
      __asm { PRFM            #0x11, [X10] }
      do
        v22 = __ldxr(_X10);
      while ( __stxr(v22 | 0x4000, _X10) );
      if ( (*(_QWORD *)(a2 + 22008) & 0x40000000) == 0 )
        goto LABEL_11;
LABEL_9:
      __asm { PRFM            #0x11, [X10] }
      do
        v17 = __ldxr(_X10);
      while ( __stxr(v17 | 0x8000, _X10) );
      goto LABEL_11;
    }
    if ( (*(_QWORD *)(a2 + 22008) & 0x40000000) != 0 )
      goto LABEL_9;
LABEL_11:
    ++v7;
    _X10 += 7;
    if ( v7 >= (unsigned __int64)*(unsigned int *)(a2 + 8160) )
      goto LABEL_6;
  }
  __break(0x5512u);
  return sde_dspp_demura_parse_dt(result, v4);
}
