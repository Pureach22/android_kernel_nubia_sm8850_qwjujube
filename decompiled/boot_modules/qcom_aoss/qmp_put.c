unsigned __int64 __fastcall qmp_put(unsigned __int64 result)
{
  if ( result )
  {
    if ( result <= 0xFFFFFFFFFFFFF000LL )
      return put_device(*(_QWORD *)(result + 8));
  }
  return result;
}
