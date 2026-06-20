void __fastcall msm_cvp_ssr_handler(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x19
  __int64 *v6; // x21
  int v7; // w8
  __int64 v8; // x3
  __int64 *v9; // x8
  __int64 *v10; // x20
  unsigned __int64 v11; // x8
  __int64 v12; // x1
  __int64 v13; // x2
  void *v14; // x0
  __int64 *v15; // x9
  __int64 v16; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v18; // x0
  unsigned __int64 v19; // x27
  __int64 (__fastcall *v20)(__int64, __int64); // x8
  __int64 v21; // x0
  __int64 v22; // x1
  int v23; // w0
  unsigned int v24; // w26
  unsigned int v25; // w28
  __int64 v26; // x28
  __int64 *v27; // x1
  char v28; // w8
  int v29; // w9
  void *v30; // x25
  void *v31; // x24
  const char *v32; // x22
  unsigned __int64 v33; // x20
  __int64 v34; // x23
  __int64 *inst_validate; // x0
  unsigned int v36; // w8
  __int64 v37; // x2
  void *v38; // x0
  const char *v39; // x20
  void *v40; // x22
  void *v41; // x24
  __int64 *v42; // x25
  unsigned __int64 v43; // x8
  unsigned __int64 v44; // x8
  unsigned __int64 v45; // x8
  unsigned int *v46; // x20
  unsigned __int64 v47; // x8
  unsigned __int64 v48; // x8
  unsigned __int64 v49; // x8
  __int64 v50; // x19
  unsigned __int64 v51; // x8
  unsigned __int64 v52; // [xsp+0h] [xbp-310h]
  _QWORD s[97]; // [xsp+8h] [xbp-308h] BYREF

  s[95] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_80;
  v5 = a1 - 1208;
  if ( a1 == 1208 || (v6 = *(__int64 **)(a1 - 952)) == nullptr )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_9307C, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    }
    goto LABEL_80;
  }
  v7 = *(_DWORD *)(a1 + 32);
  if ( v7 <= 6 )
  {
    if ( v7 == 4 )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v49 = _ReadStatusReg(SP_EL0);
        printk(&unk_8B67C, *(unsigned int *)(v49 + 1800), *(unsigned int *)(v49 + 1804), &unk_8E7CE);
      }
      mutex_lock(v5);
      v26 = a1 - 928;
      v27 = *(__int64 **)(a1 - 928);
      if ( v27 != (__int64 *)(a1 - 928) )
      {
        v28 = msm_cvp_debug;
        v29 = msm_cvp_debug_out;
        v30 = &unk_87956;
        v31 = &unk_925B4;
        v32 = "msm_cvp_ssr_handler";
        v33 = _ReadStatusReg(SP_EL0);
        while ( 1 )
        {
          v34 = *v27;
          if ( (v28 & 2) != 0 && !v29 )
          {
            v36 = *(_DWORD *)(v33 + 1800);
            v37 = *(unsigned int *)(v33 + 1804);
            v38 = v30;
            v52 = v33;
            v39 = v32;
            v40 = v31;
            v41 = v30;
            v42 = v27;
            printk(v38, v36, v37, "warn");
            v27 = v42;
            v30 = v41;
            v31 = v40;
            v32 = v39;
            v33 = v52;
            if ( !v27 )
            {
LABEL_63:
              if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
              {
                v43 = _ReadStatusReg(SP_EL0);
                printk(&unk_8314A, *(unsigned int *)(v43 + 1800), *(unsigned int *)(v43 + 1804), "warn");
              }
              goto LABEL_79;
            }
          }
          else if ( !v27 )
          {
            goto LABEL_63;
          }
          inst_validate = cvp_get_inst_validate(v27[16], v27);
          if ( inst_validate )
          {
            v46 = (unsigned int *)inst_validate;
            print_hfi_queue_info(v6);
            cvp_put_inst(v46);
            goto LABEL_79;
          }
          v28 = msm_cvp_debug;
          v29 = msm_cvp_debug_out;
          if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
          {
            printk(v31, *(unsigned int *)(v33 + 1800), *(unsigned int *)(v33 + 1804), "warn");
            v28 = msm_cvp_debug;
            v29 = msm_cvp_debug_out;
          }
          v27 = (__int64 *)v34;
          if ( v34 == v26 )
            goto LABEL_79;
        }
      }
      goto LABEL_79;
    }
    if ( v7 == 5 )
    {
      memset(s, 0, 0x2F8u);
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v47 = _ReadStatusReg(SP_EL0);
        printk(&unk_87991, *(unsigned int *)(v47 + 1800), *(unsigned int *)(v47 + 1804), &unk_8E7CE);
      }
      mutex_lock(v5);
      v9 = (__int64 *)(a1 - 928);
      v10 = *(__int64 **)(a1 - 928);
      if ( v10 == v9 )
      {
LABEL_11:
        mutex_unlock(v5);
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v11 = _ReadStatusReg(SP_EL0);
          v12 = *(unsigned int *)(v11 + 1800);
          v13 = *(unsigned int *)(v11 + 1804);
          v14 = &unk_8471F;
LABEL_69:
          printk(v14, v12, v13, &unk_8E7CE);
          goto LABEL_80;
        }
      }
      else
      {
        while ( 1 )
        {
          v15 = (__int64 *)*v10;
          if ( v10 )
          {
            if ( *((_DWORD *)v10 + 82) != 9 )
              break;
          }
          v10 = (__int64 *)*v10;
          if ( v15 == v9 )
            goto LABEL_11;
        }
        if ( (msm_cvp_debug & 4) != 0 && !msm_cvp_debug_out )
          printk(&unk_8F8CC, "info", v10, v8);
        s[1] = v10;
        v16 = mutex_unlock(v5);
        LODWORD(s[0]) = 255;
        s[2] = 0x2F880000009LL;
        handle_session_error(v16, (__int64)s);
      }
      goto LABEL_80;
    }
