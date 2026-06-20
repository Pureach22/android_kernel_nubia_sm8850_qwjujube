__int64 __fastcall gpio_keys_close(__int64 result)
{
  __int64 (__fastcall *v1)(_QWORD); // x8
  __int64 v2; // x0

  v1 = *(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)(result + 712) + 32LL);
  if ( v1 )
  {
    v2 = *(_QWORD *)(result + 656);
    if ( *((_DWORD *)v1 - 1) != 1820440776 )
      __break(0x8228u);
    return v1(v2);
  }
  return result;
}
