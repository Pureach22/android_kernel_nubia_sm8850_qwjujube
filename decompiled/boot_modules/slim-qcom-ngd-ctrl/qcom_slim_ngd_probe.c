__int64 __fastcall qcom_slim_ngd_probe(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x21
  unsigned int v4; // w0
  int v5; // w8
  __int64 v6; // x0
  int v7; // w0
  __int64 result; // x0
  unsigned int v9; // w20
  unsigned int v10; // w19
  int v11; // w20
  unsigned int v12; // w2
  __int64 v13; // x0
  unsigned int v20; // w9

  v2 = a1 + 16;
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 112) + 152LL);
  *(_QWORD *)(v3 + 928) = a1 + 16;
  v4 = slim_register_controller(v3 + 928);
  if ( v4 )
  {
    v9 = v4;
    dev_err(v2, "error adding slim controller\n");
    return v9;
  }
  *(_QWORD *)(a1 + 168) = v3;
  _pm_runtime_use_autosuspend(v2, 1);
  pm_runtime_set_autosuspend_delay(v2, 100);
  _pm_runtime_set_status(v2, 2);
  pm_runtime_enable(v2);
  _X8 = (unsigned int *)(a1 + 496);
  __asm { PRFM            #0x11, [X8] }
  do
    v20 = __ldxr(_X8);
  while ( __stxr(v20 + 1, _X8) );
  _slimbus_dbg();
  v5 = *(_DWORD *)(v3 + 5476);
  if ( v5 >= 3 )
  {
    ipc_log_string(
      *(_QWORD *)(v3 + 5488),
      "SLIM %s:PM get_noresume count:%d\n",
      "qcom_slim_ngd_probe",
      *(_DWORD *)(*(_QWORD *)(v3 + 928) + 480LL));
    v5 = *(_DWORD *)(v3 + 5476);
  }
  if ( !v5 )
    ipc_log_string(
      *(_QWORD *)(v3 + 5496),
      "SLIM %s:PM get_noresume count:%d\n",
      "qcom_slim_ngd_probe",
      *(_DWORD *)(*(_QWORD *)(v3 + 928) + 480LL));
  *(_QWORD *)(v3 + 4944) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v3 + 4952) = v3 + 4952;
  *(_QWORD *)(v3 + 4960) = v3 + 4952;
  *(_QWORD *)(v3 + 4976) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v3 + 4968) = qcom_slim_ngd_master_worker;
  *(_QWORD *)(v3 + 4984) = v3 + 4984;
  *(_QWORD *)(v3 + 4992) = v3 + 4984;
  *(_QWORD *)(v3 + 5000) = qcom_slim_ngd_up_worker;
  v6 = alloc_workqueue(&unk_CAB9, 393226, 1, "ngd_master");
  *(_QWORD *)(v3 + 5008) = v6;
  if ( !v6 )
  {
    dev_err(v2, "Failed to start master worker\n");
    qmi_handle_release(v3 + 1608);
    if ( *(_QWORD *)(v3 + 5008) )
      destroy_workqueue();
    v10 = -12;
    goto LABEL_20;
  }
  v7 = qmi_handle_init(v3 + 1608, 0, qcom_slim_ngd_qmi_svc_event_ops, 0);
  if ( v7 < 0 )
  {
    v11 = v7;
    dev_err(*(_QWORD *)(v3 + 1968), "qmi_handle_init failed: %d\n", v7);
  }
  else
  {
    result = qmi_add_lookup(v3 + 1608, 769, 1, 0);
    if ( (result & 0x80000000) == 0 )
    {
      if ( !(_DWORD)result )
        return result;
      goto LABEL_19;
    }
    v11 = result;
    dev_err(*(_QWORD *)(v3 + 1968), "qmi_add_lookup failed: %d\n", result);
    qmi_handle_release(v3 + 1608);
  }
  LODWORD(result) = v11;
LABEL_19:
  v12 = result;
  v13 = v2;
  v10 = v12;
  dev_err(v13, "QMI service registration failed:%d\n", v12);
LABEL_20:
  slim_unregister_controller(v3 + 928);
  return v10;
}
