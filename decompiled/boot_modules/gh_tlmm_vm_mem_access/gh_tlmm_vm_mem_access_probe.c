__int64 __fastcall gh_tlmm_vm_mem_access_probe(__int64 a1)
{
  __int64 v1; // x19
  _QWORD *v3; // x0
  __int64 v4; // x22
  _QWORD *v5; // x20
  __int64 *v6; // x23
  __int64 next_available_child; // x0
  __int64 v8; // x24
  __int64 v9; // x0
  __int64 v10; // x27
  unsigned int v11; // w0
  unsigned int v12; // w0
  __int64 v13; // x2
  __int64 result; // x0
  unsigned __int64 compatible_node; // x0
  _QWORD *v16; // x20
  __int64 v17; // x1
  unsigned __int64 v18; // x2
  _QWORD *v19; // x19
  unsigned int v20; // w20
  const char *v21; // x1
  __int16 v22[2]; // [xsp+8h] [xbp-18h] BYREF
  int v23; // [xsp+Ch] [xbp-14h] BYREF
  int v24; // [xsp+10h] [xbp-10h] BYREF
  int v25; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+18h] [xbp-8h]

  v1 = a1 + 16;
  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v22[0] = 0;
  v3 = (_QWORD *)devm_kmalloc(a1 + 16, 184, 3520);
  if ( v3 )
  {
    v4 = *(_QWORD *)(a1 + 760);
    v5 = v3;
    *(_QWORD *)(a1 + 168) = v3;
    *v3 = v1;
    v25 = 0;
    v24 = 0;
    if ( of_find_property(v4, "qcom,master", 0) )
    {
      v6 = v5 + 17;
      v5[17] = v5 + 17;
      v5[18] = v5 + 17;
      next_available_child = of_get_next_available_child(v4, 0);
      if ( next_available_child )
      {
        v8 = next_available_child;
        while ( 1 )
        {
          v9 = devm_kmalloc(v1, 64, 3520);
          if ( !v9 )
          {
            v20 = -12;
            goto LABEL_35;
          }
          v10 = v9;
          *(_QWORD *)(v9 + 16) = v5;
          v11 = of_property_read_variable_u32_array(v8, "qcom,vmid", &v25, 1, 0);
          if ( (v11 & 0x80000000) != 0 )
          {
            v21 = "Failed to find dest vmid:%d\n";
            goto LABEL_34;
          }
          *(_WORD *)(v10 + 28) = v25;
          v11 = of_property_read_variable_u32_array(v8, "qcom,label", &v24, 1, 0);
          if ( (v11 & 0x80000000) != 0 )
            break;
          *(_DWORD *)(v10 + 32) = v24;
          v12 = gh_tlmm_vm_parse_gpio_list(a1, v10, v8);
          if ( v12 )
            goto LABEL_29;
          v13 = *v6;
          if ( *(__int64 **)(*v6 + 8) != v6 || (__int64 *)v10 == v6 || v13 == v10 )
          {
            _list_add_valid_or_report(v10, v5 + 17);
          }
          else
          {
            *(_QWORD *)(v13 + 8) = v10;
            *(_QWORD *)v10 = v13;
            *(_QWORD *)(v10 + 8) = v6;
            *v6 = v10;
          }
          v8 = of_get_next_available_child(v4, v8);
          if ( !v8 )
            goto LABEL_18;
        }
        v21 = "Failed to find gunyah label:%d\n";
LABEL_34:
        v20 = v11;
        dev_err(v1, v21);
        goto LABEL_35;
      }
    }
    else
    {
      v12 = gh_tlmm_vm_parse_gpio_list(a1, v5 + 9, v4);
      if ( v12 )
      {
LABEL_29:
        v20 = v12;
LABEL_35:
        dev_err(v1, "Failed to populate TLMM VM info ret:%d\n", v20);
        goto LABEL_36;
      }
    }
LABEL_18:
    compatible_node = of_find_compatible_node(0, 0, "qcom,gunyah-vm-id-1.0");
    if ( compatible_node && compatible_node < 0xFFFFFFFFFFFFF001LL
      || (compatible_node = of_find_compatible_node(0, 0, "qcom,haven-vm-id-1.0")) != 0
      && compatible_node < 0xFFFFFFFFFFFFF001LL )
    {
      if ( (of_property_read_variable_u32_array(compatible_node, "qcom,owner-vmid", &v23, 1, 0) & 0x80000000) != 0 )
      {
        v18 = gh_mem_notifier_register(3, gh_tlmm_vm_mem_on_release_handler, v5);
        if ( v18 >= 0xFFFFFFFFFFFFF001LL )
        {
          dev_err(v1, "Failed to register on release notifier%ld\n", v18);
          result = 4294967274LL;
          goto LABEL_37;
        }
        v5[1] = gh_guest_memshare_nb_handler;
        v19 = v5 + 1;
        v5[7] = v18;
        *((_DWORD *)v5 + 6) = 0x7FFFFFFF;
        result = gunyah_qtvm_register_notifier(v5 + 1);
        if ( !(_DWORD)result )
        {
          v5[4] = gh_guest_memshare_notify_nb_handler;
          *((_DWORD *)v5 + 12) = 0x7FFFFFFF;
          result = gh_rm_register_notifier(v5 + 4);
          if ( (_DWORD)result )
          {
            v20 = result;
            gunyah_qtvm_unregister_notifier(v19);
LABEL_36:
            result = v20;
          }
        }
      }
      else
      {
        result = ghd_rm_get_vmid(0, v22);
        if ( !(_DWORD)result )
        {
          v5[19] = 0xFFFFFFFE00000LL;
          v16 = v5 + 19;
          v16[1] = v16 + 1;
          v16[2] = v16 + 1;
          v17 = system_wq;
          v16[3] = gh_tlmm_vm_mem_handle_fn;
          queue_work_on(32, v17, v16);
          result = 0;
        }
      }
    }
    else
    {
      dev_err(v1, "Could not find vm-id node\n");
      result = 4294967277LL;
    }
  }
  else
  {
    result = 4294967284LL;
  }
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
