__int64 __fastcall qcom_slim_ngd_runtime_resume(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x1
  int v3; // w8
  int v4; // w8
  __int64 v5; // x21
  int v6; // w8
  int v7; // w8
  int v8; // w8
  unsigned int v9; // w0
  unsigned int v10; // w20
  int v11; // w8
  int v12; // w8
  unsigned int v13; // w20
  int v14; // w0
  int v15; // w8
  __int64 v16; // x1
  int v17; // w8
  __int64 v18; // x1
  int v19; // w8
  int v20; // w8
  int v21; // w8
  int v22; // w8
  int v24; // w20
  unsigned int v25; // w21
  int v26; // w8

  v1 = *(_QWORD *)(a1 + 152);
  _slimbus_dbg();
  v3 = *(_DWORD *)(v1 + 5476);
  if ( v3 >= 3 )
  {
    ipc_log_string(*(_QWORD *)(v1 + 5488), "Slim runtime resume\n");
    v3 = *(_DWORD *)(v1 + 5476);
  }
  if ( !v3 )
    ipc_log_string(*(_QWORD *)(v1 + 5496), "Slim runtime resume\n");
  mutex_lock(v1 + 5200, v2);
  if ( !*(_QWORD *)(v1 + 1920) )
  {
    _slimbus_dbg();
    v12 = *(_DWORD *)(v1 + 5476);
    if ( v12 >= 2 )
    {
      printk(&unk_CA26, "qcom_slim_ngd_runtime_resume");
      ipc_log_string(*(_QWORD *)(v1 + 5488), "%s QMI handle is NULL\n", "qcom_slim_ngd_runtime_resume");
      if ( *(_DWORD *)(v1 + 5476) )
        goto LABEL_31;
    }
    else if ( v12 )
    {
LABEL_31:
      mutex_unlock(v1 + 5200);
      return 0;
    }
    ipc_log_string(*(_QWORD *)(v1 + 5496), "%s QMI handle is NULL\n", "qcom_slim_ngd_runtime_resume");
    goto LABEL_31;
  }
  if ( *(_BYTE *)(v1 + 5508) == 1 )
  {
    enable_irq(*(unsigned int *)(v1 + 5504));
    *(_BYTE *)(v1 + 5508) = 0;
    _slimbus_dbg();
    v4 = *(_DWORD *)(v1 + 5476);
    if ( v4 >= 3 )
    {
      ipc_log_string(*(_QWORD *)(v1 + 5488), "Slim ngd IRQ enabled\n");
      v4 = *(_DWORD *)(v1 + 5476);
    }
    if ( !v4 )
      ipc_log_string(*(_QWORD *)(v1 + 5496), "Slim ngd IRQ enabled\n");
  }
  if ( *(_DWORD *)(v1 + 5384) >= 2u )
  {
    v5 = *(_QWORD *)(v1 + 1960);
    _slimbus_dbg();
    v6 = *(_DWORD *)(v1 + 5476);
    if ( v6 >= 3 )
    {
      ipc_log_string(*(_QWORD *)(v1 + 5488), "SLIM: NGD power up\n");
      v6 = *(_DWORD *)(v1 + 5476);
    }
    if ( !v6 )
      ipc_log_string(*(_QWORD *)(v1 + 5496), "SLIM: NGD power up\n");
    v7 = *(_DWORD *)(v1 + 5384);
    if ( v7 == 3 )
    {
      if ( !(unsigned int)wait_for_completion_timeout(v1 + 1928, 250) )
      {
        _slimbus_dbg();
        v17 = *(_DWORD *)(v1 + 5476);
        if ( v17 >= 1 )
        {
          printk(&unk_D0AA, v16);
          ipc_log_string(*(_QWORD *)(v1 + 5488), "slimbus QMI init timed out\n");
          *(_QWORD *)(v1 + 5472) = *(unsigned int *)(v1 + 5476);
        }
        else if ( v17 )
        {
          goto LABEL_45;
        }
        ipc_log_string(*(_QWORD *)(v1 + 5496), "slimbus QMI init timed out\n");
LABEL_45:
        if ( *(_DWORD *)(v1 + 5384) == 3 )
        {
          _slimbus_dbg();
          v19 = *(_DWORD *)(v1 + 5476);
          if ( v19 < 2 )
          {
            if ( v19 )
              goto LABEL_50;
            goto LABEL_48;
          }
          printk(&unk_CBAD, v18);
          ipc_log_string(*(_QWORD *)(v1 + 5488), "HW wakeup attempt during SSR\n");
          if ( !*(_DWORD *)(v1 + 5476) )
LABEL_48:
            ipc_log_string(*(_QWORD *)(v1 + 5496), "HW wakeup attempt during SSR\n");
        }
        else
        {
          *(_DWORD *)(v1 + 5384) = 2;
        }
LABEL_50:
        _slimbus_dbg();
        v20 = *(_DWORD *)(v1 + 5476);
        if ( v20 >= 2 )
        {
          printk(&unk_C999, "qcom_slim_ngd_runtime_resume");
          ipc_log_string(
            *(_QWORD *)(v1 + 5488),
            "%s Power up request failed, try resume again\n",
            "qcom_slim_ngd_runtime_resume");
          if ( *(_DWORD *)(v1 + 5476) )
          {
LABEL_52:
            if ( (*(_BYTE *)(v1 + 5508) & 1) != 0 )
              goto LABEL_62;
            goto LABEL_58;
          }
        }
        else if ( v20 )
        {
          goto LABEL_52;
        }
        ipc_log_string(
          *(_QWORD *)(v1 + 5496),
          "%s Power up request failed, try resume again\n",
          "qcom_slim_ngd_runtime_resume");
        if ( (*(_BYTE *)(v1 + 5508) & 1) != 0 )
        {
LABEL_62:
          v13 = -11;
          goto LABEL_63;
        }
LABEL_58:
        disable_irq(*(unsigned int *)(v1 + 5504));
        *(_BYTE *)(v1 + 5508) = 1;
        _slimbus_dbg();
        v21 = *(_DWORD *)(v1 + 5476);
        if ( v21 >= 3 )
        {
          ipc_log_string(*(_QWORD *)(v1 + 5488), "Slim ngd IRQ disabled\n");
          v21 = *(_DWORD *)(v1 + 5476);
        }
        if ( !v21 )
          ipc_log_string(*(_QWORD *)(v1 + 5496), "Slim ngd IRQ disabled\n");
        goto LABEL_62;
      }
      v7 = *(_DWORD *)(v1 + 5384);
    }
    if ( (v7 & 0xFFFFFFFE) == 2 )
    {
      _slimbus_dbg();
      v8 = *(_DWORD *)(v1 + 5476);
      if ( v8 >= 3 )
      {
        ipc_log_string(*(_QWORD *)(v1 + 5488), "Sending QMI power on request\n");
        v8 = *(_DWORD *)(v1 + 5476);
      }
      if ( !v8 )
        ipc_log_string(*(_QWORD *)(v1 + 5496), "Sending QMI power on request\n");
      v9 = qcom_slim_qmi_power_request(v1, 1);
      if ( v9 )
      {
        v10 = v9;
        _slimbus_dbg();
        v11 = *(_DWORD *)(v1 + 5476);
        if ( v11 >= 1 )
        {
          printk(&unk_CA3F, v10);
          ipc_log_string(*(_QWORD *)(v1 + 5488), "SLIM QMI power request failed:%d\n", v10);
          *(_QWORD *)(v1 + 5472) = *(unsigned int *)(v1 + 5476);
        }
        else if ( v11 )
        {
          goto LABEL_45;
        }
        ipc_log_string(*(_QWORD *)(v1 + 5496), "SLIM QMI power request failed:%d\n", v10);
        goto LABEL_45;
      }
    }
    *(_DWORD *)(v1 + 5432) = (unsigned int)readl_relaxed(*(_QWORD *)(v1 + 1976)) >> 16;
    if ( (readl_relaxed(*(_QWORD *)(v5 + 8) + 4LL) & 2) != 0 )
    {
      qcom_slim_ngd_setup(v1);
    }
    else
    {
      *(_DWORD *)(v1 + 4880) = 0;
      writel_relaxed(4261412864LL, *(_QWORD *)(v5 + 8) + 16LL);
      v14 = readl_relaxed(*(_QWORD *)(v5 + 8) + 8LL);
      writel_relaxed(v14 | 0x10000u, *(_QWORD *)(v5 + 8) + 8LL);
      qcom_slim_ngd_setup(v1);
      if ( !(unsigned int)wait_for_completion_timeout(v1 + 4880, 2500) )
      {
        dev_err(*(_QWORD *)(v1 + 1968), "capability exchange timed-out\n");
        v24 = readl_relaxed(*(_QWORD *)(v5 + 8));
        v25 = readl_relaxed(*(_QWORD *)(v5 + 8) + 4LL);
        _slimbus_dbg();
        v26 = *(_DWORD *)(v1 + 5476);
        if ( v26 >= 2 )
        {
          printk(&unk_D882, v25);
          ipc_log_string(*(_QWORD *)(v1 + 5488), "slim capability time-out stat:0x%x,cfg:0x%x\n", v25, v24);
          if ( *(_DWORD *)(v1 + 5476) )
            goto LABEL_45;
        }
        else if ( v26 )
        {
          goto LABEL_45;
        }
        ipc_log_string(*(_QWORD *)(v1 + 5496), "slim capability time-out stat:0x%x,cfg:0x%x\n", v25, v24);
        goto LABEL_45;
      }
      if ( *(_DWORD *)(v1 + 5384) == 3 )
      {
        _slimbus_dbg();
        v15 = *(_DWORD *)(v1 + 5476);
        if ( v15 >= 3 )
        {
          ipc_log_string(*(_QWORD *)(v1 + 5488), "ADSP slimbus power up now\n");
          v15 = *(_DWORD *)(v1 + 5476);
        }
        if ( !v15 )
          ipc_log_string(*(_QWORD *)(v1 + 5496), "ADSP slimbus power up now\n");
        complete_all(v1 + 4912);
      }
    }
  }
  v13 = 0;
  *(_DWORD *)(v1 + 5384) = 0;
LABEL_63:
  mutex_unlock(v1 + 5200);
  _slimbus_dbg();
  v22 = *(_DWORD *)(v1 + 5476);
  if ( v22 >= 3 )
  {
    ipc_log_string(
      *(_QWORD *)(v1 + 5488),
      "Slim runtime resume: ret %d irq_disabled %d\n",
      v13,
      *(unsigned __int8 *)(v1 + 5508));
    v22 = *(_DWORD *)(v1 + 5476);
  }
  if ( !v22 )
    ipc_log_string(
      *(_QWORD *)(v1 + 5496),
      "Slim runtime resume: ret %d irq_disabled %d\n",
      v13,
      *(unsigned __int8 *)(v1 + 5508));
  return v13;
}
