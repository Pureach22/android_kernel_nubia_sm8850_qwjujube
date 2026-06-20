__int64 __fastcall qcom_smp2p_probe(__int64 a1)
{
  __int64 v2; // x22
  _QWORD *v3; // x0
  _QWORD *v4; // x26
  _QWORD *v5; // x20
  _QWORD *v6; // x19
  _QWORD *v7; // x2
  __int64 v8; // x0
  unsigned int variable_u32_array; // w0
  unsigned int irq; // w23
  unsigned __int64 v11; // x0
  unsigned int v12; // w27
  const char *v13; // x1
  __int64 v14; // x0
  __int64 v15; // x25
  __int64 v16; // x0
  unsigned __int64 v17; // x0
  unsigned int v18; // w0
  __int64 next_available_child; // x0
  __int64 v20; // x25
  _QWORD *v21; // x0
  _QWORD *v22; // x1
  __int64 v23; // x0
  _QWORD *v24; // x28
  unsigned int string; // w0
  unsigned __int64 v26; // x0
  unsigned __int64 v27; // x8
  _QWORD *v28; // x2
  _QWORD *v29; // x2
  __int64 v30; // x1
  __int64 v31; // x0
  unsigned __int64 v32; // x0
  unsigned __int64 v33; // x24
  unsigned int v34; // w25
  signed int v35; // w28
  _QWORD *v36; // x21
  _QWORD *v37; // x23
  const char *v38; // x1
  __int64 v39; // x0
  int v40; // w2
  __int64 v41; // x0
  unsigned int v42; // w0
  _QWORD *v43; // x22
  _QWORD *v44; // x21
  _QWORD *v45; // x21
  _QWORD *v46; // x22
  unsigned int i; // [xsp+4h] [xbp-7Ch]
  __int64 v49; // [xsp+10h] [xbp-70h] BYREF
  char s1[8]; // [xsp+18h] [xbp-68h] BYREF
  __int64 v51; // [xsp+20h] [xbp-60h]
  __int64 v52; // [xsp+28h] [xbp-58h]
  __int64 v53; // [xsp+30h] [xbp-50h]
  __int64 v54; // [xsp+38h] [xbp-48h]
  __int64 v55; // [xsp+40h] [xbp-40h]
  void *v56; // [xsp+48h] [xbp-38h]
  _QWORD *v57; // [xsp+50h] [xbp-30h]
  __int64 v58; // [xsp+58h] [xbp-28h]
  __int64 v59; // [xsp+60h] [xbp-20h]
  __int64 v60; // [xsp+68h] [xbp-18h]
  __int64 v61; // [xsp+70h] [xbp-10h]
  __int64 v62; // [xsp+78h] [xbp-8h]

  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !ilc )
    ilc = ipc_log_context_create(2, "smp2p", 0);
  v2 = a1 + 16;
  v3 = (_QWORD *)devm_kmalloc(a1 + 16, 176, 3520);
  if ( !v3 )
  {
    v12 = -12;
    goto LABEL_78;
  }
  v4 = v3 + 18;
  v5 = v3 + 20;
  *v3 = v2;
  v3[18] = v3 + 18;
  v6 = v3;
  v3[19] = v3 + 18;
  v7 = v3 + 3;
  v3[20] = v3 + 20;
  v3[21] = v3 + 20;
  v8 = *(_QWORD *)(a1 + 760);
  *(_QWORD *)(a1 + 168) = v6;
  variable_u32_array = of_property_read_variable_u32_array(v8, "qcom,smem", v7, 2, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v12 = variable_u32_array;
    goto LABEL_78;
  }
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,local-pid", v6 + 6, 1, 0) & 0x80000000) != 0
    || (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,remote-pid", (char *)v6 + 52, 1, 0) & 0x80000000) != 0 )
  {
    v13 = "failed to read %s\n";
    v14 = a1 + 16;
    goto LABEL_15;
  }
  irq = platform_get_irq(a1, 0);
  if ( (irq & 0x80000000) != 0 )
  {
    v12 = irq;
    goto LABEL_78;
  }
  v6[10] = v2;
  *((_BYTE *)v6 + 104) = 1;
  v11 = mbox_request_channel(v6 + 10, 0);
  v6[17] = v11;
  if ( v11 < 0xFFFFFFFFFFFFF001LL )
  {
LABEL_22:
    v18 = qcom_smp2p_alloc_outbound_item(v6);
    if ( (v18 & 0x80000000) != 0 )
    {
      v12 = v18;
    }
    else
    {
      next_available_child = of_get_next_available_child(*(_QWORD *)(a1 + 760), 0);
      if ( next_available_child )
      {
        v20 = next_available_child;
        _ReadStatusReg(SP_EL0);
        do
        {
          v23 = _kmalloc_cache_noprof(mbox_send_message, 3520, 104);
          v24 = (_QWORD *)v23;
          if ( !v23 )
            goto LABEL_71;
          *(_QWORD *)(v23 + 16) = v6;
          *(_DWORD *)(v23 + 96) = 0;
          string = of_property_read_string(v20, "qcom,entry-name", v23 + 24);
          if ( (string & 0x80000000) != 0 )
            goto LABEL_60;
          if ( of_find_property(v20, "interrupt-controller", 0) )
          {
            *(_QWORD *)s1 = v20 + 24;
            v51 = 0x2000000000LL;
            v52 = 32;
            v53 = 0;
            v54 = 0;
            v55 = 0;
            v56 = &smp2p_irq_ops;
            v57 = v24;
            v58 = 0;
            v59 = 0;
            v60 = 0;
            v61 = 0;
            v26 = irq_domain_instantiate(s1);
            if ( v26 <= 0xFFFFFFFFFFFFF000LL )
              v27 = v26;
            else
              v27 = 0;
            v24[6] = v27;
            if ( !v27 )
            {
              dev_err(*v6, "failed to add irq_domain\n");
              goto LABEL_71;
            }
            v28 = (_QWORD *)*v4;
            if ( *(_QWORD **)(*v4 + 8LL) == v4 && v24 != v4 && v28 != v24 )
            {
              v28[1] = v24;
              *v24 = v28;
              v24[1] = v4;
              *v4 = v24;
              goto LABEL_32;
            }
            v21 = v24;
            v22 = v4;
          }
          else
          {
            string = qcom_smp2p_outbound_entry(v6, v24, v20);
            if ( (string & 0x80000000) != 0 )
            {
LABEL_60:
              v12 = string;
              goto LABEL_72;
            }
            v29 = (_QWORD *)*v5;
            if ( *(_QWORD **)(*v5 + 8LL) == v5 && v24 != v5 && v29 != v24 )
            {
              v29[1] = v24;
              *v24 = v29;
              v24[1] = v5;
              *v5 = v24;
              goto LABEL_32;
            }
            v21 = v24;
            v22 = v5;
          }
          _list_add_valid_or_report(v21, v22);
LABEL_32:
          v20 = of_get_next_available_child(*(_QWORD *)(a1 + 760), v20);
        }
        while ( v20 );
      }
      v30 = *((unsigned int *)v6 + 6);
      v31 = *((unsigned int *)v6 + 13);
      v49 = 0;
      v32 = qcom_smem_get(v31, v30, &v49);
      if ( v32 <= 0xFFFFFFFFFFFFF000LL )
      {
        v6[1] = v32;
        v33 = v32;
        if ( *(_BYTE *)(v32 + 4) )
        {
          v34 = *((_DWORD *)v6 + 8);
          v35 = *(unsigned __int16 *)(v32 + 14);
          for ( i = irq; (int)v34 < v35; ++v34 )
          {
            v36 = v4;
            v37 = (_QWORD *)(v33 + 20 + 20LL * v34);
            while ( 1 )
            {
              v36 = (_QWORD *)*v36;
              if ( v36 == v4 )
                break;
              if ( v34 > 0xF )
                __break(0x5512u);
              v38 = (const char *)v36[3];
              *(_QWORD *)s1 = *v37;
              v51 = v37[1];
              if ( !strcmp(s1, v38) )
              {
                v36[4] = v37 + 2;
                *((_DWORD *)v36 + 10) = readl();
                v35 = *(unsigned __int16 *)(v33 + 14);
                break;
              }
            }
          }
          irq = i;
          *((_DWORD *)v6 + 8) = v34;
        }
      }
      __dsb(0xEu);
      v39 = v6[17];
      if ( v39 )
      {
        mbox_send_message(v39, 0);
        mbox_client_txdone(v6[17], 0);
      }
      else
      {
        regmap_write(v6[8], *((unsigned int *)v6 + 18), 1LL << *((_DWORD *)v6 + 19));
      }
      v40 = *((_DWORD *)v6 + 13);
      *((_DWORD *)v6 + 14) = irq;
      v41 = kasprintf(3264, "smp2p_%d", v40);
      v6[5] = v41;
      if ( v41 )
      {
        v42 = devm_request_threaded_irq(v2, irq, 0, qcom_smp2p_intr, 0x2000, v41, v6);
        if ( v42 )
        {
          v12 = v42;
          dev_err(v2, "failed to request interrupt\n");
        }
        else
        {
          device_set_wakeup_capable(v2, 1);
          v12 = dev_pm_set_wake_irq(v2, irq);
          if ( !v12 )
            goto LABEL_78;
          dev_pm_clear_wake_irq(v2);
        }
      }
      else
      {
LABEL_71:
        v12 = -12;
      }
LABEL_72:
      v43 = (_QWORD *)*v4;
      if ( (_QWORD *)*v4 != v4 )
      {
        do
        {
          v44 = (_QWORD *)*v43;
          irq_domain_remove(v43[6]);
          kfree(v43);
          v43 = v44;
        }
        while ( v44 != v4 );
      }
      v45 = (_QWORD *)*v5;
      if ( (_QWORD *)*v5 != v5 )
      {
        do
        {
          v46 = (_QWORD *)*v45;
          qcom_smem_state_unregister(v45[11]);
          kfree(v45);
          v45 = v46;
        }
        while ( v46 != v5 );
      }
      kfree(v6[5]);
      *(_WORD *)(v6[2] + 14LL) = 0;
    }
    mbox_free_channel(v6[17]);
    goto LABEL_78;
  }
  if ( v11 == -19 )
  {
    v15 = *v6;
    v6[17] = 0;
    v16 = *(_QWORD *)(v15 + 744);
    v58 = 0;
    v59 = 0;
    v56 = nullptr;
    v57 = nullptr;
    v54 = 0;
    v55 = 0;
    v52 = 0;
    v53 = 0;
    *(_QWORD *)s1 = 0;
    v51 = 0;
    if ( (unsigned int)_of_parse_phandle_with_args(v16, "qcom,ipc", 0, 0, 0, s1) || !*(_QWORD *)s1 )
    {
      dev_err(v15, "no qcom,ipc node\n");
      v12 = -19;
      goto LABEL_78;
    }
    v17 = syscon_node_to_regmap();
    v6[8] = v17;
    if ( v17 > 0xFFFFFFFFFFFFF000LL )
    {
      v12 = v17;
      goto LABEL_78;
    }
    if ( (of_property_read_u32_index(*(_QWORD *)(v15 + 744), "qcom,ipc", 1, v6 + 9) & 0x80000000) != 0 )
    {
      v13 = "no offset in %s\n";
    }
    else
    {
      if ( (of_property_read_u32_index(*(_QWORD *)(v15 + 744), "qcom,ipc", 2, (char *)v6 + 76) & 0x80000000) == 0 )
        goto LABEL_22;
      v13 = "no bit in %s\n";
    }
    v14 = v15;
LABEL_15:
    dev_err(v14, v13);
    v12 = -22;
    goto LABEL_78;
  }
  v12 = v11;
LABEL_78:
  _ReadStatusReg(SP_EL0);
  return v12;
}
