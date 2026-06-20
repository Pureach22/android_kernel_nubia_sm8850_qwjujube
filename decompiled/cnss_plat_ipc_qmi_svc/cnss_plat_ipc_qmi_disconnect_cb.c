__int64 __fastcall cnss_plat_ipc_qmi_disconnect_cb(
        __int64 result,
        unsigned int a2,
        unsigned int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 v8; // x8
  const char *v9; // x1
  unsigned __int64 StatusReg; // x8
  const char *v13; // x1
  __int16 v14; // w9
  const char *v15; // x8
  __int16 v16; // w9
  const char *v17; // x8
  __int64 next; // x0
  unsigned int v19; // w8
  __int64 (__fastcall *v20)(__int64, __int64); // x9
  __int64 v21; // x0
  __int64 v22; // x1
  unsigned __int64 v23; // x8
  const char *v24; // x1
  __int16 v25; // w9
  const char *v26; // x8
  __int64 v27; // x0
  unsigned int v28; // w8
  __int64 (__fastcall *v29)(__int64, __int64); // x9
  __int64 v30; // x0
  __int64 v31; // x1
  char v32; // [xsp+0h] [xbp-20h]
  int i; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v34; // [xsp+18h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  i = 0;
  if ( plat_ipc_qmi_svc[0] == result )
  {
    if ( byte_7DB4 == 1 && qword_7DAC == __PAIR64__(a3, a2) )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v13 = "irq";
      }
      else
      {
        v16 = *(_DWORD *)(StatusReg + 16);
        v17 = (const char *)(StatusReg + 2320);
        v13 = (v16 & 0xFF00) != 0 ? "soft_irq" : v17;
      }
      cnss_plat_ipc_debug_log_print(
        cnss_plat_ipc_log_context,
        v13,
        "cnss_plat_ipc_qmi_disconnect_cb",
        byte_80DC,
        "%s: QMI client disconnect. QMI Socket Node:%d Port:%d ID: %d\n",
        (__int64)"cnss_plat_ipc_qmi_disconnect_cb",
        a2,
        a3,
        0);
      word_7DA8 = 0;
      qword_7DAC = 0;
      byte_7DB4 = 0;
      mutex_lock(&unk_7D78);
      for ( i = 0; ; ++i )
      {
        next = idr_get_next(&qword_7D60, &i);
        if ( !next )
          break;
        complete(next + 40);
      }
      result = mutex_unlock(&unk_7D78);
      v19 = dword_7DC8;
      if ( dword_7DC8 )
      {
        v20 = (__int64 (__fastcall *)(__int64, __int64))off_7DB8;
        if ( off_7DB8 )
        {
          v21 = qword_7DC0;
          v22 = (unsigned __int8)byte_7DB4;
          if ( *((_DWORD *)off_7DB8 - 1) != -538254584 )
            __break(0x8229u);
          result = v20(v21, v22);
          v19 = dword_7DC8;
        }
        if ( v19 > 1 )
          goto LABEL_41;
      }
    }
    if ( byte_7DDC == 1 && qword_7DD4 == __PAIR64__(a3, a2) )
    {
      v23 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v23 + 16) & 0xF0000) != 0 )
      {
        v24 = "irq";
      }
      else
      {
        v25 = *(_DWORD *)(v23 + 16);
        v26 = (const char *)(v23 + 2320);
        v24 = (v25 & 0xFF00) != 0 ? "soft_irq" : v26;
      }
      cnss_plat_ipc_debug_log_print(
        cnss_plat_ipc_log_context,
        v24,
        "cnss_plat_ipc_qmi_disconnect_cb",
        byte_80DC,
        "%s: QMI client disconnect. QMI Socket Node:%d Port:%d ID: %d\n",
        (__int64)"cnss_plat_ipc_qmi_disconnect_cb",
        a2,
        a3,
        1);
      word_7DD0 = 0;
      qword_7DD4 = 0;
      byte_7DDC = 0;
      mutex_lock(&unk_7D78);
      for ( i = 0; ; ++i )
      {
        v27 = idr_get_next(&qword_7D60, &i);
        if ( !v27 )
          break;
        complete(v27 + 40);
      }
      result = mutex_unlock(&unk_7D78);
      v28 = dword_7DF0;
      if ( dword_7DF0 )
      {
        v29 = (__int64 (__fastcall *)(__int64, __int64))off_7DE0;
        if ( off_7DE0 )
        {
          v30 = qword_7DE8;
          v31 = (unsigned __int8)byte_7DDC;
          if ( *((_DWORD *)off_7DE0 - 1) != -538254584 )
            __break(0x8229u);
          result = v29(v30, v31);
          v28 = dword_7DF0;
        }
        if ( v28 > 1 )
LABEL_41:
          __break(0x5512u);
      }
    }
  }
  else
  {
    v8 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v8 + 16) & 0xF0000) != 0 )
    {
      v9 = "irq";
    }
    else
    {
      v14 = *(_DWORD *)(v8 + 16);
      v15 = (const char *)(v8 + 2320);
      if ( (v14 & 0xFF00) != 0 )
        v9 = "soft_irq";
      else
        v9 = v15;
    }
    result = cnss_plat_ipc_debug_log_print(
               cnss_plat_ipc_log_context,
               v9,
               "cnss_plat_ipc_qmi_disconnect_cb",
               byte_80DC,
               "Invalid QMI Handle\n",
               a6,
               a7,
               a8,
               v32);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
