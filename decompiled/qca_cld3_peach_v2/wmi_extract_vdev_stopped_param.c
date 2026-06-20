__int64 __fastcall wmi_extract_vdev_stopped_param(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 2752LL);
  if ( !v1 )
    return 16;
  if ( *((_DWORD *)v1 - 1) != 1109935215 )
    __break(0x8228u);
  return v1();
}
