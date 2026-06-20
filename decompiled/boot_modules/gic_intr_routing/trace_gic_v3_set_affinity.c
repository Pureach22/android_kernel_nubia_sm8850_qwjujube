void __fastcall trace_gic_v3_set_affinity(
        __int64 a1,
        __int64 a2,
        unsigned int *a3,
        _QWORD *a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x25
  __int64 v9; // x26
  __int64 v14; // x20
  int v16; // w8
  __int64 v17; // x9
  char v18; // w8
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x20
  int v21; // w0
  __int64 v22; // x9
  __int64 v23; // x10
  unsigned __int64 v24; // x8
  unsigned __int64 v25; // x9
  __int64 v26; // x10
  __int64 v27; // x8
  __int64 v28; // x19
  __int64 v29; // x10
  int v30; // w8
  __int64 v31; // x9
  __int64 *v32; // x11
  unsigned __int64 v34; // x10
  unsigned int v35; // w10
  unsigned int v36; // w21
  __int64 v37; // x11
  __int64 v38; // x22
  _BOOL4 v39; // w20
  bool v40; // w8
  _BOOL4 v41; // w24
  __int64 v42; // x9
  __int64 v43; // x8
  unsigned __int64 v49; // x11
  unsigned __int64 v52; // x10
  unsigned __int64 v55; // x11
  unsigned __int64 v58; // x11
  unsigned __int64 v61; // x10
  __int64 v62; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(a2 + 8);
  if ( (unsigned __int64)(v8 - 1020) < 0xFFFFFFFFFFFFFC24LL )
    return;
  v9 = *(_QWORD *)(a2 + 16);
  if ( (byte_7B4E & 1) == 0 )
  {
    v14 = a6;
    raw_spin_lock(&gic_init_lock);
    if ( (byte_7B4E & 1) != 0 )
    {
LABEL_8:
      raw_spin_unlock(&gic_init_lock);
      a6 = v14;
      goto LABEL_9;
    }
    v16 = readl_relaxed((unsigned int *)(v14 + 8)) & 0xFF000FFF;
    if ( v16 != 33555515 && v16 != 67109947 )
    {
      v17 = a2;
      if ( v16 != 1191182448 )
      {
LABEL_7:
        gic_routing_data[0] = *(_QWORD *)(v17 + 24);
        __dmb(0xAu);
        byte_7B4E = 1;
        goto LABEL_8;
      }
      byte_7B4C = 1;
    }
    byte_7B4D = (readl_relaxed((unsigned int *)(v14 + 4)) & 0x2000000) == 0;
    printk(&unk_813D, "qcom_gic_enable_quirks");
    v17 = a2;
    goto LABEL_7;
  }
LABEL_9:
  if ( byte_7B4D == 1 )
  {
    qword_7B58 = a7;
    qword_7B60 = a8;
    if ( (byte_7B4C & 1) == 0 && !dword_7B68 )
    {
      v18 = 0;
      v62 = a6;
      do
      {
        v19 = (unsigned int)(-1LL << v18) & _cpu_possible_mask;
        if ( !(_DWORD)v19 )
          break;
        v20 = __clz(__rbit64(v19));
        v21 = readl_relaxed((unsigned int *)(a7 + v20 * a8));
        writel_relaxed(
          v21 & 0xFDFFFFFF | ((((_cpu_online_mask >> v20) & 1LL) == 0) << 25),
          (unsigned int *)(a7 + v20 * a8));
        v18 = v20 + 1;
      }
      while ( v20 < 0x1F );
      a6 = v62;
      dword_7B68 = 1;
    }
    v22 = *(unsigned int *)(v9 + 24);
    v23 = qword_7B30;
    v24 = *(unsigned int *)(_ReadStatusReg(SP_EL0) + 40);
    if ( (v22 & ~v23) != 0
      || ((unsigned int)v23 & _cpu_online_mask) != 0
      || (*((_QWORD *)&_cpu_online_mask + (v24 >> 6)) & (1LL << v24)) != 0
      || (gic_routing_data[(v24 >> 6) + 1] & (1LL << v24)) == 0 )
    {
      if ( (v22 & ~qword_7B38) != 0
        || ((unsigned int)qword_7B38 & _cpu_online_mask) != 0
        || (v25 = v24 >> 6, v26 = *((_QWORD *)&_cpu_online_mask + (v24 >> 6)), v27 = 1LL << v24, (v26 & v27) != 0)
        || (gic_routing_data[v25 + 2] & v27) == 0 )
      {
        v28 = a6;
        if ( (_sw_hweight64(*a3) & 0xFFFFFFFELL) != 0 )
        {
          v29 = *(_QWORD *)a3;
          v30 = qword_7B38;
          v31 = (unsigned int)~(_DWORD)qword_7B30;
          if ( (v31 & *(_QWORD *)a3) == 0
            || (unsigned int)v29 == (unsigned int)qword_7B30
            || (unsigned int)v29 == (unsigned int)qword_7B38
            || ((unsigned int)qword_7B38 | (unsigned int)qword_7B30) == (unsigned int)v29 )
          {
            v32 = (__int64 *)&_cpu_online_mask;
            v34 = (unsigned int)v29 & _cpu_online_mask;
            _ZF = (_DWORD)v34 == 0;
            v35 = __clz(__rbit64(v34));
            if ( _ZF )
              v35 = 32;
            if ( v35 < nr_cpu_ids )
              v32 = (__int64 *)a3;
            v36 = v8 - 32;
            v37 = *v32;
            *a4 |= 0x80000000uLL;
            v38 = v31 & v37;
            v39 = ((unsigned int)v37 & ~v30) != 0 || (v31 & v37) == 0;
            v41 = (byte_7B4C != 1
                || (!(*(_QWORD *)((_BYTE *)&gic_class_initialized
                                + (((unsigned __int64)(unsigned int)(v8 - 32) >> 3) & 0x1FFFFFF8))
                    & (1LL << ((unsigned __int8)v8 - 32))
                    | v38)
                  ? (v40 = v39)
                  : (v40 = 0),
                    !v40))
               && (((*(_QWORD *)((char *)&gic_class_initialized
                               + (((unsigned __int64)(unsigned int)(v8 - 32) >> 3) & 0x1FFFFFF8)) >> ((unsigned __int8)v8 - 32))
                  & 1) == 0
                || ((v39
                   ^ (unsigned int)(*(_QWORD *)((char *)&active_gic_class0
                                              + (((unsigned __int64)(unsigned int)(v8 - 32) >> 3) & 0x1FFFFFF8)) >> ((unsigned __int8)v8 - 32)))
                  & 1) != 0
                || (v38 != 0) != ((*(_QWORD *)((char *)&active_gic_class1
                                             + (((unsigned __int64)(unsigned int)(v8 - 32) >> 3) & 0x1FFFFFF8)) >> ((unsigned __int8)v8 - 32))
                                & 1));
            raw_spin_lock(&gic_class_lock);
            v42 = v36 >> 6;
            v43 = 1LL << v36;
            _X10 = (unsigned __int64 *)((char *)&gic_class_initialized + 8 * v42);
            __asm { PRFM            #0x11, [X10] }
            do
              v49 = __ldxr(_X10);
            while ( __stxr(v49 | v43, _X10) );
            if ( v39 )
            {
              _X10 = (unsigned __int64 *)((char *)&active_gic_class0 + 8 * v42);
              __asm { PRFM            #0x11, [X10] }
              do
                v55 = __ldxr(_X10);
              while ( __stxr(v55 | v43, _X10) );
              if ( !v38 )
              {
                _X9 = (unsigned __int64 *)((char *)&active_gic_class1 + 8 * v42);
                __asm { PRFM            #0x11, [X9] }
                do
                  v61 = __ldxr(_X9);
                while ( __stxr(v61 & ~v43, _X9) );
                goto LABEL_56;
              }
            }
            else
            {
              _X10 = (unsigned __int64 *)((char *)&active_gic_class0 + 8 * v42);
              __asm { PRFM            #0x11, [X10] }
              do
                v58 = __ldxr(_X10);
              while ( __stxr(v58 & ~v43, _X10) );
            }
            _X9 = (unsigned __int64 *)((char *)&active_gic_class1 + 8 * v42);
            __asm { PRFM            #0x11, [X9] }
            do
              v52 = __ldxr(_X9);
            while ( __stxr(v52 | v43, _X9) );
LABEL_56:
            raw_spin_unlock(&gic_class_lock);
            if ( v41 )
              gic_do_class_update(v28, v36, v39, v38 != 0);
          }
        }
      }
    }
  }
}
