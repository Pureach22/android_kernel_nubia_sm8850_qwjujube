__int64 __fastcall wncc_print_cvpwnccbufs_table(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x26
  __int64 v5; // x19
  unsigned int v6; // w27
  __int64 v7; // x28
  __int64 v8; // x19
  unsigned __int64 StatusReg; // x8

  if ( *(_DWORD *)(result + 12920) )
  {
    if ( *(_QWORD *)(result + 12928) )
    {
      if ( (msm_cvp_debug & 0xEFE8) != 0 && !msm_cvp_debug_out )
      {
        v8 = result;
        printk(&unk_83072, &unk_94624, "_wncc_print_cvpwnccbufs_table", a4);
        result = v8;
      }
      v4 = 0;
      v5 = 0;
      v6 = 0;
      do
      {
        if ( v6 >= *(_DWORD *)(result + 12920) )
          break;
        if ( *(_DWORD *)(*(_QWORD *)(result + 12928) + v4 + 4) )
        {
          if ( (msm_cvp_debug & 0xEFE8) != 0 && !msm_cvp_debug_out )
          {
            v7 = result;
            printk(&unk_827C7, &unk_94624, "_wncc_print_cvpwnccbufs_table", (unsigned int)v5);
            result = v7;
          }
          ++v6;
        }
        ++v5;
        v4 += 12;
      }
      while ( v5 != 2400 );
    }
    else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      return printk(&unk_8B4A1, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    }
  }
  else if ( (msm_cvp_debug & 0xEFE8) != 0 && !msm_cvp_debug_out )
  {
    return printk(&unk_90402, &unk_94624, "_wncc_print_cvpwnccbufs_table", a4);
  }
  return result;
}
