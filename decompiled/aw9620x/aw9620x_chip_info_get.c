__int64 __fastcall aw9620x_chip_info_get(__int64 a1, int a2, char *s)
{
  __int64 v4; // x21
  __int64 v5; // x23
  __int64 v6; // x23
  __int64 v7; // x23
  __int64 v8; // x23
  __int64 v9; // x20
  __int64 v10; // x20
  int v11; // w3
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v13 = 0;
  v5 = snprintf(s, 0x1000u, "sar%u , driver version %s\n", *(_DWORD *)(v4 - 48), "v0.3.0");
  aw9620x_i2c_read(v4 - 56, 0xFF00u, &v13);
  v6 = v5 + snprintf(&s[v5], 4096 - v5, "chipid is 0x%08x\n", v13);
  aw9620x_i2c_read(v4 - 56, 0x1A10u, (_DWORD *)(v4 + 592));
  v7 = v6 + snprintf(&s[v6], 4096 - v6, "chip firmware ver is 0x%08x\n", *(_DWORD *)(v4 + 592));
  v8 = v7 + snprintf(&s[v7], 4096 - v7, "bin  firmware ver is 0x%08x\n", *(_DWORD *)(v4 + 588));
  aw9620x_i2c_read(v4 - 56, 0x4414u, &v13);
  v9 = v8 + snprintf(&s[v8], 4096 - v8, "REG_HOSTIRQEN is 0x%08x\n", v13);
  if ( *(_BYTE *)(v4 - 52) == 1 )
    v9 += snprintf(&s[v9], 4096 - v9, "Error updating register bin file, update with default array\n");
  if ( *(_BYTE *)(v4 + 584) == 1 )
  {
    v10 = v9
        + snprintf(
            &s[v9],
            4096 - v9,
            "boot ver is 0x%08x, date is 0x%08x, checksum is 0x%08x\n",
            *(_DWORD *)(v4 + 600),
            *(_DWORD *)(v4 + 604),
            *(_DWORD *)(v4 + 608));
    v9 = v10 + snprintf(&s[v10], 4096 - v10, "fw checksum is 0x%08x\n", *(_DWORD *)(v4 + 596));
  }
  v11 = *(_DWORD *)(v4 + 612);
  if ( v11 )
    v9 += snprintf(&s[v9], 4096 - v9, "boot bin ver is 0x%08x\n", v11);
  _ReadStatusReg(SP_EL0);
  return v9;
}
