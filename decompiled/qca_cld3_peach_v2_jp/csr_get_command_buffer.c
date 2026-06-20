__int64 __fastcall csr_get_command_buffer(__int64 a1)
{
  __int64 result; // x0

  result = sme_get_command_buffer(a1);
  if ( result )
    ++*(_DWORD *)(a1 + 17220);
  return result;
}
