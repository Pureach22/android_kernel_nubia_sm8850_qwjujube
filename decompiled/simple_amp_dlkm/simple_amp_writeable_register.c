bool __fastcall simple_amp_writeable_register(__int64 a1)
{
  return (unsigned int)get_access_mode(*(_QWORD *)(a1 + 152)) - 1 < 2;
}
