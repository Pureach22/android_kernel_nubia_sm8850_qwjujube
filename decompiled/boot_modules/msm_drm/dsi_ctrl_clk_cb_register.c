__int64 __fastcall dsi_ctrl_clk_cb_register(_QWORD *a1, _QWORD *a2)
{
  const char *v3; // x3

  if ( a1 && a2 )
  {
    a1[204] = *a2;
    a1[205] = a2[1];
    return 0;
  }
  else
  {
    if ( a1 )
      v3 = (const char *)a1[2];
    else
      v3 = "inv";
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid params\n", v3);
    return 4294967274LL;
  }
}
