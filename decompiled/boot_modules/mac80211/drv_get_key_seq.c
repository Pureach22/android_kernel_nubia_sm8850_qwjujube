__int64 __fastcall drv_get_key_seq(__int64 result)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(result + 464) + 240LL);
  if ( v1 )
  {
    if ( *((_DWORD *)v1 - 1) != -111748570 )
      __break(0x8228u);
    return v1();
  }
  return result;
}
