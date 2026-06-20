void qcom_wdt_trigger_bite()
{
  __int64 v0; // x0
  int v1; // w25
  unsigned int v2; // w20
  unsigned int v3; // w21
  unsigned int v4; // w22
  unsigned int v5; // w23
  unsigned int v6; // w26
  unsigned int v7; // w28
  unsigned int v8; // w19
  bool v9; // cf
  unsigned int v10; // w9
  int v11; // w10
  __int64 v12; // x0
  __int64 v13; // x27
  unsigned int v14; // w9
  _QWORD *v15; // x8
  void (*v16)(void); // x8
  void (__fastcall *v17)(_QWORD); // x8
  void (*v18)(void); // x8
  __int64 v19; // x19
  __int64 v20; // [xsp+0h] [xbp-70h]
  __int64 v21; // [xsp+8h] [xbp-68h]
  int v22; // [xsp+14h] [xbp-5Ch]
  _QWORD v23[2]; // [xsp+18h] [xbp-58h] BYREF
  __int64 v24; // [xsp+28h] [xbp-48h]
  __int64 v25; // [xsp+30h] [xbp-40h]
  __int64 v26; // [xsp+38h] [xbp-38h]
  __int64 v27; // [xsp+40h] [xbp-30h]
  __int64 v28; // [xsp+48h] [xbp-28h]
  __int64 v29; // [xsp+50h] [xbp-20h]
  __int64 v30; // [xsp+58h] [xbp-18h]
  __int64 v31; // [xsp+60h] [xbp-10h]
  __int64 v32; // [xsp+68h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( wdog_data )
  {
    v30 = 0;
    v31 = 0;
    v28 = 0;
    v29 = 0;
    v26 = 0;
    v27 = 0;
    v24 = 0;
    v25 = 0;
    v23[0] = 0;
    v23[1] = 0;
    v0 = nr_ipi_get();
    v1 = v0;
    v20 = sched_clock(v0);
    v21 = *(_QWORD *)(wdog_data + 40);
    _rcu_read_lock();
    if ( nr_irqs >= 1 )
    {
      v2 = 0;
      v3 = 0;
      v4 = 0;
      v5 = 0;
      v6 = 0;
      v7 = 0;
      v8 = 0;
      v22 = 0;
      while ( 1 )
      {
        if ( (int)v6 > v1 )
        {
          v12 = irq_to_desc(v6);
          if ( v12 )
          {
            v13 = v12;
            v14 = kstat_irqs_usr(v6) - *(_DWORD *)(v12 + 472);
            if ( v14 > v8 )
            {
              if ( ((16LL * v7) | 4uLL) > 0x50
                || (v15 = &v23[2 * v7], *((_DWORD *)v15 + 1) = v14, *(_DWORD *)v15 = v6, ((16LL * v7) | 8uLL) > 0x50) )
              {
                __break(1u);
                break;
              }
              v5 = HIDWORD(v23[0]);
              v4 = HIDWORD(v24);
              v3 = HIDWORD(v26);
              v2 = HIDWORD(v28);
              v9 = HIDWORD(v24) >= HIDWORD(v23[0]);
              v15[1] = v13;
              if ( v9 )
                v10 = v5;
              else
                v10 = v4;
              v11 = !v9;
              if ( v3 < v10 )
              {
                v10 = v3;
                v11 = 2;
              }
              if ( v2 < v10 )
              {
                v10 = v2;
                v11 = 3;
              }
              v22 = HIDWORD(v30);
              if ( HIDWORD(v30) >= v10 )
                v8 = v10;
              else
                v8 = HIDWORD(v30);
              if ( HIDWORD(v30) >= v10 )
                v7 = v11;
              else
                v7 = 4;
            }
          }
        }
        if ( (int)++v6 >= nr_irqs )
          goto LABEL_29;
      }
    }
    v22 = 0;
    v2 = 0;
    v3 = 0;
    v4 = 0;
    v5 = 0;
LABEL_29:
    _rcu_read_unlock();
    printk(&unk_7EB7, (v20 - v21) / 0xF4240uLL);
    if ( v5 )
    {
      printk(&unk_7E92, LODWORD(v23[0]));
      if ( !v4 )
      {
LABEL_31:
        if ( !v3 )
          goto LABEL_32;
        goto LABEL_37;
      }
    }
    else if ( !v4 )
    {
      goto LABEL_31;
    }
    printk(&unk_7E92, (unsigned int)v24);
    if ( !v3 )
    {
LABEL_32:
      if ( !v2 )
        goto LABEL_33;
      goto LABEL_38;
    }
LABEL_37:
    printk(&unk_7E92, (unsigned int)v26);
    if ( !v2 )
    {
LABEL_33:
      if ( !v22 )
      {
LABEL_40:
        dev_err(*(_QWORD *)(wdog_data + 8), "Causing a QCOM Apps Watchdog bite!\n");
        v16 = *(void (**)(void))(*(_QWORD *)(wdog_data + 16) + 40LL);
        if ( *((_DWORD *)v16 - 1) != 2060914831 )
          __break(0x8228u);
        v16();
        v17 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(wdog_data + 16) + 8LL);
        if ( *((_DWORD *)v17 - 1) != -872624411 )
          __break(0x8228u);
        v17(1);
        v18 = *(void (**)(void))(*(_QWORD *)(wdog_data + 16) + 16LL);
        if ( *((_DWORD *)v18 - 1) != 2060914831 )
          __break(0x8228u);
        v18();
        v19 = -10000;
        do
        {
          _const_udelay(4295000);
          v9 = __CFADD__(v19++, 1);
        }
        while ( !v9 );
        while ( 1 )
          _const_udelay(4295);
      }
LABEL_39:
      printk(&unk_7E92, (unsigned int)v30);
      goto LABEL_40;
    }
LABEL_38:
    printk(&unk_7E92, (unsigned int)v28);
    if ( !v22 )
      goto LABEL_40;
    goto LABEL_39;
  }
  _ReadStatusReg(SP_EL0);
}
