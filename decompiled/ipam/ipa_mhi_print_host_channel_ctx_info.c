__int64 __fastcall ipa_mhi_print_host_channel_ctx_info(__int64 a1, __int64 a2, int a3)
{
  unsigned __int64 v6; // x2
  int v7; // w0
  __int64 result; // x0
  int v9; // w21
  int v10; // w21
  int v11; // w21
  int v12; // w21
  int v13; // w21
  int v14; // w21
  int v15; // w21
  int v16; // w21
  _QWORD v17[7]; // [xsp+8h] [xbp-38h] BYREF

  v17[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 56);
  memset(v17, 0, 44);
  v7 = ipa_mhi_read_write_host(1, v17, v6, 0x2Cu);
  if ( v7 )
  {
    result = scnprintf(a2, a3, "Failed to read from host %d\n", v7);
  }
  else
  {
    v9 = scnprintf(a2, a3, "ch_id: %d\n", *(unsigned __int8 *)(a1 + 1));
    v10 = scnprintf(a2 + v9, a3 - v9, "chstate: 0x%x\n", LOBYTE(v17[0])) + v9;
    v11 = scnprintf(a2 + v10, a3 - v10, "brstmode: 0x%x\n", BYTE1(v17[0]) & 3) + v10;
    v12 = scnprintf(a2 + v11, a3 - v11, "chtype: 0x%x\n", HIDWORD(v17[0])) + v11;
    v13 = scnprintf(a2 + v12, a3 - v12, "erindex: 0x%x\n", LODWORD(v17[1])) + v12;
    v14 = scnprintf(a2 + v13, a3 - v13, "rbase: 0x%llx\n", *(_QWORD *)((char *)&v17[1] + 4)) + v13;
    v15 = scnprintf(a2 + v14, a3 - v14, "rlen: 0x%llx\n", *(_QWORD *)((char *)&v17[2] + 4)) + v14;
    v16 = scnprintf(a2 + v15, a3 - v15, "rp: 0x%llx\n", *(_QWORD *)((char *)&v17[3] + 4)) + v15;
    result = (unsigned int)scnprintf(a2 + v16, a3 - v16, "wp: 0x%llx\n", *(_QWORD *)((char *)&v17[4] + 4)) + v16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
