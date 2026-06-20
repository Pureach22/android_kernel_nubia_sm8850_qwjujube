__int64 __fastcall adc5_gen3_poll_wait_hs(_QWORD *a1, unsigned int a2)
{
  __int64 v3; // x22
  int v5; // w23
  __int64 v6; // x2
  unsigned int v7; // w0
  unsigned int v8; // w0
  __int64 result; // x0
  unsigned int v10; // w19
  __int64 v11; // x1
  char v12[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v13[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v3 = 24LL * a2;
  v5 = 150;
  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = 0;
  v12[0] = 1;
  while ( 1 )
  {
    v7 = regmap_bulk_read(*a1, (unsigned int)*(unsigned __int16 *)(a1[3] + v3) + 69, v13, 1);
    if ( (v7 & 0x80000000) != 0 )
    {
      v10 = v7;
      v11 = 69;
      goto LABEL_12;
    }
    if ( v13[0] == 1 )
      break;
LABEL_2:
    usleep_range_state(100, 110, 2);
    if ( !--v5 )
    {
      printk(&unk_94F6, v13[0], v6);
      ipc_log_string(a1[2], "Setting HS ready bit timed out, status:%#x\n", v13[0]);
      result = 4294967186LL;
      goto LABEL_8;
    }
  }
  v8 = regmap_bulk_read(*a1, (unsigned int)*(unsigned __int16 *)(a1[3] + 24LL * a2) + 229, v12, 1);
  if ( (v8 & 0x80000000) == 0 )
  {
    if ( !v12[0] )
    {
      result = 0;
      goto LABEL_8;
    }
    goto LABEL_2;
  }
  v10 = v8;
  v11 = 229;
LABEL_12:
  printk(&unk_9458, v11, 1);
  result = v10;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
