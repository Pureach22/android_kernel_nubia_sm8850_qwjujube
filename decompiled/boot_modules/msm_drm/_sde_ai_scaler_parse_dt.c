unsigned __int64 __fastcall sde_ai_scaler_parse_dt(__int64 a1, __int64 a2)
{
  unsigned __int64 result; // x0
  __int64 v4; // x8
  unsigned __int64 v5; // x8
  unsigned __int64 v7; // x13
  int v8; // w14
  int v9; // w14
  unsigned __int64 v15; // x13
  unsigned __int64 v16; // x21
  unsigned __int64 v17; // x19
  int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  result = sde_get_dt_props(a1, 4, (__int64)&ai_scaler_prop, 4u, (unsigned int *)&v18);
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    *(_DWORD *)(a2 + 20108) = 0;
    v4 = *(_QWORD *)(result + 320);
    if ( !*(_DWORD *)(v4 + 2304) || !v18 )
    {
      if ( !result )
        goto LABEL_21;
      goto LABEL_20;
    }
    if ( (unsigned int)v18 <= *(_DWORD *)(a2 + 8160)
      || (v16 = result, printk(&unk_232682, "_sde_ai_scaler_parse_dt"), result = v16, *(_DWORD *)(a2 + 8160)) )
    {
      v5 = 0;
      _X9 = (unsigned __int64 *)(a2 + 8200);
      do
      {
        if ( v5 == 12 )
          __break(0x5512u);
        v7 = _X9[2];
        *(_DWORD *)(v7 + 712) = 24;
        if ( *(_BYTE *)result == 1 && (__int64)v5 < v18 )
        {
          v8 = *(_DWORD *)(*(_QWORD *)(result + 320) + 4 * v5);
          *(_DWORD *)(v7 + 716) = v8;
          if ( v8 == -1 )
          {
            *(_DWORD *)(v7 + 716) = 0;
          }
          else
          {
            *(_DWORD *)(v7 + 720) = *(_DWORD *)(*(_QWORD *)(result + 320) + 1536LL);
            v9 = *(_DWORD *)(*(_QWORD *)(result + 320) + 768LL);
            *(_BYTE *)(v7 + 732) = 1;
            *(_DWORD *)(v7 + 724) = v9;
            __asm { PRFM            #0x11, [X9] }
            do
              v15 = __ldxr(_X9);
            while ( __stxr(v15 | 0x1000000, _X9) );
            ++*(_DWORD *)(a2 + 20108);
          }
        }
        ++v5;
        _X9 += 7;
      }
      while ( v5 < *(unsigned int *)(a2 + 8160) );
    }
    if ( result )
    {
      v4 = *(_QWORD *)(result + 320);
LABEL_20:
      v17 = result;
      kvfree(v4);
      kvfree(v17);
      result = 0;
    }
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
