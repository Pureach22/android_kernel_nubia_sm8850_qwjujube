__int64 __fastcall amoled_ecm_enable(_QWORD *a1)
{
  unsigned int v2; // w0
  int v3; // w8
  char *v4; // x21
  unsigned int v5; // w0
  __int64 v6; // x8
  __int64 v7; // x9
  char v8; // w11
  char v9; // w10
  unsigned int v10; // w20
  __int64 v11; // x14
  char v12; // w10
  char v13; // w11
  char v14; // w12
  char v15; // w13
  __int64 v16; // x17
  __int64 v17; // x0
  __int64 v18; // x13
  __int64 *v19; // x8
  __int64 v20; // x0
  unsigned int v21; // w0
  unsigned int v22; // w0
  __int64 v23; // x0
  __int64 v25; // x8
  const char *v26; // x1
  _BYTE v27[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v28[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *((_WORD *)a1 + 16) )
  {
    v2 = nvmem_device_write(*(_QWORD *)a1[5], 85, 2, a1 + 4);
    if ( (v2 & 0x80000000) != 0 )
    {
      v25 = a1[1];
      v26 = "Failed to write swire count to SDAM, rc=%d\n";
      goto LABEL_44;
    }
    v3 = 1;
  }
  else
  {
    if ( !*((_DWORD *)a1 + 7) )
    {
      v10 = -22;
      goto LABEL_37;
    }
    v3 = 0;
  }
  *((_DWORD *)a1 + 9) = v3;
  v4 = &ecm_reset_config;
  v5 = nvmem_device_write(*(_QWORD *)a1[5], (unsigned __int8)ecm_reset_config, 1, &algn_1A9);
  if ( (v5 & 0x80000000) != 0 )
    goto LABEL_20;
  v4 = &byte_1AA;
  v5 = nvmem_device_write(*(_QWORD *)a1[5], (unsigned __int8)byte_1AA, 1, &algn_1AB);
  if ( (v5 & 0x80000000) != 0 )
    goto LABEL_20;
  v4 = &byte_1AC;
  v5 = nvmem_device_write(*(_QWORD *)a1[5], (unsigned __int8)byte_1AC, 1, &unk_1AD);
  if ( (v5 & 0x80000000) != 0 )
    goto LABEL_20;
  v4 = &byte_1AE;
  v5 = nvmem_device_write(*(_QWORD *)a1[5], (unsigned __int8)byte_1AE, 1, &algn_1AF);
  if ( (v5 & 0x80000000) != 0 )
    goto LABEL_20;
  v4 = &byte_1B0;
  v5 = nvmem_device_write(*(_QWORD *)a1[5], (unsigned __int8)byte_1B0, 1, &algn_1B1);
  if ( (v5 & 0x80000000) != 0 )
    goto LABEL_20;
  v4 = &byte_1B2;
  v5 = nvmem_device_write(*(_QWORD *)a1[5], (unsigned __int8)byte_1B2, 1, &algn_1B3);
  if ( (v5 & 0x80000000) != 0 )
    goto LABEL_20;
  v4 = &byte_1B4;
  v5 = nvmem_device_write(*(_QWORD *)a1[5], (unsigned __int8)byte_1B4, 1, &unk_1B5);
  if ( (v5 & 0x80000000) != 0 )
    goto LABEL_20;
  v4 = aRlsfaft;
  v5 = nvmem_device_write(*(_QWORD *)a1[5], (unsigned __int8)aRlsfaft[0], 1, &aRlsfaft[1]);
  if ( (v5 & 0x80000000) != 0
    || (v4 = &aRlsfaft[2],
        v5 = nvmem_device_write(*(_QWORD *)a1[5], (unsigned __int8)aRlsfaft[2], 1, &aRlsfaft[3]),
        (v5 & 0x80000000) != 0)
    || (v4 = &aRlsfaft[4],
        v5 = nvmem_device_write(*(_QWORD *)a1[5], (unsigned __int8)aRlsfaft[4], 1, &aRlsfaft[5]),
        (v5 & 0x80000000) != 0)
    || (v4 = &aRlsfaft[6],
        v5 = nvmem_device_write(*(_QWORD *)a1[5], (unsigned __int8)aRlsfaft[6], 1, &aRlsfaft[7]),
        (v5 & 0x80000000) != 0) )
  {
LABEL_20:
    v10 = v5;
    dev_err(a1[1], "Failed to write %u to SDAM, rc=%d\n", (unsigned __int8)*v4, v5);
LABEL_21:
    dev_err(a1[1], "Failed to reset ECM SDAM configuration, rc=%d\n", v10);
    goto LABEL_37;
  }
  v6 = *((unsigned int *)a1 + 54);
  if ( !(_DWORD)v6 )
  {
    v9 = 0;
    v8 = 0;
    goto LABEL_28;
  }
  if ( (_DWORD)v6 == 1 )
  {
    v7 = 0;
    v8 = 0;
    v9 = 0;
    do
    {
LABEL_27:
      v18 = 1LL << v7++;
      v8 |= v18;
      v9 |= v18;
    }
    while ( v6 != v7 );
    goto LABEL_28;
  }
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v7 = (unsigned int)v6 & 0xFFFFFFFE;
  do
  {
    v16 = 1LL << v11;
    v17 = 2LL << v11;
    v11 += 2;
    v12 |= v16;
    v13 |= v17;
    v14 |= v16;
    v15 |= v17;
  }
  while ( v7 != v11 );
  v8 = v13 | v12;
  v9 = v15 | v14;
  if ( v7 != v6 )
    goto LABEL_27;
LABEL_28:
  v19 = (__int64 *)a1[5];
  v28[0] = v8;
  v20 = *v19;
  v27[0] = v9;
  v21 = nvmem_device_write(v20, 95, 1, v28);
  if ( (v21 & 0x80000000) != 0 )
  {
    v10 = v21;
    dev_err(a1[1], "Failed to write %u to ECM_SEND_IRQ, rc=%d\n", v28[0], v21);
    goto LABEL_21;
  }
  v22 = nvmem_device_write(*(_QWORD *)a1[5], 96, 1, v27);
  if ( (v22 & 0x80000000) != 0 )
  {
    v10 = v22;
    dev_err(a1[1], "Failed to write %u to ECM_WRITE_TO_SDAM, rc=%d\n", v27[0], v22);
    usleep_range_state(10000, 12000, 2);
    goto LABEL_21;
  }
  usleep_range_state(10000, 12000, 2);
  v2 = nvmem_device_write(*(_QWORD *)a1[5], 84, 1, (char *)a1 + 36);
  if ( (v2 & 0x80000000) != 0 )
  {
    v25 = a1[1];
    v26 = "Failed to write ECM mode to SDAM, rc=%d\n";
    goto LABEL_44;
  }
  if ( *((_BYTE *)a1 + 225) == 6 )
  {
    v2 = regmap_write(*a1, (unsigned int)(*((_DWORD *)a1 + 55) + 160), 128);
    if ( (v2 & 0x80000000) != 0 )
    {
      v25 = a1[1];
      v26 = "Failed to enable ECM, rc=%d\n";
    }
    else
    {
      v2 = regmap_write(*a1, (unsigned int)(*((_DWORD *)a1 + 55) + 161), 128);
      if ( (v2 & 0x80000000) == 0 )
        goto LABEL_34;
      v25 = a1[1];
      v26 = "Failed to enable ECM counter, rc=%d\n";
    }
LABEL_44:
    v10 = v2;
    dev_err(v25, v26);
    goto LABEL_37;
  }
LABEL_34:
  v10 = v2;
  if ( !*((_DWORD *)a1 + 9) )
  {
    v23 = _msecs_to_jiffies(*((unsigned int *)a1 + 7));
    queue_delayed_work_on(32, system_wq, a1 + 12, v23);
  }
  *((_BYTE *)a1 + 226) = 1;
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return v10;
}
