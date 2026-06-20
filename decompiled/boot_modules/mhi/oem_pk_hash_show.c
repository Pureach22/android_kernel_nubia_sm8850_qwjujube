__int64 __fastcall oem_pk_hash_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x23
  __int64 v6; // x22
  int reg; // w0
  unsigned int v8; // w21
  unsigned int v9; // w21
  unsigned int v10; // w21
  unsigned int v11; // w21
  unsigned int v12; // w21
  unsigned int v13; // w21
  unsigned int v14; // w21
  unsigned int v15; // w21
  unsigned int v16; // w21
  unsigned int v17; // w21
  unsigned int v18; // w21
  unsigned int v19; // w21
  unsigned int v20; // w21
  unsigned int v21; // w21
  unsigned int v22; // w21
  int v23; // w20
  __int64 v25; // x19
  __int64 v26; // [xsp+8h] [xbp-48h] BYREF
  __int64 v27; // [xsp+10h] [xbp-40h]
  __int64 v28; // [xsp+18h] [xbp-38h]
  __int64 v29; // [xsp+20h] [xbp-30h]
  __int64 v30; // [xsp+28h] [xbp-28h]
  __int64 v31; // [xsp+30h] [xbp-20h]
  __int64 v32; // [xsp+38h] [xbp-18h]
  __int64 v33; // [xsp+40h] [xbp-10h]
  __int64 v34; // [xsp+48h] [xbp-8h]

  v5 = 0;
  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 - 24);
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  while ( 1 )
  {
    reg = mhi_read_reg(v6, *(_QWORD *)(v6 + 40), (unsigned int)(v5 + 100), (char *)&v26 + v5);
    if ( reg )
      break;
    v5 += 4;
    if ( v5 == 64 )
    {
      v8 = sysfs_emit_at(a3, 0, "OEMPKHASH[%d]: 0x%x\n", 0, v26);
      v9 = sysfs_emit_at(a3, v8, "OEMPKHASH[%d]: 0x%x\n", 1, HIDWORD(v26)) + v8;
      v10 = sysfs_emit_at(a3, v9, "OEMPKHASH[%d]: 0x%x\n", 2, v27) + v9;
      v11 = sysfs_emit_at(a3, v10, "OEMPKHASH[%d]: 0x%x\n", 3, HIDWORD(v27)) + v10;
      v12 = sysfs_emit_at(a3, v11, "OEMPKHASH[%d]: 0x%x\n", 4, v28) + v11;
      v13 = sysfs_emit_at(a3, v12, "OEMPKHASH[%d]: 0x%x\n", 5, HIDWORD(v28)) + v12;
      v14 = sysfs_emit_at(a3, v13, "OEMPKHASH[%d]: 0x%x\n", 6, v29) + v13;
      v15 = sysfs_emit_at(a3, v14, "OEMPKHASH[%d]: 0x%x\n", 7, HIDWORD(v29)) + v14;
      v16 = sysfs_emit_at(a3, v15, "OEMPKHASH[%d]: 0x%x\n", 8, v30) + v15;
      v17 = sysfs_emit_at(a3, v16, "OEMPKHASH[%d]: 0x%x\n", 9, HIDWORD(v30)) + v16;
      v18 = sysfs_emit_at(a3, v17, "OEMPKHASH[%d]: 0x%x\n", 10, v31) + v17;
      v19 = sysfs_emit_at(a3, v18, "OEMPKHASH[%d]: 0x%x\n", 11, HIDWORD(v31)) + v18;
      v20 = sysfs_emit_at(a3, v19, "OEMPKHASH[%d]: 0x%x\n", 12, v32) + v19;
      v21 = sysfs_emit_at(a3, v20, "OEMPKHASH[%d]: 0x%x\n", 13, HIDWORD(v32)) + v20;
      v22 = sysfs_emit_at(a3, v21, "OEMPKHASH[%d]: 0x%x\n", 14, v33) + v21;
      v23 = sysfs_emit_at(a3, v22, "OEMPKHASH[%d]: 0x%x\n", 15, HIDWORD(v33)) + v22;
      goto LABEL_5;
    }
  }
  v23 = reg;
  v25 = *(_QWORD *)(*(_QWORD *)(v6 + 16) + 192LL);
  dev_err(a1, "[E][%s] Could not capture OEM PK HASH\n", "oem_pk_hash_show");
  if ( v25 && *(_DWORD *)(v25 + 24) <= 2u )
    ipc_log_string(*(_QWORD *)(v25 + 32), "[E][%s] Could not capture OEM PK HASH\n", "oem_pk_hash_show");
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return v23;
}
