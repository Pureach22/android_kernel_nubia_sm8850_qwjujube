__int64 __fastcall dsi_pwr_get_dt_vreg_data(__int64 a1, __int64 a2, const char *a3)
{
  __int64 v6; // x22
  __int64 child_by_name; // x23
  __int64 next_child; // x0
  __int64 v9; // x1
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 result; // x0
  unsigned int v13; // w22
  _QWORD dest[18]; // [xsp+8h] [xbp-E8h] BYREF
  _QWORD v15[11]; // [xsp+98h] [xbp-58h] BYREF

  v15[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memcpy(dest, &dsi_parser_get_of_utils_of_utils, sizeof(dest));
  if ( !a1 || !a2 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Bad params\n");
LABEL_17:
    result = 4294967274LL;
    goto LABEL_18;
  }
  v6 = *(_QWORD *)(a1 + 744);
  *(_DWORD *)(a2 + 8) = 0;
  child_by_name = of_get_child_by_name(v6, a3);
  if ( !child_by_name )
  {
    memset(v15, 0, 80);
    if ( (unsigned int)_of_parse_phandle_with_args(v6, a3, 0, 0, 0, v15) || (child_by_name = v15[0]) == 0 )
    {
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: No supply entry present for %s\n", a3);
      goto LABEL_17;
    }
  }
  next_child = of_get_next_child(child_by_name, 0);
  if ( next_child )
  {
    v9 = next_child;
    do
    {
      ++*(_DWORD *)(a2 + 8);
      v9 = of_get_next_child(child_by_name, v9);
    }
    while ( v9 );
  }
  v10 = *(unsigned int *)(a2 + 8);
  if ( !(_DWORD)v10 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: No vregs defined for %s\n", a3);
    goto LABEL_17;
  }
  v11 = devm_kmalloc(a1, 80 * v10, 3520);
  *(_QWORD *)a2 = v11;
  if ( v11 )
  {
    dest[0] = v6;
    dest[1] = v6;
    result = dsi_pwr_parse_supply_node(dest, child_by_name, (_QWORD *)a2);
    if ( (_DWORD)result )
    {
      v13 = result;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: failed to parse supply node for %s, rc = %d\n",
        a3,
        result);
      devm_kfree(a1);
      result = v13;
      *(_QWORD *)a2 = 0;
      *(_DWORD *)(a2 + 8) = 0;
    }
  }
  else
  {
    *(_DWORD *)(a2 + 8) = 0;
    result = 4294967284LL;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
