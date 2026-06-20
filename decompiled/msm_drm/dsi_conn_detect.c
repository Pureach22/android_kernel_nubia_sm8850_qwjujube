__int64 __fastcall dsi_conn_detect(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w8
  int v5; // w0

  _ReadStatusReg(SP_EL0);
  v3 = 3;
  if ( a1 && a3 )
  {
    v5 = ((__int64 (*)(void))dsi_display_get_info)();
    if ( v5 )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to get display info, rc=%d\n", v5);
      v3 = 2;
    }
    else
    {
      v3 = 1;
      *(_DWORD *)(a1 + 216) = 0;
      *(_DWORD *)(a1 + 220) = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
