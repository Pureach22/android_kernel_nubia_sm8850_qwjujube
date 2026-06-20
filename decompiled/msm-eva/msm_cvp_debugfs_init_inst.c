_QWORD *__fastcall msm_cvp_debugfs_init_inst(_QWORD *result, __int64 a2)
{
  _QWORD *v2; // x19
  _QWORD *v4; // x20
  unsigned __int64 dir; // x0
  _QWORD *v6; // x21
  __int64 file; // x0
  __int64 v8; // x8
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v12; // x8
  _QWORD v13[6]; // [xsp+0h] [xbp-40h] BYREF
  __int16 v14; // [xsp+30h] [xbp-10h]
  __int64 v15; // [xsp+38h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  memset(v13, 0, sizeof(v13));
  if ( result )
  {
    v2 = result;
    snprintf((char *)v13, 0x32u, "inst_%pK", result);
    v4 = (_QWORD *)_kmalloc_cache_noprof(kfree, 3520, 16);
    if ( v4 )
    {
      *v4 = v2[16];
      v4[1] = v2;
      dir = debugfs_create_dir(v13, a2);
      if ( dir && dir < 0xFFFFFFFFFFFFF001LL )
      {
        v6 = (_QWORD *)dir;
        file = debugfs_create_file("info", 292, dir, v4, &inst_info_fops);
        if ( file )
        {
          v8 = *(_QWORD *)(file + 48);
          result = v6;
          *(_QWORD *)(v6[6] + 696LL) = *(_QWORD *)(v8 + 696);
          *((_DWORD *)v2 + 3478) = 1;
          goto LABEL_21;
        }
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          printk(&unk_8E302, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
        }
        debugfs_remove(v6);
      }
      else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v10 = _ReadStatusReg(SP_EL0);
        printk(&unk_8698D, *(unsigned int *)(v10 + 1800), *(unsigned int *)(v10 + 1804), &unk_8E7CE);
      }
      kfree(v4);
LABEL_18:
      result = nullptr;
      goto LABEL_21;
    }
    result = nullptr;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v12 = _ReadStatusReg(SP_EL0);
      printk(&unk_847A4, *(unsigned int *)(v12 + 1800), *(unsigned int *)(v12 + 1804), &unk_8E7CE);
      goto LABEL_18;
    }
  }
  else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v9 = _ReadStatusReg(SP_EL0);
    printk(&unk_87AB8, *(unsigned int *)(v9 + 1800), *(unsigned int *)(v9 + 1804), &unk_8E7CE);
    goto LABEL_18;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
