__int64 __fastcall adc5_gen3_dump_regs_debug(__int64 result)
{
  _QWORD *v1; // x19
  __int64 v2; // x24
  unsigned __int64 v3; // x20
  __int64 v4; // x0
  int v5; // w25
  unsigned int v6; // w0
  __int64 v7; // x2
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(result + 36) )
  {
    v1 = (_QWORD *)result;
    v2 = 0;
    v3 = 0;
    do
    {
      ipc_log_string(v1[2], "ADC SDAM%d DUMP\n", v3);
      v4 = *v1;
      v5 = *(unsigned __int16 *)(v1[3] + v2);
      v8[0] = 0;
      v6 = regmap_bulk_read(v4, (unsigned int)(v5 + 64), v8, 8);
      if ( (v6 & 0x80000000) != 0 )
        goto LABEL_3;
      ipc_log_string(v1[2], "%#04x: %*ph\n", v5 + 64, 8, v8);
      v6 = regmap_bulk_read(*v1, (unsigned int)(v5 + 72), v8, 8);
      if ( (v6 & 0x80000000) != 0 )
        goto LABEL_3;
      ipc_log_string(v1[2], "%#04x: %*ph\n", v5 + 72, 8, v8);
      v6 = regmap_bulk_read(*v1, (unsigned int)(v5 + 80), v8, 8);
      if ( (v6 & 0x80000000) != 0
        || (ipc_log_string(v1[2], "%#04x: %*ph\n", v5 + 80, 8, v8),
            v6 = regmap_bulk_read(*v1, (unsigned int)(v5 + 88), v8, 8),
            (v6 & 0x80000000) != 0)
        || (ipc_log_string(v1[2], "%#04x: %*ph\n", v5 + 88, 8, v8),
            v6 = regmap_bulk_read(*v1, (unsigned int)(v5 + 96), v8, 8),
            (v6 & 0x80000000) != 0)
        || (ipc_log_string(v1[2], "%#04x: %*ph\n", v5 + 96, 8, v8),
            v6 = regmap_bulk_read(*v1, (unsigned int)(v5 + 104), v8, 8),
            (v6 & 0x80000000) != 0) )
      {
LABEL_3:
        result = printk(&unk_9738, v6, v7);
      }
      else
      {
        result = ipc_log_string(v1[2], "%#04x: %*ph\n", v5 + 104, 8, v8);
      }
      ++v3;
      v2 += 24;
    }
    while ( v3 < *((unsigned int *)v1 + 9) );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
