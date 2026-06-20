__int64 __fastcall ocp_notifier_probe(__int64 a1)
{
  __int64 v1; // x20
  _QWORD *v3; // x0
  _QWORD *v4; // x19
  unsigned __int64 v5; // x0
  unsigned int irq; // w23
  __int64 v7; // x0
  __int64 v8; // x8
  unsigned __int64 v9; // x0
  int v10; // w24
  int v11; // w9
  unsigned int v12; // w26
  int v13; // w0
  int v14; // w0
  unsigned __int64 v15; // x0
  unsigned int v16; // w22
  __int64 v17; // x0
  __int64 v18; // x8
  unsigned __int64 v19; // x0
  unsigned int v20; // w25
  int v21; // w0
  int v22; // w0
  unsigned __int64 v24; // [xsp+8h] [xbp-28h] BYREF
  int v25; // [xsp+14h] [xbp-1Ch] BYREF
  unsigned __int64 v26; // [xsp+18h] [xbp-18h] BYREF
  int v27; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+28h] [xbp-8h]

  v1 = a1 + 16;
  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  v24 = 0;
  v3 = (_QWORD *)devm_kmalloc(a1 + 16, 80, 3520);
  if ( !v3 )
  {
    irq = -12;
    goto LABEL_40;
  }
  v4 = v3;
  *v3 = v1;
  v5 = devm_nvmem_cell_get(v1, "ocp_log");
  v4[4] = v5;
  if ( v5 < 0xFFFFFFFFFFFFF001LL )
  {
    irq = platform_get_irq(a1, 0);
    if ( (irq & 0x80000000) != 0 )
    {
      dev_err(v1, "failed to get OCP irq, ret=%d\n", irq);
      goto LABEL_40;
    }
    v7 = ipc_log_context_create(3, "regulator_ocp", 0);
    v8 = v4[4];
    v4[6] = v7;
    *(_QWORD *)(a1 + 168) = v4;
    v9 = nvmem_cell_read(v8, &v24);
    v10 = v9;
    if ( v9 >= 0xFFFFFFFFFFFFF001LL )
    {
      dev_err(v1, "failed to read OCP nvmem cell, ret=%d\n", v9);
LABEL_39:
      ipc_log_context_destroy(v4[6]);
      irq = v10;
      goto LABEL_40;
    }
    *((_DWORD *)v4 + 10) = v24 >> 1;
    kfree(v9);
    v11 = *((_DWORD *)v4 + 10);
    v4[1] = 0x1000000400000000LL;
    v4[2] = 0;
    v4[3] = 0;
    if ( v11 >= 1 )
    {
      v12 = 0;
      while ( 1 )
      {
        v13 = ocp_notifier_read_entry(v4, v4 + 4, v12, &v25);
        if ( v13 )
        {
          v10 = v13;
          goto LABEL_38;
        }
        v14 = ocp_notifier_log_event(v4, v4 + 4, &v25, "Regulator OCP event before kernel boot:");
        if ( v14 )
          break;
        if ( (signed int)++v12 >= *((_DWORD *)v4 + 10) )
          goto LABEL_13;
      }
      v10 = v14;
      if ( v14 != -517 )
        dev_err(v1, "failed to log OCP entry %d, ret=%d\n", v12, v14);
      goto LABEL_38;
    }
LABEL_13:
    v10 = devm_request_threaded_irq(v1, irq, 0, ocp_notifier_handler, 0x2000, "regulator-ocp", v4);
    if ( v10 )
    {
LABEL_38:
      idr_destroy(v4 + 1);
      goto LABEL_39;
    }
    v27 = 0;
    v26 = 0;
    v15 = devm_nvmem_cell_get(v1, "alarm_log");
    v4[7] = v15;
    if ( v15 >= 0xFFFFFFFFFFFFF001LL )
    {
      if ( (_DWORD)v15 == -517 )
      {
        v10 = -517;
        goto LABEL_38;
      }
      v4[7] = 0;
LABEL_33:
      irq = 0;
      goto LABEL_40;
    }
    v16 = platform_get_irq(a1, 1);
    if ( (v16 & 0x80000000) != 0 )
    {
      dev_err(v1, "failed to get alarm irq, ret=%d\n", v16);
      v10 = v16;
      goto LABEL_38;
    }
    v17 = ipc_log_context_create(3, "regulator_alarm", 0);
    v18 = v4[7];
    v4[9] = v17;
    v19 = nvmem_cell_read(v18, &v26);
    v10 = v19;
    if ( v19 >= 0xFFFFFFFFFFFFF001LL )
    {
      dev_err(v1, "failed to read alarm nvmem cell, ret=%d\n", v19);
    }
    else
    {
      *((_DWORD *)v4 + 16) = v26 >> 1;
      kfree(v19);
      if ( *((int *)v4 + 16) < 1 )
      {
LABEL_27:
        v10 = devm_request_threaded_irq(v1, v16, 0, alarm_notifier_handler, 0x2000, "regulator-alarm", v4);
        if ( v10 )
        {
LABEL_37:
          ipc_log_context_destroy(v4[9]);
          goto LABEL_38;
        }
        goto LABEL_33;
      }
      v20 = 0;
      while ( 1 )
      {
        v21 = ocp_notifier_read_entry(v4, v4 + 7, v20, &v27);
        if ( v21 )
        {
          v10 = v21;
          goto LABEL_37;
        }
        v22 = ocp_notifier_log_event(v4, v4 + 7, &v27, "Regulator alarm event before kernel boot:");
        if ( v22 )
          break;
        if ( (signed int)++v20 >= *((_DWORD *)v4 + 16) )
          goto LABEL_27;
      }
      v10 = v22;
      if ( v22 == -517 )
        goto LABEL_37;
      dev_err(v1, "failed to log alarm entry %d, ret=%d\n", v20, v22);
    }
    ipc_log_context_destroy(v4[9]);
    if ( v10 )
      goto LABEL_38;
    goto LABEL_33;
  }
  irq = v5;
  if ( (_DWORD)v5 == -517 )
    irq = -517;
  else
    dev_err(v1, "failed to get nvmem cell, ret=%d\n", (unsigned int)v5);
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return irq;
}
