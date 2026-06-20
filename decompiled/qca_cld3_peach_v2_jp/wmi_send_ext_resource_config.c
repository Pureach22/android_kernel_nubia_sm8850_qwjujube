__int64 __fastcall wmi_send_ext_resource_config(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 2424LL);
  if ( !v1 )
    return 16;
  if ( *((_DWORD *)v1 - 1) != -27434418 )
    __break(0x8228u);
  return v1();
}
