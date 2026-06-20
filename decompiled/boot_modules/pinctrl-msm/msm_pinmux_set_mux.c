__int64 __fastcall msm_pinmux_set_mux(__int64 a1, int a2, unsigned int a3)
{
  __int64 drvdata; // x20
  __int64 v6; // x0
  unsigned int v7; // w24
  __int64 irq_data; // x0
  __int64 v9; // x9
  __int64 v10; // x21
  __int64 v11; // x25
  int v12; // w19
  int v13; // w26
  int v14; // w10
  __int64 v15; // x8
  __int64 v16; // x9
  int v17; // w11
  int v18; // w27
  __int64 result; // x0
  __int64 v20; // x9
  __int64 v21; // x8
  __int64 v22; // x28
  __int64 v23; // x23
  unsigned __int64 v24; // x24
  __int64 v25; // x8
  unsigned int v26; // w0
  unsigned __int64 v27; // x8
  __int64 v28; // x9
  unsigned int v29; // w0
  unsigned __int64 v30; // x8
  __int64 v31; // x9
  __int64 v32; // x8
  __int64 v33; // x9
  unsigned int v34; // w0
  unsigned __int64 v41; // x9
  unsigned __int64 v44; // x9
  unsigned __int64 v47; // x9
  unsigned int v48; // [xsp+Ch] [xbp-14h]
  int v49; // [xsp+10h] [xbp-10h]
  unsigned int v50; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v51; // [xsp+18h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  drvdata = pinctrl_dev_get_drvdata();
  v6 = *(_QWORD *)(drvdata + 312);
  v50 = 0;
  if ( _irq_resolve_mapping(v6, a3, &v50) )
    v7 = v50;
  else
    v7 = 0;
  irq_data = irq_get_irq_data(v7);
  v9 = *(_QWORD *)(drvdata + 968);
  v10 = irq_data;
  v11 = *(_QWORD *)(v9 + 32) + 112LL * a3;
  v13 = *(_DWORD *)(v9 + 108);
  v12 = *(_DWORD *)(v9 + 112);
  v14 = (*(_DWORD *)(v11 + 84) >> 7) & 0x1F;
  v15 = *(unsigned int *)(v11 + 56);
  v16 = -1LL << ((*(_DWORD *)(v11 + 84) >> 7) & 0x1F);
  if ( (unsigned int)v15 < 2 )
  {
    v17 = (0xFFFFFFFFFFFFFFFFLL >> -(char)v14) & v16;
    if ( !(_DWORD)v15 )
    {
      v18 = 0;
      goto LABEL_12;
    }
  }
  else
  {
    v17 = (0xFFFFFFFFFFFFFFFFLL >> ((unsigned __int8)__clz(v15 - 1) - (unsigned __int8)v14)) & v16;
  }
  v18 = 0;
  while ( *(_DWORD *)(*(_QWORD *)(v11 + 48) + 4LL * v18) != a2 )
  {
    if ( (_DWORD)v15 == ++v18 )
      goto LABEL_10;
  }
LABEL_12:
  if ( v18 == (_DWORD)v15 )
  {
LABEL_10:
    __break(0x800u);
    result = 4294967274LL;
    goto LABEL_44;
  }
  v49 = v17;
  if ( irq_data )
  {
    if ( v18 != v13 )
    {
      v20 = *(_QWORD *)(irq_data + 8);
      v21 = 1LL << v20;
      _X10 = (unsigned __int64 *)(drvdata + 888 + 8LL * ((unsigned int)v20 >> 6));
      __asm { PRFM            #0x11, [X10] }
      do
        v41 = __ldxr(_X10);
      while ( __stlxr(v41 | v21, _X10) );
      __dmb(0xBu);
      if ( (v41 & v21) == 0 )
        disable_irq(v7);
    }
  }
  v48 = v7;
  v22 = drvdata + 976;
  v23 = raw_spin_lock_irqsave(drvdata + 764);
  LODWORD(v24) = readl((unsigned int *)(*(_QWORD *)(drvdata + 976 + 8 * ((*(_QWORD *)(v11 + 84) >> 5) & 3LL))
                                      + *(unsigned int *)(v11 + 60)));
  if ( v18 == v13 && (((unsigned __int64)(unsigned int)v24 >> ((*(_QWORD *)(v11 + 84) >> 42) & 0x1F)) & 1) != 0 )
  {
    v25 = 1LL << a3;
    _X10 = (unsigned __int64 *)(drvdata + 928 + 8LL * (a3 >> 6));
    __asm { PRFM            #0x11, [X10] }
    do
      v47 = __ldxr(_X10);
    while ( __stlxr(v47 | v25, _X10) );
    __dmb(0xBu);
    if ( (v47 & v25) == 0 )
    {
      v26 = readl((unsigned int *)(*(_QWORD *)(v22 + 8 * ((*(_QWORD *)(v11 + 84) >> 5) & 3LL))
                                 + *(unsigned int *)(v11 + 64)));
      v27 = *(_QWORD *)(v11 + 84);
      v28 = 1LL << ((v27 >> 52) & 0x1F);
      if ( ((v26 >> ((v27 >> 47) & 0x1F)) & 1) != 0 )
      {
        if ( ((unsigned int)v28 & v26) != 0 )
          goto LABEL_25;
        v29 = v26 | v28;
      }
      else
      {
        if ( ((unsigned int)v28 & v26) == 0 )
          goto LABEL_25;
        v29 = v26 & ~(_DWORD)v28;
      }
      writel(v29, (unsigned int *)(*(_QWORD *)(v22 + 8 * ((v27 >> 5) & 3)) + *(unsigned int *)(v11 + 64)));
    }
  }
LABEL_25:
  if ( v12 && v18 == v12 )
  {
    v30 = *(_QWORD *)(v11 + 84);
    if ( (((unsigned int)v24 >> ((v30 >> 37) & 0x1F)) & 1) != 0 )
      LODWORD(v24) = v24 & ~(1 << SBYTE4(v30));
  }
  else
  {
    v30 = *(_QWORD *)(v11 + 84);
    v24 = (v18 << ((unsigned int)v30 >> 7)) | (unsigned int)v24 & ~v49;
    if ( v12 && ((v24 >> ((v30 >> 37) & 0x1F)) & 1) != 0 )
      LODWORD(v24) = v24 | (1 << SBYTE4(v30));
  }
  writel(v24, (unsigned int *)(*(_QWORD *)(v22 + 8 * ((v30 >> 5) & 3)) + *(unsigned int *)(v11 + 60)));
  raw_spin_unlock_irqrestore(drvdata + 764, v23);
  result = 0;
  if ( v10 && v18 == v13 )
  {
    v31 = *(_QWORD *)(v10 + 8);
    v32 = 1LL << v31;
    _X10 = (unsigned __int64 *)(drvdata + 888 + 8LL * ((unsigned int)v31 >> 6));
    __asm { PRFM            #0x11, [X10] }
    do
      v44 = __ldxr(_X10);
    while ( __stlxr(v44 & ~v32, _X10) );
    __dmb(0xBu);
    if ( (v44 & v32) != 0 )
    {
      if ( *(_QWORD *)(v10 + 40)
        && ((*(_QWORD *)(drvdata + 8LL * (*(_QWORD *)(v10 + 8) >> 6) + 848) >> *(_QWORD *)(v10 + 8)) & 1) != 0 )
      {
        irq_chip_set_parent_state(v10, 0, 0);
      }
      else
      {
        v33 = *(_QWORD *)(v11 + 92);
        if ( (v33 & 0x20) != 0 )
          v34 = 1 << v33;
        else
          v34 = 0;
        writel(
          v34,
          (unsigned int *)(*(_QWORD *)(v22 + 8 * ((*(_QWORD *)(v11 + 84) >> 5) & 3LL)) + *(unsigned int *)(v11 + 72)));
      }
      enable_irq(v48);
    }
    result = 0;
  }
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return result;
}
