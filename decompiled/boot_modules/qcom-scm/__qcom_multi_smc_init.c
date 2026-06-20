__int64 __fastcall _qcom_multi_smc_init(__int64 *a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 result; // x0
  __int64 *v6; // x8
  __int64 v7; // x21
  int convention; // w0
  __int64 v9; // x2
  __int16 v10; // w9
  int v11; // w1
  unsigned int v12; // w8
  unsigned int irq; // w8
  __int64 v14; // x8
  unsigned int v15; // w19
  __int64 v16; // x0
  __int64 parent; // x0
  __int64 v18; // x8
  unsigned int v19; // w0
  __int64 v20; // x2
  __int64 v21; // x8
  __int64 v22; // [xsp+8h] [xbp-D8h] BYREF
  __int64 v23; // [xsp+10h] [xbp-D0h]
  __int64 v24; // [xsp+18h] [xbp-C8h]
  __int64 v25; // [xsp+20h] [xbp-C0h]
  __int64 v26; // [xsp+28h] [xbp-B8h]
  __int64 v27; // [xsp+30h] [xbp-B0h]
  __int64 v28; // [xsp+38h] [xbp-A8h]
  __int64 v29; // [xsp+40h] [xbp-A0h]
  __int64 v30; // [xsp+48h] [xbp-98h]
  __int64 v31; // [xsp+50h] [xbp-90h]
  __int64 v32; // [xsp+58h] [xbp-88h] BYREF
  __int64 v33; // [xsp+60h] [xbp-80h]
  __int64 v34; // [xsp+68h] [xbp-78h]
  _QWORD v35[12]; // [xsp+70h] [xbp-70h] BYREF
  int v36; // [xsp+D0h] [xbp-10h]
  int v37; // [xsp+D4h] [xbp-Ch]
  __int64 v38; // [xsp+D8h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *((_DWORD *)a1 + 54) = 0;
  a1[24] = 0x1000000400000000LL;
  a1[25] = 0;
  v4 = *a1;
  a1[26] = 0;
  result = of_device_is_compatible(*(_QWORD *)(v4 + 744), "qcom,scm-v1.1");
  if ( (_DWORD)result )
  {
    a1[28] = 0xFFFFFFFE00000LL;
    a1[29] = (__int64)(a1 + 29);
    a1[30] = (__int64)(a1 + 29);
    a1[31] = (__int64)scm_irq_work;
    v37 = 0;
    v34 = 0;
    v35[0] = 0x400000024LL;
    v36 = 2;
    v6 = (__int64 *)_scm;
    memset(&v35[1], 0, 88);
    v32 = 0;
    v33 = 0;
    v30 = 0;
    v31 = 0;
    v28 = 0;
    v29 = 0;
    v26 = 0;
    v27 = 0;
    v24 = 0;
    v25 = 0;
    v23 = 0;
    *((_DWORD *)a1 + 68) = 0;
    v7 = *v6;
    convention = _get_convention();
    if ( (unsigned int)(convention - 2) < 2 )
    {
      if ( (unsigned int)_scm_smc_call(v7, v35, qcom_scm_convention, &v32, 1) )
        goto LABEL_22;
LABEL_7:
      v10 = v33;
      v11 = (unsigned __int16)v33;
      a1[32] = (unsigned __int8)v32;
      v12 = v11 - 32;
      *((_DWORD *)a1 + 68) = 1;
      if ( (unsigned int)(v11 - 32) <= 0x3DB )
      {
        HIDWORD(v23) = 0;
      }
      else
      {
        if ( (v10 & 0xFC00) != 0x1000 )
        {
          _warn_printk("Unexpected virq: %d\n", v11);
          __break(0x800u);
          goto LABEL_10;
        }
        HIDWORD(v23) = 2;
        v12 = v11 - 4096;
      }
      v24 = v12 | 0x100000000LL;
      LODWORD(v23) = 3;
      parent = of_irq_find_parent(*(_QWORD *)(*(_QWORD *)_scm + 744LL));
      v18 = parent + 24;
      if ( !parent )
        v18 = 0;
      v22 = v18;
      v19 = irq_create_fwspec_mapping(&v22);
      v20 = *((unsigned int *)a1 + 68);
      a1[33] = v19;
      printk(&unk_129F0, "qcom_scm_query_wq_queue_info", v20);
      v21 = a1[32];
      qcom_scm_sem_lock = 0;
      dword_72C = v21;
      irq = *((_DWORD *)a1 + 66);
      off_730 = &off_730;
      off_738 = &off_730;
      goto LABEL_11;
    }
    if ( convention == 1 )
    {
      if ( !(unsigned int)((__int64 (__fastcall *)(__int64, _QWORD *, __int64 *))scm_legacy_call_atomic)(v7, v35, &v32) )
        goto LABEL_7;
    }
    else
    {
      printk(&unk_124E9, "qcom_scm_call_atomic", v9);
    }
LABEL_22:
    printk(&unk_12026, "qcom_scm_query_wq_queue_info", "qcom_scm_query_wq_queue_info");
LABEL_10:
    irq = platform_get_irq(a2, 0);
    if ( (irq & 0x80000000) != 0 )
    {
      v16 = *a1;
      v15 = irq;
      dev_err(v16, "WQ IRQ is not specified: %d\n", irq);
      goto LABEL_16;
    }
LABEL_11:
    result = devm_request_threaded_irq(*a1, irq, qcom_scm_irq_handler, 0, 0x2000, "qcom-scm", a1);
    if ( (result & 0x80000000) == 0 )
      goto LABEL_12;
    v14 = *a1;
    v15 = result;
    dev_err(v14, "Failed to request qcom-scm irq: %d\n", (unsigned int)result);
LABEL_16:
    result = v15;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
