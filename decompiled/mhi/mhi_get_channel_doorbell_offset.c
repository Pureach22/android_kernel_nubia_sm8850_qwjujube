__int64 __fastcall mhi_get_channel_doorbell_offset(__int64 a1)
{
  __int64 (*v1)(void); // x9
  __int64 v2; // x19
  __int64 result; // x0

  v1 = *(__int64 (**)(void))(a1 + 568);
  v2 = *(_QWORD *)(a1 + 16);
  if ( *((_DWORD *)v1 - 1) != -748163823 )
    __break(0x8229u);
  result = v1();
  if ( (_DWORD)result )
  {
    dev_err(v2 + 40, "Unable to read CHDBOFF register\n");
    return 4294967291LL;
  }
  return result;
}
