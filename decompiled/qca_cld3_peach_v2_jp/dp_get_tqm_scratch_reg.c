__int64 __fastcall dp_get_tqm_scratch_reg(__int64 a1)
{
  __int64 result; // x0
  __int64 (*v2)(void); // x8

  result = *(_QWORD *)(a1 + 1128);
  v2 = *(__int64 (**)(void))(*(_QWORD *)(result + 74392) + 1840LL);
  if ( v2 )
  {
    if ( *((_DWORD *)v2 - 1) != 1129568724 )
      __break(0x8228u);
    return v2();
  }
  return result;
}
