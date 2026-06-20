__int64 __fastcall rndis_set_host_mac(__int64 result, __int64 a2)
{
  *(_QWORD *)(result + 24) = a2;
  return result;
}
