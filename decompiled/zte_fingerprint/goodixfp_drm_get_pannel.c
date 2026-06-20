__int64 __fastcall goodixfp_drm_get_pannel(__int64 a1)
{
  int v1; // w19
  void *v3; // x0
  unsigned int v4; // w21
  __int64 v5; // x0
  unsigned __int64 panel; // x0
  __int64 v7; // x20
  _QWORD v9[11]; // [xsp+8h] [xbp-58h] BYREF

  v9[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v1 = of_count_phandle_with_args(a1, "panel", 0);
    if ( v1 >= 1 )
    {
      v4 = 0;
      while ( 1 )
      {
        memset(v9, 0, 80);
        v5 = (unsigned int)_of_parse_phandle_with_args(a1, "panel", 0, 0, v4, v9) ? 0LL : v9[0];
        panel = of_drm_find_panel(v5);
        if ( panel <= 0xFFFFFFFFFFFFF000LL )
          break;
        if ( v1 == ++v4 )
        {
          v3 = &unk_918A;
          goto LABEL_12;
        }
      }
      v7 = panel;
      printk(&unk_8E7B);
      goodixfp_active_panel = v7;
      printk(&unk_8ED6);
      v1 = 0;
    }
    else
    {
      v3 = &unk_95E1;
LABEL_12:
      printk(v3);
    }
  }
  else
  {
    printk(&unk_9815);
    v1 = -19;
  }
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v1;
}
