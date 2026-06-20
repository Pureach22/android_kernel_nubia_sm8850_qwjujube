__int64 get_hfi_version()
{
  return *(unsigned int *)(**(_QWORD **)(*(_QWORD *)(cvp_driver + 48) + 256LL) + 16LL);
}
