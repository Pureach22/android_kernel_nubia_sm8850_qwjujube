__int64 __fastcall cnss_plat_ipc_qmi_init_setup_req_handler(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 *a4)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v5; // x22
  const char *v9; // x1
  int v10; // w10
  char v11; // w8
  __int64 result; // x0
  __int64 v13; // x7
  const char *v14; // x1
  char v15; // [xsp+0h] [xbp-20h]
  char v16; // [xsp+0h] [xbp-20h]
  _QWORD v17[3]; // [xsp+8h] [xbp-18h] BYREF

  StatusReg = _ReadStatusReg(SP_EL0);
  v5 = _ReadStatusReg(SP_EL0);
  v17[2] = *(_QWORD *)(StatusReg + 1808);
  v17[0] = 0;
  v17[1] = 0;
  if ( (*(_DWORD *)(v5 + 16) & 0xF0000) != 0 )
  {
    v9 = "irq";
  }
  else if ( (*(_DWORD *)(v5 + 16) & 0xFF00) != 0 )
  {
    v9 = "soft_irq";
  }
  else
  {
    v9 = (const char *)(v5 + 2320);
  }
  cnss_plat_ipc_debug_log_print(
    cnss_plat_ipc_log_context,
    v9,
    "cnss_plat_ipc_qmi_init_setup_req_handler",
    byte_82E1,
    "MAC: %d HW_TRC: %d CAL: %d\n",
    *a4,
    a4[1],
    *((unsigned int *)a4 + 1),
    v15);
  v10 = *((_DWORD *)a4 + 1);
  byte_7E01 = *a4;
  v11 = a4[1];
  dword_7E04 = v10;
  byte_7E02 = v11;
  daemon_cfg = 1;
  result = qmi_send_response(plat_ipc_qmi_svc[0], a2, a3, 1, 18, &cnss_plat_ipc_qmi_init_setup_resp_msg_v01_ei, v17);
  if ( (result & 0x80000000) != 0 )
  {
    if ( (*(_DWORD *)(v5 + 16) & 0xF0000) != 0 )
    {
      v14 = "irq";
    }
    else if ( (*(_DWORD *)(v5 + 16) & 0xFF00) != 0 )
    {
      v14 = "soft_irq";
    }
    else
    {
      v14 = (const char *)(v5 + 2320);
    }
    result = cnss_plat_ipc_debug_log_print(
               cnss_plat_ipc_log_context,
               v14,
               "cnss_plat_ipc_qmi_init_setup_req_handler",
               byte_80DC,
               "%s: QMI failed: %d\n",
               (__int64)"cnss_plat_ipc_qmi_init_setup_req_handler",
               result,
               v13,
               v16);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
