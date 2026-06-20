__int64 __fastcall drv_cmd_set_wmmps(_QWORD *a1, __int64 a2, __int64 a3)
{
  return hdd_wmmps_helper(*a1, a3);
}
