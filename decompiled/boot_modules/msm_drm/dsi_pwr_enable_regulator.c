__int64 __fastcall dsi_pwr_enable_regulator(_DWORD *a1, char a2)
{
  int v2; // w9
  unsigned int v3; // w8
  __int64 result; // x0
  _DWORD *v5; // x19
  unsigned int v6; // w0
  unsigned int v7; // w20
  unsigned int v8; // w19

  if ( a1[2] )
  {
    if ( *(_QWORD *)a1 )
    {
      v2 = a1[3];
      if ( (a2 & 1) != 0 )
      {
        if ( v2 )
        {
          v3 = 0;
        }
        else
        {
          v5 = a1;
          v6 = dsi_pwr_enable_vregs();
          if ( v6 )
          {
            v7 = v6;
            drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to enable regulators\n");
            v3 = v7;
          }
          else
          {
            v3 = 0;
          }
          a1 = v5;
        }
        ++a1[3];
        return v3;
      }
      else if ( v2 )
      {
        a1[3] = v2 - 1;
        if ( v2 == 1 )
        {
          result = dsi_pwr_enable_vregs();
          if ( (_DWORD)result )
          {
            v8 = result;
            drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to disable vregs\n");
            return v8;
          }
        }
        else
        {
          return 0;
        }
      }
      else
      {
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: Unbalanced regulator off:%s\n",
          (const char *)(*(_QWORD *)a1 + 8LL));
        return 0;
      }
    }
    else
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
      return 4294967274LL;
    }
  }
  else
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: No valid regulators to enable\n");
    return 0;
  }
  return result;
}
