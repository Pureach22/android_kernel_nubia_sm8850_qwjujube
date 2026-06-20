__int64 __fastcall adreno_drawctxt_dump(_QWORD *a1, __int64 *a2)
{
  _DWORD *v3; // x22
  __int64 *v4; // x20
  _QWORD *v5; // x19
  int v6; // w8
  __int64 v7; // x0
  int v8; // w2
  __int64 result; // x0
  __int64 v10; // x8
  unsigned int v11; // w8
  unsigned int v12; // w23
  _QWORD *v13; // x24
  __int64 v14; // x8
  unsigned int v16; // w9
  int v22; // w8
  __int64 *v23; // [xsp+0h] [xbp-A0h]
  _QWORD *v24; // [xsp+8h] [xbp-98h]
  int v25; // [xsp+14h] [xbp-8Ch] BYREF
  __int64 v26; // [xsp+18h] [xbp-88h] BYREF
  __int64 v27; // [xsp+20h] [xbp-80h] BYREF
  __int64 v28; // [xsp+28h] [xbp-78h]
  __int64 v29; // [xsp+30h] [xbp-70h]
  __int64 v30; // [xsp+38h] [xbp-68h]
  __int64 v31; // [xsp+40h] [xbp-60h]
  __int64 v32; // [xsp+48h] [xbp-58h]
  __int64 v33; // [xsp+50h] [xbp-50h]
  __int64 v34; // [xsp+58h] [xbp-48h]
  __int64 v35; // [xsp+60h] [xbp-40h]
  __int64 v36; // [xsp+68h] [xbp-38h]
  __int64 v37; // [xsp+70h] [xbp-30h]
  __int64 v38; // [xsp+78h] [xbp-28h]
  __int64 v39; // [xsp+80h] [xbp-20h]
  __int64 v40; // [xsp+88h] [xbp-18h]
  __int64 v41; // [xsp+90h] [xbp-10h]
  __int64 v42; // [xsp+98h] [xbp-8h]

  v4 = a2;
  v5 = a1;
  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 0;
  v27 = 0;
  v25 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  kgsl_readtimestamp(a1, a2, 3, (char *)&v26 + 4);
  kgsl_readtimestamp(v5, v4, 1, &v26);
  kgsl_readtimestamp(v5, v4, 2, &v25);
  v6 = raw_spin_trylock_bh((char *)v4 + 404);
  v7 = *v5;
  v8 = *((_DWORD *)v4 + 1);
  if ( !v6 )
  {
    result = dev_err(v7, "  context[%u]: could not get lock\n", v8);
    goto LABEL_23;
  }
  v24 = v5;
  dev_err(
    v7,
    "  context[%u]: queue=%u, submit=%u, start=%u, retire=%u\n",
    v8,
    HIDWORD(v26),
    *((_DWORD *)v4 + 386),
    v26,
    v25);
  v10 = *((unsigned int *)v4 + 358);
  if ( (_DWORD)v10 != *((_DWORD *)v4 + 359) )
  {
    if ( (unsigned int)v10 >= 0x80 )
    {
LABEL_31:
      __break(0x5512u);
    }
    else
    {
      v3 = (_DWORD *)v4[v10 + 51];
      if ( (v4[4] & 0x400000) != 0 )
      {
        dev_err(*v5, "  possible deadlock. Context %u might be blocked for itself\n", *((_DWORD *)v4 + 1));
        goto LABEL_17;
      }
      _X21 = v3 + 8;
      v11 = v3[8];
      if ( v11 )
      {
        do
        {
          __asm { PRFM            #0x11, [X21] }
          do
            v16 = __ldxr(_X21);
          while ( v16 == v11 && __stxr(v11 + 1, _X21) );
          LODWORD(v5) = v11;
          if ( v16 == v11 )
            break;
          LODWORD(v5) = 0;
          v11 = v16;
        }
        while ( v16 );
      }
      else
      {
        LODWORD(v5) = 0;
      }
      if ( ((((_DWORD)v5 + 1) | (unsigned int)v5) & 0x80000000) == 0 )
      {
        if ( !(_DWORD)v5 )
          goto LABEL_17;
LABEL_10:
        if ( v3[4] == 4 && v3[18] )
        {
          dev_err(*v24, "  context[%u] (ts=%u) Active sync points:\n", *((_DWORD *)v4 + 1), v3[5]);
          kgsl_dump_syncpoints(v24, v3);
        }
        if ( v3 )
        {
          __asm { PRFM            #0x11, [X21] }
          do
            v22 = __ldxr(_X21);
          while ( __stlxr(v22 - 1, _X21) );
          if ( v22 == 1 )
          {
            __dmb(9u);
            kgsl_drawobj_destroy_object(_X21);
          }
          else if ( v22 <= 0 )
          {
            refcount_warn_saturate(_X21, 3);
          }
        }
        goto LABEL_17;
      }
    }
    refcount_warn_saturate(_X21, 0);
    if ( !(_DWORD)v5 )
      goto LABEL_17;
    goto LABEL_10;
  }
LABEL_17:
  v3 = nullptr;
  v12 = 0;
  v23 = v4;
  v13 = v4 + 194;
  v4 = &v27;
  LODWORD(v5) = 120;
  _X21 = (unsigned int *)"%u.%0u ";
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v27 = 0;
  do
  {
    v14 = *(_QWORD *)((char *)v3 + (_QWORD)v13);
    if ( v14 )
    {
      if ( v12 > 0x78 )
        goto LABEL_31;
      v12 += scnprintf(
               (char *)&v27 + v12,
               120LL - v12,
               "%u.%0u ",
               10 * v14 / 0x2EE00uLL,
               10 * v14 / 0xC0uLL
             - 1000
             * ((unsigned __int64)(((unsigned __int64)(10 * v14) * (unsigned __int128)0xAAAAAAAAAAAAAAABLL) >> 64)
              / 0x1F400));
    }
    v3 += 2;
  }
  while ( v3 != (_DWORD *)&unk_38 );
  dev_err(*v24, "  context[%u]: submit times: %s\n", *((_DWORD *)v23 + 1), (const char *)&v27);
  result = raw_spin_unlock_bh((char *)v23 + 404);
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
