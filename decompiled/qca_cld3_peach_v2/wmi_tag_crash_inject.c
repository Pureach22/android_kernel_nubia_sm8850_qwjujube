__int64 __fastcall wmi_tag_crash_inject(__int64 result, char a2)
{
  *(_BYTE *)(result + 720) = a2;
  return result;
}
