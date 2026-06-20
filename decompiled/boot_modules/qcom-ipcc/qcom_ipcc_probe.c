unsigned __int64 __fastcall qcom_ipcc_probe(__int64 a1)
{
  __int64 v1; // x20
  _QWORD *v3; // x0
  _QWORD *v4; // x19
  unsigned __int64 result; // x0
  unsigned __int64 v6; // x22
  int v7; // w0
  int v8; // w3
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x22
  bool v12; // zf
  __int64 v13; // x8
  unsigned __int64 v14; // x0
  unsigned __int64 v15; // x8
  __int64 v16; // x8
  __int64 v17; // x23
  __int64 node_with_property; // x0
  __int64 v19; // x24
  int v20; // w0
  int v21; // w27
  unsigned int i; // w28
  unsigned __int64 v23; // x8
  __int64 v24; // x0
  int v25; // w9
  __int64 v26; // x0
  __int64 v27; // x0
  int v28; // w23
  __int64 v29; // x2
  __int64 v30; // x0
  __int64 v31; // x20
  __int64 v32; // x8
  unsigned __int64 v33; // x19
  __int64 v34; // [xsp+0h] [xbp-70h]
  __int64 v35; // [xsp+8h] [xbp-68h] BYREF
  __int64 v36; // [xsp+10h] [xbp-60h]
  __int64 v37; // [xsp+18h] [xbp-58h]
  __int64 v38; // [xsp+20h] [xbp-50h]
  __int64 v39; // [xsp+28h] [xbp-48h]
  __int64 v40; // [xsp+30h] [xbp-40h]
  void *v41; // [xsp+38h] [xbp-38h]
  _QWORD *v42; // [xsp+40h] [xbp-30h]
  __int64 v43; // [xsp+48h] [xbp-28h]
  __int64 v44; // [xsp+50h] [xbp-20h]
  __int64 v45; // [xsp+58h] [xbp-18h]
  __int64 v46; // [xsp+60h] [xbp-10h]
  __int64 v47; // [xsp+68h] [xbp-8h]

  v1 = a1 + 16;
  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (_QWORD *)devm_kmalloc(a1 + 16, 184, 3520);
  if ( !v3 )
  {
LABEL_23:
    result = 4294967284LL;
    goto LABEL_24;
  }
  v4 = v3;
  *v3 = v1;
  result = devm_platform_ioremap_resource(a1, 0);
  v4[1] = result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    v6 = result;
    v7 = readl(result + 8);
    if ( (v7 & 1) != 0 )
    {
      v28 = v7;
      dev_info(v1, "Clear on receive read is set from boot firmware\n");
      writel(v28 & 0xFFFFFFFE, v6 + 8);
    }
    result = platform_get_irq(a1, 0);
    *((_DWORD *)v4 + 45) = result;
    if ( (result & 0x80000000) == 0 )
    {
      v8 = qcom_ipcc_probe_id++;
      v9 = devm_kasprintf(v1, 3264, "ipcc_%d", v8);
      if ( v9 )
      {
        v10 = *(_QWORD *)(a1 + 760);
        v11 = v9;
        v37 = 0xFFFFFFFFLL;
        v38 = 0;
        v12 = v10 == 0;
        v13 = v10 + 24;
        v39 = 0;
        v40 = 0;
        if ( v12 )
          v13 = 0;
        v43 = 0;
        v44 = 0;
        v35 = v13;
        v36 = 0;
        v41 = &qcom_ipcc_irq_ops;
        v42 = v4;
        v45 = 0;
        v46 = 0;
        v14 = irq_domain_instantiate(&v35);
        v15 = v14 <= 0xFFFFFFFFFFFFF000LL ? v14 : 0LL;
        v4[2] = v15;
        if ( v15 )
        {
          v16 = *v4;
          v17 = *(_QWORD *)(a1 + 760);
          v43 = 0;
          v44 = 0;
          v41 = nullptr;
          v42 = nullptr;
          v39 = 0;
          v40 = 0;
          v37 = 0;
          v38 = 0;
          v35 = 0;
          v36 = 0;
          v34 = v16;
          *((_DWORD *)v4 + 44) = 0;
          node_with_property = of_find_node_with_property(0, "mboxes");
          if ( node_with_property )
          {
            v19 = node_with_property;
            do
            {
              if ( (of_device_is_available(v19) & 1) != 0 )
              {
                v20 = of_count_phandle_with_args(v19, "mboxes", "#mbox-cells");
                if ( v20 >= 1 )
                {
                  v21 = v20;
                  for ( i = 0; i != v21; ++i )
                  {
                    if ( !(unsigned int)_of_parse_phandle_with_args(v19, "mboxes", "#mbox-cells", 0xFFFFFFFFLL, i, &v35)
                      && v35 == v17 )
                    {
                      ++*((_DWORD *)v4 + 44);
                    }
                  }
                }
              }
              v19 = of_find_node_with_property(v19, "mboxes");
            }
            while ( v19 );
          }
          v23 = *((int *)v4 + 44);
          if ( (_DWORD)v23 )
          {
            if ( is_mul_ok(v23, 0xF8u) )
            {
              v24 = devm_kmalloc(v34, 248 * v23, 3520);
              v4[3] = v24;
              if ( v24 )
              {
                v4[5] = v34;
                v25 = *((_DWORD *)v4 + 44);
                v4[6] = &ipcc_mbox_chan_ops;
                v4[7] = v24;
                *((_DWORD *)v4 + 16) = v25;
                v4[10] = qcom_ipcc_mbox_xlate;
                *((_WORD *)v4 + 34) = 0;
                v26 = devm_mbox_controller_register(v34);
                if ( (_DWORD)v26 )
                  goto LABEL_36;
                goto LABEL_29;
              }
            }
            else
            {
              v4[3] = 0;
            }
            v26 = 4294967284LL;
            goto LABEL_36;
          }
LABEL_29:
          v27 = devm_request_threaded_irq(v1, *((unsigned int *)v4 + 45), qcom_ipcc_irq_fn, 0, 81924, v11, v4);
          if ( (v27 & 0x80000000) == 0 )
          {
            result = 0;
            *(_QWORD *)(a1 + 168) = v4;
            goto LABEL_24;
          }
          v29 = v27;
          v30 = v1;
          v31 = v29;
          dev_err(v30, "Failed to register the irq: %d\n", v29);
          if ( *((_DWORD *)v4 + 44) )
            mbox_controller_unregister(v4 + 5);
          v26 = v31;
LABEL_36:
          v32 = v4[2];
          v33 = v26;
          irq_domain_remove(v32);
          result = v33;
          goto LABEL_24;
        }
      }
      goto LABEL_23;
    }
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
