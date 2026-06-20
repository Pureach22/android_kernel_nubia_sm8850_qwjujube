__int64 __fastcall clk_hw_populate_clock_opp_table(__int64 result, __int64 a2)
{
  __int64 *v2; // x25
  __int64 v4; // x23
  const char *name; // x0
  size_t v6; // x20
  const char *v7; // x3
  int v8; // w21
  const char *v9; // x0
  int v10; // w26
  unsigned __int64 v11; // x20
  __int64 v12; // x21
  unsigned int v13; // w24
  unsigned __int64 v14; // x26
  unsigned __int64 v15; // x22
  __int64 device_by_node; // x0
  bool v17; // cf
  int v18; // w26
  __int64 v19; // x23
  __int64 v20; // x0
  __int64 v21; // x22
  int v22; // w8
  unsigned int *v23; // x8
  unsigned int vdd_level; // w0
  __int64 v25; // x27
  __int64 *v26; // x24
  unsigned __int64 v27; // x22
  unsigned __int64 v28; // x25
  __int64 v29; // x0
  int v30; // w28
  void *v31; // x0
  int v32; // [xsp+0h] [xbp-E0h]
  int v33; // [xsp+14h] [xbp-CCh] BYREF
  _QWORD v34[12]; // [xsp+18h] [xbp-C8h] BYREF
  int v35; // [xsp+78h] [xbp-68h]
  __int64 v36; // [xsp+80h] [xbp-60h] BYREF
  __int64 v37; // [xsp+88h] [xbp-58h]
  __int64 v38; // [xsp+90h] [xbp-50h]
  __int64 v39; // [xsp+98h] [xbp-48h]
  __int64 v40; // [xsp+A0h] [xbp-40h]
  __int64 v41; // [xsp+A8h] [xbp-38h]
  __int64 v42; // [xsp+B0h] [xbp-30h]
  __int64 v43; // [xsp+B8h] [xbp-28h]
  __int64 v44; // [xsp+C0h] [xbp-20h]
  __int64 v45; // [xsp+C8h] [xbp-18h]
  __int64 v46; // [xsp+D0h] [xbp-10h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = (__int64 *)(a2 + 48);
  if ( *(_QWORD *)(a2 + 48) && *(_DWORD *)(a2 + 72) )
  {
    v4 = result;
    v35 = 0;
    memset(v34, 0, sizeof(v34));
    v33 = 0;
    name = (const char *)clk_hw_get_name(a2);
    v6 = strlen(name) + 16;
    v7 = (const char *)clk_hw_get_name(a2);
    if ( v6 > 0x63 )
    {
      result = printk(&unk_28444);
    }
    else
    {
      v8 = scnprintf(v34, 100, "qcom,%s-opp-handle", v7);
      v9 = (const char *)clk_hw_get_name(a2);
      if ( strlen(v9) + 16 > v8 )
      {
        clk_hw_get_name(a2);
        result = printk(&unk_28D4F);
      }
      else
      {
        result = of_find_property(v4, v34, &v33);
        if ( result )
        {
          v10 = v33 >> 2;
          if ( ((v33 >> 2) & 0x80000000) == 0 )
          {
            v11 = 8LL * (unsigned int)(v33 >> 2);
            result = _kmalloc_noprof(v11, 3264);
            v12 = result;
            if ( result )
            {
              v32 = v10;
              if ( v10 < 1 )
              {
LABEL_20:
                if ( *(int *)(a2 + 72) < 1 )
                  goto LABEL_49;
                v18 = 0;
                v19 = 0;
                while ( 1 )
                {
                  v20 = clk_hw_round_rate(a2, v19 + 1);
                  if ( !v20 )
                  {
                    clk_hw_get_name(a2);
                    v31 = &unk_292CB;
                    goto LABEL_48;
                  }
                  if ( v19 == v20 )
                    goto LABEL_49;
                  v21 = *v2;
                  v19 = v20;
                  v22 = *(_DWORD *)(*v2 + 24);
                  if ( v22 < 2 )
                  {
                    vdd_level = clk_find_vdd_level(a2, v2, v20);
                    if ( (vdd_level & 0x80000000) != 0 )
                    {
                      printk(&unk_287EE);
                      goto LABEL_49;
                    }
                    v23 = (unsigned int *)(*(_QWORD *)(v21 + 32) + 4LL * vdd_level);
                  }
                  else
                  {
                    v23 = (unsigned int *)(*(_QWORD *)(v21 + 32) + 4LL * v22 * v18);
                  }
                  v25 = *v23;
                  if ( !(_DWORD)v25 )
                  {
                    clk_hw_get_name(a2);
                    printk(&unk_290DD);
                    goto LABEL_49;
                  }
                  if ( (v25 & 0x80000000) == 0 )
                  {
                    v26 = v2;
                    if ( v32 >= 1 )
                    {
                      v27 = 0;
                      v28 = v11;
                      while ( 1 )
                      {
                        if ( (v27 & 0x8000000000000000LL) != 0 || v11 < v27 || v28 < 8 )
                          goto LABEL_54;
                        v29 = *(_QWORD *)(v12 + v27);
                        v36 = 0;
                        v37 = v19;
                        v38 = v25;
                        v30 = dev_pm_opp_add_dynamic(v29, &v36);
                        clk_hw_get_name(a2);
                        if ( v30 )
                          break;
                        if ( v11 < v27 )
                          goto LABEL_54;
                        v17 = v28 >= 8;
                        v28 -= 8LL;
                        if ( !v17 )
                          goto LABEL_54;
                        printk(&unk_2880A);
                        v27 += 8LL;
                        if ( 8LL * (unsigned int)v32 == v27 )
                          goto LABEL_23;
                      }
                      printk(&unk_28BCC);
                      printk(&unk_292EE);
                    }
LABEL_23:
                    ++v18;
                    v2 = v26;
                    if ( v18 < *(_DWORD *)(a2 + 72) )
                      continue;
                  }
                  goto LABEL_49;
                }
              }
              v13 = 0;
              v14 = 0;
              v15 = v11;
              while ( 1 )
              {
                if ( (v14 & 0x8000000000000000LL) != 0 || v11 < v14 || v15 < 8 )
LABEL_54:
                  __break(1u);
                *(_QWORD *)(v12 + v14) = 0;
                v44 = 0;
                v45 = 0;
                v42 = 0;
                v43 = 0;
                v40 = 0;
                v41 = 0;
                v39 = 0;
                v37 = 0;
                v38 = 0;
                v36 = 0;
                if ( (unsigned int)_of_parse_phandle_with_args(v4, v34, 0, 0, v13, &v36) || !v36 )
                {
                  clk_hw_get_name(a2);
                  printk(&unk_296FC);
                  goto LABEL_47;
                }
                device_by_node = of_find_device_by_node();
                if ( !device_by_node )
                  break;
                if ( v11 < v14 )
                  goto LABEL_54;
                v17 = v15 >= 8;
                v15 -= 8LL;
                if ( !v17 )
                  goto LABEL_54;
                *(_QWORD *)(v12 + v14) = device_by_node + 16;
                v14 += 8LL;
                ++v13;
                if ( 8LL * (unsigned int)v32 == v14 )
                  goto LABEL_20;
              }
              clk_hw_get_name(a2);
              printk(&unk_28904);
LABEL_47:
              v31 = &unk_285B8;
LABEL_48:
              printk(v31);
LABEL_49:
              result = kfree(v12);
            }
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
