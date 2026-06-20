__int64 __fastcall wmi_extract_pdev_csa_switch_count_status(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 2856LL);
  if ( !v1 )
    return 16;
  if ( *((_DWORD *)v1 - 1) != 1881074951 )
    __break(0x8228u);
  return v1();
}
