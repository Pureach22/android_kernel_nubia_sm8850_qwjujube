__int64 __fastcall dsi_pwr_of_get_vreg_data(__int64 *a1, __int64 a2, const char *a3)
{
  __int64 (__fastcall *v5)(__int64, const char *); // x8
  __int64 v6; // x0
  __int64 v8; // x22
  __int64 v9; // x0
  __int64 (__fastcall *v10)(_QWORD); // x8
  int v11; // w0
  __int64 v12; // x0
  __int64 result; // x0
  unsigned int v14; // w21
  _QWORD v15[11]; // [xsp+8h] [xbp-58h] BYREF

  v15[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    *(_DWORD *)(a2 + 8) = 0;
    v5 = (__int64 (__fastcall *)(__int64, const char *))a1[10];
    v6 = *a1;
    if ( *((_DWORD *)v5 - 1) != 387453051 )
      __break(0x8228u);
    v8 = v5(v6, a3);
    if ( v8
      || (v9 = a1[1], memset(v15, 0, 80), !(unsigned int)_of_parse_phandle_with_args(v9, a3, 0, 0, 0, v15))
      && (v8 = v15[0]) != 0 )
    {
      v10 = (__int64 (__fastcall *)(_QWORD))a1[17];
      if ( *((_DWORD *)v10 - 1) != -1880641320 )
        __break(0x8228u);
      v11 = v10(v8);
      *(_DWORD *)(a2 + 8) = v11;
      if ( v11 )
      {
        v12 = _kmalloc_noprof(80LL * *(unsigned int *)(a2 + 8), 3520);
        *(_QWORD *)a2 = v12;
        if ( v12 )
        {
          result = dsi_pwr_parse_supply_node(a1, v8, a2);
          if ( (_DWORD)result )
          {
            v14 = result;
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: failed to parse supply node for %s, rc = %d\n",
              a3,
              result);
            kfree(*(_QWORD *)a2);
            result = v14;
            *(_QWORD *)a2 = 0;
            *(_DWORD *)(a2 + 8) = 0;
          }
        }
        else
        {
          *(_DWORD *)(a2 + 8) = 0;
          result = 4294967284LL;
        }
      }
      else
      {
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: No vregs defined for %s\n", a3);
        result = 4294967274LL;
      }
    }
    else
    {
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: No supply entry present for %s\n", a3);
      result = 4294967274LL;
    }
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Bad params\n");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
