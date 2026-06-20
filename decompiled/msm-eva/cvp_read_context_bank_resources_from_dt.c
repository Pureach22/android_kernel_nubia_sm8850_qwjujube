__int64 __fastcall cvp_read_context_bank_resources_from_dt(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x20
  __int64 v3; // x21
  __int64 v5; // x0
  __int64 v6; // x19
  __int64 v7; // x2
  __int64 v8; // x3
  __int64 v9; // x2
  __int64 *v10; // x1
  const char *v11; // x22
  int v12; // w8
  int v13; // w9
  __int64 result; // x0
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x9
  unsigned __int64 v17; // x9
  unsigned __int64 StatusReg; // x8
  __int64 v19; // x2
  __int64 v20; // x3
  unsigned __int64 v21; // x8
  unsigned int v22; // w20
  __int64 property; // x0
  char v24; // w8
  unsigned __int64 domain_for_dev; // x0
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x8
  _QWORD *v28; // x8
  __int64 v29; // x9
  unsigned __int64 v30; // x8
  unsigned int v31; // w19
  unsigned int v32; // w9
  unsigned __int64 v33; // x8

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 112);
    if ( v1 )
    {
      v2 = *(_QWORD *)(v1 + 152);
      if ( v2 )
      {
        v3 = *(_QWORD *)(a1 + 760);
        v5 = devm_kmalloc(a1 + 16, 56, 3520);
        if ( !v5 )
        {
          result = 4294967284LL;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            StatusReg = _ReadStatusReg(SP_EL0);
            printk(&unk_936C1, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
            result = 4294967284LL;
          }
          goto LABEL_63;
        }
        v6 = v5;
        if ( (unsigned int)of_property_read_string(v3, "label", v5 + 16)
          && (msm_cvp_debug & 0x100) != 0
          && !msm_cvp_debug_out )
        {
          printk(&unk_8AEA0, "core", v7, v8);
        }
        *(_QWORD *)v6 = v6;
        v9 = v2 + 944;
        *(_QWORD *)(v6 + 8) = v6;
        v10 = *(__int64 **)(v2 + 952);
        if ( v6 == v2 + 944 || v10 == (__int64 *)v6 || *v10 != v9 )
        {
          _list_add_valid_or_report(v6, v10, v9);
          if ( (msm_cvp_debug & 0x100) == 0 )
            goto LABEL_15;
        }
        else
        {
          *(_QWORD *)(v2 + 952) = v6;
          *(_QWORD *)v6 = v9;
          *(_QWORD *)(v6 + 8) = v10;
          *v10 = v6;
          if ( (msm_cvp_debug & 0x100) == 0 )
            goto LABEL_15;
        }
        if ( !msm_cvp_debug_out )
          printk(&unk_96A17, "core", "msm_cvp_populate_context_bank", *(_QWORD *)(v6 + 16));
LABEL_15:
        v11 = *(const char **)(v6 + 16);
        if ( !strcmp(v11, "cvp_camera") )
        {
          *(_BYTE *)(v6 + 28) = 1;
          result = msm_cvp_setup_context_bank(v2 + 608, v6, a1 + 16);
          if ( (_DWORD)result )
          {
            if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
              goto LABEL_59;
            v21 = _ReadStatusReg(SP_EL0);
            v22 = result;
            printk(&unk_91D2E, *(unsigned int *)(v21 + 1800), *(unsigned int *)(v21 + 1804), &unk_8E7CE);
            goto LABEL_52;
          }
          goto LABEL_68;
        }
        if ( !strcmp(v11, "cvp_hlos") )
        {
          v12 = -1879048192;
          v13 = 1258291200;
        }
        else if ( !strcmp(v11, "cvp_sec_nonpixel") )
        {
          v12 = 629145600;
          v13 = 0x1000000;
        }
        else
        {
          if ( strcmp(v11, "cvp_sec_pixel") )
            goto LABEL_39;
          v12 = 612368384;
          v13 = 645922816;
        }
        *(_DWORD *)(v6 + 32) = v13;
        *(_DWORD *)(v6 + 36) = v12;
LABEL_39:
        property = of_find_property(v3, "qcom,iommu-vmid", 0);
        v24 = BYTE1(msm_cvp_debug);
        *(_BYTE *)(v6 + 28) = property != 0;
        if ( (v24 & 1) != 0 && !msm_cvp_debug_out )
          printk(&unk_936F5, "core", *(_QWORD *)(v6 + 16), property != 0);
        if ( (of_property_read_variable_u32_array(v3, "buffer-types", v6 + 24, 1, 0) & 0x80000000) != 0 )
        {
          result = 4294967294LL;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v27 = _ReadStatusReg(SP_EL0);
            printk(&unk_8A409, *(unsigned int *)(v27 + 1800), *(unsigned int *)(v27 + 1804), &unk_8E7CE);
            result = 4294967294LL;
          }
          goto LABEL_59;
        }
        if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
          printk(&unk_93724, "core", *(_QWORD *)(v6 + 16), *(unsigned int *)(v6 + 32));
        domain_for_dev = iommu_get_domain_for_dev(a1 + 16);
        *(_QWORD *)(v6 + 48) = domain_for_dev;
        if ( !domain_for_dev || domain_for_dev >= 0xFFFFFFFFFFFFF001LL )
        {
          result = 4294967277LL;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v33 = _ReadStatusReg(SP_EL0);
            printk(&unk_83478, *(unsigned int *)(v33 + 1800), *(unsigned int *)(v33 + 1804), &unk_8E7CE);
            result = 4294967277LL;
          }
          goto LABEL_59;
        }
        result = msm_cvp_setup_context_bank(v2 + 608, v6, a1 + 16);
        if ( (_DWORD)result )
        {
          if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
            goto LABEL_59;
          v26 = _ReadStatusReg(SP_EL0);
          v22 = result;
          printk(&unk_91D67, *(unsigned int *)(v26 + 1800), *(unsigned int *)(v26 + 1804), &unk_8E7CE);
LABEL_52:
          result = v22;
LABEL_59:
          v28 = *(_QWORD **)(v6 + 8);
          if ( *v28 == v6 && (v29 = *(_QWORD *)v6, *(_QWORD *)(*(_QWORD *)v6 + 8LL) == v6) )
          {
            *(_QWORD *)(v29 + 8) = v28;
            *v28 = v29;
          }
          else
          {
            _list_del_entry_valid_or_report(v6);
            result = v32;
          }
          *(_QWORD *)v6 = 0xDEAD000000000100LL;
          *(_QWORD *)(v6 + 8) = 0xDEAD000000000122LL;
LABEL_63:
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v30 = _ReadStatusReg(SP_EL0);
            v31 = result;
            printk(&unk_8D787, *(unsigned int *)(v30 + 1800), *(unsigned int *)(v30 + 1804), &unk_8E7CE);
            return v31;
          }
          return result;
        }
        iommu_set_fault_handler(*(_QWORD *)(v6 + 48), msm_cvp_smmu_fault_handler, v2);
LABEL_68:
        result = 0;
        if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
        {
          printk(&unk_8999C, "core", v19, v20);
          return 0;
        }
        return result;
      }
      result = 4294967274LL;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v17 = _ReadStatusReg(SP_EL0);
        printk(&unk_8D745, *(unsigned int *)(v17 + 1800), *(unsigned int *)(v17 + 1804), &unk_8E7CE);
        return 4294967274LL;
      }
    }
    else
    {
      result = 4294967277LL;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v16 = _ReadStatusReg(SP_EL0);
        printk(&unk_849F0, *(unsigned int *)(v16 + 1800), *(unsigned int *)(v16 + 1804), &unk_8E7CE);
        return 4294967277LL;
      }
    }
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v15 = _ReadStatusReg(SP_EL0);
      printk(&unk_8D714, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
