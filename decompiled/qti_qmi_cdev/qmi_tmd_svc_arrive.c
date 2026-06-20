__int64 __fastcall qmi_tmd_svc_arrive(__int64 a1)
{
  __int64 result; // x0
  unsigned __int16 *v3; // x19
  unsigned int v4; // w0
  unsigned int v5; // w0
  __int64 v6; // x4
  unsigned __int64 v7; // x27
  const char *v8; // x28
  __int64 v9; // x1
  unsigned __int64 v10; // x0
  unsigned __int64 v11; // x26
  const char *v12; // x27
  __int64 v13; // x1
  unsigned __int64 v14; // x0
  __int64 v15; // x3
  void *v16; // x0
  _QWORD v17[9]; // [xsp+8h] [xbp-58h] BYREF
  _BYTE v18[4]; // [xsp+54h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+58h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v17, 0, sizeof(v17));
  v18[0] = 0;
  result = _kmalloc_cache_noprof(queue_work_on, 3520, 3284);
  v3 = (unsigned __int16 *)result;
  if ( result )
  {
    mutex_lock(a1 - 72);
    v4 = qmi_txn_init(a1 - 376, v17, &tmd_get_mitigation_device_list_resp_msg_v01_ei, v3);
    if ( (v4 & 0x80000000) != 0 )
    {
      v15 = *(unsigned int *)(a1 - 24);
      v6 = v4;
      v16 = &unk_7FDD;
    }
    else
    {
      if ( (qmi_send_request(a1 - 376, 0, v17, 32, 0, &tmd_get_mitigation_device_list_req_msg_v01_ei, v18) & 0x80000000) != 0 )
      {
        qmi_txn_cancel(v17);
LABEL_18:
        mutex_unlock(a1 - 72);
LABEL_32:
        result = kfree(v3);
        goto LABEL_33;
      }
      v5 = qmi_txn_wait(v17, 25);
      if ( (v5 & 0x80000000) != 0 )
      {
        v15 = *(unsigned int *)(a1 - 24);
        v6 = v5;
        v16 = &unk_803C;
      }
      else
      {
        v6 = *v3;
        if ( !*v3 )
        {
          mutex_unlock(a1 - 72);
          if ( *((_DWORD *)v3 + 2) )
          {
            v7 = 0;
            do
            {
              v8 = (const char *)(a1 - 16);
              do
              {
                v8 = *(const char **)v8;
                if ( v8 == (const char *)(a1 - 16) )
                  goto LABEL_8;
                if ( v7 >= 0x21 )
                {
LABEL_38:
                  __break(0x5512u);
LABEL_39:
                  __break(1u);
                }
              }
              while ( strncasecmp(v8 - 40, (const char *)&v3[17 * v7 + 6], 0x20u) );
              *((_BYTE *)v8 - 8) = 1;
              if ( 34 * v7 > 0xCA7 )
                goto LABEL_39;
              v9 = *((unsigned int *)v8 + 6);
              *((_DWORD *)v8 + 7) = HIBYTE(v3[17 * v7 + 22]);
              qmi_tmd_send_state_request(v8 - 80, v9);
              if ( !*((_QWORD *)v8 + 2) )
              {
                v10 = thermal_of_cooling_device_register(*((_QWORD *)v8 - 10), v8 - 72, v8 - 80, qmi_device_ops);
                *((_QWORD *)v8 + 2) = v10;
                if ( v10 >= 0xFFFFFFFFFFFFF001LL )
                  printk(&unk_81DE, "qti_qmi_cdev", "qmi_register_cooling_device", v8 - 72, v10);
              }
LABEL_8:
              ++v7;
            }
            while ( v7 < *((unsigned int *)v3 + 2) );
          }
          if ( *((_BYTE *)v3 + 1100) )
          {
            v11 = 0;
            while ( v11 < *((unsigned int *)v3 + 276) )
            {
              v12 = (const char *)(a1 - 16);
              do
              {
                v12 = *(const char **)v12;
                if ( v12 == (const char *)(a1 - 16) )
                  goto LABEL_21;
                if ( v11 > 0x40 )
                  goto LABEL_38;
              }
              while ( strncasecmp(v12 - 40, (const char *)&v3[17 * v11 + 554], 0x20u) );
              *((_BYTE *)v12 - 8) = 1;
              if ( v11 == 64 || 34 * v11 > 0x85F )
                goto LABEL_39;
              v13 = *((unsigned int *)v12 + 6);
              *((_DWORD *)v12 + 7) = HIBYTE(v3[17 * v11 + 570]);
              qmi_tmd_send_state_request(v12 - 80, v13);
              if ( !*((_QWORD *)v12 + 2) )
              {
                v14 = thermal_of_cooling_device_register(*((_QWORD *)v12 - 10), v12 - 72, v12 - 80, qmi_device_ops);
                *((_QWORD *)v12 + 2) = v14;
                if ( v14 >= 0xFFFFFFFFFFFFF001LL )
                  printk(&unk_81DE, "qti_qmi_cdev", "qmi_register_cooling_device", v12 - 72, v14);
              }
LABEL_21:
              ++v11;
              if ( !*((_BYTE *)v3 + 1100) )
                goto LABEL_32;
            }
          }
          goto LABEL_32;
        }
        v15 = *(unsigned int *)(a1 - 24);
        v16 = &unk_7F67;
      }
    }
    printk(v16, "qti_qmi_cdev", "verify_devices_and_register", v15, v6);
    goto LABEL_18;
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
