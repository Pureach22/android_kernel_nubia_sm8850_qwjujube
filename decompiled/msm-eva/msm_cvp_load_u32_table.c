__int64 __fastcall msm_cvp_load_u32_table(__int64 a1, __int64 a2, __int64 a3, int a4, __int64 *a5, _DWORD *a6)
{
  __int64 result; // x0
  __int64 v13; // x3
  unsigned __int64 v14; // x25
  int v15; // w8
  unsigned __int64 v16; // x24
  __int64 v17; // x0
  __int64 v18; // x23
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x8
  unsigned __int64 StatusReg; // x8

  result = of_find_property(a2, a3, 0);
  if ( result )
  {
    result = get_u32_array_num_elements(a2, a3);
    if ( (_DWORD)result )
    {
      v14 = (int)result / ((unsigned __int64)a4 >> 2);
      v15 = v14 * a4;
      v16 = (int)v14 * a4;
      v17 = devm_kmalloc(a1 + 16, v15, 3520);
      if ( v17 )
      {
        v18 = v17;
        if ( (of_property_read_variable_u32_array(a2, a3, v17, v16 >> 2, 0) & 0x80000000) != 0 )
        {
          result = 4294967274LL;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            StatusReg = _ReadStatusReg(SP_EL0);
            printk(&unk_95EC3, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
            return 4294967274LL;
          }
        }
        else
        {
          result = 0;
          *a5 = v18;
          if ( a6 )
            *a6 = v14;
        }
      }
      else
      {
        result = 4294967284LL;
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v20 = _ReadStatusReg(SP_EL0);
          printk(&unk_969B0, *(unsigned int *)(v20 + 1800), *(unsigned int *)(v20 + 1804), &unk_8E7CE);
          return 4294967284LL;
        }
      }
    }
    else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v19 = _ReadStatusReg(SP_EL0);
      printk(&unk_85366, *(unsigned int *)(v19 + 1800), *(unsigned int *)(v19 + 1804), &unk_8E7CE);
      return 0;
    }
  }
  else if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
  {
    printk(&unk_8CC52, "core", a3, v13);
    return 0;
  }
  return result;
}
