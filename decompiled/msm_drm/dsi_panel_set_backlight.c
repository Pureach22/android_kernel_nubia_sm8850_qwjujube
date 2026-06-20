__int64 __fastcall dsi_panel_set_backlight(__int64 *a1, unsigned int a2)
{
  __int64 result; // x0
  long double v5; // q0
  int v6; // w3
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x9
  unsigned int v11; // w0
  __int64 v12; // x0
  __int64 v13; // x3
  const char *v14; // x2
  unsigned int v15; // w19
  __int64 v16; // x0

  _ReadStatusReg(SP_EL0);
  if ( (*((_BYTE *)a1 + 1274) & 1) != 0 )
    goto LABEL_2;
  *(double *)&v5 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: backlight type:%d lvl:%d\n", *((_DWORD *)a1 + 368), a2);
  v6 = *((_DWORD *)a1 + 368);
  if ( v6 > 2 )
  {
    result = 0;
    if ( (unsigned int)(v6 - 3) < 2 )
      goto LABEL_31;
    goto LABEL_9;
  }
  if ( v6 )
  {
    if ( v6 == 1 )
    {
      result = backlight_device_set_brightness(a1[196], a2);
      goto LABEL_31;
    }
    if ( v6 == 2 )
    {
      result = zte_dsi_panel_update_backlight(a1, a2, *(double *)&v5);
      goto LABEL_31;
    }
LABEL_9:
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Backlight type(%d) not supported\n", v6);
    result = 4294966772LL;
    goto LABEL_31;
  }
  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid Params\n", *(double *)&v5);
LABEL_27:
    result = 4294967274LL;
    goto LABEL_31;
  }
  v7 = a1[193];
  if ( !v7 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: pwm device not found\n", *(double *)&v5);
    goto LABEL_27;
  }
  v8 = (unsigned int)(1000 * *((_DWORD *)a1 + 389));
  v9 = (unsigned int)v8 * a2 / *((_DWORD *)a1 + 371);
  if ( (((unsigned int)v9 | (unsigned int)v8) & 0x80000000) != 0 )
  {
    v11 = -22;
LABEL_29:
    v13 = *a1;
    v14 = "*ERROR* [msm-dsi-error]: [%s] failed to change pwm config, rc=%d\n";
    goto LABEL_30;
  }
  if ( *(_QWORD *)(v7 + 56) != v9 || *(_QWORD *)(v7 + 48) != v8 )
  {
    v11 = pwm_apply_might_sleep(v5);
    if ( v11 )
      goto LABEL_29;
  }
  if ( a2 )
  {
    if ( (a1[194] & 1) == 0 )
    {
      v12 = a1[193];
      if ( v12 )
      {
        if ( (unsigned __int8)BYTE4(*(_QWORD *)(v12 + 64)) == 1 || (v11 = pwm_apply_might_sleep(v5)) == 0 )
        {
          result = 0;
          *((_BYTE *)a1 + 1552) = 1;
          goto LABEL_31;
        }
      }
      else
      {
        v11 = -22;
      }
      v13 = *a1;
      v14 = "*ERROR* [msm-dsi-error]: [%s] failed to enable pwm, rc=%d\n";
LABEL_30:
      v15 = v11;
      drm_dev_printk(0, &unk_248D72, v14, v13, v11);
      result = v15;
      goto LABEL_31;
    }
LABEL_2:
    result = 0;
    goto LABEL_31;
  }
  if ( !*((_BYTE *)a1 + 1552) )
    goto LABEL_2;
  v16 = a1[193];
  if ( v16 && (unsigned __int8)BYTE4(*(_QWORD *)(v16 + 64)) == 1 )
    pwm_apply_might_sleep(v5);
  result = 0;
  *((_BYTE *)a1 + 1552) = 0;
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
