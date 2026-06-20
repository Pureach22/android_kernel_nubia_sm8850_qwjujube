__int64 __fastcall amoled_ecm_disable(_QWORD *a1)
{
  unsigned int v2; // w0
  __int64 *v3; // x8
  __int64 v4; // x0
  unsigned int v5; // w20
  __int64 v7; // x8
  const char *v8; // x1
  _BYTE v9[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *((_BYTE *)a1 + 225) == 6 )
  {
    v2 = regmap_write(*a1, (unsigned int)(*((_DWORD *)a1 + 55) + 161), 0);
    if ( (v2 & 0x80000000) != 0 )
    {
      v7 = a1[1];
      v8 = "Failed to disable ECM counter, rc=%d\n";
      goto LABEL_11;
    }
    v2 = regmap_write(*a1, (unsigned int)(*((_DWORD *)a1 + 55) + 160), 0);
    if ( (v2 & 0x80000000) != 0 )
    {
      v7 = a1[1];
      v8 = "Failed to disable ECM, rc=%d\n";
      goto LABEL_11;
    }
  }
  v2 = nvmem_device_write(*(_QWORD *)a1[5], 97, 2, (char *)a1 + 34);
  if ( (v2 & 0x80000000) != 0 )
  {
    v7 = a1[1];
    v8 = "Failed to write ECM average to SDAM, rc=%d\n";
LABEL_11:
    v5 = v2;
    dev_err(v7, v8);
    goto LABEL_7;
  }
  cancel_delayed_work(a1 + 12);
  v3 = (__int64 *)a1[5];
  *((_WORD *)a1 + 17) = 0;
  a1[2] = 0;
  *((_DWORD *)a1 + 6) = 0;
  *((_DWORD *)a1 + 9) = 2;
  *((_WORD *)a1 + 113) = 0;
  v4 = *v3;
  v9[0] = 0;
  v5 = nvmem_device_write(v4, 96, 1, v9);
  if ( (v5 & 0x80000000) != 0 )
    dev_err(a1[1], "Failed to write %u to ECM_WRITE_TO_SDAM, rc=%d\n", v9[0], v5);
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return v5;
}
