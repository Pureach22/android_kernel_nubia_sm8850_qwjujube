__int64 __fastcall qcom_clk_crm_init(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  const char *v4; // x3
  unsigned __int64 v6; // x0
  unsigned __int64 device; // x0
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v9; // [xsp+10h] [xbp-20h]
  __int64 v10; // [xsp+18h] [xbp-18h]
  __int64 v11; // [xsp+20h] [xbp-10h]
  __int64 v12; // [xsp+28h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    if ( (*(_BYTE *)(a2 + 44) & 1) != 0 )
    {
      result = 0;
    }
    else
    {
      v4 = *(const char **)a2;
      v10 = 0;
      v11 = 0;
      *(_QWORD *)s = 0;
      v9 = 0;
      snprintf(s, 0x20u, "qcom,%s-crmc", v4);
      if ( of_find_property(*(_QWORD *)(a1 + 744), s, 0)
        && (v6 = syscon_regmap_lookup_by_phandle(*(_QWORD *)(a1 + 744), s),
            *(_QWORD *)(a2 + 8) = v6,
            v6 >= 0xFFFFFFFFFFFFF001LL) )
      {
        dev_err(a1, "%s regmap error\n", s);
        result = *(unsigned int *)(a2 + 8);
      }
      else if ( *(_QWORD *)a2
             && (device = crm_get_device(), *(_QWORD *)(a2 + 16) = device, device >= 0xFFFFFFFFFFFFF001LL) )
      {
        printk(&unk_2820D);
        result = *(unsigned int *)(a2 + 16);
      }
      else
      {
        if ( !*(_BYTE *)(a2 + 45) )
          *(_BYTE *)(a2 + 45) = 8;
        result = 0;
        *(_BYTE *)(a2 + 44) = 1;
      }
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
