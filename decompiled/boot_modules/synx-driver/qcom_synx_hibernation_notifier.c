__int64 __fastcall qcom_synx_hibernation_notifier(__int64 a1, __int64 a2)
{
  unsigned int v2; // w0
  __int64 v3; // x4
  __int64 v4; // x5
  __int64 v5; // x4
  void *v6; // x0
  const char *v7; // x2
  __int64 v8; // x3
  unsigned int v9; // w0
  unsigned int v10; // w0
  __int64 result; // x0
  unsigned int v12; // w0
  void *v13; // x0
  const char *v14; // x2
  __int64 v15; // x3

  if ( a2 == 2 )
  {
    v9 = synx_global_mem_init();
    if ( v9 )
    {
      if ( (synx_debug & 1) != 0 )
      {
        v5 = v9;
        v6 = &unk_281B8;
        v7 = "synx_hibernate_exit";
        v8 = 4173;
        goto LABEL_31;
      }
      return 32770;
    }
    if ( (synx_debug & 8) == 0 )
      return 1;
    v13 = &unk_27AA2;
    v14 = "synx_hibernate_exit";
    v15 = 4177;
    goto LABEL_27;
  }
  if ( a2 == 1 )
  {
    v2 = synx_prepare_pm_ops();
    if ( v2 )
    {
      if ( (synx_debug & 1) != 0 )
      {
        v5 = v2;
        v6 = &unk_29FFB;
        v7 = "synx_hibernate_entry";
        v8 = 4133;
LABEL_31:
        printk(v6, &unk_29207, v7, v8, v5, v4);
        return 32770;
      }
      return 32770;
    }
    if ( (synx_debug & 8) == 0 )
      return 1;
    v13 = &unk_266B7;
    v14 = "synx_hibernate_entry";
    v15 = 4137;
    goto LABEL_27;
  }
  if ( a2 == 3 && pm_suspend_target_state == 3 )
  {
    v10 = synx_prepare_pm_ops();
    if ( v10 )
    {
      if ( (synx_debug & 1) != 0 )
      {
        v5 = v10;
        v6 = &unk_266ED;
        v7 = "synx_deep_sleep_entry";
        v8 = 4153;
        goto LABEL_31;
      }
      return 32770;
    }
    if ( (synx_debug & 8) == 0 )
      return 1;
    v13 = &unk_258E1;
    v14 = "synx_deep_sleep_entry";
    v15 = 4157;
    goto LABEL_27;
  }
  result = 1;
  if ( a2 == 4 && pm_suspend_target_state == 3 )
  {
    v12 = synx_gmem_init(1);
    if ( v12 )
    {
      if ( (synx_debug & 1) != 0 )
      {
        v5 = v12;
        v6 = &unk_2A6A5;
        v7 = "synx_deep_sleep_exit";
        v8 = 4193;
        goto LABEL_31;
      }
      return 32770;
    }
    if ( (synx_debug & 8) == 0 )
      return 1;
    v13 = &unk_26AA0;
    v14 = "synx_deep_sleep_exit";
    v15 = 4197;
LABEL_27:
    printk(v13, &unk_2A972, v14, v15, v3, v4);
    return 1;
  }
  return result;
}
