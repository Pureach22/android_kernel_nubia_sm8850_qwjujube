__int64 __fastcall syna_tcm_detect_device(__int64 a1, char a2, __int64 a3)
{
  __int64 v5; // x2
  __int64 v7; // x2
  void *v8; // x0
  __int64 v9; // x2

  if ( !a1 )
  {
    v8 = &unk_3365A;
    goto LABEL_16;
  }
  *(_WORD *)(a1 + 8) = 0;
  if ( (a2 & 0xF) != 1 )
  {
    if ( (a2 & 0xF) == 2 )
    {
      printk(&unk_32B1F, "syna_tcm_detect_device", 2);
      return 4294967055LL;
    }
    v8 = &unk_349DB;
LABEL_16:
    printk(v8, "syna_tcm_detect_device", a3);
    return 4294967055LL;
  }
  if ( (syna_tcm_v1_detect(a1, a2 < 0, a3 & 1) & 0x80000000) != 0 )
  {
    if ( *(_DWORD *)(a1 + 584) )
      printk(&unk_33152, "syna_tcm_detect_device", **(unsigned __int8 **)(a1 + 576));
    return 4294967051LL;
  }
  else if ( *(_QWORD *)(a1 + 920) && *(_QWORD *)(a1 + 912) )
  {
    if ( a2 < 0 )
    {
      return 1;
    }
    else
    {
      v9 = *(unsigned __int8 *)(a1 + 9);
      if ( (_DWORD)v9 == 11 )
      {
        printk(&unk_3C6EF, "syna_tcm_detect_device", v9);
      }
      else if ( (_DWORD)v9 == 1 )
      {
        printk(&unk_3213C, "syna_tcm_detect_device", *(unsigned int *)(a1 + 12));
      }
      else
      {
        printk(&unk_3962C, "syna_tcm_detect_device", v9);
      }
      return *(unsigned __int8 *)(a1 + 9);
    }
  }
  else
  {
    printk(&unk_3B9DE, "syna_tcm_detect_device", v5);
    printk(&unk_36C5F, "syna_tcm_detect_device", v7);
    return 4294967051LL;
  }
}
