__int64 __fastcall core_info_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  __int64 v7; // x0
  __int64 v8; // x23
  __int64 *v9; // x20
  __int64 v10; // x27
  unsigned int v11; // w0
  __int64 v12; // x25
  __int64 v13; // x24
  __int64 v14; // x25
  _DWORD *v15; // x8
  __int64 v16; // x0
  unsigned __int64 StatusReg; // x8
  __int64 result; // x0
  unsigned __int64 v19; // x8
  __int64 v20; // x24
  __int64 v21; // x24
  __int64 v22; // x24
  __int64 v23; // x24
  const char *v24; // x4
  __int64 v25; // x25
  const char *v26; // x4
  __int64 v27; // x25
  const char *v28; // x4
  __int64 v29; // x25
  const char *v30; // x4
  __int64 v31; // x25
  const char *v32; // x4
  __int64 v33; // x25
  const char *v34; // x4
  __int64 v35; // x25
  const char *v36; // x4
  __int64 v37; // x25
  const char *v38; // x4
  unsigned int v39; // w0
  __int64 v40; // x19
  unsigned __int64 v41; // x8
  _QWORD v43[16]; // [xsp+8h] [xbp-A8h] BYREF
  __int64 v44; // [xsp+88h] [xbp-28h]
  __int64 v45; // [xsp+90h] [xbp-20h]
  __int64 v46; // [xsp+98h] [xbp-18h]
  __int64 v47; // [xsp+A0h] [xbp-10h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v45 = 0;
  v46 = 0;
  v44 = 0;
  memset(v43, 0, sizeof(v43));
  if ( v4 && *(_QWORD *)(v4 + 256) )
  {
    v7 = _kmalloc_cache_noprof(_kmalloc_large_noprof, 3520, 4096);
    v8 = v7;
    if ( v7 )
    {
      v9 = *(__int64 **)(v4 + 256);
      v10 = v7 + 4096;
      v11 = write_str(v7, 4096, "===============================\n");
      v12 = v8 + v11 + (unsigned int)write_str(v8 + v11, 4096LL - v11, "CORE %d: %pK\n", 0, (const void *)v4);
      v13 = v12 + (unsigned int)write_str(v12, v10 - v12, "===============================\n");
      v14 = v13 + (unsigned int)write_str(v13, v10 - v13, "Core state: %d\n", *(_DWORD *)(v4 + 304));
      if ( !v9 )
        goto LABEL_15;
      v15 = (_DWORD *)v9[15];
      if ( !v15 )
        goto LABEL_15;
      v16 = *v9;
      if ( *(v15 - 1) != -438871699 )
        __break(0x8228u);
      if ( ((unsigned int (__fastcall *)(__int64, _QWORD *))v15)(v16, v43) )
      {
        if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          printk(&unk_8E33A, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
        }
      }
      else
      {
LABEL_15:
        v20 = v14 + (unsigned int)write_str(v14, v10 - v14, "FW version : %s\n", (const char *)v43);
        v21 = v20 + (unsigned int)write_str(v20, v10 - v20, "base addr: 0x%x\n", v44);
        v22 = v21 + (unsigned int)write_str(v21, v10 - v21, "register_base: 0x%x\n", v45);
        v23 = v22 + (unsigned int)write_str(v22, v10 - v22, "register_size: %u\n", HIDWORD(v45));
        v14 = v23 + (unsigned int)write_str(v23, v10 - v23, "irq: %u\n", v46);
      }
      if ( (completion_done(v4 + 312) & 1) != 0 )
        v24 = "pending";
      else
        v24 = "done";
      v25 = v14 + (unsigned int)write_str(v14, v10 - v14, "completions[%d]: %s\n", 1, v24);
      if ( (completion_done(v4 + 344) & 1) != 0 )
        v26 = "pending";
      else
        v26 = "done";
      v27 = v25 + (unsigned int)write_str(v25, v10 - v25, "completions[%d]: %s\n", 2, v26);
      if ( (completion_done(v4 + 376) & 1) != 0 )
        v28 = "pending";
      else
        v28 = "done";
      v29 = v27 + (unsigned int)write_str(v27, v10 - v27, "completions[%d]: %s\n", 3, v28);
      if ( (completion_done(v4 + 408) & 1) != 0 )
        v30 = "pending";
      else
        v30 = "done";
      v31 = v29 + (unsigned int)write_str(v29, v10 - v29, "completions[%d]: %s\n", 4, v30);
      if ( (completion_done(v4 + 440) & 1) != 0 )
        v32 = "pending";
      else
        v32 = "done";
      v33 = v31 + (unsigned int)write_str(v31, v10 - v31, "completions[%d]: %s\n", 5, v32);
      if ( (completion_done(v4 + 472) & 1) != 0 )
        v34 = "pending";
      else
        v34 = "done";
      v35 = v33 + (unsigned int)write_str(v33, v10 - v33, "completions[%d]: %s\n", 6, v34);
      if ( (completion_done(v4 + 504) & 1) != 0 )
        v36 = "pending";
      else
        v36 = "done";
      v37 = v35 + (unsigned int)write_str(v35, v10 - v35, "completions[%d]: %s\n", 7, v36);
      if ( (completion_done(v4 + 536) & 1) != 0 )
        v38 = "pending";
      else
        v38 = "done";
      v39 = write_str(v37, v10 - v37, "completions[%d]: %s\n", 8, v38);
      v40 = simple_read_from_buffer(a2, a3, a4, v8, v37 + v39 - v8);
      kfree(v8);
      result = v40;
    }
    else
    {
      result = -12;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v41 = _ReadStatusReg(SP_EL0);
        printk(&unk_847A4, *(unsigned int *)(v41 + 1800), *(unsigned int *)(v41 + 1804), &unk_8E7CE);
        result = -12;
      }
    }
  }
  else
  {
    result = 0;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v19 = _ReadStatusReg(SP_EL0);
      printk(&unk_8E291, *(unsigned int *)(v19 + 1800), *(unsigned int *)(v19 + 1804), &unk_8E7CE);
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
