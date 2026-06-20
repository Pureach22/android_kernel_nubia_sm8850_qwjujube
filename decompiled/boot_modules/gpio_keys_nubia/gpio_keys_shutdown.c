__int64 __fastcall gpio_keys_shutdown(__int64 a1)
{
  __int64 result; // x0

  result = gpio_keys_suspend(a1 + 16);
  if ( (_DWORD)result )
    return dev_err(a1 + 16, "failed to shutdown\n");
  return result;
}
