__int64 __fastcall msm_gpio_irq_set_type(_QWORD *a1, int a2)
{
  __int64 data; // x21
  __int64 v5; // x0
  __int64 v6; // x0
  unsigned __int64 v7; // x9
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x10
  unsigned __int64 v11; // x9
  __int64 v12; // x8
  __int64 v13; // x0
  int v14; // w10
  __int64 v15; // x8
  unsigned int v16; // w23
  __int64 v17; // x9
  bool v18; // cc
  __int64 v19; // x22
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x23
  __int64 v23; // x9
  __int64 v24; // x8
  __int64 v25; // x10
  int v26; // w25
  __int64 v27; // x24
  int v28; // w0
  __int64 v29; // x8
  __int64 v30; // x24
  int v31; // w0
  unsigned __int64 v32; // x11
  unsigned __int64 v33; // x10
  unsigned __int64 v34; // x11
  unsigned int v35; // w8
  int v36; // w12
  __int64 v37; // x11
  int v38; // w11
  int v39; // w10
  int v40; // w10
  unsigned int v41; // w21
  __int64 v42; // x0
  __int64 v43; // x24
  __int64 v44; // x22
  __int64 v45; // x25
  int v46; // w0
  __int64 irq_data; // x0
  __int64 v48; // x8
  void (*v49)(void); // x8
  int v50; // w10
  __int64 v51; // x25
  __int64 v52; // x9
  unsigned int v53; // w0
  __int64 v54; // x8
  void *v55; // x9
  unsigned __int64 v63; // x10
  unsigned __int64 v66; // x10
  unsigned __int64 v69; // x10
  unsigned __int64 v72; // x10
  unsigned int v73; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v74; // [xsp+8h] [xbp-8h]

  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  data = gpiochip_get_data(a1[6]);
  v5 = a1[6];
  v73 = 0;
  v6 = gpiochip_get_data(v5);
  if ( a2 == 3 && *(_BYTE *)(*(_QWORD *)(v6 + 968) + 92LL) == 1 )
  {
    if ( a1[5] )
    {
      v7 = a1[1];
      v8 = 1LL << v7;
      if ( (*(_QWORD *)(v6 + 8 * (v7 >> 6) + 848) & (1LL << v7)) != 0 )
      {
        v9 = (unsigned int)v7 >> 6;
        v10 = data + 768;
        goto LABEL_79;
      }
    }
  }
  if ( a1[5] )
    irq_chip_set_type_parent(a1, (unsigned int)a2);
  v11 = a1[1];
  v12 = 1LL << v11;
  if ( (*(_QWORD *)(data + 8 * (v11 >> 6) + 848) & (1LL << v11)) != 0 )
  {
    _X9 = (unsigned __int64 *)(data + 768 + 8LL * ((unsigned int)v11 >> 6));
    __asm { PRFM            #0x11, [X9] }
    do
      v63 = __ldxr(_X9);
    while ( __stxr(v63 & ~v12, _X9) );
    v54 = a1[2];
    v55 = &handle_fasteoi_irq;
    goto LABEL_70;
  }
  v13 = gpiochip_get_data(a1[6]);
  v14 = *(_DWORD *)(v13 + 756);
  v15 = a1[1];
  if ( v14 >= 1 )
  {
    v16 = 0;
    v17 = *(_QWORD *)(*(_QWORD *)(v13 + 968) + 144LL);
    while ( v15 != *(_DWORD *)(v17 + 8LL * (unsigned int)v14) )
    {
      v18 = v14-- < 2;
      v16 += 4;
      if ( v18 )
        goto LABEL_17;
    }
    if ( a2 != 3 )
    {
      v41 = *(_DWORD *)(v17 + 8LL * (unsigned int)v14 + 4);
      v42 = gpiochip_get_data(a1[6]);
      if ( (a2 & 5) != 0 )
      {
        v43 = v42;
        v44 = raw_spin_lock_irqsave(v42 + 764);
        v45 = *(_QWORD *)(*(_QWORD *)(v43 + 968) + 32LL) + 112LL * a1[1];
        v46 = readl_relaxed((unsigned int *)(*(_QWORD *)(msm_pinctrl_data
                                                       + 8 * ((*(_QWORD *)(v45 + 84) >> 5) & 3LL)
                                                       + 976)
                                           + *(unsigned int *)(v45 + 80)
                                           + (unsigned __int64)v16));
        writel_relaxed(
          v46 | 0x100,
          (unsigned int *)(*(_QWORD *)(msm_pinctrl_data + 8 * ((*(_QWORD *)(v45 + 84) >> 5) & 3LL) + 976)
                         + *(unsigned int *)(v45 + 80)
                         + (unsigned __int64)v16));
        raw_spin_unlock_irqrestore(v43 + 764, v44);
      }
      irq_data = irq_get_irq_data(v41);
      if ( irq_data )
      {
        v48 = *(_QWORD *)(irq_data + 24);
        if ( v48 )
        {
          v49 = *(void (**)(void))(v48 + 64);
          if ( *((_DWORD *)v49 - 1) != 270158662 )
            __break(0x8228u);
          v49();
        }
      }
LABEL_66:
      if ( (a2 & 0xC) != 0 )
      {
        v54 = a1[2];
        v55 = &handle_level_irq;
      }
      else
      {
        if ( (a2 & 3) == 0 )
          goto LABEL_71;
        v54 = a1[2];
        v55 = &handle_edge_irq;
      }
LABEL_70:
      *(_QWORD *)(v54 + 112) = v55;
      goto LABEL_71;
    }
  }
LABEL_17:
  v19 = *(_QWORD *)(*(_QWORD *)(data + 968) + 32LL) + 112 * v15;
  v20 = raw_spin_lock_irqsave(data + 764);
  v21 = a1[1];
  v22 = v20;
  v23 = (unsigned int)v21 >> 6;
  v24 = 1LL << v21;
  v25 = data + 768;
  if ( a2 == 3 && (*(_QWORD *)(v19 + 92) & 0xF800000000000LL) == 0x800000000000LL )
  {
    _X9 = (unsigned __int64 *)(v25 + 8 * v23);
    __asm { PRFM            #0x11, [X9] }
    do
      v66 = __ldxr(_X9);
    while ( __stxr(v66 | v24, _X9) );
  }
  else
  {
    _X9 = (unsigned __int64 *)(v25 + 8 * v23);
    __asm { PRFM            #0x11, [X9] }
    do
      v69 = __ldxr(_X9);
    while ( __stxr(v69 & ~v24, _X9) );
  }
  if ( ((*(_DWORD *)(v19 + 92) >> 21) & 0x1F) != 0 )
    v26 = 0xFFFFFFFFFFFFFFFFLL >> -((*(_DWORD *)(v19 + 92) >> 21) & 0x1F);
  else
    v26 = 7;
  if ( *(_BYTE *)(data + 760) == 1 )
  {
    v27 = (unsigned int)(*(_DWORD *)(v19 + 76) + *(_DWORD *)(data + 1008));
    qcom_scm_io_readl(v27, &v73);
    v73 = v73 & ~(v26 << BYTE2(*(_DWORD *)(v19 + 92)))
        | (((*(_DWORD *)(v19 + 92) >> 26) & 0x1F) << BYTE2(*(_DWORD *)(v19 + 92)));
    if ( (unsigned int)qcom_scm_io_writel(v27) )
      dev_err(*(_QWORD *)data, "Failed routing %lu interrupt to Apps proc", a1[1]);
  }
  else
  {
    v28 = readl((unsigned int *)(*(_QWORD *)(data + 976 + 8 * ((*(_QWORD *)(v19 + 84) >> 5) & 3LL))
                               + *(unsigned int *)(v19 + 76)));
    v29 = (*(_QWORD *)(v19 + 84) >> 5) & 3LL;
    v73 = v28 & ~(v26 << BYTE2(*(_DWORD *)(v19 + 92)))
        | (((*(_DWORD *)(v19 + 92) >> 26) & 0x1F) << BYTE2(*(_DWORD *)(v19 + 92)));
    writel(v73, (unsigned int *)(*(_QWORD *)(data + 976 + 8 * v29) + *(unsigned int *)(v19 + 76)));
  }
  v30 = data + 976;
  v31 = readl((unsigned int *)(*(_QWORD *)(data + 976 + 8 * ((*(_QWORD *)(v19 + 84) >> 5) & 3LL))
                             + *(unsigned int *)(v19 + 68)));
  v32 = *(_QWORD *)(v19 + 92);
  v10 = (v32 >> 47) & 0x1F;
  v9 = 1LL << (BYTE4(v32) & 0x1F);
  v8 = v31 | (unsigned int)v9;
  v73 = v31 | v9;
  if ( (_DWORD)v10 == 1 )
  {
    v33 = v32 >> 42;
    v34 = v32 >> 37;
    v35 = v8 & ~((1 << v33) | (1 << v34));
    v73 = v35;
    if ( a2 <= 2 )
    {
      if ( a2 != 1 )
      {
        if ( a2 != 2 )
          goto LABEL_58;
        goto LABEL_43;
      }
LABEL_44:
      v40 = (1 << v33) | (1 << v34);
      goto LABEL_45;
    }
    if ( a2 == 3 )
      goto LABEL_44;
    if ( a2 == 4 )
    {
      v40 = 1 << v34;
LABEL_45:
      v35 |= v40;
LABEL_57:
      v73 = v35;
    }
LABEL_58:
    v51 = (unsigned int)v9 & v31;
    writel(
      v35,
      (unsigned int *)(*(_QWORD *)(v30 + 8 * ((*(_QWORD *)(v19 + 84) >> 5) & 3LL)) + *(unsigned int *)(v19 + 68)));
    if ( !v51 )
    {
      v52 = *(_QWORD *)(v19 + 92);
      if ( (v52 & 0x20) != 0 )
        v53 = 1 << v52;
      else
        v53 = 0;
      writel(
        v53,
        (unsigned int *)(*(_QWORD *)(v30 + 8 * ((*(_QWORD *)(v19 + 84) >> 5) & 3LL)) + *(unsigned int *)(v19 + 72)));
    }
    if ( ((*(_QWORD *)(data + 8LL * (a1[1] >> 6) + 768) >> a1[1]) & 1) != 0 )
      msm_gpio_update_dual_edge_pos(data, v19);
    raw_spin_unlock_irqrestore(data + 764, v22);
    goto LABEL_66;
  }
  if ( (_DWORD)v10 == 2 )
  {
    v33 = v32 >> 37;
    v36 = 3 << (v32 >> 42);
    v35 = v8 & ~(v36 | (1 << (v32 >> 37)));
    v73 = v35;
    if ( a2 > 2 )
    {
      if ( a2 != 3 )
      {
        if ( a2 == 4 )
        {
LABEL_43:
          v40 = 1 << v33;
          goto LABEL_45;
        }
        goto LABEL_58;
      }
      v50 = v36 | (1 << v33);
    }
    else
    {
      v37 = (v32 >> 42) & 0x1F;
      if ( a2 == 1 )
      {
        v38 = 1 << v37;
        v39 = 1 << v33;
      }
      else
      {
        if ( a2 != 2 )
          goto LABEL_58;
        v38 = 2 << v37;
        v39 = 1 << v33;
      }
      v50 = v38 | v39;
    }
    v35 |= v50;
    goto LABEL_57;
  }
  __break(0x800u);
LABEL_79:
  _X9 = (unsigned __int64 *)(v10 + 8 * v9);
  __asm { PRFM            #0x11, [X9] }
  do
    v72 = __ldxr(_X9);
  while ( __stxr(v72 | v8, _X9) );
  *(_QWORD *)(a1[2] + 112LL) = &handle_fasteoi_ack_irq;
  msm_gpio_update_dual_edge_parent(a1);
LABEL_71:
  _ReadStatusReg(SP_EL0);
  return 0;
}
