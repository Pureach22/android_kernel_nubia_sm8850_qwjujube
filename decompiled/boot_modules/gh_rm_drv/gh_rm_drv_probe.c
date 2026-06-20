__int64 __fastcall gh_rm_drv_probe(__int64 a1)
{
  __int64 node_opts_by_path; // x0
  __int64 compatible_child; // x0
  __int64 v4; // x20
  __int64 parent; // x0
  __int64 v6; // x22
  __int64 matching_fwspec; // x0
  int v8; // w0
  unsigned __int64 compatible_node; // x0
  unsigned __int64 v10; // x22
  unsigned __int64 v11; // x0
  int variable_u32_array; // w0
  char *v13; // x20
  int *v14; // x8
  __int64 result; // x0
  const char *v16; // x1
  unsigned int v17; // w20
  unsigned int v18; // w20
  __int64 v19; // x0
  unsigned int string_helper; // w0
  int v21; // w25
  unsigned __int64 v22; // x24
  __int64 v23; // x21
  __int64 v24; // x27
  unsigned __int64 v25; // x28
  unsigned __int64 v26; // x20
  bool v27; // cf
  const char *v28; // x26
  size_t v29; // x2
  _QWORD *v30; // x1
  __int64 v31; // x0
  int v32; // w0
  int v33; // w25
  unsigned int vm_id_info; // w0
  __int64 v35; // x2
  unsigned int v36; // w0
  char *s1; // [xsp+0h] [xbp-C0h] BYREF
  __int64 v38; // [xsp+8h] [xbp-B8h] BYREF
  _QWORD v39[2]; // [xsp+10h] [xbp-B0h] BYREF
  __int64 v40; // [xsp+20h] [xbp-A0h]
  __int64 v41; // [xsp+28h] [xbp-98h]
  unsigned int v42; // [xsp+30h] [xbp-90h] BYREF
  unsigned __int16 v43; // [xsp+34h] [xbp-8Ch] BYREF
  __int64 v44; // [xsp+38h] [xbp-88h] BYREF
  __int64 v45; // [xsp+40h] [xbp-80h]
  __int64 v46; // [xsp+48h] [xbp-78h]
  __int64 v47; // [xsp+50h] [xbp-70h]
  __int64 v48; // [xsp+58h] [xbp-68h]
  __int64 v49; // [xsp+60h] [xbp-60h]
  __int64 v50; // [xsp+68h] [xbp-58h]
  __int64 v51; // [xsp+70h] [xbp-50h]
  __int64 v52; // [xsp+78h] [xbp-48h]
  __int64 v53; // [xsp+80h] [xbp-40h]
  __int64 v54; // [xsp+88h] [xbp-38h]
  __int64 v55; // [xsp+90h] [xbp-30h]
  __int64 v56; // [xsp+98h] [xbp-28h]
  _QWORD v57[4]; // [xsp+A0h] [xbp-20h] BYREF

  v57[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  rm = *(_QWORD *)(a1 + 144);
  if ( !rm )
  {
    dev_err(a1, "Failed to get the rm pointer\n");
    result = 4294967277LL;
    goto LABEL_72;
  }
  node_opts_by_path = of_find_node_opts_by_path("/hypervisor", 0);
  if ( node_opts_by_path
    && (compatible_child = of_get_compatible_child(node_opts_by_path, "gunyah-resource-manager")) != 0 )
  {
    v4 = *(_QWORD *)(compatible_child + 112);
  }
  else
  {
    v4 = of_root;
  }
  parent = of_irq_find_parent();
  gh_rm_intc = parent;
  if ( !parent )
  {
    v16 = "Failed to get the IRQ parent node\n";
    goto LABEL_67;
  }
  v6 = parent + 24;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v44 = parent + 24;
  v45 = 0;
  matching_fwspec = irq_find_matching_fwspec(&v44, 1);
  if ( !matching_fwspec )
  {
    v52 = 0;
    v53 = 0;
    v50 = 0;
    v51 = 0;
    v48 = 0;
    v49 = 0;
    v46 = 0;
    v47 = 0;
    v44 = v6;
    v45 = 0;
    gh_rm_irq_domain = irq_find_matching_fwspec(&v44, 0);
    if ( gh_rm_irq_domain )
      goto LABEL_10;
    v16 = "Failed to get IRQ domain associated with RM\n";
LABEL_67:
    dev_err(a1, v16);
    result = 4294967290LL;
    goto LABEL_72;
  }
  gh_rm_irq_domain = matching_fwspec;
LABEL_10:
  v8 = gunyah_rm_notifier_register(rm, &gh_rm_core_notifier_blk);
  if ( !v8 )
  {
    v55 = 0;
    v56 = 0;
    v53 = 0;
    v54 = 0;
    v51 = 0;
    v52 = 0;
    v49 = 0;
    v50 = 0;
    v47 = 0;
    v48 = 0;
    v45 = 0;
    v46 = 0;
    v44 = 0;
    s1 = nullptr;
    v38 = 0;
    gh_init_vm_prop_table();
    compatible_node = of_find_compatible_node(v4, 0, "qcom,gunyah-vm-id-1.0");
    if ( compatible_node && (v10 = compatible_node, compatible_node < 0xFFFFFFFFFFFFF001LL)
      || (v11 = of_find_compatible_node(v4, 0, "qcom,haven-vm-id-1.0")) != 0 && (v10 = v11, v11 < 0xFFFFFFFFFFFFF001LL) )
    {
      variable_u32_array = of_property_read_variable_u32_array(v10, "qcom,vmid", (char *)&v38 + 4, 1, 0);
      if ( variable_u32_array < 0 )
      {
        v18 = variable_u32_array;
        dev_err(a1, "Could not read vmid: %d\n", variable_u32_array);
        result = v18;
        if ( v18 != -19 )
          goto LABEL_72;
        goto LABEL_71;
      }
      if ( (of_property_read_variable_u32_array(v10, "qcom,owner-vmid", &v38, 1, 0) & 0x80000000) == 0 )
      {
        if ( !(unsigned int)of_property_read_string(v10, "qcom,image-name", &s1) )
        {
          v13 = s1;
          if ( *s1 )
          {
            if ( !strcmp(s1, "qcom,trustedvm") )
            {
              v14 = &dword_14008;
            }
            else if ( !strcmp(v13, "qcom,cpusysvm") )
            {
              v14 = &dword_14020;
            }
            else
            {
              if ( strcmp(v13, "qcom,oemvm") )
              {
                printk(&unk_137B9, v13);
                goto LABEL_33;
              }
              v14 = &dword_14038;
            }
          }
          else
          {
            v14 = &vm_name_map;
          }
          v19 = (unsigned int)*v14;
          if ( (_DWORD)v19 != 5 )
          {
LABEL_34:
            LOWORD(v44) = WORD2(v38);
            gh_update_vm_prop_table(v19, &v44);
            LOWORD(v44) = v38;
            gh_update_vm_prop_table(1, &v44);
            v43 = 0;
            v42 = 0;
            v40 = 0;
            v41 = 0;
            v39[0] = 0;
            v39[1] = 0;
            v57[0] = 0;
            v57[1] = 0;
            string_helper = of_property_read_string_helper(v10, "qcom,peers", 0, 0, 0);
            if ( string_helper )
            {
              v21 = string_helper;
              if ( (string_helper & 0x80000000) != 0
                || (v22 = 8LL * string_helper, (v23 = _kmalloc_noprof(v22, 3520)) == 0) )
              {
                dev_err(a1, "Failed to allocate memory\n");
              }
              else
              {
                if ( (of_property_read_string_helper(v10, "qcom,peers", v23, v21, 0) & 0x80000000) != 0 )
                {
                  dev_err(a1, "Failed to find qcom,peers\n");
                }
                else if ( v21 >= 1 )
                {
                  v24 = 8LL * (unsigned int)v21;
                  v25 = 0;
                  v26 = v24;
                  while ( 1 )
                  {
                    if ( v26 < 8 || (v25 & 0x8000000000000000LL) != 0 || v22 < v25 || (v27 = v26 >= 8, v26 -= 8LL, !v27) )
                      __break(1u);
                    v28 = *(const char **)(v23 + v25);
                    if ( !v28 )
                      goto LABEL_41;
                    if ( strnstr(*(_QWORD *)(v23 + v25), "vm-name:", 8) )
                    {
                      v29 = strlen(v28 + 8);
                      v30 = v28 + 8;
                      v31 = 0;
                      goto LABEL_55;
                    }
                    if ( strnstr(v28, "vm-uri:", 7) )
                      break;
                    if ( !strnstr(v28, "vm-guid:", 8) )
                    {
                      dev_err(a1, "Unknown peer type:%s\n", v28);
                      goto LABEL_41;
                    }
                    v32 = uuid_parse(v28 + 8, v57);
                    if ( !v32 )
                    {
                      v30 = v57;
                      v31 = 2;
                      v29 = 16;
LABEL_55:
                      v33 = gh_rm_vm_lookup(v31, v30, v29, &v43);
                      if ( v33 < 0 )
                        goto LABEL_40;
                      goto LABEL_56;
                    }
                    v33 = v32;
                    dev_err(a1, "Invalid GUID:%s\n", v28 + 8);
                    if ( v33 < 0 )
                    {
LABEL_40:
                      dev_err(a1, "lookup %s failed, VM is not running ret=%d\n", v28, v33);
                      goto LABEL_41;
                    }
LABEL_56:
                    vm_id_info = gh_rm_get_vm_id_info(v43);
                    v35 = v43;
                    if ( (vm_id_info & 0x80000000) == 0 )
                    {
                      vm_id_info = gh_rm_get_vm_name(v43, &v42);
                      if ( (vm_id_info & 0x80000000) == 0 )
                      {
                        gh_rm_get_vminfo(v42, v39);
                        v36 = gh_rm_populate_hyp_res(v43, v40);
                        if ( (v36 & 0x80000000) != 0 )
                          dev_err(a1, "Failed to get hyp resources for vmid = %d ret = %d\n", v43, v36);
                        goto LABEL_41;
                      }
                      v35 = v43;
                    }
                    dev_err(a1, "Failed to get vmid info for vmid = %d ret = %d\n", v35, vm_id_info);
LABEL_41:
                    v25 += 8LL;
                    if ( v24 == v25 )
                      goto LABEL_69;
                  }
                  v29 = strlen(v28 + 7);
                  v30 = v28 + 7;
                  v31 = 1;
                  goto LABEL_55;
                }
LABEL_69:
                kfree(v23);
              }
            }
            srcu_notifier_chain_register(&gh_rm_notifier, &gh_rm_status_nb);
            gh_rm_core_initialized = 1;
            result = queue_work_on(32, system_wq, &gh_rm_get_svm_res_work);
            goto LABEL_71;
          }
        }
LABEL_33:
        v19 = 2;
        goto LABEL_34;
      }
      LOWORD(v44) = WORD2(v38);
      gh_update_vm_prop_table(1, &v44);
      srcu_notifier_chain_register(&gh_rm_notifier, &gh_rm_status_nb);
      result = gunyah_qtvm_register_notifier(&gh_vm_status_nb);
      gh_rm_core_initialized = 1;
    }
    else
    {
      result = dev_err(a1, "Could not find vm-id node\n");
    }
LABEL_71:
    result = gh_rm_setup_feature_scm_assign(result);
    goto LABEL_72;
  }
  v17 = v8;
  dev_err(a1, "Failed to register to RM notifier %d\n", v8);
  result = v17;
LABEL_72:
  _ReadStatusReg(SP_EL0);
  return result;
}
