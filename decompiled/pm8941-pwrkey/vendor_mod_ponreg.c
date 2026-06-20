__int64 __fastcall vendor_mod_ponreg(_QWORD *a1)
{
  __int64 result; // x0
  int v3; // w2

  result = dev_info(*a1, "%s: modify pwrkey s2 warm reset\n", "vendor_mod_ponreg");
  v3 = *((_DWORD *)a1 + 4);
  if ( v3 )
  {
    dev_err(*a1, "use pon pbs address=0x%04X\n", v3);
    result = regmap_write(a1[3], (unsigned int)(*((_DWORD *)a1 + 4) + 66), 1);
    if ( (_DWORD)result )
      return dev_err(*a1, "pwrkey s2 register write failed, rc=%d\n", result);
  }
  return result;
}
