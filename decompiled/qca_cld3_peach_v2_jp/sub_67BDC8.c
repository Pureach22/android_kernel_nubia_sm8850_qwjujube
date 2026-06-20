__int64 __fastcall sub_67BDC8(__int64 a1)
{
  __int64 v1; // x9
  __int64 v2; // x13
  __int64 v3; // x27

  *(_QWORD *)(v3 + 208) = v2;
  *(_QWORD *)(v3 + 216) = v1;
  return wmi_unified_set_ric_req_cmd(a1);
}
