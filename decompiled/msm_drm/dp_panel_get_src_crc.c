__int64 __fastcall dp_panel_get_src_crc(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 1216) + 712LL);
  if ( *((_DWORD *)v1 - 1) != 824414895 )
    __break(0x8228u);
  return v1();
}
