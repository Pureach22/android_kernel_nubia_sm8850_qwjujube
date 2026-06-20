__int64 __fastcall zte_ir_write(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v6; // x21
  unsigned __int64 v7; // x0
  int v8; // w20
  __int64 result; // x0
  __int64 v10; // x2
  int v11; // w8
  unsigned int v12; // w13
  unsigned __int64 v13; // x3
  __int64 v14; // x2
  unsigned __int64 v15; // x5
  __int16 v16; // w2
  unsigned __int64 v17; // x6
  unsigned __int64 v18; // x4
  unsigned __int64 v19; // x4
  unsigned __int64 v20; // x20
  _WORD *v21; // x5
  __int64 v22; // x7
  unsigned __int64 v23; // x7
  _WORD *v24; // x5
  int v25; // w3
  int v26; // w7
  bool v27; // cf
  __int64 v28; // x0
  _QWORD *v29; // [xsp+70h] [xbp-90h] BYREF
  _QWORD *v30; // [xsp+78h] [xbp-88h]
  __int64 v31; // [xsp+80h] [xbp-80h]
  _QWORD v32[11]; // [xsp+88h] [xbp-78h] BYREF
  _QWORD v33[4]; // [xsp+E0h] [xbp-20h] BYREF

  v33[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = nullptr;
  v31 = 0;
  v29 = nullptr;
  printk(&unk_6EFB, "zte_ir_write");
  v6 = *(_QWORD *)(a1 + 32);
  mutex_lock(v6 + 80040);
  v7 = memdup_user(a2, a3);
  if ( v7 > 0xFFFFFFFFFFFFF000LL )
  {
    v8 = v7;
LABEL_3:
    mutex_unlock(v6 + 80040);
    if ( v8 )
      result = v8;
    else
      result = a3;
    goto LABEL_6;
  }
  if ( a3 < 4 )
  {
LABEL_36:
    v30 = nullptr;
    v31 = 0;
    v29 = nullptr;
    printk(&unk_6E3C, "zte_ir_write");
    v28 = *(_QWORD *)(v6 + 80016);
    v33[2] = 0;
    memset(&v32[2], 0, 72);
    v33[0] = v33;
    v33[1] = v33;
    v32[1] = &v29;
    v29 = v32;
    v30 = v32;
    v32[0] = &v29;
    v8 = spi_sync(v28, v32);
    if ( v8 )
      dev_err(*(_QWORD *)(v6 + 80016), "unable to deliver the signal,ret = %d\n", v8);
    printk(&unk_6E2E, "zte_ir_write");
    goto LABEL_3;
  }
  v10 = 0;
  v11 = 0;
  v12 = 0;
  while ( 1 )
  {
    if ( v10 < 0 || a3 < 4 * v10 || a3 - 4 * v10 < 4 )
      goto LABEL_40;
    v13 = (unsigned __int64)(((*(unsigned int *)(v7 + 4 * v10) * (unsigned __int64)(*(_DWORD *)(v6 + 80008) >> 4)
                             + 500000)
                            * (unsigned __int128)0x10C6F7A0B5ED8D37uLL) >> 64) >> 16;
    if ( (v12 + (unsigned int)v13) >> 6 >= 0x271 )
      break;
    v14 = 80006;
    if ( (v11 & 1) == 0 )
      v14 = 80004;
    if ( (_DWORD)v13 )
    {
      LODWORD(v15) = 40000 - v12;
      v16 = *(_WORD *)(v6 + v14);
      if ( v12 <= 0x9C40 )
        v15 = (unsigned int)v15;
      else
        v15 = 0;
      if ( (unsigned int)(v13 - 1) < v15 )
        v15 = (unsigned int)(v13 - 1);
      v17 = v12;
      if ( v15 >= 2 )
      {
        v19 = v15 + 1;
        v20 = ~v15;
        v21 = (_WORD *)(v6 + 6 + 2LL * v12);
        v22 = v19 & 1;
        if ( (v19 & 1) == 0 )
          v22 = 2;
        v18 = v19 - v22;
        v23 = v20 + v22;
        v17 = v18 + v12;
        do
        {
          v23 += 2LL;
          *(v21 - 1) = v16;
          *v21 = v16;
          v21 += 2;
        }
        while ( v23 );
      }
      else
      {
        LODWORD(v18) = 0;
      }
      v24 = (_WORD *)(v6 + 4 + 2 * v17);
      if ( v12 >= 0x9C40 )
        v12 = 40000;
      v25 = v18 - v13;
      v26 = v18 - 40000 + v12;
      v12 = v17;
      while ( v26 )
      {
        v27 = __CFADD__(v25++, 1);
        ++v12;
        ++v26;
        *v24++ = v16;
        if ( v27 )
          goto LABEL_9;
      }
      __break(0x5512u);
LABEL_40:
      __break(1u);
    }
LABEL_9:
    v10 = ++v11;
    if ( a3 >> 2 <= v11 )
      goto LABEL_36;
  }
  printk(&unk_6E5E, "zte_ir_write");
  result = -22;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
