__int64 __fastcall qmi_ts_send_request(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        _WORD *a8)
{
  unsigned int v16; // w0
  unsigned int v17; // w21
  unsigned int v18; // w0
  void *v20; // x0
  _QWORD v21[10]; // [xsp+0h] [xbp-50h] BYREF

  v21[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v21, 0, 72);
  mutex_lock(a1 + 312);
  v16 = qmi_txn_init(a1 + 8, v21, a5, a7);
  if ( (v16 & 0x80000000) != 0 )
  {
    v17 = v16;
    v20 = &unk_84AA;
LABEL_10:
    printk(v20, "qti_qmi_sensor_v2", "qmi_ts_send_request");
    goto LABEL_5;
  }
  v17 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD *, _QWORD, __int64, __int64, __int64))qmi_send_request)(
          a1 + 8,
          0,
          v21,
          a2,
          a3,
          a4,
          a6);
  if ( (v17 & 0x80000000) != 0 )
  {
    printk(&unk_83CC, "qti_qmi_sensor_v2", "qmi_ts_send_request");
    qmi_txn_cancel(v21);
    goto LABEL_5;
  }
  v18 = qmi_txn_wait(v21, 25);
  if ( (v18 & 0x80000000) != 0 )
  {
    v17 = v18;
    v20 = &unk_82A3;
    goto LABEL_10;
  }
  v17 = (unsigned __int16)*a8;
  if ( *a8 )
  {
    v20 = &unk_8608;
    goto LABEL_10;
  }
LABEL_5:
  mutex_unlock(a1 + 312);
  _ReadStatusReg(SP_EL0);
  return v17;
}
