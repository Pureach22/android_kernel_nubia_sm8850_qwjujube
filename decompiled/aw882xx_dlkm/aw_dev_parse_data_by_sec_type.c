__int64 __fastcall aw_dev_parse_data_by_sec_type(__int64 a1, __int64 a2, _DWORD *a3, __int64 a4)
{
  int v4; // w9
  __int64 result; // x0
  __int64 v7; // x22
  __int64 *v8; // x8
  int v10; // w19
  __int64 v12; // x1
  __int64 v13; // x23
  __int64 *v14; // x8
  __int64 v15; // x1

  v4 = a3[7];
  result = 0;
  if ( v4 <= 6 )
  {
    if ( v4 == 4 )
    {
      return aw_dev_parse_reg_bin_with_hdr(a1, a2 + (unsigned int)a3[9], (unsigned int)a3[8], a4);
    }
    else if ( !v4 )
    {
      v7 = a1;
      v8 = *(__int64 **)(a1 + 112);
      v10 = a3[8];
      v12 = v8[14];
      if ( !v12 )
        v12 = *v8;
      v13 = (unsigned int)a3[9];
      printk(&unk_2880A, v12, "aw_dev_parse_raw_reg");
      if ( (v10 & 3) != 0 )
      {
        v14 = *(__int64 **)(v7 + 112);
        v15 = v14[14];
        if ( !v15 )
          v15 = *v14;
        printk(&unk_26FE8, v15, "aw_dev_parse_raw_reg");
        return 4294967274LL;
      }
      else
      {
        *(_DWORD *)(a4 + 16) = v10;
        *(_QWORD *)(a4 + 24) = a2 + v13;
        *(_DWORD *)a4 = 1;
        return 0;
      }
    }
  }
  else if ( v4 == 7 )
  {
    return aw_dev_prof_parse_multi_bin(a1, a2 + (unsigned int)a3[9], (unsigned int)a3[8], a4);
  }
  else if ( v4 == 10 )
  {
    return aw882xx_monitor_parse_fw(a1 + 672, a2 + (unsigned int)a3[9], (unsigned int)a3[8]);
  }
  return result;
}
