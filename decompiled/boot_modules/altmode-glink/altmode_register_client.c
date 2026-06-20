__int64 __fastcall altmode_register_client(__int64 a1, __int16 *a2)
{
  __int64 result; // x0
  __int64 v4; // x0
  __int64 v6; // x19
  int v7; // w0
  __int64 device_by_node; // x0
  __int64 v9; // x20
  __int64 v10; // x0
  char v11; // w9
  __int16 v12; // w10
  __int64 v13; // x22
  __int64 v14; // x10
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x2
  int v18; // w0
  int v19; // w20
  int v20; // w19
  __int64 v21; // [xsp+8h] [xbp-58h] BYREF
  __int64 v22; // [xsp+10h] [xbp-50h]
  __int64 v23; // [xsp+18h] [xbp-48h]
  __int64 v24; // [xsp+20h] [xbp-40h]
  __int64 v25; // [xsp+28h] [xbp-38h]
  __int64 v26; // [xsp+30h] [xbp-30h]
  __int64 v27; // [xsp+38h] [xbp-28h]
  __int64 v28; // [xsp+40h] [xbp-20h]
  __int64 v29; // [xsp+48h] [xbp-18h]
  __int64 v30; // [xsp+50h] [xbp-10h]
  __int64 v31; // [xsp+58h] [xbp-8h]

  result = -22;
  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 || !*((_QWORD *)a2 + 1) || !*((_QWORD *)a2 + 2) || !*((_QWORD *)a2 + 3) || !*a2 )
    goto LABEL_24;
  v4 = *(_QWORD *)(a1 + 744);
  v29 = 0;
  v30 = 0;
  v6 = a1;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v7 = _of_parse_phandle_with_args(v4, "qcom,altmode-dev", "#altmode-cells", 0xFFFFFFFFLL, 0, &v21);
  if ( v7 )
  {
    v19 = v7;
    dev_err(v6, "Error parsing qcom,altmode-dev property: %d\n", v7);
    result = v19;
    goto LABEL_24;
  }
  if ( (_DWORD)v22 != 1 )
  {
    dev_err(v6, "Error in port_index specification\n");
    result = -22;
    goto LABEL_24;
  }
  if ( HIDWORD(v22) >= 4 )
  {
    dev_err(v6, "Invalid port_index: %d, max is %d\n", HIDWORD(v22), 3);
    result = -22;
    goto LABEL_24;
  }
  device_by_node = of_find_device_by_node(v21);
  if ( !device_by_node || (v9 = *(_QWORD *)(device_by_node + 168)) == 0 )
  {
    result = -517;
    goto LABEL_24;
  }
  v10 = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 112);
  if ( !v10 )
  {
LABEL_20:
    result = -12;
    goto LABEL_24;
  }
  v11 = BYTE4(v22);
  v12 = *a2;
  v13 = v10;
  *(_QWORD *)v10 = v9;
  *(_BYTE *)(v10 + 56) = v11;
  *(_WORD *)(v10 + 8) = v12;
  v14 = *((_QWORD *)a2 + 3);
  *(_QWORD *)(v10 + 24) = *((_QWORD *)a2 + 2);
  *(_QWORD *)(v10 + 32) = v14;
  *(_QWORD *)(v10 + 64) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v10 + 72) = v10 + 72;
  *(_QWORD *)(v10 + 80) = v10 + 72;
  v15 = *((_QWORD *)a2 + 1);
  *(_QWORD *)(v10 + 88) = client_cb_work;
  v16 = kstrdup(v15, 3264);
  *(_QWORD *)(v13 + 16) = v16;
  if ( !v16 )
  {
    kfree(v13);
    goto LABEL_20;
  }
  mutex_lock(v9 + 40);
  v17 = *(unsigned __int8 *)(v13 + 56) | (*(unsigned __int16 *)(v13 + 8) << 8);
  v18 = idr_alloc(v9 + 16, v13, v17, (unsigned int)(v17 + 1), 3264);
  if ( v18 < 0 )
  {
    v20 = v18;
    printk(&unk_74A3, "altmode_register_client");
    mutex_unlock(v9 + 40);
    kfree(*(_QWORD *)(v13 + 16));
    kfree(v13);
    result = v20;
  }
  else
  {
    list_add((_QWORD *)(v13 + 40), (_QWORD *)(v9 + 104));
    mutex_unlock(v9 + 40);
    if ( !*(_DWORD *)(v9 + 120) )
      queue_delayed_work_on(32, system_wq, v9 + 128, 5);
    result = v13;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
