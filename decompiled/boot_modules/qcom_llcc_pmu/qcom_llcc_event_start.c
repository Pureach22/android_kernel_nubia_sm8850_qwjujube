__int64 __fastcall qcom_llcc_event_start(__int64 result, char a2)
{
  if ( (a2 & 2) != 0 && (*(_BYTE *)(result + 480) & 2) == 0 )
  {
    __break(0x800u);
    *(_DWORD *)(result + 480) = 0;
  }
  else
  {
    *(_DWORD *)(result + 480) = 0;
  }
  return result;
}
