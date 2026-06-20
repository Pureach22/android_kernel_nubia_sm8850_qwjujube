__int64 __fastcall wmi_convert_pdev_id_host_to_target(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 (*v3)(void); // x8

  v3 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 3680LL);
  if ( !v3 )
    return 16;
  if ( *((_DWORD *)v3 - 1) != -2112860426 )
    __break(0x8228u);
  *a3 = v3();
  return 0;
}
