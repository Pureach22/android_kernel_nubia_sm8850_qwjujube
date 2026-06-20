__int64 __fastcall cam_cci_set_debug(__int64 a1, __int64 a2)
{
  *(_QWORD *)(a1 + 5888) = a2;
  return 0;
}
