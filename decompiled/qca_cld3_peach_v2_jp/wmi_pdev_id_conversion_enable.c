__int64 __fastcall wmi_pdev_id_conversion_enable(__int64 result, __int64 a2)
{
  __int64 (__fastcall *v2)(__int64, __int64); // x8

  if ( !*(_DWORD *)(result + 724) )
  {
    v2 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(result + 728) + 3952LL);
    if ( *((_DWORD *)v2 - 1) != 1693807655 )
      __break(0x8228u);
    return v2(result, a2);
  }
  return result;
}
