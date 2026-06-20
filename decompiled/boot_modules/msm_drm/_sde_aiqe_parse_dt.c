unsigned __int64 __fastcall sde_aiqe_parse_dt(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  unsigned __int64 result; // x0
  unsigned __int64 v5; // x4
  bool v6; // cc
  unsigned __int64 v7; // x8
  unsigned __int64 v9; // x13
  int v10; // w14
  _DWORD *v11; // x14
  unsigned __int64 v17; // x13
  __int64 v18; // x11
  unsigned __int64 v20; // x12
  _DWORD *v21; // x12
  int v22; // w13
  unsigned __int64 v24; // x12
  __int64 v25; // x11
  unsigned __int64 v27; // x13
  _DWORD *v28; // x12
  int v29; // w13
  unsigned __int64 v31; // x12
  unsigned __int64 v32; // x19
  unsigned __int64 v33; // x21
  int v34; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v35; // [xsp+8h] [xbp-8h]

  v3 = a2 + 0x4000;
  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  *(_DWORD *)(a2 + 20116) = 0;
  result = sde_get_dt_props(a1, 13, (__int64)&aiqe_prop, 0xDu, (unsigned int *)&v34);
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    LODWORD(v5) = *(_DWORD *)(a2 + 8160);
    v6 = v34 > (unsigned int)v5;
    *(_DWORD *)(v3 + 3720) = v34;
    if ( v6 )
    {
      v33 = result;
      printk(&unk_25B9C0, "_sde_aiqe_parse_dt");
      LODWORD(v5) = *(_DWORD *)(a2 + 8160);
      result = v33;
      *(_DWORD *)(v3 + 3720) = v5;
    }
    if ( *(_BYTE *)result == 1 )
    {
      if ( (_DWORD)v5 )
      {
        v7 = 0;
        _X9 = (unsigned __int64 *)(a2 + 8200);
        while ( v7 != 12 )
        {
          if ( (__int64)v7 < v34 )
          {
            v9 = _X9[2];
            *(_DWORD *)(v9 + 600) = 21;
            v10 = *(_DWORD *)(*(_QWORD *)(result + 320) + 4 * v7);
            *(_DWORD *)(v9 + 604) = v10;
            if ( v10 == -1 )
            {
              *(_DWORD *)(v9 + 604) = 0;
            }
            else
            {
              *(_DWORD *)(v9 + 612) = *(_DWORD *)(*(_QWORD *)(result + 320) + 768LL);
              *(_DWORD *)(v9 + 608) = *(_DWORD *)(*(_QWORD *)(result + 320) + 1536LL);
              v11 = *(_DWORD **)(result + 320);
              if ( v11[576] )
              {
                *(_BYTE *)(v9 + 616) = 1;
                v11 = *(_DWORD **)(result + 320);
              }
              if ( v11[768] )
              {
                ++*(_DWORD *)(v3 + 3732);
                *(_BYTE *)(v9 + 617) = 1;
                v11 = *(_DWORD **)(result + 320);
              }
              if ( v11[960] )
              {
                *(_BYTE *)(v9 + 618) = 1;
                v11 = *(_DWORD **)(result + 320);
              }
              if ( v11[1152] )
                *(_BYTE *)(v9 + 619) = 1;
              __asm { PRFM            #0x11, [X9] }
              do
                v17 = __ldxr(_X9);
              while ( __stxr(v17 | 0x200000, _X9) );
            }
            v5 = *(unsigned int *)(a2 + 8160);
            ++v7;
            _X9 += 7;
            if ( v7 < v5 )
              continue;
          }
          goto LABEL_23;
        }
LABEL_48:
        __break(0x5512u);
      }
    }
    else
    {
LABEL_23:
      if ( *(_BYTE *)(result + 7) == 1 && (_DWORD)v5 )
      {
        v18 = 1344;
        _X8 = (unsigned __int64 *)(a2 + 8200);
        while ( v18 != 1356 )
        {
          if ( v18 - 1344 < v34 )
          {
            v21 = (_DWORD *)_X8[2];
            v21[160] = 22;
            v22 = *(_DWORD *)(*(_QWORD *)(result + 320) + 4 * v18);
            v21[161] = v22;
            if ( v22 == -1 )
            {
              v21[161] = 0;
            }
            else
            {
              v21[164] = *(_DWORD *)(*(_QWORD *)(result + 320) + 6144LL);
              v21[162] = *(_DWORD *)(*(_QWORD *)(result + 320) + 6912LL);
              __asm { PRFM            #0x11, [X8] }
              do
                v24 = __ldxr(_X8);
              while ( __stxr(v24 | 0x400000, _X8) );
            }
            v5 = *(unsigned int *)(a2 + 8160);
            v20 = v18 - 1343;
            ++v18;
            _X8 += 7;
            if ( v20 < v5 )
              continue;
          }
          goto LABEL_34;
        }
        goto LABEL_48;
      }
    }
LABEL_34:
    if ( *(_BYTE *)(result + 10) == 1 && (_DWORD)v5 )
    {
      v25 = 1920;
      _X8 = (unsigned __int64 *)(a2 + 8200);
      while ( v25 != 1932 )
      {
        if ( v25 - 1920 < v34 )
        {
          v28 = (_DWORD *)_X8[2];
          v28[169] = 23;
          v29 = *(_DWORD *)(*(_QWORD *)(result + 320) + 4 * v25);
          v28[170] = v29;
          if ( v29 == -1 )
          {
            v28[170] = 0;
          }
          else
          {
            v28[173] = *(_DWORD *)(*(_QWORD *)(result + 320) + 8448LL);
            v28[171] = *(_DWORD *)(*(_QWORD *)(result + 320) + 9216LL);
            __asm { PRFM            #0x11, [X8] }
            do
              v31 = __ldxr(_X8);
            while ( __stxr(v31 | 0x800000, _X8) );
          }
          v27 = v25 - 1919;
          ++v25;
          _X8 += 7;
          if ( v27 < *(unsigned int *)(a2 + 8160) )
            continue;
        }
        goto LABEL_45;
      }
      goto LABEL_48;
    }
LABEL_45:
    if ( result )
    {
      v32 = result;
      kvfree(*(_QWORD *)(result + 320));
      kvfree(v32);
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
