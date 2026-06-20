__int64 __fastcall _md_dump_fw_region(__int64 a1, const char *a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x8
  size_t v10; // x0
  unsigned __int64 v11; // x2
  __int64 result; // x0
  unsigned int v13; // w20
  unsigned int v14; // w19
  __int64 v15; // x0
  __int64 v16; // x8
  _QWORD v17[3]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v18; // [xsp+20h] [xbp-20h]
  __int64 v19; // [xsp+28h] [xbp-18h]
  __int64 v20; // [xsp+30h] [xbp-10h]
  __int64 v21; // [xsp+38h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 4688);
  v19 = 0;
  v20 = 0;
  v18 = 0;
  memset(v17, 0, sizeof(v17));
  if ( !v5 || (msm_minidump_enabled() & 1) == 0 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_823BE, "err ", 0xFFFFFFFFLL, "codec", "__md_dump_fw_region");
    result = 0;
    goto LABEL_14;
  }
  v10 = strnlen(a2, 0xDu);
  if ( v10 == -1 )
  {
    _fortify_panic(2, -1, 0);
  }
  else
  {
    if ( v10 == 13 )
      v11 = 13;
    else
      v11 = v10 + 1;
    if ( v11 < 0xE )
    {
      sized_strscpy(v17, a2);
      v18 = a3;
      v19 = a4;
      v20 = a5;
      result = msm_minidump_add_region(v17);
      if ( (result & 0x80000000) != 0 )
      {
        if ( (msm_vidc_debug & 1) != 0 )
        {
          v14 = result;
          printk(&unk_83775, "err ", 0xFFFFFFFFLL, "codec", "__md_dump_fw_region");
          result = v14;
        }
      }
      else if ( (msm_vidc_debug & 2) != 0 )
      {
        v13 = result;
        printk(&unk_80658, "high", 0xFFFFFFFFLL, "codec", "__md_dump_fw_region");
        result = v13;
      }
LABEL_14:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  v15 = _fortify_panic(7, 13, v11);
  __arm_mte_increment_tag((void *)(v16 + 720), 3u);
  return _md_dump_hfi_queues(v15);
}
