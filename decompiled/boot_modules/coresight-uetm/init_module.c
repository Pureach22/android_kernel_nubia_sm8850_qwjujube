__int64 init_module()
{
  unsigned __int64 qcom_scmi_device; // x0
  unsigned int v1; // w19
  __int64 (*v2)(void); // x8
  unsigned __int64 v3; // x0
  __int64 v4; // x1
  _DWORD *v5; // x9
  __int64 v6; // x0
  int v7; // w0
  int v8; // w8
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qcom_scmi_device = get_qcom_scmi_device();
  v1 = qcom_scmi_device;
  sdev = qcom_scmi_device;
  if ( qcom_scmi_device > 0xFFFFFFFFFFFFF000LL )
  {
    printk(&unk_80A8, (unsigned int)qcom_scmi_device);
    if ( v1 )
      goto LABEL_11;
  }
  else
  {
    v2 = *(__int64 (**)(void))(*(_QWORD *)(qcom_scmi_device + 928) + 24LL);
    if ( *((_DWORD *)v2 - 1) != -1171826031 )
      __break(0x8228u);
    v3 = v2();
    ops = v3;
    if ( v3 >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_8049, v4);
      v1 = -14;
      goto LABEL_11;
    }
    v5 = *(_DWORD **)(v3 + 8);
    v6 = ph;
    v10 = 0;
    if ( *(v5 - 1) != 1134762728 )
      __break(0x8229u);
    v7 = ((__int64 (__fastcall *)(__int64, int *, __int64, __int64, _QWORD, __int64))v5)(v6, &v10, 1430606925, 1, 0, 4);
    v8 = v10;
    if ( v7 )
      v8 = v7;
    uetm_cnt = v8 & ~(v8 >> 31);
  }
  v1 = _platform_driver_register(uetm_driver, &_this_module);
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return v1;
}