LABEL_36:
    mutex_lock(a1 - 1208);
    if ( *(_DWORD *)(a1 - 904) == 2 )
    {
      v19 = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
        {
          v24 = *(_DWORD *)(v19 + 1800);
          v25 = *(_DWORD *)(v19 + 1804);
          get_aon_time();
          printk(&unk_90CD5, v24, v25, "warn");
        }
        *(_BYTE *)(a1 + 60) = 1;
        v20 = (__int64 (__fastcall *)(__int64, __int64))v6[3];
        if ( !v20 )
          break;
        v21 = *v6;
        v22 = *(unsigned int *)(a1 + 32);
        if ( *((_DWORD *)v20 - 1) != 675362894 )
          __break(0x8228u);
        v23 = v20(v21, v22);
        if ( v23 != -11 )
        {
          if ( v23 )
          {
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              v51 = _ReadStatusReg(SP_EL0);
              printk(&unk_9722E, *(unsigned int *)(v51 + 1800), *(unsigned int *)(v51 + 1804), &unk_8E7CE);
            }
            *(_BYTE *)(a1 + 60) = 0;
          }
          break;
        }
        *(_BYTE *)(a1 + 60) = 0;
        mutex_unlock(v5);
        usleep_range_state(500, 1000, 2);
        if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
          printk(&unk_9720B, *(unsigned int *)(v19 + 1800), *(unsigned int *)(v19 + 1804), "warn");
        mutex_lock(v5);
        if ( *(_DWORD *)(a1 - 904) != 2 )
          goto LABEL_70;
      }
    }
    else
    {
LABEL_70:
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
      {
        v45 = _ReadStatusReg(SP_EL0);
        printk(&unk_8D3E3, *(unsigned int *)(v45 + 1800), *(unsigned int *)(v45 + 1804), "warn");
      }
    }
LABEL_79:
    mutex_unlock(v5);
    goto LABEL_80;
  }
  if ( v7 != 7 )
  {
    if ( v7 == 8 )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v48 = _ReadStatusReg(SP_EL0);
        printk(&unk_919B9, *(unsigned int *)(v48 + 1800), *(unsigned int *)(v48 + 1804), &unk_8E7CE);
      }
      v18 = *(_QWORD *)(a1 - 928);
      if ( v18 != a1 - 928 )
      {
        if ( v18 || (v18 = 0x97E830004F900LL, a1 != 0x97E830004FCA0LL) )
        {
          if ( (msm_cvp_debug & 4) != 0 && !msm_cvp_debug_out )
          {
            v50 = v18;
            printk(&unk_86529, "info", v18, a4);
            v18 = v50;
          }
          handle_session_timeout(v18, 0);
        }
      }
      goto LABEL_80;
    }
    goto LABEL_36;
  }
  trigger_smmu_fault = 1;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v44 = _ReadStatusReg(SP_EL0);
    v12 = *(unsigned int *)(v44 + 1800);
    v13 = *(unsigned int *)(v44 + 1804);
    v14 = &unk_8F908;
    goto LABEL_69;
  }
LABEL_80:
  _ReadStatusReg(SP_EL0);
}
