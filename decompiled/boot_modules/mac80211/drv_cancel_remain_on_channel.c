__int64 __fastcall drv_cancel_remain_on_channel(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 464) + 480LL);
  if ( *((_DWORD *)v1 - 1) != 844051912 )
    __break(0x8228u);
  return v1();
}
