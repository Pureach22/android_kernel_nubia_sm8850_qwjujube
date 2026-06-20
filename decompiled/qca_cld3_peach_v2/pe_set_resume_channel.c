__int64 __fastcall pe_set_resume_channel(__int64 result, __int16 a2, int a3)
{
  *(_WORD *)(result + 4028) = a2;
  *(_DWORD *)(result + 4032) = a3;
  return result;
}
