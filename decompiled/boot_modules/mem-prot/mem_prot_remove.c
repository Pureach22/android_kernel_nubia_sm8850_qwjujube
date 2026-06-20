__int64 __fastcall mem_prot_remove(__int64 a1)
{
  return of_reserved_mem_device_release(a1 + 16);
}
