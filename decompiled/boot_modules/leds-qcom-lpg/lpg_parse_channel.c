__int64 __fastcall lpg_parse_channel(_QWORD *a1, __int64 a2, __int64 *a3)
{
  __int64 result; // x0
  __int64 v7; // x22
  unsigned int v8; // w0
  unsigned int v9; // [xsp+0h] [xbp-10h] BYREF
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  v10 = 2;
  if ( (of_property_read_variable_u32_array(a2, &unk_9C88, &v9, 1, 0) & 0x80000000) == 0
    && v9
    && v9 <= *((_DWORD *)a1 + 38) )
  {
    v7 = a1[18] + 104LL * (v9 - 1);
    *(_BYTE *)(v7 + 28) = 1;
    v8 = of_property_read_variable_u32_array(a2, "color", &v10, 1, 0);
    if ( (v8 & 0x80000000) == 0 || v8 == -22 )
    {
      result = 0;
      *(_DWORD *)(v7 + 32) = v10;
      *a3 = v7;
    }
    else
    {
      result = dev_err_probe(*a1, v8, "failed to parse \"color\" of %pOF\n", a2);
    }
  }
  else
  {
    result = dev_err_probe(*a1, 4294967274LL, "invalid \"reg\" of %pOFn\n", a2);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
