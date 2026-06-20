__int64 __fastcall eusb2_repeater_reg_read(__int64 *a1, __int64 a2, unsigned __int16 a3, __int64 a4)
{
  int v5; // w20
  __int64 result; // x0
  __int64 v7; // x8
  int v8; // w9
  unsigned int v9; // w19

  v5 = a3;
  result = regmap_bulk_read(a1[11], *((unsigned __int16 *)a1 + 48) + (unsigned int)a3, a2, a4);
  if ( (_DWORD)result )
  {
    v7 = *a1;
    v8 = *((unsigned __int16 *)a1 + 48);
    v9 = result;
    dev_err(v7, "read failed: addr=0x%04x, ret=%d\n", v8 + v5, result);
    return v9;
  }
  return result;
}
