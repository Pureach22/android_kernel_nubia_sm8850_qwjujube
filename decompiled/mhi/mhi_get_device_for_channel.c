__int64 __fastcall mhi_get_device_for_channel(__int64 a1, unsigned int a2)
{
  if ( *(_DWORD *)(a1 + 208) <= a2 )
    return 0;
  else
    return *(_QWORD *)(*(_QWORD *)(a1 + 176) + 400LL * a2 + 272);
}
