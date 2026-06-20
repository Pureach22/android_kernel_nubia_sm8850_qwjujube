unsigned __int64 __fastcall spmi_pmic_arb_debugfs_init(__int64 a1)
{
  __int64 v2; // x8
  unsigned __int64 v3; // x3
  unsigned __int64 dir; // x20
  unsigned __int64 file_unsafe; // x0
  unsigned __int64 result; // x0
  const char *v7; // x1
  __int64 v8; // [xsp+8h] [xbp-18h] BYREF
  __int16 v9; // [xsp+10h] [xbp-10h]
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 40);
  v9 = 0;
  v8 = 0;
  scnprintf(&v8, 10, "spmi%u", *(_DWORD *)(v2 + 912));
  v3 = debugfs_create_dir(&v8, 0);
  if ( v3 >= 0xFFFFFFFFFFFFF001LL )
  {
    result = dev_err(*(_QWORD *)(a1 + 40), "Could not create %s debugfs directory, rc=%ld\n", (const char *)&v8, v3);
    goto LABEL_13;
  }
  *(_QWORD *)(a1 + 176) = v3;
  dir = debugfs_create_dir("address_map", v3);
  if ( dir > 0xFFFFFFFFFFFFF000LL )
  {
    dev_err(*(_QWORD *)(a1 + 40), "Could not create address_map debugfs directory, rc=%ld\n", dir);
    goto LABEL_12;
  }
  file_unsafe = debugfs_create_file_unsafe("spmi_addr", 384, dir, a1, &debug_spmi_addr_fops);
  if ( file_unsafe > 0xFFFFFFFFFFFFF000LL )
  {
    v7 = "Could not create spmi_addr debugfs file, rc=%ld\n";
LABEL_11:
    dev_err(*(_QWORD *)(a1 + 40), v7, file_unsafe);
    goto LABEL_12;
  }
  file_unsafe = debugfs_create_file_unsafe("soc_addr_start", 256, dir, a1, &debug_soc_start_addr_fops);
  if ( file_unsafe > 0xFFFFFFFFFFFFF000LL )
  {
    v7 = "Could not create soc_addr_start debugfs file, rc=%ld\n";
    goto LABEL_11;
  }
  result = debugfs_create_file_unsafe("soc_addr_end", 256, dir, a1, &debug_soc_end_addr_fops);
  if ( result >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(*(_QWORD *)(a1 + 40), "Could not create soc_addr_end debugfs file, rc=%ld\n", result);
LABEL_12:
    result = debugfs_remove(*(_QWORD *)(a1 + 176));
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
