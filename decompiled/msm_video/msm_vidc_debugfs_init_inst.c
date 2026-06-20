unsigned __int64 __fastcall msm_vidc_debugfs_init_inst(__int64 a1, __int64 a2)
{
  int v4; // w3
  __int64 v5; // x4
  _QWORD *v6; // x20
  unsigned __int64 dir; // x0
  __int64 v8; // x4
  unsigned __int64 v9; // x21
  unsigned __int64 file; // x0
  __int64 v11; // x4
  __int64 v12; // x8
  unsigned __int64 result; // x0
  _QWORD v14[6]; // [xsp+0h] [xbp-40h] BYREF
  __int16 v15; // [xsp+30h] [xbp-10h]
  __int64 v16; // [xsp+38h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a1 + 332);
  v15 = 0;
  memset(v14, 0, sizeof(v14));
  snprintf((char *)v14, 0x32u, "inst_%d", v4);
  v6 = (_QWORD *)vzalloc_noprof(16);
  if ( !v6 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_92E2A, "err ", a1 + 340, "msm_vidc_debugfs_init_inst", v5);
    goto LABEL_18;
  }
  *v6 = *(_QWORD *)(a1 + 320);
  v6[1] = a1;
  dir = debugfs_create_dir(v14, a2);
  if ( !dir || dir >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_8EFFD, "err ", a1 + 340, "msm_vidc_debugfs_init_inst", v8);
    goto LABEL_14;
  }
  v9 = dir;
  file = debugfs_create_file("info", 292, dir, v6, &inst_info_fops);
  if ( !file || file >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_89B72, "err ", a1 + 340, "msm_vidc_debugfs_init_inst", v11);
    debugfs_remove(v9);
LABEL_14:
    vfree(v6);
LABEL_18:
    result = 0;
    goto LABEL_19;
  }
  v12 = *(_QWORD *)(file + 48);
  result = v9;
  *(_QWORD *)(*(_QWORD *)(v9 + 48) + 696LL) = *(_QWORD *)(v12 + 696);
  *(_DWORD *)(a1 + 4208) = 1;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
