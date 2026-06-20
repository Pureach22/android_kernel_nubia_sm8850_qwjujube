void affinity_initialize_workfn()
{
  __int64 v0; // x28
  unsigned int v2; // w23
  __int64 v3; // x0
  __int64 *v4; // x8
  __int64 v6; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v12; // x26
  __int64 v13; // x27
  const char **v14; // x8
  __int64 first_bit; // x0
  __int64 *v16; // x8
  __int64 v17; // x8
  unsigned __int64 v18; // x8
  unsigned int v19; // w8
  unsigned __int64 v20; // x27
  __int64 v21; // x0
  __int64 *v22; // x8
  __int64 v23; // x0
  unsigned int v25; // w8
  unsigned __int64 v26; // [xsp+8h] [xbp-18h]
  _QWORD v27[2]; // [xsp+10h] [xbp-10h] BYREF

  v0 = 0;
  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27[0] = 0;
  if ( byte_7B4E == 1 )
  {
    __dmb(9u);
    v0 = gic_routing_data[0];
  }
  if ( nr_irqs >= 2 )
  {
    _X21 = &dword_7B50;
    v2 = 1;
    while ( 1 )
    {
      __asm { PRFM            #0x11, [X21] }
      do
        v25 = __ldxr((unsigned int *)&dword_7B50);
      while ( __stlxr(v25, (unsigned int *)&dword_7B50) );
      __dmb(0xBu);
      if ( v25 )
        goto LABEL_40;
      __dmb(0xBu);
      StatusReg = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      _rcu_read_lock();
      v6 = irq_to_desc(v2);
      if ( v6 )
        break;
LABEL_11:
      _rcu_read_unlock(v6);
      _WriteStatusReg(DAIF, StatusReg);
      if ( (int)++v2 >= nr_irqs )
        goto LABEL_39;
    }
    v12 = v6;
    raw_spin_lock(v6 + 172);
    v13 = *(_QWORD *)(v12 + 56);
    if ( (unsigned __int64)(v13 - 1020) >= 0xFFFFFFFFFFFFFC24LL )
    {
      v14 = *(const char ***)(v12 + 72);
      if ( v14 )
      {
        if ( v0 )
        {
          if ( v14 == (const char **)v0 )
            goto LABEL_18;
        }
        else if ( !strcmp(*v14, "GICv3") )
        {
LABEL_18:
          if ( find_first_bit(&gic_saved_class0, 1020) == 1020 )
          {
            first_bit = find_first_bit(&gic_saved_class0, 1020);
            v16 = (__int64 *)(v12 + 24);
            if ( first_bit != 1020 )
              v16 = &qword_7B30;
            v17 = *v16;
            v27[0] = v17;
LABEL_22:
            v18 = (unsigned int)v17 & _cpu_online_mask;
            _ZF = (_DWORD)v18 == 0;
            v19 = __clz(__rbit64(v18));
            if ( _ZF )
              v19 = 32;
            if ( v19 >= nr_cpu_ids )
              v27[0] = _cpu_online_mask;
            if ( (unsigned int)irq_do_set_affinity(v12 + 48, v27, 0)
              && (unsigned int)__ratelimit(&affinity_initialize_workfn__rs, "affinity_initialize_workfn") )
            {
              printk(&unk_8198, "affinity_initialize_workfn");
            }
LABEL_10:
            v6 = raw_spin_unlock(v12 + 172);
            goto LABEL_11;
          }
          v20 = (unsigned int)(v13 - 32);
          raw_spin_lock(&gic_class_lock);
          if ( ((*(_QWORD *)((char *)&active_gic_class0 + ((v20 >> 3) & 0x1FFFFFF8)) >> v20) & 1) != 0 )
          {
            v26 = *(_QWORD *)((char *)&active_gic_class1 + ((v20 >> 3) & 0x1FFFFFF8));
            raw_spin_unlock(&gic_class_lock);
            v21 = find_first_bit(&gic_saved_class0, 1020);
            v22 = (__int64 *)(v12 + 24);
            if ( v21 != 1020 )
              v22 = &qword_7B30;
            v17 = *v22;
            v27[0] = v17;
            if ( ((v26 >> v20) & 1) != 0 )
              goto LABEL_10;
            goto LABEL_22;
          }
          raw_spin_unlock(&gic_class_lock);
          v23 = find_first_bit(&gic_saved_class0, 1020);
          v4 = (__int64 *)(v12 + 24);
          _ZF = v23 == 1020;
LABEL_7:
          if ( !_ZF )
            v4 = &qword_7B30;
          v27[0] = *v4;
          goto LABEL_10;
        }
      }
    }
    v3 = find_first_bit(&gic_saved_class0, 1020);
    v4 = (__int64 *)(v12 + 24);
    _ZF = v3 == 1020;
    goto LABEL_7;
  }
LABEL_39:
  __dmb(0xBu);
  dword_7B54 = 1;
LABEL_40:
  _ReadStatusReg(SP_EL0);
}
