__int64 __fastcall wcd_mbhc_fw_read(__int64 a1)
{
  __int64 v2; // x19
  int v3; // w24
  __int64 v4; // x23
  __int64 (__fastcall *v5)(__int64, __int64); // x8
  _QWORD *v6; // x0
  __int64 v7; // x8
  int v8; // w21
  unsigned __int64 *v9; // x9
  unsigned __int64 v10; // x9
  _QWORD *v11; // x10
  __int64 v12; // x9
  __int64 result; // x0
  _QWORD v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v2 = a1 - 224;
  v3 = 15;
  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 - 8);
  v14[0] = 0;
  while ( 1 )
  {
    v5 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 - 104) + 80LL);
    if ( v5 )
    {
      if ( *((_DWORD *)v5 - 1) != 1250183833 )
        __break(0x8228u);
      v6 = (_QWORD *)v5(v2, 2);
      if ( v6 )
        break;
    }
    if ( !(unsigned int)request_firmware(v14, "wcd9320/wcd9320_mbhc.bin", *(_QWORD *)(v4 + 24)) )
    {
      v7 = v14[0];
      v6 = nullptr;
      v8 = 0;
      v9 = (unsigned __int64 *)v14[0];
      goto LABEL_11;
    }
    usleep_range_state(4000000, 4000100, 2);
    if ( !--v3 )
    {
      printk(&unk_DEF4, "wcd_mbhc_fw_read");
      goto LABEL_18;
    }
  }
  v7 = v14[0];
  v9 = v6 + 1;
  v8 = 1;
LABEL_11:
  v10 = *v9;
  if ( v10 < 0x6A )
    goto LABEL_19;
  v11 = (_QWORD *)(v7 + 8);
  if ( v8 )
    v11 = v6;
  if ( 4 * (unsigned __int64)*(unsigned __int8 *)(*v11 + 65LL) + 86 > v10 )
  {
LABEL_19:
    printk(&unk_E599, "wcd_mbhc_fw_read");
    if ( (v8 & 1) == 0 )
      release_firmware(v14[0]);
  }
  else
  {
    v12 = *(_QWORD *)(a1 - 112);
    if ( v8 )
    {
      *(_QWORD *)(v12 + 8) = *v6;
      *(_QWORD *)(a1 + 112) = v6;
    }
    else
    {
      *(_QWORD *)(v12 + 8) = *(_QWORD *)(v7 + 8);
      *(_QWORD *)(a1 + 104) = v7;
    }
  }
LABEL_18:
  result = wcd_mbhc_initialise(v2);
  _ReadStatusReg(SP_EL0);
  return result;
}
