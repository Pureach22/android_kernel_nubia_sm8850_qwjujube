__int64 __fastcall mhi_misc_cmd_completion(__int64 result, int a2, int a3)
{
  __int64 v3; // x8

  if ( a2 == 73 )
  {
    v3 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(result + 16) + 192LL) + 96LL);
    if ( v3 )
    {
      *(_DWORD *)(v3 + 32) = a3;
      return complete(v3 + 40);
    }
  }
  return result;
}
