__int64 __fastcall dp_set_rtpm_tput_policy_requirement(__int64 result, char a2)
{
  *(_DWORD *)(result + 20068) = a2 & 1;
  return result;
}
