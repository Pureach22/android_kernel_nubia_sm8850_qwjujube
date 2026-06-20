__int64 __fastcall dp_enable_verbose_debug(__int64 result)
{
  int v1; // w8

  v1 = *(_DWORD *)(*(_QWORD *)(result + 40) + 620LL);
  if ( (v1 & 4) != 0 )
    is_dp_verbose_debug_enabled = 1;
  is_hal_verbose_debug_enabled = (v1 & 2) != 0;
  return result;
}
