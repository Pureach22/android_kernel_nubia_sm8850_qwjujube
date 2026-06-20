unsigned __int64 __fastcall sde_rc_parse_dt(__int64 a1, __int64 a2)
{
  unsigned __int64 result; // x0
  __int64 v4; // x1
  unsigned int v5; // w3
  unsigned int v6; // w4
  unsigned __int64 v7; // x8
  unsigned __int64 v9; // x21
  int v10; // w4
  unsigned __int64 v11; // x19
  unsigned __int64 v17; // x12
  _DWORD *v18; // x12
  int v19; // w13
  int v20; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  result = sde_get_dt_props(a1, 5, (__int64)&rc_prop, 5u, (unsigned int *)&v20);
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_8;
  v5 = v20;
  v6 = *(_DWORD *)(a2 + 8160);
  *(_DWORD *)(a2 + 19972) = v20;
  if ( v5 <= v6 )
  {
    if ( v6 )
      goto LABEL_4;
    goto LABEL_6;
  }
  v9 = result;
  printk(&unk_266461, "_sde_rc_parse_dt");
  v10 = *(_DWORD *)(a2 + 8160);
  result = v9;
  *(_DWORD *)(a2 + 19972) = v10;
  if ( !v10 )
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
  _X9 = (unsigned __int64 *)(a2 + 8200);
  while ( v7 != 12 )
  {
    v18 = (_DWORD *)_X9[2];
    v18[130] = 17;
    if ( *(_BYTE *)result == 1 && (__int64)v7 < v20 )
    {
      v18[131] = *(_DWORD *)(*(_QWORD *)(result + 320) + 4 * v7);
      v18[132] = *(_DWORD *)(*(_QWORD *)(result + 320) + 768LL);
      v18[133] = *(_DWORD *)(*(_QWORD *)(result + 320) + 1536LL);
      v18[135] = *(_DWORD *)(*(_QWORD *)(result + 320) + 2304LL);
      if ( *(_BYTE *)(result + 4) == 1 )
        v19 = *(_DWORD *)(*(_QWORD *)(result + 320) + 3072LL);
      else
        v19 = 4;
      v18[136] = v19;
      v18[134] = v7;
      __asm { PRFM            #0x11, [X9] }
      do
        v17 = __ldxr(_X9);
      while ( __stxr(v17 | 0x20000, _X9) );
    }
    ++v7;
    _X9 += 7;
    if ( v7 >= *(unsigned int *)(a2 + 8160) )
      goto LABEL_6;
  }
  __break(0x5512u);
  return sde_aiqe_parse_dt(result, v4);
}
