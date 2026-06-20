__int64 __fastcall sub_59AB38(__int64 a1, __int64 a2)
{
  __int64 v2; // x13

  *(_QWORD *)(a1 + 456) = a2;
  *(_QWORD *)(a1 + 464) = v2;
  return wmi_extract_ndp_end_ind();
}
