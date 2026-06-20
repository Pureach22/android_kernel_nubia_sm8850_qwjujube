__int64 __fastcall _boot_firmware_iris4(__int64 a1)
{
  unsigned int v2; // w2
  __int64 v3; // x22
  __int64 result; // x0
  unsigned int v5; // w2
  unsigned int v6; // w20
  int v7; // w8
  __int64 v8; // x0
  unsigned int v9; // w2
  int i; // w20
  int v11; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v12; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v13; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 4936);
  v3 = *(_QWORD *)a1;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  result = _write_register(a1, 0xA0064u, v2);
  if ( (_DWORD)result )
    goto LABEL_5;
  result = _write_register(a1, 0xA0068u, 0x300000u);
  if ( (_DWORD)result )
    goto LABEL_5;
  result = _write_register(a1, 0xA0054u, *(_DWORD *)(a1 + 4936));
  if ( (_DWORD)result )
    goto LABEL_5;
  result = _write_register(a1, 0xA0050u, 1u);
  if ( (_DWORD)result )
    goto LABEL_5;
  v5 = *(_DWORD *)(a1 + 5080);
  if ( v5 )
  {
    result = _write_register(a1, 0xA0060u, v5);
    if ( (_DWORD)result )
      goto LABEL_5;
  }
  else if ( (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_8A4D2, "err ", 0xFFFFFFFFLL, "codec", "__program_bootup_registers_iris4");
  }
  result = _get_device_region_info(a1, &v13, &v12);
  if ( (_DWORD)result )
    goto LABEL_5;
  if ( v13 )
  {
    v6 = v12;
    if ( v12 )
    {
      result = _write_register(a1, 0xA0024u, v13);
      if ( (_DWORD)result )
        goto LABEL_5;
      result = _write_register(a1, 0xA0028u, v6);
      if ( (_DWORD)result )
        goto LABEL_5;
LABEL_18:
      v7 = *(_DWORD *)(a1 + 4792);
      if ( v7 )
        goto LABEL_19;
      goto LABEL_20;
    }
  }
  if ( (msm_vidc_debug & 2) == 0 )
    goto LABEL_18;
  printk(&unk_85601, "high", 0xFFFFFFFFLL, "codec", "__program_bootup_registers_iris4");
  v7 = *(_DWORD *)(a1 + 4792);
  if ( v7 )
  {
LABEL_19:
    result = _write_register(a1, 0xA005Cu, v7 + 1);
    if ( (_DWORD)result )
      goto LABEL_5;
  }
LABEL_20:
  if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(v3 + 760), "qcom,canoe-vidc-v2") )
  {
    v8 = a1;
    v9 = 1;
  }
  else
  {
    v8 = a1;
    v9 = 0;
  }
  result = _write_register(v8, 0xB0078u, v9);
  if ( !(_DWORD)result )
  {
    result = _write_register(a1, 0xA0048u, 1u);
    if ( !(_DWORD)result )
    {
      for ( i = 1000; i; --i )
      {
        result = _read_register(a1, 0xA004Cu, &v11);
        if ( (_DWORD)result )
          break;
        if ( (v11 & 0xE) != 0 )
        {
          if ( (msm_vidc_debug & 1) != 0 )
            printk(&unk_80DFB, "err ", 0xFFFFFFFFLL, "codec", "__boot_firmware_iris4");
          result = 4294967274LL;
          break;
        }
        if ( (v11 & 1) != 0 )
        {
          if ( (msm_vidc_debug & 2) != 0 )
            printk(&unk_862FD, "high", 0xFFFFFFFFLL, "codec", "__boot_firmware_iris4");
          result = _write_register(a1, 0xA0148u, 1u);
          if ( !(_DWORD)result )
            result = _write_register(a1, 0xA0168u, 0);
          break;
        }
        usleep_range_state(50, 100, 2);
        result = 4294967234LL;
      }
    }
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
