bool __fastcall simple_amp_readable_register(__int64 a1)
{
  return (get_access_mode(*(_QWORD *)(a1 + 152)) & 0xFFFFFFFD) == 0;
}
