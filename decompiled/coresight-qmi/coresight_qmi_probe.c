unsigned __int64 __fastcall coresight_qmi_probe(_QWORD *a1)
{
  _QWORD *v1; // x19
  unsigned __int64 result; // x0
  _QWORD *v4; // x0
  _QWORD *v5; // x21
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x9
  unsigned __int64 v9; // x0
  unsigned int v10; // w20
  unsigned __int64 v11; // x20
  _QWORD v12[2]; // [xsp+8h] [xbp-58h] BYREF
  void *v13; // [xsp+18h] [xbp-48h]
  __int64 v14; // [xsp+20h] [xbp-40h]
  _QWORD *v15; // [xsp+28h] [xbp-38h]
  __int64 v16; // [xsp+30h] [xbp-30h]
  __int64 v18; // [xsp+40h] [xbp-20h]
  __int64 v19; // [xsp+48h] [xbp-18h]
  __int64 v20; // [xsp+50h] [xbp-10h]
  __int64 v21; // [xsp+58h] [xbp-8h]

  v1 = a1 + 2;
  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v20 = 0;
  v18 = 0;
  v15 = nullptr;
  v16 = 0;
  v13 = nullptr;
  v14 = 0;
  v12[0] = 0;
  v12[1] = 0;
  if ( !coresight_alloc_device_name(&qmi_devs, a1 + 2) )
    goto LABEL_8;
  result = coresight_get_platform_data(v1);
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_9;
  a1[20] = result;
  v4 = (_QWORD *)devm_kmalloc(v1, 392, 3520);
  if ( !v4 )
  {
LABEL_8:
    result = 4294967284LL;
    goto LABEL_9;
  }
  v5 = v4;
  *v4 = v1;
  v6 = a1[95];
  a1[21] = v5;
  result = of_property_read_variable_u32_array(v6, "qcom,inst-id", v5 + 46, 1, 0);
  if ( (result & 0x80000000) == 0 )
  {
    _mutex_init(v5 + 2, "&drvdata->mutex", &coresight_qmi_probe___key);
    v7 = qmi_handle_init(v5 + 8, 7, server_ops, 0);
    if ( (v7 & 0x80000000) != 0 )
    {
      v11 = v7;
      dev_err(v1, "qmi client init failed ret:%d\n", v7);
      result = v11;
    }
    else
    {
      qmi_add_lookup(v5 + 8, 51, 1, *((unsigned int *)v5 + 92));
      v8 = a1[20];
      LODWORD(v12[0]) = 4;
      v14 = v8;
      v15 = v1;
      v13 = &qmi_ops;
      v9 = coresight_register(v12);
      v5[1] = v9;
      if ( v9 < 0xFFFFFFFFFFFFF001LL )
      {
        dev_info(v1, "qmi initialized\n");
        result = 0;
      }
      else
      {
        v10 = v9;
        qmi_handle_release(v5 + 8);
        result = v10;
      }
    }
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
