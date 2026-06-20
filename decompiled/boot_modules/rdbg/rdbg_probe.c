__int64 __fastcall rdbg_probe(__int64 a1)
{
  char *v2; // x19
  __int64 v3; // x27
  __int64 v4; // x21
  __int64 v5; // x22
  __int64 v6; // x28
  unsigned __int64 v7; // x0
  __int64 v8; // x28
  _DWORD *v9; // x24
  int byname; // w0
  unsigned int v11; // w28
  unsigned __int64 StatusReg; // x21
  __int64 v14; // x22
  __int64 (__fastcall *v15)(_QWORD, _QWORD, _QWORD); // x0

  v2 = (char *)_kmalloc_cache_noprof(qcom_smem_state_get, 3520, 32);
  if ( v2 )
  {
    while ( dword_104 >= 1 )
    {
      v3 = 0;
      v4 = 0;
      v5 = 80;
      while ( v3 != 384 )
      {
        if ( *(_QWORD *)((char *)&proc_info + v3) )
        {
          if ( snprintf(v2, 0x20u, "%s%d-out", "qcom,smp2p-interrupt-rdbg-", v4) <= 0 )
            goto LABEL_21;
          if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 760), v2) )
          {
            v6 = qword_108;
            if ( qword_108 + v5 == 16 )
            {
              v11 = -22;
LABEL_25:
              printk(&unk_7935);
              goto LABEL_23;
            }
            if ( of_find_property(*(_QWORD *)(a1 + 760), "qcom,smem-states", 0) )
            {
              v7 = qcom_smem_state_get(a1 + 16, "rdbg-smp2p-out", v6 + v5 - 8);
              *(_QWORD *)(v6 + v5) = v7;
              if ( !v7 || v7 >= 0xFFFFFFFFFFFFF001LL )
              {
                printk(&unk_7794);
                v11 = *(_DWORD *)(v6 + v5);
                if ( v11 )
                  goto LABEL_25;
              }
            }
          }
          if ( snprintf(v2, 0x20u, "%s%d-in", "qcom,smp2p-interrupt-rdbg-", v4) <= 0 )
          {
LABEL_21:
            printk(&unk_76B3);
            goto LABEL_22;
          }
          if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 760), v2) )
          {
            v8 = qword_108 + v5;
            v9 = (_DWORD *)(qword_108 + v5 - 40);
            if ( qword_108 + v5 == 40 )
            {
              printk(&unk_780A);
            }
            else
            {
              byname = of_irq_get_byname(*(_QWORD *)(a1 + 760), "rdbg-smp2p-in");
              *v9 = byname;
              *(_DWORD *)(v8 - 36) = byname;
            }
          }
        }
        ++v4;
        v3 += 24;
        v5 += 456;
        if ( v4 >= dword_104 )
          goto LABEL_20;
      }
      __break(0x5512u);
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v14 = *(_QWORD *)(StatusReg + 80);
      v15 = qcom_smem_state_get;
      *(_QWORD *)(StatusReg + 80) = &rdbg_probe__alloc_tag;
      v2 = (char *)_kmalloc_cache_noprof(v15, 3520, 32);
      *(_QWORD *)(StatusReg + 80) = v14;
      if ( !v2 )
        goto LABEL_22;
    }
LABEL_20:
    v11 = 0;
  }
  else
  {
LABEL_22:
    v11 = -12;
  }
LABEL_23:
  kfree(v2);
  return v11;
}
