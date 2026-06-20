__int64 __fastcall VI530X_Stop_Continuous_Measure(__int64 a1)
{
  __int64 result; // x0

  result = vi530x_write_byte(a1, 10, 31);
  if ( (_DWORD)result )
  {
    printk(&unk_42313F);
    return 4294967287LL;
  }
  return result;
}
